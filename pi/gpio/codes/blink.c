#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (10, OUTPUT) ;
  for (;;)
  {
    digitalWrite (10, HIGH) ; delay (500) ;
    digitalWrite (10,  LOW) ; delay (500) ;
   
  }
  return 0 ;
}	
//Command for raspberry pi
//gcc -Wall -o blink blink.c -lwiringPi
//followed by 
// sudo ./blink
