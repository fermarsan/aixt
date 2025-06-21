# Supported devices and boards

All the supported devices implement these modules:
- `time`: Delay functions
- `pin`: GPIO
- `adc`: ADC inputs
- `pwm`: PWM outputs
- `uart`: serial port

Some other devices like PIC16F (xc8 compiler) and Atmel AVR (arduino-cli) support pin-port management module:
- `port`: GPIO as multi-bit port

The modules for hardware timers managment are available for PIC16F (xc8 compiler) and STM32 (arduino-cli):
- `timer0` Timer 0
- `timer1` Timer 1
- ...

The external interrupts module is available for PIC16F (xc8 compiler), Atmel AVR (arduino-cli) and STM32 (arduino-cli):
- `ext` External interrupts

## Devices supported on C backend

| Aixt port name    | C compiler            | Board                         | Device                | CPU                               |
|-------------------|-----------------------|-------------------------------|-----------------------|-----------------------------------|
| Emulator          | GCC or TCC            | Linux, Android and Windows    | Emulator CLI          | x64 or AArch64                    |
| PIC16F8x          | xc8                   | ---                           | PIC16F8x family       | PIC16                             |
| PIC16F87x         | xc8                   | ---                           | PIC16F87x family      | PIC16                             |
| PIC16F88x         | xc8                   | ---                           | PIC16F88x family      | PIC16                             |
| CY8CKIT-049-42xx  | PSoC Creator          | CY8CKIT-049-42xx              | CY8C4245AXI-483       | Cortex-M0                         |
| CY8CKIT-145-40xx  | PSoC Creator          | CY8CKIT-145-40xx              | CY8C4045AZI-S413      | Cortex-M0                         |
<!-- | CH573F-mini-BLE   | MounRiver Studio II   | CH573F Core Board             | CH573F                | RV32                              |
| CH582F-mini-BLE   | MounRiver Studio II   | CH582F Core Board             | CH582F                | RV32                              |
| PIC16F6xx         | xc8                   | ---                           | PIC16F6xx family      | PIC16                             |
| PIC18F452         | xc8                   | ---                           | PIC18F452             | PIC18                             |
| PIC18F2550        | xc8                   | ---                           | PIC18F2550            | PIC18                             |
| PIC18F4550        | xc8                   | ---                           | PIC18F4550            | PIC18                             |
| Exp16-PIC24       | xc16                  | Explorer 16                   | PIC24FJ128GA010       | PIC33                             | 
| Exp16-dsPIC33     | xc16                  | Explorer 16                   | dsPIC33FJ256GP710A    | dsPIC33                           |
| M0sense           | Boufalolab SDK        | Sipeed M0sense                | BL702                 | RV32                              | -->


| Aixt port name    | Implemented modules                                   |
|-------------------|-------------------------------------------------------|
| Emulator          | `time`, `pin`, `adc`, `pwm`, `uart`                   |
| PIC16F8x          | `time`, `pin`, `port`, `timer0`, `ext`                |
| PIC16F87x         | `time`, `pin`, `port`, `timer0`, `ext`                |
| PIC16F88x         | `time`, `pin`, `port`, `adc`, `uart`, `timer0`, `ext` |
| CY8CKIT-049-42xx  | `time`, `pin`, `adc`, `pwm`                           |
| CY8CKIT-145-40xx  | `time`, `pin`, `adc`, `pwm`                           |
<!-- | CH573F-mini-BLE   | `time`, `pin`, `adc`, `pwm`, `uart`                   |
| CH582F-mini-BLE   | `time`, `pin`, `adc`, `pwm`, `uart`                   |
| PIC16F6xx         | `time`, `pin`, `port`, `timer0`, `ext`                |
| PIC18F452         | WIP...                                                |
| PIC18F2550        | WIP...                                                |
| PIC18F4550        | WIP...                                                |
| Exp16-PIC24       | WIP...                                                | 
| Exp16-dsPIC33     | WIP...                                                |
| M0sense           | WIP...                                                | -->

## Devices supported on NXT backend
This backend is designed for supporting LEGO Mindstorms NXT Intelligent Brick.  

| Aixt port name    | C compiler    | Board                 | Device        | CPU       |
|-------------------|---------------|-----------------------|---------------|-----------|
| NXT               | nbc           | NXT Intelligent Brick | AT91SAM7S256  | ARM7TDMI  |


| Aixt port name    | Implemented modules                                       |
|-------------------|-----------------------------------------------------------|
| NXT               | `time`, `motor`, `sensor`, `button`, `lcd`, `ht_sens`,    |
|                   | `task`, `array`, `math`, `rand`, `str`, `sound`, `comm`,  |
|                   | `file`, `i2c`, `io`, `lowspeed`, `ui`                     |
  
## Devices supported on Arduino backend

