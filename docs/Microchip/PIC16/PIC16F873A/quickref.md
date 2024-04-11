# Guia Rápida para PIC16F873A
## Referencia del PIC16 utilizado de la marca MICROCHIP
- PIC16F873A

**NOTA:** Este microcontrolador PIC16F cuenta con salidas digitales, entradas digitales, ADC, PWM y comunicación serial.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `a6` indica el pin 6 del puerto A. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).

### Nombres de los pines del PIC16F873A
| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | a0| a1| a2| a3| a4| a5| - | - |
| **B**  | b0| b1| b2| b3| b4| b5| b6| b7|
| **C**  | c0| c1| c2| c3| c4| c5| c6| c7|

En las familias de microcontroladores del _PIC16_, los registros del puerto se dividen en: 

- `TRIS` Para configurar cada pin del puerto
- `PORT` Para gestionar los pines como entradas o salidas

Luego, para facilitar la implementación (y no generar código inncesario) de este port _Aixt_, el nombre de cada pin difiere de su configuración, entrada y salida como en el siguiente ejemplo: 

- `b5_s` Nombre del bit para configurar el `b5` pin como entrada o salida 
- `b5`   Nombre del bit para leer el pin como entrada o salida `b5`

### Componentes Integrados 
- Cuenta con seis pines analogicos que se encuentran distribuidas en el puerto A.

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
|:------:|---|---|---|---|---|---|---|---|
| **A**  |AN0|AN1|AN2|AN3|AN4|AN5| - | - |
| **B**  | - | - | - | - | - | - | - | - |
| **C**  | - | - | - | - | - | - | - | - |

- Cuenta con dos pines para la modulacion del PWM.

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | - | - | - | - | - | - | - | - |
| **B**  | - | - | - | - | - | - | - | - |
| **C**  | - | c1| c2| - | - | - | - | - |

- Cuenta con dos pines para la cominicación serial.   

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | - | - | - | - | - | - | - | - |
| **B**  | - | - | - | - | - | - | - | - |
| **C**  | - | - | - | - | - | - | c6| c7|

### Funciones soportadas
Las funciones que contiene la API entradas o salidas digitales, conversor analogico a digital, modulación pwm y comunicación serial.

name                                | description
------------------------------------|------------------------------------------------------
`pin__setup(PIN_NAME, PIN_MODE)`   | Configura `PIN_NAME` en `PIN_MODE`
`pin__high(PIN_NAME)`               | Encender `PIN_NAME`
`pin__low(PIN_NAME)`                | Apagar `PIN_NAME`
`pin__write(PIN_NAME,VAL)`          | Escribe `VAL` en `PIN_NAME`
`pin__read(PIN_NAME)`               | lee `PIN_NAME`
`pin__digital(PIN)`                 | Configura I/0 digitales `PIN_NAME`
`pin (PIN)`                         | Configura `PIN_OUTPUT` o `PIN_INPUT`
`port`                              | Inicializa `port`
`port__read(PORT_NAME)`             | Lee `PORT_NAME`
`port__setup(PORT_NAME, VALUE)`     | Configura `PORT_NAME` asigna valor `VALUE`
`port__write(PORT_NAME, VALUE)`     | Escribe `PORT_NAME` en `VALUE`
`adc__setup()`                      | Configura el `adc` 
`adc__read(channel)`                | Configura el canal `channel` del `adc`
`adc`                               | Inicializa `adc`
`pwm__setup()`                      | Configura el resgitro `pwm`
`pwm__write(duty)`                  | Calcula el `duty` del `pwm` 
`pwm`                               | Inicializa `pwm`
`uart__setup()`                     | Configura el `uart`
`uart__read()`                      | Lee los datos del `uart`
`uart__write()`                     | Escribe los datos del `uart`
`uart`                              | Inicializa el `uart`
`time__sleep(time)`                 | Retardo en `seg`
`time__sleep_us(time)`              | Retardo en `microseg`
`time__sleep_ms(time)`              | Retardo en `miliseg`
`time`                              | Inicializa el `time`

