#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <SPIFFS.h>

//#define DebugIOT
//#define DebugAQU

WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);

void DataIn(char* topic, byte* message, unsigned int length) {
  //destroys the pid loop
  DynamicJsonDocument doc(200);
  String Data(reinterpret_cast<char*>(message), length);
  Serial.print("Recived on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  Serial.println(Data);
  if (String(topic) == SubAWSTopic) {
    if (deserializeJson(doc, Data) == DeserializationError::Ok) {
      // Successfully parsed JSON string
      // Access struct members as needed
      ixposkp = doc["xposkp"];
      ixposki = doc["xposki"];
      ixposkd = doc["xposkd"];
      ixposSet = doc["xposSet"];

      ixvelkp = doc["xvelkp"];
      ixvelki = doc["xvelki"];
      ixvelkd = doc["xvelkd"];

      iyposkp = doc["yposkp"];
      iyposki = doc["yposki"];
      iyposkd = doc["yposkd"];
      iyposSet = doc["yposSet"];

      iyvelkp = doc["yvelkp"];
      iyvelki = doc["yvelki"];
      iyvelkd = doc["yvelkd"];
#ifdef DebugIOT
      Serial.print("ixposkp: ");
      Serial.println(ixposkp);
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
      Serial.println(iyvelkd);
#endif
    } else {
      // Failed to parse JSON string
      Serial.println("Failed to parse JSON");
    }
  }

}

void DataAQU(void * parameter) {
  /*Takes The xpos,ypos,xvel,yvel and displays them over Serial and ESPnow
    constructs an OutMessage Struct to be sent over ESPNOW*/
  while (1) {
    StaticJsonDocument<250> doc;

    // Populate the JSON document with values directly
    doc["xpos"] = CountsToAngle(xEncoderCount);
    doc["ypos"] = CountsToAngle(yEncoderCount);
    doc["xvel"] = getxSpeed();
    doc["yvel"] = getySpeed();
    doc["xposPID"] = xPOSPID.output;
    doc["yposPID"] = yPOSPID.output;
    doc["xvelPID"] = xVELPID.output;
    doc["yvelPID"] = yVELPID.output;

    // Serialize the JSON document to a String
    String jsonString;
    serializeJson(doc, jsonString);
#ifdef DebugAQU
    // Print the JSON string
    Serial.println(jsonString);
#endif
    //Publish json string to AWS MQTTserver
    mqttClient.publish(PubAWSTopic, jsonString.c_str());
    mqttClient.loop();
    delay(5);
  }
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
