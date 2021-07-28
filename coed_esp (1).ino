#include <SerialCommand.h>
SerialCommand SCmd;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "id blynk";
char ssid[] = "id wifi";
char pass[] = "password";
int val;                                 
void setup() 
{
  Serial.begin(9600); 
  SCmd.addCommand("B",DATA);
  Blynk.begin(auth, ssid, pass)
}

void loop() 
{ Blynk.run();
  SCmd.readSerial();
Blynk.virtualWrite(V1,val);                  

void DATA(){ char*arg; arg = SCmd.next();val=atoi(arg);} 
