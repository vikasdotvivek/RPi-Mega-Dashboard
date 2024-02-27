import time
import RPi.GPIO as GPIO

counts1=0
counts2=0
counts3=0
counts4=0

#@staticmethod
def primary(counts1):
    #global counts
    counts1 += 1

def secondary(counts2):
    counts2 += 1

def speed(counts3)
    counts3 += 1

def fuel(counts4)
    counts4 += 1

def main():

    primary(counts1)
    print(counts1)

    secondary(counts2)
    print(counts2)

    speed(counts3)
    print(counts3)



    try:
        while True:
            time.sleep(0,1)

    except KeyboardInterrupt:
        GPIO.cleanup()

GPIO.setmode(GPIO.BCM)

#primary
GPIO.setup(2,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.add_event_detect(2,GPIO.FALLING,callback=primary())

#secondary
GPIO.setup(3,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.add_event_detect(3,GPIO.FALLING,callback=secondary())

#speed
GPIO.setup(4,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.add_event_detect(4,GPIO.FALLING,callback=speed())

#fuel
GPIO.setup(17,GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.add_event_detect(17,GPIO.FALLING,callback=fuel())

if __name__ == "__main__":
    main()
