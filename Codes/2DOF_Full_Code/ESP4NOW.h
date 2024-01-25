#include <esp_now.h>


uint8_t HubAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

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
    
  iyposkp=inparamters.yposkp;
  iyposki=inparamters.yposki;
  iyposkd=inparamters.yposkd;
  iyposSet = inparamters.yposSet;
  
  iyvelkp=inparamters.yvelkp;
  iyvelki=inparamters.yvelki;
  iyvelkd=inparamters.yvelkd;

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
void DataAQU(void * parameter) {
  /*Takes The xpos,ypos,xvel,yvel and displays them over Serial and ESPnow
    constructs an OutMessage Struct to be sent over ESPNOW*/

  States.xpos = CountsToAngle(xEncoderCount);
  States.ypos = CountsToAngle(yEncoderCount);
  States.xvel = getxSpeed();
  States.yvel = getySpeed();
  States.xposPID = xPOSPID->output;
  States.yposPID = yPOSPID->output;
  States.xvelPID = xVELPID->output;
  States.yvelPID = yVELPID->output;

  esp_err_t result = esp_now_send(HubAddress, (uint8_t *) &States, sizeof(States));
  if (result == ESP_OK) {
    Serial.println("Sent with success");
  }
  else {
    Serial.println("Error sending the data");
  }
}
