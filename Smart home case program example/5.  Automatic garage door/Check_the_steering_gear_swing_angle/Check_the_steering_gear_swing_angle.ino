
#include <Servo.h>

Servo servo_11;

void setup(){
  servo_11.attach(11);
}

void loop(){
  servo_11.write(0);
  delay(1000);
  servo_11.write(90);
  delay(1000);
  servo_11.write(180);
  delay(1000);

}
