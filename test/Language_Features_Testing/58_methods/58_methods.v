// import pin 

struct LED {
mut:
	state 		bool
	is_analog	bool
}

fn (mut led LED) off() {
	led.state = false
}

mut led_1 := LED {
	state: 		false
	is_analog: 	true
}

led_1.state = true 

state := led_1.state
led_1.off()