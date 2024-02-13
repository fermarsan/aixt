#include <assert.h>
/* FreeRTOS */
#include <FreeRTOS.h>
#include <task.h>
/* BL702 Driver*/
#include <bflb_platform.h>
#include <hal_gpio.h>
/* USB STDIO */
#include <usb_stdio.h>

#include "io_def.h"

static void rgbled_task(void* pvParameters)
{
    const char* const taskName = pcTaskGetTaskName(NULL);

    enum {
        BLACK = 0,
        BLUE = 0b1,
        GREEN = 0b10,
        RED = 0b100,
        WHITE = RED | GREEN | BLUE,
        COLOR_MASK = WHITE,
    };

    uint8_t led_state = BLACK;
    uint8_t led_state_next_offset = 1;

    bool now_is_pressed = false;
    bool last_is_pressed = false;
    uint64_t keep_pressed_count = 0;
    uint64_t keep_released_count = 0;

    printf("[%s] start loop\r\n", taskName);
    for (TickType_t tick_now;; vTaskDelay(pdMS_TO_TICKS(10))) {
        tick_now = xTaskGetTickCount();

        last_is_pressed = now_is_pressed;
        now_is_pressed = !gpio_read(BTN_PIN);
        bool now_is_released = !now_is_pressed;

        bool now_is_still_pressed = now_is_pressed && last_is_pressed;
        keep_pressed_count = now_is_still_pressed ? (keep_pressed_count + 1) : now_is_still_pressed;
        bool now_is_still_released = !(now_is_pressed || last_is_pressed);
        keep_released_count = now_is_still_released ? (keep_released_count + 1) : now_is_still_released;

        bool action_press = now_is_pressed && !last_is_pressed;
        bool action_release = !now_is_pressed && last_is_pressed;

        if (action_press) {
            led_state_next_offset *= (uint8_t)-1;
        }

        if (now_is_still_pressed && (keep_pressed_count % 50 == 0)) {
            led_state = (led_state + led_state_next_offset) & COLOR_MASK;
            printf("%s 1 so led_state is %x\r\n", led_state_next_offset == 1 ? "increase" : "decrease", led_state);
            printf("rgb(%u,%u,%u)\r\n", !!(led_state & RED), !!(led_state & GREEN), !!(led_state & BLUE));
        }

        gpio_write(LED_B_PIN, !(led_state & BLUE));
        gpio_write(LED_G_PIN, !(led_state & GREEN));
        gpio_write(LED_R_PIN, !(led_state & RED));
    }
}

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
    gpio_set_mode(BTN_PIN, GPIO_INPUT_PP_MODE);
    printf("[init] goio set mode complete.\r\n");

    static uint8_t freertos_heap[configTOTAL_HEAP_SIZE];
    static HeapRegion_t xHeapRegions[] = {
        {(uint8_t*)freertos_heap, configTOTAL_HEAP_SIZE}, {NULL, 0}, /* Terminates the array. */
    };
    vPortDefineHeapRegions(xHeapRegions);

    configASSERT((configMAX_PRIORITIES > 4));

    printf("[OS] Starting rgbled task...\r\n");
    xTaskCreate(rgbled_task, (char*)"rgbled_task", 1024, NULL, configMAX_PRIORITIES - 1, NULL);

    bflb_print_device_list();

    vTaskStartScheduler();

    while (1) {
        __WFI();
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}
