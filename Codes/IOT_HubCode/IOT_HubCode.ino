#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <SPIFFS.h>
#include "Secrets.h"
#include <ArduinoJson.h>
WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);

float ixposkp = 0.1;
float ixposki = 0.001;
float ixposkd = 0.001;
float ixvelkp = 0.1;
float ixvelki = 0.001;
float ixvelkd = 0.001;
float iyposkp = 0.1;
float iyposki = 0.001;
float iyposkd = 0.001;
float iyvelkp = 0.1;
float iyvelki = 0.001;
float iyvelkd = 0.001;
float ixposSet = 0;
float iyposSet = 0;
float ixvelSet = 0;
float iyvelSet = 0;
int Opratingpoint = 1400;

// Callback function for receiving ESP-NOW messages
void DataIn(char* topic, byte* message, unsigned int length) {
    //TO DO
    //Checks If correct format
    //destroys the pid loop
    DynamicJsonDocument doc(1024);
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
  
      } else {
        // Failed to parse JSON string
        Serial.println("Failed to parse JSON");
      }
    }

}
void connectToAWS() {
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
}
int32_t getWiFiChannel(const char *ssid) {
  if (int32_t n = WiFi.scanNetworks()) {
    for (uint8_t i = 0; i < n; i++) {
      if (!strcmp(ssid, WiFi.SSID(i).c_str())) {
        return WiFi.channel(i);
      }
    }
  }
  return 0;
}
struct outMessage {
  //TO DO
  float xpos;
  float xvel;
  float ypos;
  float yvel;
  float xvelPID;
  float yvelPID;
  float xposPID;
  float yposPID;
};
void connectToWiFi() {
  Serial.println("Connecting to WiFi");
  WiFi.begin(SECRET_SSID, SECRET_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}
void setup() {
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  //esp_wifi_set_ps(WIFI_PS_NONE);
  Serial.println("ESP_now Ready");
  // Register callback function for receiving ESP-NOW messages



  // Connect to WiFi
  connectToWiFi();
  //Connect to AWS
  connectToAWS() ;
  Serial.println("Ready");
  Serial.println(WiFi.macAddress());

}

void loop() {
  StaticJsonDocument<256> doc;

  // Populate the JSON document with example values for testing
  doc["xpos"] = 10.22;
  doc["ypos"] = 20.33;
  doc["xvel"] = 5.55;
  doc["yvel"] = -2.11;
  doc["xposPID"] = 15.66;
  doc["yposPID"] = -7.77;
  doc["xvelPID"] = 3.33;
  doc["yvelPID"] = 8.88;

  // Serialize the JSON document to a String
  String jsonString;
  serializeJson(doc, jsonString);

  // Print the JSON string
  //Serial.println(jsonString);

  //mqttClient.publish(PubAWSTopic, jsonString.c_str());
  //delay(1000);
  mqttClient.loop();

}
