# Guia Rápida para PIC16F676
## Referencia del PIC16 utilizado de la marca MICROCHIP
- PIC16F676

**NOTA:** Este microcontrolador PIC16F solo cuenta con salidas digitales, entradas digitales y ADC.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `a6` indica el pin 6 del puerto A. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Nombres de los pines del PIC16F676
| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 
|:------:|---|---|---|---|---|---|
| **A**  | a0| a1| a2| a3| a4| a5|
| **C**  | c0| c1| c2| c3| c4| c5|

En las familias de microcontroladores del _PIC16_, los registros del puerto se dividen en: 

- `TRIS` Para configurar cada pin del puerto
- `PORT` Para gestionar los pines como entradas o salidas

Luego, para facilitar la implementación (y no generar código inncesario) de este port _Aixt_, el nombre de cada pin difiere de su configuración, entrada y salida como en el siguiente ejemplo: 

- `a5_s` Nombre del bit para configurar el `a5` pin como entrada o salida 
- `a5`   Nombre del bit para leer el pin como entrada o salida `a5`

### Componentes Integrados 
Cuenta con ocho pines analogicas que se encuentran distribuidas entre en el puerto A y el puerto C.

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 
|:------:|---|---|---|---|---|---|
| **A**  |AN0|AN1|AN2|-  |AN3|-  |
| **C**  |AN4|AN5|AN6|AN7|-  |-  |

### Funciones soportadas
Las funciones que contiene la API entradas o salidas digitales y para realizar una conversión analogico a digital.

name                                  | description
--------------------------------------|----------------------------------------------
`pin__setup(PIN_NAME, PIN_MODE)`     | Configura `PIN_NAME` en `PIN_MODE`
`pin__high(PIN_NAME)`                 | Encender `PIN_NAME`
`pin__low(PIN_NAME)`                  | Apagar `PIN_NAME`
`pin__write(PIN_NAME,VAL)`            | Escribe `VAL` en `PIN_NAME`
`pin__read(PIN_NAME)`                 | lee `PIN_NAME`
`pin__digital(PIN)`                   | Configura I/0 digitales `PIN_NAME`
`pin (PIN)`                           | Configura `PIN_OUTPUT` o `PIN_INPUT`
`port`                                | Inicializa `port`
`port__read(PORT_NAME)`               | Lee `PORT_NAME`
`port__setup(PORT_NAME, VALUE)`       | Configura `PORT_NAME` asigna valor `VALUE`
`port__write(PORT_NAME, VALUE)`       | Escribe `PORT_NAME` en `VALUE`
`adc__setup()`                        | Configura el `adc` 
`adc__read(channel)`                  | Configura el canal `channel` del `adc`
`adc`                                 | Inicializa `adc` 
`time__sleep(time)`                   | Retardo en `seg`
`time__sleep_us(time)`                | Retardo en `microseg`
`time__sleep_ms(time)`                | Retardo en `miliseg`
`time`                                | Inicializa el `time`

### Ejemplos de las diferentes funciones de la API en lenguaje _Aixt_v 

## Tiempo

```v

time__sleep(5)	// Tiempo de 5 segundos
time__sleep_us(10)	// Tiempo de 10 microsegundos
time__sleep_ms(500)	// Tiempo de 500 milisegundos

```

## Configuración de pines 

```v

pin.setup(a5, pin.output)      // Función para configurar el pin como salida 
pin.setup(c2, pin.output)      // Función para configurar el pin como salida
pin.setup(a2, pin.input)    // Función para configurar el pin como entrada
pin.setup(c4, pin.input)    // Función para configurar el pin como entrada

pin.high(a5)    // Función para encender el pin           
pin.low(a5)     // Función para apagar el pin

pin.write(a2, 0)  // Función sobre escribir el pin
pin.write(a2, 1)  // Función sobre escribir el pin

pin.read(a4)      // Función para leer el pin
pin.read(c3)      // Función para leer el pin

```

Ejemplo de prender y apagar un led:

```v
      
for {

    pin.high(c1);
    sleep_us(500);
    pin.low(c1);
    sleep_us(500);

}

```
Ejemplo de prender y apagar un led con una entrada digital:

```v

pin.digital(); // Todas los pin son I/O digitales

for {
    
    if(c2 == 1){        // Condición si encuentra un 1 en el pin c2
        
        pin.high(c1);
        pin.high(c0);
    }
    
    else if(c4 == 1){   // Condición si encuentra un 1 en el pin c4
        
        pin.low(c1);
        pin.low(c0);
    }

}
        
```

## Configuración del port

```v

port.setup(a, ob000000)      // Función para configurar el puerto como salida 

```

Ejemplo de prender y apagar un puerto del microcontrolador:

```v
      
for {
        
    port.write(a,0b010101);
    sleep_ms(500);
    port.write(a,0b101010);
    sleep_ms(500);      
        
}

```

## Configuración del ADC

```v

adc.setup()     // Inicializa el ADC
adc.read(0)     // Escoge el pin del canal analogico

```

Ejemplo de prender y apagar leds dependiendo del valor del ADC:

```v

unsigned int adc_result;  // Declaración de variable para almacenar el valor del ADC
        
for {
            
    adc_result = adc.read(0); // Almacena el valor del ADC
    
    if ( adc_result >= 1020 ){
        
        pin.high(c0);
        pin.high(c1);
        pin.high(c2);           
    }
    
    else if ( adc_result >= 820 ){
        
        pin.high(c0);
        pin.high(c1);
        pin.low(c2);
    }
    
    else if ( adc_result >= 620 ){
        
        pin.high(c0);
        pin.low(c1);
        pin.low(c2);   
    }
        
    else {
        
        pin.low(c0);
        pin.low(c1);
        pin.low(c2);      
    }

}

```