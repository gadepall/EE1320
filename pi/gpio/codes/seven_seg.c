#include <wiringPi.h>
int main (void)
{
  int Z=1,Y=0,X=0,W=1;
  int D=1,C=0,B=0,A=1;
  int a,b,c,d,e,f,g;
  wiringPiSetup () ;
  pinMode (0, OUTPUT) ;
  pinMode (1, OUTPUT) ;
  pinMode (2, OUTPUT) ;
  pinMode (3, OUTPUT) ;
  pinMode (4, OUTPUT) ;
  pinMode (5, OUTPUT) ;
  pinMode (6, OUTPUT) ;
 
  for (;;)
  {
  
 D = (W&&X&&Y&&!Z) || (!W&&!X&&!Y&&Z);
  C = (W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  B = (W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
  A = (!W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z) || (!W&&!X&&!Y&&Z);
   
a = (A&&!B&&!C&&!D) || (!A&&!B&&C&&!D);
b = (A&&!B&&C&&!D) || (!A&&B&&C&&!D);
c = (!A&&B&&!C&&!D);
d = (A&&!B&&!C&&!D) || (!A&&!B&&C&&!D) || (A&&B&&C&&!D);
e = (A&&!B&&!C&&!D) || (A&&B&&!C&&!D) || (!A&&!B&&C&&!D) || (A&&!B&&C&&!D) || (A&&B&&C&&!D) || (A&&!B&&!C&&D);
f = (A&&!B&&!C&&!D) || (!A&&B&&!C&&!D) || (A&&B&&!C&&!D) || (A&&B&&C&&!D);
g = (!A&&!B&&!C&&!D) || (A&&!B&&!C&&!D) || (A&&B&&C&&!D);
  
 /*  digitalWrite (0, A);
   digitalWrite (1, B) ;
   digitalWrite (2, C) ;
   digitalWrite (3, D) ;
   * */
    digitalWrite(0, a);
  digitalWrite(1, b);
  digitalWrite(2, c);
  digitalWrite(3, d);
   digitalWrite(4, e);
  digitalWrite(5, f);
  digitalWrite(6, g);
  
  W=A;
  X=B;
  Y=C;
  Z=D;
  delay(1000);
  }
  return 0 ;
}	
//Command for raspberry pi
//gcc -Wall -o blink blink.c -lwiringPi
//followed by 
// sudo ./blink
