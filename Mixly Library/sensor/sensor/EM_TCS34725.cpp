
#ifdef __AVR
  #include <avr/pgmspace.h>
#elif defined(ESP8266)
  #include <pgmspace.h>
#endif
#include <stdlib.h>
#include <math.h>

#include "EM_TCS34725.h"

//long unsigned int time = 0;


byte *gammatable;

float EM_TCS34725::_powf(const float x, const float y) {
  return (float)(pow((double)x, (double)y));
}


void EM_TCS34725::writeReg (uint8_t reg, uint32_t value) {

    Wire.beginTransmission(TCS34725_ADDRESS);
#if ARDUINO >= 100
    Wire.write(TCS34725_COMMAND_BIT | reg);
    Wire.write(value & 0xFF);
#else
    Wire.send(TCS34725_COMMAND_BIT | reg);
    Wire.send(value & 0xFF);
#endif
    Wire.endTransmission();

}


uint8_t EM_TCS34725::readReg(uint8_t reg) {

    Wire.beginTransmission(TCS34725_ADDRESS);
#if ARDUINO >= 100
    Wire.write(TCS34725_COMMAND_BIT | reg);
#else
    Wire.send(TCS34725_COMMAND_BIT | reg);
#endif
    Wire.endTransmission();

    Wire.requestFrom(TCS34725_ADDRESS, 1);
#if ARDUINO >= 100
    return Wire.read();
#else
    return Wire.receive();
#endif
}


uint16_t EM_TCS34725::readRegWord(uint8_t reg) {

    uint16_t x; uint16_t t;

    Wire.beginTransmission(TCS34725_ADDRESS);

#if ARDUINO >= 100
    Wire.write(TCS34725_COMMAND_BIT | reg);
#else
    Wire.send(TCS34725_COMMAND_BIT | reg);
#endif
    Wire.endTransmission();

    Wire.requestFrom(TCS34725_ADDRESS, 2);
#if ARDUINO >= 100
    t = Wire.read();
    x = Wire.read();
#else
    t = Wire.receive();
    x = Wire.receive();
#endif
    x <<= 8;
    x |= t;
    return x;

}


void EM_TCS34725::enable(void) {

    writeReg(TCS34725_ENABLE, TCS34725_ENABLE_PON);

    delay(3);

    writeReg(TCS34725_ENABLE, TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN);

}


void EM_TCS34725::disable(void) {

    /* Turn the device off to save power */
    uint8_t reg = 0;

    reg = readReg(TCS34725_ENABLE);
    writeReg(TCS34725_ENABLE, reg & ~(TCS34725_ENABLE_PON | TCS34725_ENABLE_AEN));

}



EM_TCS34725::EM_TCS34725() {
    _tcs34725Initialised = false;
}


boolean EM_TCS34725::begin(tcs34725IntegrationTime_t it, tcs34725Gain_t gain) {

    _tcs34725IntegrationTime = it;
    _tcs34725Gain = gain;

    Wire.begin();
    /* Make sure we're actually connected */
    uint8_t x = readReg(TCS34725_ID);
    if ((x != 0x44) && (x != 0x10))
    {
        return false;
    }
    _tcs34725Initialised = true;

    /* Set default integration time and gain */
    setIntegrationTime(_tcs34725IntegrationTime);
    setGain(_tcs34725Gain);

    /* Note: by default, the device is in power down mode on bootup */
    enable();

    gammatable = (byte*)malloc(256*sizeof(byte));
    for(int i=0; i<256; i++){
        float x = i;
        x /= 255;
        x = pow(x, 2.5);
        x *= 255;Serial.println(i);
        gammatable[i] = x;
    }

    return true;

}
  

void EM_TCS34725::setIntegrationTime(tcs34725IntegrationTime_t it) {

    if (!_tcs34725Initialised) begin();

    /* Update the timing register */
    writeReg(TCS34725_ATIME, it);

    /* Update value placeholders */
    _tcs34725IntegrationTime = it;

}


void EM_TCS34725::setGain(tcs34725Gain_t gain) {

    if (!_tcs34725Initialised) begin();

    /* Update the timing register */
    writeReg(TCS34725_CONTROL, gain);

    /* Update value placeholders */
    _tcs34725Gain = gain;

}


uint16_t EM_TCS34725::getRed() {

    uint16_t r;

    this->getRGBC(&r, NULL, NULL, NULL, false);

    return r;

}

uint16_t EM_TCS34725::getGreen() {

    uint16_t g;

    this->getRGBC(NULL, &g, NULL, NULL, false);

    return g;

}

uint16_t EM_TCS34725::getBlue() {

    uint16_t b;

    this->getRGBC(NULL, NULL, &b, NULL, false);

    return b;

}

uint16_t EM_TCS34725::getRedToGamma() {

    uint16_t r, c;

    float fr,fc;

    this->getRGBC(&r, NULL, NULL, &c, false);
    fr = r;
    fc = c;

    return (uint16_t)gammatable[(int)(((fr/fc)*256))];

}

