#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

DHT dht(DHTPIN,DHTTYPE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print(F("DHTxx tedt"));
  dht.begin();
   Serial.println("oled test");
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
   display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0,  10 );
}

void loop() {
  // put your main code here, to run repeatedly:
 float h = dht.readHumidity();
 float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  int a=analogRead(15);
  Serial.println("the ldr value is");
  Serial.println(a);
  delay(2000);
   display.println("humidity");
    display.print(h);
     display.println("temperature");
      display.print(t);
       display.println("intensity");
        display.print(a);
         delay(2000);
 display.clearDisplay();


  
  display.display(); 


}
