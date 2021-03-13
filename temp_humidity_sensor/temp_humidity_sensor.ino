#include <DHT.h>


#define DHTTYPE DHT11   // DHT 11
#define DHT11_PIN 4

DHT dht(DHT11_PIN,DHTTYPE);

void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();  
  Serial.print("Temperature = ");
  Serial.println(t);
  Serial.print("Humidity = ");
  Serial.println(h);
  delay(1000);
}
