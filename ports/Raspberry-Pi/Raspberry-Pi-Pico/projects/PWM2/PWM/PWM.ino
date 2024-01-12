#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/machine/pin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/time/sleep_ms.c"


void setup() {

pin_mode(led5, out5);

 }

void loop() {

BRILLO = adc_read(POT1)/4;
adc_read(led5, BRILLO);

}