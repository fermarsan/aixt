import pwm
import time {sleep_ms}

  for (int i = 0; i < 3; i++) pin__setup(pwm_pin[i], PWM__OUT);


for {

  for (int i = 0; i < 3; i++) {
    if (m[i] == 0)  // Increasing
    {
      pwm__write(pwm_pin[i], d[i]++);
      if (d[i] == DUTY_MAX) m[i] = 1;
    } else  // Decreasing
    {
      pwm__write(pwm_pin[i], d[i]--);
      if (d[i] == DUTY_MIN) m[i] = 0;
    }
  }
time__sleep_ms(5);  
}