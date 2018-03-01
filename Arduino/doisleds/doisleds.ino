const int PIN_LED_01=12;
const int PIN_LED_02=11;
void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED_01,OUTPUT);
  pinMode(PIN_LED_02,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(PIN_LED_01,HIGH);
  digitalWrite(PIN_LED_02,LOW);
  delay(1000);
  digitalWrite(PIN_LED_01,LOW);
  digitalWrite(PIN_LED_02,HIGH);
  delay(1000);

}
