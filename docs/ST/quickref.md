# **Fast guide STM32F103C*
This Aixt implementation that supports the card  Blue Pill STM32F103C

# **ID card STM32F103C**

## View
* *STM32F103C, a total of 44 interfaces are connected, for example, the pin function definition table is the interface definition.*

![Alt text](Picture/BLUE_PILL_STM32F103C.jpg)
*Image taken from the device datasheet*

## Datasheet
[STM32F103C](https://pdf1.alldatasheet.com/datasheet-pdf/view/201596/STMICROELECTRONICS/STM32F103C8T6.html)
To program the card STM32F103C, the ST must be connected,therefore, it is recommended to see the datasheet:
[ST LINK-V2](https://www.waveshare.com/wiki/ST-LINK/V2_(mini))
## Port Identification
Below are the ports used and their proper designations for programming:

No.| Name     | Function 
-- |-----     |---
1  |VBAT      |3.3V power supply; The output current of the external power supply
2  |          | By default, it is enabled as a chip, and the high level is effective 
3  |          | Empty feet 
4  |          | GPIO11/SPI_SCLK/IIC_SDA/ADC_CH10/JTAG_TDI/TDO 
7  |R         | NRST_RESET BUTTON
10 |A0        | PA0_ADC0_CTS2_T2C1E_WKUP
11 |A1        | PA1_ADC1_RTS2_T2C2
12 |A2        | PA2_ADC2_TX2_T2C3
13 |A3        | PA3_ADC3_RX2_T2C4
14 |A4        | PA4_ADC4_NSS1_CK2
15 |A5        | PA5_ADC5_SCK1 
16 |A6        | PA6_ADC6_MISO1_T3C1_T1BKIN 
17 |A7        | PA7_ADC7_MOSI1_T3C2_T1C1N  
18 |B0        | PB0_ADC8_T3C3_T1C2N
19 |B1        | PB1_ADC9_T3C4_T1C3N
20 |BOOT1     | PB2_BOOT1
21 |B10       | PB10_SCL2_TX3_T2C3N
22 |B11       | PB11_SDA2_RX3_T2C4N
25 |B12       | PB12_SMBAI2_NSS2_T1BKIN_CK3
26 |B13       | PB13_SCK2_T1C1N_CTS3
27 |B14       | PB14_MISO2_T1C2N_RTS3
28 |B15       | PB15_MOSI2_T1C3N
29 |A8        | PA8_CK1_T1C1_MCO
30 |A9        | PA9_TX1_T1C2
31 |A10       | PA10_RX1_T1C3
32 |A11       | PA11_USB-_CTS1_T1C4_CANRX
33 |A12       | PA12_USB+_RTS1_T1ETR_CANTX 
34 |SWIO      | SWIO_JTMS_PA13 
37 |SWCLK     | SWCLK_JTCK_PA14
38 |A15       | PA15_JTDI_NSS1_T2C1E
39 |B3        | PB3_JTDO_SCK1_T2C2_TRACE SWO
40 |B4        | PB4_JTRST_MISO1_T3C1
41 |B5        | PB5_SMBAI1_MOSI1_T2C2
42 |B6        | PB6_SCL1_T4C1_TX1
43 |B7        | PB7_SDA1_T4C2_RX1
44 |BOOT0     | BOOT0
45 |B8        | PB8_SCL1_T4C3_CANRX
46 |B9        | PB9_SDA1_T4C4_CANTX
   |5V        | INPUT 5V BLUE PILL STM32F103C
   |GND       | GROUND CARD BLUE PILL STM32F103C
   |3.3V      | INPUT 3.3V BLUE PILL STM32F103C


### Digital input and Output

To identify the digital inputs and outputs, the input and output ports of the card are tested respectively, for this, a code was programmed which allowed the identified ports to be tested one by one, as shown in (image 1):
the led is protected by a resistor de 330Ω
PA0,PA1,PA2,PA3,PA4,PA5,PA6,PA7,PB0,PB1,PB10,PB11,PB12,PB13,PB14,PB15,PA8,PA9,PA10,PA11,PA12,PB5,PB6,PB7,PB8,PB9,the aforementioned can also be used as outputs since the card pins allow both functions depending on how they are classified in programming, the difference between these ports or pins will be that some support voltages of exactly 5 volts and others that support voltages lower than 5 volts, to be able to deliver 3.3 volts and 5 volts to the card a burner is used ST-LINK V2  which allows us to select between these two voltages which one we want to deliver and allows us to synchronize the program that we have in the application ARDUINO IDE 2.2.1 for STM32VLD to FLASH  and the card STM32F103C3.

const int ledPIN1 = PA8; //salida digital al led PA3

const int intPIN = PA9; //entrada digital al led PA8
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledPIN1, OUTPUT);//led conectado a salida PA9
  pinMode(intPIN, INPUT);//interruptor conectado a entrada PA8
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(intPIN)==LOW){
    //INTERRUPTOR PRESIONADO
  digitalWrite(ledPIN1, LOW); //LED conectado a PA9  

  }
  else{
    //interruptor suelto

  digitalWrite(ledPIN1, LOW);  //LED conectado a PA9
  
  }  
 delay (1);
}

