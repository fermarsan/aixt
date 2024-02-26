/*        
      TARJETA DE PROGRAMACIÓN Ai-WB2-32S-Kit

                  DESCRIPCIÓN:

 	PWM_Output                                

*/

#include "bl602_pwm.h"

void setup() {
 pinMode(17, OUTPUT);
}
void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(17, i);
    delay(10);
  }
  delay(1000);

  for (int i = 255; i >= 0; i--) {
    analogWrite(17, i);
    delay(10);
  }
  delay(1000);
}