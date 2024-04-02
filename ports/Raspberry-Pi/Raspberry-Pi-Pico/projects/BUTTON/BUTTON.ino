#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/pin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\time/sleep_ms.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"

boolean b0n;

void setup() {

pin_setup(led, out);
pin_setup(gp11, in);
 }

void loop() {
  
if (pin_read(gp11));
{
sleep_ms(50);
while(pin_read(gp11));
sleep_ms(50);
b0n = ! b0n;

if(b0n)
pin_high(led);
else
pin_low(led);

}
}