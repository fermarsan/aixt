#define THRESHOLD 40
#define MIC SENSOR_2

set_sensor_sound(in_2)
 while(true){
 until(MIC > THRESHOLD)
 forward(motor_ac, 75)
 sleep(300)
 until(MIC > THRESHOLD)
 Off(motor_ac)
 sleep(300)
 }