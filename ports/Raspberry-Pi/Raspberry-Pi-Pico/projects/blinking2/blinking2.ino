#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/machine/pin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt-rp-2040\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/time/sleep_ms.c"

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pin_mode(led, out);
  
}

// the loop function runs over and over again forever
void loop() {
  
  pin_low(led);
  sleep_ms(2000);                      // wait for a second

  pin_high(led);
  sleep_ms(2000);                      // wait for a second
}