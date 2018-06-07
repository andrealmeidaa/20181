import pyfirmata
import signal
import sys

def signal_handler(signal, frame):
  pinoLED.write(0)
  sys.exit(0)
  board.exit()

signal.signal(signal.SIGINT, signal_handler)

PORT = '/dev/ttyACM2'
DELAY = 2
board = pyfirmata.Arduino(PORT)

iterator=pyfirmata.util.Iterator(board)
iterator.start()

pinoLED=board.get_pin("d:12:o")
pinoChama=board.get_pin("a:1:i")
pinoChama.enable_reporting()
#Para ficar com valores semelhantes ao do Arduino, deve ser feita uma regra de três
try:
    while True:
        valor=pinoChama.read()#Varia de 0 a 1
        if (valor!=None):
            if (valor<0.2): 
                pinoLED.write(1) 
            else:
                pinoLED.write(0)
        print(valor)
        board.pass_time(DELAY)
except Exception as e:
    print(str(e))
    pinoLED.write(0)
    board.exit()
