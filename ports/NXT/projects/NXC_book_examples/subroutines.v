fn turn_around(int pwr)
{
 on_rev(motor_c, pwr)
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
 Off(motor_ac);
