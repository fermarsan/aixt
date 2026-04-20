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


## Devices features


| Nombre en Aixt      | Backend | Compilador de C |
|---------------------|---------|-----------------|
| emulator / emu      | c       | GCC or TCC      |
| nxt                 | nxc     | nbc             |
| pic16f83            | c       | xc8             |
| pic16f84(a)         | c       | xc8             |
| pic16f627           | c       | xc8             |
| pic16f628           | c       | xc8             |
| pic16(l)f627a       | c       | xc8             |
| pic16(l)f628a       | c       | xc8             |
| pic16(l)f648a       | c       | xc8             |
| pic16f873(a)        | c       | xc8             |
| pic16f874(a)        | c       | xc8             |
| pic16f876(a)        | c       | xc8             |
| pic16f877(a)        | c       | xc8             |
| pic16f882           | c       | xc8             |
| pic16f883           | c       | xc8             |
| pic16f884           | c       | xc8             |
| pic16f886           | c       | xc8             |
| pic16f887           | c       | xc8             |
| exp16-pic24         | c       | xc16            |
| cy8ckit-049-42xx    | c       | PSoC Creator    |
| cy8ckit-145-40xx    | c       | PSoC Creator    |
| uno                 | arduino | arduino-cli     |
| nano                | arduino | arduino-cli     |
| mega                | arduino | arduino-cli     |
| esp32-devkitc       | arduino | arduino-cli     |
| esp32-c3-core       | arduino | arduino-cli     |
| esp32-c3fh4         | arduino | arduino-cli     |
| fire                | arduino | arduino-cli     |
| xiao-samd21         | arduino | arduino-cli     |
| xiao-esp32-c3       | arduino | arduino-cli     |
| xiao-esp32-c6       | arduino | arduino-cli     |
| xiao-esp32-s3       | arduino | arduino-cli     |
| blue-pill           | arduino | arduino-cli     |
| nucleo-l031k6       | arduino | arduino-cli     |
| pico                | arduino | arduino-cli     |
| stm32f411core       | arduino | arduino-cli     |
| stm32g431core       | arduino | arduino-cli     |
| ch32v103r8t6-evt-r1 | arduino | arduino-cli     |

| Nombre en Aixt      | Tarjeta de desarrollo         | Dispositivo      | CPU             |
|---------------------|-------------------------------|------------------|-----------------|
| emulator            | Linux, Android and Windows    | Emulator CLI     | x64 or AArch64  |
| nxt                 | NXT Intelligent Brick         | AT91SAM7S256     | ARM7TDMI        |
| pic16f83            | ---                           | PIC16F83         | PIC16           |
| pic16f84(a)         | ---                           | PIC16F84(A)      | PIC16           |
| pic16f627           | ---                           | PIC16F627        | PIC16           |
| pic16f628           | ---                           | PIC16F628        | PIC16           |
| pic16(l)f627a       | ---                           | PIC16(L)F627A    | PIC16           |
| pic16(l)f628a       | ---                           | PIC16(L)F628A    | PIC16           |
| pic16(l)f648a       | ---                           | PIC16(L)F648A    | PIC16           |
| pic16f873(a)        | ---                           | PIC16F873(A)     | PIC16           |
| pic16f874(a)        | ---                           | PIC16F874(A)     | PIC16           |
| pic16f876(a)        | ---                           | PIC16F876(A)     | PIC16           |
| pic16f877(a)        | ---                           | PIC16F877(A)     | PIC16           |
| pic16f882           | ---                           | PIC16F882        | PIC16           |
| pic16f883           | ---                           | PIC16F883        | PIC16           |
| pic16f884           | ---                           | PIC16F884        | PIC16           |
| pic16f886           | ---                           | PIC16F886        | PIC16           |
| pic16f887           | ---                           | PIC16F887        | PIC16           |
| exp16-pic24         | Explorer 16                   | PIC24FJ128GA010  | PIC24           |
| cy8ckit-049-42xx    | CY8CKIT-049-42xx              | CY8C4245AXI-483  | Cortex-M0       |
| cy8ckit-145-40xx    | CY8CKIT-145-40xx              | CY8C4045AZI-S413 | Cortex-M0       |
| arduino-uno         | Arduino Uno                   | ATmega328p       | AVR 8-bit       |
| arduino-nano        | Arduino Nano                  | ATmega328p       | AVR 8-bit       |
| arduino-mega        | Arduino Mega                  | ATmega2560       | AVR 8-bit       |
| esp32-devkitc       | ESP32 DEVKITV1                | ESP32            | LX6             |
| esp32-c3-core       | CORE-ESP32                    | ESP32-C3         | RV32            |
| esp32-c3fh4         | ESP32-C3FH4 Core Board        | ESP32-C3         | RV32            |
| fire                | M5Stack FIRE                  | ESP32            | LX6             |
| xiao-samd21         | XIAO SAMD21                   | ATSAMD21G18      | Cortex-M0+      |
| xiao-esp32-c3       | XIAO-ESP32-C3                 | ESP32-C3         | RV32            |
| xiao-esp32-c6       | XIAO-ESP32-C6                 | ESP32-C6         | RV32            |
| xiao-esp32-s3       | XIAO-ESP32-S3                 | ESP32-S3         | LX6             |
| blue-pill           | Blue Pill                     | STM32F103C6      | Cortex-M3       |
| nucleo-l031k6       | Nucleo-L031K6                 | STM32F031K6T6    | Cortex-M0       |
| rp-pico             | Raspberry Pi Pico             | RP2040           | Dual Cortex-M0+ |
| stm32f411core       | STM32F411CBU6 Core Board      | STM32F411CBU6    | Cortex-M4F      |
| stm32g431core       | STM32G431CBU6 Core Board      | STM32G431CBU6    | Cortex-M4F      |
| ch32v103r8t6-evt-r1 | CH32V103R8T6-EVT-R1 Ev. Board | CH32V103R8T6     | RV32            |

