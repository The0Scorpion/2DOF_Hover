// Cascaded PID Control
#pragma once
#include "PID.h"
#include "Parameters.h"
#include "EEPROM.h"
#include "RVG0.h"
#include "encoder.h"
#include <espMqttClient.h>
#include <ArduinoJson.h>
#include "AWS_IOT.h"
#include "ActionsBuffer.h"

// Define topics and buffer sizes
#define SUB_AWS_TOPIC "2DOF/Actions"
#define PUB_LOG_TOPIC "2DOF/LOG"
#define JSON_DOC_SIZE 1024
#define WARN_LIMIT 10
#define CRITICAL_LIMIT 1

StaticJsonDocument<256> DataPacket;
// Define static JSON document and action buffer
StaticJsonDocument<JSON_DOC_SIZE> actionsObject;
JsonArray receivedActions;
int currentControlAction = 0;

// Function declarations


// Callback for receiving MQTT messages
void dataIn(const espMqttClientTypes::MessageProperties &properties, const char *topic, const uint8_t *payload, size_t len, size_t index, size_t total)
{
    // Check if the topic matches the subscription topic
    if (String(topic) == SUB_AWS_TOPIC)
    {
        // Deserialize JSON payload
        DeserializationError error = deserializeJson(actionsObject, payload, len);
        if (error)
        {
            Serial.println("Failed to parse JSON");
            return;
        }

        // Handle the action message
        // Check and extract startIndex and ActionCount from the JSON object
        if (actionsObject.containsKey("startIndex"))
        {
            int startIndex = actionsObject["startIndex"];
            int actionCount = actionsObject["ActionCount"];

            // Extract the actions array
            receivedActions = actionsObject["actions"].as<JsonArray>();

            // Populate the actions buffer
            for (int i = 0; i < actionCount; i++)
            {
                actionsBuffer[startIndex + i][0] = receivedActions[i][0];
                actionsBuffer[startIndex + i][1] = receivedActions[i][1];
            }
        }

        // Check and extract the work status from the JSON object
        if (actionsObject.containsKey("work"))
        {
            bool work = actionsObject["work"];
            if (work)
            {
                // Prepare and send the data packet
                DataPacket["ID"] = -1;
                DataPacket["xpos"] = CountsToAngle(xEncoderCount);
                DataPacket["ypos"] = CountsToAngle(yEncoderCount);
                DataPacket["xvel"] = getxSpeed();
                DataPacket["yvel"] = getySpeed();
                serializeJson(DataPacket, jsonString, sizeof(jsonString));
                mqttClient.publish(PubAWSTopic, SendingQoS, false, jsonString);
            }
        }

#ifdef DEBUG_IOT
        Serial.print("Received ");
        Serial.print(len);
        Serial.print(" bytes on topic: ");
        Serial.println(SUB_AWS_TOPIC);
        Serial.print("Work: ");
        Serial.println(work);
#endif
    }
}

// Function to handle the received action message

// Function to initialize the controller
void initController()
{
    // Reset and initialize the actions buffer
    initializeActionsBuffer();

#ifdef DEBUG_CF
    Serial.println("Initialized PID Loops Successfully");
#endif
}

// Function to perform one step of the controller loop
void stepController()
{
    // Calculate motor actions from the actions buffer
    xAction = actionsBuffer[currentControlAction][0] * 10;
    yAction = actionsBuffer[currentControlAction][1] * 10;

    // Check the number of remaining actions
    int remainingActions = getRemainingActions(currentControlAction);

    // Publish warning if the remaining actions are below the warning limit
    if (remainingActions < WARN_LIMIT)
    {
        publishWarning("Low Number Of actions Remaining");
    }

    // Publish error if the remaining actions are below the critical limit
    if (remainingActions < CRITICAL_LIMIT)
    {
        publishError("Very Low Number Of actions Remaining");
        Work = 0;
        failcount++;
    }
    currentControlAction++;
}

