/*!
 * @file EM_JQ8400.cpp
 * @brief color sensor
 * @n Header file for EMakefun's MP3 Module
 *
 * @copyright  [EM](http://www.emakefun.com), 2019
 * @copyright GNU Lesser General Public License
 *
 * @author [carl](carl@emakefun.com,ken@emakefun.com)
 * @version  V1.0
 * @date  2019-07-12
 */
/**************************************************************************/
#include "EM_JQ8400.h"

EM_JQ8400::EM_JQ8400(uint8_t IO_busycheck, uint8_t busychecken)
{
  JQ8400 = new SoftwareSerial(IO_busycheck, busychecken);
  JQ8400->begin(9600);
}

/************************************************************************
  功能描述：起始码-指令类型-数据长度-校验和
  入口参数：   MODE：模式
  返 回 值： none
  其他说明： 不带数据的指令播放函数.无数数据传入
**************************************************************************/
void EM_JQ8400::Command(UartCommand Command)
{
  u8 Buffer[4] = {0xaa};

  Buffer[1] = Command;                           //指令类型
  Buffer[2] = 0x00;                              //数据长度
  Buffer[3] = Buffer[0] + Buffer[1] + Buffer[2]; //校验和

  if (IO_BUSYCHECKEN)
  {
    delay(10);
    while (digitalRead(IO_BUSYCHECK) == HIGH)
      ; //忙检测
  }
  JQ8400->write(Buffer, 4);
}

/************************************************************************
  功能描述：起始码-指令类型-数据长度-数据-校验和
  入口参数：   *DAT：字符串指针,Len字符串长度
  返 回 值： none
  其他说明：
**************************************************************************/
void EM_JQ8400::Command_Data(UartCommandData Command, uint8_t DATA)
{
  uint8_t Buffer[6] = {0xaa};
  uint8_t DataLen = 0;                                                                                                                                           //数据长度
  Buffer[1] = Command;                                                                                                                                           //指令类型
  if ((Command != AppointTrack) && (Command != SetCycleCount) && (Command != SelectTrackNoPlay) && (Command != AppointTimeBack) && (Command != AppointTimeFast)) //只含一个数据指令
  {
    Buffer[2] = 1;                                             //数据长度
    Buffer[3] = DATA;                                          //数据
    Buffer[4] = Buffer[0] + Buffer[1] + Buffer[2] + Buffer[3]; //校验和
    DataLen = 5;
  }
  else //含两个数据指令
  {
    Buffer[2] = 2;          //数据长度
    Buffer[3] = DATA / 256; //数据
    Buffer[4] = DATA % 256; //数据
    Buffer[5] = Buffer[0] + Buffer[1] + Buffer[2] + Buffer[3] + Buffer[4];
    DataLen = 6;
  }

  if (IO_BUSYCHECKEN)
  {
    delay(10);
    while (digitalRead(IO_BUSYCHECK) == HIGH)
      ; //忙检测
  }
  JQ8400->write(Buffer, DataLen);
}

/************************************************************************
  功能描述：播放根目录指定文件名的音频文件
  入口参数：JQ8400_Symbol:系统盘符，*DATA:需要播放的文件名
  返 回 值： none
  其他说明：播放FLASH根目录下文件名为00001.mp3的音频，JQ_8x00_AppointPlay(JQ8400_FLASH,"00001");
**************************************************************************/
void EM_JQ8400::AppointPlay(JQ8400_Symbol MODE, char *DATA)
{
  u8 Buffer[30] = {0xaa, 0x08};
  u8 i, j;
  Buffer[2] = 1 + strlen(DATA) + 5; //长度
  Buffer[3] = MODE;                 //盘符
  Buffer[4] = '/';                  //路径
  i = 5;
  while (*DATA)
  {
    Buffer[i++] = *DATA;
    DATA++;
  }
  Buffer[i++] = '*';
  Buffer[i++] = '?';
  Buffer[i++] = '?';
  Buffer[i++] = '?';
  for (j = 0; j < i; j++)
  {
    Buffer[i] = Buffer[i] + Buffer[j]; //计算校验合
  }
  i++;

  if (IO_BUSYCHECKEN)
  {
    delay(10);
    while (digitalRead(IO_BUSYCHECK) == HIGH)
      ; //忙检测
  }

  JQ8400->write(Buffer, i);
}

/************************************************************************
  功能描述：组合播报函数
  入口参数：   *DAT：字符串指针,Len字符串长度
  返 回 值： none
  其他说明： 将需要播报的文件名放入数组中作为形参即可,例：组合播放01,02文件，则DATA内容为{1,2}，MakeUpPlay（DATA，2）
**************************************************************************/
void EM_JQ8400::MakeUpPlay(unsigned char *DATA, unsigned char Len)
{
  unsigned char CRC_data = 0, i = 3;
  unsigned char Buffer[30] = {0xaa, 0x1b};

  Buffer[2] = Len * 2; //计算长度
  CRC_data = CRC_data + 0xaa + 0x1b + Buffer[2];
  while (Len--)
  {
    Buffer[i] = *DATA / 10 + 0x30; //取出十位
    CRC_data = CRC_data + Buffer[i];
    i++;
    Buffer[i] = *DATA % 10 + 0x30; //取出个位
    CRC_data = CRC_data + Buffer[i];
    i++;
    DATA++;
  }
  Buffer[i] = CRC_data;
  i++;
  if (IO_BUSYCHECKEN)
  {
    delay(10);
    while (digitalRead(IO_BUSYCHECK) == HIGH)
      ; //忙检测
  }

  JQ8400->write(Buffer, i);
}
