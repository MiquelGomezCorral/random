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

maxClickCount = 1
startx = 400; starty = 270; maxx = 2; maxy = 2; pixelSkip = 1
def main():
    global paused,runing
    Clicks = 0; clickStart = False
    
    listen = Listener(on_press=on_pressK)
    listen.start()

    while runing:
        if(not paused): #Click in the middle to start
            capture = pg.screenshot(region=(startx, starty, maxx, maxy))
            pixels = capture.getdata()
            px=startx; py = starty; 
            while(pixels[0] != (75, 219, 106) and runing and not paused):
                capture = pg.screenshot(region=(startx, starty, maxx, maxy))
                pixels = capture.getdata()
                pass
                #End while loop
            pg.click(px, py)
            pg.PAUSE = BaseDelay/cliclPor
            
            Clicks+=1
            if(Clicks>=maxClickCount): 
                Clicks = 0
                paused = True
            #End while loop
    listen.stop()

#pg.click(startx, starty)
main()
