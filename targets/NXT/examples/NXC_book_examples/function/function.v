import motor { Motor }
import time

mut left_m := Motor.new(motor.a)
mut right_m := Motor.new(motor.b)
mut both_m := Motor.new(motor.ab)

fn turn_around() {
	right_m.write(-75)
	time.sleep_ms(3400)
	both_m.write(75)
}	 

both.write(75)
time.sleep_ms(1)

turn_around()
time.sleep_ms(2)

turn_around()
time.sleep_ms(1)

turn_around()
both_m.off()