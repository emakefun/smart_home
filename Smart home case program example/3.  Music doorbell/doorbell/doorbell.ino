void setup(){
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
  // 判断连接在D2号接口的触摸传感器是否被触摸；1表示有触摸，0表示没有被触摸
  if (digitalRead(2) == 1) {
    tone(3,131);
    delay(600);
    tone(3,587);
    delay(500);
    tone(3,587);
    delay(500);
    tone(3,659);
    delay(500);
    tone(3,784);
    delay(500);
    tone(3,880);
    delay(500);
    tone(3,880);
    delay(500);
    tone(3,988);
    delay(500);
    tone(3,988);
    delay(500);
    tone(3,659);
    delay(500);

  } else {
    noTone(3);

  }

}
