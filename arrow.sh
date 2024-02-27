#!/bin/bash

# Replace with the correct serial port 
port="/dev/cu.usbmodem142201"  

while true; do
  read -rsn1 key  # Read single character without waiting for Enter 

  if [ "$key" = $'\x1b' ]; then  # Detect arrow keys
    read -rsn1 -t 1 key1
    read -rsn1 -t 1 key2

    if [ "$key1" = "[" ]; then
      if [ "$key2" = "D" ]; then echo "l" > $port 
      elif [ "$key2" = "C" ]; then echo "r" > $port
      fi
    fi
  fi
done
