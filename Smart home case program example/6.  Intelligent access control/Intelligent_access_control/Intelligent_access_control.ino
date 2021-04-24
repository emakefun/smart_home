#include "EM_TTP229.h"
EM_TTP229 mTTP229;
int SCLPin = 9, SDOPin = 8;
String Read_Key () {
 String key_name = mTTP229.GetKeyMap();
 char * result = (char *)key_name.c_str();
 return result;
}
#include <Servo.h>

String item;
volatile int number;
String password[]={"0", "0", "0"};

Servo servo_12;

void setup(){
  item = "";
  number = 0;
  mTTP229.initTTP229(SCLPin, SDOPin);
  Serial.begin(9600);
  servo_12.attach(12);
}

void loop(){
  item = Read_Key();
  if (item == "1" && number == 0) {
    Serial.println(item);
    password[(int)(0)] = item;
    number = 1;
    delay(100);

  }
  if (item == "2" && number == 1) {
    Serial.println(item);
    password[(int)(1)] = item;
    number = 2;
    delay(100);

  }
  if (item == "3" && number == 2) {
    Serial.println(item);
    password[(int)(2)] = item;
    number = 3;
    delay(100);

  }
  if (password[(int)(0)] == "1" && (password[(int)(1)] == "2" && password[(int)(2)] == "3")) {
    Serial.println("hello");
    servo_12.write(0);
    delay(2000);
    password[(int)(0)] = "0";
    password[(int)(1)] = "0";
    password[(int)(2)] = "0";
    number = 0;

  } else {
    servo_12.write(90);
    delay(20);

  }

}
