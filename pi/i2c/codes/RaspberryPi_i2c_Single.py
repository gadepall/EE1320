import smbus
import time
#(1) denotes the I2C port being used.
bus = smbus.SMBus(1)
vi=5;
b=0;
r1=1000;
# These are the Arduino addresses.
address1 = 0x04

def readNumber(address):#Passing the address as a parameter to the the read function.
    number = (bus.read_byte(address)) #Reading from the slave.
    return number

while True:
    time.sleep(1)
    n=(readNumber(address1)*5)
    vo=(n*vi)/1024.0;
    b=(vi/vo)-1;
    r2=r1/b;
    print ('The resistance value measured 1 is :', r2)

