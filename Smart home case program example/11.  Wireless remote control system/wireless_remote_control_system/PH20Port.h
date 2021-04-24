
#ifndef _PH20Port_H_
#define _PH20Port_H_

#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>

#define RJ25_MAX 16

#define P1 1
#define P2 2
#define P3 3
#define P4 4

#define P5 5
#define P6 6
#define P7 7
#define P8 8

#define P9  9 
#define P10 10
#define P11 11
#define P12 12
            
#define P13 13
#define P14 14
#define P15 15
#define P16 16

/**
 * A structure to represent PH20Port Signal.
 */
typedef struct
{
  uint8_t s1;
  uint8_t s2;
  uint8_t s3;
  uint8_t s4;
  uint8_t s5;
  uint8_t s6;
} PH20Port_Sig;

extern PH20Port_Sig PH20_Port[RJ25_MAX];  // PH20Port[0] is nonsense

#define NC (0)  //use UART RX for NULL port

#define SLOT1       (1)
#define SLOT2       (2)
#define SLOT3       (3)
#define SLOT4       (4)
#define SLOT5       (5)
#define SLOT6       (6)

#define SLOT_1  SLOT1
#define SLOT_2  SLOT2
#define SLOT_3  SLOT3
#define SLOT_4  SLOT4
#define SLOT_5  SLOT3
#define SLOT_6  SLOT4

#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef TRUE
#define TRUE    (1)
#endif

/**
 * Class: PH20Port
 *
 * \par Description
 * Declaration of Class PH20Port
 */
