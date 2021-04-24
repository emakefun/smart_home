
#include <Wire.h>
#include "TM1650.h"
#include <Servo.h>

TM1650 tm_4display;
volatile int _light;
volatile int yudi;
volatile int item;
Servo servo_13;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  tm_4display.init();
  _light = 0;
  yudi = 0;
  item = 0;
  tm_4display.clear();
  servo_13.attach(13);
}

void loop(){
  // 将连接在A2接口的光敏传感器的模拟值赋给light变量
  _light = analogRead(A2);
  // 将连接在A1接口的雨滴传感器的返回值赋予yudi变量
  yudi = analogRead(A1);
  tm_4display.displayString(_light);
  Serial.print(String(" light:") + String(_light));
  Serial.print(",");
  Serial.println(String("yudi:") + String(yudi));
  delay(500);
  // 判断光线模拟值是否大于100，如果是打开窗户；否则，关闭窗户
  if (_light > 100) {
    // 雨滴传感器感应都雨水时，数值会变小，否则数值变大。此处判断雨滴模拟返回值是否小于200，如果是，则关闭窗户；否则打开窗户
    if (yudi < 200) {
      servo_13.write(90);
      delay(300);

    } else {
      servo_13.write(0);
      delay(3000);

    }

  } else {
    servo_13.write(90);
    delay(20);

  }

}
