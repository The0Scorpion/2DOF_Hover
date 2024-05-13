/*
   Submodule for connecting to AWS mqtt server
   handles publishing and recived messages
   Credit:Scorpion
   Created:15/12/2023
*/
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

#define DebugIOT
//#define DebugAQU

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);

void DataIn(char* topic, byte* message, unsigned int length) {
  //destroys the pid loop
  JsonDocument ParamterObject;
  String Data(reinterpret_cast<char*>(message), length);


  if (String(topic) == SubAWSTopic) {
    if (deserializeJson(ParamterObject, Data) == DeserializationError::Ok) {
      // Successfully parsed JSON string
      // Access struct members as needed
      if (ParamterObject.containsKey("xposkp")) {
        xposkp =    fmin(fmax(ParamterObject["xposkp"], -xposkpLimit), xposkpLimit);
      } if (ParamterObject.containsKey("xposki")) {
        xposki =    fmin(fmax(ParamterObject["xposki"], -xposkdLimit), xposkdLimit);
      } if (ParamterObject.containsKey("xposkd")) {
        xposkd =    fmin(fmax(ParamterObject["xposkd"], -xposkiLimit), xposkiLimit);
      } if (ParamterObject.containsKey("xposSet")) {
        xposSet =   fmin(fmax(ParamterObject["xposSet"], -xposSetLimit), xposSetLimit);
      }

      if (ParamterObject.containsKey("xvelkp")) {
        xvelkp =    fmin(fmax(ParamterObject["xvelkp"], -xvelkpLimit), xvelkpLimit);
      } if (ParamterObject.containsKey("xvelki")) {
        xvelki =    fmin(fmax(ParamterObject["xvelki"], -xvelkiLimit), xvelkiLimit);
      } if (ParamterObject.containsKey("xvelkd")) {
        xvelkd =    fmin(fmax(ParamterObject["xvelkd"], -xvelkdLimit), xvelkdLimit);
      }

      if (ParamterObject.containsKey("yposkp")) {
        yposkp =    fmin(fmax(ParamterObject["yposkp"], -yposkpLimit), xposkpLimit);
      } if (ParamterObject.containsKey("yposki")) {
        yposki =    fmin(fmax(ParamterObject["yposki"], -yposkiLimit), yposkiLimit);
      } if (ParamterObject.containsKey("yposkd")) {
        yposkd =    fmin(fmax(ParamterObject["yposkd"], -yposkdLimit), yposkdLimit);
      } if (ParamterObject.containsKey("yposSet")) {
        yposSet =   fmin(fmax(ParamterObject["yposSet"], -yposSetLimit), yposSetLimit);
      }

      if (ParamterObject.containsKey("yvelkp")) {
        yvelkp =    fmin(fmax(ParamterObject["yvelkp"], -yvelkpLimit), yvelkpLimit);
      } if (ParamterObject.containsKey("yvelki")) {
        yvelki =    fmin(fmax(ParamterObject["yvelki"], -yvelkiLimit), yvelkiLimit);
      } if (ParamterObject.containsKey("yvelkd")) {
        yvelkd =    fmin(fmax(ParamterObject["yvelkd"], -yvelkdLimit), yvelkdLimit);
      }

      if (ParamterObject.containsKey("work")) {
        Work =    ParamterObject["work"];

      }

      if (ParamterObject.containsKey("save")) {
        if ((byte)ParamterObject["save"]) {

          int pos = 1;
          EEPROM.write(pos, xposkp);
          pos += 4;
          EEPROM.write(pos, xposki);
          pos += 4;
          EEPROM.write(pos, xposkd);
          pos += 4;

          EEPROM.write(pos, xvelkp);
          pos += 4;
          EEPROM.write(pos, xvelki);
          pos += 4;
          EEPROM.write(pos, xvelkd);
          pos += 4;

          EEPROM.write(pos, yposkp);
          pos += 4;
          EEPROM.write(pos, yposki);
          pos += 4;
          EEPROM.write(pos, yposkd);
          pos += 4;

          EEPROM.write(pos, yvelkp);
          pos += 4;
          EEPROM.write(pos, yvelki);
          pos += 4;
          EEPROM.write(pos, yvelkd);

          EEPROM.commit();
        }
      }

      if (ParamterObject.containsKey("load")) {
        if ((byte)ParamterObject["load"]) {

          int pos = 1;
          xposkp = EEPROM.read(pos);
          pos += 4;
          xposki = EEPROM.read(pos);
          pos += 4;
          xposkd = EEPROM.read(pos);
          pos += 4;


          xvelkp = EEPROM.read(pos);
          pos += 4;
          xvelki = EEPROM.read(pos);
          pos += 4;
          xvelkd = EEPROM.read(pos);
          pos += 4;

          yposkp = EEPROM.read(pos);
          pos += 4;
          yposki = EEPROM.read(pos);
          pos += 4;
          yposkd = EEPROM.read(pos);
          pos += 4;

          yvelkp = EEPROM.read(pos);
          pos += 4;
          yvelki = EEPROM.read(pos);
          pos += 4;
          yvelkd = EEPROM.read(pos);
        }

      }
#ifdef DebugIOT
      Serial.print("Recived ");
      Serial.print(length);
      Serial.print(" bytes on topic: ");
      Serial.println(topic);
      Serial.print("Message: ");
      Serial.println(Data);
      Serial.print("Work: ");
      Serial.println(Work);

      /*Serial.print("xposkp: ");
        Serial.println(xposkp);
        Serial.print("ixposki: ");
        Serial.println(ixposki);
        Serial.print("ixposkd: ");
        Serial.println(ixposkd);
        Serial.print("ixposSet: ");
        Serial.println(ixposSet);

        Serial.print("ixvelkp: ");
        Serial.println(ixvelkp);
        Serial.print("ixvelki: ");
        Serial.println(ixvelki);
        Serial.print("ixvelkd: ");
        Serial.println(ixvelkd);

        Serial.print("iyposkp: ");
        Serial.println(iyposkp);
        Serial.print("iyposki: ");
        Serial.println(iyposki);
        Serial.print("iyposkd: ");
        Serial.println(iyposkd);
        Serial.print("iyposSet: ");
        Serial.println(iyposSet);

        Serial.print("iyvelkp: ");
        Serial.println(iyvelkp);
        Serial.print("iyvelki: ");
        Serial.println(iyvelki);
        Serial.print("iyvelkd: ");
        Serial.println(iyvelkd);*/
#endif

      PID_Running = 0;

    } else {
      // Failed to parse JSON string
      Serial.println("Failed to parse JSON");
    }
  }
  PID_Running = 0;
  DisableMotors();
  delay(2000);
  PID_Running = 1;
}

