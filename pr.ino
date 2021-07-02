#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#include <math.h>

const char* ssid = "Shaolin's World";
const int pResistor = A0; 
const char* password = "sixtimes21"; 

WiFiClient client;

unsigned long myChannelNumber = 1012728; 
const char * myWriteAPIKey = "SOSBGI5TYN22Q8MV";

void setup(){ 

  Serial.begin(9600);  
 
  pinMode(pResistor,INPUT);

  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);

}

int count=0;
  
void loop(){
 
  int value = analogRead(pResistor);

  if((value<20)|(value>50)){
  
  count+=1;

  Serial.println(count);
  
}
  
  Serial.println(value);
  
  ThingSpeak.writeField(myChannelNumber,4,count,myWriteAPIKey);
  

}
