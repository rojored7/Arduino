

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



float centi()
{

  int dato;
  float c;
  dato=analogRead(A0);
  
  c = (500.0 * dato)/1023;

 
  return (c);
}

float kelvin(float cent)
{
  float k;
  k=cent+273.15;
  return(k);
  
}

float fahren(float cent)
{
  float f;
  f=cent*1.8+32;
  return (f);
  

}

float rankin(float cent)
{
  float r;
  r=(cent + 273.15)*1.8;
  return (r);
}



void setup() {
  
lcd.begin(16,2);
lcd.print("C=      K=");
lcd.setCursor(0,1);
lcd.print("Temperatura");
}


void loop() {

  float Centigrados = centi();
  float Fahrenheit = fahren (Centigrados);
  float Rankin = rankin (Centigrados);
  float Kelvin = kelvin (Centigrados);
  
  lcd.setCursor(2,0);
  lcd.print(Centigrados);
  
  lcd.setCursor(10,0);
  lcd.print(Kelvin);
  
  
  delay(200);
  
  
}
