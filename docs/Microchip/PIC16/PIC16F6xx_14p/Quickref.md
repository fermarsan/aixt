# Quick Guide to PIC16F6xx_14p
## Reference PIC16 microcontroller by MICROCHIP
- PIC16F6xx_14p (includes PIC16F630, PIC16F676 and PIC16F684)

**NOTE:** A quick guide does **NOT** replace the **datasheet** — it only includes the essential information affecting configuration, pin usage, **ADC**, It is only available on the PIC16F676 and PIC16F684. The PIC16F630 does not have an **ADC**.

## Pin Naming

Pin names consist of a letter indicating the port and a number indicating the pin. For example, **c1** means pin **1** of port **c**. All Aixt pin names are lowercase according to the  [V language variable naming rules](https://github.com/vlang/v/blob/master/doc/docs.md#variables).

These pins can function as digital inputs or outputs, analog inputs for the **ADC**, or perform special functions such as clock, interrupt, or comparator functions. Understanding this nomenclature allows you to correctly configure each pin and take full advantage of the microcontroller's capabilities without conflicts between its digital and analog functions.

| Port | 0    | 1    | 2    | 3    | 4    | 5    | 6 | 7 |
|:----:|------|------|------|------|------|------|---|---|
| **A** | `a0` | `a1` | `a2` | `a3` | `a4` | `a5` | - | - |
| **C** | `c0` | `c1` | `c2` | `c3` | `c4` | `c5` | - | - |

The analog **ADC** functions are only available on the PIC16F676 and PIC16F684. The PIC16F630 uses all pins solely as digital I/O.

#### 14-pin PDIP, SOIC, TSSOP
![alt text](image-2.png) Source: https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40039F.pdf

#### 14-Pin Diagram (PDIP, SOIC, TSSOP)
![alt text](image-3.png)
Source: https://ww1.microchip.com/downloads/en/DeviceDoc/41202F-print.pdf

## Characteristics

| **Feature** | **Value** |
|------------------------------- | ------------------------------------- |
|**Family** | PIC16F6xx_14p |
|**Architecture** | 8-bit, Mid-Range RISC core |
|**Program Memory (Flash)** | ~1K words |
|**RAM (SRAM)** | 64 bytes |
|**Data EEPROM** | 128 bytes |
|**Number of Pins** | 14 |
|**I/O Ports** | 2 (Port A and Port C) |
|**Digital Pins** | Up to 12 I/O pins |
|**ADC** | PIC16F676 and PIC16F684 only |
|**ADC Resolution** | 10 bits (when available) |
|**Comparators** | 1 analog comparator |
|**Timers** | Timer0 (8 bits), Timer1 (16 bits) |
|**Internal Oscillator** | 4 MHz calibrated (OSCCAL) |
|**Operating Voltage** | 2.0 V – 5.5 V |
|**Power Consumption** | Low power consumption with Sleep mode |
|**Interrupts** | INT, Timer0, Timer1, IOC |
|**Programming** | ICSP® (In-Circuit Serial Programming) |

These features are common to all three devices in the **PIC16F6xx_14p** family.

## Main Specifications

- The specifications are common to the **PIC16F6xx_14p** family.
- The **ADC** analog functions are not present in the **PIC16F630**.

| **Category** | **Specification** |
|----------------------------- | ------------------------------------------------------ |
|**Architecture** | 8-bit, Mid-Range RISC core (35 instructions) |
|**Program Memory** | ~1K Flash words |
|**RAM (SRAM)** | 64 bytes |
|**EEPROM** | 128 bytes |
|**I/O Ports** | Port A and Port C |
|**Digital I/O Pins** | Up to 12 pins (RA0–RA5, RC0–RC5) |
|**Analog Inputs (ADC)** | Available only on PIC16F676 and PIC16F684 (10-bit) |
|**Comparators** | 1 analog comparator |
|**Timers** | Timer0 (8-bit), Timer1 (16-bit) |
|**Internal Oscillator** | 4 MHz calibrated (OSCCAL) |
|**External Clock** | OSC1/OSC2 available |
|**Operating Voltage** | 2.0 V to 5.5 V |
|**Power Consumption** | Low power consumption with Sleep mode |
|**Interrupts** | External INT, Timer0, Timer1, IOC (Interrupt-on-Change) |
|**Programming** | ICSP® (In-Circuit Serial Programming) |
|**Package** | DIP-14 / SOIC-14 |

## General Configuration

The initial configuration of the microcontroller defines the basic behavior of the pins, ports, and peripherals before the main program begins execution. In the **PIC16F6xx_14p** family, it is recommended to first configure the digital mode of the pins, set the port addresses, and, if the model allows it, enable the **ADC** module.

```v
import pin
import port
import adc
import time

pin.setup(pin.a0, pin.output) // Digital pins
pin.setup(pin.a1, pin.input)
pin.setup(pin.a2, pin.output)
pin.setup(pin.c0, pin.input)
pin.setup(pin.c3, pin.output)

pin.digital() 
// Set all pins to 
// digital mode (ANSEL = 0, CMCON = 0x07)

port.setup(port.a, 0b000000)   // Port A as outputs
port.setup(port.c, 0b000011)   // RC0 & RC1 inputs, others outputs

adc.setup()          // Initialize ADC (PIC16F676 and PIC16F684 only)
adc.read(0)          // Select AN0 channel
```

## Electrical Limits

| **Parameter**               | **Value / Range**         | **Description**                         |
| --------------------------- | ------------------------- | --------------------------------------- |
| **Operating voltage (VDD)** | **2.0 V – 5.5 V**         | Recommended operating range.            |
| **Max pin voltage**         | **−0.3 V to VDD + 0.3 V** | Absolute limits to avoid damage.        |
| **Max current per I/O pin** | **25 mA**                 | Avoid exceeding to prevent overheating. |
| **Max current per port**    | **80 mA**                 | Total allowed for Port A or C.          |
| **Total device current**    | **~200 mA (max)**         | Absolute maximum rating.                |
| **Sleep current**           | **< 1 µA typical**        | Ultra-low power mode.                   |
| **Internal oscillator**     | **4 MHz**                 | Calibrated with OSCCAL.                 |
| **MCLR resistor**           | **10 kΩ**                 | Typical pull-up resistor on RA3/MCLR.   |
| **Max external clock**      | **20 MHz**                | With HS/XT/EC modes.                    |

These values ​​correspond to typical operating conditions. For absolute values ​​and extreme conditions, always refer to the official Microchip data sheet.

## Key Records Table (TRIS, PORT, ANSEL, ADCON)

| **Register**           | **Function**         | **Description**                                  |
| ---------------------- | -------------------- | ------------------------------------------------ |
| **TRIS** (TRISA/TRISC) | Pin direction        | 1 = Input, 0 = Output.                           |
| **PORT** (PORTA/PORTC) | Read/write pins      | Inputs read, outputs write according to TRIS.    |
| **ANSEL**              | Analog configuration | Enables ADC channels. 1 = Analog, 0 = Digital.   |
| **ADCON0**             | ADC control          | Enables ADC, selects channel, starts conversion. |
| **ADCON1**             | ADC configuration    | References, ADC clock, justification.            |

The **ANSEL**, **ADCON0**, and **ADCON1** registers do not exist in the **PIC16F630**, as this device does not include an **ADC** module. **They only exist** in the PIC16F676 and PIC16F684.
For the **PIC16F6xx_14p** family, these registers should only be used when working with the **PIC16F676** or **PIC16F684**.

## Timer

| **Timer** | **Register(s)** | **Available on** | **Description / Basic Use** |
| ---------- | --------------------------------------------- | ----------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|**Timer0** | `OPTION_REG`<br>`INTCON` (T0IE, T0IF) | 630 · 676 · 684 | 8-bit timer with prescaler. Uses internal clock (Fosc/4) or external input **RA2/T0CKI**. Generates an interrupt on overflow. Ideal for simple delays and event counting. |
| **Timer1** | `T1CON`<br>`PIE1` (TMR1IE)<br>`PIR1` (TMR1IF) | 676 · 684 | More precise 16-bit timer. Can use internal or external clock via **T1CKI**. Supports prescaler. Suitable for stable time measurements.

* Timer1 is NOT available on the **PIC16F630**.

## Interrupts

| **Register** | **Function** | **Description / Basic Use** |
------------ | -------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
**INTCON** | Global Interrupt Control | Contains the main bits: **GIE** (enables all interrupts), **PEIE** (peripherals), **T0IE/T0IF** (Timer0), **INTE/INTF** (RA2/INT), **RAIE/RAIF** (change on Port A). |
**PIE1** | Interrupt Enable | Enables interrupts from internal peripherals such as **Timer1 (TMR1IE)** and **ADC (ADIE)**. Requires **PEIE = 1**. |
**PIR1** | Interrupt Flags | Indicates which module generated the interrupt (**TMR1IF**, **ADIF**, etc.). Must be cleared by software. |
**IOCA** | Interrupt-on-Change (Port A) | Enables interrupts when a pin on **Port A** changes state. Useful for buttons or sensors without continuous polling.

#### Available Interrupt Types
- Timer0 overflow
- Timer1 overflow
- External interrupt via RA2/INT pin
- Interrupt-on-change on Port A pins
- ADC complete (PIC16F676 and PIC16F684 only)

The **PIC16F630** does not include an **ADC**, therefore it does not generate ADC interrupts.
All interrupts require `GIE` = 1 in `INTCON`.
Peripheral interrupts require `PEIE` = 1 in addition to the specific bit in `PIE1`.

## Oscillator Configuration

| Component / Register   | Function               | Description                                                           |
| ---------------------- | ---------------------- | --------------------------------------------------------------------- |
| **OSCCAL**             | Oscillator calibration | Adjusts internal 4 MHz oscillator (factory value).                    |
| **Oscillator Mode**    | Config bits (fuses)    | INTOSC, LP, XT, HS, EC. INTOSC (4 MHz) is common.                     |
| **OSC1/CLKIN (RA5)**   | External clock input   | Used when external crystal/clock is selected.                         |
| **OSC2/CLKOUT (RA4)**  | Clock output           | Outputs system clock in external modes; digital/AN3 in internal mode. |
| **Internal Frequency** | 4 MHz                  | Default operating frequency.                                          |

## Reset and WDT Modes

Fuses (also called configuration bits or configuration fuses) are special configuration bits that define the basic behavior of the microcontroller before the program starts running.

They allow you to configure fundamental PIC functions, such as:

- Clock/oscillator source: INTOSC, XT, HS, LP, EC.
- Watchdog Timer (WDT) enabled or disabled.
- Brown-Out Reset (BOR) enabled or disabled.
- MCLR configured as an external reset or as a digital pin.
- Code Protection.
- Power-Up Timer (PWRT).

**Operation**:

- Fuses are read when the microcontroller is powered on or reset.
- They operate independently of the program.
- They are configured when the PIC is programmed, not during normal execution.
- They are defined in the programmer (PICkit), in MPLAB, or in the project configuration file. 
- In Aixt and other compilers, they are usually declared as configuration directives.

An incorrect fuse configuration can cause the **PIC to fail to boot**, **be difficult to program**, or **operate at the wrong frequency**.

The most important fuses in a quick guide are: **Oscillator**, **WDT**, and **MCLR**; the others can be found in the complete datasheet on the main page (https://www.microchip.com/).

Example:
```v
Oscillator = INTOSC
WDT = OFF
MCLR = ENABLED
BOR = ON
```

| **Mode** | **Typical Use** |
---------- | ------------------------------------------------------------------------ |
**INTOSC** | Internal 4 MHz oscillator (recommended mode for educational projects). |
**LP** | Very low frequency crystals (low power consumption). |
**XT** | Standard crystals (mid-range frequencies). |
**HS** | High-speed crystals (up to 20 MHz). |
**EC** | External digital clock source. |

## Reset and WDT Modes

It is important to note that:
- **POR** and **BOR** operate automatically and do not require coding.
- **MCLR** depends on the configuration of the corresponding fuse.
- The **WDT** can be enabled or disabled using fuses.
- In **SLEEP** mode, power consumption is extremely low, and the WDT can be used as a wake-up timer.

| **Mode / Register** | **Function** | **Description / Basic Use** |
| ------------------------- | ----------------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
**POR (Power-On Reset)** | Power-On Reset | Automatically activates when the PIC receives power. Ensures the microcontroller starts in a stable state. |
**MCLR (External Reset)** | RA3/MCLR | Pulling MCLR low resets the PIC. Useful for debugging or reset buttons. |
**BOR (Brown-Out Reset)** | Undervoltage Protection | Resets the PIC if VDD falls below a critical threshold. Prevents unstable operation due to low voltage. |
**WDT (Watchdog Timer)** | Time Exceedance Reset | Resets the PIC if the program freezes or takes too long to execute. Requires periodic **CLRWDT** instructions. |
**WDT Prescaler** | WDT Time Control | Allows adjusting the WDT wait time using a prescaler (configurable via fuses). |
**SLEEP** | Low Power Mode | The PIC enters low power consumption mode; exits via interrupts or WDT. |

## Example, using pins

```v
import pin
import port
import time

// Pin configuration
pin.setup(pin.a0, pin.output) // RA0 as output
pin.setup(pin.a1, pin.input) // RA1 as input
pin.setup(pin.c3, pin.output) // RC3 as output

// Turning a pin on and off
pin.high(pin.a0) // Sets RA0 to high
time.sleep_ms(500)
pin.low(pin.a0) // Sets RA0 to low

// Toggling a pin
pin.toggle(pin.c3) // Changes the state of RC3

// Reading an input pin
value := pin.read(pin.a1) // Reads the logic state of RA1

// Echo: copy input to output
pin.write(pin.c3, value) // RC3 takes the value read from RA1
```