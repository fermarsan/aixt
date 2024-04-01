//#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/pin.c"
//#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\time/sleep.c"
//#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"

import time {sleep}
import pin

void setup() {

  pin_setup(led, out);

}

void loop() {
  
  pin_low(led);
  sleep(2);                  

  pin_high(led);
  sleep(2);             
}