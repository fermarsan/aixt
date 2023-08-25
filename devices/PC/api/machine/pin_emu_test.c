// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: pin_emu_test.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: Pin emulation testing.
#include <unistd.h>
#include "machine__pin_emu.c"

int main() {
    pin_update();
    usleep(1500000);
    pin_high(A);
    pin_write(B, 1);
    usleep(1500000);
    pin_low(A);
    usleep(1500000);
    pin_write(B, 0);
    printf("z = %i\n", pin_read(z));
    return 0;
}