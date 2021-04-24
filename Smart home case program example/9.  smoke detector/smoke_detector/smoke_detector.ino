volatile int qiti;
volatile int huoyan;

void setup(){
  Serial.begin(9600);
  qiti = 0;
  huoyan = 0;
  pinMode(8, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  // 把连接在A0接口的气体传感器的模拟值赋给qiti变量
  qiti = analogRead(A0);
  // 把连接在D8号接口的火焰传感器的值赋给huoyan变量
  huoyan = digitalRead(8);
  Serial.print(String("qiti:") + String(qiti));
  Serial.print(",");
  Serial.println(String("huoyan:") + String(huoyan));
  delay(200);
  // 判断气体模拟值是否大于100或者火焰传感器器是否感应到火焰
  if (qiti > 100 || huoyan == 0) {
    // 打开风扇
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    // 蜂鸣器报警
    tone(3,131);
    delay(1000);
    tone(3,220);
    delay(1000);

  } else {
    // 关闭风扇和蜂鸣器
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    noTone(3);

  }

}
