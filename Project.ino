//Including libraries
#include<ESP8266WiFi.h>  // Library for ESP8266 WiFi

const char *ssid="*****";  //  local WiFi name  ssid(service set identifier)
const char *pwd="*****";  // local WiFi pwd(password)

void setup() {
  Serial.begin(9600);  //to STARTS serial communication
  Serial.println("WiFi Connecting to "+String(ssid));  // WiFi Connection with local network
  WiFi.begin(ssid,pwd);  // WiFi connection with SSID and Password
  while(WiFi.status()!= WL_CONNECTED)  // WiFi Status Checking
  {
    Serial.print(".....");
    delay(300);
  }
  Serial.println("\n WiFi Connected with "+String(ssid));  // WiFi Connected and display the IP address
  Serial.println("IP Address : ");  // IP address of connected network
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:

}