### Ejemplos de las diferentes funciones de la API en lenguaje _Aixt_v 

## Tiempo

```v

sleep(5)	// Tiempo de 5 segundos
sleep__us(10)	// Tiempo de 10 microsegundos
sleep__ms(500)	// Tiempo de 500 milisegundos

```

## Configuración de pines 

```v

pin.setup(a5, pin.output)      // Función para configurar el pin como salida 
pin.setup(b7, pin.output)      // Función para configurar el pin como salida
pin.setup(a0, pin.input)    // Función para configurar el pin como entrada
pin.setup(c4, pin.input)    // Función para configurar el pin como entrada

pin.high(a5)    // Función para encender el pin           
pin.low(a5)     // Función para apagar el pin

pin.write(a2, 0)  // Función sobre escribir el pin
pin.write(a2, 1)  // Función sobre escribir el pin

pin.read(b4)      // Función para leer el pin
pin.read(c7)      // Función para leer el pin

```

Ejemplo de prender y apagar un led:

```v
      
for {

    pin.high(c7);
    sleep_us(500);
    pin.low(c7);
    sleep_us(500);

}

```
Ejemplo de prender y apagar un led con una entrada digital:

```v

pin.digital();

for {
    
    if(b4 == 1){        // Condición si encuentra un 1 en el pin c2
        
        pin.high(a4);
        pin.high(a5);
    }
    
    else if(b5 == 1){   // Condición si encuentra un 1 en el pin c4
        
        pin.low(a4);
        pin.low(a5);
    }

}
        
```
## Configuración del port

```v

port.setup(b, ob00000000)      // Función para configurar el puerto como salida 

```

Ejemplo de prender y apagar un puerto del microcontrolador:

```v
      
for {
        
    port.write(b,0b01010101);
    sleep_ms(500);
    port.write(b,0b10101010);
    sleep_ms(500);      
        
}

```

## Configuración del ADC

```v

adc.setup()     // Iicializa el ADC
adc.read(0)     // Escoge el pin denl canal analogico

```

Ejemplo de prender y apagar leds dependiendo del valor del ADC:

```v

unsigned int adc_result;  // Declaración de variable para almacenar el valor del ADC
        
for {
            
    adc_result = adc.read(0) ; // Almacena el valor del ADC
    
    if ( adc_result >= 1020 ){
        
        pin.high(b0);
        pin.high(b1);
        pin.high(b2);           
    }
    
    else if ( adc_result >= 820 ){
        
        pin.high(b0);
        pin.high(b1);
        pin.low(b2);
    }
    
    else if ( adc_result >= 620 ){
        
        pin.high(b0);
        pin.low(b1);
        pin.low(b2);   
    }
        
    else {
        
        pin.low(b0);
        pin.low(b1);
        pin.low(b2);      
    }

}

```

## Configuración del PWM

```v

pwm.setup()     // Inicializa el pwm
pwm.write()     // Calcula el ciclo de trabajo 

```
Ejemplo de variar la intensidad de un led:

```v

for {
    
    adc = adc.read(0);  // Almacena el valor del ADC
        
    pwm.write(adc);  // Realiza el calculo del Duty y lo guarda en CCP2
        
}

```

## Configuración del UART Transmisión

```v

uart.setup()     // Inicializa la comunicación serial

```
Ejemplo enviar un caracter y visualizarlo en un mensaje:

```v

for {
            
    uart.write(0x33);
	sleep_ms(500);
	uart.write(0x99);
	sleep_ms(500);
    
}

```

## Configuración del UART Recepción

```v

uart.setup()     // Inicializa la comunicación serial

```
Ejemplo prender y apagar un el puerto del micro enviando un caracteres desde el PC:

```v

port.setup(b, 0b00000000);
port.write(b, 0b00000000);
pin.setup(c7, pin.input);
uart.setup();

for {

    port.read(b) = uart.read();

}

```