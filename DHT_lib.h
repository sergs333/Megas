#include <EthernetClient.h>
#include <DHT.h>
#include "Megas.h"

void dht_init(DHT *__dht, byte pin) {
  __dht->setup(pin);
}


void dht_print_values(DHT *__dht, EthernetClient cl){
  double H,T;
  
  H = __dht->getHumidity();
  T = __dht->getTemperature();

  cl.print(F("{"));
     cl.print(F("\"Type\":\"DHT\",")); 
     cl.print(F("\"Temperature\":\"")); cl.print(T); cl.print(F("\","));
     cl.print(F("\"Humidity\":\"")); cl.print(H); cl.print(F("\","));
  cl.print(F("}")); 
}

void dht_works(DHT *__dht,EthernetClient cl, PinMode *__pin){
  double value;
  if (__pin->getMode() == MODE_DHT_TEMP){
     value = __dht->getTemperature();
  } else {
     value = __dht->getHumidity();
  }

  if (__pin->ThresholdMode == )
  
  
}



