import subprocess

# Define el comando que quieres ejecutar en Bash
ruta = r"C:\Users\mique\Desktop\honey_kiss_frames\ezgif-frame-010.jpg"
comando_bash = "ascii-image-converter "+ruta+" -d 100,50 -b"

# Ejecuta el comando en Bash y captura la salida
resultado = subprocess.run(comando_bash, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, encoding='utf-8')

# Imprime la salida de Bash
print(resultado.stdout)

# Guarda la salida en un archivo
with open("salida_bash.txt", errors="ignore") as archivo:
    archivo.write(resultado.stdout)