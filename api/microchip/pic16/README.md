## Description

`pic16` is not a module by itself, but a namespace for the API modules of Microchip PIC16 target devices. Some of functions are shared by most of targets. The API for the PIC16 includes the core modules and the additional ones.


### PIC16-core modules

- [pin_fn](microchip.pic16.pin_fn.html) for the pin management.
- [pin_fast](microchip.pic16.pin_fast.html) for the pin management (faster version).
- [port](microchip.pic16.port.html) for the pin port management.
- [timer0](microchip.pic16.timer0.html) for the timer0.
- [ext](microchip.pic16.ext.html) for the external interrupt through RB0/INT pin.
- [extb](microchip.pic16.extb.html) for the external interrupt by changes on RB7-RB4 pins.


### PIC16 additional modules

- [pwm](microchip.pic16_pwm.pwm.html) for the pin management.
- [uart](microchip.pic16_uart.uart.html) serial port.
- [enhanced uart](microchip.pic16_euart.uart.html) enhanced serial port.
- [timer1](microchip.pic16_timer1.timer1.html) for the timer1.
- [timer2](microchip.pic16_timer2.timer2.html) for the timer2.


### Supported target devices
  
PIC16F6xx_14p:

  - PIC16F630
  - PIC16F676
  - PIC16F684
  
PIC16F6xx_18p:

  - PIC16F627(A)
  - PIC16F628(A)
  - PIC16F648A
  - PIC16LF627A
  - PIC16LF628A
  - PIC16LF648A

PIC16F6xx_20p:

  - PIC16F685
  - PIC16F687
  - PIC16F689
  - PIC16F690

PIC16F8x:

  - PIC16F83
  - PIC16F84(A)

PIC16F87x:

  - PIC16F873(A)
  - PIC16F874(A)
  - PIC16F876(A)
  - PIC16F877(A)
  
PIC16F88x: 

  - PIC16F882
  - PIC16F883
  - PIC16F884
  - PIC16F886
  - PIC16F887
