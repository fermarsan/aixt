import sound

const time = 200
const maxvol = 7
const minvol = 1
const midvol = 3

@[inline]
fn pause_4th() {
	sleep_ms(time)
}

@[inline]
fn pause_8th() {
	sleep_ms(time / 2)
}

@[inline]
fn note_4th() {
	sound.play_file_ex('! Click.rso', midvol, false)
	pause_4th()
}

@[inline]
fn note_8th() {
	sound.play_file_ex('! Click.rso', maxvol, false)
	pause_8th()
}

sound.play_file_ex('! Startup.rso', minvol, false)
sleep_ms(2000)
note_4th()
note_8th()
note_8th()
note_4th()
note_4th()
pause_4th()
note_4th()
note_4th()
sleep_ms(100)
