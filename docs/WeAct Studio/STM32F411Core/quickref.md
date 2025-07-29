# QUICK GUIDE STM32F411CEU6

This is an Aixt implementation to provide support for the STM32F411CEU6 board.

## SUMMARY

* The **STM32F411CEU6** is a powerful 32-bit ARM Cortex-M4 microcontroller from STMicroelectronics. It is ideal for embedded systems and real-time applications.
* This chip features a high-performance core, rich peripherals, and advanced timer and interrupt control, widely used in both academic and industrial contexts.
* It is often used with the **WeAct Studio Black Pill** board, which integrates all necessary hardware for easy programming and prototyping.

## FUNCTION

* The STM32F411CEU6 allows for digital and analog input/output, PWM, serial communication, timers, interrupts, and more.
* It is ideal for building automation systems, sensor reading, actuator control, and embedded computing.
* It integrates multiple peripherals like UART, I2C, SPI, ADC, PWM, and advanced timers.
* The board supports development using the Aixt platform and allows transcompilation of V code to C.

## SPECS

* Core: ARM Cortex-M4 @ 100 MHz
* Flash: 512 KB
* SRAM: 128 KB
* GPIO Pins: Up to 50
* ADC: 12-bit, up to 10 channels
* Timers: 
  * 4 x 16-bit general-purpose timers (TIM2–TIM5)
  * 1 x 32-bit timer (TIM2)
  * 2 x advanced-control PWM timers (TIM1, TIM8)
* Interfaces:
  * 3 x USART/UART
  * 3 x SPI
  * 2 x I2C
  * USB 2.0 FS (device)
* Debug: SWD

## PIN IDENTIFICATION

| Pin    | Name      | Function                     |
|--------|-----------|------------------------------|
| PA0    | GPIO, ADC | User Button                  |
| PA5    | GPIO      | SPI1_SCK, LED (optional)     |
| PA7    | GPIO, ADC | SPI1_MOSI                    |
| PB6    | GPIO      | I2C1_SCL, TIM4_CH1           |
| PB7    | GPIO      | I2C1_SDA, TIM4_CH2           |
| PB10   | GPIO      | UART3_TX, TIM2_CH3           |
| PB11   | GPIO      | UART3_RX, TIM2_CH4           |
| PC13   | GPIO      | Onboard Button (LOW active)  |
| PC14   | GPIO      | XTAL_IN                      |
| PC15   | GPIO      | XTAL_OUT                     |
| 3.3V   |           | Power Supply                 |
| GND    |           | Ground                       |

## PROGRAMMING IN V LANGUAGE

| Name                        | Description                                       |
|-----------------------------|---------------------------------------------------|
| `pin.setup(pin, mode)`      | Set `pin` as `mode` (input, output)              |
| `pin.high(pin)`             | Set pin high                                     |
| `pin.low(pin)`              | Set pin low                                      |
| `pin.write(pin, val)`       | Write digital value                              |
| `pin.read(pin)`             | Read digital value                               |
| `adc.read(pin)`             | Read analog input                                |
| `pwm.write(pin, val)`       | Set PWM duty cycle                               |
| `uart.setup(baud)`          | Initialize UART at `baud` rate                   |
| `uart.read()`               | Read UART input                                  |
| `uart_any()`                | Bytes available to read                          |
| `uart.println("text")`      | Print via UART                                   |
| `time.sleep(time)`          | Sleep in seconds                                 |
| `time.sleep_ms(time)`       | Sleep in milliseconds                            |
| `time.sleep_us(time)`       | Sleep in microseconds                            |
| `timer1.every(ms, func)`    | Run `func` every X ms using timer1               |
| `exti.attach(pin, func)`    | Attach interrupt handler to a pin                |

---

## EXAMPLES

### BLINKING

```v
import time { sleep_ms }
import pin

pin.setup(7, pin.output) // PA7

for {
    pin.high(7)
    sleep_ms(500)
    pin.low(7)
    sleep_ms(500)
}
```
### PWM

```v
import time { sleep_ms }
import pin
import pwm

__global (
  duty = 0
)

pin.setup(7, pin.output) // PA7

for {
    pwm.write(7, duty)
    sleep_ms(200)
    duty += 25
    if duty >= 255 {
        duty = 0
    }
}

