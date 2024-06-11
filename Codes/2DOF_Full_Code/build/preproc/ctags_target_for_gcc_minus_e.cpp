# 1 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
# 2 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 3 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 4 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 5 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 6 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 7 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 8 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 9 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 10 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 11 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 12 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 13 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 14 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
# 15 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 2
//#define OFFLINE
TaskHandle_t TaskHandle_1;

void setup() {
  Serial.begin(115200);//init Serial For debugging
  //initEncoder(0, 0);
  //Over the air task to allow wireless flash runs on core 1
    EEPROM.begin(300);

  initWIFI();// Blocking Stop for offline

  xTaskCreatePinnedToCore(
    OTATASK,
    "OTA Routine",
    5000,
    
# 30 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 3 4
   __null
# 30 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
       ,
    0,
    
# 32 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 3 4
   __null
# 32 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
       ,
    1);

  //Data Acquisition  Task Run on core 0 for now
  xTaskCreatePinnedToCore(
    DataAQU, // Function to implement the task
    "Data AQU Loop", // Name of the task
    5000, // Stack size in words
    
# 40 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 3 4
   __null
# 40 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
       , // Task input parameter
    0, // Priority of the task
    
# 42 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 3 4
   __null
# 42 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
       , // Task handle.
    0); // Core where the task should run

  //Main Loop task runs on core 0
  xTaskCreatePinnedToCore(
    PIDLoop, //Function to implement the task
    "Main Loop", // Name of the task
    10000, // Stack size in words
    
# 50 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino" 3 4
   __null
# 50 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
       , // Task input parameter
    9, // Priority of the task
    &TaskHandle_1, // Task handle.
    0); // Core where the task should run


}
//#define DebugCFMain
void loop() {

  //if debug then print the values between IMU and Encoder
# 86 "D:\\WorkDirectory\\2DOF_Hover\\Codes\\2DOF_Full_Code\\2DOF_Full_Code.ino"
}
