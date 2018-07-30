import serial

ser = serial.Serial(port = "/dev/ttyS0", baudrate=9600)

print "Serial is open!"
while 1:
        data=ser.read(1)
        print data
