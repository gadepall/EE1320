#include <wiringPi.h>
int main (void)
{
  wiringPiSetup () ;
  pinMode (0, OUTPUT) ;//a
  pinMode (1, OUTPUT) ;//b
  pinMode (2, OUTPUT) ;//c
  pinMode (3, OUTPUT) ;//d
  pinMode (4, OUTPUT) ;//e
  pinMode (5, OUTPUT) ;//f
  pinMode (12, OUTPUT) ;//g
  for (;;)
  {
    digitalWrite (0,  0) ; 
	digitalWrite (1,  0) ;
    digitalWrite (2,  0) ;
	digitalWrite (3,  0) ;
    digitalWrite (4,  0) ;
	digitalWrite (5,  0) ;
	digitalWrite (12,  1) ;
    
   
  }
  return 0 ;
}	
//Run following statements on terminal
//gcc -Wall -o 7seg 7seg.c -lwiringPi
//followed by 
// sudo ./7seg
