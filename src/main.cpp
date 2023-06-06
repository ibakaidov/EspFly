#include <ESP32Servo.h>
#include "reciver.hpp"
Servo myservo;  // create servo object to control a servo

// Possible PWM GPIO pins on the ESP32: 0(used by on-board button),2,4,5(used by on-board LED),12-19,21-23,25-27,32-33 
#define servoPin 2

void setup() {
  Serial.begin(9600);     // debug info
  initReciver();
  myservo.attach(servoPin); // attaches the servo on pin 18 to the servo object (using timer 0)
  Serial.println("Start IBus2PWM_ESP32");
}

int saveval=0;

void loop() {
  int* channels = readChannels();
  for (size_t i = 0; i < 6; i++)
  {
    Serial.print(i);
    Serial.print(": ");
    Serial.print( channels[i]);
    Serial.print(". ");

  }
  Serial.println();
  delete[] channels;
  delay(100);
}