#include <ESP8266WiFi.h>  // Library for ESP8266 WiFi
#include<BlynkSimpleEsp8266.h>  
#include<Ultrasonic.h>  // Library for ultrasonic sensor
#include<SimpleTimer.h>  // A simple Arduino library for work with time



#define BLYNK_PRINT Serial

Ultrasonic ultrasonic(7);  // Defining the pin number


const char* auth="";  // You should get Auth Token in the Blynk App.
const char* ssid="";  //  local WiFi name  ssid(service set identifier)
const char* pwd="";  // local WiFi pwd(password)


SimpleTimer t;


void setup()
{
  Serial.begin(9600);  // to STARTS serial communication


  Blynk.begin(auth, ssid, pwd);  // Blynk connected to auth, ssid, pwd
  t.setInterval(5000L,thread);  // Setup a function to be called every 5 seconds
  
}

void loop()
{
  Blynk.run();  // keeping connection alive, sending data, receiving data
  t.run();  // // run timer every second
}

void thread()
{
  
 int RangeInInches = ultrasonic.MeasureInInches();
  
 int RangeInCentimeters = ultrasonic.MeasureInCentimeters(); 
 
  Blynk.virtualWrite(V2,RangeInInches);  // sending sensor value to Blynk app
  Blynk.virtualWrite(V3,RangeInCentimeters);   // sending sensor value to Blynk app
}
