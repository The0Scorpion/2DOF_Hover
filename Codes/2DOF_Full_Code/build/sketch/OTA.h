#line 1 "C:\\Programs\\2DOF_Hover\\Codes\\2DOF_Full_Code\\OTA.h"
/*
 * Submodule that setups Over the air flash 
 * Credit: Scorpion
 * Created: 20/12/2023
*/

#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#define OTAName "2DOFHover"
#define Pass "admin"
//OTA task as seen in Example (allows to upload the code wirelessly (Over the air)
byte wifi=0;
void initWIFI(){
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  WiFi.waitForConnectResult();
  
  //init the OTA
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    //ESP.restart();
  }
  wifi=1;
}

void OTATASK(void * parameter) {
  //Connect to wifi
  if(wifi){
  ArduinoOTA.setPassword(Pass);
  ArduinoOTA.setHostname(OTAName);
  ArduinoOTA
  .onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println("Start updating " + type);
  })
  .onEnd([]() {
    Serial.println("\nEnd");
  })
  .onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  })
  .onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });

  ArduinoOTA.begin();

  //wait for OTA connection
  while (1) {
    ArduinoOTA.handle();
  }
}}
