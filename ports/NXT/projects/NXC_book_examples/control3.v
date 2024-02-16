# define THRESHOLD 40

 set:sensor_light(in_3);
 forward(motor_ac, 75);
 while (true)
 {
 if (sensor(in_3) > THRESHOLD)
 {
 on_rev(motor_c, 75);
 sleep(100);
 until(sensor(in_3) <= THRESHOLD);
 forward(motor_ac, 75);
 } 
 }