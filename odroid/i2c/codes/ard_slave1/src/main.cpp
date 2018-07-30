/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
#include <Wire.h>

#define SLAVE_ADDRESS 0x05
int number = 0;
int state = 0;
void sendData();
void receiveData(int byteCount);

void setup() {
pinMode(13, OUTPUT);
Serial.begin(9600); // start serial for output
// initialize i2c as slave
Wire.begin(SLAVE_ADDRESS);

// define callbacks for i2c communication
Wire.onReceive(receiveData);
Wire.onRequest(sendData);

Serial.println("Ready!");
}

void loop() {
delay(100);
}

// callback for received data
void receiveData(int byteCount){

while(Wire.available()) {
number = Wire.read();
Serial.print("data received: ");
Serial.println(number);

if (number == 1){

if (state == 0){
digitalWrite(13, HIGH); // set the LED on
state = 1;
}
else{
digitalWrite(13, LOW); // set the LED off
state = 0;
}
}
}
}

// callback for sending data
void sendData(){
Wire.write(number);
}

//#ifndef LED_BUILTIN
//#define LED_BUILTIN 13
//#endif

//void setup()
//{
  //// initialize LED digital pin as an output.
  //pinMode(LED_BUILTIN, OUTPUT);
//}

//void loop()
//{
  //// turn the LED on (HIGH is the voltage level)
  //digitalWrite(13, 1);

  //// wait for a second
  //delay(500);

  //// turn the LED off by making the voltage LOW
  //digitalWrite(13,0);

   //// wait for a second
  //delay(500);
//}
