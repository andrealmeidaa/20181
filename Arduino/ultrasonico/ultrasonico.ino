
#include <HCSR04.h> //Importa a biblioteca para lidar com o sensor

const int PIN_TRIGGER=4; //Configuração dos pinos
const int PIN_ECHO=5;
const int LED_VERMELHO=11;
const int LED_AMARELO=10;
const int LED_VERDE=9;

UltraSonicDistanceSensor sensor(PIN_TRIGGER,PIN_ECHO); // Cria o sensor Ultrassônico

void setup() {
  pinMode(LED_VERMELHO,OUTPUT);
  pinMode(LED_AMARELO,OUTPUT);
  pinMode(LED_VERDE,OUTPUT);
  Serial.begin(9600);//Inicia o serial para escrever as distâncias medidas

}
void resetLeds(){//Desliga todos os LEDS
  
  digitalWrite(LED_VERMELHO,LOW);
  digitalWrite(LED_VERDE,LOW);
  digitalWrite(LED_AMARELO,LOW);
}
void loop() {

  double distancia=sensor.measureDistanceCm();//Realiza a medição da distância em Centímetros
  Serial.println(distancia);
  resetLeds();
  if (distancia!=-1.0){//Se a função retornar -1.0 significa que não existem objetos no alcance do sensor
     if (distancia<20.0){//Se menor do que 20, acede o vermelho
      digitalWrite(LED_VERMELHO,HIGH);
    }else if(distancia<50.0){//Menor do que 50 acende o amarelo
      digitalWrite(LED_AMARELO,HIGH);
    }else{//Acende o verde nas demais opções
      digitalWrite(LED_VERDE,HIGH);
    }
  }
 
  delay(1000);

}
