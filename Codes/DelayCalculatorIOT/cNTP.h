/*
   Submodule for Network time protocol
   syncs the esp time to the main server
   Credit:Scorpion
   Created: 5/3/2024
*/

//#include <WiFi.h> //Already Included
#include <NTPClient.h>
//#include <WiFiUdp.h> //Already Included
#define DebugcNTP
int RTT = -230;
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "time.aws.com", 0, 60000);

//to document

unsigned long MMdelta = 0L;



void initNTP() {
  // Initialize a NTPClient to get time
  timeClient.begin();



  while (!timeClient.update()) {
    timeClient.forceUpdate();
  }


  MMdelta = millis() + RTT;
}
void UpdateTimeStamp() {
  timeClient.update();
  int ms = (millis() - MMdelta)  % 1000;
  formattedDate = String(timeClient.getEpochTime());
  formattedDate += ms > 100 ? String(ms) : ( ms > 10 ? ("0" + String(ms)) : ("00" + String(ms))); //counvert 15 into "015"
  /*
    formattedDate = String(timeClient.getHours()) + ":";
    formattedDate += String(timeClient.getMinutes()) + ":";
    formattedDate += String(timeClient.getSeconds()) + ":";

    formattedDate += String((millis() - MMdelta)  % 1000);*/

#ifdef DebugcNTP
  //Serial.println(formattedDate);
  Serial.println(formattedDate);
#endif

}
