#include <stdio.h>
#include <string.h>

#define output GPIO_ModeOut_PP_5mA

@[as_macro] pub const a11 = A, 11

@[inline]
pub fn high_(port, ...) {
	C."GPIO" #port "_SetBits(GPIO_Pin_" #__VA_ARGS__ ")\n"
}

@[inline]
pub fn high(id u8) {
	C.pin.high_(id u8)
}

//@[inline]
pub fn setup_(port, pin, ...) {
	C."GPIO" #port "_ModeCfg(GPIO_Pin_" #pin ", " #__VA_ARGS__ ")\n"
}
@[inline]
pub fn setup_(port, pin, ...) {
	C."PWMX_ACTOUT(CH_PWM" #port ", " #__VA_ARGS__ ")\n"
}

@[inline]
pub fn setup(id u8, mode u8) {
	C.pin.setup_(id u8, mode u8)
}


// @[inline]
pub fn high(a11) {
	C.GPIOA_SetBits(GPIO_Pin_11)
}
// @[inline]
pub fn low(a11) {
	C.GPIOA_ResetBits(GPIO_Pin_11)
}

int main()
{
    //printf(pin.setup(pin.a11, pin.output)put));
    printf(pin.setup(4, 10));
    printf(pin.high(pin.a11));
    return 0;
}

// #include "CH57x_common.h"

// int main(void) {

//     SetSysClock(CLK_SOURCE_PLL_60MHz);

//     GPIOA_ModeCfg(GPIO_Pin_11, GPIO_ModeOut_PP_5mA);
//     GPIO_ModeIN_PD
//     while(1){
//         GPIOA_SetBits(GPIO_Pin_11);
//         DelayMs(500);
//         GPIOA_ResetBits(GPIO_Pin_11);
//         DelayMs(500);
//         }
//         DelayMs(1);
//     }
// }
