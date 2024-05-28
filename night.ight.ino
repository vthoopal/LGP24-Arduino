/*this code adjusts the brightness and number of leds based on the light falling on the ir sensor
it also has a dht11 sensor to measure and print temperature and humidity
*/

#include "DHT11.h"igh
DHT11 dht11(2);
int light;
int r=3 ;
int g= 5;
int b = 6;
int w = 10;
int y = 9;
int brightness;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = dht11.readTemperature();
  int hum = dht11.readHumidity();
 analogWrite(r,0);
    analogWrite(g,0);
    analogWrite(b,0);
    analogWrite(w,0);
    analogWrite(y,0);
   light =analogRead(5);
   brightness = map(light,1,1023,1,255);
   Serial.print(light);
   Serial.print("light");
   Serial.print(brightness);
   Serial.println("-");
   Serial.print("TEMP");
   Serial.println(temp);
   Serial.print("HUMIDITY");
   Serial.println(hum);
   long roundbright = light/200;
   if(roundbright<1){
    analogWrite(r,brightness);
   }
   else if(roundbright<2){
    analogWrite(r,brightness);
    analogWrite(g,brightness);
   }
   else if(roundbright<3){
    analogWrite(r,brightness);
    analogWrite(g,brightness);
    analogWrite(b,brightness);
   }
   else if(roundbright<4){
    analogWrite(r,brightness);
    analogWrite(g,brightness);
    analogWrite(b,brightness);
    analogWrite(y,brightness);
   }
   else{
    analogWrite(r,brightness);
    analogWrite(g,brightness);
    analogWrite(b,brightness);
    analogWrite(w,brightness);
    analogWrite(y,brightness);
   }
   delay(500);
}
