#include <Bounce2.h> 

void pirobutton_init(Bounce* __pir, byte pin) {
  pinMode(pin ,INPUT);
  // Activate internal pull-up (optional) 
  digitalWrite(pin ,HIGH);
  __pir->attach(pin);
  __pir->interval(5);
}

void pirobutton_print(PinMode* __pin, EthernetClient cl, Bounce* __pir){


}

boolean pirobutton_work(PinMode* __pin, Bounce* __pir){
   
   if (__pir->update() == 1) { // PIR/BUTTON state changed
      

   }

}
