
#include <Servo.h>

String item;
volatile long time;
Servo servo_12;
Servo servo_13;

void setup(){
  Serial.begin(9600);
  item = "";
  time = 0;
  servo_12.attach(12);
  servo_13.attach(13);
}

void loop(){
  if (Serial.available() > 0) {
    item = Serial.readStringUntil('.');
    if (String(item).equals(String("OPEN DOOR"))) {
      Serial.println("OPEN DOOR");
      servo_12.write(90);
      delay(20);

    } else if (String(item).equals(String("CLOSE DOOR"))) {
      Serial.println("CLOSE DOOR");
      servo_12.write(0);
      delay(20);
    }
    if (String(item).equals(String("OPEN Window"))) {
      Serial.println("OPEN Window");
      servo_13.write(90);
      delay(20);

    } else if (String(item).equals(String("CLOSE Window"))) {
      Serial.println("CLOSE Window");
      servo_13.write(0);
      delay(20);
    }

  }

}
