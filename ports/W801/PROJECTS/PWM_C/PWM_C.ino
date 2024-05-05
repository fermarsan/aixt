
#include <Arduino.h>

#define DUTY_MAX 240
#define DUTY_MIN 50

// Note: on W801 board only two LEDs are connetcted to PWM pins, so PB5 led won't lit

int m[3] = { 0 }, d[3] = { DUTY_MIN, (DUTY_MIN + DUTY_MAX) / 2, DUTY_MAX - 1 };

int pwm_pin[3] = { LED_BUILTIN_1, LED_BUILTIN_2, LED_BUILTIN_3 };

void setup() {
  for (int i = 0; i < 3; i++) pinMode(pwm_pin[i], PWM_OUT);
}

void loop() {

  for (int i = 0; i < 3; i++) {
    if (m[i] == 0)  // Increasing
    {
      analogWrite(pwm_pin[i], d[i]++);
      if (d[i] == DUTY_MAX) m[i] = 1;
    } else  // Decreasing
    {
      analogWrite(pwm_pin[i], d[i]--);
      if (d[i] == DUTY_MIN) m[i] = 0;
    }
  }
delay(5);  
}
