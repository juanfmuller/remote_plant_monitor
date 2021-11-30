import os
import glob
import time
import board
import math
import busio
import adafruit_ads1x15.ads1015 as ADS
import RPi.GPIO as GPIO
from time import sleep
 
os.system('modprobe w1-gpio')
os.system('modprobe w1-therm')
 
base_dir = '/sys/bus/w1/devices/'
device_folder = glob.glob(base_dir + '28*')[0]
device_file = device_folder + '/w1_slave'
i2c = busio.I2C(board.SCL, board.SDA)
from adafruit_ads1x15.analog_in import AnalogIn
ads = ADS.ADS1015(i2c)
chan0 = AnalogIn(ads, ADS.P0)
chan1 = AnalogIn(ads, ADS.P1)
 
def read_temp_raw():
    f = open(device_file, 'r')
    lines = f.readlines()
    f.close()
    return lines
 
def read_temp():
    lines = read_temp_raw()
    while lines[0].strip()[-3:] != 'YES':
        time.sleep(0.2)
        lines = read_temp_raw()
    equals_pos = lines[1].find('t=')
    if equals_pos != -1:
        temp_string = lines[1][equals_pos+2:]
        temp_c = int(temp_string) / 1000
        temp_f = temp_c * 9 / 5 + 32
        
        #return temp_c, temp_f
        return math.trunc(temp_f)
    
while True:
    with open('moist_values.txt', 'a') as f:
        print(math.trunc(chan0.voltage), file=f)
        print('Humidity:',math.trunc(chan0.voltage))
        with open('temp_values.txt', 'a') as f:
            print(read_temp(), file=f)
            print('Temperature: ', read_temp())	
            time.sleep(1)
