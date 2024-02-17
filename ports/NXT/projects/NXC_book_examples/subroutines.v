fn turn_around(int pwr)
{
 reverse(motor_c, pwr)
  sleep(900)
 forward(motors_ac, pwr)
}

 forward(motors_ac, 75)
 sleep(1000)
 turn_around(75)
 sleep(2000)
 turn_around(75)
 sleep(1000)
 turn_around(75)
 off(motors_ac);
