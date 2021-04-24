#ifndef _TTP229_H_
#define _TTP229_H_
#include <Arduino.h>
#define KEY_MAX 16
typedef struct
{
  String keyname;
  uint16_t keycode;
} TTP_ST_KEY_MAP;

typedef enum {
  EM_KEYCODE_1 = 0,
  EM_KEYCODE_2,
  EM_KEYCODE_3,
  EM_KEYCODE_4,
  EM_KEYCODE_5,
  EM_KEYCODE_6,
  EM_KEYCODE_7,
  EM_KEYCODE_8,
  EM_KEYCODE_9,
  EM_KEYCODE_0,
  EM_KEYCODE_A,
  EM_KEYCODE_B,
  EM_KEYCODE_C,
  EM_KEYCODE_D,
  EM_IR_KEYCODE_STAR,
  EM_IR_KEYCODE_POUND,
} E_EM_KEYCODE;
extern TTP_ST_KEY_MAP em_ttp_keymap[];

class EM_TTP229 {
  private:
    uint8_t SCLPin, SDOPin;
  public:
    void initTTP229(uint8_t SclPin, uint8_t SdoPin);
    uint16_t GetKeyCode(void);
    String GetKeyMap(void);
    uint16_t GetKey(void);
};
#endif  /* _KEYMAY_H_ */
