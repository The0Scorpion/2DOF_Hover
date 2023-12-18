  /**
     Complete project details at https://RandomNerdTutorials.com/arduino-load-cell-hx711/
  
     HX711 library for Arduino - example file
     https://github.com/bogde/HX711
  
     MIT License
     (c) 2018 Bogdan Necula
  
  **/
  
  #include <Arduino.h>
  #include "HX711.h"
  #include <ESP32Servo.h>
  
  // HX711 circuit wiring
  const int LOADCELL_DOUT_PIN = 21;
  const int LOADCELL_SCK_PIN = 22;
  Servo ESC;     // create servo object to control the ESC
  HX711 scale;
  int potValue;  // value from the analog pin
  float maxload = 0;
  void setup() {
    Serial.begin(115200);
    //Serial.println("HX711 Demo");
    //Serial.println("Initializing the scale");
    ESC.attach(5, 1000, 2000); // (pin, min pulse width, max pulse width in microseconds)
    ESC.write(0);
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  
    //Serial.println("Before setting up the scale:");
    //Serial.print("read: \t\t");
    //Serial.println(scale.read());      // print a raw reading from the ADC
  
    //Serial.print("read average: \t\t");
    //Serial.println(scale.read_average(20));   // print the average of 20 readings from the ADC
  
    //Serial.print("get value: \t\t");
    //Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight (not set yet)
  
    //Serial.print("get units: \t\t");
    //Serial.println(scale.get_units(5), 1);  // print the average of 5 readings from the ADC minus tare weight (not set) divided
    // by the SCALE parameter (not set yet)
  
    scale.set_scale(-370);
    //scale.set_scale(-471.497);                      // this value is obtained by calibrating the scale with known weights; see the README for details
    scale.tare();               // reset the scale to 0
    //
    //  Serial.println("After setting up the scale:");
    //
    //  Serial.print("read: \t\t");
    //  Serial.println(scale.read());                 // print a raw reading from the ADC
    //
    //  Serial.print("read average: \t\t");
    //  Serial.println(scale.read_average(20));       // print the average of 20 readings from the ADC
    //
    //  Serial.print("get value: \t\t");
    //  Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight, set with tare()
    //
    //  Serial.print("get units: \t\t");
    //  Serial.println(scale.get_units(5), 1);        // print the average of 5 readings from the ADC minus tare weight, divided
    //            // by the SCALE parameter set with set_scale
  
    //Serial.println("Readings:");
    Serial.print("Power,");
    Serial.println("Lift");
    ESC.write(0);
  }
  
  void loop() { //potValue = analogRead(A1);   // reads the value of the potentiometer (value between 0 and 1023)
    if (Serial.available()) {
      potValue = Serial.parseInt();
      ESC.writeMicroseconds(potValue);
      delay(2000);
      for (int i = 0; i < 40; i++) {
        ESC.write(potValue);    // Send the signal to the ESC
        Serial.print((float)potValue);
        Serial.print(", ");
        float value = scale.get_units(1);
        Serial.print(value, 1);
        Serial.print(", ");
        if (value < maxload)maxload = value;
        Serial.println(maxload, 1);
      }
      Serial.read();
      potValue = Serial.parseInt();
      unsigned long st = millis();
      for (int i = 0; i < 160; i++) {
        st = millis();
        ESC.writeMicroseconds(potValue);    // Send the signal to the ESC
        Serial.print((float)potValue);
        Serial.print(", ");
        float value = scale.get_units();
        Serial.print(value, 1);
        Serial.print(", ");
        if (value < maxload)maxload = value;
        Serial.println(maxload, 1);
        while (millis() - st < 12)delay(1);
      }
      potValue = 0;
      ESC.write(0);
      Serial.flush();
      while (Serial.available())Serial.read();
    }
  
  }
