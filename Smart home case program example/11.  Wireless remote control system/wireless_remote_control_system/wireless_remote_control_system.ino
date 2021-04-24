#include "IR_remote.h"
#include "keymap.h"
IRremote ir(4);

#include <Servo.h>

Servo servo_12;
Servo servo_13;

void setup(){
  ir.begin();

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  servo_12.attach(12);
  servo_13.attach(13);
}

void loop(){
  // 按下1键，同时打开风扇和黄灯
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_1) {
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);

  }
  // 按下2键，同时关闭风扇和黄灯
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_2) {
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);

  }
  // 按下3键，打开门
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_3) {
    servo_12.write(90);
    delay(20);

  }
  // 按下4键，关闭门
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_4) {
    servo_12.write(0);
    delay(20);

  }
  // 按下5键，打开窗
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_5) {
    servo_13.write(90);
    delay(20);

  }
  // 按下4键，关闭窗
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_6) {
    servo_13.write(0);
    delay(20);

  }

}
