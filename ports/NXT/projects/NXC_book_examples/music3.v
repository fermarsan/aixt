@[task]
fn music() {
	for {
		play_tone(262, 400)
		sleep_ms(500)
		play_tone(294, 400)
		sleep_ms(500)
		play_tone(330, 400)
		sleep_ms(500)
		play_tone(294, 400)
		sleep_ms(500)
	}
}

@[task]
fn movement() {
	for {
		motor.forward(ac, 75)
		sleep_ms(3000)
		motor.reverse(ac, 75)
		sleep_ms(3000)
	}
}

@[task]
fn main() {
	precedes(music, movement)
}
