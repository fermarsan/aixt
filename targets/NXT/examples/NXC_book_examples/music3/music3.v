import sound
import motor_fn as motor
import time
import task

@[task]
fn music() {
	for {
		sound.play_tone(262, 400)
		time.sleep_ms(500)
		sound.play_tone(294, 400)
		time.sleep_ms(500)
		sound.play_tone(330, 400)
		time.sleep_ms(500)
		sound.play_tone(294, 400)
		time.sleep_ms(500)
	}
}

@[task]
fn movement() {
	for {
		motor.write(motor.ac, 75)
		time.sleep_ms(3000)
		motor.write(motor.ac, -75)
		time.sleep_ms(3000)
	}
}

@[task]
fn main() {
	task.priority(music, movement)
}