<!-- 
| CH573F-mini-BLE       | c         | MounRiver Studio II   | CH573F Core Board             | CH573F                | RV32                  |
| CH582F-mini-BLE       | c         | MounRiver Studio II   | CH582F Core Board             | CH582F                | RV32                  |
| PIC16F6xx             | c         | xc8                   | ---                           | PIC16F6xx family      | PIC16                 |
| PIC18F452             | c         | xc8                   | ---                           | PIC18F452             | PIC18                 |
| PIC18F2550            | c         | xc8                   | ---                           | PIC18F2550            | PIC18                 |
| PIC18F4550            | c         | xc8                   | ---                           | PIC18F4550            | PIC18                 |
| Exp16-dsPIC33         | c         | xc16                  | Explorer 16                   | dsPIC33FJ256GP710A    | dsPIC33               |
| M0sense               | c         | Boufalolab SDK        | Sipeed M0sense                | BL702                 | RV32                  |
| ESP32-CYD             | arduino   | arduino-cli           | ESP32-CYD                     | ESP32                 | LX6                   | 
| LQFP32-MiniEVB        | arduino   | arduino-cli           | LQFP32 MiniEVB                | lgt8f328p             | AVR 8-bit compatible  |  
| AIR32F103             | arduino   | arduino-cli           | CORE-Air32F103CBT6            | air32f103             | Cortex-M3             | 
| RP-Pico-W             | arduino   | arduino-cli           | Raspberry Pi Pico W           | RP2040                | Dual Cortex-M0+       | 
| NodeMCU-V3-Lua        | arduino   | arduino-cli           | NodeMCU V3 Lua                | ESP8266               | LX106                 | 
| ATtiny85-Kickstart    | arduino   | arduino-cli           | Digispark Kickstart           | ATtiny85              | AVR 8-bit             |
| MH-ATtiny88           | arduino   | arduino-cli           | MH-Tiny                       | ATtiny88              | AVR 8-bit             |  
| ESP32-D1              | arduino   | arduino-cli           | D1 R32                        | ESP32                 | LX6                   |  
| T-WATCH-2020          | arduino   | arduino-cli           | T-Watch 2020 V1               | ESP32                 | LX6                   | 
| Black-Pill            | arduino   | arduino-cli           | Black Pill                    | STM32F411CEU6         | Cortex-M4             | 
| Black-Pill2           | arduino   | arduino-cli           | Black Pill                    | AT32F403ACGU7         | Cortex-M4             |
| CH552-core            | arduino   | arduino-cli           | CH552 Core Board              | CH552                 | E8051                 |
| CH552-core-WeAct      | arduino   | arduino-cli           | CH552 Core Board WeAct Studio | CH552                 | E8051                 |
| CH32V103R8T6-EVT-R1   | arduino   | arduino-cli           | CH32V103R8T6-EVT-R1 Ev. Board | CH32V103R8T6          | RV32                  |
| CH32V003-Dev-Board    | arduino   | arduino-cli           | CH32V003 Dev Board            | CH32V003F4U6          | RV32                  |
| CH32V203-Dev-Board    | arduino   | arduino-cli           | CH32V203 Dev Board            | CH32V203C8T6          | RV32                  | 
| CH32V305-Dev-Board    | arduino   | arduino-cli           | CH32V305 Dev Board            | CH32V305RBT6          | RV32                  | 
| W801                  | arduino   | arduino-cli           | HLK-W801-KIT-V1.1             | W801-C400             | XT804                 | 
| Ai-WB2-32S-Kit        | arduino   | arduino-cli           | Ai-WB2-32S-Kit                | BL602                 | RV32                  |
-->

**NOTE:** parenthesis in device names means optional, for instance `PIC16F84(A)` means that both `PIC16F84` and `PIC16F84A` devices are supported.

