#include <SerialCommand.h>
SerialCommand SCmd;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "ON5ptYBeEMH8lyw2sytZ_Jm22IYx60aS";
char ssid[] = "netis_C01178";
char pass[] = "password";
int val;                                           //giá trị nhận từ arduino
void setup() 
{
  Serial.begin(9600); 
  SCmd.addCommand("B",DATA);
  Blynk.begin(auth, ssid, pass)
}

void loop() 
{ Blynk.run();
  SCmd.readSerial();
Blynk.virtualWrite(V1,val);                      // gửi lên blynk
}

void DATA(){ char*arg; arg = SCmd.next();val=atoi(arg);} 
