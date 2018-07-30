import smbus 
import time
# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
address1 = 0x04
address2 = 0x05

def writeNumber(address,value):
	bus.write_byte(address, value)
# bus.write_byte_data(address, 0, value)
	return -1

def readNumber(address):
	number = bus.read_byte(address)
# number = bus.read_byte_data(address, 1)
	return number

while True:
	var1 = input("Enter 1-9:")
	if not var1:
		continue
	
	writeNumber(address1,var1)
	print("RPI: Hi Arduino1, I sent you ", var1)
	# sleep one second
	time.sleep(1)
	
	var2 = input("Enter 1-9:")
	if not var2:
		continue
	writeNumber(address2,var2)
	print("RPI: Hi Arduino2, I sent you ", var2)
	# sleep one second
	time.sleep(1)
	
	number = readNumber(address1)
	print("Arduino1: Hey RPI, I received a digit ", number)
	number = readNumber(address2)
	print("Arduino2: Hey RPI, I received a digit ", number)
	
