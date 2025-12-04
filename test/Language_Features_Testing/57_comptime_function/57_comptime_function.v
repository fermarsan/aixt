import uart

@[if flag_1 ?]
fn msg1() {
	uart.println('Message 1')
}

@[if flag_2 ?]
fn msg2() {
	uart.println('Message 2')
}

fn main() {
	msg1()
	msg2()
}