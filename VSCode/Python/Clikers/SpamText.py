import customtkinter as cmtk
import pyautogui as pg
from pynput.keyboard import *
import time

# Logic
# =========================================================================
BaseDelay = 0.02
triggerK = KeyCode.from_char('z')
exitK = KeyCode.from_char('q')
porK = KeyCode.from_char('x')
paused = True; runing = True
cliclPorK = True
cliclPor = 1

def on_pressK(key):
    global paused, runing, cliclPorK, cliclPor
    if key == triggerK: #Press z to start/stop
        paused = not paused
    elif key == exitK: #press q to exit
        runing = False
        print("'q' PRESED. EXITING.")
    elif key == porK: #press x to make it go faster
        cliclPorK = False
        cliclPor = (cliclPor+1)%5
        if cliclPor == 0: cliclPor = 1
        print(f"Current click velocity: {cliclPor}.")


def start():
    global BaseDelay
    x = SpamEntry.get()
    BaseDelay = float(DelayEntry.get())
    max = int(MaxIterEntry.get())
    i = 0
    listen = Listener(on_press=on_pressK)
    listen.start()
    while runing:
        if(not paused):
            #pg.click((1920-200,1080-125)) #Coordenadas del pixel de la barra de donde escribes
            #pg.PAUSE = BaseDelay/cliclPor
            pg.write(str(x)) #Texto a enviar
            pg.press('enter')
            #pg.click((1920-73,1080-125)) #Coordenadas del pixel del botón de enviar
            pg.PAUSE = BaseDelay/cliclPor
            i+=1
            if(i >= max): break
        else:
            time.sleep(0.1)
    listen.stop()

def spam():
    print(SpamEntry.get() + " " + DelayEntry.get() + " "+ MaxIterEntry.get())


# GUI
# =========================================================================

cmtk.set_appearance_mode("dark")
cmtk.set_default_color_theme("dark-blue")

root = cmtk.CTk()
#root.geometry("500x")


frame = cmtk.CTkFrame(master=root)
frame.pack(pady=10, padx=60, fill="both", expand=True)

# TEXT
frameTEXT = cmtk.CTkFrame(master=frame)
frameTEXT.pack(pady=2, padx=5, fill="both", expand=False)
TextLabel = cmtk.CTkLabel(master=frameTEXT, text="Text to spam")
TextLabel.pack(pady=2, padx=10)
SpamEntry = cmtk.CTkEntry(master=frameTEXT, placeholder_text="Me cago en tu puta madre")
SpamEntry.pack(pady=2, padx=10)

# Delay
frameDELAY = cmtk.CTkFrame(master=frame)
frameDELAY.pack(pady=2, padx=5, fill="both", expand=False)
TextLabel = cmtk.CTkLabel(master=frameDELAY, text="Delay (s)")
TextLabel.pack(pady=2, padx=10)
DelayEntry = cmtk.CTkEntry(master=frameDELAY, placeholder_text="0.1")
DelayEntry.pack(pady=2, padx=10)

# Repeat until
frameUNTIL = cmtk.CTkFrame(master=frame)
frameUNTIL.pack(pady=2, padx=5, fill="both", expand=False)
MaxIterLabel = cmtk.CTkLabel(master=frameUNTIL, text="Max iterations")
MaxIterLabel.pack(pady=2, padx=10)
MaxIterEntry = cmtk.CTkEntry(master=frameUNTIL, placeholder_text="100")
MaxIterEntry.pack(pady=2, padx=10)

# Repeat until
frameKeys = cmtk.CTkFrame(master=frame)
frameKeys.pack(pady=2, padx=5, fill="both", expand=False)
StartLabel = cmtk.CTkLabel(master=frameKeys, text="KEY TOOLS")
StartLabel.pack(pady=2, padx=10, side="left")
StartLabel = cmtk.CTkLabel(master=frameKeys, text="z to start/stop")
StartLabel.pack(pady=2, padx=10, side="top")
ExitLabel = cmtk.CTkLabel(master=frameKeys, text="q to exit")
ExitLabel.pack(pady=2, padx=10)
IncreaseLabel = cmtk.CTkLabel(master=frameKeys, text="x to Cicle speeds")
IncreaseLabel.pack(pady=2, padx=10)

StartButton = cmtk.CTkButton(master=frame, text="Start", command=start) #(SpamEntry.text, DelayEntry.text)
StartButton.pack(pady=12, padx=10)

root.mainloop()