## Implemented modules by device

| Aixt port name                                    | Implemented modules                                                  |
| ------------------------------------------------- | -------------------------------------------------------------------- |
| Emulator                                          | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| NXT                                               | `time`, `motor`, `sensor`, `button`, `lcd`, `ht_sens`,               |
|                                                   | `task`, `array`, `math`, `rand`, `str`, `sound`, `comm`,             |
|                                                   | `file`, `i2c`, `io`, `lowspeed`, `ui`                                |
| [PIC16F8x](../setup/equivalent_devices.json)      | `time`, `pin`, `port`, `timer0`, `ext`                               |
| [PIC16F6xx-14p](../setup/equivalent_devices.json) | `time`, `pin`, `port`, `adc`, `timer0`, `ext`                        |
| [PIC16F6xx-18p](../setup/equivalent_devices.json) | `time`, `pin`, `port`, `timer0`, `ext`                               |
| [PIC16F6xx-20p](../setup/equivalent_devices.json) | `time`, `pin`, `port`, `timer0`, `ext`                               |
| [PIC16F87x](../setup/equivalent_devices.json)     | `time`, `pin`, `port`, `timer0`, `ext`                               |
| [PIC16F88x](../setup/equivalent_devices.json)     | `time`, `pin`, `port`, `adc`, `uart`, `timer0`, `ext`                |
| Exp16-PIC24                                       | `time`, `pin`, `port`                                                |
| CY8CKIT-049-42xx                                  | `time`, `pin`, `adc`, `pwm`                                          |
| CY8CKIT-145-40xx                                  | `time`, `pin`, `adc`, `pwm`                                          |
| Arduino-Uno                                       | `time`, `pin`, `port`, `adc`, `pwm`, `uart`, `ext`                   |
| Arduino-Nano                                      | `time`, `pin`, `port`, `adc`, `pwm`, `uart`, `ext`                   |
| Arduino-Mega                                      | `time`, `pin`, `port`, `adc`, `pwm`, `uart`, `ext`                   |
| ESP32-DevKitC                                     | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| ESP32-C3-CORE                                     | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| ESP32-C3FH4                                       | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| FIRE                                              | `time`, `pin`, `adc`, `pwm`, `uart`, `button`, `lcd`, `power`, `imu` |
| XIAO-SAMD21                                       | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| [XIAO-ESP32-xx](../setup/equivalent_devices.json) | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| Blue-Pill                                         | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| Nucleo-L031K6                                     | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| RP-Pico                                           | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| Ai-WB2-32S-Kit                                    | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| STM32G431Core                                     | `time`, `pin`, `adc`, `pwm`, `uart`, `timer1`, `ext`                 |
| STM32G431Core                                     | `time`, `pin`, `adc`, `pwm`, `uart`, `timer1`, `ext`                 |
| CH32V103R8T6-EVT-R1                               | `time`, `pin`, `adc`, `pwm`, `uart`                                  |

<!--                                              

| CH573F-mini-BLE                                   | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| CH582F-mini-BLE                                   | `time`, `pin`, `adc`, `pwm`, `uart`                                  |
| PIC16F6xx                                         | `time`, `pin`, `port`, `timer0`, `ext`                               |
| PIC18F452                                         | WIP...                                                               |
| PIC18F2550                                        | WIP...                                                               |
| PIC18F4550                                        | WIP...                                                               |
| Exp16-dsPIC33                                     | WIP...                                                               |
| M0sense                                           | WIP...                                                               |
| ESP32-CYD                                         | WIP...                                                               |
| LQFP32-MiniEVB                                    | `time`, `pin`, `port`, `adc`, `pwm`, `uart`, `ext`                   |
| AIR32F103                                         | `time`, `pin`, `adc`, `pwm`, `uart`,                                 |
| RP-Pico-W                                         | `time`, `pin`, `adc`, `pwm`, `uart`,                                 |
| NodeMCU-V3-Lua                                    | `time`, `pin`, `port`, `adc`, `pwm`, `uart`,                         |
| ATtiny85-Kickstart                                | WIP...                                                               |
| MH-ATtiny88                                       | WIP...                                                               |
| ESP32-D1                                          | WIP...                                                               |
| T-WATCH-2020                                      | WIP...                                                               |
| Black-Pill                                        | WIP...                                                               |
| Black-Pill2                                       | WIP...                                                               |
| CH552-core                                        | WIP...                                                               |
| CH552-core-WeAct                                  | WIP...                                                               |
| CH32V103R8T6-EVT-R1                               | WIP...                                                               |
| CH32V003-Dev-Board                                | WIP...                                                               |
| CH32V203-Dev-Board                                | WIP...                                                               |
| CH32V305-Dev-Board                                | WIP...                                                               |
| W801                                              | WIP...                                                               | 
-->                                 
