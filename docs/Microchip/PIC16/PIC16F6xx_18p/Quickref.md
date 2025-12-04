# Quick Guide for PIC16F62X
## Reference of the PIC16 used from the MICROCHIP brand
- PIC16F62X (PIC16F627, PIC16F627A, PIC16F628 and PIC16F628A)

**NOTE:** An 8-bit, RISC microcontroller, the PIC16F62x family is the only one in its category that combines pin-to-pin compatibility with the older PIC16F84, but adds three more peripherals (**USART, PWM-CCP and comparators**), in addition to allowing the disabling of analog modules to recover all digital pins.

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

**PDIP, SOIC (Plastic Dual In-line Package, Small Outline Integrated Circuit)**

- **Plastic Dual In-line Package:** This is the large package, with pins on the sides, used for prototypes and breadboards. It is easy to solder and fits on a breadboard.
- **Small Outline Integrated Circuit:** SMD (surface mount) package, medium size, compact, cannot be used on a breadboard without an adapter.
![alt text](image-1.png)

**SSOP (Shrink Small Outline Package)** Small version, very fine pins, compact, ideal for portable equipment, requires specialized soldering.
![alt text](image-2.png)Fountain: (https://ww1.microchip.com/downloads/en/DeviceDoc/40300c.pdf)

## Main Specifications

| Nº | Specification       | Typical Value                               |
| -- | -------------------- | ------------------------------------------ |
| 1  | Program Memory  | 1K to 4K instructions (depends on the model) |
| 2  | RAM                  | 224 bytes                                  |
| 3  | EEPROM               | **128 bytes (all PIC16F62x)**        |
| 4  | Total Pins        | 18-20                                         |
| 5  | Operating Voltage | 2.0 V – 5.5 V                              |
| 6  | Maximum Frequency     | 20 MHz                                     |

## Features

| Nº | Feature          | Description / Value                |
| -- | ----------------------- | ---------------------------------- |
| 1  | Architecture            | M8-bit RISC Microcontroller       |
| 2  | Digital Pins | 15 (PORTA + PORTB) |
| 3 | EEPROM | 128 bytes |
| 4 | PWM | Available on 628(A) and 648A (CCP1) |
| 5 | USART (Serial) | Yes, on 627A/628A/648A |
| 6 | Analog Comparators | Yes, with CMCON disable |
| 7 | Timers | TMR0, TMR1, TMR2 |
| 8 | Interrupts | 12 available sources |
| 9 | Watchdog Timer | Yes |
| 10 | Sleep Mode | Yes |
| 11 | Maximum Frequency | Up to 20 MHz (200 ns per cycle) |
| 12 | Program Memory | 1K words (16F627) / 2K words (16F628/628A) |
| 13 | RAM | 224 bytes |
| 14 | Operating Voltage | 3.0–5.5 V (F62x) / 2.0–5.5 V (LF62x)                                |

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

- **`MCLR`** configurable as a digital input (only in A versions), adjustable according to the oscilloscope = the constant **CPU_FREQ** depends on the frequency of the external oscillator connected to the PIC.
- Oscillator Modes:
  - LP, XT, HS (oscilloscope), 
  - RC
  - xternal oscillator connects to pins **OSC1/OSC2**
  - - **INTOSC (internal oscillator)** → only on 628A/648A

## Timers

| Timer | Bits | Function |
| -- | ----------------------- | ---------------------------------- |
| **TMR0** | 8 bits  | general/counter, prescaler |
| **TMR1** | 16 bits | timer with prescaler  |
| **TMR2** | 8 bits  | time base for PWM     |

## Delays
```v
import time

time.sleep(2) // 2-second delay
time.sleep_ms(50) // 50-millisecond delay
time.sleep_us(100) // 100-microsecond delay

@[as_macro] // Delays depend on the microcontroller's frequency; ensure that CPU_FREQ matches your oscillator's frequency.
pub const CPU_FREQ: u32 = 4_000_000 // 4 MHz
```

## Integrated Modules
- **USART (Serial) - Universal Synchronous/Asynchronous Transmitter/Receiver**
- Available in 16F627A / 628A / 648A.
- Enables asynchronous transmission and reception (9600, 19200, etc.).

| Register | Function |
| -- | --------------------------------------------- |
| **TXSTA** | Transmitter Control                        |
| **RCSTA** | Receiver Control                          |
| **SPBRG** | Baud Rate Generator |

- **PWM (CCP1) - Baud Rate Generator**
  - Available on 16F628(A) and 648A.
  - Resolution: 10 bits for the duty cycle.
  - Works in conjunction with TMR2; does not require the CPU to manually generate the signal.

| Register | Function |
| ----------- | ---------------------------------------- |
| **CCP1CON** | CCP1 Module Configuration (PWM Mode) |
|**PR2** | Determines the PWM Period |
|**TMR2** | PWM Base Timer |
|**CCPR1L** | Adjusts the Duty Cycle |

- **Comparators**
  - Two comparators that can be disabled with **(CMCON = 0x07)** to use **RA0–RA3** as digital inputs.
  - Does not measure voltage.
  - Available on the entire PIC16F62X family.
  - Inputs: V+ and V- (two voltages to compare).
  - Output: (1 (high) → if V+ > V-) and (0 (low) → if V+ < V-)
  - The output can be internally connected to peripherals, such as the TMR0 timer, interrupts, or even the corresponding digital pin.

| Register | Function |
| ----------- |  --------------------------------------------------------- |
| **CMCON** | Configures and enables/disables the comparators. |
| **VREF** | Programmable voltage reference for the comparisons. |

## EEPROM (Electrically Erasable Programmable Read-Only Memory)

- 128 bytes of non-volatile memory.
- Writing is done using registers EECON1, EECON2, EEADR, and EEDATA.
- Write process with unlock protection.
- Data is retained; data is lost in RAM upon power-off.
- Stores configuration or counters.

| Register | Function |
| ---------- | ------------------------------------------------------- |
| **EECON1** | EEPROM read/write operation control |
|**EECON2** | Unlock sequence for writing (safe process) |
|**EEADR** | Address of the byte to read or write |
|**EEDATA** | Data to be read or written                           |

## Main Registers

| No. | Register | Function |
| -- | --------------- | ------------------------------ |
| 1  | PORTA           | Inputs/Outputs RA0–RA5 |
| 2 | PORTB | Inputs/Outputs RB0–RB7 |
| 3 | TRISA | Port A Address |
|4 | TRISB | Port B Address |
|5 | TMR0 | Timer 0 |
|6 | TMR1/T1CON | Timer 1 |
|7 | TMR2/T2CON | Timer 2 |
|8 | CMCON | Comparators |
|9 | CCP1CON | PWM Control (models with CCP1) |
|10 | TXSTA / RCSTA | USART Control |
|11 | INTCON | Main Interrupts |
|12 | PIE1 / PIR1 | Peripheral Flags |
|13 | EECON1 / EECON2 | EEPROM Control                 |

## Typical Uses

The PIC16F62x is ideal for:

- Replacing the older **PIC16F84** with more features.
- Controlling small motors with PWM.
- Serial communication in simple projects.
- Digital metering with interrupts on RB0 or ​​switching on RB4–RB7.
- Digital inputs with interrupt-driven debouncing.
- Low-power systems in Sleep mode.