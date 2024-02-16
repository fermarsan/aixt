#define NEAR 15
set_sensor_lowspeed(in_4)
while(true){
	forward(motor_ac,50)
	while(sensor_us(in_4)>NEAR)
	Off(motor_ac)
	on_rev(motor_c,100)
	sleep(800)
}