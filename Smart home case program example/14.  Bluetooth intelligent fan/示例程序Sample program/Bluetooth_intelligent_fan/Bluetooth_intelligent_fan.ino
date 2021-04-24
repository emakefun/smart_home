String item;
volatile long time;

void setup(){
  Serial.begin(9600);
  item = "";
  time = 0;
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){
  if (Serial.available() > 0) {
    item = Serial.readStringUntil('.');
    if (String(item).equals(String("OPEN"))) {
      Serial.println("OPEN");
      digitalWrite(3,HIGH);

    } else if (String(item).equals(String("CLOSE"))) {
      Serial.println("CLOSE");
      digitalWrite(3,LOW);
    }
    if (String(item).equals(String("OPEN Fan"))) {
      Serial.println("OPEN Fan");
      // 打开风扇
      digitalWrite(5,HIGH);
      digitalWrite(6,LOW);

    } else if (String(item).equals(String("CLOSE Fan"))) {
      Serial.println("CLOSE Fan");
      // 关闭风扇
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
    }

  }

}
