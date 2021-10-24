#define LED_R 12
#define buzer 1
#define PIR 2
 
void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(buzer, OUTPUT);
  pinMode(PIR, INPUT);
  digitalWrite(LED_R, LOW);
}
 
void loop() {
  if (digitalRead(PIR) == HIGH) {
    digitalWrite(LED_R, HIGH);
    digitalWrite(buzer, HIGH);
    }  else {
    digitalWrite(LED_R, LOW); 
    digitalWrite(buzer, LOW);
    }
}
