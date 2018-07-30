#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (13, OUTPUT) ;
  for (;;)
  {
    digitalWrite (13, HIGH) ; delay (1000) ;
    digitalWrite (13,  LOW) ; delay (1000) ;
   
  }
  return 0 ;
}	
//Run following statements on terminal
//gcc -Wall -o blink blink.c -lwiringPi
//followed by 
// sudo ./blink
