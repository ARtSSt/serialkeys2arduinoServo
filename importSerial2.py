import serial
import keyboard

# Replace with the correct serial port
port = "/dev/cu.usbmodem142201"
baudrate = 9600

# Initialize serial connection
try:
    ser = serial.Serial(port, baudrate)
    print("Serial connection established successfully.")
except serial.SerialException as e:
    print(f"Error opening serial port: {e}")
    exit(1)

# Define key mapping for controlling the servo
key_map = {
    "left": "l",  # Left arrow key
    "right": "r",  # Right arrow key
}

def main():
    while True:
        if keyboard.is_pressed('left') or keyboard.is_pressed('right'):
            key = keyboard.read_event().name
            if key in key_map:
                # Send command to the Arduino based on key pressed
                try:
                    ser.write(key_map[key].encode())
                    print(f"Sent command: {key_map[key]}")
                except serial.SerialException as e:
                    print(f"Error writing to serial port: {e}")

if __name__ == "__main__":
    main()
