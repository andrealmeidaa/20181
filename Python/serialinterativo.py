import time #Controla o tempo 
from serial import Serial #Biblioteca PySerial

canalSerial=Serial('/dev/ttyACM0',9600) 
while True: 
    comando=raw_input("Digite o comado:") 
    if (comando=="Sair"):
        break
    canalSerial.write(comando) 
    canalSerial.flush() 
    time.sleep(1) 
canalSerial.close()
