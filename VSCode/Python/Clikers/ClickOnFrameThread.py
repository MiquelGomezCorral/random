import pyautogui as pg
import numpy as np
import threading 
from concurrent.futures import ThreadPoolExecutor
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
        
#----------------------------------------------------------------
maxClickCount = 30
#startx = 400; starty = 270; maxx = 1050; maxy = 500; pixelSkip = 85
startx = 30; starty = 60; maxx = 1890; maxy = 990; pixelSkip = 70
px = 0; py= 0; stop = False
# create a thread pool
# pool = th.ThreadPool(processes=10)
nThreads = 10
def main():
    global paused,runing
    Clicks = 0; clickStart = False
    
    listen = Listener(on_press=on_pressK)
    listen.start()

    while runing:
        if(paused): continue 
        """if(not clickStart): #Click in the middle to start
            pg.click(startx+maxx/2, starty+maxy/2)
            clickStart = True"""
            
        capture = pg.screenshot(region=(startx, starty, maxx, maxy))
        pixels = capture.getdata()
        
        px=0; py = 0; stop = False
        
        with ThreadPoolExecutor(max_workers=10) as executor:
            for index in range(nThreads):
                executor.submit(search, args=(pixels, index,nThreads))
                print(f'thread {index} sent por {threading.current_thread().name}')
        print(f'all work sent por {threading.current_thread().name}')
        executor.shutdown(wait=True)
        
        px+=startx; py+=starty
        pg.click(px, py)
        pg.PAUSE = BaseDelay/cliclPor
        
        Clicks+=1
        if(Clicks>=maxClickCount): 
            Clicks = 0
            paused = True
            """qclickStart = False"""
        #End while loop
    listen.stop()

def search(pixels, start,nThreads):
    print(f'work started por {threading.current_thread().name}')
    global px, py, stop
    f = False
    i = start
    while((i < len(pixels)) and not f and not stop):
        if pixels[i] == (127, 217, 254):
            f = True
            stop = True
            break
        i+=nThreads+pixelSkip 
        #End while loop 
    if(f): 
        px = i%maxx; py = i//maxx
        print(f'Encontrado por {threading.current_thread().name}')

main()
