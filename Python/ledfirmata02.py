import pyfirmata

PIN = 12 
DELAY = 2 

PORT = '/dev/ttyACM0'

board = pyfirmata.Arduino(PORT)

pinoarduino=board.get_pin("d:12:o")
try:
    while True:
        pinoarduino.write(1) 
        board.pass_time(DELAY)
        pinoarduino.write(0)
        board.pass_time(DELAY)
except:
    pinoarduino.write(0)
    board.exit()
