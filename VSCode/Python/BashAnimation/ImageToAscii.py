import subprocess
import os
import time
import imghdr

CLEAR = "\033[1A\x1b[2K"

def imprimeBash(ruta):
    comando_bash = "ascii-image-converter "+ruta+" -d 100,50"
    resultado = subprocess.run(comando_bash, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, encoding='utf-8')
    # Imprime la s
    # alida de Bash
    print(CLEAR*52, end = "")
    print(resultado.stdout)
    
    # Guarda la salida en un archivo
    #with open("./salida_bash.txt") as archivo:
    #   archivo.write(resultado.stdout)

#carpeta = r"C:\Users\mique\Desktop\honey_kiss_frames\Frames"
carpeta = r"C:\Users\mique\Desktop\pepis\Frames"
imagenes = os.listdir(carpeta)

for image in imagenes:
    time.sleep(0.01)
    ruta = os.path.join(carpeta, image)
    if os.path.isfile(ruta) and imghdr.what(ruta):
        # Estprint(f'Es un archivo: {image}')
        # bash comando + Image path
        imprimeBash(ruta)

