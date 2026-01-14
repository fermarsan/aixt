#  QUICK GUIDE ESP32-C3FH4

This is an Aixt implementation to provide support for the ESP32-C3FH4 board.

## SUMMARY

* The ESP32C3FH4 by WeAct Studio is a development board based on the ESP32-C3FH4 microcontroller from Espressif Systems. This microcontroller is part of the ESP32 family from Espressif, known for its low-power Wi-Fi and Bluetooth connectivity.

* The ESP32-C3FH4 is a low-cost, low-power microcontroller. It is based on a 32-bit RISC-V processor architecture and features dual-mode Wi-Fi connectivity and integrated Bluetooth technology.

* WeAct Studio is a manufacturer of development boards and electronic modules. The ESP32C3FH4 development board from WeAct Studio provides a convenient environment for working with the ESP32-C3FH4 microcontroller. It typically includes features such as input/output ports, antenna connectors, programming interfaces, and debugging capabilities, among others. 

## FUNCTION
* The functions of the ESP32C3FH4 from WeAct Studio are determined both by the capabilities of the ESP32-C3FH4 microcontroller and by the additional features provided by the WeAct Studio development board.

* The ESP32C3FH4 can utilize its analog and digital input pins to connect a variety of sensors, such as temperature, humidity, light, motion sensors, etc. This allows the creation of IoT devices that can collect data from the environment. In addition to reading sensor data, the ESP32C3FH4 can control output devices such as motors, relays, lights, among others. This enables system automation and the creation of interactive devices.

* The ESP32C3FH4 can communicate with other devices through serial ports, such as UART, SPI, and I2C. This allows integration with a wide variety of devices and peripherals.

* The ESP32-C3FH4 microcontroller offers integrated security features, such as data encryption and authentication, which are important for security-sensitive applications such as access control systems and medical devices.

* With low power consumption, ESP32-C3FH4 is an ideal choice for IoT (internet of thing) devices in the following areas; smart homes, industrial automation, healthcare, consumer electronics, smart agriculture, POS machines, service robots, audio devices, low-power IoT data loggers, low-power IoT sensor hubs.

## SPECS

* 32-bit RIsC-V single-core processor, up to 160Mhz.
* CoreMark score: 
	* 1 core at 160MHz: 407.22 CoreMark; 2.55 CoreMark/MHz.
* 384 KB ROM.
* 400 KB SRAM (16 KB for cache).
* 8 KB SRAM in RTC. 
* Embedded flash.
* SPI, Dual SPI, Quad SPI and QPI interfaces that allow connection to multiple flash. 
* Supports flash in.Circuit Programming (ICP).
* Digital interfaces: 
	* 3 x SPI.
	* 2 x UART.
	* 1 x I2C.
	* 1 x I2S.
	* Remote control peripheral, with 2 transmit channels and 2 receive channels. 
	* LED PWM controller, with up to 6 channels. 
	* Full-speed USB Serial/JTAG controller. 
	* General DMA controller (GDMA), with 3 transmit channels and 3 receive channels.
* Analog intefaces: 
	* 2 x 12-bit SAR ADCs, up to 6 channels. 
* Timers: 
	* 2 x 54-bit general-purpose timers.
	* 3 x digital watchdog timers. 
	* 1 x analog watchdog timer.
	* 1 x 52-bit system timer. 

	## WiFI

	* Supports 20 MHz, 40 MHz bandwidth in 2.4 GHz band.
	* 1T1R mode with data rate up to 150 Mbps. 
	* 4 x virtual Wi-Fi interfaces. 

	## Bluetooth

	* Bluetooth LE: Bluetooth 5, Bluetooth mesh. 
	* High power mode (21 dBm).
	* Speed: 125 Kbps, 500 Kbps, 1 Mbps, 2Mbps. 
	* Internal co-existence mechanism between Wi-Fi and Bluetooth to share the same antena. 


## DATASHEET

