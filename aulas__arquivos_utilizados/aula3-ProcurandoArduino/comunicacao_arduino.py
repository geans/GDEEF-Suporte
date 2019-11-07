# Required pyserial

import serial
import time
from platform import system


# Checking platform
if (system() == 'Windows'):
    nome = 'COM'
elif (system() == 'Linux'):
    nome = '/dev/ttyACM'
arduino_encontrado = False

for numero in range(0, 20):
    porta = nome + str(numero)
    try:
        print("Tentando porta {}".format(numero))
        arduino = serial.Serial(porta, baudrate=9600, timeout=2.0, write_timeout=2.0)
        time.sleep(2)               # tempo de guarda após abrir serial
        arduino.write(b'arduino?')  # consulta arduino
        buffer_serial = arduino.readline().decode("utf-8")
        if buffer_serial == "Sim, sou eu":
            arduino_encontrado = True
            print("  |-> Arduino encontrado na porta {}\n".format(numero))
            break
        else:
            print("  |-> Não encontrado na porta {}".format(numero))
        arduino.close()
    except serial.serialutil.SerialException:
        print("  |-> Porta {} não existe".format(numero))
        pass

if arduino_encontrado == False:
    print("\nArduino não encontrado")
    exit()

arduino.write(b'acender')            # acende o LED
buffer_serial = arduino.readline()
print(buffer_serial.decode("utf8"))  # decodifica os acentos e imprime na tela
time.sleep(2)                        # tempo para ver o LED aceso

arduino.write(b'apagar')             # apaga o LED
buffer_serial = arduino.readline()
print(buffer_serial.decode("utf8"))  # decodifica os acentos e imprime na tela

arduino.close()
