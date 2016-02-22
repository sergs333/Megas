#ifndef DHT_pin_h
#define DHT_pin_h

#include <EthernetClient.h>
#include <DHT.h>
#include "Megas.h"
#include "Pin.h"


class DHTPin: public Pin {
  DHT dht;
  void init(byte _pin, byte _mode);
  void print_values(EthernetClient cl);
  void work(EthernetClient cl);

  protected:
    double UpperThreshold;
    double LowerThreshold;
    byte   ActionPin;
    int    LowerAction;
    int    UpperAction;
    
};



void DHTPin::init(byte _pin, byte _mode) {
  Pin::init(_pin,_mode);
  dht.setup(pin);
}

void DHTPin::print_values(EthernetClient cl) {
  double H,T;
  H = dht.getHumidity();
  T = dht.getTemperature();
  cl.print(F("{"));
     cl.print(F("\"Type\":\"DHT\",")); 
     cl.print(F("\"Temperature\":\"")); cl.print(T); cl.print(F("\","));
     cl.print(F("\"Humidity\":\"")); cl.print(H); cl.print(F("\","));
  cl.print(F("}")); 
}

void DHTPin::work(EthernetClient cl){
  DHTPin::print_values(cl);
}


#endif
