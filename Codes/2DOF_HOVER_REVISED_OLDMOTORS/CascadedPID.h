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
#define SubAWSTopic "2DOF/Parameters"

void DataIn(const espMqttClientTypes::MessageProperties &properties, const char *topic, const uint8_t *payload, size_t len, size_t index, size_t total)
{
  lastMqttMessageTime = millis();
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
        //serializeJson(DataPacket, SendingString, sizeof(SendingString));
        //mqttClient.publish(PubAWSTopic, SendingQoS, false, SendingString);
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
// Initialize PID controllers and related variables
void initController() {
    // Reset and initialize 4 PID objects with specified parameters

    // X Position PID
    xPOSPID.reset();
    xPOSPID.init(xposkp, xposki, xposkd, xposSet, -PositionLoopSat, PositionLoopSat);

    // X Velocity PID
    xVELPID.reset();
    xVELPID.init(xvelkp, xvelki, xvelkd, xvelSet, -xmaxDeltaMicros / 10, xmaxDeltaMicros / 10);

    // Y Position PID
    yPOSPID.reset();
    yPOSPID.init(yposkp, yposki, yposkd, yposSet, -PositionLoopSat, PositionLoopSat);

    // Y Velocity PID
    yVELPID.reset();
    yVELPID.init(yvelkp, yvelki, yvelkd, yvelSet, -ymaxDeltaMicros / 10, ymaxDeltaMicros / 10);

    // Set initial targets for RVG0 module
    XRVG0_U.Y1target = xposSet;
    YRVG0_U.Y1target = yposSet;

#ifdef DebugCF
    Serial.println("Initialized PID Loops Successfully");
#endif
}

// Perform one step of the controller loop
void stepController() {
    // Calculate RVG0 outputs
    RVG0_step();

    // Set position setpoints from RVG0 module
    xPOSPID.setpoint = XRVG0_Y.Y1ref;
    yPOSPID.setpoint = YRVG0_Y.Y1ref;

    // Calculate velocity setpoints from position PID outputs and RVG0 references
    xVELPID.setpoint = (float)xPOSPID.calculate(CountsToAngle(xEncoderCount)) + XRVG0_Y.Y2ref;
    yVELPID.setpoint = (float)yPOSPID.calculate(CountsToAngle(yEncoderCount)) + YRVG0_Y.Y2ref;

    // Calculate motor actions from velocity PID outputs, converting from percent to microseconds (pulse width)
    xAction = (float)xVELPID.calculate(xSpeed) * 10;
    yAction = (float)yVELPID.calculate(ySpeed) * 10;
}
