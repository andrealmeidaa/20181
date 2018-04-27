
#include <LiquidCrystal.h>

#include <HCSR04.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
UltraSonicDistanceSensor sensor(12,11);

void setup() {

  lcd.begin(16, 2);
  lcd.print("Distancia");
  Serial.begin(9600);
}
void loop() {
  double distancia=sensor.measureDistanceCm();
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  Serial.println(distancia);
  delay(1000);
}

