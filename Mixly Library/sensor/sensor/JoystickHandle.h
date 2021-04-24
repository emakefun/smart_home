#ifndef JoystickHandle_H
#define JoystickHandle_H

#include <Arduino.h>
#include <stdint.h>
#include <string.h>
#include <Wire.h>

#define JOYSTICK_I2C_ADDR         0x5A
#define JOYSTICK_BASE_REG         0x10
#define JOYSTICK_LEFT_X_REG       0x10
#define JOYSTICK_LEFT_Y_REG       0x11
#define JOYSTICK_RIGHT_X_REG      0x12
#define JOYSTICK_RIGHT_Y_REG      0x13

#define BUTOON_BASE               0x20

#define BUTOON_LEFT_REG           0x24
#define BUTOON_RIGHT_REG          0x23
#define BUTOON_UP_REG             0x22
#define BUTOON_DOWN_REG           0x21
#define JOYSTICK_BUTTON_REG       0x20

#define	PRESS_DOWN                0
#define	PRESS_UP                  1
#define	PRESS_REPEAT              2
#define	SINGLE_CLICK              3
#define	DOUBLE_CLICK              4  
#define	LONG_PRESS_START          5
#define	LONG_PRESS_HOLD           6
#define	number_of_event           7
#define	NONE_PRESS                8

enum {BUTOON_LEFT = 0, BUTOON_RIGHT, BUTOON_UP, BUTOON_DOWN, JOYSTICK_BUTTON};

class JoystickHandle 
{
  private:
    uint8_t ReadByte(uint8_t reg);
    boolean WireWriteByte(uint8_t val);
    boolean WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len);
    int WireReadDataArray(uint8_t reg, uint8_t *val, unsigned int len);
  public:
    uint8_t Left_x, Left_y;
    uint8_t BOARD_ADDR;
    
    JoystickHandle(void);
    JoystickHandle(uint8_t reg);

    boolean ButtonPressed(uint8_t button);     //will be TRUE if button was JUST pressed
    boolean ButtonReleased(uint8_t button);    //will be TRUE if button was JUST released
    uint8_t AnalogRead_X(void);
    uint8_t AnalogRead_Y(void);
    uint8_t Get_Button_Status(uint8_t button);
    ~JoystickHandle();
};

#endif
