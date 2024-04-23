from ColorPrinter import *
import serial
import time

arduino = serial.Serial(port='COM4',  baudrate=115200, timeout=1)

HOOD = 0
ENGINE = 0

WHEEL_L = 0
WHEEL_R = 0

HEADLIGHT_L = 0
HEADLIGHT_R = 0

value = "000000"

while True:
    time.sleep(.01)

    try:
        value = arduino.readline().decode('utf-8').rstrip()
    except:
        printRedB("Failed to read serial from arduino.")
    
    if (len(value) >= 6):

        a = int(value[0])
        b = int(value[1])
        c = int(value[2])
        d = int(value[3])
        e = int(value[4])
        f = int(value[5])

        if(HOOD!=a):
            HOOD=a

            if(HOOD==1):
                printBlue("Hood closed!")
            else:
                printLightBlue("Hood opened!")
                
        if(ENGINE!=b):
            ENGINE=b
    
            if(ENGINE==1):
                printRed("Engine placed!")
            else:
                printLightRed("Engine removed!")
            

        if(WHEEL_L!=c):
            WHEEL_L=c
        
            if(WHEEL_L==1):
                printGreen("Left wheel connected!")
            else:
                printLightGreen("Left wheel disconnected!")
            
        if(WHEEL_R!=d):
            WHEEL_R=d
    
            if(WHEEL_R==1):
                printMagenta("Right wheel connected!")
            else:
                printMagenta("Right wheel disconnected!")
            
        if(HEADLIGHT_L!=e):
            HEADLIGHT_L=e
        
            if(HEADLIGHT_L==1):
                printYellow("Left Headlight inserted!")
            else:
                printLightYellow("Left Headlight removed!")
            
        if(HEADLIGHT_R!=f):
            HEADLIGHT_R=f

            if(HEADLIGHT_R==1):
                printCyan("Right Headlight inserted!")
            else:
                printLightCyan("Right Headlight removed!")

        '''
        print("HO=" + str(HOOD) + " | EN="  + str(ENGINE) + 
              " | WL="  + str(WHEEL_L) + " | WR="  + str(WHEEL_R) + 
              " | HL="  + str(HEADLIGHT_L) + " | HR="  + str(HEADLIGHT_R))
        '''
