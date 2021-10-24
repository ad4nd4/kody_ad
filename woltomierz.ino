
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//#define VREF 1100 // mV - napięcie referencyjne komparatora, wewn napiecie odniesienia
#define VREF 4960 //mV - nap ref, odniesienie do USB, usb daje niecale 5V

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int prev_value = 0;

void setup()
{
   //inicjalizacja portu szeregowego
   Serial.begin(9600);

   //inicjalizacja lcd przez i2c
   lcd.begin(16, 2); 
   lcd.backlight();
   delay(250);
   lcd.noBacklight();
   delay(250);
   lcd.backlight();
   
   lcd.setCursor (0,0);
   lcd.print("Woltomierz");
   lcd.setCursor (0,1);
   lcd.print("wiatrakowy");
   delay(2000);
   int i = 0;
   while (i<10){
      delay(500);
      lcd.setCursor (i,1);
      lcd.print("*");
      i++;
   }

   //ustawienie komparatora napiecia na wewnetrzne napiecie atmegi - zakomentowac jesli do USB
   //analogReference(INTERNAL);

   //a0 na wejscie
   pinMode(A0, INPUT);
}

void loop() 
{
   int analog_value = analogRead(A0);
   float voltage = VREF* float(analog_value) / 1023.0; 

   /*if (voltage < 0.1) 
   {
     voltage
     
     
     =0.0;
   } */
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("V = ");
    if (prev_value == (int)voltage)
    {
        lcd.noBacklight();
    }
    else if (voltage<4096){
      lcd.backlight();       
      lcd.print(voltage);
      lcd.setCursor(14,0);
      lcd.print("mV");
    }
    else {
      lcd.backlight();
      lcd.print("Poza skalą");      
    }

    prev_value = int(voltage);
    
    delay(1000);
}
