/*
 * Submodule that sets up Over-the-Air (OTA) Flash
 * Credit: Scorpion
 * Created: 20/12/2023
 */

#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "Secrets.h" // Make sure to define 'ssid' and 'password' in this file

#define OTAName "2DOFHover"
#define Pass "admin"



// Function to initialize WiFi connection
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  WiFi.waitForConnectResult();

  // Initialize OTA
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    //ESP.restart(); // Consider enabling if a restart is necessary upon failed connection
  }

}

// OTA task function
void OTATask(void *parameter) {
  // Connect to WiFi
  if (WiFi.status() == WL_CONNECTED) {
    ArduinoOTA.setPassword(Pass);
    ArduinoOTA.setHostname(OTAName);

    // OTA callbacks
    ArduinoOTA
      .onStart([]() {
        String type;
        if (ArduinoOTA.getCommand() == U_FLASH)
          type = "sketch";
        else // U_SPIFFS
          type = "filesystem";
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

    // Wait for OTA update
    while (1) {
      ArduinoOTA.handle();
    }
  }
}
