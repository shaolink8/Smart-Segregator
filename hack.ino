#include <ESP8266WiFi.h>;
#include <DHT.h> 
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
//#include <math.h> 

DHT dht(13,DHT11);

const int trigPin = 2;  
const int echoPin = 0;  
const char* ssid = "Shaolin's World";
const char* password = "sixtimes21"; 

WiFiClient client;

unsigned long myChannelNumber = 1012728; 
const char * myWriteAPIKey = "SOSBGI5TYN22Q8MV";

void setup()

{
  
Serial.begin(9600);

pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT); 

WiFi.begin(ssid, password);
ThingSpeak.begin(client);
dht.begin();

}
  
void loop()

{
  
  long duration;
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  
  duration=pulseIn(echoPin,HIGH);
  
  float distance=duration*0.034/2;
  
  Serial.print("Distance = ");
  Serial.println(distance);
  
  float humidity=dht.readHumidity();
  float temperature=dht.readTemperature();
  
  if(isnan(humidity)||isnan(temperature))
  
  {
  
    Serial.println("Error reading");
    return;
  
  }
  
  float heatIndex=dht.computeHeatIndex(temperature,humidity,false);
  
  Serial.print("Humidity = ");
  //Serial.print(humidity);
  Serial.print(humidity/100);
  Serial.println("%");
  Serial.print("Temperature = ");
  Serial.println(temperature);
  //Serial.println("°C");
  Serial.print("Heat Index = "); 
  Serial.println(heatIndex);
  Serial.println("");
  
  delay(500);
  
  ThingSpeak.writeField(myChannelNumber, 1,temperature, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2,humidity, myWriteAPIKey); 
  ThingSpeak.writeField(myChannelNumber, 3,distance, myWriteAPIKey); 
  
}
