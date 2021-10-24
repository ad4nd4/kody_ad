#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#define irPin 11

IRrecv irrecv(irPin);
decode_results results;
 
#define diodaPin 3
int jasnosc = 0;
 
void setup() {
   Serial.begin(9600);
   irrecv.enableIRIn();
 
    pinMode(diodaPin, OUTPUT);
}
 
void loop() {
   if (irrecv.decode(&results)) {
 
       switch (results.value) {
         case 0xE0984BB6:
            if(jasnosc < 255) {jasnosc = jasnosc+5;}
            Serial.println(jasnosc);
            analogWrite(diodaPin, jasnosc);
            break;
 
         case 0x371A3C86:
            if(jasnosc > 0) {jasnosc = jasnosc-5;}
            Serial.println(jasnosc);
            analogWrite(diodaPin, jasnosc);
            break;
         }
   irrecv.resume();
   }
}
