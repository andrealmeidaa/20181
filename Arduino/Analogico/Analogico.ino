byte leds[]={12,11,10};
int tempoEntreAcendimentos;
void setup()
{
  for(int i=0;i<3;i++){
      pinMode(leds[i],OUTPUT);
  }
}
void loop()
{
  tempoEntreAcendimentos=analogRead(A1);
  alteraLEDS(LOW);
  delay(tempoEntreAcendimentos*2);
  alteraLEDS(HIGH);
  delay(tempoEntreAcendimentos*2);
  
}
void alteraLEDS(int estado){
  for(int i=0;i<3;i++){
      digitalWrite(leds[i],estado);
  }
}
