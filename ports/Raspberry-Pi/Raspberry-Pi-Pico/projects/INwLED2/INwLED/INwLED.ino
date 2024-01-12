#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/machine/pin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/time/sleep_ms.c"
boolean b0n;

void setup() {

pin_mode(led, out);
pin_mode(boton, in);
 }

void loop() {
  
if (pin_read(boton));
{
sleep_ms(50);
while(pin_read(boton));
sleep_ms(50);
b0n = ! b0n;

if(b0n)
pin_high(led);
else
pin_low(led);

}
}