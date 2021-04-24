#ifndef _RGBULTRASONIC_H_
#define _RGBULTRASONIC_H_

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include "RGBLed.h"

#define UL_LIMIT_MIN 5
#define UL_LIMIT_MID 10
#define UL_LIMIT_MAX 400

#define RGB_RED     0x00FF00
#define RGB_GREEN   0xFF0000
#define RGB_BLUE    0x0000FF
#define RGB_YELLOW  0xFFFF00
#define RGB_PURPLE  0x00FFFF
#define RGB_ORANGE  0xA5FF00
#define RGB_INDIGO  0x004b82
#define RGB_VIOLET  0x2b8ae2
#define RGB_WHITE   0xFFFFFF
#define RGB_BLACK   0

typedef enum
{
    E_RGB_ALL = 0,
    E_RGB_RIGHT = 1,
    E_RGB_LEFT = 2
} E_RGB_INDEX;

typedef enum
{
	  E_EFFECT_NONE = 0,
    E_EFFECT_BREATHING = 1,
    E_EFFECT_ROTATE = 2,
    E_EFFECT_FLASH = 3
} E_RGB_EFFECT;

class RgbUltrasonic
{
  private:
    byte SignalPin, RgbPin;
  public:
    RGBLed *mRgb;
    uint16_t FrontDistance;
    RgbUltrasonic(byte signal_pin, byte rgb_pin);
    uint16_t GetUltrasonicDistance(void);
    void SetRgbIndexColor(int start_index, int end_index, long Color);
    void SetRgbEffect(E_RGB_INDEX index, long Color, uint8_t effect = E_EFFECT_NONE);
};
#endif
