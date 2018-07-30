#!usr/bin/env python

import time
import minimalmodbus
import serial


instrument = minimalmodbus.Instrument('/dev/ttyUSB0',1)         
vi=5;#VCC
r1=1000;#1K known resistance 

#Modbus Configuration for Master
instrument.serial.baudrate  = 19200
instrument.serial.bytesize  = 8
instrument.serial.parity    = serial.PARITY_NONE
instrument.serial.stopbits  = 1
instrument.serial.timeout   = 1                             
instrument.mode             = minimalmodbus.MODE_RTU        


while 1:

	try:
		#Reading  resistor[0] in slave
		test_reg = instrument.read_registers(0,1)               
	#                        print (test_reg)
		#Calculating the resistance using voltage level
		vo=(test_reg[0]*vi)/1024.0;
		b=(vi/vo)-1;
		r2=r1/b;
		print ('The resistance value measured from 1 is:', r2)
		#polling every 0.5 seconds
		time.sleep (0.5)               
	except:
		print ("error USB2 -----")
		time.sleep (1)
        
