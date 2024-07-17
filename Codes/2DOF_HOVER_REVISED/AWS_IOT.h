/*
   Submodule for connecting to AWS mqtt server
   handles publishing and recived messages
   Credit:Scorpion
   Created:15/12/2023
*/
#include <ArduinoJson.h>
#include <espMqttClient.h>
#include "Parameters.h"
#include "Secrets.h"
#include "encoder.h"
#include "EEPROM.h"
#include "Motors.h"

#define DebugIOT
#define DebugAQU

char Data[256];
espMqttClientSecure mqttClient;
StaticJsonDocument<1024> ParamterObject;
StaticJsonDocument<256> DataPacket;
char jsonString[256];

void DataIn(const espMqttClientTypes::MessageProperties &properties, const char *topic, const uint8_t *payload, size_t len, size_t index, size_t total)
{
  if (String(topic) == SubAWSTopic)
  {
    DeserializationError error = deserializeJson(ParamterObject, payload, len);
    if (error)
    {
      Serial.println("Failed to parse JSON");
      return;
    }

    // Parse parameters
    if (ParamterObject.containsKey("xposkp"))
      xposkp = constrain(ParamterObject["xposkp"], -xposkpLimit, xposkpLimit);
    if (ParamterObject.containsKey("xposki"))
      xposki = constrain(ParamterObject["xposki"], -xposkiLimit, xposkiLimit);
    if (ParamterObject.containsKey("xposkd"))
      xposkd = constrain(ParamterObject["xposkd"], -xposkdLimit, xposkdLimit);
    if (ParamterObject.containsKey("xposSet"))
      xposSet = constrain(ParamterObject["xposSet"], -xposSetLimit, xposSetLimit);

    if (ParamterObject.containsKey("xvelkp"))
      xvelkp = constrain(ParamterObject["xvelkp"], -xvelkpLimit, xvelkpLimit);
    if (ParamterObject.containsKey("xvelki"))
      xvelki = constrain(ParamterObject["xvelki"], -xvelkiLimit, xvelkiLimit);
    if (ParamterObject.containsKey("xvelkd"))
      xvelkd = constrain(ParamterObject["xvelkd"], -xvelkdLimit, xvelkdLimit);

    if (ParamterObject.containsKey("yposkp"))
      yposkp = constrain(ParamterObject["yposkp"], -yposkpLimit, yposkpLimit);
    if (ParamterObject.containsKey("yposki"))
      yposki = constrain(ParamterObject["yposki"], -yposkiLimit, yposkiLimit);
    if (ParamterObject.containsKey("yposkd"))
      yposkd = constrain(ParamterObject["yposkd"], -yposkdLimit, yposkdLimit);
    if (ParamterObject.containsKey("yposSet"))
      yposSet = constrain(ParamterObject["yposSet"], -yposSetLimit, yposSetLimit);

    if (ParamterObject.containsKey("yvelkp"))
      yvelkp = constrain(ParamterObject["yvelkp"], -yvelkpLimit, yvelkpLimit);
    if (ParamterObject.containsKey("yvelki"))
      yvelki = constrain(ParamterObject["yvelki"], -yvelkiLimit, yvelkiLimit);
    if (ParamterObject.containsKey("yvelkd"))
      yvelkd = constrain(ParamterObject["yvelkd"], -yvelkdLimit, yvelkdLimit);

    if (ParamterObject.containsKey("work"))
    {
      Work = ParamterObject["work"];
      if (Work)
      {
        DataPacket["ID"] = -1;
        DataPacket["xpos"] = CountsToAngle(xEncoderCount);
        DataPacket["ypos"] = CountsToAngle(yEncoderCount);
        DataPacket["xvel"] = getxSpeed();
        DataPacket["yvel"] = getySpeed();
        serializeJson(DataPacket, jsonString, sizeof(jsonString));
        mqttClient.publish(PubAWSTopic, SendingQoS, false, jsonString);
      }
    }

    if (ParamterObject.containsKey("save") && (byte)ParamterObject["save"])
    {
      int pos = 2;
      EEPROM.put(pos, xposkp);
      pos += sizeof(xposkp);
      EEPROM.put(pos, xposki);
      pos += sizeof(xposki);
      EEPROM.put(pos, xposkd);
      pos += sizeof(xposkd);
      EEPROM.put(pos, xvelkp);
      pos += sizeof(xvelkp);
      EEPROM.put(pos, xvelki);
      pos += sizeof(xvelki);
      EEPROM.put(pos, xvelkd);
      pos += sizeof(xvelkd);
      EEPROM.put(pos, yposkp);
      pos += sizeof(yposkp);
      EEPROM.put(pos, yposki);
      pos += sizeof(yposki);
      EEPROM.put(pos, yposkd);
      pos += sizeof(yposkd);
      EEPROM.put(pos, yvelkp);
      pos += sizeof(yvelkp);
      EEPROM.put(pos, yvelki);
      pos += sizeof(yvelki);
      EEPROM.put(pos, yvelkd);
      EEPROM.commit();
    }

    if (ParamterObject.containsKey("load") && (byte)ParamterObject["load"])
    {
      int pos = 2;
      EEPROM.get(pos, xposkp);
      pos += sizeof(xposkp);
      EEPROM.get(pos, xposki);
      pos += sizeof(xposki);
      EEPROM.get(pos, xposkd);
      pos += sizeof(xposkd);
      EEPROM.get(pos, xvelkp);
      pos += sizeof(xvelkp);
      EEPROM.get(pos, xvelki);
      pos += sizeof(xvelki);
      EEPROM.get(pos, xvelkd);
      pos += sizeof(xvelkd);
      EEPROM.get(pos, yposkp);
      pos += sizeof(yposkp);
      EEPROM.get(pos, yposki);
      pos += sizeof(yposki);
      EEPROM.get(pos, yposkd);
      pos += sizeof(yposkd);
      EEPROM.get(pos, yvelkp);
      pos += sizeof(yvelkp);
      EEPROM.get(pos, yvelki);
      pos += sizeof(yvelki);
      EEPROM.get(pos, yvelkd);
    }

#ifdef DebugIOT
    Serial.print("Received ");
    Serial.print(len);
    Serial.print(" bytes on topic: ");
    Serial.println(topic);
    Serial.print("Message: ");
    Serial.println(Data);
    Serial.print("Work: ");
    Serial.println(Work);
#endif

    ControllerRunning = 0;
  }

  ControllerRunning = 0;
  DisableMotors();
  delay(2000);
  ControllerRunning = 1;
}

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
