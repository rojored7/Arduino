#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float UP=0, DOWN=0, FIN=0, CONT=0,  TIM1=0,  TIM2=0, TIM3=0;
float RA=3.9 , pi=3.1416, me=0, km=0, velocidad=0, TT=0; 
float PE=2*pi*(RA);  
int motor = (6);
int cont = (7);
double panel = (A0);
double adc = 0;
double analog=0;
int vuel=0 ;
int ciclos=0;
int sali=0;

void setup() {
  Serial.begin(9600);
  pinMode(cont, INPUT);
  pinMode(panel, INPUT);
  pinMode(motor, OUTPUT);

}

void loop() {

  analogWrite(motor,0);
  vuel = digitalRead(cont);
  analog = analogRead(panel);
  adc=((5.0/1023.0)*analog);

 
  if(vuel==1 & adc >=3.0)
  {
  VELOCIDAD();  
  digitalWrite(motor,HIGH);
  ciclos++;
  }
  if(ciclos==20)
  {
  sali++;
  ciclos=0;
  }
  delay(14);
double m=0;
m=(PE*sali);
Serial.println (m);
lcd.print (m);
lcd.clear();
  //Serial.println(motor);
  //Serial.println(sali);
  Serial.println(adc);
  //Serial.println("ciclos");
  //Serial.print(ciclos);
  MOSTRAR();
}


void VELOCIDAD(){
        if (cont%2 == 0 ) {
              TIM1=millis();
        }
        else {
              TIM2=millis();
        }
        TIM3=(abs(TIM2-TIM1)); 
        TT=(TT+TIM3)/1000;
        velocidad=(60*sali/TT);
        Serial.print("TT: ");
        Serial.print(TT);
        Serial.print("V= ");
        Serial.println(velocidad);

        
      
}

void MOSTRAR()
{
  lcd.print("T");
  lcd.print(TT);
  lcd.print("D");
  lcd.print(km);
  lcd.print("RPM");
  lcd.print(velocidad);  
}

