# Quick reference for PIC16F8x family

## Reference for the Microchip PIC16F8x devices
- PIC16F83
- PIC16F83A
- PIC16F84
- PIC16F84A

**NOTE:** This PIC16F8x microcontroller only has digital outputs and digital inputs

## Pin Names
The pin names are named with a letter indicating the port and a number indicating the pin. For example, `a6` indicates pin 6 of port A. All names in **Aixt** are written in lowercase, to follow [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Pin names for PIC16F84A
| Port | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:----:|---|---|---|---|---|---|---|---|
| **A**| a0| a1| a2| a3| a4|---|---|---|
| **B**| b0| b1| b2| b3| b4| b5| b6| b7|

In the _PIC16_ microcontroller families, the port registers are divided into:

- `TRIS` To configure each port pin
- `PORT` To manage the pins as inputs or outputs

### Supported Functions
The functions contained in the API are digital inputs or outputs.

name                                  | description
--------------------------------------|------------------------------
`pin.setup(pin_name, mode)`           | configures `pin_name` in `pin_mode`
`pin.high(pin_name)`                  | turn on `pin_name`
`pin.low(pin_name)`                   | turn off `pin_name`
`pin.toggle(pin_name)`                | toggle the state of `pin_name`
`pin.write(pin_name,val)`             | write `val` to `pin_name`
`pin.read(pin_name)`                  | read `pin_name`
`pin (pin)`                           | configure `pin_output` or `pin_input`
`port`                                | initialize `port`
`port.read(port_name)`                | read `port_name`
`port.setup(port_name, value)`        | configure `port_name` assign value `value`
`port.write(port_name, value)`        | write `port_name` to `value`
`time.sleep(time)`                    | delay in `sec`
`time.sleep_us(time)`                 | delay in `microsec`
`time.sleep_ms(time)`                 | delay in `millisec`
`time`                                | initialize `time`

### Examples of the different API functions in _Aixt_ language

## Time

```v

time.sleep(5)	// Time of 5 seconds
time.sleep_us(10)	// Time of 10 microseconds
time.sleep_ms(500)	// Time of 500 milliseconds

```

## Pin Configuration

```v

pin.setup(a4, output)      // Function to configure the pin as output
pin.setup(b2, output)      // Function to configure the pin as output
pin.setup(a2, input)    // Function to configure the pin as input
pin.setup(b4, input)    // Function to configure the pin as input

pin.high(a4)    // Function to turn on the pin
pin.low(a4)     // Function to turn off the pin

pin.write(a2, 0)  // Function to write to the pin
pin.write(a2, 1)  // Function to write to the pin

pin.read(a1)  // Function to read the pin
pin.read(a1)  // Function to read the pin

```

Example of turning an LED on and off:

```v

for {

    pin.high(b1);
    time.sleep_us(500);
    pin.low(b1);
    time.sleep_us(500);

}

```
Example of turning an LED on and off with a digital input:

```v

for {

    if(b2 == 1){        // Condition if it finds a 1 in b2

        pin.high(b1);
        pin.high(b0);
    }

    else if(b4 == 1){   // Condition if it finds a 1 in b4

        pin.low(b1);
        pin.low(b0);
    }

}

```
## Port Configuration

```v

port.setup(a, 0b00000000)      // Function to configure the port as output

```

Example of turning on and off a port of the microcontroller:

```v

while(1){

    port.write(a,0b00110101);
    time.sleep_ms(500);
    port.write(a,0b00001010);
    time.sleep_ms(500);

}

```
