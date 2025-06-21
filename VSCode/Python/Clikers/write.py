import time
import random
import pyautogui
import keyboard 

pyautogui.PAUSE = 0

split: bool = False
time_delay: float = 0.35 # 0.2 -> 110 WPM

def main(text: str) -> None:
    print("Switch to the desired window and press 'q' to start typing...")
    keyboard.wait('left')  
    
    extra_char: str = ""
    if split:
        text = text.split()
        extra_char = " "
    
    for char in text:
        if keyboard.is_pressed('esc'):
            print("Stopped by user.")
            break
        
        pyautogui.write(f"{char}{extra_char}")
        time.sleep(random.random() * 0.2)

if __name__ == "__main__":
    # text = "I walk a lonely road. The only one that I have ever known. Don't know where it goes, but it's only me, I walk alone."
    # text = "A sapling must have good soil in order to grow strong. Infertile soil will not bring forth splendid fruit."
    # text = "As I fear not a child with a weapon he cannot lift, I will never fear the mind of a man who does not think."
    text = "Hey Jude, don't make it bad. Take a sad song and make it better. Remember to let her into your heart then you can start to make it better."
    main(text)