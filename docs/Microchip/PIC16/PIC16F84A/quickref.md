# Guia Rápida para PIC16F84A
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
`pin__setup(PIN_NAME, PIN_MODE)`     | Configura `PIN_NAME` en `PIN_MODE`
`pin__high(PIN_NAME)`                 | Encender `PIN_NAME`
`pin__low(PIN_NAME)`                  | Apagar `PIN_NAME`
`pin__write(PIN_NAME,VAL)`            | Escribe `VAL` en `PIN_NAME`
`pin__read(PIN_NAME)`                 | lee `PIN_NAME`
`pin (PIN)`                           | Configura `PIN_OUTPUT` o `PIN_INPUT`
`port`                                | Inicializa `port`
`port__read(PORT_NAME)`               | Lee `PORT_NAME`
`port__setup(PORT_NAME, VALUE)`       | Configura `PORT_NAME` asigna valor `VALUE`
`port__write(PORT_NAME, VALUE)`       | Escribe `PORT_NAME` en `VALUE`
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
    sleep__us(500);
    pin.low(b1);
    sleep__us(500);

}

```
Ejemplo de prender y apagar un led con una entrada digital:

```v

for {
    
    if(b2 == 1){        // Condición si encuentra un 1 en el pin b2
        
        pin.high(b1);
        pin.high(b0);
    }
    
    else if(b4 == 1){   // Condición si encuentra un 1 en el pin b4
        
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
    time__sleep_ms(500);
    port.write(a,0b001010);
    time__sleep_ms(500);      
        
}

```