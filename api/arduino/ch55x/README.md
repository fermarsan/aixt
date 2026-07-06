## Description

`ch55x` is not a module by itself, but a namespace for the CH55x API modules.

The API is split into several folders:

- core
- ch55x
- uart

The CH55x backend is based on the Arduino backend and uses **Arduino CLI** together with the **CH55xDuino** core and the **SDCC** compiler.

The current implementation supports the following microcontrollers:

- CH551
- CH552

The API provides a high-level interface for accessing the peripherals of the CH55x family from the V language without directly manipulating Special Function Registers (SFRs).

---

# Quick reference for the CH551 / CH552 boards

The original pin functions and alternate functions can be found in the official WCH datasheet.

Supported peripherals include:

- GPIO
- ADC
- PWM
- UART0
- Timers
- Interrupts
- USB Device
- SPI
- External Interrupts

---

# Board configuration

The default board configuration is:

| Parameter | Value |
|-----------|-------|
| Target | ch55x |
| Backend | Arduino |
| Core | CH55xDuino |
| Compiler | SDCC |
| Upload Tool | Arduino CLI |
| Default CPU Frequency | 6 MHz |
| Internal Oscillator | 24 MHz |
| PLL | 96 MHz |
| USB Clock | 48 MHz |

---

# Clock configuration

After reset the CH551/CH552 uses the internal RC oscillator.

| Clock | Frequency |
|--------|-----------|
| Internal RC | 24 MHz |
| PLL | 96 MHz |
| USB Clock | 48 MHz |
| Default System Clock | 6 MHz |

The system clock may be configured using the `CLOCK_CFG` register.

An external crystal oscillator may also be used.

When the external oscillator is enabled:

- XI becomes crystal input.
- XO becomes crystal output.

When disabled:

- XI → P1.2
- XO → P1.3

General recommendations:

- USB Full-Speed requires a 48 MHz USB clock.
- Lower system frequencies reduce power consumption.
- The internal oscillator accuracy depends on the V33 supply voltage.

---

# Delay and Timing

Use the `time` module.

```v
import time

time.sleep(2)
time.sleep_ms(500)
time.sleep_us(100)