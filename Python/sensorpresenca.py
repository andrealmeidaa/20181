import time #Controla o tempo 
from serial import Serial #Biblioteca PySerial

canalSerial=Serial('/dev/ttyACM0',9600) 
while True: 
    if canalSerial.inWaiting()>0:
        texto=canalSerial.readline()
        print(texto) 

