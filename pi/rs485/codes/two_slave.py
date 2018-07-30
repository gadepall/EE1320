#!usr/bin/env python

import time
import minimalmodbus
import serial


instrument = minimalmodbus.Instrument('/dev/ttyUSB0',1)         
instrument2 = minimalmodbus.Instrument('/dev/ttyUSB0',2)        
vi=5;
b=0;
r1=1000;

instrument.serial.baudrate   = 19200
instrument.serial.bytesize   = 8
instrument.serial.parity     = serial.PARITY_NONE
instrument.serial.stopbits   = 1
instrument.serial.timeout    = 1                             
instrument.mode              = minimalmodbus.MODE_RTU        

instrument2.serial.baudrate  = 19200
instrument2.serial.bytesize  = 8
instrument2.serial.parity    = serial.PARITY_NONE
instrument2.serial.stopbits  = 1
instrument2.serial.timeout   = 1                             
instrument2.mode             = minimalmodbus.MODE_RTU        

usb1_on = True
usb2_on = True

while 1:
	if usb2_on == True :
		try:
			print ("USB1")
			test_reg = instrument2.read_registers(0,1)              
			print (test_reg[0])
			vo=(test_reg[0]*vi)/1024.0;
			b=(vi/vo)-1;
			r2=r1/b;
			print ('The resistance value measured from 1 is:', r2)
			time.sleep (0.05)
		except:
			print ("error USB1")
			time.sleep (1)
			
			
	if usb1_on == True :
		try:
			print ("USB2")
			test_reg = instrument.read_registers(0,1)               
			print (test_reg)
			vo=(test_reg[0]*vi)/1024.0;
			b=(vi/vo)-1;
			r2=r1/b;
			print ('The resistance value measured from 2 is:', r2)
			time.sleep (0.5)               
		except:
			print ("error USB2 ")
			time.sleep (1)
	
	
