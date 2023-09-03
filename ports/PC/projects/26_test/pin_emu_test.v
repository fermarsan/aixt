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
    sleep_ms(1500)
    pin_high(A)
    pin_write(B, 1)
    sleep_us(1500000)
    pin_low(A)
    sleep(2)
    pin_write(B, 0)
}