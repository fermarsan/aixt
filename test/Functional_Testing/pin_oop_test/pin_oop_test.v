module main

import pin_oop

fn main() {
    led := pin_oop.new(13)

    led.setup(pin_oop.out)

    led.high()
    led.low()

    led.write(1)
    _ = led.read()
}
