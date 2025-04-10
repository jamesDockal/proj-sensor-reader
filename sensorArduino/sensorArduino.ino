#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
int lm35 = 2;
int dht11 = 4;
int light = 1;


int luz = 0;
int umidade = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(lm35,INPUT);
  pinMode(light,INPUT);
  pinMode(dht11, INPUT);

}

void loop() {
float temperatura = analogRead(lm35);
 luz = analogRead(light);
 umidade - digitalRead(dht11);
 
 float h = dht.readHumidity();
 float t2 = dht.readTemperature();
 
 Serial.print("{  \"sensor\":\"temperatura\",  \"valor\": ");
 Serial.print(t2);
 Serial.println(" }");
 Serial.print("{  \"sensor\":\"luminosidade\",  \"valor\": ");
 Serial.print(luz);
 Serial.println(" }");
 Serial.print("{  \"sensor\":\"umidade\",  \"valor\": ");
 Serial.print(h);
 Serial.println(" }");
 delay(3000);
 }
