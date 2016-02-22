#ifndef DHTAction_pin_h
#define DHTAction_pin_h

#include "Megas.h"
#include "DHT_Pin.h"


class DHTPin: public Pin {
  DHT dht;
  init(byte _pin, byte _mode, double _Threshold, byte _ThresholdMode);

  protected:
    double UpperThreshold;
    double LowerThreshold;
    byte   ActionPin;
    int    LowerAction;
    int    UpperAction;
    
}


double value;
  if (__pin->getMode() == MODE_DHT_TEMP){
     value = __dht->getTemperature();
  } else {
     value = __dht->getHumidity();
  }

  checkThreshold(value, Threshold, ThresholdMode)


  
#endif
