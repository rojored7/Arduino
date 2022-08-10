#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

float hall = (A0);
float v;
float d;
float t;
float k;
float h;
float c;
float p;
float pi = 3.1416;

  
void setup() {
Serial.begin(9600); 
}

void loop() {
  distancia();
  vueltas();
  Serial.println("V: ");
  Serial.println(v);
  Serial.println("D: ");
  Serial.println(d);
  Serial.println("T: ");
  Serial.println(t);
  Serial.println("#V: ");
  Serial.println(k);
  
  lcd.setCursor(0,0);
  lcd.print("D: ");
  lcd.print(d);

  lcd.setCursor(0,5);
  lcd.print("#V: ");
  lcd.print(k);  
  
  delay(1000);
}

int perimetro(void)
{
  float r=0.3;
  p=(2*pi*r);
  return p;
}

int distancia(void)
{
  d=p*k;
  return d;
}

int vueltas(void)
{    
  if (!hall==1)   
      k=k+1;    
  else  
      k=k; 
  return k;
}
millis();
