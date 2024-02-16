#define turn_around \
 on_rev(motor_b, 75)
 sleep(3400)
 forward(motor_ab, 75)

 forward(motor_ab, 75)
 sleep(1000)
 turn_around
 sleep(2000)
 turn_around
 sleep(1000)
 turn_around
 Off(motor_ab)
