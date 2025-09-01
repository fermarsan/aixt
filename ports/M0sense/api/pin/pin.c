// Project name: Aixt project, https://github.com/fermarsan/aixt

// Author: Yahir Gracia
// Date: 2024
// License: MIT
//
// Description: Pin(M0sense)
#define LED_B_PIN   a0 // Onboard LEDs
#define LED_G_PIN   a1
#define LED_R_PIN   a2

#define BTN_PIN     d6_i  // Onboard switchs  

@[as_macro] pub const a0 =_s    TRISAbits.TRISA0




// Onboard ADC  
#define ADC_CLK_DIV_1, /*!< ADC clock:on 32M clock is 32M */
#define ADC_CLK_DIV_4, /*!< ADC clock:on 32M clock is 8M */
#define ADC_CLK_DIV_8, /*!< ADC clock:on 32M clock is 4M */
#define ADC_CLK_DIV_12, /*!< ADC clock:on 32M clock is 2.666M */
#define ADC_CLK_DIV_16, /*!< ADC clock:on 32M clock is 2M */
#define ADC_CLK_DIV_20, /*!< ADC clock:on 32M clock is 1.6M */
#define ADC_CLK_DIV_24, /*!< ADC clock:on 32M clock is 1.333M */
#define ADC_CLK_DIV_32, /*!< ADC clock:on 32M clock is 1M */