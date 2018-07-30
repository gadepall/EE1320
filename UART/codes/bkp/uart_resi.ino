#include "Arduino.h"

int V_out_q=0;
float V_in=5,V_out;
float R1=220;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  int R2=0;
  V_out_q=analogRead(0);
  V_out=V_in*V_out_q/1024;
  R2=R1*((V_in)/(V_out)-1.0);
  delay(3000);
  Serial.write(R2);
  Serial.println(R2);
}
