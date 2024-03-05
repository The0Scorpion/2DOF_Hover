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
int RTT = 244;
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 7200, 60000);

//to document

unsigned long MMdelta = 0L;
long Offset = 7200;


void initNTP() {
  // Initialize a NTPClient to get time
  timeClient.begin();



  while (!timeClient.update()) {
    timeClient.forceUpdate();
  }

  int startSec = timeClient.getSeconds();
  while (startSec == timeClient.getSeconds()) {
    timeClient.forceUpdate();
  }

  MMdelta = millis() + RTT;
}
void UpdateTimeStamp() {
  timeClient.update();
  formattedDate = String(timeClient.getHours()) + ":";
  formattedDate += String(timeClient.getMinutes()) + ":";
  formattedDate += String(timeClient.getSeconds()) + ":";
  formattedDate += String(((millis() - MMdelta))  % 1000);

#ifdef DebugcNTP
  //Serial.println(formattedDate);
  Serial.println(formattedDate);
#endif

}
