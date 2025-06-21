import pyautogui as pg
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

def main():
    listen= Listener(on_press=on_pressK)
    listen.start()
    while runing:
        if(not paused):
            pg.click(pg.position())
            pg.PAUSE = BaseDelay/cliclPor
    listen.stop()

main()
