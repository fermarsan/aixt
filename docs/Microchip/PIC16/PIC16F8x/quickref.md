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

```# Guia Rápida para PIC16F84A
## Referencia del PIC16 utilizado de la marca MICROCHIP
- PIC16F84A

**NOTA:** Este microcontrolador PIC16F solo cuenta con salidas digitales y entradas digitales

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `a6` indica el pin 6 del puerto A. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Nombres de los pines del PIC16F84A
| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | a0| a1| a2| a3| a4|---|---|---|
| **B**  | b0| b1| b2| b3| b4| b5| b6| b7|

En las familias de microcontroladores del _PIC16_, los registros del puerto se dividen en:

- `TRIS` Para configurar cada pin del puerto
- `PORT` Para gestionar los pines como entradas o salidas

Luego, para facilitar la implementación (y no generar código inncesario) de este port _Aixt_, el nombre de cada pin difiere de su configuración, entrada y salida como en el siguiente ejemplo:

- `a5_s` Nombre del bit para configurar el `a5` pin como entrada o salida
- `a5`   Nombre del bit para leer el pin como entrada o salida `a5`

### Funciones soportadas
Las funciones que contiene la API entradas o salidas digitales.

name                                  | description
--------------------------------------|------------------------------
`pin.setup(pin_name, mode)`     | Configura `PIN_NAME` en `PIN_MODE`
`pin.high(PIN_NAME)`                 | Encender `PIN_NAME`
`pin.low(PIN_NAME)`                  | Apagar `PIN_NAME`
`pin.write(PIN_NAME,VAL)`            | Escribe `VAL` en `PIN_NAME`
`pin.read(PIN_NAME)`                 | lee `PIN_NAME`
`pin (PIN)`                           | Configura `PIN_OUTPUT` o `PIN_INPUT`
`port`                                | Inicializa `port`
`port.read(PORT_NAME)`               | Lee `PORT_NAME`
`port.setup(PORT_NAME, VALUE)`       | Configura `PORT_NAME` asigna valor `VALUE`
`port.write(PORT_NAME, VALUE)`       | Escribe `PORT_NAME` en `VALUE`
`time.sleep(time)`                   | Retardo en `seg`
`time.sleep_us(time)`                | Retardo en `microseg`
`time.sleep_ms(time)`                | Retardo en `miliseg`
`time`                                | Inicializa el `time`

### Ejemplos de las diferentes funciones de la API en lenguaje _Aixt_v

## Tiempo

```v

time.sleep(5)	// Tiempo de 5 segundos
time.sleep_us(10)	// Tiempo de 10 microsegundos
time.sleep_ms(500)	// Tiempo de 500 milisegundos

```

## Configuración de pines

```v

pin.setup(a4, output)      // Función para configurar el pin como salida
pin.setup(b2, output)      // Función para configurar el pin como salida
pin.setup(a2, input)    // Función para configurar el pin como entrada
pin.setup(b4, input)    // Función para configurar el pin como entrada

pin.high(a4)    // Función para encender el pin
pin.low(a4)     // Función para apagar el pin

pin.write(a2, 0)  // Función sobre escribir el pin
pin.write(a2, 1)  // Función sobre escribir el pin

pin.read(a1)  // Función para leer el pin
pin.read(a1)  // Función para leer el pin

```

Ejemplo de prender y apagar un led:

```v

for {

    pin.high(b1);
    time.sleep_us(500);
    pin.low(b1);
    time.sleep_us(500);

}

```
Ejemplo de prender y apagar un led con una entrada digital:

```v

for {

    if(b2 == 1){        // Condición si encuentra un 1 en el b2

        pin.high(b1);
        pin.high(b0);
    }

    else if(b4 == 1){   // Condición si encuentra un 1 en el b4

        pin.low(b1);
        pin.low(b0);
    }

}

```
## Configuración del port

```v

port.setup(a, ob000000)      // Función para configurar el puerto como salida

```

Ejemplo de prender y apagar un puerto del microcontrolador:

```v

while(1){

    port.write(a,0b110101);
    time.sleep_ms(500);
    port.write(a,0b001010);
    time.sleep_ms(500);

}

```
