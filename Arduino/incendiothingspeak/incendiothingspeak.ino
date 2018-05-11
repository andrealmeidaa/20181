

#include <SoftwareSerial.h>

const int PINO_D0=7;
const int TX=9;
const int RX=10;
const String API_KEY="xxxxxxx";
const String HOST="api.thingspeak.com";
const int PORT=80;
int countTimeCommand;
boolean found=false;
SoftwareSerial esp8266(TX,RX);
void setup() {
 pinMode(PIN_A0,INPUT);
 pinMode(PINO_D0,INPUT);
 Serial.begin(9600);
 esp8266.begin(115200);
 delay(2000);
 esp8266.println("AT");
 delay(4000);
 esp8266.println("AT+CMODE=1");
 delay(4000);
 esp8266.println("AT+CWJAP=\"wIFRN-IoT\",\"Ifrn@IoT!N0CFrZ\"");
 delay(4000);
}

void loop() {
 int distanciaChama=analogRead(PIN_A0);
 int alteracao=digitalRead(PINO_D0);
 int chama;
 if(alteracao!=HIGH){
    chama=1;
 }else{
    chama=0;
 }
 String comando="GET /update?api_key="+API_KEY+"&field1="+String(distanciaChama)+"&field2="+String(chama);
 esp8266.println("AT+CIPSTART=\"TCP\",\""+HOST+"\",80");
 delay(2000);
 esp8266.println("AT+CIPSEND="+String(comando.length()+4));
 delay(2000);
 esp8266.println(comando);
 Serial.println(comando);
 delay(3500);
 esp8266.println("AT+CIPCLOSE");
 Serial.println(comando);
 delay(10000);
}


