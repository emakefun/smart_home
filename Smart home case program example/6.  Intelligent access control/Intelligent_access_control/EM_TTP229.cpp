#include "EM_TTP229.h"

ST_KEY_MAP em_ttp_keymap[16] = {
  {"1", 0xFFFE},
  {"2", 0xFFFD},
  {"3", 0xFFFB},
  {"4", 0xFFEF},
  {"5", 0xFFDF},
  {"6", 0xFFBF},
  {"7", 0xFEFF},
  {"8", 0xFDFF},
  {"9", 0xFBFF},
  {"*", 0xEFFF},
  {"0", 0xDFFF},
  {"#", 0xBFFF},
  {"D", 0x7FFF},
  {"C", 0xF7FF},
  {"B", 0xFF7F},
  {"A", 0xFFF7},
};

void EM_TTP229::initTTP229(uint8_t SclPin, uint8_t SdoPin) {
  SCLPin = SclPin;
  SDOPin = SdoPin;
  pinMode(SCLPin , OUTPUT);
  pinMode(SDOPin , INPUT);
}

uint16_t EM_TTP229::GetKeyCode(void) {
  unsigned int DATA = 0;
  pinMode(SDOPin , OUTPUT);
  digitalWrite(SDOPin, HIGH);
  delayMicroseconds(93);
  digitalWrite(SDOPin, LOW);
  delayMicroseconds(10);
  pinMode(SDOPin , INPUT);
  for (int i = 0; i < 16; i++)
  {
    digitalWrite(SCLPin, HIGH);
    digitalWrite(SCLPin, LOW);
    DATA |= digitalRead(SDOPin) << i;
  }
  delay(4);
  return DATA & 0xFFFF;
}
String EM_TTP229::GetKeyMap(void) {
  byte i;
  uint16_t keycode = GetKeyCode();
  ST_KEY_MAP *irkeymap = em_ttp_keymap;
  for (i = 0; i < KEY_MAX; i++) {
    //    Serial.println(irkeymap[i].keycode);
    if (irkeymap[i].keycode == keycode)
      return irkeymap[i].keyname;
  }
  return "";
}

uint16_t EM_TTP229::GetKey(void) {
  byte i;
  uint16_t keycode = GetKeyCode();
  ST_KEY_MAP *irkeymap = em_ttp_keymap;
  for (i = 0; i < KEY_MAX; i++) {
    //    Serial.println(irkeymap[i].keycode);
    if (irkeymap[i].keycode == keycode)
      return i;
  }
  return 0xff;
}
