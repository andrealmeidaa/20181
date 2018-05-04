const int PINO_SENSOR=10;
const int PINO_D0 = 9;
const int PINO_A0 = A1;
const int LED_VERDE=11;
const int LED_VERMELHO=12;
 
void setup()
{
  Serial.begin(9600);
  //pinMode(PINO_A0, INPUT);
  pinMode(PINO_D0, INPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO,OUTPUT);
}
 
void loop()
{
  //int valorAferido = analogRead(PINO_A0);
  int valorSensor= digitalRead(PINO_D0);
  int movimento=digitalRead(PINO_SENSOR);
 
  //Serial.print("Porta analogica: ");
  //Serial.print(valorAferido);

 
  if (valorSensor != HIGH && movimento==HIGH)
  {
    Serial.println("Fogo detectado com perigo!!!");
    digitalWrite(LED_VERMELHO,HIGH);
    digitalWrite(LED_VERDE,LOW);
  }else{
    Serial.println("Sem fogo e/ou movimento");
    digitalWrite(LED_VERMELHO,LOW);
    digitalWrite(LED_VERDE,HIGH);
  }
  delay(500);
}
