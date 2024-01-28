#include <esp_now.h>
#include <WiFi.h>

// ESP-NOW receiver MAC address

uint8_t receiverMac[] = {0x30, 0xC6, 0xF7, 0x44, 0x2F, 0x14};
esp_now_peer_info_t peerInfo;
// Callback function for receiving ESP-NOW messages
void OnDataRecv(const uint8_t* mac, const uint8_t* data, int len) {
  Serial.print("Received data from ");
  for (int i = 0; i < 6; ++i) {
    Serial.print(mac[i], HEX);
    if (i < 5) Serial.print(":");
  }
  Serial.print(", data: ");
  Serial.write(data, len);
  Serial.println();
}
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
void setup() {
  Serial.begin(115200);
  //  WiFi.mode(WIFI_STA);
  //  WiFi.begin("A30", "123456789");
  //   while (WiFi.status() != WL_CONNECTED) {
  //    delay(1000);
  //    Serial.println("Connecting to WiFi...");
  //    Serial.println(WiFi.status());
  //  }
  //  Serial.println("Connected to WiFi.");
  // Initialize ESP-NOW
  if (esp_now_init() == ESP_OK) {
    Serial.println("ESP-NOW initialized successfully");
  } else {
    Serial.println("Failed to initialize ESP-NOW");
  }

  // Register callback function for receiving data
  esp_now_register_send_cb(OnDataSent);

  // Add the receiver's MAC address

  memcpy(peerInfo.peer_addr, receiverMac, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) == ESP_OK) {
    Serial.println("ESP-NOW peer added successfully");
  } else {
    Serial.println("Failed to add ESP-NOW peer");
    return;
  }
}

void loop() {
  // Send a message using ESP-NOW
  String message = "Hello, ESP-NOW!";
  esp_now_send(receiverMac, (uint8_t*)message.c_str(), message.length());

  delay(5000);  // Wait for 5 seconds before sending the next message
}
