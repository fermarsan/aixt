/* BL702 Driver*/
#include <bflb_platform.h>
#include <bl702_glb.h>
#include <hal_gpio.h>
#include <hal_i2c.h>
/* USB STDIO */
#include <usb_stdio.h>

#include "io_def.h"

#define QMI8658A_DEV_ADDR (0x6A)

#define QMI8658A_REG_AX_L (0x35)
#define QMI8658A_REG_AX_H (0x36)
#define QMI8658A_REG_AY_L (0x37)
#define QMI8658A_REG_AY_H (0x38)
#define QMI8658A_REG_AZ_L (0x39)
#define QMI8658A_REG_AZ_H (0x3A)

#define QMI8658A_REG_GX_L (0x3B)
#define QMI8658A_REG_GX_H (0x3C)
#define QMI8658A_REG_GY_L (0x3D)
#define QMI8658A_REG_GY_H (0x3E)
#define QMI8658A_REG_GZ_L (0x3F)
#define QMI8658A_REG_GZ_H (0x40)

int main(void)
{
    bflb_platform_init(0);
    MSG_DBG(
        "Now can use MSG_xxx, LOG_xxx and bflb_platform_printf on uart.\r\n");  // just appear on uart unless use printf

#ifdef M0SENSE_USE_USBSTDIO
    usb_stdio_init();                                        // MUST be called before any call to printf or puts
    printf("Now can use printf, puts on usb_cdc_acm.\r\n");  // on usb, ttyACMx on Linux or COMx on Windows.
#endif

    GLB_GPIO_Type gpios[] = {IMU_SCK_PIN, IMU_SDA_PIN};
    GLB_GPIO_Func_Init(GPIO_FUN_I2C, gpios, sizeof(gpios) / sizeof(GLB_GPIO_Type));
    printf("[init] goio set mode complete.\r\n");
    /* initialize I2C0 */
    i2c_register(I2C0_INDEX, "i2c");
    struct device* i2c_dev = device_find("i2c");
    if (!i2c_dev) {
        printf("[init] I2C initial failed!\r\n");
    }
    device_open(i2c_dev, DEVICE_OFLAG_DEFAULT);
    printf("[init] I2C initial success!\r\n");

    uint8_t buf[12] = {0x60, 0xff, 0xff, 0x00, 0xff, 0x00, 0x03};
    i2c_msg_t msg;
    msg.buf = buf;
    msg.slaveaddr = QMI8658A_DEV_ADDR;

    msg.len = 7;
    msg.flags = SUB_ADDR_1BYTE | I2C_WR;
    msg.subaddr = 0x02;
    while (i2c_transfer(i2c_dev, &msg, 1)) {
        mtimer_delay_ms(50);
    }

    msg.len = sizeof(buf);
    msg.flags = SUB_ADDR_1BYTE | I2C_RD;
    msg.subaddr = QMI8658A_REG_AX_L;

    int16_t acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z;
    while (1) {
        if (i2c_transfer(i2c_dev, &msg, 1) == 0) {
            acc_x = buf[1];
            acc_x = (acc_x << 8) | buf[0];
            acc_y = buf[3];
            acc_y = (acc_y << 8) | buf[2];
            acc_z = buf[5];
            acc_z = (acc_z << 8) | buf[4];

            gyro_x = buf[7];
            gyro_x = (gyro_x << 8) | buf[6];
            gyro_y = buf[9];
            gyro_y = (gyro_y << 8) | buf[8];
            gyro_z = buf[11];
            gyro_z = (gyro_z << 8) | buf[10];
            printf("acc: %6d, %6d, %6d AND gyro: %6d, %6d, %6d\r\n", acc_x, acc_y, acc_z, gyro_x, gyro_y, gyro_z);
        }
        mtimer_delay_ms(100);
    }
}
