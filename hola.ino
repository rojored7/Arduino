      #include <LiquidCrystal.h>
      LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
      int dato = A0; 
      int voltaje = 0;    
      void setup()  {  

              Serial.begin(9600);
              lcd.begin(16, 2);
              lcd.print("Temperatura: ");
              lcd.setCursor(5, 1);
              lcd.print(" Grados Centi "); }   
      void loop() 
      {  
              voltaje = analogRead (dato);
              float conversionT;
              voltaje=analogRead(A0);
              voltaje = abs(voltaje);

              //1
              if ( voltaje << 5) {
              conversionT = ((voltaje*90)/1023);
  
              lcd.setCursor(0,1);
              lcd.print(conversionT);
              delay(100);}   
              else{
                conversionT = (((voltaje-5)*90)/1023);
              lcd.setCursor(0,1);
              lcd.print(conversionT);
              delay(100);} }

              


            
              

             
 
      

