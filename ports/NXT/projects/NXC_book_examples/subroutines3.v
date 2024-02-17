inline void turn_around

const (
pwr 
turntime
)

{
 reverse(motor_c, pwr)
 sleep(turntime)
 forward(motors_ac, pwr)
}


 forward(motors_ac, 75)
 sleep(1000)
 turn_around(75, 2000)
 sleep(2000)
 turn_around(75, 500)
 sleep(1000)
 turn_around(75, 3000)
 off(motors_ac)
