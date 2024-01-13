/* BL702 Driver*/
#include <bflb_platform.h>
#include <hal_gpio.h>
/* USB STDIO */
#include <usb_stdio.h>

#include "io_def.h"

int main(void)
{
    bflb_platform_init(0);
    MSG_DBG(
        "Now can use MSG_xxx, LOG_xxx and bflb_platform_printf on uart.\r\n");  // just appear on uart unless use printf

#ifdef M0SENSE_USE_USBSTDIO
    usb_stdio_init();                                        // MUST be called before any call to printf or puts
    printf("Now can use printf, puts on usb_cdc_acm.\r\n");  // on usb, ttyACMx on Linux or COMx on Windows.
#endif

    gpio_set_mode(LED_B_PIN, GPIO_OUTPUT_PP_MODE);
    gpio_set_mode(LED_G_PIN, GPIO_OUTPUT_PP_MODE);
    gpio_set_mode(LED_R_PIN, GPIO_OUTPUT_PP_MODE);
    printf("[init] goio set mode complete.\r\n");

    enum {
        BLACK = 0,
        BLUE = 0b1,
        GREEN = 0b10,
        RED = 0b100,
        WHITE = RED | GREEN | BLUE,
        COLOR_MASK = WHITE,
    };

    uint8_t led_state = BLACK;

    printf("[main] start loop\r\n");
    while (1) {
        led_state = (led_state + 1) & COLOR_MASK;
        printf("increase 1 so led_state is %x\r\n", led_state);
        printf("rgb(%u,%u,%u)\r\n", !!(led_state & RED), !!(led_state & GREEN), !!(led_state & BLUE));

        gpio_write(LED_B_PIN, !(led_state & BLUE));
        gpio_write(LED_G_PIN, !(led_state & GREEN));
        gpio_write(LED_R_PIN, !(led_state & RED));
        mtimer_delay_ms(200);
    }
}
