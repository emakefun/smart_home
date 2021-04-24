
#include <Servo.h>

Servo servo_11;

void setup(){
  pinMode(7, INPUT);
  servo_11.attach(11);
}

void loop(){
  // 判断连接在D7号管脚的红外避障传感器是否感应到车，“0”表示感应到，“1”表示没感应到
  if (digitalRead(7) == 0) {
    servo_11.write(90);
    delay(5000);

  } else {
    servo_11.write(0);
    delay(1000);

  }

}
