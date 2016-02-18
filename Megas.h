#include <EEPROM.h>
#include <Arduino.h>  // for type definitions

#ifndef Megas_h
#define Megas_h

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
 const static byte MODE_BUTTON          PROGMEM = 51;
 const static byte MODE_PIR             PROGMEM = 52;
 const static byte MODE_RELAY           PROGMEM = 53;
 const static byte MODE_DHT22           PROGMEM = 54; 
 const static byte MODE_DHT11           PROGMEM = 55; 
 const static byte MODE_DBS18           PROGMEM = 56; 
 const static byte MODE_1WIRE           PROGMEM = 57; 
 const static byte MODE_SERVO           PROGMEM = 70; 
 const static byte MODE_SERVO_COMPLEX   PROGMEM = 71; 



template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}

const static byte DISABLED_DIGITAL_PINS[] PROGMEM = {0,1,4,10,11,12,13,50,51,52,53};

class PinMode {
public:
   void init(byte _pin, byte _mode);
   boolean isAnalog();
   boolean isDigital();
   boolean isDisabled();
   byte getPin();
   byte getMode();
protected:
   byte pin;
   byte mode;

};

void PinMode::init(byte _pin, byte _mode){
  pin = _pin;
  mode = _mode;
}
// Getter function
boolean PinMode::isAnalog(){
  if (mode<50) {
    return true;
  } else {
    return false;
  }
}

boolean PinMode::isDigital(){
  if (this->isAnalog()) {
    return false;
  } else {
    return true;
  }
}

boolean PinMode::isDisabled(){
  if ( mode == MODE_ANALOG_DISABLED || mode == MODE_DIGITAL_DISABLED ) {
    return true;
  } else {
    return false;
  }
}

byte PinMode::getPin(){
  return pin;
}

byte PinMode::getMode(){
  return mode;
}

#endif
