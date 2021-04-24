
#include "DHT.h"

DHT dhtA0(A0, 11);
DHT dhtA3(A3, 11);

void setMotor8833(int speedpin,int dirpin, int speed)
{
  if (speed == 0)
  {
    digitalWrite(dirpin, LOW);
    analogWrite(speedpin, 0);
  }
  else if (speed > 0)
  {
    digitalWrite(dirpin, LOW);
    analogWrite(speedpin, speed);
  }
  else
  {
    digitalWrite(dirpin, HIGH);
    analogWrite(speedpin, 255 + speed);
  }
}

void setup(){
  Serial.begin(9600);
   dhtA0.begin();
   dhtA3.begin();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
}

void loop(){
  // 使用串口监视器查看温度传感器的温度模拟值
  Serial.println(String("T:") + String(dhtA0.readTemperature()));
  delay(500);
  // 判断温度模拟值是否大于30，如果是，打开风扇；否则，关闭风扇
  if (dhtA3.readTemperature() > 30) {
    setMotor8833(5, 6, 100);

  } else {
    setMotor8833(5, 6, 0);

  }

}
