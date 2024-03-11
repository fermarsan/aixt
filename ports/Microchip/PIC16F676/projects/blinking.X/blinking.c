
// Projects for pin the PIC16F676

#include "../../api/builtin.c.v"
#include "../../api/pin/pin.c.v"
#include "../../api/pin/setup.c.v"
#include "../../api/pin/high.c.v"
#include "../../api/pin/low.c.v"
#include "../../api/pin/write.c.v"
#include "../../api/pin/read.c.v"
#include "../../api/time/sleep_ms.c.v"
#include "../../api/time/sleep_us.c.v"

void main(void) {
    
    pin__setup(c1, out);

    pin__write(c1, 0);

    while (1) {

        pin__high(c1);
        time__sleep_ms(300);
        pin__low(c1);
        time__sleep_ms(300);
    
    }
}
