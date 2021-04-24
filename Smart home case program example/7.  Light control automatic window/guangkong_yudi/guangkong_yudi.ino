
#include <Wire.h>
#include "TM1650.h"
#include <Servo.h>

TM1650 tm_4display;
volatile int _light;
volatile int yudi;
volatile int item;
Servo servo_3;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  tm_4display.init();
  _light = 0;
  yudi = 0;
  item = 0;
  servo_3.attach(3);
}

void loop(){
  tm_4display.clear();

  _light = analogRead(A0);
  yudi = analogRead(A1);
  tm_4display.displayString(_light);
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.println(analogRead(A1));
  delay(500);
  if (_light > 200) {
    item = 1;
    if (analogRead(A1) < 1000 && item == 1) {
      Serial.println(analogRead(A1));
      item = 0;
      servo_3.write(90);
      delay(20);
      delay(5000);

    } else {
      servo_3.write(0);
      delay(20);

    }

  } else {
    servo_3.write(90);
    delay(20);

  }

}
