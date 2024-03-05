/*
   Submodule for Network time protocol
   syncs the esp time to the main server
   Credit:Scorpion
   Created: 20/10/2024
*/

//#include <WiFi.h> //Already Included
#include <NTPClient.h>
//#include <WiFiUdp.h> //Already Included
#define DebugcNTP
int RTT = 250;
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "time.aws.com");

//to document

unsigned long MMdelta = 0L;
long Offset = 7200;


void initNTP() {
  // Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +2 = 7200
  timeClient.setTimeOffset(Offset);


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

  timeClient.setTimeOffset(Offset + ((millis() - MMdelta) / 1000));
  formattedDate = timeClient.getFormattedTime();

  int splitT = formattedDate.indexOf("T");

  // Extract time
  timeStamp = formattedDate.substring(splitT + 1, formattedDate.length() - 1) + ":";
  timeStamp += String((millis() - MMdelta) % 1000);
  
#ifdef DebugcNTP
  Serial.println(formattedDate);
  Serial.println(timeStamp);
#endif

}
