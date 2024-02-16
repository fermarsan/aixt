inline void turn_around()
{
 on_rev(motor_c, 75) 
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
 Off(motor_ac)