// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin_emu_test.v
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Pin emulation testing.
import time
import machine { pin }

fn main() {
    pin_update()
    sleep_ms(2000)
    pin_high(a)
    pin_write(b, 1)
    sleep_us(2000000)
    pin_low(a)
    sleep(2)
    pin_write(b, 0)
}