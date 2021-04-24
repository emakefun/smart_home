#include"BS818A.h"

void BS818A::InitBS818A(byte clockPin,byte dataPin) {
  DataPin = dataPin;
  ClockPin = clockPin;
  pinMode(DataPin , OUTPUT);
}
int BS818A::getButtonCode() {
  unsigned int DATA = 0;
  pinMode(ClockPin , OUTPUT);
  digitalWrite(ClockPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(ClockPin, LOW);
  delayMicroseconds(20);
  pinMode(ClockPin , INPUT);
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(DataPin, HIGH);
    delayMicroseconds(4);
    digitalWrite(DataPin, LOW);
    delayMicroseconds(4);
    DATA |= digitalRead(ClockPin) << i;
  }
  delay(6);
  return DATA & 0xFFFF;
}
boolean BS818A::PressBsButton(unsigned int button) {
  BsKey = getButtonCode();
  if (BsKey != BS_Released) {
    if ((BsKey & button) == button)
      return 1;
    else
      return 0;
  }
  else
    return 0;
}
