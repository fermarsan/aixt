# Quick reference for the Arduino Nano board

Quick reference for the Microchip PIC16F8x devices:
- PIC16F83
- PIC16F84
- PIC16F84A

**NOTE:** This PIC16F8x microcontrollers only has digital outputs and digital inputs

## General $\mu C$ control

```v
// by default the CPU oscillation frequency is 10Mhz
@[as_macro] const cpu_freq = 4_000_000  // change it to 4Mhz
```