[ESP32-C3_Series](https://www.espressif.com/sites/default/files/documentation/esp32-c3_datasheet_en.pdf)

## PIN IDENTIFICATION 

![Alt text](Picture/WeAct-Studio-ESP32.jpg) 

| Pin No. | Name                              | Function                                                                                                                     |
| ------- | --------------------------------- | ---------------------------------------------------------------------------------------------------------------------------- |
| 0       | GPIO0; ADC1_0; XTAL_32K_P         | Analog; Digital;                                                                                                             |
| 1       | GPIO1; ADC1_1; XTAL_32K_N         | Analog; Digital;                                                                                                             |
| 2       | GPIO2; ADC1_2; FSPIQ; BOOT        | Analog; Digital; Fast Serial Peripheral Interface Quad-SPI; Booting.                                                         |
| 3       | GPIO3; ADC1_3;                    | Analog; Digital.                                                                                                             |
| 4       | GPIO4; ADC1_4; FSPHID; SCK; MTMS  | Analog; Digital; Full-Speed USB Human Interface Device; Serial Clock; Multi-Track Memory System.                             |
| 5       | GPI05; ADC2_0; FSPIWP; MISO; MTDI | Analog; Digital; Full-Speed Serial Peripheral Interface Write Protect; Master In Slave Out; Microcontroller Test Data Input. |
| 6       | GPIO6; FSPICLK; MOSI; MTCK        | Digital; Full-Speed Serial Peripheral Interface Clock; Master Out Slave In; Microcontroller Test Clock.                      |
| 7       | GPI07; FSPID; SS; MTDO            | Digital; Full-Speed Serial Peripheral Interface Data; Slave Select; Microcontoller Test Data Output.                         |
| 8       | GPIO8; SDA; LOG; BULTIN LED       | Digital; Serial Data; Builtin LED.                                                                                           |
| 9       | GPIO9; SCL; BOOT                  | Digital; Serial Clock Line; Booting.                                                                                         |
| 10      | GPIO10; FSPICSO; JTAG             | Digital; Full-Speed Serial Peripheral Interface Chip Select Output; Joint Test Action Group.                                 |
| 18      | GPIO18; USB_D+                    | Digital; USB Conecction Dp.                                                                                                  |
| 19      | GPI019; USB_D-                    | Digital; USB Conecction Dn.                                                                                                  |
| 21      | GPIO21; RXD 0                     | Digital; Serial Communication (Receiver)                                                                                     |
| 22      | GPIO22; TXD 0                     | Digital; Serial Communication (Transmitter)                                                                                  |
|         | 5v                                | Board Power Supply                                                                                                           |
|         | VB                                | Voltage Boost                                                                                                                |
|         | GND                               | Ground                                                                                                                       |
|         | GND                               | Ground                                                                                                                       |
|         | GND                               | Ground                                                                                                                       |
|         | GND                               | Ground                                                                                                                       |
|         | 3.3v                              | Microcontroller Power Supply                                                                                                 |
|         | 3.3v                              | Microcontroller Power Supply                                                                                                 |
|         | EN                                | Enable                                                                                                                       |


## PROGRAMMING IN V LENGUAJE

| Name                      | Description                                    |
| ------------------------- | ---------------------------------------------- |
| `pin.setup(pin, mode)`    | Configure `pin` as `mode` (input, out)         |
| `pin.high(pin)`           | Digital output high `pin`                      |
| `pin.low(pin)`            | Digital output low `pin`                       |
| `pin.write(pin, val)`     | Write `val` to `pin`                           |
| `pin.read(pin)`           | Digital read `pin`                             |
| `adc.read(pin)`           | Analog read `pin` for `adc`                    |
| `pwm.write(pin, val)`     | PWM output `pin` with duty cycle `val`         |
| `uart.setup(baud_rate)`   | Serial Communication initiation at `Baud_rate` |
| `uart_any()`              | Get the number of byte to read                 |
| `uart.read()`             | Serial Communication read                      |
| `uart.println("message")` | Print `message` through Serial Communication   |
| `time.sleep(time)`        | Time delay in `sec`                            |
| `time.sleep_us(time)`     | Time delay in `microsec`                       |
| `time.sleep_ms(time)`     | Time delay in `milisec`                        |

* Description and compilation example on YouTube: https://youtu.be/dbCGMkhsr1E 

## EXAMPLES

  Examples for transcompilation to C language, from AIXT

### BLINKING

```v
	import time { sleep_ms }  			// Import the time module
	import pin 						 	// Import the pin module 

	pin.setup(1, pin.output)  			// Set pin #1 as output

	for {
		pin.high(1)  					// Output High
		time.sleep_ms(1000)  				// Delay for 1s
		pin.low(1)  					// Output Low 
		time.sleep_ms(1000)  				// Delay for 1s 
	}
```

### PWM OUTPUT 

```v
 import time { sleep_ms }
import pin
import pwm

__global (
  val1 = 0
  val2 = 0 
  val3 = 0 
)

pin.setup(1, pin.output)
pin.setup(4, pin.output)
pin.setup(10, pin.output)

for {
    pwm.write(1, val1)
	pwm.write(4, val2)
	pwm.write(10, val3)
    sleep_ms(500)
    val1=val1+50
	val2=val2+25
	val3=val3+25
    if val1==400 {
		  val1=0  
    }

	if val2 == 150 {
		val2 = 0
	}

	if val3 == 100 {
		val3 = 0
	}
} 
```

### ANALOG READING

```v
import pin                            	  
import adc                            	 
import pwm                            	 

__global (
    volumen = 0                        	 
    )
   
for{                                      
  volumen=adc.read(3)                      
	pwm.write(7,volumen)                   
}
```
### SERIAL COMMUNICATION 

```v
import pin             
import uart            
  
 __global(
 	button=0              
 )

 pin.setup(4, pin.output)
 uart.setup(9600)


for {                   

	if pin.read(4) == 1  
	{ 
		button=button+1 
		uart.print(button)
	}
}
```
