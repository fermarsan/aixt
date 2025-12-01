# Quick Guide to the P16F8X
## Reference for the PIC16 used by the MICROCHIP brand
- PIC16F8X (PIC16F83, PIC16F84, PIC16CR83, PIC16CR84)

**NOTE** This guide does **NOT** include **ADC**, **PWM**, or **UART** modules, as the PIC16F8X does not have these modules.

## Pin Names
Pin names consist of a letter indicating the port and a number indicating the pin. For example, **a2** indicates pin **2** of port **A**. All names in Aixt are written in lowercase [V Variable Naming Rules]. (https://github.com/vlang/v/blob/master/doc/docs.md#variables)

It has two digital circuit input/output pins to display the programmed on/off behavior of the LED.

| Port | 0    | 1    | 2    | 3    | 4    | 5     | 6     | 7     |
| :---: | ---- | ---- | ---- | ---- | ---- | ----- | ----- | ----- |
| **A** | `a0` | `a1` | `a2` | `a3` | `a4` | ----- | ----- | ----- |
| **B** | `b0` | `b1` | `b2` | `b3` | `b4` | `b5`  | `b6`  | `b7`  |

At **a4**, the output is open-drain, the input is normal, and no pin supports continuous analog voltage in ADC mode, as it is digital.

**Aixt uses lowercase pin names, without the "R" prefix: a0, a1, b3, b7…**

| Nº | Specification                     | Value  |
|:--:|------------------------------------|--------|
|  1 | Program Memory (KB) (KB)           | 0.875  |
|  2 | RAM (bytes)                        | 36     |
|  3 | EEPROM (bytes)                     | 64     |
|  4 | Number of Pins                    | 18     |
|  5 | Minimum Operating Voltage (V)    | 2      |
|  6 | Maximum Operating Voltage (V)    | 6      |

Fountain: (https://www.microchip.com/en-us/product/pic16f83)

| Nº | Feature                           | Description / Value                              |
|:--:|-------------------------------------------|--------------------------------------------------|
|  1 | Architecture                               | 8-bit RISC Microcontroller                  |
|  2 | Digital I/O Pins                     | 13 (PORTA + PORTB)                               |
|  3 |Flash Memory  (program)                   | 512–1K instructions                             |
|  4 |EEPROM Memory                              | 64 bytes                                         |
|  5 | RAM                                        | 36 to 68 bytes (depending on variant)                   |
|  6 | Timer                               | 8-bit TMR0                                   |
|  7 | Available Interrupt Types         | 4                                               |

```v
import pin

// Configuration
pin.setup(pin.b0, pin.output)
pin.setup(pin.a1, pin.input)

// Write to pins
pin.high(pin.b0)
pin.low(pin.a3)

// Toggle a pin
pin.toggle(pin.b7)

// Read a pin
value := pin.read(pin.a1)

// Echo (input → output)
pin.write(pin.b2, pin.read(pin.a1))
```
![alternative text](image.png) Fountain: (https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/30430D.pdf)

It is a simple microcontroller geared towards basic learning. Because it does not incorporate advanced peripherals such as **ADC**, **PWM**, or **UART**, its primary use is digital.

- It is only suitable for testing **I/O**, **TMR0**, **interrupts**, and **EEPROM**.
- It is ideal for introductory exercises, simulation, and understanding the **PIC** architecture.
- It allows for clear study of:
  - **Read-Modify-Write (R-M-W)** operations on ports
  - Address configuration using **TRIS**
  - Use of the **prescaler**
  - Operation of the **TMR0 timer**
  - **Interrupt** latencies and handling
  - Reading and writing to **EEPROM**

Thanks to its simplicity, this microcontroller is perfect for developing a solid foundation before moving on to more complex devices.

It is ideal for introductory simulation exercises and for understanding the fundamentals of the PIC architecture.

- It allows for the clear study of concepts such as:
 - Read-Modify-Write **(R-M-W)**
 - **TRIS** configuration
 - Interrupt latencies
 - Prescaler usage
 - Data **EEPROM** handling

**`MCLR`** stands for Master Clear/Reset, a controller reset pin connected to Vcc (+5V).
**`OSC`** stands for Oscillator Pins, which controls the system clock and determines program execution speed. In the PIC16F83-1, it is an internal crystal-mode output connected to the second pin (it has one input and one output, OSC1 and OSC2).
**`VDD`** Positive power and ground reference for the logic and I/O pins, respectively. These pins have diode protection.
**`VSS`** stands for Voltage Source, Source, or Voltage Supply Source and is the ground (GND) pin, also known as the voltage reference, 0 volts for the entire circuit.

## General control of $\mu C$
```v
// Microcontroller oscillator frequency
// Adjust according to the crystal used in the hardware or simulation.

@[as_macro]
pub const CPU_FREQ: u32 = 4_000_000; // 4 MHz
```

| Hardware | Value for CPU_FREQ |
|---------------------|---------------------|
| 4 MHz               | 4_000_000           |
| 8 MHz               | 8_000_000           |
| 10 MHz              | 10_000_000          |
| 20 MHz              | 20_000_000          |

# Delay

The **`time`** module allows you to generate delays in seconds, milliseconds, or microseconds.

```v
import time

time.sleep(2) // 2-second delay
time.sleep_ms(50) // 50 ms delay
time.sleep_us(100) // 100 µs delay
```

## Functions
| Nº | Registro        | Función principal                                   |
|:--:|-----------------|------------------------------------------------------|
|  1 | PORTA           | Read/write pins RA0–RA4                  |
|  2 | PORTB           | Read/write pins RB0–RB7                  |
|  3 | TRISA           | Port A address configuration             |
|  4 | TRISB           | Port B Address Configuration             |
|  5 | TMR0            | 8-bit Timer/Counter                     |
|  6 | OPTION_REG      | Prescaler, INT Edge, TMR0 Configuration TMR0           |
|  7 | INTCON          | Interrupt Management (GIE, INTE, T0IE, RBIE)   |
|  8 | EECON1          | EEPROM Control                                   |
|  9 | EECON2          | EEPROM Write Sequence                       |