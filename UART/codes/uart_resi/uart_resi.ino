//Remove the following line if you are using the Arduino IDE
//#include "Arduino.h"

//Declaration or Initialization
int Vq=0;
float Vcc=5,V0;
float R1=220;
//R1 is known resistance

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int R2=0;
  //R2 is unknown resistance
  Vq=analogRead(0);
  //Reading from A0 and Vq is an integer between 0 to 1023
  V0=Vcc*Vq/1024;
  //V0 is actual output voltage across Unknown resistance R2
  R2=R1*((Vcc)/(V0)-1.0);
  //Formula from voltage divider circuit
  delay(3000);
  Serial.write(R2);
  //Writing the measured resistance to serial port of arduino
  Serial.println(R2);
  //To see the value in serial monitor of Arduino
}