| Aixt port name        | Compiler      | Board                         | Device                | CPU                   |
|-----------------------|---------------|-------------------------------|-----------------------|-----------------------|
| Arduino-Uno           | arduino-cli   | Arduino Uno                   | ATmega328p            | AVR 8-bit             |
| Arduino-Nano          | arduino-cli   | Arduino Nano                  | ATmega328p            | AVR 8-bit             |
| Arduino-Mega          | arduino-cli   | Arduino Mega                  | ATmega2560            | AVR 8-bit             |        
| ESP32-DevKitC         | arduino-cli   | ESP32 DEVKITV1                | ESP32                 | LX6                   |  
| ESP32-C3-CORE         | arduino-cli   | CORE-ESP32                    | ESP32-C3              | RV32                  |  
| ESP32-C3FH4           | arduino-cli   | ESP32-C3FH4 Core Board        | ESP32-C3              | RV32                  |  
| XIAO-SAMD21           | arduino-cli   | XIAO SAMD21                   | ATSAMD21G18           | Cortex-M0+            |    
| XIAO-ESP32-xx         | arduino-cli   | XIAO ESP32-xx                 | ESP8266               | LX106                 |  
| Blue-Pill             | arduino-cli   | Blue Pill                     | STM32F103C6           | Cortex-M3             |  
| RP-Pico               | arduino-cli   | Raspberry Pi Pico             | RP2040                | Dual Cortex-M0+       |   
| Ai-WB2-32S-Kit        | arduino-cli   | Ai-WB2-32S-Kit                | BL602                 | RV32                  | 
| STM32G431Core         | arduino-cli   | STM32G431CBU6 Core Board      | STM32G431CBU6         | Cortex-M4F            |
<!-- | LQFP32-MiniEVB        | arduino-cli   | LQFP32 MiniEVB                | lgt8f328p             | AVR 8-bit compatible  |  
| AIR32F103             | arduino-cli   | CORE-Air32F103CBT6            | air32f103             | Cortex-M3             | 
| RP-Pico-W             | arduino-cli   | Raspberry Pi Pico W           | RP2040                | Dual Cortex-M0+       | 
| NodeMCU-V3-Lua        | arduino-cli   | NodeMCU V3 Lua                | ESP8266               | LX106                 | 
| ATtiny85-Kickstart    | arduino-cli   | Digispark Kickstart           | ATtiny85              | AVR 8-bit             |
| MH-ATtiny88           | arduino-cli   | MH-Tiny                       | ATtiny88              | AVR 8-bit             |  
| ESP32-D1              | arduino-cli   | D1 R32                        | ESP32                 | LX6                   |  
| T-WATCH-2020          | arduino-cli   | T-Watch 2020 V1               | ESP32                 | LX6                   | 
| Black-Pill            | arduino-cli   | Black Pill                    | STM32F411CEU6         | Cortex-M4             | 
| Black-Pill2           | arduino-cli   | Black Pill                    | AT32F403ACGU7         | Cortex-M4             |
| CH552-core            | arduino-cli   | CH552 Core Board              | CH552                 | E8051                 |
| CH552-core-WeAct      | arduino-cli   | CH552 Core Board WeAct Studio | CH552                 | E8051                 |
| CH32V103R8T6-EVT-R1   | arduino-cli   | CH32V103R8T6-EVT-R1 Ev. Board | CH32V103R8T6          | RV32                  |
| CH32V003-Dev-Board    | arduino-cli   | CH32V003 Dev Board            | CH32V003F4U6          | RV32                  |
| CH32V203-Dev-Board    | arduino-cli   | CH32V203 Dev Board            | CH32V203C8T6          | RV32                  | 
| CH32V305-Dev-Board    | arduino-cli   | CH32V305 Dev Board            | CH32V305RBT6          | RV32                  | 
| W801                  | arduino-cli   | HLK-W801-KIT-V1.1             | W801-C400             | XT804                 | -->


| Aixt port name        | Implemented modules                                   |
|-----------------------|-------------------------------------------------------|
| Arduino-Uno           | `time`, `pin`, `port`, `adc`, `pwm`, `uart`, `ext`    |
| Arduino-Nano          | `time`, `pin`, `port`, `adc`, `pwm`, `uart`, `ext`    |
| Arduino-Mega          | `time`, `pin`, `port`, `adc`, `pwm`, `uart`, `ext`    |        
| ESP32-DevKitC         | `time`, `pin`, `adc`, `pwm`, `uart`,                  |  
| ESP32-C3-CORE         | `time`, `pin`, `adc`, `pwm`, `uart`,                  |  
| ESP32-C3FH4           | `time`, `pin`, `adc`, `pwm`, `uart`,                  |  
| XIAO-SAMD21           | `time`, `pin`, `adc`, `pwm`, `uart`,                  |    
| XIAO-ESP32-C3         | `time`, `pin`, `adc`, `pwm`, `uart`,                  |  
| Blue-Pill             | `time`, `pin`, `adc`, `pwm`, `uart`,                  |  
| RP-Pico               | `time`, `pin`, `adc`, `pwm`, `uart`,                  |   
| Ai-WB2-32S-Kit        | `time`, `pin`, `adc`, `pwm`, `uart`,                  | 
| STM32G431Core         | `time`, `pin`, `adc`, `pwm`, `uart`, `timer1`, `ext`  |
<!-- | LQFP32-MiniEVB        | `time`, `pin`, `port`, `adc`, `pwm`, `uart`, `ext`    |  
| AIR32F103             | `time`, `pin`, `adc`, `pwm`, `uart`,                  | 
| RP-Pico-W             | `time`, `pin`, `adc`, `pwm`, `uart`,                  | 
| NodeMCU-V3-Lua        | `time`, `pin`, `port`, `adc`, `pwm`, `uart`,          | 
| ATtiny85-Kickstart    | WIP...                                                |
| MH-ATtiny88           | WIP...                                                |  
| ESP32-D1              | WIP...                                                |  
| T-WATCH-2020          | WIP...                                                | 
| Black-Pill            | WIP...                                                | 
| Black-Pill2           | WIP...                                                |
| CH552-core            | WIP...                                                |
| CH552-core-WeAct      | WIP...                                                |
| CH32V103R8T6-EVT-R1   | WIP...                                                |
| CH32V003-Dev-Board    | WIP...                                                |
| CH32V203-Dev-Board    | WIP...                                                | 
| CH32V305-Dev-Board    | WIP...                                                | 
| W801                  | WIP...                                                | -->