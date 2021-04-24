
#include "DHT.h"

DHT dhtA3(A3, 11);

void setup(){
  Serial.begin(9600);
   dhtA3.begin();
}

void loop(){
  Serial.print(String("Tep:") + String(String(dhtA3.readTemperature()) + String("C")));
  Serial.print(" ");
  Serial.print(String("Hum:") + String(String(dhtA3.readHumidity()) + String("%")));
  Serial.print(" ");
  // 光敏传感器连接A2号管脚
  Serial.println(String("光照强度：") + String(String(analogRead(A2)) + String("%")));
  delay(500);

}
