#line 1 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\AWS_IOT.h"
/*
   Submodule for connecting to AWS mqtt server
   handles publishing and recived messages
   Credit:Scorpion
   Created:15/12/2023
*/
#pragma once
#include <ArduinoJson.h>
#include <espMqttClient.h>
#include "Parameters.h"
#include "Secrets.h"
#include "encoder.h"
#include "EEPROM.h"
#include "Motors.h"
// #define DebugIOT
#define DebugAQU
//  Select  Control Type

// TODO Other Controllers
char Data[256];
espMqttClientSecure mqttClient;

#ifdef CascadedPIDControl
#include "CascadedPID.h"
#elif defined(OnlineControl)
#include "CascadedPID.h"
#endif
void DataIn(const espMqttClientTypes::MessageProperties &properties, const char *topic, const uint8_t *payload, size_t len, size_t index, size_t total);

void onMqttSubscribe(uint16_t packetId, const espMqttClientTypes::SubscribeReturncode *codes, size_t len)
{
  Serial.println("Subscribe acknowledged.");
 /* for (size_t i = 0; i < len; ++i)
  {
    Serial.print("  qos: ");
    Serial.println(static_cast<uint8_t>(codes[i]));
  }*/
}

void onMqttConnect(bool sessionPresent)
{
  uint16_t packetIdSub0 = mqttClient.subscribe(SubAWSTopic, ReceiveQoS);
  Serial.print("Subscribing at QoS 0, packetId: ");
  Serial.println(packetIdSub0);
}

void onMqttDisconnect(espMqttClientTypes::DisconnectReason reason)
{
  Serial.printf("Disconnected from MQTT: %u.\n", static_cast<uint8_t>(reason));
  if (WiFi.isConnected())
  {
    while (!mqttClient.connected())
    {
      Serial.println("Connecting to AWS IoT...");
      if (mqttClient.connect())
      {
        Serial.println("Connected to AWS IoT");
      }
      else
      {
        Serial.print("Failed, ");
        Serial.println(". Retrying in 3 seconds...");
        delay(3000); // Add delay
      }
    }
  }
}

void onMqttPublish(uint16_t packetId)
{
  lastMqttMessageTime = millis();
}

void initMQTT()
{
  // Connect to AWS
  Serial.println("Connecting to AWS");

  while (WiFi.waitForConnectResult() != WL_CONNECTED)
  {
    Serial.println("Waiting for Wifi");
    delay(500);
    // ESP.restart();
  }
  mqttClient.onPublish(onMqttPublish);
  mqttClient.onSubscribe(onMqttSubscribe);
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onMessage(DataIn);
  mqttClient.onDisconnect(onMqttDisconnect);

  // Set AWS IoT endpoint and port
  mqttClient.setServer(AWS_ENDPOINT, AWS_PORT);

  // Set certificate and private key
  mqttClient.setCACert(AWS_CERT_CA);
  mqttClient.setCertificate(AWS_CERT_CRT);
  mqttClient.setPrivateKey(AWS_CERT_PRIVATE);

  while (!mqttClient.connected())
  {
    Serial.println("Connecting to AWS IoT...");

    // Set client ID and try to connect
    if (mqttClient.connect())
    {
      Serial.println("Connected to AWS IoT");
    }
    else
    {
      Serial.print("Failed, ");
      Serial.println(". Retrying in 3 seconds...");
      delay(3000);
    }
  }

  Serial.println("MQTT Ready");
}
void DataAQU(void *parameter)
{
  /*Takes The xpos,ypos,xvel,yvel and displays them over Serial and ESPnow
    constructs an OutMessage Struct to be sent over ESPNOW*/
  Serial.println("IOT Task Started");
  initMQTT();

  lastsent = millis();
  lastAquired = millis();

  while (1)
  {

#ifdef SendPIDActions
    DataPacket["xposPID"] = xPOSPID.output;
    DataPacket["yposPID"] = yPOSPID.output;
    DataPacket["xvelPID"] = xVELPID.output;
    DataPacket["yvelPID"] = yVELPID.output;
#endif

    if (Work)
    {
      // Generate a unique key for this data packet
      String key = String(counta++); // 0-2000
      if (counta >= 2000)
      {
        esp_restart();
        Work = 0;
        counta = 0;
      }

      // Constants for damped oscillation
      float A = 0.35;
      float A_final = 0.01;
      float t_max = 2000.0;
      float beta = log(A / A_final) / t_max;
      float omega = PI / 100.0;
      float time = counta;

      // Damped oscillation position
      float xpos = A * exp(-beta * time) * cos(omega * time);
      float ypos = A * exp(-beta * time) * cos(omega * time);

      // Damped oscillation velocity (derivative of position)
      float xvel = -A * beta * exp(-beta * time) * cos(omega * time) - A * exp(-beta * time) * omega * sin(omega * time);
      float yvel = -A * beta * exp(-beta * time) * cos(omega * time) - A * exp(-beta * time) * omega * sin(omega * time);

      // Create a JSON document for the current data packet
      DataPacket.clear();
      DataPacket["xpos"] = String(xpos, 3).toFloat();
      DataPacket["ypos"] = String(ypos, 3).toFloat();
      DataPacket["xvel"] = String(xvel, 3).toFloat();
      DataPacket["yvel"] = String(yvel, 3).toFloat();

      // Add the current data packet to the parent JSON object
      SendingDoc[key] = DataPacket;
    }

    else
    {
      mqttClient.loop();
    }
#ifdef DebugAQU12
    // Print the HeartBeat string
    // Serial.println("Holding The MQTT");
    Serial.print("free Heap: ");
    Serial.println(ESP.getFreeHeap());
#endif
    // For now just send every Send Period
    if (millis() - lastsent > (Work ? Send_Period : 5000)) // send empty messgae every 5 seconds to keep alive
    {
      Readytosend = 1;
    }

    // Check if Readytosend is set
    if (Readytosend)
    {
// Add metadata to the parent JSON object
#ifdef DebugAQU12
      // Print the HeartBeat string
      // Serial.println("Holding The MQTT");
      Serial.print("free Heap: ");
      Serial.println(ESP.getFreeHeap());
#endif
      int packetCount = SendingDoc.size();
      SendingDoc["numPackets"] = packetCount;           // Number of packets
      SendingDoc["startPacket"] = counta - packetCount; // Assuming packets are sequential

      // Create a buffer to hold the serialized parent JSON object
      serializeJson(SendingDoc, SendingString);

      // Publish the buffer to AWS MQTT server
      mqttClient.publish(PubAWSTopic, SendingQoS, false, SendingString);

#ifdef DebugAQU
      // Print the entire JSON string
      // Serial.println(SendingString);
#endif

      // Clear the parent JSON object after publishing
      SendingDoc.clear();

      // Reset Readtosend flag
      Readytosend = false;
      
      lastsent = millis();
    }
    while (millis() - lastAquired < Sampling_time / 1000)
    {
      mqttClient.loop();
      vTaskDelay(1);
    }

    lastAquired = millis();
  }
}
