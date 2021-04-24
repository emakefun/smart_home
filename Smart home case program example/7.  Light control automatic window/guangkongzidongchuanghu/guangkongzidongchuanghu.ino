
#include <Wire.h>
#include "TM1650.h"
#include <Servo.h>

TM1650 tm_4display;
volatile int _light;
Servo servo_13;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  tm_4display.init();
  _light = 0;
  tm_4display.clear();
  servo_13.attach(13);
}

void loop(){
  // 将连接在A2接口的光敏传感器的模拟值赋给light变量
  _light = analogRead(A2);
  tm_4display.displayString(_light);
  Serial.println(_light);
  delay(500);
  // 判断光线模拟值是否大于100，如果是，则打开窗户；否则，关闭窗户
  if (_light > 100) {
    servo_13.write(0);
    delay(5000);

  } else {
    servo_13.write(90);
    delay(20);

  }

}
