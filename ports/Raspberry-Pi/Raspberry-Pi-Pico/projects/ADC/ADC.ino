#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/pin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/adc.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"

int val;

void setup() {

pin_setup(gp13, out);
pin_setup(gp14, out);
pin_setup(gp15, out);
pin_setup(gp16, out);
 }

void loop() {

val=adc_read(gp27);
  
if (val>=0,val<255) {
pin_high(gp13);
pin_low(gp14);
pin_low(gp15);
pin_low(gp16);
}

if (val>=255,val<511) {
pin_low(gp13);
pin_high(gp14);
pin_low(gp15);
pin_low(gp16);
}

if (val>=511,val<767) {
pin_low(gp13);
pin_low(gp14);
pin_high(gp15);
pin_low(gp16);
}

if (val>=767,val<1023) {
pin_low(led1);
pin_low(led2);
pin_low(led3);
pin_high(led4);
}

}