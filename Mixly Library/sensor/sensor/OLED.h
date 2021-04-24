#ifndef _LED_H__
#define _LED_H__

//导入Arduino核心头文件
#include"Arduino.h"  
#include "font.h"

static int scl = A5;
static int sda = A4;
static int res = 10;

 


#define OLED_SCLK_Clr() digitalWrite(scl,LOW)//SCL
#define OLED_SCLK_Set() digitalWrite(scl,HIGH)

#define OLED_SDIN_Clr() digitalWrite(sda,LOW)//SDA
#define OLED_SDIN_Set() digitalWrite(sda,HIGH)

#define OLED_RST_Clr() digitalWrite(res,LOW)//RES   注：此引脚是为了配合SPI驱动模块改成I2C驱动模块使用的（改装的话必须接），如果买的是I2C模块，请忽略此引脚。
#define OLED_RST_Set() digitalWrite(res,HIGH)


#define OLED_CMD  0  //写命令
#define OLED_DATA 1 //写数据




class OLED
{
    private:
     
    
    
    public:
         
        void OLED_ColorTurn(uint8_t i);
        void OLED_DisplayTurn(uint8_t i);
        void I2C_Start(void);
        void I2C_Stop(void);
        void I2C_WaitAck(void);
        void Send_Byte(uint8_t dat);
        void OLED_WR_Byte(uint8_t dat,uint8_t mode);
        void OLED_Refresh(void);
        void OLED_Clear(void);
        void OLED_DrawPoint(uint8_t x,uint8_t y);
        void OLED_ClearPoint(uint8_t x,uint8_t y);
        void OLED_DrawLine(uint8_t x1,uint8_t y1,uint8_t x2,uint8_t y2);
        void OLED_DrawCircle(uint8_t x,uint8_t y,uint8_t r);
        void OLED_ShowChar(uint8_t x,uint8_t y,const char chr,uint8_t size1);
        void OLED_ShowString(uint8_t x,uint8_t y,const char *chr,uint8_t size1);
        u32 OLED_Pow(uint8_t m,uint8_t n);
        void OLED_ShowNum(uint8_t x,uint8_t y,int num,uint8_t len,uint8_t size1);
        void OLED_ShowChinese(uint8_t x,uint8_t y,const uint8_t num,uint8_t size1);
        void OLED_WR_BP(uint8_t x,uint8_t y);
        void OLED_ShowPicture(uint8_t x0,uint8_t y0,uint8_t x1,uint8_t y1,const uint8_t BMP[]);
        void OLED_Init(void);

};


#endif
