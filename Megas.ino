
/* EEPROM settings save
 * Mapping:
 * Mapping version - 1 byte
 * {Mode[1],Multiplier[2], UpperLimit[2] LowerLimit[2] UpperAction/LowerAction[51]
 * A00          0                   
 * ..
 * A15          15
 * D01
 * ..
 * D54
 *
 */

#include <EEPROM.h>
#include <DHT.h>
#include "megas.h"

const static char SOFT_REVISION[] PROGMEM = "MEGADS:01";
struct pin_t { byte mode; //short multiplier; short UpperLimit; short LowerLimit; //char Action[51];
} pin;

char EEPROM_revision[9];

void readEEPROM() {
  // put your setup code here, to run once:
  int n = 0;
  int i = 0;
  n = EEPROM_readAnything(0, EEPROM_revision);
  if (EEPROM_revision == SOFT_REVISION) {
    for (i=0; i<TOTAL_PINS; i++){
      n = EEPROM_readAnything( sizeof(SOFT_REVISION)+i*sizeof(pin), pin);      
    }
  } else {
    n = EEPROM_writeAnything(0,SOFT_REVISION); 
  }
  

}

const int MAXIMUM_AVAILABLE_PINS PROGMEM = 50;
PinMode pins[MAXIMUM_AVAILABLE_PINS]; // An array of MyClass objects using default constructor

void init_pins(){
  //init Analog
  byte i = 0;
  for (byte z = 0; z < TOTAL_ANALOG_PINS; z++) {
       pins[z].init(z,MODE_ANALOG_DISABLED);
       i++;
   }
  //init Digital
  for (byte z = 0; z < TOTAL_DIGITAL_PINS; z++) {
       // exclude disabled pins
       if ( z !=0 && z!=1 && z!=4 && z!=10 && z!=11 && z!=12 && z!=13 && z!=50 && z!=51 && z!=52 && z!=53){
         pins[i].init(z,MODE_DIGITAL_DISABLED);
         i++;
       }
   }
    
}

//
// Initialize the objects in setup()
//
void setup()
{ 
   Serial.begin(9600);
   init_pins();
   dht.setup(2);
   dht2.setup(3);
}

//
// Use the objects in loop()
//
void loop()
{
   for (int i = 0; i < MAXIMUM_AVAILABLE_PINS; i++) {
       Serial.print("pin[");
       Serial.print(pins[i].getPin()); 
       Serial.print("] isAnalog = [");
       Serial.println(pins[i].isAnalog());
       Serial.print("] mode = ");
       Serial.println(pins[i].getMode());
   }
   Serial.println();
   
  delay(dht.getMinimumSamplingPeriod());

  Serial.print(dht.getHumidity());
  Serial.print(dht.getTemperature());
  
   
   delay(10000);
   

}



