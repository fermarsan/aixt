#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/machine/pin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/time/sleep_ms.c"

int BRILLO;

void setup() {

pin_mode(led5, out);

 }

void loop() {

BRILLO = adc_read(POT1)/4;
adc_write(led5, BRILLO);

}