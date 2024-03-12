import sound

@[task]
fn music() {
	for {
		sound.play_tone(262, 400)
		sleep_ms(500)
		sound.play_tone(294, 400)
		sleep_ms(500)
		sound.play_tone(330, 400)
		sleep_ms(500)
		sound.play_tone(294, 400)
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
