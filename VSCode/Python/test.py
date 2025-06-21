import threading 
from concurrent.futures import ThreadPoolExecutor
from time import sleep
py = 0
px = 0

nThreads = 10
executor = ThreadPoolExecutor(10)

def main():
    global py, px
    #print(str(py) + ', ' + str(px))
    with ThreadPoolExecutor(max_workers=10) as executor:
        for index in range(nThreads):
            w = executor.submit(algo,index,index)
    executor.shutdown(wait = True)
    print("Done!")

def algo(i,x):
    print(f'Empiezo {threading.current_thread().name}, call: {i}{x}')
    sleep(i)
    print(f'Termino {threading.current_thread().name}, call: {i}{x}')
    

main()
