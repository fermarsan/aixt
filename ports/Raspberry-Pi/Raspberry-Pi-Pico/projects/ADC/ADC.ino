#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/bottom.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/blinking.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/adc.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\time/sleep_ms.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"

int val;

void setup() {

pin_setup(led1, out);
pin_setup(led2, out);
pin_setup(led3, out);
pin_setup(led4, out);
 }

void loop() {

val=adc_read(pot);
  
if (val>=0,val<255) {
pin_high(led1);
pin_low(led2);
pin_low(led3);
pin_low(led4);
}

if (val>=255,val<511) {
pin_low(led1);
pin_high(led2);
pin_low(led3);
pin_low(led4);
}

if (val>=511,val<767) {
pin_low(led1);
pin_low(led2);
pin_high(led3);
pin_low(led4);
}

if (val>=767,val<1023) {
pin_low(led1);
pin_low(led2);
pin_low(led3);
pin_high(led4);
}

}