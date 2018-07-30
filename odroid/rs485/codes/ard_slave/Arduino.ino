#include <ModbusRtu.h>

#define TXEN	4 

// data array for modbus network sharing
uint16_t au16data[16] = {
  3, 1415, 9265, 4, 2, 7182, 28182, 8, 0, 0, 0, 0, 0, 0, 1, -1 };

Modbus slave(1,0,TXEN); 

void setup() {
  slave.begin( 19200 ); 
}

void loop() {
  slave.poll( au16data, 16 );
}
