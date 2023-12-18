#include <esp_now.h>



void GetMacAddress(){
  Serial.begin(115200);
  WiFi.mode(WIFI_MODE_STA);
  Serial.println(WiFi.macAddress());
}
/*---------------------------------------------------------------------------------------------------*/
void OnDataSentCB(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}
void OnDataRecvCB(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&inparamters, incomingData, sizeof(inparamters));
  //TO DO
  //Checks If correct format 
  //destroys the pid loop
  
  ixposkp=inparamters.xposkp;
  ixposki=inparamters.xposki;
  ixposkd=inparamters.xposkd;
  ixposSet = inparamters.xposSet;
  
  ixvelkp=inparamters.xvelkp;
  ixvelki=inparamters.xvelki;
  ixvelkd=inparamters.xvelkd;
  ixvelSet = inparamters.xvelSet;
    
  iyposkp=inparamters.yposkp;
  iyposki=inparamters.yposki;
  iyposkd=inparamters.yposkd;
  iyposSet = inparamters.yposSet;
  
  iyvelkp=inparamters.yvelkp;
  iyvelki=inparamters.yvelki;
  iyvelkd=inparamters.yvelkd;
  iyvelSet = inparamters.yvelSet;

  Sampling_time = inparamters.SamplingTime;
  
  //re init the PID TASK
   PID_Running=0;
}
/*---------------------------------------------------------------------------------------------------*/
void ESPNowInit()
{
  if (esp_now_init() != ESP_OK){
      Serial.println("Error initializing ESP-NOW");
      esp_now_register_recv_cb(OnDataRecvCB);
      esp_now_register_send_cb(OnDataSentCB);
      }
  else
      Serial.println("Initialized Successfully");
}
/*---------------------------------------------------------------------------------------------------*/
void RegisterPeer(uint8_t *LOC_broadcastAddress, esp_now_peer_info_t LOC_peer)
{
  memcpy(LOC_peer.peer_addr , LOC_broadcastAddress ,6);
  LOC_peer.channel = 0;  
  LOC_peer.encrypt = false;

  if (esp_now_add_peer(&LOC_peer) != ESP_OK){
    Serial.println("Failed to add peer");
  }
  else
  Serial.println("peer added successfully");
}
