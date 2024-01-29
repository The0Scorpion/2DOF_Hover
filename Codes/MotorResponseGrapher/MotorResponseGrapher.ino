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


Servo Fmotor, Rmotor, Bmotor, Lmotor;
int potValue;  // value from the analog pin
float maxload = 0;
void setup() {
  Serial.begin(115200);
  //Serial.println("HX711 Demo");
  //Serial.println("Initializing the scale");
  Fmotor.attach(26, 1000, 2000); // (pin, min pulse width, max pulse width in microseconds)
  Rmotor.attach(27, 1000, 2000);
  Bmotor.attach(16, 1000, 2000);
  Lmotor.attach(17, 1000, 2000);

  Fmotor.write(0); // (pin, min pulse width, max pulse width in microseconds)
  Rmotor.write(0);
  Bmotor.write(0);
  Lmotor.write(0);
  // scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);

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

  //scale.set_scale(-370);
  //scale.set_scale(-471.497);                      // this value is obtained by calibrating the scale with known weights; see the README for details
  //scale.tare();               // reset the scale to 0
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
}

void loop() { //potValue = analogRead(A1);   // reads the value of the potentiometer (value between 0 and 1023)
  if (Serial.available()) {
    potValue = Serial.parseInt();
    Fmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
    Rmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
    Bmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
    Lmotor.writeMicroseconds(potValue);
    delay(2000);
    for (int i = 0; i < 40; i++) {
      Fmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
      Rmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
      Bmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
      Lmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
    }
    Serial.read();
    potValue = Serial.parseInt();
    unsigned long st = millis();
    for (int i = 0; i < 160; i++) {
      st = millis();
      Fmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
      Rmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
      Bmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
      Lmotor.writeMicroseconds(potValue);    // Send the signal to the Fmotor
    }
    potValue = 0;
    Fmotor.write(0); // (pin, min pulse width, max pulse width in microseconds)
    Rmotor.write(0);
    Bmotor.write(0);
    Lmotor.write(0);
    Serial.flush();
    while (Serial.available())Serial.read();
  }

}