### Analog Output
To recognize the analog inputs, the same port testing process carried out previously is carried out with the difference that only the ports that allow them to be used to receive and transmit analog signals will be tested, which allow the amplitude and period of the signal to be modified. A signal for this case is reflected when a potentiometer is used, which works as a variable resistor that has a value between 0Ω and 10 kΩ that regulates the level of voltage that will be supplied by this device at the input of our LED, 
The LED is protected by a 330Ω resistor, with this circuit which will allow us to observe how the light intensity of the LED varies depending on the value of Ω assigned to the potentiometer, during the verification it is obtained that the ports that allow the transfer of analog signals are A8, A9, A10,B3,B4,B5,B6,B7,B12, B13,B14,B15, for this, a code is programmed which allows the ports previously identified to be identified one by one.


### PWM Output


To recognize the PWM signal port of the AIR32F103 card, the ports of the card are tested to find out which of them provides us with this function, so we can obtain a PWM signal using an analog signal as input modulating the width of the pulses generated by the output ports through, during identification it is obtained that the pins that allow the emission of a PWM signal are.

example for PWM and Analog

define LED_BUILTIN 2

#include <PWMOutESP32.h> //https://github.com/fellipecouto/PWMOutESP32 [ http://www.efeitonerd.com.br ]

//Resolution between 1 and 16 (bits). Frequency between 1 and 40000 (Hz)
PWMOutESP32 pwm(10, 5000); //Resolution=10bits, Frequency=5000Hz

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("\nPWMOutESP32");
  Serial.println("Library for controlling ESP32 PWM outputs similar to use on Arduino");
  Serial.print("Maximum PWM value for the configured resolution: ");
  Serial.println(pwm.getMaxPWMValue());
}

void loop() {

  for (int fadeValue = 0; fadeValue <= pwm.getMaxPWMValue(); fadeValue++)  {
    pwm.analogWrite(LED_BUILTIN, fadeValue);
    delay(2);
  }
  delay(500);

  for (int fadeValue = pwm.getMaxPWMValue(); fadeValue >= 0; fadeValue--)  {
    pwm.analogWrite(LED_BUILTIN, fadeValue);
    delay(2);
  }
  delay(500);

}

### UART communication

To identify the ports of the card that allow us to have UART communication, the 3.3 V provided by the AIR32F103 card is used as input, the input voltage is regulated by means of a potentiometer that, by turning its knob and through the communication between The cards through the UART port allow LEDs assigned on the STM32F103C card to be turned on and off. When our voltage regulation device is at its minimum resistance value, the green LED must be on. When it reaches the average resistance value, it must turn on. the yellow LED and when it reaches its maximum resistance value, the Red LED must turn on at the input, an LED must be connected to each port, to do this these two cards will be connected through the generic UART port, that is, connect the PA9 port (TX) of the AIR32F103C card with port PA10 (RX) of the STM32F103C card and port PA10 (RX) of the AIR32F103C card with port PA9 (TX) of the STM32F103C card.

