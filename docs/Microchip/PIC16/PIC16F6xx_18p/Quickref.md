# Quick Guide for PIC16F6xx_18p
## Reference of the PIC16 used from the MICROCHIP brand
- PIC16F6xx_18p (Includes PIC16F627, PIC16F627A, PIC16F628, PIC16F628A and PIC16F648A)

**NOTE:** The 8-bit, RISC microcontroller, the PIC16F6xx_18p family, is pin-compatible with the PIC16F84, but adds advanced peripherals such as **USART**, **PWM**, **CCP1**, and analog comparators, as well as allowing the deactivation of analog modules to recover all pins as digital.

| Model | Flash | USART | PWM (CCP1) | Osc. internal |
| ---------- | ----- | ----- | ---------- | ------------ |
| PIC16F627 | 1K | NOT | NOT | NOT |
| PIC16F627A | 1K | YES | NOT | NOT |
| PIC16F628 | 2K | NOT | YES | NOT |
| PIC16F628A | 2K | YES | YES | YES |
| PIC16F648A | 4K | YES | YES | YES |

## Pin Names
Pin names are designated with a letter indicating the port and a number indicating the pin. For example, `b6` indicates pin 6 of port B. All names in **Aixt** are written in lowercase, for clarity. [V variable naming rules.] (https://github.com/vlang/v/blob/master/doc/docs.md#variables).

| Port | 0    | 1    | 2    | 3    | 4    | 5    | 6     | 7     |
| :----: | ---- | ---- | ---- | ---- | ---- | ---- | ----- | ----- |
|  **A** | `a0` | `a1` | `a2` | `a3` | `a4` | `a5` | ----- | ----- |
|  **B** | `b0` | `b1` | `b2` | `b3` | `b4` | `b5` | `b6`  | `b7`  |

- **a4** → **open-drain** type output, the same as in PIC16F84.
- **a0–a3** → can function as comparator inputs **(CMCON)**.
- **b0** → interrupt input **INT**.
- **b4–b7** → interrupts on state change **(Port Change)**.
- **a5** → can function as **MCLR** or digital input (configurable, A models).

**PDIP, SOIC (Plastic Dual In-line Package, Small Outline Integrated Circuit)**

- **Plastic Dual In-line Package:** This is the large package, with pins on the sides, used for prototypes and breadboards. It is easy to solder and fits on a breadboard.
- **Small Outline Integrated Circuit:** SMD (surface mount) package, medium size, compact, cannot be used on a breadboard without an adapter.
![alt text](image-3.png)
Fountain: (https://ww1.microchip.com/downloads/en/DeviceDoc/40044E.pdf)
![alt text](image-6.png)
Fountain: (https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40300C.pdf)

**SSOP (Shrink Small Outline Package)** Small version, very fine pins, compact, ideal for portable equipment, requires specialized soldering.
![alt text](image-4.png) 
Fountain: (https://ww1.microchip.com/downloads/en/DeviceDoc/40044E.pdf)
![alt text](image-7.png)
Fountain: (https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40300C.pdf) 

## Main Specifications

| Feature (PIC16F627A*/628A/648A) | Value |
----------------------------------- | ----- |
Program Memory Size (KB) | 1.75* |
RAM (bytes) | 224 |
Data EEPROM (bytes) | 128 |
Number of Pins | 18 |
Maximum Operating Voltage (V) | 5.5 |
Minimum Operating Voltage (V) | 2.0 |

Source: (https://www.microchip.com/en-us/product/pic16f627a)

| Feature (PIC16F627/28) | Value |
---------------------------------------- | ----- |
Maximum ADC Resolution (bits) | 0 |
Number of Comparators | 2 |
Data EEPROM (bytes) | 128 |
Data Signal Modulator (DSM) | 0 |
Numerically Controlled Oscillator (NCO) | 0 |
Maximum Operating Voltage (V) | 5.5 |

Source: (https://www.microchip.com/en-us/product/pic16f627)

## Features

They have 18 pins, up to 4K words of program memory, 224 bytes of RAM, 128 bytes of EEPROM, operate between 2.0 and 5.5 V, and reach up to 20 MHz, making them suitable for simple control, serial communication, and compact embedded systems.

| Feature | Description |
----------------------- | --------------------------------------------- |
| Architecture | **8-bit RISC** Microcontroller |
| Supported Models | PIC16F627, 627A, 628, 628A, 648A |
| Packages | **PDIP-18, SOIC-18, SSOP-18** |
| Compatibility | **Pin-to-pin compatible with PIC16F84** |
| Program Memory | **1K / 2K / 4K words** (depending on model) |
| RAM | **224 bytes** |
| Data EEPROM | **128 bytes** |
| I/O Pins | **15 digital pins** (PORTA + PORTB) |
| Operating Voltage | **2.0–5.5 V (LF) / 3.0–5.5 V (F)** |
| Maximum Frequency | **20 MHz** |
| Internal Oscillator | **628A and 648A only** |
| Timers | **TMR0 (8-bit), TMR1 (16-bit), TMR2 (8-bit)** |
| PWM (CCP1) | **628 / 628A / 648A** |
| USART | **627A / 628A / 648A** |
| Analog Comparators | **2 comparators**, disableable |
| Interrupts | **External INT + change on RB4–RB7** |
| Watchdog Timer | Yes |
| Sleep Mode | Yes |
| ADC | **Not available** |

## Aixt Base Code (I/O)

```v
import pin

// Pin configuration
pin.setup(pin.b0, pin.output)
pin.setup(pin.a1, pin.input)

// Digital write
pin.high(pin.b0)
pin.low(pin.a3)

// Toggle
pin.toggle(pin.b7)

// Read
value := pin.read(pin.a1)

// Input → Output echo
pin.write(pin.b2, pin.read(pin.a1))
```

## Oscillator and MCLR

`MCLR/a5` can be configured as a digital input only on A models (PIC16F627A, 628A, and 648A) using the configuration bits; on non-A models, it functions exclusively as an external reset.

The constant **CPU_FREQ** must match the actual frequency of the oscillator (internal or external) for the delays and timings to be correct.

External oscillator modes:
- **LP**, **XT**, **HS** (crystal or resonator),
- **RC**.

The external oscillator is connected to the OSC1/OSC2 pins.

The internal oscillator **INTOSC** is available only on the PIC16F628/28A and PIC16F648A, allowing operation without an external oscillator.

## Timers

| Timer | Size | Description |
------------ | ------- | ---------------------------------------------------------------------------------------------------------------------------------------- |
**TMR0** | 8 bits | General-purpose timer/counter with a shared **prescaler** with the Watchdog Timer; can count external or internal pulses. |
**TMR1** | 16 bits | High-resolution timer with a configurable prescaler, ideal for precise measurements and generating periodic interrupts. |
**TMR2** | 8 bits | Timer with a **postscaler**, used as the time base for the **PWM module (CCP1)** in models that include it. |

## Delays

Delays are implemented by software and are suitable for simple tasks; for more precise or non-blocking timings, the use of **TMR0, TMR1 or TMR2** type timers is recommended.

```v
import time

time.sleep(2) // 2-second delay
time.sleep_ms(50) // 50-millisecond delay
time.sleep_us(100) // 100-microsecond delay

@[as_macro] // Delays depend on the microcontroller's frequency; ensure that CPU_FREQ matches your oscillator's frequency.
pub const CPU_FREQ: u32 = 4_000_000 // 4 MHz
```

## Integrated Modules
- **USART (Serial) - Universal Asynchronous Transmitter/Receiver**
  - Available in 16F627A / 628A / 648A.
  - It supports asynchronous serial communication (e.g., 9600, 19200 bps).
   - It uses dedicated hardware, reducing the CPU load.

| Register | Function |
| -- | --------------------------------------------- |
| **TXSTA** | Transmitter Control                        |
| **RCSTA** | Receiver Control                          |
| **SPBRG** | Baud Rate Generator |

- **PWM (CCP1) - Baud Rate Generator**
  - Available on 16F628/28A and 648A.
  - Resolution: 10 bits for the duty cycle.
  - Works in conjunction with TMR2; does not require the CPU to manually generate the signal.

| Register | Function |
| ----------- | ---------------------------------------- |
| **CCP1CON** | CCP1 Module Configuration (PWM Mode) |
|**PR2** | Determines the PWM Period |
|**TMR2** | PWM Base Timer |
|**CCPR1L** | Adjusts the Duty Cycle |

- **Comparators**
  - Two analog comparators are available across the entire **PIC16F6xx_18p** family.
  - They can be disabled using `CMCON = 0x07` to use pins **a0–a3** as digital inputs/outputs.
  - They do not perform analog-to-digital conversion (they do not measure voltage, they only compare levels).
  - Inputs: V+ and V- (two voltages to compare).
  - Output: (1 (high) → if V+ > V-) and (0 (low) → if V+ < V-)
  - The output can be routed internally to peripherals as interrupts or used as a logic signal, without the need for external hardware.

| Register | Function |
| ----------- |  --------------------------------------------------------- |
| **CMCON** | Configures and enables comparators. |
**VRCON** | Generates an internal voltage reference. |

## EEPROM (Electrically Erasable Programmable Read-Only Memory)

- 128 bytes of non-volatile memory.
- Writing is done using registers EECON1, EECON2, EEADR, and EEDATA.
- Write process with unlock protection.
- It retains data even without power; RAM loses its contents when turned off.
- Stores configuration or counters.

| Register | Function |
| ---------- | ------------------------------------------------------- |
| **EECON1** | EEPROM read/write operation control |
|**EECON2** | Unlock sequence for writing (safe process) |
|**EEADR** | Address of the byte to read or write |
|**EEDATA** | Data to be read or written                           |

## Main Registers

| Register | Function |
| ------------------ | ----------------- |
| PORTA / PORTB | I/O |
| TRISA / TRISB | Address |
| INTCON | Interrupts |
| PIE1 / PIR1 | Peripheral Flags |
| TMR0 / TMR1 / TMR2 | Timers |
| CMCON | Comparators |
| CCP1CON | PWM |
| TXSTA / RCSTA | USART |

## Typical Uses

- Replace the older **PIC16F84** with more features.
- Control small motors with PWM.
- Serial communication in simple projects.
- Digital measurement with interrupts `b0` or changes in `b4–b7`.
- Digital inputs with interrupt-based debouncing (debouncing is not done automatically by the hardware, it is implemented by software).
- Low-power systems in Sleep mode.