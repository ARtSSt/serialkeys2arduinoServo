# serialkeys2arduinoServo

This Repo is for use in UCSD VIS 147b as class support material
<br />
•
**This is using traditional USB serial from a Arduino directly connected to a PC**
<br />
In this repo we look at 2 ways to move a servo connected to USB, using the keyboard over the serial port. 

Here we will wire a single servo motor with data to pin 9, ground and 5v on the arduino. 
We connect this to the computer via serial USB. 
Once the Arduino Code is upload it is listenening on the port. 
In the .sh and .Py
Notes : 
- if you have the arduino serial monitor open the applications won't connect, please make sure it is closed after testing.
- this was written for use with MacOS it may or may not work out of the box on windows(untested.)
- on Mac the .sh and .py may need elevated permissions depending on your system settings. use the terminal navigate to the files via command line and use the 'sudo chmod +x' cmd to elevate the file permissions. 

**Using a ESB32-WROOM-32 Module**

Boards I used for testing this : ```https://www.amazon.com/dp/B08246MCL5?psc=1&ref=ppx_yo2ov_dt_b_product_details```

Setup : follow this tutorial ```https://www.instructables.com/Step-by-Step-Tutorial-Setting-Up-ESP32-Board-in-Ar/```

The Files LRB_ServoWifi sets up a client for recieving https request over the LAN. Taking from the LRB_Http.py client code keyboard commands "L" and "R" to rotate a servo on Pin 27 of this board. 
"B" key turns on and off the on board LED to help debug. 
