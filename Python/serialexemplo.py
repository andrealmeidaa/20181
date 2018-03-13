import time
from serial import Serial

canalSerial=Serial('/dev/ttyACM1',9600)
canalSerial.write(b'Vermelho OFF')
canalSerial.flush()
time.sleep(1)
canalSerial.write(b'Verde ON')
time.sleep(1)
canalSerial.flush()
