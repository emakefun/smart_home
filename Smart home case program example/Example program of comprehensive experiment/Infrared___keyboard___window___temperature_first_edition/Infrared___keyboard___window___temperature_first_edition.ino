#include "IR_remote.h"
#include "keymap.h"
IRremote ir(9);

#include "EM_TTP229.h"
EM_TTP229 mTTP229;
int SCLPin = 8, SDOPin = A1;
String Read_Key () {
 String key_name = mTTP229.GetKeyMap();
 char * result = (char *)key_name.c_str();
 return result;
}
#include <Servo.h>
#include <Wire.h>
#include "TM1650.h"
#include "DHT.h"

String item;
volatile int num;
volatile int i;
String password[]={"0", "0", "0"};

Servo servo_2;
Servo servo_3;
TM1650 tm_4display;
volatile int light;
DHT dhtA2(A2, 11);

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

void yaokong() {
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_3) {
    servo_2.write(0);
    delay(500);

  }
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_4) {
    servo_2.write(90);
    delay(500);

  }
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_5) {
    servo_3.write(90);
    delay(500);

  }
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_6) {
    servo_3.write(0);
    delay(500);

  }
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_7) {
    setMotor8833(5, 6, 100);

  }
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_8) {
    setMotor8833(5, 6, 0);

  }
}

void mimakaimen() {
  item = Read_Key();
  if (item == "1" && num == 0) {
    Serial.println(item);
    password[(int)(0)] = item;
    num = 1;
    delay(100);

  }
  if (item == "2" && num == 1) {
    Serial.println(item);
    password[(int)(1)] = item;
    num = 2;
    delay(100);

  }
  if (item == "3" && num == 2) {
    Serial.println(item);
    password[(int)(2)] = item;
    num = 3;
    delay(100);

  }
  if (password[(int)(0)] == "1" && (password[(int)(1)] == "2" && password[(int)(2)] == "3")) {
    Serial.println("hello");
    servo_2.write(0);
    delay(500);
    delay(2000);
    password[(int)(0)] = "0";
    password[(int)(1)] = "0";
    password[(int)(2)] = "0";
    num = 0;

  } else {
    servo_2.write(90);
    delay(500);

  }
}

void wengan() {
  tm_4display.clear();
  light = analogRead(A3);
  tm_4display.displayString(light);
  if (digitalRead(7) == 0) {
    servo_3.write(90);
    delay(500);

  } else {
    if (light > 200) {
      servo_3.write(0);
      delay(500);

    } else {
      servo_3.write(90);
      delay(500);

    }

  }
  if (dhtA2.readTemperature() > 30) {
    setMotor8833(5, 6, 100);

  } else {
    setMotor8833(5, 6, 0);

  }
}

void setup(){
  item = "";
  num = 0;
  i = 1;
  ir.begin();

  mTTP229.initTTP229(SCLPin, SDOPin);
  Serial.begin(9600);
  servo_2.attach(2);
  servo_3.attach(3);
  Wire.begin();
  tm_4display.init();
  servo_2.write(90);
  delay(500);
  servo_3.write(0);
  delay(500);
  tm_4display.clear();
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  light = 0;
  pinMode(7, INPUT);
   dhtA2.begin();
}

void loop(){
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_1) {
    i = 1;
    tm_4display.displayString(i);

  }
  if (ir.getIrKey(ir.getCode(),2) == EM_IR_KEYCODE_2) {
    i = 0;

  }
  if (i == 0) {
    mimakaimen();
    wengan();

  } else {
    yaokong();

  }

}
