fn turn_around(int pwr)
{
 reverse(motor_c, pwr)
  sleep(900)
 forward(motor_ac, pwr)
}

 forward(motor_ac, 75)
 sleep(1000)
 turn_around(75)
 sleep(2000)
 turn_around(75)
 sleep(1000)
 turn_around(75)
 off(motor_ac);
