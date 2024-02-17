#define turn_right(s,t) forward(motor_a, s); reverse(motor_b, s); sleep(t);

#define turn_left(s,t) reverse(motor_a, s); forward(motor_b, s); sleep(t);

#define forwards(s,t) forward(motors_ab, s); sleep(t);

#define backwards(s,t) reverse(motor_ab, s); sleep(t);


 backwards(50,10000)
 forwards(50,10000)
 turn_left(75,750)
 forwards(75,1000)
 backwards(75,2000)
 forwards(75,1000)
 turn_right(75,750)
 forwards(30,2000)
 off(motor_ab)
