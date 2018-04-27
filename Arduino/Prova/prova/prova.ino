
#include <HCSR04.h> //Importa a biblioteca para lidar com o sensor

const int PIN_TRIGGER=4; //Configuração dos pinos
const int PIN_ECHO=5;
const int LED_VERMELHO=12;
const int LED_VERDE=11;

UltraSonicDistanceSensor sensor(PIN_TRIGGER,PIN_ECHO); // Cria o sensor Ultrassônico

void setup() {
  pinMode(LED_VERMELHO,OUTPUT);
  pinMode(LED_VERDE,OUTPUT);
  Serial.begin(9600);//Inicia o serial para escrever as distâncias medidas

}
void resetLeds(){//Desliga todos os LEDS
  
  digitalWrite(LED_VERMELHO,LOW);
  digitalWrite(LED_VERDE,LOW);
}
void piscarLed(int led, int tempoEspera){
  for(int i=0;i<6;i++){
    digitalWrite(led,HIGH);
    delay(tempoEspera);
    digitalWrite(led,LOW);
  }
}
void loop() {

  double distancia=sensor.measureDistanceCm();//Realiza a medição da distância em Centímetros
  resetLeds();
  if (distancia!=-1.0){//Se a função retornar -1.0 significa que não existem objetos no alcance do sensor
     if (distancia<10.0){//Se menor do que 20, acede o vermelho
      piscarLed(LED_VERMELHO,10);
      Serial.write("PERIGO IMINENTE\n");
    }else if(distancia<25.0){//Menor do que 50 acende o amarelo
      piscarLed(LED_VERMELHO,60);
      Serial.write("PERIGO\n");
    }else if (distancia<40){
      piscarLed(LED_VERMELHO,120);
      Serial.write("ATENÇÃO!");
    }
    else{//Acende o verde nas demais opções
      piscarLed(LED_VERDE,200);
      Serial.write("TUDO LIMPO!\n");
    }
  }
  delay(1000);
}
