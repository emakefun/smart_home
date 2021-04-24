
#include "Buzzer.h"
#include "Sounds.h"
#include "PH20Port.h"

PH20Port buzzerplay(P9);

#include "Buzzer.h"

int touch_PIN2  = 2;
Buzzer mBuzzer = Buzzer(buzzerplay.pin1());
Buzzer buzzer(buzzerplay.pin1());

void setup() {

pinMode(touch_PIN2,INPUT);
}

void loop()  {

   if (digitalRead(touch_PIN2)==HIGH) {
    mBuzzer.bendTones(1500, 2500, 1.05, 20, 8);
    mBuzzer.bendTones(2499, 1500, 1.05, 25, 8);
  } else {
    buzzer.noTone();
  }

}
