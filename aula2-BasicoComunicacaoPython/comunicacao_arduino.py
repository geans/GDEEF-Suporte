# Required pyserial
# Installing:
#   pip install pyserial

import serial
import time

port = 'COMx'  # troque o "x" pelo número da porta que está o arduino
arduino = serial.Serial(port, baudrate=9600, timeout=2, write_timeout=2)
time.sleep(2)  # tempo de guarda após abrir serial

arduino.write(b'1')  # acende o LED
buffer_serial = arduino.readline()
print(buffer_serial.decode("utf8"))  # decodifica os acentos e imprime na tela
time.sleep(2)  # tempo para ver o LED aceso

arduino.write(b'0')  # apaga o LED
buffer_serial = arduino.readline()
print(buffer_serial.decode("utf8"))  # decodifica os acentos e imprime na tela

arduino.close()