#include <stdio.h>
#include <string.h>

#define output GPIO_ModeOut_PP_5mA

#define a11 A, 11

#define pin.high_(port, ...) "GPIO" #port "_SetBits(GPIO_Pin_" #__VA_ARGS__ ")\n"

#define pin.high(PIN_NAME)  pin.high_(PIN_NAME)

//#define pin.setup_(port, pin, ...) "GPIO" #port "_ModeCfg(GPIO_Pin_" #pin ", " #__VA_ARGS__ ")\n"
#define pin.setup_(port, pin, ...) "PWMX_ACTOUT(CH_PWM" #port ", " #__VA_ARGS__ ")\n"

#define pin.setup(PIN_NAME, PIN_MODE)  pin.setup_(PIN_NAME, PIN_MODE)


// #define pin.high(a11)     GPIOA_SetBits(GPIO_Pin_11)
// #define pin.low(a11)      GPIOA_ResetBits(GPIO_Pin_11)

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