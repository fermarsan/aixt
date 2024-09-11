#include <stdio.h>
#include <string.h>

#define output GPIO_ModeOut_PP_5mA

#define a11 A, 11

@[inline]
pub fn pwm.high_(port, ...) {
	C."GPIO" #port "_SetBits(GPIO_Pin_" #__VA_ARGS__ ")\n"
}

@[inline]
pub fn pin.high(PIN_NAME) {
	C.pin.high_(PIN_NAME)
}

//@[inline]
pub fn pwm.setup_(port, pin, ...) {
	C."GPIO" #port "_ModeCfg(GPIO_Pin_" #pin ", " #__VA_ARGS__ ")\n"
}
@[inline]
pub fn pwm.setup_(port, pin, ...) {
	C."PWMX_ACTOUT(CH_PWM" #port ", " #__VA_ARGS__ ")\n"
}

@[inline]
pub fn pwm.setup(PIN_NAME, PIN_MODE) {
	C.pin.setup_(PIN_NAME, PIN_MODE)
}


// @[inline]
pub fn pin.high(a11) {
	C.GPIOA_SetBits(GPIO_Pin_11)
}
// @[inline]
pub fn pin.low(a11) {
	C.GPIOA_ResetBits(GPIO_Pin_11)
}

int main() 
{
    //printf(pin.setup(a11, output));
    printf(pin.setup(4, 10));
    printf(pin.high(a11));
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