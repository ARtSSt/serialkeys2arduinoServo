#THis code is to support sending Commands from a client PC side to Arduino ESP32-WROOM-32 server for system controls
import requests

# Replace with your ESP32's IP address
esp32_ip = "You Module IP here" #this should be your server IP on LAN

# Define the URL for sending commands
url = f"http://{esp32_ip}/control"

# Function to send command to ESP32
def send_command(command):
    try:
        response = requests.get(url, params={"command": command})
        if response.status_code == 200:
            print(f"Command {command} sent successfully.")
        else:
            print(f"Failed to send command {command}.")
    except Exception as e:
        print(f"Error occurred: {e}")

# Continuously prompt user for commands until they enter 'quit'
while True:
    command = input("Enter command (L, R, B) or 'quit' to exit: ").strip().upper()
    
    if command == 'QUIT':
        print("Exiting...")
        break
    
    if command in ['L', 'R', 'B']:
        send_command(command)
    else:
        print("Invalid command. Please enter 'L', 'R', 'B', or 'quit'.")
