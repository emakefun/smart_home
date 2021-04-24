
#include "SoftI2CMaster.h"
#include "LiquidCrystal_SoftI2C.h"
#include "DHT.h"

LiquidCrystal_SoftI2C mylcd(0x27,16,2,7,A0);
DHT dhtA3(A3, 11);

void setup(){
  mylcd.init();
  mylcd.backlight();
   dhtA3.begin();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  mylcd.setCursor(0, 0);
  mylcd.print(String("T:") + String(dhtA3.readTemperature()));
  mylcd.setCursor(0, 1);
  mylcd.print(String("H:") + String(dhtA3.readHumidity()));
  if (dhtA3.readTemperature() > 35 || dhtA3.readHumidity() > 45) {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    delay(1000);

  } else {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);

  }

}
