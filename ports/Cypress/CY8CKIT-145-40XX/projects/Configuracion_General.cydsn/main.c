/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

#define STEP_SIZE (capsense_LINEARSLIDER_X_RESOLUTION/capsense_LINEARSLIDER_NUM_SENSORS)

#include "../../api/builtin.c"
#include "../../api/machine/pin.c"
#include "../../api/time/sleep_ms.c"

//void pin_high(void),pin_low(void),pin_write(void);

//void PWM0(void),PWM1(void),PWM2(void);
//void CAPSENSE0(void),CAPSENSE1(void);

int main(void)
{   
    CyGlobalIntEnable; /* Enable global interrupts. */
    uart_Start();    /* Configuracion General*/
    pwm0_Start();
    pwm1_Start();
    pwm2_Start();
    clock_Start();
    capsense_Start();
    capsense_InitializeAllBaselines();
    capsense_ScanAllWidgets();
    
    // pin_high();
    // pin_low();
    // pin_write();
    //PWM0();
    //PWM1();
    //PWM2();
    
    for(;;)
    {
        //CAPSENSE0();
      
        // Codigo del usuario
               
        //CAPSENSE1();
        
        pin_high(led4);
        sleep_ms(300);
        pin_low(led4);
        sleep_ms(300);
    }
    return 0;
}

// void pin_high()
// {
//     int __pin_name;
//     __pin_name=1;
    
//     switch(__pin_name) {
//     case 1: led1_Write(0);
//     break;
//     case 2: ;
//     break;
//     case 3: ;
//     break;
//     case 4: led4_Write(0);
//     break;
//     case 5: led5_Write(0);
//     break;
//     case 6: led6_Write(0);
//     break;
//     case 7: led7_Write(0);
//     break;
//     case 8: led8_Write(0);
//     break;
//     case 9: led9_Write(0);
//     break;
//     case 10: led10_Write(0);
//     break;
//     case 11: led11_Write(0);
//     break;
//     case 12: ;
//     break;
//     case 13: do0_Write(0);
//     break;
//     case 14: do0_Write(0);
//     break;
//     case 15: do0_Write(0);
//     break;
//     }   
// }

// void pin_low()
// {
//     int __pin_name;
//     __pin_name=4;
    
//     switch(__pin_name) {
//     case 1: led1_Write(1);
//     break;
//     case 2: ;
//     break;
//     case 3: ;
//     break;
//     case 4: led4_Write(1);
//     break;
//     case 5: led5_Write(1);
//     break;
//     case 6: led6_Write(1);
//     break;
//     case 7: led7_Write(1);
//     break;
//     case 8: led8_Write(1);
//     break;
//     case 9: led9_Write(1);
//     break;
//     case 10: led10_Write(1);
//     break;
//     case 11: led11_Write(1);
//     break;
//     case 12: ;
//     break;
//     case 13: do0_Write(1);
//     break;
//     case 14: do0_Write(1);
//     break;
//     case 15: do0_Write(1);
//     break;
//     }   
// }

// void pin_write()
// {
//     int __pin_name, __value;
//     __pin_name=5;
//     __value=0;
    
//     switch(__pin_name) {
//     case 1: led1_Write(__value);
//     break;
//     case 2: ;
//     break;
//     case 3: ;
//     break;
//     case 4: led4_Write(__value);
//     break;
//     case 5: led5_Write(__value);
//     break;
//     case 6: led6_Write(__value);
//     break;
//     case 7: led7_Write(__value);
//     break;
//     case 8: led8_Write(__value);
//     break;
//     case 9: led9_Write(__value);
//     break;
//     case 10: led10_Write(__value);
//     break;
//     case 11: led11_Write(__value);
//     break;
//     case 12: ;
//     break;
//     case 13: do0_Write(__value);
//     break;
//     case 14: do0_Write(__value);
//     break;
//     case 15: do0_Write(__value);
//     break;
//     }       
// }

void PWM0()
    {
        uint16 ciclo_util0=20;    //Definicion por el usuario ciclo util en [%]
        pwm0_WriteCompare(65535-ciclo_util0*655);
    }

void PWM1()
    {
        uint16 ciclo_util1=40;    //Definicion por el usuario ciclo util en [%]
        pwm1_WriteCompare(65535-ciclo_util1*655);
    }
    
void PWM2()
    {
        uint16 ciclo_util2=60;    //Definicion por el usuario ciclo util en [%]
        pwm2_WriteCompare(65535-ciclo_util2*655);
    }
    
void CAPSENSE0()
    {
        for(;;)
        {
            if (!capsense_IsBusy())
            {capsense_ProcessAllWidgets();
            break;}
        }
    }
    
void CAPSENSE1()
    {
        capsense_UpdateAllBaselines();
        capsense_ScanAllWidgets();
    }

/* [] END OF FILE */
