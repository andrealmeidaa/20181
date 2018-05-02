

const int LED_VERDE=11;
const int LED_VERMELHO=12;
const int SENSOR=10;

void setup() {
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO,OUTPUT);
  pinMode(SENSOR,INPUT);
  Serial.begin(9600);

}

void loop() {

 int movimento=digitalRead(SENSOR);

 if (movimento==HIGH){

  digitalWrite(LED_VERDE,LOW);
  digitalWrite(LED_VERMELHO,HIGH);
  Serial.println("Movimento");
  
 }else{
  digitalWrite(LED_VERDE,HIGH);
  digitalWrite(LED_VERMELHO,LOW);
  Serial.println("Sem detecção");
  
 }

 delay(1000);

}
