#include <espnow.h>
#include <ESP8266WiFi.h>

// ESP-NOW receiver MAC address

// Create a struct_message called myData


uint8_t receiverMac[] = {0x30, 0xC6, 0xF7, 0x44, 0x2F, 0x14};
//esp_now_peer_info_t peerInfo;
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
/*void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
  }*/
void OnDataSent(uint8_t *mac_addr, uint8_t  status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == 0 ? "Delivery Success" : "Delivery Fail");
}
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  //  WiFi.begin("A30", "123456789");
  //   while (WiFi.status() != WL_CONNECTED) {
  //    delay(1000);
  //    Serial.println("Connecting to WiFi...");
  //    Serial.println(WiFi.status());
  //  }
  //  Serial.println("Connected to WiFi.");
  // Initialize ESP-NOW
  WiFi.disconnect();
  if (esp_now_init() == 0) {
    Serial.println("ESP-NOW initialized successfully");
  } else {
    Serial.println("Failed to initialize ESP-NOW");
  }

  // Register callback function for receiving data
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);

  // Add the receiver's MAC address

  /* memcpy(peerInfo.peer_addr, receiverMac, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;

    if (esp_now_add_peer(&peerInfo) == ESP_OK) {
     Serial.println("ESP-NOW peer added successfully");
    } else {
     Serial.println("Failed to add ESP-NOW peer");
     return;
    }*/
  esp_now_add_peer(receiverMac, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
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
outMessage myData;
unsigned long lastTime = 0;
unsigned long timerDelay = 2000;  // send readings timer
void loop() {
  if ((millis() - lastTime) > timerDelay) {
    // Set values to send
    myData.xpos = 10;
    myData.ypos = 0;
    myData.xvel = 1;
    myData.yvel = 22;
    myData.xposPID = 6;
    myData.yposPID = 2;
    myData.xvelPID = 3;
    myData.yvelPID = 4;

    // Send message via ESP-NOW
    esp_now_send(receiverMac, (uint8_t *) &myData, sizeof(myData));

    lastTime = millis();
  }
}
