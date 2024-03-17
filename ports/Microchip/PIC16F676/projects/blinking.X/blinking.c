
// Projects for pin the PIC16F676

#include "../../api_c/builtin.c"
#include "../../api_c/machine/pin.c"
#include "../../api_c/time/sleep_ms.c"
#include "../../api_c/time/sleep_us.c"

void main(void) {
    
    pin__setup(c1, out);

    pin_write(c1, 0);

    while (1) {

        pin_high(c1);
        sleep_ms(300);
        pin_low(c1);
        sleep_ms(300);
    
    }
}
