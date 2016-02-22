#ifndef Megas_h
#define Megas_h

#include <Arduino.h>  // for type definitions

//Global
 const static byte TOTAL_PINS             PROGMEM = 70;
 const static byte TOTAL_ANALOG_PINS      PROGMEM = 16;
 const static byte TOTAL_DIGITAL_PINS     PROGMEM = 54;

//ANALOG
 const static byte MODE_ANALOG_DISABLED   PROGMEM = 0;
 const static byte MODE_VOLTAGE    PROGMEM = 1;
 const static byte MODE_AMPERAGE   PROGMEM = 2;
 const static byte MODE_TEMPRETURE PROGMEM = 3;

 //DIGITAL
 const static byte MODE_DIGITAL_DISABLED PROGMEM = 50;
 const static byte MODE_BUTTON           PROGMEM = 51;
 const static byte MODE_PIR              PROGMEM = 52;
 const static byte MODE_RELAY            PROGMEM = 53;
 const static byte MODE_DHT_TEMP         PROGMEM = 54; 
 const static byte MODE_DHT_HUM          PROGMEM = 54; 
  const static byte MODE_DBS18           PROGMEM = 56; 
 const static byte MODE_1WIRE            PROGMEM = 57; 
 const static byte MODE_SERVO            PROGMEM = 70; 
 const static byte MODE_SERVO_COMPLEX    PROGMEM = 71; 

//ThresholdModes
 const static byte TMODE_EQUAL      PROGMEM = 0;
 const static byte TMODE_BELOW      PROGMEM = 1;
 const static byte TMODE_ABOVE      PROGMEM = 2;
 const static byte TMODE_EQBELOW    PROGMEM = 3;
 const static byte TMODE_EQABOVE    PROGMEM = 4;

 const static byte DISABLED_DIGITAL_PINS[] PROGMEM = {0,1,4,10,11,12,13,50,51,52,53};

boolean checkThreshold(double value, double  Threshold, byte ThresholdMode) {
  if ( ThresholdMode == TMODE_EQUAL && value == Threshold) {return true;}
  if ( ThresholdMode == TMODE_BELOW && value < Threshold) {return true;}
  if ( ThresholdMode == TMODE_ABOVE && value > Threshold) {return true;}
  if ( ThresholdMode == TMODE_EQBELOW && value <= Threshold) {return true;}
  if ( ThresholdMode == TMODE_EQABOVE && value >= Threshold) {return true;} 
  return false; 
  
}


#endif
