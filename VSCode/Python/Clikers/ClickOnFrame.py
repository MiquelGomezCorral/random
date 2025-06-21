import pyautogui as pg
import numpy as np
from ScreenShoot import get_image
from pynput.keyboard import *

BaseDelay = 0.02
triggerK = KeyCode.from_char('z')
exitK = KeyCode.from_char('q')
porK = KeyCode.from_char('x')
paused = True; runing = True
cliclPorK = True
cliclPor = 1

def on_pressK(key):
    global paused, runing, cliclPorK, cliclPor
    if key == triggerK:
        paused = not paused
    elif key == exitK:
        runing = False
        print("'q' PRESED. EXITING.")
    elif key == porK:
        cliclPorK = False
        cliclPor = (cliclPor+1)%5
        if cliclPor == 0: cliclPor = 1        
        print(f"Current click velocity: {cliclPor}.")

maxClickCount = 100
#startx = 400; starty = 270; maxx = 1050; maxy = 500; pixelSkip = 85
startx = 30; starty = 60; maxx = 1890; maxy = 990; pixelSkip = 70
def main():
    global paused,runing
    Clicks = 0; clickStart = False
    
    listen = Listener(on_press=on_pressK)
    listen.start()

    while runing:
        if(paused): continue 
        if(not clickStart): #Click in the middle to start
            pg.click(startx+maxx/2, starty+maxy/2)
            clickStart = True
            
        capture = pg.screenshot(region=(startx, starty, maxx, maxy))
        pixels = capture.getdata()
        px=0; py = 0; i = 0
        while(i < len(pixels)):
            if pixels[i] == (127, 217, 254):
                px = i%maxx; py = i//maxx
                break
            i+=pixelSkip 
            #End while loop
        px+=startx; py+=starty
        pg.click(px, py)
        pg.PAUSE = BaseDelay/cliclPor
        
        Clicks+=1
        if(Clicks>=maxClickCount): 
            Clicks = 0
            paused = True
            #qclickStart = False
        #End while loop
    listen.stop()

main()