example:

## Programming in v language
For each of these modules, you will have a file in .c.v format with the same name of the module and in this you will have the text module followed by the name of the module, example:
* module pin
* module adc
* module pwm


### Output port configuration
To activate the port to use
```go
pin__setup(PIN_NAME, MODE)
```
To activate the port to use
```go
pin__high(PIN_NAME)
```
* *Example: If you want to activate the port 17;  `pin__high(17)`.*

To disable the port being used
```go
pin__low(PIN_NAME)
```
* *Example: If you want to disable the port 17;  `pin__low(17)`.*

To disable or enable the port to be used

```go
pin__write(PIN_NAME, VALUE)
```
* *Example: If you want to disable port 17 `pin__write(17, 1)`, and if you want to activate  `pin__write(17, 0)`.*




### Analog to digital ports (ADC)

To configure one of the analog ports
```go
adc__setup(PIN_NAME, SETUP_VALUE, ... )
```
* *In PIN_NAME the name of the analog port is entered, in SETUP_VALUE the VALUE that will be given is said port.*

To detect the analog port VALUE
```go
x = adc__read(PIN_NAME)
```
* *In `PIN_NAME` the name of the analog port is entered, and `x` takes the VALUE of said port..*

## Pulse Width Modulation (PWM outputs)

To configure some PWM
```go
pwm__setup(SETUP_VALUE, setup_VALUE_1, ... )
```
* *In pwm you set the PWM to use, and in SETUP_VALUE the VALUE to which you want to configure said pwm.*


To configure the duty cycle of a modulator
```go
pwm__duty(duty)
```
* *In PWM the pwm to be used is set, and in `duty` the VALUE of the cycle (from 0 to 100) in percentage.*

## Serial communication (UART)

The UART used to be the standard stream output, so the functions `print()`, `println()` and `input()` work directly on the default UART. The default UART could change depending on the board or microcontroller, please refer to the specific documentation. The syntax for most of UART functions is: `uart_function_name_x()`, being `x` the identifying number in case of multiple UARTs. You can omit the `x` for referring to the first or default UART, or in the case of having only one.  

### UART setup

```v
uart__setup(BAUD_RATE)   // the same of uart__setup(BAUD_RATE)
```
For a second connection it is used as:
```v 
uart__setup_1(BAUD_RATE)   // the same of uart__setup_1(BAUD_RATE)
```
- `BAUD_RATE` configure the communication speed
### Serial transmitting

```v
uart__print(MESSAGE)      // print a string to the default UART
```
```v
uart__println(MESSAGE)    // print a string plus a line-new character to the default UART
```
```v
uart__ready // get everything ready for to UART
```
```v
uart__read // receives binary data (in Bytes) to UART
```
```v
uart__write(MESSAGE)    // send binary data (in Bytes) to second UART
```
- For a second UART, it would be used as follows:
```v
uart__print_1(MESSAGE)    // print a string to the second UART
```
```v
uart__println_1(MESSAGE)  // print a string plus a line-new character to the second UART
```
```v
uart__write_1(MESSAGE)    // send binary data (in Bytes) to second UART
```
```v
uart__ready_1 // get everything ready for to second UART
```
```v
uart__read_1 // receives binary data (in Bytes) to second UART
```

### Retardos

* Use of times

    * In each expression, the time VALUE is put inside the parentheses.
```go
time__sleep(S) //Seconds
```
```go
time__sleep_ms(MS) //Milliseconds
```
```go
time__sleep_us(US) //Microseconds
```

* Example flashing LED

```go
import pin
import time {sleep_ms}

pin.setup(14, pin.out)

for {   //infinite loop
    pin.high(14)
    sleep_ms(500)
    pin.low(14)
    sleep_ms(500)
}
```