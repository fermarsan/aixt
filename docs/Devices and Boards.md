# Supported devices and boards

All the supported devices implement these modules:
- `time`: Delay functions
- `pin`: GPIO
- `adc`: ADC inputs
- `pwm`: PWM outputs
- `uart`: serial port

Some other devices like PIC16F and AT support pin-port management:
- `port`: GPIO as multi-bit port

## Emulator for Linux, Android (Termux) and Windows
- **_x64-based or AArch64-based device_**: x64 or AArch64 

## LEGO Mindstorms NXT
- **_NXT Intelligent Brick_**: AT91SAM7S256 (ARM7TDMI) "_nxc_ backend" 
  
## Microchip

For XC8 compiler:
- **8-bit 16F family**
    - PIC16F8x family   **_(only `time`, `pin`, `port`)_**
    - PIC16F628A    **_(WIP...)_**
    - PIC16F676     **_(only `time`, `pin`, `adc`, `port`)._**
    - PIC16F873A    
    - PIC16F886     
- **8-bit 18F family**
    - PIC18F452     
    - PIC18F2550     
- **_Explorer 16_**: PIC18F4550 **_(WIP...)_**

For XC16 compiler:
- **_Explorer 16_**: PIC24FJ128GA010 
- **_Explorer 16_**: dsPIC33FJ256GP710A **_(WIP...)_**

## Atmel (Microchip)
- **_Digispark Kickstarter_**: ATtiny85 "_arduino_ backend" **_(WIP...)_** 
- **_MH-Tiny_**: ATtiny88 "_arduino_ backend" 
- **_Arduino Uno_**: ATmega328p "_arduino_ backend"   
- **_Arduino Nano_**: ATmega328p "_arduino_ backend"  

## Seeed Studio
- **_Seeed Studio XIAO SAMD21_**: ATSAMD21G18 (Cortex-M0+) "_arduino_ backend" 

## Cypress
For PSoC Creator:
- **PSoC 3**
    - **_CY8CKIT-001 + (009)_**: CY8C3866AXI-040 (8051) **_(WIP...)_**
- **PSoC 4**
  - **_CY8CKIT-049-42xx_**: CY8C4245AXI-483 (Cortex-M0) **_(WIP...)_**
  - **_CY8CKIT-145-40xx_**: CY8C4045AZI-S413 (Cortex-M0) **_(WIP...)_**
- **PSoC 5LP**
    - **_CY8CKIT-059_**: CY8C5888LTI-LP097 (Cortex-M3) **_(WIP...)_**

## LogicGreen 
- **_LQFP32 MiniEVB_**: lgt8f328p "_arduino_ backend"

## Espressif
- **ESP8266**
    - **_NodeMCU V3 Lua_**: ESP8266 (LX106) "_arduino_ backend" 
- **ESP32**
    - **_ESP32 DEVKITV1_**: ESP32 (LX6) "_arduino_ backend" **_(WIP...)_**
    - **_D1 R32_**: ESP32 (LX6) "_arduino_ backend" _(WIP...)_**
    - **_CORE-ESP32_**: ESP32-C3 (RV32) "_arduino_ backend" **_(WIP...)_**
    - **_ESP32-C3FH4 Core Board (WeAct Studio)_**: ESP32-C3 (RV32) "_arduino_ backend" 
    - **_LILYGO T-Watch 2020 V1_**: ESP32 (LX6) "_arduino_ backend" **_(WIP...)_**  

## ST
- **_Blue Pill_**: STM32F103C6 (Cortex-M3) "_arduino_ backend" 
- **_STM32G431CBU6 Core Board_**: STM32G431CBU6 (Cortex-M4F) "_arduino_ backend" **_(WIP...)_**

## LuatOS
- **_CORE-Air32F103CBT6_**: air32f103 (Cortex-M3) "_arduino_ backend" 

## Artery
- **_Black Pill_**: AT32F403ACGU7 (Cortex-M4) "_arduino_ backend" **_(WIP...)_**

## Raspberry Pi
- **_Raspberry Pi Pico_**: RP2040 (Dual Cortex-M0+) "_arduino_ backend" 
- **_Raspberry Pi Pico W_**: RP2040 (Dual Cortex-M0+) "_arduino_ backend" 

## WCH
- **_CH552 Core Board_**: CH552 (E8051) **_(WIP...)_**
- **_CH552 Core Board (WeAct Studio)_**: CH552 (E8051) **_(WIP...)_**
- **_CH573F Core Board_**: CH573F (RV32) **_(WIP...)_**
- **_CH582F Core Board_**: CH582F (RV32) **_(WIP...)_**
- **_CH32V103R8T6-EVT-R1 Evaluation Board_**: CH32V103R8T6 (RV32) **_(WIP...)_**
- **_CH32V003 Development Board_**: CH32V003F4U6 (RV32) **_(WIP...)_**
- **_CH32V203 Development Board_**: CH32V203C8T6 (RV32) **_(WIP...)_** 
- **_CH32V305 Development Board_**: CH32V305RBT6 (RV32) **_(WIP...)_** 

## WinnerMicro
- **_HLK-W801-KIT-V1.1_**: W801-C400 (XT804) "_arduino_ backend" **_(WIP...)_**

## Sipeed
- **_Sipeed M0sense_**: BL702 (RV32) "_arduino_ backend" **_(WIP...)_**

## Ai-Thinker
- **_Ai-WB2-32S-Kit_**: BL602 "_arduino_ backend" **_(only `time`, `pin`, `pwm`, `uart`)_**


# Devices updated API v0.1.2

- Software Emulator for Linux, Android (Termux) and Windows     _(GCC-TCC)_
- PIC16F8x family: PIC16F83, PIC16F83A, PIC16F84, PIC16F84A     _(XC8)_
- Arduino Uno         _(arduino-cli)_
- Arduino Nano        _(arduino-cli)_
- ESP32-DevKitC       _(arduino-cli)_
- Raspberry Pi Pico   _(arduino-cli)_