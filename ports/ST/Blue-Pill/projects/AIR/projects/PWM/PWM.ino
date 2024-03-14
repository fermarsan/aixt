// Project Name: Aixt project https://gitlab.com/fermarsan/aixt-project.git
// File Name: PWM.ino
// Author: Fernando Martínez Santa - Stiven Cortazar Cortazar - Yesid Reyes Tique
// Date: 2022-2024
// License: MIT
//
// // Description: PWM Ouput functions (Ai-Thinker_Ai-WB2-32S-Kit)
//              (PC port) 

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