#ifndef BS818A_h
#define BS818A_h

#include <Arduino.h>

#define BS_KEYCODE_1 0x43FD
#define BS_KEYCODE_2 0x43FB
#define BS_KEYCODE_3 0x43F7
#define BS_KEYCODE_4 0x43EF 
#define BS_KEYCODE_5 0x43DF
#define BS_KEYCODE_6 0x43BF
#define BS_KEYCODE_7 0x437F
#define BS_KEYCODE_8 0x42FF
#define BS_Released  0x41FF
class BS818A {
  private:
    uint8_t DataPin, ClockPin;
    unsigned int BsKey;
  public:
    void InitBS818A(byte clockPin,byte dataPin);
    int getButtonCode(void);
    boolean PressBsButton(unsigned int button);
};
#endif
