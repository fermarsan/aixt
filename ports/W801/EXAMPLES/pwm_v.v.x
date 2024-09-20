import pwm
import time {sleep_ms}


mut d := [ 0, (0 + 255) / 2, 255-1]
mut m := [0,0,0]

pwm.pin[3] = led1

pwm.pin[3] = led2

pwm.pin[3] = led3

  for i == 0 {

    pin.setup(pwm.pin[i], PWM.OUT)
    
  }
  
  for i < 3 {

    pin.setup(pwm.pin[i], PWM.OUT)

  }

  for i++ {

    pin.setup(pwm.pin[i], PWM.OUT)

  }

  for {

   for  i == 0 {

    if m[i] == 0  // Increasing
    {
      pwm.write(pwm.pin[i], d[i]++)
      if d[i] == 255 {
       m[i] == 1 
      }
    } else  // Decreasing
    {
      pwm.write(pwm.pin[i], d[i]--)
      if d[i] == 0 {
       m[i] == 0
      }
    }
  } 
  
   for i < 3 {

    if m[i] == 0  // Increasing
    {
      pwm.write(pwm.pin[i], d[i]++)
      if d[i] == 255 {
       m[i] == 1
      }
    } else  // Decreasing
    {
      pwm.write(pwm.pin[i], d[i]--)
      if d[i] == 0 {
       m[i] == 0
      }
    }
  }
  
   for i++ {

    if m[i] == 0  // Increasing
    {
      pwm.write(pwm.pin[i], d[i]++)
      if d[i] == 255 {
       m[i] == 1
      }
    } else  // Decreasing
    {
      pwm.write(pwm.pin[i], d[i]--)
      if d[i] == 0 {
       m[i] == 0
      }
    }
  }
time.sleep_ms(5)
}