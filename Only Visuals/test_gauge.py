#!/usr/bin/env python3
from tkinter import *
import tkinter as tk
from tkinter.font import Font
from tkinter import messagebox
import time
import random
import gaugelib
'''
import RPi.GPIO as gpio

gpio.setmode(gpio.BCM)
gpio.setwarnings(False)

hallpin = 2
counts=0

gpio.setup( hallpin, gpio.IN)


#while True:
if(gpio.input(hallpin) == False):
        counts+=1

'''
win = tk.Tk()
a5 = PhotoImage(file="g1.png")
win.tk.call('wm', 'iconphoto', win._w, a5)
win.title("Team Jatayu")
win.geometry("1920x1080+0+0")
win.resizable(width=True, height=True)
win.configure(bg='black')

g_value=0
x=0

def read_every_second():
    global x
    g_value=random.randint(0,4000)
    p1.set_value(int(g_value))
    g_value=random.randint(0,60)
    p2.set_value(int(g_value))
    g_value=random.randint(0,100)
    p3.set_value(int(g_value))
    g_value=random.randint(0,125)
    p4.set_value(int(g_value))
    x+=1    
    if x>100:
#        graph1.draw_axes()
        x=0
    win.after(100, read_every_second)

p1 = gaugelib.DrawGauge2(
    win,
    max_value=4000,
    min_value=0,
    size=600,
    bg_col='black',
    unit = "RPM",bg_sel = 2)
p1.pack(side=LEFT)
p2 = gaugelib.DrawGauge2(
    win,
    max_value=60,
    min_value= 0.0,
    size=600,
    bg_col='black',
    unit = "Speed",bg_sel = 2)
p2.pack(side=RIGHT)

p3 = gaugelib.DrawGauge3(
    win,
    max_value=100.0,
    min_value= 0.0,
    size=500,
    bg_col='black',
    unit = "Fuel",bg_sel = 1)
p3.pack()
p4 = gaugelib.DrawGauge3(
    win,
    max_value=125.0,
    min_value= 0.0,
    size=500,
    bg_col='black',
    unit = "Temp",bg_sel = 2)
p4.pack()

read_every_second()
mainloop()
