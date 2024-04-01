#include <stdio.h>
#include <string.h>

#define pin__output GPIO_ModeOut_PP_5mA

#define a11 A, 11

#define pin__high_(port, ...) "GPIO" #port "_SetBits(GPIO_Pin_" #__VA_ARGS__ ")\n"

#define pin__high(PIN_NAME)  pin__high_(PIN_NAME)

#define pin__setup_(port, pin, ...) "GPIO" #port "_ModeCfg(GPIO_Pin_" #pin ", " #__VA_ARGS__ ")\n"

#define pin__setup(PIN_NAME, PIN_MODE)  pin__setup_(PIN_NAME, PIN_MODE)
   
// #define pin__high(a11)     GPIOA_SetBits(GPIO_Pin_11)
// #define pin__low(a11)      GPIOA_ResetBits(GPIO_Pin_11)

int main() 
{
    printf(pin__setup(a11, pin__output));
    printf(pin__high(a11));
    return 0;
}
    
// #include "CH58x_common.h"                                

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