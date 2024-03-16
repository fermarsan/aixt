# Guia Rápida para PIC18F452
## Referencia del PIC18 utilizado de la marca MICROCHIP
- PIC18F452

**NOTA:** Este microcontrolador PIC18F cuenta con salidas digitales, entradas digitales, ADC, PWM y comunicación serial.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `a3` indica el pin 3 del puerto A. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Nombres de los pines del PIC18F452
| Puerto | - | - | - | - | - | - | - | - |
| **A**  | a0| a1| a2| a3| a4| a5| - | - |
| **B**  | b0| b1| b2| b3| b4| b5| b6| b7|
| **C**  | c0| c1| c2| c3| c4| c5| c6| c7|
| **D**  | d0| d1| d2| d3| d4| d5| d6| d7|

En las familias de microcontroladores del _PIC18F452_, los registros del puerto se dividen en: 

- `TRIS` Para configurar cada pin del puerto
- `PORT` Lee los niveles en los pines del dispositivo 

Luego, para facilitar la implementación (y no generar código inncesario) de este port _Aixt_, el nombre de cada pin difiere de su configuración, entrada y salida como en el siguiente ejemplo: 

- `b2_s` Nombre del bit para configurar el `b2` pin como entrada o salida 
- `b2_i`  Nombre del bit para leer el pin como entrada `b2`
- `b2`    Nombre del bit para leer el pin como salida  `b2`

### Componentes Integrados 
- Cuenta con seis pines analogicos que se encuentran distribuidas en el puerto A.

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
|:------:|---|---|---|---|---|---|---|---|
| **A**  |AN0|AN1|AN2|AN3| - |AN4| - | - |
| **B**  | - | - | - | - | - | - | - | - |
| **C**  | - | - | - | - | - | - | - | - |
| **D**  | - | - | - | - | - | - | - | - |
| **E**  |AN5|AN6|AN7| - | - | - | - | - |

- Cuenta con dos pines para la modulacion del PWM.

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | - | - | - | - | - | - | - | - |
| **B**  | - | - | - | - | - | - | - | - |
| **C**  | - | c1| c2| - | - | - | - | - |
| **D**  | - | - | - | - | - | - | - | - |
| **E**  | - | - | - | - | - | - | - | - |


- Cuenta con dos pines para la cominicación serial.   

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | - | - | - | - | - | - | - | - |
| **B**  | - | - | - | - | - | - | - | - |
| **C**  | - | - | - | - | - | - | c6| c7|
| **D**  | - | - | - | - | - | - | - | - |
| **E**  | - | - | - | - | - | - | - | - |

### Funciones soportadas
Las funciones que contiene la API entradas o salidas digitales, conversor analogico a digital, modulación pwm y comunicación serial.

name                             | description
---------------------------------|------------------------------------------------------
`pin__high(pin)`                 | Modo alto `pin`
`pin__low(pin)`                  | Modo bajo `pin`
`pin__write(pin, val)`           | Escribe `val` en `pin`
`pin__read(pin)`                 | Lee `pin`
`pin__setup(pin, mode)`          | Configura pines I/O     `pin`
`port__setup(port, mode)`        | Configura puertos I/O   `pin`
`port__write(port, val)`         | Escribe `val` en `port`
`port__read(port)`               | Lee `port`
`adc__setup()`                   | Configura el `adc` 
`adc__read(channel)`             | Configura el canal `channel` del `adc`
`adc__reading()`                 | Almacena el valor del `adc`
`pwm__setup(pin1, pin2)`         | Configura el registro `pin1` y la salida en `pin2`
`pwm__write(duty, pin)`          | Calcula el `duty` del `pwm` y lo alamcena en `pin` 
`uart__setup()`                  | Configura el `uart`
`uart__write()`                  | Configura el `TX`
`uart__read()`                   | Configura el `RX`
`time__sleep(TIME)`              | Retardo en `seg`
`time__sleep_us(TIME)`           | Retardo en `microseg`
`time__sleep_ms(TIME) `          | Retardo en `miliseg`

## Configuración de pines 
```go
pin.setup(d3, output)      // Función para configurar el pin como salida 
pin.setup(a2, output)      // Función para configurar el pin como salida
pin.setup(b5, input)    // Función para configurar el pin como entrada
pin.setup(d1, input)    // Función para configurar el pin como entrada

pin.high(b3)    // Función para encender el pin           
pin.low(b3)     // Función para apagar el pin

pin.write(d1, 0)  // Función sobre escribir el pin
pin.write(d1, 1)  // Función sobre escribir el pin

pin.read(a4)      // Función para leer el pin
pin.read(b3)      // Función para leer el pin

```
## Configuración de puertos
```go

port.setup(d3, output)      // Función para configurar el pin como salida 
port.setup(b5, input)    // Función para configurar el pin como entrada

port.write(d1, 0b01010101)  // Función sobre escribir el pin
port.write(d1, 0x00)  // Función sobre escribir el pin

port.read(a4)      // Función para leer el pin
port.read(b3)      // Función para leer el pin

```
Ejemplo de prender y apagar un led:

```go
      
for {
    pin.high(d4)
    time.sleep_ms(500)
    pin.low(d4)
    time.sleep_ms(500)
}
```
Ejemplo de prender y apagar un led con una entrada digital:

```go

for {
    
    if(d4 == 0){        // Condición si encuentra un 0 en el pin d4
        
        pin.high(c3)
        pin.high(c5)
    }
    
    else if(d2 == 1){   // Condición si encuentra un 1 en el pin d2
        
        pin.low(a4)
        pin.low(a2)
    }

}
        
```
## Configuración del ADC
```go

    adc.setup()
    
// CONFIGURAMOS EL PUERTO B COMO SALIDA

    port.setup(b, port.output)
    
    // CONFIGURAMOS EL PUERTO C COMO SALIDA

    port.setup(c, port.output)

    // LIMPIAMOS EL PUERTO B

    port.write(b, 0x00)

    // LIMPIAMOS EL PUERTO c

    port.write(c, 0x00)
   
    for
    {

        adc.read(0)
        valor := adc.reading()
        port.write(b, valor & 0xFF)                   // Muestra el dato de la parte baja en el puerto B
        port.write(c, (valor>>8) & 0x03 )                 // Muestra el dato de la parte alta en el puerto C
        time.sleep_ms(10)
    }

```
## Configuración del PWM
```go
pwm.setup(1, 2)     // Inicializa el pwm
pwm.write(val, 1)     // Calcula el ciclo de trabajo 

```
Ejemplo de variar la intensidad de un led:

```go
 for {    
        valor_adc := adc.read(0)  // Almacena el valor del ADC
        pwm.write(valor_adc,1)  // Calcula el ciclo de trabajo y lo establece en el módulo PWM CCP1        
    }

```




## Configuración del UART Transmisión
```go
   
       //CONFIG DE LOS PINES
    pin.setup(c6,output)   //RC6 = TX

       //Inicializamos la comunicación serial
    uart.setup()
    
    for {
         uart.write(0x33)
         time.sleep_ms(500)
         uart.write(0x99)
         time.sleep_ms(500)
     }
     
```
## Configuración del UART Recepcion

```go

    port.setup(b, port.output)

    // LIMPIAMOS EL PUERTO B

    port.write(b, port.output)
    
   
   // CONFIGURAMOS EL PIN C7 PARA LA RECEPCIÓN DE DATOS
    pin.setup(c7,input)

   // INICIALIZAMOS LA COMUNICACION SERIAL EN 9600 BAUDIOS
    uart.setup()             

     for {
         port.write(b, uart.read())
     }





```