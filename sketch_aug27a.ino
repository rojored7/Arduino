#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

#include "DHT.h" //cargamos la librería DHT

#define DHTPIN 2 //Seleccionamos el pin en el que se //conectará el sensor
#define DHTTYPE DHT11 //Se selecciona el DHT11 (hay //otros DHT)
DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que será usada por Arduino para comunicarse con el sensor



int ven1 = (7 );
int ven2 = (8);
int lum = (A0);



void setup() {
Serial.begin(9600); //Se inicia la comunicación serial 
dht.begin(); //Se inicia el sensor
pinMode(ven1, OUTPUT);
pinMode(ven2, OUTPUT);
//pinMode(lum, INPUT);
analogWrite(ven1, 0);
analogWrite(ven2, 0);

}



void loop() {
const int h = dht.readHumidity(); //Se lee la humedad
const int t = dht.readTemperature(); //Se lee la temperatura
//const int l = analogRead(lum);



Serial.println("Humedad: "); 
lcd.setCursor(12,0);
lcd.print("H:");
lcd.print(h);
Serial.println(h);



Serial.println("Temperatura: ");
lcd.setCursor(7,0);
lcd.print("T:");
lcd.print(t);
Serial.println(t);




            

delay(2000); //Se espera 2 segundos para seguir leyendo //datos


lcd.clear();



//analogWrite (l, map(lum, 0, 1023, 0, 5));

      

 
      
if (t < 50){

        digitalWrite(ven1, LOW);
        
        }
   else{}
   if(t >= 50){
        digitalWrite(ven1, HIGH);

   }
   else{}
   

int h1 = (h);
         
if (h1 < 70){

        digitalWrite(ven2, LOW);
        
        }
   else{}
   if(h1 >= 70){
        digitalWrite(ven2, HIGH);

   }
   else{}
   
}

