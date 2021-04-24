String item;
volatile long time;

void setup(){
  Serial.begin(9600);
  item = "";
  time = 0;
  pinMode(3, OUTPUT);
}

void loop(){
  if (Serial.available() > 0) {
    item = Serial.readStringUntil('.');
    if (String(item).equals(String("OPEN"))) {
      Serial.println("OPEN");
      // 打开连接D3号管脚的绿灯
      digitalWrite(3,HIGH);

    } else if (String(item).equals(String("CLOSE"))) {
      Serial.println("CLOSE");
      // 关闭连接D3号管脚的绿灯
      digitalWrite(3,LOW);
    }

  }

}
