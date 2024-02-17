inline void turn_around()
{
 reverse(motor_c, 75) 
 sleep(900)
 forward(motor_ac, 75)
}

 forward(motor_ac, 75)
 sleep(1000)
 turn_around()
 sleep(2000)
 turn_around()
 sleep(1000)
 turn_around()
 off(motor_ac)