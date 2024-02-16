set_sensor(in_1,sensor_touch)
 forward(motor_ac, 75)
 until (sensor_1 == 1)
 Off(motor_ac)