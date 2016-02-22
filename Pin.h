#ifndef Pin_h
#define Pin_h

#include <Arduino.h>  // for type definitions
#include "Megas.h"

class Pin {
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

void Pin::init(byte _pin, byte _mode){
  pin = _pin;
  mode = _mode;
}
// Getter function
boolean Pin::isAnalog(){
  if (mode<50) {
    return true;
  } else {
    return false;
  }
}

boolean Pin::isDigital(){
  if (this->isAnalog()) {
    return false;
  } else {
    return true;
  }
}

boolean Pin::isDisabled(){
  if ( mode == MODE_ANALOG_DISABLED || mode == MODE_DIGITAL_DISABLED ) {
    return true;
  } else {
    return false;
  }
}

byte Pin::getPin(){
  return pin;
}

byte Pin::getMode(){
  return mode;
}




#endif
