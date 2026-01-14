import time
import pin

enum colors {
    BLACK = 0
    BLUE = 0b1
    GREEN = 0b10
    RED = 0b100
    WHITE = 0b111
    COLOR_MASK = 0b111
}

fn main() int {

    pin.setup(led_b, out)
    pin.setup(led_g, out)
    pin.setup(led_r, out)
    // printf("[init] goio set mode complete.\r\n")



    led_state := u8(BLACK)

    // printf("[main] start loop\r\n")
    for {
        led_state = (led_state + 1) & COLOR_MASK
        // printf("increase 1 so led_state is %x\r\n", led_state);
        // printf("rgb(%u,%u,%u)\r\n", !!(led_state & RED), !!(led_state & GREEN), !!(led_state & BLUE));

        pin.write(led_b, !(led_state & BLUE))
        pin.write(led_g, !(led_state & GREEN))
        pin.write(led_r, !(led_state & RED))
        sleep_ms(200)
    }
}
