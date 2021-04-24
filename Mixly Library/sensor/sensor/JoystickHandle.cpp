#include "JoystickHandle.h"


JoystickHandle::JoystickHandle()
{
    Wire.begin();
    BOARD_ADDR = 0x5a;
}

JoystickHandle::JoystickHandle(uint8_t reg)
{
    Wire.begin();
    BOARD_ADDR = reg;
}

boolean JoystickHandle::WireWriteByte(uint8_t val)
{
    Wire.beginTransmission(BOARD_ADDR);
    Wire.write(val);
    if( Wire.endTransmission() != 0 ) {
        return false;
    }
    return true;
}

boolean JoystickHandle::WireWriteDataArray(uint8_t reg, uint8_t *val, unsigned int len)
{
    unsigned int i;
    Wire.beginTransmission(BOARD_ADDR);
    Wire.write(reg);
    for(i = 0; i < len; i++) {
        Wire.write(val[i]);
    }
    if( Wire.endTransmission() != 0 ) {
        return false;
    }
    return true;
}

int JoystickHandle::WireReadDataArray(uint8_t reg, uint8_t *val, unsigned int len)
{
    unsigned char i = 0;  
    /* Indicate which register we want to read from */
    if (!WireWriteByte(reg)) {
        return -1;
    }
    Wire.requestFrom(BOARD_ADDR, len);
    while (Wire.available()) {
        if (i >= len) {
            return -1;
        }
        val[i] = Wire.read();
        i++;
    }
    /* Read block data */    
    return i;
}

uint8_t JoystickHandle::ReadByte(uint8_t reg)
{
    byte d[1];
    WireReadDataArray(reg, d, 1);
    return d[0];
}

uint8_t JoystickHandle::AnalogRead_X(void)
{
    Left_x = ReadByte(JOYSTICK_LEFT_X_REG);
    return Left_x;
}

uint8_t JoystickHandle::AnalogRead_Y(void)
{
    Left_y = ReadByte(JOYSTICK_LEFT_Y_REG);
    return Left_y;
}

uint8_t JoystickHandle::Get_Button_Status(uint8_t button)
{
    switch(button) {
        case 0: 
            return ReadByte(BUTOON_LEFT_REG);
        case 1: 
            return ReadByte(BUTOON_RIGHT_REG);
        case 2: 
            return ReadByte(BUTOON_UP_REG);
        case 3: 
            return ReadByte(BUTOON_DOWN_REG);
        case 4: 
            return ReadByte(JOYSTICK_BUTTON_REG);
        default:
            return 0xff;
    }
    
}

boolean JoystickHandle::ButtonPressed(uint8_t button)
{
    if(Get_Button_Status(button) != NONE_PRESS && Get_Button_Status(button) != 0xff)
    {
        return true;
    }
    return false;    
}

boolean JoystickHandle::ButtonReleased(uint8_t button)   
{
        if(Get_Button_Status(button) == NONE_PRESS)
    {
        return true;
    }
    return false;   
}

JoystickHandle::~JoystickHandle()
{

}
