#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

int pin=6;
IRrecv odbiornik(pin); 
decode_results KodKlawisza;

void setup() {
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
Serial.begin(9600);
odbiornik.enableIRIn(); //ur. odb.
}

void loop() {
 
double long KodCzerwony,KodZielony, KodNiebieski;

if (odbiornik.decode(&KodKlawisza)==1){//sprawdza czy jest sg.
Serial.println(KodKlawisza.value,HEX);
Serial.println("");
odbiornik.resume();
delay(200);

 if((KodKlawisza.value==0xEE886D7F)|(KodKlawisza.value==0xFFE21D)){
Serial.println("KodCzerwony");
digitalWrite(9, HIGH);
delay(1000);
digitalWrite(9, LOW);
}

  if((KodKlawisza.value==0x20FE4DBB)|(KodKlawisza.value==0xFFC23D)|(KodKlawisza.value==0x7C205335)){
Serial.println("KodZielony");
digitalWrite(8, HIGH);
delay(1000);
digitalWrite(8, LOW);
}

/* if((KodKlawisza.value==0x)|(KodKlawisza.value==0x)|(KodKlawisza.value==0x)){
Serial.println("KodNiebieski");
digitalWrite(7, HIGH);
delay(1000);
digitalWrite(7, LOW);
  }
  */
}
}
