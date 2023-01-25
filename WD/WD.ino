#define GATE_PIN 10    // вывод на затвор транзистора
#define TIMER_TIMEOUT_MIN 5 // задержка на сброс в случае отключения
unsigned long tmr = millis();
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  Serial.setTimeout(20);  // таймаут на чтение из порта

}
 String str;
 
void loop() {
  str = Serial.readString();    //читает строку
  
  if (str == "RST") {        
    digitalWrite(GATE_PIN, 1);    // давит на сброс при нажатии на кнопку в приложении
  }
  if (str == "OK") {      // просто показывает работоспособность, дублирует функционал индикатора в программе. Можно убрать
    digitalWrite(13, 1);
    delay(10);
    digitalWrite(13, 0);
  }
  if (str == "OK") {
    tmr = millis();
  }
  if (millis() - tmr <= 1000 * 60 * TIMER_TIMEOUT_MIN) {
    tmr = millis();
    digitalWrite (GATE_PIN, 1);
    delay(50);
    digitalWrite (GATE_PIN, 0);
  }
}
