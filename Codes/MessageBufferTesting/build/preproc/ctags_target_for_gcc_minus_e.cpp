# 1 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino"
# 2 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 2
# 3 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 2
# 4 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 2
# 5 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 2
# 6 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 2


// #define OFFLINE


# 12 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 2


// #define DebugCFMain
TaskHandle_t ControlTaskHandle, OTATaskHandle, IOTTaskHandle;

void setup()
{
// calibESCs();

  Serial.begin(115200); // init Serial For debugging

  // initEncoder(0, 0);
  // Over the air task to allow wireless flash runs on core 1
  EEPROM.begin(300);

  initWiFi(); // Blocking Stop for offline

  xTaskCreatePinnedToCore(
      OTATask,
      "OTA Routine",
      10000,
      
# 33 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 3 4
     __null
# 33 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino"
         ,
      0,
      &OTATaskHandle,
      0);

  // Data Acquisition  Task Run on core 0 for now
  xTaskCreatePinnedToCore(
      DataAQU, // Function to implement the task
      "Data AQU Loop", // Name of the task
      40000, // Stack size in words
      
# 43 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 3 4
     __null
# 43 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino"
         , // Task input parameter
      7, // Priority of the task
      &IOTTaskHandle, // Task handle.
      0); // Core where the task should run

  // Main Loop task runs on core 0
  /* xTaskCreatePinnedToCore(

       Control,       // Function to implement the task

       "Main Loop",   // Name of the task

       5120,          // Stack size in words

       NULL,          // Task input parameter

       9,             // Priority of the task

       &ControlTaskHandle, // Task handle.

       0);            // Core where the task should run*/
# 61 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino"
  // Initialize the watchdog timer

  esp_task_wdt_init(60 /*seconds without iot activity to reset after*/, true); // Time in seconds
  esp_task_wdt_add(
# 64 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino" 3 4
                  __null
# 64 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino"
                      ); // Add the main task to the watchdog
  lastMqttMessageTime = millis();
}

void loop()
{

  // Check if the watchdog timer should be reset
  if (millis() - lastMqttMessageTime < 60 /*seconds without iot activity to reset after*/ * 1000)
  {
    // Feed the watchdog
    esp_task_wdt_reset();
  }
  /*else

  {

    Serial.println("Watchdog timeout! No MQTT message received.");

    // Take any necessary action, e.g., reset the ESP32

    esp_restart();

  }*/
# 83 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino"
  /*mqttClient.unsubscribe(SubAWSTopic);

  delay(2000);

  uint16_t packetIdSub0 = mqttClient.subscribe(SubAWSTopic, ReceiveQoS);

  Serial.print("Subscribing at QoS 0, packetId: ");

  Serial.println(packetIdSub0);

  delay(20000);*/
# 89 "F:\\Programs\\2DOF_Hover\\Codes\\MessageBufferTesting\\MessageBufferTesting.ino"
  // if debug then print the values between IMU and Encoder





  // make sure motors are disabled if not intended to run
  if (!Work || failed_Trials > fail_TrailLimit)
  {
    DisableMotors();
  }
}
