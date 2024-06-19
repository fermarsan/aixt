import pwm
import time {sleep_ms}


int m[3] = { 0 }, d[3] = { DUTY.MIN, (DUTY.MIN + DUTY.MAX) / 2, DUTY.MAX - 1 };

int32_t pwm.pin[3] = { led1, led2, led3 };


  for (int i = 0; i < 3; i++) pin.setup(pwm.pin[i], PWM.OUT);


for {

  for (int i = 0; i < 3; i++) {
    if (m[i] == 0)  // Increasing
    {
      pwm.write(pwm.pin[i], d[i]++);
      if (d[i] == DUTY.MAX) m[i] = 1;
    } else  // Decreasing
    {
      pwm.write(pwm.pin[i], d[i]--);
      if (d[i] == DUTY.MIN) m[i] = 0;
    }
  }
time.sleep_ms(5);  
}