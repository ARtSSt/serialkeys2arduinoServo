# serialkeys2arduinoServo

This Repo is for use in UCSD VIS 147b as class support material

In this repo we look at 2 ways to move a servo connected to USB, using the keyboard over the serial port. 

Here we will wire a single servo motor with data to pin 9, ground and 5v on the arduino. 
We connect this to the computer via serial USB. 
Once the Arduino Code is upload it is listenening on the port. 
In the .sh and .Py
Notes : 
- if you have the arduino serial monitor open the applications won't connect, please make sure it is closed after testing.
- this was written for use with MacOS it may or may not work out of the box on windows(untested.)
- on Mac the .sh and .py may need elevated permissions depending on your system settings. use the terminal navigate to the files via command line and use the 'sudo chmod +x' cmd to elevate the file permissions. 
