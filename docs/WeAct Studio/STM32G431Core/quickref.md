# QUICK GUIDE STM32G431CBU6

This is an Aixt implementation to provide support for the **STM32G431CBU6** development board.

## SUMMARY

* The STM32G431CBU6 by STMicroelectronics is a development board based on the STM32G431C6 microcontroller, part of the STM32G4 family, which combines performance, efficiency, and advanced features for embedded control.

* It is built around a 32-bit ARM Cortex-M4 core with FPU (Floating Point Unit), ideal for motor control, digital signal processing (DSP), industrial automation, and power control applications.

* The board includes multiple peripherals such as high-resolution ADCs, advanced timers (including PWM), and serial communication (UART, I2C, SPI), enabling robust embedded systems development.

## FUNCTION

* The STM32G431CBU6 can use its analog and digital pins to interface with sensors and actuators, enabling data acquisition and embedded control systems.

* It provides high-resolution PWM outputs, 12-bit analog inputs, and configurable timers for real-time process control.

* It supports multiple communication interfaces: UART, SPI, I2C, and CAN, allowing integration with a wide variety of external devices.

* Ideal for applications requiring precision, analog signal control, and real-time processing such as switched-mode power supplies, converters, motor controllers, and industrial IoT systems.

## SPECS

* ARM® Cortex®-M4 32-bit core with FPU.
* Up to 170 MHz system clock.
* 128 KB Flash memory.
* 32 KB SRAM.
* 1 x 12-bit ADC with up to 16 channels.
* 1 x 12-bit DAC.
* 6 general-purpose and advanced timers (PWM, encoder, capture, etc.).
* Communication:
  * 3 x USART/UART
  * 1 x SPI
  * 1 x I2C
  * 1 x CAN FD
* Power supply: 3.3V.
* USB port (depending on variant).
* General-purpose GPIO pins.

## PIN IDENTIFICATION

| Pin   | Name           | Main Function                                 |
|-------|----------------|-----------------------------------------------|
| PC6   | LED_BUILTIN    | Digital Output, onboard LED                   |
| PC13  | BUTTON         | Digital Input, onboard button (optional)      |
| PA7   | GPIO / PWM     | PWM Output or GPIO                            |
| PA8   | GPIO / PWM     | PWM Output or GPIO                            |
| PA9   | GPIO / PWM     | PWM Output or GPIO                            |
| PA0-PA5 | ADC Inputs   | Analog Inputs                                 |
| USART1 (PA9/PA10) | UART TX/RX | Serial Communication                |
| GND   | Ground         |                                               |
| 3.3V  | Power Supply   |                                               |

## PROGRAMMING IN V LANGUAGE (EXTENDED)

| Name                         | Description                                                        |
|------------------------------|--------------------------------------------------------------------|
| `pin.setup(pin, mode)`       | Configure `pin` as `input` or `output`                            |
| `pin.high(pin)`              | Set `pin` to high (HIGH)                                          |
| `pin.low(pin)`               | Set `pin` to low (LOW)                                            |
| `pin.write(pin, val)`        | Write value `val` (1 or 0) to `pin`                               |
| `pin.read(pin)`              | Digital read of `pin`                                             |
| `adc.read(pin)`              | Analog read from `pin`                                            |
| `pwm.write(pin, val)`        | PWM output on `pin` with duty cycle `val`                         |
| `pwm.setup(pin, freq)`       | Configure PWM `pin` with custom frequency                         |
| `pwm.stop(pin)`              | Disable PWM on `pin`                                              |
| `timer.start(id, ms)`        | Start `timer` with `id` (1, 2...) to trigger every `ms` ms        |
| `timer.stop(id)`             | Stop the specified timer                                          |
| `interrupt.setup(pin)`       | Enable external interrupt on `pin`                                |
| `interrupt.disable(pin)`     | Disable external interrupt on `pin`                               |
| `interrupt.on_falling(pin)`  | Trigger interrupt on falling edge on `pin`                        |
| `interrupt.on_rising(pin)`   | Trigger interrupt on rising edge on `pin`                         |
| `time.sleep(time)`           | Delay in seconds                                                  |
| `time.sleep_us(time)`        | Delay in microseconds                                             |
| `time.sleep_ms(time)`        | Delay in milliseconds                                             |
| `uart.setup(baud_rate)`      | Initialize serial communication at `baud_rate`                    |
| `uart.read()`                | Read data from UART                                               |
| `uart.println("message")`    | Print `message` through UART                                      |

## EXAMPLES

### BLINKING

```v
import time { sleep_ms }  			
import pin 						 	

pin.setup(6, pin.output)  			// PC6 as output

for {
	pin.high(6)  					
	time.sleep_ms(1000)  			
	pin.low(6)  					
	time.sleep_ms(1000)  			
}
```

### EXTERNAL INTERRUPT

```v
import pin
import ext

__global (
	state = true
)

@[ext_isr: 'pin.pc13']
fn blink() {
	state = !state
}

fn main() {
	pin.setup(pin.pc13, pin.in_pulldown)
	pin.setup(pin.pa8, pin.output)
	pin.high(pin.pa8)

	ext.irq_enable(pin.pc13, ext.rising)

	for {
		pin.write(pin.pa8, u8(state))
	}
}
```


### PWM OUTPUT 
```v
import time
import pin
import pwm

const duty_table = [u8(25), 60, 120, 180, 205]

pin.setup(pin.d3, pin.output)	// for PWM

for {
	for duty in duty_table {
		pwm.write(pin.d3, duty*256)
		time.sleep_ms(250)
	}
}