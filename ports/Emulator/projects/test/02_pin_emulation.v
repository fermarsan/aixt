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