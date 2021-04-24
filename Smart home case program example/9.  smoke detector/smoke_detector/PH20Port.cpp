#include "PH20Port.h"

PH20Port_Sig PH20_Port[RJ25_MAX] =
{
  { A3, NC, NC, NC, NC, NC },  //1
  { A2, NC, NC, NC, NC, NC },  //2
  { A1, NC, NC, NC, NC, NC },  //3
  { A0, NC, NC, NC, NC, NC },  //4
  {  7, A0, NC, NC, NC, NC },  //5
  {  8, A1, NC, NC, NC, NC },  //6
  { A5, A4, NC, NC, NC, NC },  //7
  {  6,  5, NC, NC, NC, NC },  //8
  {  3, NC, NC, NC, NC, NC },  //9
  {  4, NC, NC, NC, NC, NC },  //10
  {  5, NC, NC, NC, NC, NC },  //11
  {  6, NC, NC, NC, NC, NC },  //12
  {  4,  7,  8, A3, NC, NC },  //13
  {  2,  7, A5, A4, NC, NC },  //14
  { NC, NC,  3,  5,  6, NC },  //15
  { NC, NC, A4, A5,  2, NC },  //16
};

/***********************Port*********************/
/**
 * Alternate Constructor which can call your own function to map the PH20Port to arduino port,
 * no pins are used or initialized here
 */
PH20Port::PH20Port(void)
{
  s1 = PH20_Port[0].s1;
  s2 = PH20_Port[0].s2;
  s3 = PH20_Port[0].s3;
  s4 = PH20_Port[0].s4;
  s5 = PH20_Port[0].s5;
  s6 = PH20_Port[0].s6;
  _port = 0;
}

/**
 * Alternate Constructor which can call your own function to map the PH20Port to arduino port,
 * no pins are used or initialized here, but PWM frequency set to 976 Hz
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 */
PH20Port::PH20Port(uint8_t port)
{
  if (port < 1) return;
  s1 = PH20_Port[port-1].s1;
  s2 = PH20_Port[port-1].s2;
  s3 = PH20_Port[port-1].s3;
  s4 = PH20_Port[port-1].s4;
  s5 = PH20_Port[port-1].s5;
  s6 = PH20_Port[port-1].s6;
  _port = port;
}


/**
 * Alternate Constructor which can call your own function to map the PH20Port to arduino port,
 * no pins are used or initialized here, but PWM frequency set to 976 Hz
 * \param[in]
 *   port - RJ25 port from PORT_1 to M2
 * \param[in]
 *   slot - SLOT1 or SLOT2
 */
PH20Port::PH20Port(uint8_t port, uint8_t slot)
{
  if (port < 1) return;
  s1 = PH20_Port[port-1].s1;
  s2 = PH20_Port[port-1].s2;
  _port = port;
  _slot = slot;
}

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
uint8_t PH20Port::getPort()
{
  return(_port);
}

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
uint8_t PH20Port::getSlot(void)
{
  return(_slot);
}

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
bool PH20Port::dRead1(uint8_t mode)
{
  bool val;
  pinMode(s1, mode);
  val = digitalRead(s1);
  return(val);
}

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
bool PH20Port::dRead2(uint8_t mode)
{
  bool val;
  pinMode(s2, mode);
  val = digitalRead(s2);
  return(val);
}

bool PH20Port::dRead3(uint8_t mode)
{
  bool val;
  pinMode(s3, mode);
  val = digitalRead(s3);
  return(val);
}

bool PH20Port::dRead4(uint8_t mode)
{
  bool val;
  pinMode(s4, mode);
  val = digitalRead(s4);
  return(val);
}

bool PH20Port::dRead5(uint8_t mode)
{
  bool val;
  pinMode(s5, mode);
  val = digitalRead(s5);
  return(val);
}



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
bool PH20Port::dpRead1(void)
{
  bool val;
  pinMode(s1, INPUT_PULLUP);
  val = digitalRead(s1);
  return(val);
}

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
bool PH20Port::dpRead2(void)
{
  bool val;
  pinMode(s2, INPUT_PULLUP);
  val = digitalRead(s2);
  return(val);
}

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
void PH20Port::dWrite1(bool value)
{
  pinMode(s1, OUTPUT);
  digitalWrite(s1, value);
}

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
void PH20Port::dWrite2(bool value)
{
  pinMode(s2, OUTPUT);
  digitalWrite(s2, value);
}

void PH20Port::dWrite3(bool value)
{
  pinMode(s3, OUTPUT);
  digitalWrite(s3, value);
}
void PH20Port::dWrite4(bool value)
{
  pinMode(s4, OUTPUT);
  digitalWrite(s4, value);
}
void PH20Port::dWrite5(bool value)
{
  pinMode(s5, OUTPUT);
  digitalWrite(s5, value);
}

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
int16_t PH20Port::aRead1(void)
{
  int16_t val;
  pinMode(s1, INPUT);
  val = analogRead(s1);
  return(val);
}

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
int16_t PH20Port::aRead2(void)
{
  int16_t val;
  pinMode(s2, INPUT);
  val = analogRead(s2);
  return(val);
}

int16_t PH20Port::aRead3(void)
{
  int16_t val;
  pinMode(s3, INPUT);
  val = analogRead(s3);
  return(val);
}

int16_t PH20Port::aRead4(void)
{
  int16_t val;
  pinMode(s4, INPUT);
  val = analogRead(s4);
  return(val);
}

int16_t PH20Port::aRead5(void)
{
  int16_t val;
  pinMode(s5, INPUT);
  val = analogRead(s5);
  return(val);
}
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
void PH20Port::aWrite1(int16_t value)
{
  analogWrite(s1, value);
}

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
void PH20Port::aWrite2(int16_t value)
{
  analogWrite(s2, value);
}

void PH20Port::aWrite3(int16_t value)
{
  analogWrite(s3, value);
}
void PH20Port::aWrite4(int16_t value)
{
  analogWrite(s4, value);
}
void PH20Port::aWrite5(int16_t value)
{
  analogWrite(s5, value);
}
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
void PH20Port::reset(uint8_t port)
{
  if ( port < 1) return;
  s1 = PH20_Port[port-1].s1;
  s2 = PH20_Port[port-1].s2;
  _port = port;
}

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
void PH20Port::reset(uint8_t port, uint8_t slot)
{
  if ( port < 1) return;
  s1 = PH20_Port[port-1].s1;
  s2 = PH20_Port[port-1].s2;
  _port = port;
  _slot = slot;
}

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
uint8_t PH20Port::pin1(void)
{
  return(s1);
}

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
uint8_t PH20Port::pin2(void)
{
  return(s2);
}

uint8_t PH20Port::pin3(void)
{
  return(s3);
}
uint8_t PH20Port::pin4(void)
{
  return(s4);
}
uint8_t PH20Port::pin5(void)
{
  return(s5);
}
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
uint8_t PH20Port::pin(void)
{
  return(_slot == SLOT_1 ? s1 : s2);
}

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
uint8_t PH20Port::pin(uint8_t port, uint8_t slot)
{
  if ( port < 1) return;
  return(slot == SLOT_1 ? PH20_Port[port-1].s1 : PH20_Port[port-1].s2);
}