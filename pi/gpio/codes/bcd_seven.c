#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (0, OUTPUT) ;
  pinMode (1, OUTPUT) ;
  pinMode (2, OUTPUT) ;
  pinMode (3, OUTPUT) ;
  for (;;)
  {
   digitalWrite (0, 1);
   digitalWrite (1, 0) ;
   digitalWrite (2, 1) ;
   digitalWrite (3, 0) ;
  }
  return 0 ;
}	
//Command for raspberry pi
//gcc -Wall -o test bcd_seven.c -lwiringPi
//followed by 
// sudo ./test
