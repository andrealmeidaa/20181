const int LED_VERMELHO=12;
const int LED_VERDE=11;
void setup()
{
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE,OUTPUT);
  Serial.begin(9600);
  Serial.println("Inicializando o Arduino");
  
}

void loop()
{
  String comando;
  if (Serial.available()>0){
  	comando=Serial.readString();
    comando.trim();
    Serial.println(comando);
    if (comando.equals("Vermelho ON")){
    	digitalWrite(LED_VERMELHO,HIGH);
      Serial.println("Entrei");
    }else if (comando.equals("Vermelho OFF")){
    	digitalWrite(LED_VERMELHO,LOW);
    }else if (comando.equals("Verde ON")){
    	digitalWrite(LED_VERDE,HIGH);
    }else if(comando.equals("Verde OFF")){
    	digitalWrite(LED_VERDE,LOW);
    }
  }
}
