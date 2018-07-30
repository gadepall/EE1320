#include "Arduino.h"
#include <ModbusRtu.h>
#define TXEN  4 

//Storing resistance value
uint16_t resistance[1] = {0};
//To initialize the slave arduino with address 1
//And using 0/1 pin of arduino as TX/RX
//TXEN enables MAX485 transmission
Modbus slave(1,0,TXEN);

void setup() {
//analog pin A3 used for received resistance value 
  pinMode(A3, INPUT);
 //Baudrate at which modbus works
  slave.begin(19200);
}
void loop() {
  resistance[0]=(analogRead(A3));
  slave.poll(resistance, 1); 
}
