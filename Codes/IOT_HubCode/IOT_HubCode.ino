#include <WiFi.h>
#include <esp_now.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>
#include <SPIFFS.h>
#include "Secrets.h"
WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);
// Callback function for receiving ESP-NOW messages
void OnDataReceived(const uint8_t* mac, const uint8_t* data, int len) {
  // Convert the received data to a string
  String message = "";
  for (int i = 0; i < len; i++) {
    message += (char)data[i];
  }
  // Connect to the AWS MQTT broker
  if (mqttClient.connect(awsClientId)) {
    // Publish the received message to the AWS MQTT server
    mqttClient.publish(awsTopic, message.c_str());
    Serial.println("Message published to AWS MQTT server.");
  } else {
    Serial.println("Failed to connect to AWS MQTT server.");
  }

}

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("A30", "123456789");
  // Connect to WiFi
  // Initialize the WiFi and MQTT clients
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    Serial.println(WiFi.status());
  }
  Serial.println("Connected to WiFi.");

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW initialization failed.");
    return;
  }
  // Load root CA certificate into WiFiClientSecure
  wifiClient.setCACert(rootCACertificate);

  // Load device certificate and private key into WiFiClientSecure
  wifiClient.setCertificate(deviceCertificate);
  wifiClient.setPrivateKey(privateKey);

  // Set AWS endpoint and port
  mqttClient.setServer(awsEndpoint, awsPort);
  // Register callback function for receiving ESP-NOW messages
  esp_now_register_recv_cb(OnDataReceived);
  
  Serial.println("Ready");
  Serial.println(WiFi.macAddress());
}

void loop() {
  // Do nothing in the loop
}