uint16_t EM_TCS34725::getGreenToGamma() {

    uint16_t g, c;

    float fg,fc;

    this->getRGBC(NULL, &g, NULL, &c, false);
    fg = g;
    fc = c;

    return (uint16_t)gammatable[(int)(((fg/fc)*256))];

}

uint16_t EM_TCS34725::getBlueToGamma() {

    uint16_t b, c;

    float fb,fc;

    this->getRGBC(NULL, NULL, &b, &c, false);
    fb = b;
    fc = c;

    return (uint16_t)gammatable[(int)(((fb/fc)*256))];

}

void EM_TCS34725::getRGBC (uint16_t *r, uint16_t *g, uint16_t *b, uint16_t *c, bool wait) {

    if (!_tcs34725Initialised) begin();

    if(c) *c = readRegWord(TCS34725_CDATAL);
    else readRegWord(TCS34725_CDATAL);

    if(r) *r = readRegWord(TCS34725_RDATAL);
    else readRegWord(TCS34725_RDATAL);

    if(g) *g = readRegWord(TCS34725_GDATAL);
    else readRegWord(TCS34725_GDATAL);

    if(b) *b = readRegWord(TCS34725_BDATAL);
    else readRegWord(TCS34725_BDATAL);

    if(wait) {
        /*Set a delay for the integration time */
        switch (_tcs34725IntegrationTime)
        {
            case TCS34725_INTEGRATIONTIME_2_4MS:
                delay(3);
            break;
            case TCS34725_INTEGRATIONTIME_24MS:
                delay(24);
            break;
            case TCS34725_INTEGRATIONTIME_50MS:
                delay(50);
            break;
            case TCS34725_INTEGRATIONTIME_101MS:
                delay(101);
            break;
            case TCS34725_INTEGRATIONTIME_154MS:
                delay(154);
            break;
            case TCS34725_INTEGRATIONTIME_700MS:
                delay(700);
            break;
        }
    }

    //time = millis();
    this->lock();

}


uint16_t EM_TCS34725::calculateColorTemperature(uint16_t r, uint16_t g, uint16_t b) {

    float X, Y, Z;      /* RGB to XYZ correlation      */
    float xc, yc;       /* Chromaticity co-ordinates   */
    float n;            /* McCamy's formula            */
    float cct;

    /* 1. Map RGB values to their XYZ counterparts.    */
    /* Based on 6500K fluorescent, 3000K fluorescent   */
    /* and 60W incandescent values for a wide range.   */
    /* Note: Y = Illuminance or lux                    */
    X = (-0.14282F * r) + (1.54924F * g) + (-0.95641F * b);
    Y = (-0.32466F * r) + (1.57837F * g) + (-0.73191F * b);
    Z = (-0.68202F * r) + (0.77073F * g) + ( 0.56332F * b);

    /* 2. Calculate the chromaticity co-ordinates      */
    xc = (X) / (X + Y + Z);
    yc = (Y) / (X + Y + Z);

    /* 3. Use McCamy's formula to determine the CCT    */
    n = (xc - 0.3320F) / (0.1858F - yc);

    /* Calculate the final CCT */
    cct = (449.0F * _powf(n, 3)) + (3525.0F * _powf(n, 2)) + (6823.3F * n) + 5520.33F;

    /* Return the results in degrees Kelvin */
    return (uint16_t)cct;

}


uint16_t EM_TCS34725::calculateLux(uint16_t r, uint16_t g, uint16_t b) {

    float illuminance;

    /* This only uses RGB ... how can we integrate clear or calculate lux */
    /* based exclusively on clear since this might be more reliable?      */
    illuminance = (-0.32466F * r) + (1.57837F * g) + (-0.73191F * b);

    return (uint16_t)illuminance;

}

void EM_TCS34725::lock() {

    uint8_t r = readReg(TCS34725_ENABLE);

    r |= TCS34725_ENABLE_AIEN;

    writeReg(TCS34725_ENABLE, r);

}

void EM_TCS34725::unlock() {

    uint8_t r = readReg(TCS34725_ENABLE);

    r &= ~TCS34725_ENABLE_AIEN;

    writeReg(TCS34725_ENABLE, r);

}


void EM_TCS34725::clear(void) {

    Wire.beginTransmission(TCS34725_ADDRESS);
#if ARDUINO >= 100
    Wire.write(TCS34725_COMMAND_BIT | 0x66);
#else
    Wire.send(TCS34725_COMMAND_BIT | 0x66);
#endif
    Wire.endTransmission();

}


void EM_TCS34725::setIntLimits(uint16_t low, uint16_t high) {

    writeReg(0x04, low & 0xFF);
    writeReg(0x05, low >> 8);
    writeReg(0x06, high & 0xFF);
    writeReg(0x07, high >> 8);

}
