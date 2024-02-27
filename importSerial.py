import serial
import keyboard
import time

# Connect to Arduino over serial port
ser = serial.Serial('/dev/cu.usbmodem142201', 9600)  # Change 'COM3' to your Arduino's port

def send_command(command):
    ser.write(command.encode())

try:
    while True:
        if keyboard.is_pressed('right arrow'):
            print("Moving servo right")
            send_command('R')
            time.sleep(0.1)  # Delay for stability
        elif keyboard.is_pressed('left arrow'):
            print("Moving servo left")
            send_command('L')
            time.sleep(0.1)  # Delay for stability

except KeyboardInterrupt:
    print("Program terminated")
    ser.close()