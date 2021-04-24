void setup(){
  pinMode(4, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  // 判断连接在D4号管脚的人体传感器是否感应到有人靠近，感应到则为1，否则为0.
  if (digitalRead(4) == 1) {
    // “高”表示点亮连接在D3号管脚绿灯，时间延续5s
    digitalWrite(3,HIGH);
    delay(5000);

  } else {
    // “低”表示熄灭连接在D3号管脚绿灯
    digitalWrite(3,LOW);

  }

}
