import time
from serial import Serial

canalSerial=Serial('/dev/ttyACM0',9600)
saida1='Vermelho OFF'
canalSerial.write(saida1)
time.sleep(1.8)
saida1='Verde ON'
canalSerial.write(saida1)
canalSerial.close()
