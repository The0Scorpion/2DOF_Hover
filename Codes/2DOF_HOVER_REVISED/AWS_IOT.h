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
//#define DebugIOT
//#define DebugAQU
//Select  Control Type


// TODO Other Controllers
char Data[256];
espMqttClientSecure mqttClient;


char jsonString[256];
#ifdef CascadedPIDControl 
  #include "CascadedPID.h"
#elif defined(OnlineControl)
  #include "CascadedPID.h"
#endif
void DataIn(const espMqttClientTypes::MessageProperties &properties, const char *topic, const uint8_t *payload, size_t len, size_t index, size_t total);

void onMqttSubscribe(uint16_t packetId, const espMqttClientTypes::SubscribeReturncode *codes, size_t len)
{
  Serial.println("Subscribe acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
  for (size_t i = 0; i < len; ++i)
  {
    Serial.print("  qos: ");
    Serial.println(static_cast<uint8_t>(codes[i]));
  }
}

void onMqttConnect(bool sessionPresent)
{
  Serial.println("Connected to MQTT.");
  Serial.print("Session present: ");
  Serial.println(sessionPresent);

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
  Serial.println("Publish acknowledged.");
  Serial.print("  packetId: ");
  Serial.println(packetId);
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

  mqttClient.onSubscribe(onMqttSubscribe);
  mqttClient.onConnect(onMqttConnect);
  mqttClient.onMessage(DataIn);
  mqttClient.onDisconnect(onMqttDisconnect);
  mqttClient.onPublish(onMqttPublish);
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
  initMQTT();

  lastsent = millis();

  while (1)
  {

    // Populate the JSON document with values directly
    // UpdateTimeStamp();
    DataPacket["ID"] = Work ? counta * 5 / Send_Period : -1;
    DataPacket["xpos"] = CountsToAngle(xEncoderCount);
    DataPacket["ypos"] = CountsToAngle(yEncoderCount);
    DataPacket["xvel"] = getxSpeed();
    DataPacket["yvel"] = getySpeed();

#ifdef SendPIDActions
    DataPacket["xposPID"] = xPOSPID.output;
    DataPacket["yposPID"] = yPOSPID.output;
    DataPacket["xvelPID"] = xVELPID.output;
    DataPacket["yvelPID"] = yVELPID.output;
#endif

    if (Work)
    {
      // Serialize the JSON document to a String
      serializeJson(DataPacket, jsonString, sizeof(jsonString));
#ifdef DebugAQU
      // Print the JSON string
      Serial.println(jsonString);
#endif
      // Publish json string to AWS MQTTserver
      mqttClient.publish(PubAWSTopic, SendingQoS, false, jsonString);
    }
    else
    {
#ifdef DebugAQU
      // Print the HeartBeat string
      Serial.println("Holding The MQTT");
#endif
      mqttClient.loop();
    }
    while (millis() - lastsent < Send_Period)
    {
      mqttClient.loop();
    }
    lastsent = millis();
  }
}
