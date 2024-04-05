#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/pin.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/adc.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api\machine/pwm.c"
#include "C:\Users\Anderson\Desktop\RASPBERRY PI PICO\aixt_rppico\ports\Raspberry-Pi\Raspberry-Pi-Pico\api/builtin.c"


void setup() {
  
  Serial.begin(9600);



}

void loop() {
  
  if(Serial.available()){
    char a = Serial.read();
    Serial.println(a);

  }

}
