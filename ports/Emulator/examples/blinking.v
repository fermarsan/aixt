for {   //blinking the emulated pin x
    pin_high(x)
    sleep_ms(500)
    pin_low(x)
    sleep_ms(500)
}