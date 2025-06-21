import numpy as np
from PIL import ImageGrab

def get_image(left, top , width, height):
    printscreen_pil = ImageGrab.grab((left,top,left+width,top+height))
    printscreen_numpy = np.array(printscreen_pil.getdata(), dtype='uint8') \
        .reshape((printscreen_pil.size[1], printscreen_pil.size[0], 3))
    return printscreen_numpy