class PH20Port
{
public:

/**
 * Alternate Constructor which can call your own function to map the PH20Port to arduino port,
 * no pins are used or initialized here
 */
  PH20Port(void);

/**
 * Alternate Constructor which can call your own function to map the PH20Port to arduino port,
 * no pins are used or initialized here, but PWM frequency set to 976 Hz
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
  PH20Port(uint8_t port);

/**
 * Alternate Constructor which can call your own function to map the PH20Port to arduino port,
 * no pins are used or initialized here, but PWM frequency set to 976 Hz
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 */
  PH20Port(uint8_t port, uint8_t slot);

/**
 * \par Function
 *   getPort
 * \par Description
 *   Get current valid port of current RJ25 object
 * \par Output
 *   None
 * \return
 *   Port bumber from PORT_1 to M2
 * \par Others
 *   None
 */
  uint8_t getPort(void);

/**
 * \par Function
 *   getSlot
 * \par Description
 *   Get current valid slot of current RJ25 object's port
 * \par Output
 *   None
 * \return
 *   Slot bumber SLOT1 or SLOT2
 * \par Others
 *   None
 */
  uint8_t getSlot(void);

/**
 * \par Function
 *   dRead1
 * \par Description
 *   Read the digital input value on slot1 of current RJ25 object's port
 * \param[in]
 *   mode - digital input mode INPUT or INPUT_PULLUP
 * \par Output
 *   None
 * \return
 *   Digital input value
 * \par Others
 *   None
 */
  bool dRead1(uint8_t mode = INPUT);

/**
 * \par Function
 *   dRead2
 * \par Description
 *   Read the digital input value on slot2 of current RJ25 object's port
 * \param[in]
 *   mode - digital input mode INPUT or INPUT_PULLUP
 * \par Output
 *   None
 * \return
 *   Digital input value
 * \par Others
 *   None
 */
  bool dRead2(uint8_t mode = INPUT);
  bool dRead3(uint8_t mode = INPUT);
  bool dRead4(uint8_t mode = INPUT);
  bool dRead5(uint8_t mode = INPUT);
  
/**
 * \par Function
 *   dpRead1
 * \par Description
 *   Read the digital input value on slot1 of current RJ25 object's port, the input
 *   mode set as INPUT_PULLUP.
 * \par Output
 *   None
 * \return
 *   Digital input value
 * \par Others
 *   None
 */
  bool dpRead1(void);

/**
 * \par Function
 *   dpRead2
 * \par Description
 *   Read the digital input value on slot2 of current RJ25 object's port, the input
 *   mode set as INPUT_PULLUP.
 * \par Output
 *   None
 * \return
 *   Digital input value
 * \par Others
 *   None
 */
  bool dpRead2(void);

/**
 * \par Function
 *   dWrite1
 * \par Description
 *   Set the digital output value on slot1 of current RJ25 object's port
 * \param[in]
 *   value - digital output value HIGH or LOW
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void dWrite1(bool value);

/**
 * \par Function
 *   dWrite2
 * \par Description
 *   Set the digital output value on slot2 of current RJ25 object's port
 * \param[in]
 *   value - digital output value HIGH or LOW
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void dWrite2(bool value);
  void dWrite3(bool value);
  void dWrite4(bool value);
  void dWrite5(bool value);
/**
 * \par Function
 *   aRead1
 * \par Description
 *   Read the analog value on slot1 of current RJ25 object's port
 * \par Output
 *   None
 * \return
 *   Analog value from 0-1023
 * \par Others
 *   None
 */
  int16_t aRead1(void);

/**
 * \par Function
 *   aRead2
 * \par Description
 *   Read the analog value on slot2 of current RJ25 object's port
 * \par Output
 *   None
 * \return
 *   Analog value from 0-1023
 * \par Others
 *   None
 */
  int16_t aRead2(void);
  int16_t aRead3(void);
  int16_t aRead4(void);
  int16_t aRead5(void);
/**
 * \par Function
 *   aWrite1
 * \par Description
 *   Set the PWM output value on slot1 of current RJ25 object's port
 * \param[in]
 *   value - Analog value between 0 to 255
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void aWrite1(int16_t value);

/**
 * \par Function
 *   aWrite2
 * \par Description
 *   Set the PWM output value on slot2 of current RJ25 object's port
 * \param[in]
 *   value - Analog value between 0 to 255
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void aWrite2(int16_t value);
  void aWrite3(int16_t value);
  void aWrite4(int16_t value);
  void aWrite5(int16_t value);
/**
 * \par Function
 *   reset
 * \par Description
 *   Reset the RJ25 available PIN by its port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void reset(uint8_t port);

/**
 * \par Function
 *   reset
 * \par Description
 *   Reset the RJ25 available PIN by its port and slot
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 * \par Output
 *   None
 * \return
 *   None
 * \par Others
 *   None
 */
  void reset(uint8_t port, uint8_t slot);

/**
 * \par Function
 *   pin1
 * \par Description
 *   Return the arduino pin number of current RJ25 object's slot1
 * \par Output
 *   None
 * \return
 *   The PIN number of arduino
 * \par Others
 *   None
 */
  uint8_t pin1(void);

/**
 * \par Function
 *   pin2
 * \par Description
 *   Return the arduino pin number of current RJ25 object's slot2
 * \par Output
 *   None
 * \return
 *   The PIN number of arduino
 * \par Others
 *   None
 */
  uint8_t pin2(void);
  uint8_t pin3(void);
  uint8_t pin4(void);
  uint8_t pin5(void);
/**
 * \par Function
 *   pin
 * \par Description
 *   Return the arduino pin number of current RJ25 object's port, if the RJ25 module
 *   have one available PIN.
 * \par Output
 *   None
 * \return
 *   The PIN number of arduino
 * \par Others
 *   None
 */
  uint8_t pin(void);

/**
 * \par Function
 *   pin
 * \par Description
 *   Return the arduino pin number of current RJ25 object's port
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 * \par Output
 *   None
 * \return
 *   The PIN number of arduino
 * \par Others
 *   None
 */
  uint8_t pin(uint8_t port, uint8_t slot);

protected:

/**
 *  \par Description
 *  Variables used to store the slot1 gpio number
 */
  uint8_t s1, s2, s3, s4, s5, s6;
/**
 *  \par Description
 *  Variables used to store the port
 */

  uint8_t _port;

/**
 *  \par Description
 *  Variables used to store the slot
 */
  uint8_t _slot;
};
#endif // _RH20Port_H_