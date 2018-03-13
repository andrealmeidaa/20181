const int LED_VERMELHO=12;
const int LED_VERDE=11;

void setup() {
  pinMode(LED_VERMELHO,OUTPUT);
  pinMode(LED_VERDE,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  
  if (Serial.available()){
    String texto=Serial.readString();
    Serial.println(texto);
    if(texto=="Vermelho ON"){
     digitalWrite(LED_VERMELHO,HIGH);
    }else if(texto=="Vermelho OFF"){
      digitalWrite(LED_VERMELHO,LOW);
    }else if (texto=="Verde ON"){
      digitalWrite(LED_VERDE,HIGH);
    }else if (texto=="Verde OFF"){
      digitalWrite(LED_VERDE,LOW);
    }
  }
 }

