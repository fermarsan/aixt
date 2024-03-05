/* BL702 Driver*/
#include <bflb_platform.h>
/* USB STDIO */
#include <usb_stdio.h>

int main(void)
{
    bflb_platform_init(0);
    MSG_DBG(
        "Now can use MSG_xxx, LOG_xxx and bflb_platform_printf on uart.\r\n");  // just appear on uart unless use printf

#ifdef M0SENSE_USE_USBSTDIO
    usb_stdio_init();                                        // MUST be called before any call to printf or puts
    printf("Now can use printf, puts on usb_cdc_acm.\r\n");  // on usb, ttyACMx on Linux or COMx on Windows.
#endif

    while (1) {
        printf("hello, world\r\n");
        mtimer_delay_ms(2000);
    }
}