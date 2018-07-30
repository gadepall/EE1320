#imporing serial package
import serial

#setting baudrate and giving the port
ser = serial.Serial(port = "/dev/ttyS0", baudrate=9600)

print "Serial is open!"
while 1:
        data=ser.read(1)
	#read the GPIO 16 pin
        print data