void initMQTT() {
  //Connect to AWS
  Serial.println("Connecting to AWS");

  // Set AWS IoT endpoint and port
  mqttClient.setServer(AWS_ENDPOINT, AWS_PORT);

  // Set certificate and private key
  wifiClient.setCACert(AWS_CERT_CA);
  wifiClient.setCertificate(AWS_CERT_CRT);
  wifiClient.setPrivateKey(AWS_CERT_PRIVATE);

  while (!mqttClient.connected()) {
    Serial.println("Connecting to AWS IoT...");

    // Set client ID and try to connect
    if (mqttClient.connect(THING_NAME)) {
      Serial.println("Connected to AWS IoT");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(". Retrying in 5 seconds...");
      delay(5000);
    }
  }
  mqttClient.setCallback(DataIn);
  mqttClient.subscribe(SubAWSTopic);
  Serial.println("MQTT Ready");
  Serial.println(WiFi.macAddress());
}
void DataAQU(void * parameter) {
  /*Takes The xpos,ypos,xvel,yvel and displays them over Serial and ESPnow
    constructs an OutMessage Struct to be sent over ESPNOW*/
  initMQTT();
  lastsent = millis();
  unsigned long PktCounter = 0;
  while (1) {
    JsonDocument DataPacket;

    // Populate the JSON document with values directly
    //UpdateTimeStamp();
    DataPacket["ID"] = PktCounter;
    DataPacket["xpos"] = CountsToAngle(xEncoderCount);
    DataPacket["ypos"] = CountsToAngle(yEncoderCount);
    DataPacket["xvel"] = getxSpeed();
    DataPacket["yvel"] = getySpeed();
    DataPacket["xposPID"] = xPOSPID.output;
    DataPacket["yposPID"] = yPOSPID.output;
    DataPacket["xvelPID"] = xVELPID.output;
    DataPacket["yvelPID"] = yVELPID.output;
    //DataPacket["Time"] = timeStamp;
    PktCounter++;
    // Serialize the JSON document to a String
    String jsonString;
    serializeJson(DataPacket, jsonString);
#ifdef DebugAQU
    // Print the JSON string
    Serial.println(jsonString);
#endif
    //Publish json string to AWS MQTTserver
    mqttClient.publish(PubAWSTopic, jsonString.c_str());

    while (millis() - lastsent < Send_Period) {
      mqttClient.loop();
    }
    lastsent = millis();
  }
}
