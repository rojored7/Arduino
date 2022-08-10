#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

float vol = (A0);
int h = 0;


void setup() {
  Serial.begin(9600);
  analogRead(A0);
  pinMode(vol, INPUT);

}

void loop() {

  Serial.println("altura: ");
  Serial.println(h);
  delay(1000);
  lcd.print("Altura: ");
  lcd.print(h);
  
  

  if(vol)
  {
  if( 0 < vol < 1)
  {
    h=0;
    delay(1000);
    //vol=0;
  }
  if(1 <= vol < 2);
  {
    h=2;
    delay(1000);
    //vol=0; 
  }
  if(2 <= vol < 3);
  {
    h=4;
    delay(1000);
    //vol=0;
  }
  if(3 <= vol < 4);
  {
    h=6;
    delay(1000);
    //vol=0;
  }
  }
  else
  {
    h=0;
    delay(1000);
  }
  vol=0;
}
