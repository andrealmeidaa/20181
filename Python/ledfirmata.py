import pyfirmata

PIN = 12 
DELAY = 2 

PORT = '/dev/ttyACM0'

board = pyfirmata.Arduino(PORT)

while True:
    board.digital[PIN].write(1) 
    board.pass_time(DELAY)
    board.digital[PIN].write(0)
    board.pass_time(DELAY)
