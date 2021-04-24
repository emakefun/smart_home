'use strict';

goog.provide('Blockly.Arduino.sensor');

goog.require('Blockly.Arduino');



//��������value ת���Ƕ�value
Blockly.Arduino.kw_servo = function () {
     var value_servopin = Blockly.Arduino.valueToCode(this, 'servopin', Blockly.Arduino.ORDER_ATOMIC);
	var value_servoangle = Blockly.Arduino.valueToCode(this, 'servoangle', Blockly.Arduino.ORDER_ATOMIC);
Blockly.Arduino.setups_['setup_servo'] = 'pinMode('+value_servopin+', OUTPUT);';
Blockly.Arduino.definitions_['define_servo1'] = 'void SetServoDegree(int Angle){\nfor (int i = 0; i < 80; i++) {\nfloat pulsewidth = (Angle * 11) + 350;\ndigitalWrite('+value_servopin+', HIGH);\n   delayMicroseconds(pulsewidth);\n  digitalWrite('+value_servopin+', LOW);\n   delayMicroseconds(20000 - pulsewidth);\n}}';
	 var code = 'SetServoDegree('+value_servoangle+');\n'
    //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';

    return code;
};
//��ʼ��7��������
Blockly.Arduino.kw_7ledinit = function () {
    var value_pin1 = Blockly.Arduino.valueToCode(this, 'pin1', Blockly.Arduino.ORDER_ATOMIC);
	var value_pin2 = Blockly.Arduino.valueToCode(this, 'pin2', Blockly.Arduino.ORDER_ATOMIC);
	var value_pin3 = Blockly.Arduino.valueToCode(this, 'pin3', Blockly.Arduino.ORDER_ATOMIC);
	var value_pin4 = Blockly.Arduino.valueToCode(this, 'pin4', Blockly.Arduino.ORDER_ATOMIC);
	var value_pin5 = Blockly.Arduino.valueToCode(this, 'pin5', Blockly.Arduino.ORDER_ATOMIC);
	var value_pin6 = Blockly.Arduino.valueToCode(this, 'pin6', Blockly.Arduino.ORDER_ATOMIC);
	var value_pin7 = Blockly.Arduino.valueToCode(this, 'pin7', Blockly.Arduino.ORDER_ATOMIC);
	var value_pin8 = Blockly.Arduino.valueToCode(this, 'pin8', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_7led1'] = '#include<SegmentDisplay.h>';
	 Blockly.Arduino.definitions_['define_7led'] = 'SegmentDisplay _7SegmentDisplay('+value_pin1+', '+value_pin2+', '+value_pin3+', '+value_pin4+', '+value_pin5+', '+value_pin6+', '+value_pin7+', '+value_pin8+');'
//Blockly.Arduino.setups_['setup_7led'] ='\t'+'int i;\n'+'Serial.begin(115200);\n'+'DisplayOff();\n'+'for( i = 0 ; i < 8 ; i++ ){'+'pinMode( LED_PIN[i] ,OUTPUT );}\n'
    //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';
    var code = '';
    return code;
};
//7����������ʾ����value
Blockly.Arduino.kw_7leddisplaynum = function () {
     var value_displaynum = Blockly.Arduino.valueToCode(this, 'displaynum', Blockly.Arduino.ORDER_ATOMIC);


	 var code = '_7SegmentDisplay.DisplayChar((byte)'+value_displaynum+');\n'
    //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';

    return code;
};
//��ʼ��4*7��������
Blockly.Arduino.kw_47ledinit = function () {
    var value_Pin1 = Blockly.Arduino.valueToCode(this, 'Pin1', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin2 = Blockly.Arduino.valueToCode(this, 'Pin2', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin3 = Blockly.Arduino.valueToCode(this, 'Pin3', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin4 = Blockly.Arduino.valueToCode(this, 'Pin4', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin5 = Blockly.Arduino.valueToCode(this, 'Pin5', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin6 = Blockly.Arduino.valueToCode(this, 'Pin6', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin7 = Blockly.Arduino.valueToCode(this, 'Pin7', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin8 = Blockly.Arduino.valueToCode(this, 'Pin8', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin9 = Blockly.Arduino.valueToCode(this, 'Pin9', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin10 = Blockly.Arduino.valueToCode(this, 'Pin10', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin11 = Blockly.Arduino.valueToCode(this, 'Pin11', Blockly.Arduino.ORDER_ATOMIC);
	var value_Pin12 = Blockly.Arduino.valueToCode(this, 'Pin12', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_comport'] = '#include<SegmentDisplay.h>';
	 Blockly.Arduino.definitions_['define_47led'] = 'SegmentDisplay _4Bit_7SegmentDisplay('+value_Pin1+', '+value_Pin2+', '+value_Pin3+', '+value_Pin4+', '+value_Pin5+', '+value_Pin6+', '+value_Pin7+', '+value_Pin8+', '+value_Pin9+', '+value_Pin10+', '+value_Pin11+', '+value_Pin12+');';
	 Blockly.Arduino.setups_['setup_input_47led'] = '_4Bit_7SegmentDisplay.TurnOffAllLed();';
    var code = '';
    return code;
};
//4*7����������ʾ
Blockly.Arduino.kw_7ledcountnum = function () {
     var value_count = Blockly.Arduino.valueToCode(this, 'count', Blockly.Arduino.ORDER_ATOMIC);
	//Blockly.Arduino.definitions_['define_count'] = 'char disp[4] = { 0 , 0 , 0 , 0 } ;\nint display_dat = '+value_count+', count = 0 ;\n'+'char LED_Display_Value[][3]  ={    { \'0\', 0x3F , 0xC0 } ,\n{ \'1\', 0x06 , 0xF9 } ,\n{ \'2\', 0x5B , 0xA4 } ,\n{ \'3\', 0x4F , 0xB0 } ,\n{ \'4\', 0x66 , 0x99 } ,\n{ \'5\', 0x6D , 0x92 } ,\n{ \'6\', 0x7D , 0x82 } ,\n{ \'7\', 0x07 , 0xF8 } ,\n{ \'8\', 0x7F , 0x80 } ,\n{ \'9\', 0x6F , 0x90 } ,\n{  0 , 0x00 , 0xFF }\n};\n'+'void  DisplayOff(void){\nint i ;\nfor( i = 0 ; i < 8 ; i++)\ndigitalWrite(LED_PIN[i],LOW);\nfor( i = 0 ; i < 4 ; i++)\ndigitalWrite(LED_SELECT[i],HIGH);\n}\nchar  GetDisplayValue(char Array[][3] ,\n char DisplayChar ){int i = 0 ;\nfor( i = 0 ; i < 10 ; i++){if( Array[i][0] == DisplayChar )\n            return Array[i][COM_PORT] ;\n       }\n    return 0 ;\n}void LED_Display ( char ch){\nint i ;\nfor( i = 0 ; i < 8 ; i++){\nif(  ch & ( 1 << i ) ){\ndigitalWrite(LED_PIN[i] ,HIGH);\n}else{\ndigitalWrite(LED_PIN[i],LOW);\n}\n}\n}\nvoid numble2dis( int numble ){\nint numble_bit = 0 ;int bit_base = 1000 ;\nfor( numble_bit = 0 ; numble_bit < 4 ; numble_bit++ ){\nif( numble/bit_base != 0){\ndisp[numble_bit] = numble/bit_base + \'0\';\nnumble = numble % bit_base ;\n}else{\ndisp[numble_bit] = \'0\';\n}\nbit_base = bit_base / 10 ;\n}}';
	//Blockly.Arduino.setups_['setup_47count'] ='\t'+'int i;\nfor( i = 0 ; i < 8 ; i++ )\npinMode( LED_PIN[i] ,OUTPUT ) ;\nfor( i = 0 ; i < 4 ; i++ )\npinMode( LED_SELECT[i] ,OUTPUT ) ;\nDisplayOff();\n';
	 var code = '_4Bit_7SegmentDisplay.DisplayChar('+value_count+');';
	 //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';

    return code;
};

Blockly.Arduino.kw_7ledcountnumoff = function () {
    // var value_count = Blockly.Arduino.valueToCode(this, 'count', Blockly.Arduino.ORDER_ATOMIC);
	//Blockly.Arduino.definitions_['define_count'] = 'char disp[4] = { 0 , 0 , 0 , 0 } ;\nint display_dat = '+value_count+', count = 0 ;\n'+'char LED_Display_Value[][3]  ={    { \'0\', 0x3F , 0xC0 } ,\n{ \'1\', 0x06 , 0xF9 } ,\n{ \'2\', 0x5B , 0xA4 } ,\n{ \'3\', 0x4F , 0xB0 } ,\n{ \'4\', 0x66 , 0x99 } ,\n{ \'5\', 0x6D , 0x92 } ,\n{ \'6\', 0x7D , 0x82 } ,\n{ \'7\', 0x07 , 0xF8 } ,\n{ \'8\', 0x7F , 0x80 } ,\n{ \'9\', 0x6F , 0x90 } ,\n{  0 , 0x00 , 0xFF }\n};\n'+'void  DisplayOff(void){\nint i ;\nfor( i = 0 ; i < 8 ; i++)\ndigitalWrite(LED_PIN[i],LOW);\nfor( i = 0 ; i < 4 ; i++)\ndigitalWrite(LED_SELECT[i],HIGH);\n}\nchar  GetDisplayValue(char Array[][3] ,\n char DisplayChar ){int i = 0 ;\nfor( i = 0 ; i < 10 ; i++){if( Array[i][0] == DisplayChar )\n            return Array[i][COM_PORT] ;\n       }\n    return 0 ;\n}void LED_Display ( char ch){\nint i ;\nfor( i = 0 ; i < 8 ; i++){\nif(  ch & ( 1 << i ) ){\ndigitalWrite(LED_PIN[i] ,HIGH);\n}else{\ndigitalWrite(LED_PIN[i],LOW);\n}\n}\n}\nvoid numble2dis( int numble ){\nint numble_bit = 0 ;int bit_base = 1000 ;\nfor( numble_bit = 0 ; numble_bit < 4 ; numble_bit++ ){\nif( numble/bit_base != 0){\ndisp[numble_bit] = numble/bit_base + \'0\';\nnumble = numble % bit_base ;\n}else{\ndisp[numble_bit] = \'0\';\n}\nbit_base = bit_base / 10 ;\n}}';
	//Blockly.Arduino.setups_['setup_47count'] ='\t'+'int i;\nfor( i = 0 ; i < 8 ; i++ )\npinMode( LED_PIN[i] ,OUTPUT ) ;\nfor( i = 0 ; i < 4 ; i++ )\npinMode( LED_SELECT[i] ,OUTPUT ) ;\nDisplayOff();\n';
	 var code = '_4Bit_7SegmentDisplay.TurnOffAllLed();';
	 //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';

    return code;
};
//����������
Blockly.Arduino.kw_ultrasonicread = function () {
    var value_trigpin = Blockly.Arduino.valueToCode(this, 'trigpin', Blockly.Arduino.ORDER_ATOMIC);
	var value_echopin = Blockly.Arduino.valueToCode(this, 'echopin', Blockly.Arduino.ORDER_ATOMIC);
	var value_servos = Blockly.Arduino.valueToCode(this, 'servos', Blockly.Arduino.ORDER_ATOMIC);
	//Blockly.Arduino.definitions_['define_radar'] = '#include <Servo.h>';
	 Blockly.Arduino.definitions_['define_ultrasonicread'] = 'float checkdistance() {\ndigitalWrite('+value_trigpin+', LOW);\ndelayMicroseconds(2);\ndigitalWrite('+value_trigpin+', HIGH);\ndelayMicroseconds(10);\ndigitalWrite('+value_trigpin+', LOW);\nfloat distance = pulseIn('+value_echopin+', HIGH) / 58.00;\ndelay(10);\nreturn distance;\n}\n';
	 Blockly.Arduino.setups_['setup_ultrasonicread'] ='\t'+'pinMode('+value_trigpin+', OUTPUT);\npinMode('+value_echopin+', INPUT);\n'
    //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';
    var code = 'checkdistance()'
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};

//��ʼ��������
Blockly.Arduino.kw_dianzhen = function () {
    var value_clk = Blockly.Arduino.valueToCode(this, 'clk', Blockly.Arduino.ORDER_ATOMIC);
	var value_cs = Blockly.Arduino.valueToCode(this, 'cs', Blockly.Arduino.ORDER_ATOMIC);
	var value_din = Blockly.Arduino.valueToCode(this, 'din', Blockly.Arduino.ORDER_ATOMIC);
	var value_count = Blockly.Arduino.valueToCode(this, 'count', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_dianzhen'] = '#include "MAX7219_MaxMatrix.h"';
	 Blockly.Arduino.definitions_['define_dianzhen1'] = 'MaxMatrix ledmatrix('+value_din+','+value_cs+','+value_clk+', '+value_count+');\n';
	 Blockly.Arduino.setups_['setup_dianzhen'] ='\t'+'ledmatrix.init();\nledmatrix.setIntensity(1);\nledmatrix.clearMatrix();\n';
	 //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';
    var code = '';
	return code;
};
//��������ʾ ����
Blockly.Arduino.kw_dianzhenprint = function () {
     var dropdown_maximage = this.getFieldValue('maximage');
	//var value_cs = Blockly.Arduino.valueToCode(this, 'cs', Blockly.Arduino.ORDER_ATOMIC);
	//var value_din = Blockly.Arduino.valueToCode(this, 'din', Blockly.Arduino.ORDER_ATOMIC);
	//Blockly.Arduino.definitions_['define_dianzhen'] = '#include "LedControl.h"';
	 //Blockly.Arduino.definitions_['define_dianzhen1'] = 'int CLK = '+value_clk+';\nint CS =  '+value_cs+';\nint DIN = '+value_din+';\n'+'LedControl lc=LedControl(DIN,CLK,CS,0);\n'+'void printByte(byte character []){\nint i = 0;\nfor(i=0;i<8;i++){\nlc.setRow(0,i,character[i]);\n}}\n';
	 //Blockly.Arduino.setups_['setup_dianzhen'] ='\t'+'lc.shutdown(0,false);\nlc.setIntensity(0,15);\nlc.clearDisplay(0);\n';
	 //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';
    var code = ' ledmatrix.writeFull(ledmatrix.getMouthShape('+dropdown_maximage+'));\n';
	return code;
};
//�������������ݿɶ�
Blockly.Arduino.kw_getbluetooth = function () {
       var code = 'Serial.available() > 0'
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//���ڶ�ȡ��������
Blockly.Arduino.kw_getbluetoothdata = function () {
       var code = 'char(Serial.read())'
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};

//��ʼ������ң�� ����value
Blockly.Arduino.kw_initir = function () {
	 var value_initir = Blockly.Arduino.valueToCode(this, 'initir', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_initir'] = '#include "IR_remote.h"\n#include "keymap.h"\n'+'IRremote ir('+value_initir+');\n';
	Blockly.Arduino.setups_['setup_initir'] = 'ir.begin();\n';
	var code = '';
    return code;
};
// ��ͨ����ң�ذ���������������boolean��
Blockly.Arduino.kw_irKeyPress = function(){
 var dropdown_Irkey = this.getFieldValue('Irkey');
 var code = 'ir.getIrKey(ir.getCode(),1) == '+dropdown_Irkey+'';
 return [code, Blockly.Arduino.ORDER_ATOMIC]; //��codeΪ����ʽʱ�ô˷��ط�ʽ
};
// EMAKEFUN����ң�ذ���������������boolean��
Blockly.Arduino.kw_irKeyPress2 = function(){
 var dropdown_Irkey2 = this.getFieldValue('Irkey2');
 var code = 'ir.getIrKey(ir.getCode(),2) == '+dropdown_Irkey2+'';
 return [code, Blockly.Arduino.ORDER_ATOMIC]; //��codeΪ����ʽʱ�ô˷��ط�ʽ
};
Blockly.Arduino.kw_irKeyPress3 = function(){
 var code = 'ir.getCode()';
 return [code, Blockly.Arduino.ORDER_ATOMIC]; //��codeΪ����ʽʱ�ô˷��ط�ʽ
};
//����DS3231ʱ��ʱ�� ����������ʱ����
Blockly.Arduino.kw_ds3231setdate = function () {
    var value_year = Blockly.Arduino.valueToCode(this, 'year', Blockly.Arduino.ORDER_ATOMIC);
	var value_month = Blockly.Arduino.valueToCode(this, 'month', Blockly.Arduino.ORDER_ATOMIC);
	var value_day = Blockly.Arduino.valueToCode(this, 'day', Blockly.Arduino.ORDER_ATOMIC);
	var value_week = Blockly.Arduino.valueToCode(this, 'week', Blockly.Arduino.ORDER_ATOMIC);
	var value_hour = Blockly.Arduino.valueToCode(this, 'hour', Blockly.Arduino.ORDER_ATOMIC);
	var value_minute = Blockly.Arduino.valueToCode(this, 'minute', Blockly.Arduino.ORDER_ATOMIC);
	var value_sencond = Blockly.Arduino.valueToCode(this, 'sencond', Blockly.Arduino.ORDER_ATOMIC);
Blockly.Arduino.setups_['setup_ds3231setdate'] = 'Wire.begin();\n'+'Clock.setSecond('+value_sencond+');\n'+'Clock.setMinute('+value_minute+');\n'+'Clock.setHour('+value_hour+');\n'+'Clock.setDoW('+value_week+');\n'+'Clock.setDate('+value_day+');\n'+'Clock.setMonth('+value_month+');\n'+'Clock.setYear('+value_year+');\n';
	Blockly.Arduino.definitions_['define_ds3231setdate'] = '#include \"DS3231.h\"\n#include \"LCD.h\"\n'+'DS3231 Clock;\n'+'bool Century=false;\n'+'bool h12;\n'+'bool PM;\n'+'char lcd_dis_str[2][16];\n';
	 //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';
    var code = '';
    return code;
};
//da3231ʱ�ӻ�ȡʱ��
Blockly.Arduino.kw_ds3231gettime = function () {
	Blockly.Arduino.definitions_['define_ds3231gettime'] = 'void ReadDS3231()\n{\n    int second,minute,hour,date,month,year,temperature;\n    second=Clock.getSecond();\n    minute=Clock.getMinute();\n    hour=Clock.getHour(h12, PM);\n    date=Clock.getDate();\n    month=Clock.getMonth(Century);\n    year=Clock.getYear();\n  temperature=Clock.getTemperature();\n  sprintf(lcd_dis_str[0],\"  20%02d-%02d-%02d\",year,month,date);\n  sprintf(lcd_dis_str[1],\"   %02d:%02d:%02d  %2d\'\",hour,minute,second,temperature);\n}\n';
	//Blockly.Arduino.setups_['setup_I2CLED'] = 'lcd.begin (16,2);\n'+'lcd.setBacklightPin(3,POSITIVE);\n'+'lcd.setBacklight(HIGH);\n';
	var code = 'ReadDS3231();\n';
    return code;
};
//da3231ʱ�Ӷ�ȡ������
Blockly.Arduino.kw_ds3231readyear = function () {
       var code = 'lcd_dis_str[0]'
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//da3231ʱ�Ӷ�ȡʱ�����¶�
Blockly.Arduino.kw_ds3231readhour = function () {
       var code = 'lcd_dis_str[1]'
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//���þ�����������
Blockly.Arduino.kw_keypad = function () {
    var value_row_1 = Blockly.Arduino.valueToCode(this, 'row_1', Blockly.Arduino.ORDER_ATOMIC);
	var value_row_2 = Blockly.Arduino.valueToCode(this, 'row_2', Blockly.Arduino.ORDER_ATOMIC);
	var value_row_3 = Blockly.Arduino.valueToCode(this, 'row_3', Blockly.Arduino.ORDER_ATOMIC);
	var value_row_4 = Blockly.Arduino.valueToCode(this, 'row_4', Blockly.Arduino.ORDER_ATOMIC);
	var value_COL_1 = Blockly.Arduino.valueToCode(this, 'COL_1', Blockly.Arduino.ORDER_ATOMIC);
	var value_COL_2 = Blockly.Arduino.valueToCode(this, 'COL_2', Blockly.Arduino.ORDER_ATOMIC);
	var value_COL_3 = Blockly.Arduino.valueToCode(this, 'COL_3', Blockly.Arduino.ORDER_ATOMIC);
	var value_COL_4 = Blockly.Arduino.valueToCode(this, 'COL_4', Blockly.Arduino.ORDER_ATOMIC);
//Blockly.Arduino.setups_['setup_ds3231setdate'] = 'Wire.begin();\n'+'Clock.setSecond('+value_second+');\n'+'Clock.setMinute('+value_minute+');\n'+'Clock.setHour('+value_hour+');\n'+'Clock.setDoW('+value_week+');\n'+'Clock.setDate('+value_day+');\n'+'Clock.setMonth('+value_month+');\n'+'Clock.setYear('+value_year+');\n';
	Blockly.Arduino.definitions_['define_keypad'] = '#include \"Keypad.h\"\n'+'#define   ROW_1   '+value_row_1+'\n#define   ROW_2   '+value_row_2+'\n#define   ROW_3   '+value_row_3+'\n#define   ROW_4   '+value_row_4+'\n#define   COL_1   '+value_COL_1+'\n#define   COL_2  '+value_COL_2+'\n#define   COL_3   '+value_COL_3+'\n#define   COL_4   '+value_COL_4+'\nconst byte ROWS = 4;\nconst byte COLS = 4;\nchar hexaKeys[ROWS][COLS] = {\n  {\'1\',\'2\',\'3\',\'A\'},\n  {\'4\',\'5\',\'6\',\'B\'},\n  {\'7\',\'8\',\'9\',\'C\'},\n  {\'*\',\'0\',\'#\',\'D\'}\n};\nbyte rowPins[ROWS] = {'+value_row_1+', '+value_row_2+', '+value_row_3+', '+value_row_4+'};\nbyte colPins[COLS] = {'+value_COL_1+', '+value_COL_2+', '+value_COL_3+', '+value_COL_4+'};\nKeypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);\n';
	 //Blockly.Arduino.setups_['setup_input_'+dropdown_pin] = 'pinMode('+dropdown_pin+', INPUT);';
    var code = '';
    return code;
};
//��ȡ��������ֵ
Blockly.Arduino.kw_getkeypad = function () {
	Blockly.Arduino.definitions_['define_getkeypad'] = 'char customKey = customKeypad.getKey();\n';
	Blockly.Arduino.setups_['setup_getkeypad'] = 'int i ;\n for(i=0 ; i< ROWS ; i++)    {\npinMode(rowPins[i],OUTPUT);\npinMode(colPins[i],OUTPUT);\n    }\n';
	var code = 'char customKey = customKeypad.getKey();\n';
    return code;
};
//�������̰���������
Blockly.Arduino.kw_keypadpressed = function () {
       var code = 'customKey';
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//�������̰���ֵ
Blockly.Arduino.kw_keypadvalue = function () {
       var code = 'customKey';
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//������������
Blockly.Arduino.kw_getbluetoothvalue = function () {
	Blockly.Arduino.definitions_['define_getbluetoothvalue'] = '#include \"ProtocolParser.h\"\n'+'ProtocolParser *mProtocol = new ProtocolParser();\n';
	var code = 'mProtocol->RecevData();\n';
    return code;
};
//���յ�����������
Blockly.Arduino.kw_dogetbluetoothvalue = function () {
       var code = 'mProtocol->ParserPackage()';
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//����ģʽ ����������boolean
Blockly.Arduino.kw_bluetoothmode = function () {
	var dropdown_Bluetoothmodes = this.getFieldValue('Bluetoothmodes');
       var code = 'mProtocol->GetRobotControlFun()=='+dropdown_Bluetoothmodes+'';
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//������ȡRGBֵ
Blockly.Arduino.kw_bluetoothgetrgbvalue = function () {
		var code = ' mProtocol->GetRgbValue()';
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//��������
Blockly.Arduino.kw_bluetoothsetrgb = function () {
		var code = 'setColor( color>>16, (color>>8)&0xFF, color&0xFF);\n';
    return code;
};
//��������
Blockly.Arduino.kw_bluetoothsetbuzzer = function () {
	Blockly.Arduino.definitions_['define_bluetoothsetbuzzer'] = 'void PianoSing(byte b[])\n{\n    union result\n    {\n      float d;\n      unsigned char data[4];\n    }r1,r2;\n    r2.data[0]=b[0];\n    r2.data[1]=b[1];\n    r2.data[2]=b[2];\n    r2.data[3]=b[3];\n    mBuzzer->_tone(r2.d,120, 2);\n}\n';
	var code = 'PianoSing((byte *)mProtocol->GetPianoSing());\n';
    return code;
};
//����������value
Blockly.Arduino.kw_buzzerpin = function () {
	 var value_buzzerpin = Blockly.Arduino.valueToCode(this, 'buzzerpin', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_buzzerpin'] = '#include \"Buzzer.h\"\n'+'Buzzer *mBuzzer = new Buzzer('+value_buzzerpin+');\n';
	Blockly.Arduino.setups_['setup_buzzerpin'] = ' pinMode('+value_buzzerpin+', OUTPUT);\n';
	var code = '';
    return code;
};
//IIC����������

Blockly.Arduino.kw_iicinit = function () {
	 var value_clk = Blockly.Arduino.valueToCode(this, 'clk', Blockly.Arduino.ORDER_ATOMIC);
	 var value_dio = Blockly.Arduino.valueToCode(this, 'dio', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_iicinit'] = '#include \"TM1637.h\"\nTM1637 tm1637('+value_clk+','+value_dio+');\n';
	Blockly.Arduino.setups_['setup_iicinit'] = ' tm1637.set();\ntm1637.init();\ntm1637.point(POINT_OFF);\n';
	var code = '';
    return code;
};

Blockly.Arduino.kw_iicdisplaynum = function () {
	 var value_num1 = Blockly.Arduino.valueToCode(this, 'num1', Blockly.Arduino.ORDER_ATOMIC);
	 var value_num2 = Blockly.Arduino.valueToCode(this, 'num2', Blockly.Arduino.ORDER_ATOMIC);
	 var value_num3 = Blockly.Arduino.valueToCode(this, 'num3', Blockly.Arduino.ORDER_ATOMIC);
	 var value_num4 = Blockly.Arduino.valueToCode(this, 'num4', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_iicdisplaynum'] = 'int8_t Disp[] = {'+value_num1+', '+value_num2+', '+value_num3+', '+value_num4+'};';
	//Blockly.Arduino.setups_['setup_iicinit'] = ' tm1637.set();\ntm1637.init();\ntm1637.point(POINT_OFF);\n';
	var code = 'tm1637.display(Disp);\nwhile(1);\n';
    return code;
};
Blockly.Arduino.kw_iictube = function () {
	 var value_hours = Blockly.Arduino.valueToCode(this, 'hours', Blockly.Arduino.ORDER_ATOMIC);
	 var value_minutes = Blockly.Arduino.valueToCode(this, 'minutes', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_iictube'] = '#include <TimerOne.h>\n#define ON 1\n#define OFF 0\nint8_t TimeDisp[] = {0x00,0x00,0x00,0x00};\nunsigned char ClockPoint = 1;\nunsigned char Update;\nunsigned char halfsecond = 0;\nunsigned char second;\nunsigned char minute = '+value_minutes+';\nunsigned char hour = '+value_hours+';\nvoid TimingISR()\n{\n  halfsecond ++;\n  Update = ON;\n  if(halfsecond == 2){\n    second ++;\n    if(second == 60)\n    {\n      minute ++;\n      if(minute == 60)\n      {\n        hour ++;\n        if(hour == 24)hour = 0;\n        minute = 0;\n      }\n      second = 0;\n    }\n    halfsecond = 0;  \n  }\n  ClockPoint = (~ClockPoint) & 0x01;\n}\nvoid TimeUpdate(void)\n{\n  if(ClockPoint)tm1637.point(POINT_ON);\n  else tm1637.point(POINT_OFF); \n  TimeDisp[0] = hour / 10;\n  TimeDisp[1] = hour % 10;\n  TimeDisp[2] = minute / 10;\n  TimeDisp[3] = minute % 10;\n  Update = OFF;\n}\n';
	Blockly.Arduino.setups_['setup_iictube'] = '  Timer1.initialize(500000);\n  Timer1.attachInterrupt(TimingISR);\n';
	var code = ' if(Update == ON)\n  {\n    TimeUpdate();\n    tm1637.display(TimeDisp);\n  }\n';
    return code;
};

Blockly.Arduino.kw_stepper = function () {
	 var value_in1 = Blockly.Arduino.valueToCode(this, 'in1', Blockly.Arduino.ORDER_ATOMIC);
	 var value_in2 = Blockly.Arduino.valueToCode(this, 'in2', Blockly.Arduino.ORDER_ATOMIC);
	 var value_in3 = Blockly.Arduino.valueToCode(this, 'in3', Blockly.Arduino.ORDER_ATOMIC);
	 var value_in4 = Blockly.Arduino.valueToCode(this, 'in4', Blockly.Arduino.ORDER_ATOMIC);
	 var value_ste = Blockly.Arduino.valueToCode(this, 'ste', Blockly.Arduino.ORDER_ATOMIC);

	Blockly.Arduino.definitions_['define_stepper'] = '#include \"KW_Stepper.h\"\nStepper stepper('+value_ste+', '+value_in1+', '+value_in2+', '+value_in3+', '+value_in4+');';
	//Blockly.Arduino.setups_['setup_iictube'] = ' tm1637.set();  tm1637.init();\n  Timer1.initialize(500000);\n  Timer1.attachInterrupt(TimingISR);\n';
	var code = ' ';
    return code;
};


Blockly.Arduino.kw_stepperspeed = function () {
	 var value_speed1 = Blockly.Arduino.valueToCode(this, 'speed1', Blockly.Arduino.ORDER_ATOMIC);

	//Blockly.Arduino.definitions_['define_stepper1'] = '#include \"KW_Stepper.h\"\nStepper stepper(200, '+value_in1+', '+value_in2+', '+value_in3+', '+value_in4+');';
	//Blockly.Arduino.setups_['setup_kw_stepperspeed'] = 'stepper.setSpeed('+value_speed1+');\n';
	var code = 'stepper.setSpeed('+value_speed1+');\n';
    return code;
};
Blockly.Arduino.kw_stepperspeed2 = function () {
	 //var value_speed1 = Blockly.Arduino.valueToCode(this, 'speed1', Blockly.Arduino.ORDER_ATOMIC);
	 var value_step1 = Blockly.Arduino.valueToCode(this, 'step1', Blockly.Arduino.ORDER_ATOMIC);
	//Blockly.Arduino.definitions_['define_stepper1'] = '#include \"KW_Stepper.h\"\nStepper stepper(200, '+value_in1+', '+value_in2+', '+value_in3+', '+value_in4+');';
	//Blockly.Arduino.setups_['setup_kw_stepperspeed'] = 'stepper.setSpeed('+value_speed1+');\n';
	var code = 'stepper.step('+value_step1+');\n';
    return code;
};
//4��lcd��ʼ��
Blockly.Arduino._4linelcd = function () {
	 var value_RS = Blockly.Arduino.valueToCode(this, 'RS', Blockly.Arduino.ORDER_ATOMIC);
	 var value_RW = Blockly.Arduino.valueToCode(this, 'RW', Blockly.Arduino.ORDER_ATOMIC);
	 var value_E = Blockly.Arduino.valueToCode(this, 'E', Blockly.Arduino.ORDER_ATOMIC);
	 var value_DB4 = Blockly.Arduino.valueToCode(this, 'DB4', Blockly.Arduino.ORDER_ATOMIC);
	 var value_DB5 = Blockly.Arduino.valueToCode(this, 'DB5', Blockly.Arduino.ORDER_ATOMIC);
	 var value_DB6 = Blockly.Arduino.valueToCode(this, 'DB6', Blockly.Arduino.ORDER_ATOMIC);
	 var value_DB7 = Blockly.Arduino.valueToCode(this, 'DB7', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define__4linelcd'] = '#include <LiquidCrystal.h>\nLiquidCrystal lcd('+value_RS+','+value_RW+','+value_E+','+value_DB4+','+value_DB5+','+value_DB6+','+value_DB7+');\n';
	Blockly.Arduino.setups_['setup__4linelcd'] = 'lcd.begin(16,2);\n';
	var code = '';
    return code;
};
//8��lcd
Blockly.Arduino._8linelcd = function () {
	var value__RS = Blockly.Arduino.valueToCode(this, '_RS', Blockly.Arduino.ORDER_ATOMIC);
	 var value__RW = Blockly.Arduino.valueToCode(this, '_RW', Blockly.Arduino.ORDER_ATOMIC);
	  var value__E = Blockly.Arduino.valueToCode(this, '_E', Blockly.Arduino.ORDER_ATOMIC);
	 	 var value__DB0 = Blockly.Arduino.valueToCode(this, '_DB0', Blockly.Arduino.ORDER_ATOMIC);
	 var value__DB1 = Blockly.Arduino.valueToCode(this, '_DB1', Blockly.Arduino.ORDER_ATOMIC);
	 var value__DB2 = Blockly.Arduino.valueToCode(this, '_DB2', Blockly.Arduino.ORDER_ATOMIC);
	 	 var value__DB3 = Blockly.Arduino.valueToCode(this, '_DB3', Blockly.Arduino.ORDER_ATOMIC);
	 var value__DB4 = Blockly.Arduino.valueToCode(this, '_DB4', Blockly.Arduino.ORDER_ATOMIC);
	 var value__DB5 = Blockly.Arduino.valueToCode(this, '_DB5', Blockly.Arduino.ORDER_ATOMIC);
	 var value__DB6 = Blockly.Arduino.valueToCode(this, '_DB6', Blockly.Arduino.ORDER_ATOMIC);
	 var value__DB7 = Blockly.Arduino.valueToCode(this, '_DB7', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define__8linelcd'] = '#include <LiquidCrystal.h>\nLiquidCrystal lcd('+value__RS+','+value__RW+','+value__E+','+value__DB0+','+value__DB1+','+value__DB2+','+value__DB3+','+value__DB4+','+value__DB5+','+value__DB6+','+value__DB7+'); ';
	Blockly.Arduino.setups_['setup__8linelcd'] = 'lcd.begin(16,2);\n';
	var code = '';
    return code;
};
//rgb������ģ����ʼ��
Blockly.Arduino.kw_initrgbultrasonic = function () {
	var value_ultrasonicpin = Blockly.Arduino.valueToCode(this, 'ultrasonicpin', Blockly.Arduino.ORDER_ATOMIC);
	var value_rgbpin = Blockly.Arduino.valueToCode(this, 'rgbpin', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_initrgbultrasonic'] = '#include <RgbUltrasonic.h>\nRgbUltrasonic mRUS04('+value_ultrasonicpin+','+value_rgbpin+');\n';
	var code = '';
    return code;
};
//����RGB������ģ����ɫ
Blockly.Arduino.kw_setcolor = function () {
    var dropdown_rgbposition = this.getFieldValue('rgbposition');
	var dropdown_rgbcolor = this.getFieldValue('rgbcolor');
    var code = '  mRUS04.SetRgbColor('+dropdown_rgbposition+','+dropdown_rgbcolor+');\n';
	return code;
};
//����RGB������ģ����ɫ��ʽ
Blockly.Arduino.kw_setcolorandstyle = function () {
    var dropdown_rgbposition = this.getFieldValue('rgbposition');
	var dropdown_rgbcolor = this.getFieldValue('rgbcolor');
	var dropdown_rgbstyle = this.getFieldValue('rgbstyle');
    var code = '  mRUS04.SetRgbEffect('+dropdown_rgbposition+', '+dropdown_rgbcolor+', '+dropdown_rgbstyle+');\n';
	return code;
};
//����RGB������ģ��������ʾ
Blockly.Arduino.kw_setrgbbreathe = function () {
    var dropdown_rgbposition = this.getFieldValue('rgbposition');
    var code = '  mRUS04.SetRgbEffect('+dropdown_rgbposition+', RGB_WHITE, E_EFFECT_BREATHING);\n';
	return code;
};
//RGB������ģ����ȡ����������
Blockly.Arduino.kw_readultrasonicdistance = function () {
       var code = 'mRUS04.GetUltrasonicDistance()'
    return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//8x8ledinit 8x8��������ʼ��
Blockly.Arduino['x8ledinit'] = function(block) {
var dropdown_ROW_0s = this.getFieldValue('ROW_0s');
var dropdown_ROW_1s = this.getFieldValue('ROW_1s');
var dropdown_ROW_2s = this.getFieldValue('ROW_2s');
var dropdown_ROW_3s = this.getFieldValue('ROW_3s');
var dropdown_ROW_4s = this.getFieldValue('ROW_4s');
var dropdown_ROW_5s = this.getFieldValue('ROW_5s');
var dropdown_ROW_6s = this.getFieldValue('ROW_6s');
var dropdown_ROW_7s = this.getFieldValue('ROW_7s');
var dropdown_LED_A1 = this.getFieldValue('LED_A1');
var dropdown_LED_B1 = this.getFieldValue('LED_B1');
var dropdown_LED_C1 = this.getFieldValue('LED_C1');
var dropdown_LED_D1 = this.getFieldValue('LED_D1');
var dropdown_LED_E1 = this.getFieldValue('LED_E1');
var dropdown_LED_F1 = this.getFieldValue('LED_F1');
var dropdown_LED_G1 = this.getFieldValue('LED_G1');
var dropdown_LED_H1 = this.getFieldValue('LED_H1');
Blockly.Arduino.setups_['x8ledinit'] = 'm8x8Dot = new MaxMatrix_8x8(ROW_PIN, COL_PIN);\n';
Blockly.Arduino.definitions_['include_8x8ledinit'] = '#include<MaxMatrix_8x8.h>\n';
Blockly.Arduino.definitions_['define_8x8ledinit'] = 'MaxMatrix_8x8 *m8x8Dot;\nconst byte ROW_PIN[8] = {'+dropdown_ROW_0s+', '+dropdown_ROW_1s+', '+dropdown_ROW_2s+', '+dropdown_ROW_3s+', '+dropdown_ROW_4s+', '+dropdown_ROW_5s+', '+dropdown_ROW_6s+', '+dropdown_ROW_7s+'};\nconst byte COL_PIN[8] = {'+dropdown_LED_A1+', '+dropdown_LED_B1+', '+dropdown_LED_C1+', '+dropdown_LED_D1+', '+dropdown_LED_E1+', '+dropdown_LED_F1+', '+dropdown_LED_G1+', '+dropdown_LED_H1+'};\n';
return  '';
}
//8x8��������ʾ
Blockly.Arduino.x8leddisplay = function() {
var maximage =  this.getFieldValue('maximage');
Blockly.Arduino.setups_['x8leddisplay'] = 'm8x8Dot->writeFull(m8x8Dot->getMouthShape('+maximage+'));\n';
return '';
};
//����ɨ����ʾ
Blockly.Arduino.x8ledloopscan = function() {
return 'm8x8Dot->scan();\n';
};
//74h初始化 74hinit
Blockly.Arduino._74hinit = function() {
var dropdown_BIT_CHOICE_11 =  this.getFieldValue('BIT_CHOICE_11');
var dropdown_BIT_CHOICE_22 =  this.getFieldValue('BIT_CHOICE_22');
var dropdown_BIT_CHOICE_33 =  this.getFieldValue('BIT_CHOICE_33');
var dropdown_BIT_CHOICE_44 =  this.getFieldValue('BIT_CHOICE_44');
var dropdown_STCP_PIN1 =  this.getFieldValue('STCP_PIN1');
var dropdown_SHCP_PIN1 =  this.getFieldValue('SHCP_PIN1');
var dropdown_DATA_PIN1 =  this.getFieldValue('DATA_PIN1');
Blockly.Arduino.definitions_['include__74hinit'] = '#include<SegmentDisplay.h>\nSegmentDisplay _74HC595_7SegmentDisplay('+dropdown_BIT_CHOICE_11+', '+dropdown_BIT_CHOICE_22+', '+dropdown_BIT_CHOICE_33+', '+dropdown_BIT_CHOICE_44+', '+dropdown_STCP_PIN1+', '+dropdown_SHCP_PIN1+', '+dropdown_DATA_PIN1+');';
return '';
};
//74h数码管显示 _74hinitisplay
Blockly.Arduino['_74hinitisplay'] = function(block) {
var value__74hinitisplays = Blockly.Arduino.valueToCode(this, '_74hinitisplays', Blockly.Arduino.ORDER_ATOMIC);
return  '_74HC595_7SegmentDisplay.DisplayChar((int)'+value__74hinitisplays+'); \n';
}
//74h熄灭 _74hoff
Blockly.Arduino['_74hoff'] = function(block) {
return  '_74HC595_7SegmentDisplay.TurnOffAllLed();\n';
}
//钢琴模块
Blockly.Arduino.kw_initPiano = function () {
	var value_clk = Blockly.Arduino.valueToCode(this, 'clk', Blockly.Arduino.ORDER_ATOMIC);
	var value_dio = Blockly.Arduino.valueToCode(this, 'dio', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_initir'] = '#include"BS818A.h"\nBS818A BS;\n';
	Blockly.Arduino.setups_['setup_initPiano'] = 'BS818A::InitBS818A(' + value_clk + ',' + value_dio + ');\n';
	var code = '';
	return code;
};

Blockly.Arduino.kw_piano = function () {
	var dropdown_piano = this.getFieldValue('piano');
	var code = 'BS.PressBsButton(' + dropdown_piano + ')';
	return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//旋转编码器
Blockly.Arduino.kw_digital = function () {
	var code = 'digitalRead(' + 'SWITCH_PIN' + ')' + '== LOW';
	return [code, Blockly.Arduino.ORDER_ATOMIC];
};
Blockly.Arduino.kw_print = function () {
	Blockly.Arduino.definitions_['define_encoder_pin2'] = 'long position, ' + 'oldposition;';
	Blockly.Arduino.definitions_['read_quadrature'] = 'void read_quadrature(){\n  if (digitalRead(ENCODER_A_PIN) == LOW){\n    if (digitalRead(ENCODER_B_PIN) == LOW)\n     position++;\n  }\n  else {\n    if (digitalRead(ENCODER_B_PIN) == LOW)\n     position--;\n  }\n oldposition = position;\n}';
	var oldposition = 'position';
	return [oldposition, Blockly.Arduino.ORDER_ATOMIC];
};


//初始化矩阵键盘
Blockly.Arduino.Initialize_matrix_keyboard = function () {
	var value_scl = Blockly.Arduino.valueToCode(this, 'scl_pin', Blockly.Arduino.ORDER_ATOMIC);
	var value_sdo = Blockly.Arduino.valueToCode(this, 'sdo_pin', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['define_matrix_keyboard'] = '#include <EM_TTP229.h>\nEM_TTP229 mTTP229;\nint SCLPin = '+value_scl+', SDOPin = '+value_sdo+';\nString Read_Key () {\n String key_name = mTTP229.GetKeyMap();\n char * result = (char *)key_name.c_str();\n return result;\n}';
	Blockly.Arduino.setups_['matrix_keyboard'] ='mTTP229.initTTP229(SCLPin, SDOPin);';
	var code = '';
    return code;
};
//矩阵键盘状态
Blockly.Arduino.Matrix_keyboard_status = function () {
	var value_key = this.getFieldValue('KEY');
	var value_status = this.getFieldValue('STATUS');
	var code = 'Read_Key()'+value_status+'="'+value_key+'"';
	return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//获取矩阵键盘按下的值
Blockly.Arduino.Matrix_keyboard_values = function () {
	var code = 'Read_Key()';
 return [code, Blockly.Arduino.ORDER_ATOMIC];
};





//初始化发送
Blockly.Arduino.nrf24l01send = function(){
    var value_address = Blockly.Arduino.valueToCode(this,'address',Blockly.Arduino.ORDER_ATOMIC);
       Blockly.Arduino.definitions_['md_nrf24l01'] = '#include<SPI.h>\n#include "RF24.h"\n'
       Blockly.Arduino.setups_['begin'] ='radio.begin();\n'
       Blockly.Arduino.setups_['Address'] = 'radio.openWritingPipe('+value_address+');\n'
    var code = '';
    return code;
   };
   //初始化接收
   Blockly.Arduino.nrf24l01rec = function(){
   
    var value_address2 = Blockly.Arduino.valueToCode(this,'address2',Blockly.Arduino.ORDER_ATOMIC);
       Blockly.Arduino.definitions_['md_nrf24l01'] = '#include<SPI.h>\n#include "RF24.h"\n'
       Blockly.Arduino.setups_['begin'] ='radio.begin();\n'
       Blockly.Arduino.setups_['Address2'] = 'radio.openReadingPipe(1,'+value_address2+');\n'
    var code = '';
    return code;
   };
   //功耗等级块
   Blockly.Arduino.power_consumption_level = function(){
      var level = this.getFieldValue('version');
      Blockly.Arduino.setups_['setPALevel'] = 'radio.setPALevel('+level+');\n';
      return '';
   }
   //初始化引脚块
   Blockly.Arduino.initialize_pins = function(){
      var ce = this.getFieldValue('CE');
      var cs = this.getFieldValue('CS');
      Blockly.Arduino.definitions_['initialize'] = 'RF24 radio('+ce+','+cs+');\n';
      return '';
   }
   //发送数据
   Blockly.Arduino.nrf24l01senddatass = function(){
      var value_senddatass = Blockly.Arduino.valueToCode(this,'nrfdatass',Blockly.Arduino.ORDER_ATOMIC);
      var value_genre = this.getFieldValue('GENRE');
      var code = 'radio.write(&'+value_senddatass+', sizeof('+value_senddatass+') );\n';
      return code;
  };
  //发送字符串数据
  Blockly.Arduino.nrf24l01senddatass_string = function(){
   var value_senddatass_string = Blockly.Arduino.valueToCode(this,'nrfdatass_string',Blockly.Arduino.ORDER_ATOMIC);
   var value_genre = this.getFieldValue('GENRE');
   //Blockly.Arduino.definitions_['md_string'] = 'char value[];'
   var code = 'char value[] = ' + value_senddatass_string + ';\nradio.write(value, sizeof(value) );\n';
   return code;
};
  //监听块
  Blockly.Arduino.eavesdrop = function(){
   var listen = this.getFieldValue('EAVESDROP');
   var code = 'radio.'+listen+'Listening();\n';
   return code;
}
//RF24是否有数据可读
Blockly.Arduino.nrfdataradys = function(){
   var code = 'radio.available()';
   return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//接收数据
Blockly.Arduino.nrfrecdatas = function(){
   var value_md_nrfdatasss = Blockly.Arduino.valueToCode(this,'nrfdatasss',Blockly.Arduino.ORDER_ATOMIC);
   var code = 'radio.read(&'+value_md_nrfdatasss+', sizeof('+value_md_nrfdatasss+') );\n';
return code;
};
//接收字符串数据
Blockly.Arduino.nrfrecdatas_string = function(){
   Blockly.Arduino.definitions_['receiving_string'] = 'char aary[100]={0};\nString receiving(){\nradio.read(aary, sizeof(aary) );\nString data = aary;\nreturn data;\n}';
   var code = 'receiving()';
return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//速率块
Blockly.Arduino.transmission_rate = function(){
   var speed = this.getFieldValue('Transmission_Rate');
   Blockly.Arduino.setups_['transmission_rate'] = 'radio.setDataRate('+speed+');\n';
   return '';
}
//通道速率块
Blockly.Arduino.channel_frequency = function(){
   var value_channel = Blockly.Arduino.valueToCode(this,'channel',Blockly.Arduino.ORDER_ATOMIC);
   Blockly.Arduino.setups_['channel_frequency'] = 'radio.setChannel('+value_channel+');\n';
   return '';
}
//初始化颜色传感器
Blockly.Arduino.colorview_init = function(){
	Blockly.Arduino.definitions_['EM_TCS34725'] = '#include <EM_TCS34725.h>\nEM_TCS34725 tcs34725;\n'
	Blockly.Arduino.setups_['tcs34725'] = 'tcs34725.begin();\n';
	return '';
}
//颜色传感器读值
Blockly.Arduino.colorview_value = function () {
	var Color = this.getFieldValue('color');
	var Gamma = this.getFieldValue('gamma');
	var code = 'tcs34725.' + Color + Gamma +'()';
	return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//初始化语音识别传感器
Blockly.Arduino.VoiceRecognition_init = function(){
	Blockly.Arduino.definitions_['VoiceRecognition'] = '#include <asr_ld3320.h>\n'
	Blockly.Arduino.setups_['VoiceRecognition_init'] = 'Wire.begin();\n';
	return '';
}
//语音识别模式设置
Blockly.Arduino.VoiceRecognition_Mode = function(){
	var mode = this.getFieldValue('MODE');
	Blockly.Arduino.setups_['VoiceRecognition_Mode'] = 'uint8_t asr_mode = '+mode+';\nld3320_config_mode(asr_mode);\n';
	return '';
 }
 //语音识别设置词条和编号
Blockly.Arduino.VoiceRecognition_Content = function () {
	var key = Blockly.Arduino.valueToCode(this, 'Key', Blockly.Arduino.ORDER_ATOMIC);
	var content = Blockly.Arduino.valueToCode(this, 'Content', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.setups_['VoiceRecognition_content'+ key] ='ld3320_add_words('+key+','+ content+');\ndelay(200);\n';
	var code = '';
    return code;
};
//语音识别开始识别
Blockly.Arduino.VoiceRecognition_Start = function(){
	Blockly.Arduino.setups_['VoiceRecognition_Start'] = 'ld3320_asr_start();\n';
	return '';
}
//语音识别进行复位
Blockly.Arduino.VoiceRecognition_Reset = function(){
	Blockly.Arduino.setups_['VoiceRecognition_Reset'] = 'ld3320_reset();\ndelay(200);\n';
	return '';
}
//语音识别获取识别到词条的对应编号
Blockly.Arduino.VoiceRecognition_Number = function(){
	var code = 'ld3320_get_result()';
	return [code, Blockly.Arduino.ORDER_ATOMIC];
}
//语音识别设置唤醒时间
Blockly.Arduino.VoiceRecognition_Time = function(){
	var time = Blockly.Arduino.valueToCode(this,'time',Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.setups_['SetTime'] = 'ld3320_config_time('+time+');\n';
	return '';
 }
//初始化MP3模块
Blockly.Arduino.MP3_MODE = function () {
	var tx_pin = Blockly.Arduino.valueToCode(this, 'tx_pin', Blockly.Arduino.ORDER_ATOMIC);
	var rx_pin = Blockly.Arduino.valueToCode(this, 'rx_pin', Blockly.Arduino.ORDER_ATOMIC);
	Blockly.Arduino.definitions_['MP3_MODE'] = '#include <EM_JQ8400.h>\nEM_JQ8400 JQ8400_Device('+rx_pin+','+tx_pin+');\n';
	Blockly.Arduino.setups_['MP3_MODE'] ='Serial.begin(9600);\n';
    return '';
};
//设置设置MP3模块音量
Blockly.Arduino.MP3_Volume = function(){
	var Volume = Blockly.Arduino.valueToCode(this,'Volume',Blockly.Arduino.ORDER_ATOMIC);
	var operation = this.getFieldValue('Operation');
	Blockly.Arduino.setups_['operation'] = 'JQ8400_Device.Command_Data('+operation+','+Volume+');\n';
	return '';
 }
 //MP3模块开始播放
Blockly.Arduino.MP3_Play = function(){
	var control = this.getFieldValue('Control');
	var code = 'JQ8400_Device.Command('+control+');\n';
	return code;
}
//OLED初始化
Blockly.Arduino.OLED_Model = function () {
	Blockly.Arduino.definitions_['OLED_MODE'] = '#include <OLED.h>\nOLED oled;\n';
	Blockly.Arduino.setups_['OLED_INIT'] ='oled.OLED_Init();\noled.OLED_ColorTurn(0);\noled.OLED_DisplayTurn(0);\n';
    return '';
};
//OLED实时刷新
Blockly.Arduino.OLED_Refresh = function () {
	var code ='oled.OLED_Refresh();\n';
    return code;
};
//OLED清屏
Blockly.Arduino.OLED_Clear = function () {
	var code ='oled.OLED_Clear();\n';
    return code;
};
//OLED显示字符串
Blockly.Arduino.OLED_Display_String = function () {
	var horizontal = Blockly.Arduino.valueToCode(this,'horizontal',Blockly.Arduino.ORDER_ATOMIC);
	var longitudinal = Blockly.Arduino.valueToCode(this,'longitudinal',Blockly.Arduino.ORDER_ATOMIC);
	var Content = Blockly.Arduino.valueToCode(this,'Content',Blockly.Arduino.ORDER_ATOMIC);
	var Size = this.getFieldValue('Size');
	var code ='oled.OLED_ShowString(' + horizontal +',' + longitudinal + ',' + Content + ',' + Size + ');\n';
    return code;
};
//OLED显示字符
Blockly.Arduino.OLED_Display_Char = function () {
	var horizontal = Blockly.Arduino.valueToCode(this,'horizontal',Blockly.Arduino.ORDER_ATOMIC);
	var longitudinal = Blockly.Arduino.valueToCode(this,'longitudinal',Blockly.Arduino.ORDER_ATOMIC);
	var Content = Blockly.Arduino.valueToCode(this,'Content',Blockly.Arduino.ORDER_ATOMIC);
	var Size = this.getFieldValue('Size');
	var code ='oled.OLED_ShowChar(' + horizontal +',' + longitudinal + ',' + Content + ',' + Size + ');\n';
    return code;
};
//OLED显示数字
Blockly.Arduino.OLED_Display_Num = function () {
	var horizontal = Blockly.Arduino.valueToCode(this,'horizontal',Blockly.Arduino.ORDER_ATOMIC);
	var longitudinal = Blockly.Arduino.valueToCode(this,'longitudinal',Blockly.Arduino.ORDER_ATOMIC);
	var digits = Blockly.Arduino.valueToCode(this,'Digits',Blockly.Arduino.ORDER_ATOMIC);
	var Content = Blockly.Arduino.valueToCode(this,'Content',Blockly.Arduino.ORDER_ATOMIC);
	var Size = this.getFieldValue('Size');
	var code ='oled.OLED_ShowNum(' + horizontal +',' + longitudinal + ',' + Content + ',' + digits + ','+ Size + ');\n';
    return code;
};
//OLED画线
Blockly.Arduino.OLED_Display_Line = function () {
	var start_horizontal = Blockly.Arduino.valueToCode(this,'Start_horizontal',Blockly.Arduino.ORDER_ATOMIC);
	var start_longitudinal = Blockly.Arduino.valueToCode(this,'Start_longitudinal',Blockly.Arduino.ORDER_ATOMIC);
	var ending_horizontal = Blockly.Arduino.valueToCode(this,'Ending_horizontal',Blockly.Arduino.ORDER_ATOMIC);
	var ending_longitudinal = Blockly.Arduino.valueToCode(this,'Ending_longitudinal',Blockly.Arduino.ORDER_ATOMIC);
	var code ='oled.OLED_DrawLine(' + start_horizontal +',' + start_longitudinal + ',' + ending_horizontal + ',' + ending_longitudinal + ');\n';
    return code;
};
//OLED画圆
Blockly.Arduino.OLED_Display_DrawCircle = function () {
	var horizontal = Blockly.Arduino.valueToCode(this,'horizontal',Blockly.Arduino.ORDER_ATOMIC);
	var longitudinal = Blockly.Arduino.valueToCode(this,'longitudinal',Blockly.Arduino.ORDER_ATOMIC);
	var radius = Blockly.Arduino.valueToCode(this,'Radius',Blockly.Arduino.ORDER_ATOMIC);
	var code ='oled.OLED_DrawCircle(' + horizontal +',' + longitudinal + ',' + radius + ');\n';
    return code;
};
//压力传感器
Blockly.Arduino.Pressure = function () {
	var pin = this.getFieldValue('Pin');
	Blockly.Arduino.definitions_['Pressure'] = 'int fsrPin = ' + pin + ';\n';
	var code = 'analogRead(fsrPin)';
	return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//水蒸气传感器
Blockly.Arduino.Water_Vapor = function () {
	var pin = this.getFieldValue('Pin');
	Blockly.Arduino.definitions_['Water_Vapor'] = 'int WaterVaporPin = ' + pin + ';\n';
	var code = 'analogRead(WaterVaporPin)';
	return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//手柄摇杆传感器
Blockly.Arduino.hand_jobone_header_x= function(){
	var deacting_one_x=this.getFieldValue('Decasx');
	var value_Speed_x = 'joystick.AnalogRead_X()';
  var value_Speed_y= 'joystick.AnalogRead_Y()';
  var code = '';
  if (deacting_one_x== 1) {
    code = value_Speed_x
  }else {
    code = value_Speed_y
  }
	return [code, Blockly.Arduino.ORDER_ATOMIC];
};
//手柄键盘传感器
Blockly.Arduino.hand_botton_fore= function(){
  var btn_four=this.getFieldValue('Btnfour');
  var btn_lasts=this.getFieldValue('Btnlast');
  var buttonjoge = 'joystick.Get_Button_Status('+btn_four+')';
  var code=buttonjoge+'=='+btn_lasts;
  return [code, Blockly.Arduino.ORDER_ATOMIC];
};
// 手柄初始化
Blockly.Arduino.hand_initalize_header=function(){
	Blockly.Arduino.definitions_['define_maker'] = '#include "JoystickHandle.h"\nJoystickHandle joystick(JOYSTICK_I2C_ADDR);\n';
	var code='';
	return code;
};
// 判断手柄按键按下/释放
Blockly.Arduino.hand_press_that=function(){
	var btn_pre=this.getFieldValue('Btnfour');
	var btn_prebt='PRESS_DOWN';
	var buttpress = 'joystick.Get_Button_Status('+btn_pre+')';
	var code=buttpress+'=='+btn_prebt;
	return [code, Blockly.Arduino.ORDER_ATOMIC];
};
Blockly.Arduino.hand_release_that=function(){
	var btn_rel=this.getFieldValue('Btnfour');
	var btn_relbt='NONE_PRESS';
	var buttrelease = 'joystick.Get_Button_Status('+btn_rel+')';
	var code=buttrelease+'=='+btn_relbt;
	return [code, Blockly.Arduino.ORDER_ATOMIC];
}

// 手柄左右摇杆
Blockly.Arduino.hand_LR_press= function(){
	var deacting_lr=this.getFieldValue('LRpre');
	var lr_press=this.getFieldValue('Jobone');
	var code = '';
	if(lr_press == 1){
		code='joystick.'+deacting_lr+'nalogRead_X()'
	}else{
		code='joystick.'+deacting_lr+'nalogRead_Y()'
	}
   	return [code, Blockly.Arduino.ORDER_ATOMIC];
};

// 指南针
Blockly.Arduino.compass_star=function(){
	var compass_xyz='int x_values,y_values,z_values,azimuth_values;\nint readCompass(){\n int x, y, z;\n int azimuth;\n qmc.read(&x, &y, &z,&azimuth);\n x_values = x;\n y_values = y;\n z_values = z;\n azimuth_values = azimuth;\n}\n';
	Blockly.Arduino.setups_['setup_compass_star'] ='\t'+'Wire.begin();\n'
	                                               +'\t'+'qmc.init();\n';
	Blockly.Arduino.definitions_['define_compass'] = '#include "MechaQMC5883.h"\nMechaQMC5883 qmc;\n'+compass_xyz;
    var code='readCompass();\n';
	return code;
}

Blockly.Arduino.compass_vue=function(){
	var compass_v=this.getFieldValue('capa');
    var code=compass_v+"_values";
	return [code, Blockly.Arduino.ORDER_ATOMIC];
	
}
// 陀螺仪
Blockly.Arduino.gyro_init=function(){
	Blockly.Arduino.definitions_['define_gyro'] = '#include "Mpu6050Module.h";\nMpu6050Module mpu6050;';
	Blockly.Arduino.setups_['setup_gyro'] = 'mpu6050.InitMpu6050();\n';
	var code='mpu6050.GetInclination();\n';
	return code;
}

Blockly.Arduino.gyro_getvalue=function(){
	var gyros = this.getFieldValue('gyrov');
	var code='mpu6050.'+gyros;
	return [code, Blockly.Arduino.ORDER_ATOMIC];
}

//rgb环灯
Blockly.Arduino.rgbLamp_init=function(){
	var lam = Blockly.Arduino.valueToCode(this,'rgb_init',Blockly.Arduino.RGBLAMP_ONES);
	Blockly.Arduino.definitions_['define_rgblamp'] = '#include "RGBLed.h"\n#define RgbPin '+lam+'\n';
	var code ='';
	return code;
}
Blockly.Arduino.rgbLamp_Bright=function(){
	var brg = Blockly.Arduino.valueToCode(this,'rgb_briga',Blockly.Arduino.RGBLAMP_BRIG);
	var code ='mRgb.setBrightness('+brg+');\n';
	return code
}
Blockly.Arduino.rgbLamp_num=function(){
	var rnuma = Blockly.Arduino.valueToCode(this,'rgb_numa',Blockly.Arduino.RGBNUMA);
	var rnumb = Blockly.Arduino.valueToCode(this,'rgb_numb',Blockly.Arduino.RGBNUMB);
	var rnumc = Blockly.Arduino.valueToCode(this,'rgb_numc',Blockly.Arduino.RGBNUMC);
	var rnumd = Blockly.Arduino.valueToCode(this,'rgb_numd',Blockly.Arduino.RGBNUMD);
	var rnume = Blockly.Arduino.valueToCode(this,'rgb_nume',Blockly.Arduino.RGBNUME);
	var rnumf = Blockly.Arduino.valueToCode(this,'rgb_numf',Blockly.Arduino.RGBNUMF);
	var rnumg = Blockly.Arduino.valueToCode(this,'rgb_numg',Blockly.Arduino.RGBNUMG);
	Blockly.Arduino.definitions_['define_rgblnum'] = 'RGBLed mRgb(RgbPin, '+rnuma+');\nint delayval = '+rnumd+';\n';
	var code ='for(int rgbdh='+rnumb+'-1;rgbdh<'+rnumc+';rgbdh++){\nmRgb.setColorAt(rgbdh,'+rnume+','+rnumf+','+rnumg+');\nmRgb.show();\ndelay(delayval);\n}';
	return code
}