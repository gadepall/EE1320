#include <wiringPi.h>

int A=0,B=0,C=0,D=0,a,b,c,d,e,f,g,W,X,Y,Z,i,j;
int r0; 
unsigned int initialtime, elapsed;
void showit(int x);

int main (void)
{
//Declarations
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

//Decade Counting
for( r0=0;r0<=9;r0++)
{ 
initialtime=millis();
//Counting 1000 milliseconds
for(elapsed=0;elapsed<=1000;elapsed=millis()-initialtime)
{

//Write number to display
showit(r0);

}//end counting 10 sec
} //end counting 1 sec


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
//Display logic
void showit(int x)
{
int D,C,B,A;

//Decimal to Binary conversion
A=x%2;
x=x/2;
B=x%2;
x=x/2;
C=x%2;
x=x/2;
D=x%2;

//BCD to seven segement decoder
a=(!D&&!C&&!B&&A)||(!D&&C&&!B&&!A);
b=(!D&&C&&!B&&A)||(!D&&C&&B&&!A);
c=(!D&&!C&&B&&!A);
d=(!D&&!C&&!B&&A)||(!D&&C&&!B&&!A)||(!D&&C&&B&&A);
e=(!D&&!C&&!B&&A)||(!D&&!C&&B&&A)||(!D&&C&&!B&&!A)||(!D&&C&&!B&&A)||(!D&&C&&B&&A)||(D&&!C&&!B&&A);
f=(!D&&!C&&!B&&A)||(!D&&!C&&B&&!A)||(!D&&!C&&B&&A)||(!D&&C&&B&&A);
g=(!D&&!C&&!B&&!A)||(!D&&!C&&!B&&A)||(!D&&C&&B&&A);

//Writing to display
    digitalWrite (0,  a) ; 
	digitalWrite (1,  b) ;
    digitalWrite (2,  c) ;
	digitalWrite (3,  d) ;
    digitalWrite (4,  e) ;
	digitalWrite (5,  f) ;
	digitalWrite (12,  g) ;
}
	
//Run following statements on terminal
//gcc -Wall -o decade decade.c -lwiringPi
//followed by 
// sudo ./decade
