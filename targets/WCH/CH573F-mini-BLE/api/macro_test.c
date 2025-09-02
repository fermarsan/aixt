#include <stdio.h>
#include <string.h>

#define output GPIO_ModeOut_PP_5mA

@[as_macro] pub const a11 = A, 11

@[inline]
pub fn high_(port, ...) {
	C."GPIO" #port "_SetBits(GPIO_Pin_" #__VA_ARGS__ ")\n"
}

@[inline]
pub fn high(PIN_NAME) {
	C.pin.high_(PIN_NAME)
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
pub fn setup(PIN_NAME, PIN_MODE) {
	C.pin.setup_(PIN_NAME, PIN_MODE)
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
    //printf(pin.setup(pin.a11, pin.output));
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