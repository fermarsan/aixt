set_sensor_touch(in_1)
 forward(motor_ac, 75)
 while (true)
 {
 if (sensor_1 == 1)
 {
 on_rev(motor_ac, 75) sleep(300)
 forward(motor_a, 75) sleep(300)
 forward(motor_ac, 75)
 }
 }