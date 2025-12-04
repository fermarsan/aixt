# Quick Guide to PIC16F676
## Reference PIC16 microcontroller by MICROCHIP
- PIC16F676

**NOTE:** A quick guide does **NOT** replace the **datasheet** — it only includes the essential information affecting configuration, pin usage, **ADC**, basic peripherals, and important startup values.

## Pin Naming

Pin names consist of a letter indicating the port and a number indicating the pin. For example, **c1** means pin **1** of port **c**. All Aixt pin names are lowercase according to the  [V language variable naming rules](https://github.com/vlang/v/blob/master/doc/docs.md#variables).

These pins can function as digital inputs or outputs, analog inputs for the **ADC**, or perform special functions such as clock, interrupt, or comparator functions. Understanding this nomenclature allows you to correctly configure each pin and take full advantage of the microcontroller's capabilities without conflicts between its digital and analog functions.

| Port | 0    | 1    | 2    | 3    | 4    | 5    | 6 | 7 |
|:----:|------|------|------|------|------|------|---|---|
| **A** | `a0` | `a1` | `a2` | `a3` | `a4` | `a5` | - | - |
| **C** | `c0` | `c1` | `c2` | `c3` | `c4` | `c5` | - | - |

![Pinout](image.png) Source: https://ww1.microchip.com/downloads/aemDocuments/documents/MCU08/ProductDocuments/DataSheets/40039F.pdf

## Characteristics

| Feature | Value |
|---------|-------|
| Program memory size (KB) | 1.75 |
| RAM | 64 |
| EEPROM (bytes)| 128 |
| Pin count | 14 |
| Max operating voltage | 5.5 V |
| Min operating voltage | 2.0 V |

Source:https://www.microchip.com/en-us/product/pic16f676

## Main Specifications

| **Category**              | **Specification**                                   |
|--------------------------|-----------------------------------------------------|
| **Architecture**         | 8-bit Mid-Range RISC (35 instructions)              |
| **Flash Memory**         | 1K program words                                    |
| **RAM**                  | 64 bytes                                            |
| **EEPROM**               | 128 bytes                                           |
| **I/O Ports**            | 12 digital pins (RA0–RA5, RC0–RC5)                  |
| **ADC Channels**         | 8 analog channels, 10-bit resolution                |
| **Comparator**           | 1 analog comparator                                 |
| **Timers**               | Timer0 (8-bit), Timer1 (16-bit)                     |
| **Internal Oscillator**  | 4 MHz calibrated (OSCCAL)                           |
| **Operating Voltage**    | 2.0 V to 5.5 V                                      |
| **Power Consumption**    | Low power with Sleep mode                           |
| **Interrupts**           | INT, Timer0, Timer1, ADC, IOC                       |
| **Programming**          | ICSP® (In-Circuit Serial Programming)               |
| **External Clock**       | OSC1/OSC2 available                                 |

## General Configuration

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

pin.digital() // Set all pins to digital mode (ANSEL = 0, CMCON = 0x07)

port.setup(port.a, 0b000000)   // Port A as outputs
port.setup(port.c, 0b000011)   // RC0 & RC1 inputs, others outputs

adc.setup()          // Initialize ADC
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

## Key Records Table (TRIS, PORT, ANSEL, ADCON)

| **Register**           | **Function**         | **Description**                                  |
| ---------------------- | -------------------- | ------------------------------------------------ |
| **TRIS** (TRISA/TRISC) | Pin direction        | 1 = Input, 0 = Output.                           |
| **PORT** (PORTA/PORTC) | Read/write pins      | Inputs read, outputs write according to TRIS.    |
| **ANSEL**              | Analog configuration | Enables ADC channels. 1 = Analog, 0 = Digital.   |
| **ADCON0**             | ADC control          | Enables ADC, selects channel, starts conversion. |
| **ADCON1**             | ADC configuration    | References, ADC clock, justification.            |

## Timer0 and Timer1

| **Timer**  | **Registers**                             | **Function** | **Description**                                                          |
| ---------- | ----------------------------------------- | ------------ | ------------------------------------------------------------------------ |
| **Timer0** | `OPTION_REG`, `INTCON` (T0IF, T0IE)       | 8-bit timer  | Internal clock or RA2/T0CKI, prescaler 1:2–1:256, interrupt on overflow. |
| **Timer1** | `T1CON`, `PIR1 (TMR1IF)`, `PIE1 (TMR1IE)` | 16-bit timer | Internal/external clock (T1CKI), prescaler 1:1–1:8, overflow interrupt.  |

## Interrupts (INTCON, IOCA, PIE1, PIR1)

| **Register** | **Function**                 | **Description**                                       |
| ------------ | ---------------------------- | ----------------------------------------------------- |
| **INTCON**   | Core interrupt controller    | Includes GIE, PEIE, Timer0, INT, and RA-change flags. |
| **IOCA**     | Interrupt-on-change          | Triggers on RA pin state change.                      |
| **PIE1**     | Peripheral interrupt enables | Enables Timer1, ADC, comparator interrupts.           |
| **PIR1**     | Peripheral interrupt flags   | Shows which peripheral generated the interrupt.       |

## Oscillator Configuration

| Component / Register   | Function               | Description                                                           |
| ---------------------- | ---------------------- | --------------------------------------------------------------------- |
| **OSCCAL**             | Oscillator calibration | Adjusts internal 4 MHz oscillator (factory value).                    |
| **Oscillator Mode**    | Config bits (fuses)    | INTOSC, LP, XT, HS, EC. INTOSC (4 MHz) is common.                     |
| **OSC1/CLKIN (RA5)**   | External clock input   | Used when external crystal/clock is selected.                         |
| **OSC2/CLKOUT (RA4)**  | Clock output           | Outputs system clock in external modes; digital/AN3 in internal mode. |
| **Internal Frequency** | 4 MHz                  | Default operating frequency.                                          |

## Reset and WDT Modes

| Mode / Register | Function        | Description                                   |
| --------------- | --------------- | --------------------------------------------- |
| **POR**         | Power-On Reset  | Ensures stable startup when power is applied. |
| **MCLR**        | External reset  | RA3/MCLR low resets the PIC.                  |
| **BOR**         | Brown-Out Reset | Resets on low voltage.                        |
| **WDT**         | Watchdog Timer  | Resets if software freezes (requires CLRWDT). |
| **WDTCON**      | WDT control     | Enables/disables WDT, prescaler.              |
| **PCON**        | Reset cause     | Indicates last reset event.                   |
| **SLEEP**       | Low-power mode  | Wakes on interrupt or WDT.                    |

## Example, use of pins

```v
pin.high(pin.a0) // Write to pins
pin.low(pin.c3)

pin.toggle(pin.a2) // Toggle pin

value := pin.read(pin.c0) // Read pin

pin.write(pin.a0, pin.read(pin.c0)) // Echo (input → output)
```

## Example of ADC

```v
adc_val := adc.read(0)

if adc_val > 512 {
    pin.high(pin.c3)
} else {
    pin.low(pin.c3)
}
```

## Example of time

```v
time.sleep_ms(500)
```