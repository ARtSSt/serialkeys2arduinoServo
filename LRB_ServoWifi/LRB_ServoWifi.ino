//This Code is to support ESP32-WROOM-32 setting up a server and recieving key commands from PC client to move a servo
//This is not the most secure method abd you should not publish code online with your Wifi network and password listed in lines 9,10.
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include <ESP32Servo.h> //Make sure this is set correctly and not <Servo.h> which is often default and not supprted on this board

const char* ssid = "Your Wifi Network Name"; //only works for 2g channels
const char* password = "Wifi Password"; //Your wifi pwd

WebServer server(80); //port 80 is a generic open port
Servo servo;

const int ledPin = 2;
bool ledState = false;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  servo.attach(27); //this is the pin I am using on my board, change to the one you choose to use

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: "); //here i print the IP adress of this module on this subnet for use in client side signal
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/plain", "ESP32 Server");
  });

  server.on("/control", HTTP_GET, []() {
    if (server.hasArg("command")) {
      String command = server.arg("command");
      if (command == "L") {
        servo.write(180); // Rotate servo to 180 degrees
      } else if (command == "R") {
        servo.write(0); // Rotate servo to 0 degrees
      } else if (command == "B") {
        ledState = !ledState; // Toggle LED state
        digitalWrite(ledPin, ledState);
      }
      server.send(200, "text/plain", "OK");
    } else {
      server.send(400, "text/plain", "Invalid request");
    }
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
