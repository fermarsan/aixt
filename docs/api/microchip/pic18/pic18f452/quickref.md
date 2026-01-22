# Guia Rápida para PIC18F452
## Referencia del PIC18 utilizado de la marca MICROCHIP
- PIC18F452

**NOTA:** Este microcontrolador PIC18F cuenta con salidas digitales, entradas digitales, ADC, PWM y comunicación serial.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `a3` indica el pin 3 del puerto A. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Nombres de los pines del PIC18F452
| Puerto | -   | -   | -   | -   | -   | -   | -   | -   |
| ------ | --- | --- | --- | --- | --- | --- | --- | --- |
| **A**  | a0  | a1  | a2  | a3  | a4  | a5  | -   | -   |
| **B**  | b0  | b1  | b2  | b3  | b4  | b5  | b6  | b7  |
| **C**  | c0  | c1  | c2  | c3  | c4  | c5  | c6  | c7  |
| **D**  | d0  | d1  | d2  | d3  | d4  | d5  | d6  | d7  |

En las familias de microcontroladores del _PIC18F452_, los registros del puerto se dividen en: 

- `TRIS` Para configurar cada pin del puerto
- `PORT` Lee los niveles en los pines del dispositivo 

Luego, para facilitar la implementación (y no generar código inncesario) de este port _Aixt_, el nombre de cada pin difiere de su configuración, entrada y salida como en el siguiente ejemplo: 

- `b2_s` Nombre del bit para configurar el `b2` pin como entrada o salida 
- `b2_i`  Nombre del bit para leer el pin como entrada `b2`
- `b2`    Nombre del bit para leer el pin como salida  `b2`

### Componentes Integrados 
- Cuenta con seis pines analogicos que se encuentran distribuidas en el puerto A.

| Puerto | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| :----: | --- | --- | --- | --- | --- | --- | --- | --- |
| **A**  | AN0 | AN1 | AN2 | AN3 | -   | AN4 | -   | -   |
| **B**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **C**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **D**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **E**  | AN5 | AN6 | AN7 | -   | -   | -   | -   | -   |

- Cuenta con dos pines para la modulacion del PWM.

| Puerto | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| :----: | --- | --- | --- | --- | --- | --- | --- | --- |
| **A**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **B**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **C**  | -   | c1  | c2  | -   | -   | -   | -   | -   |
| **D**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **E**  | -   | -   | -   | -   | -   | -   | -   | -   |


- Cuenta con dos pines para la cominicación serial.   

| Puerto | 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   |
| :----: | --- | --- | --- | --- | --- | --- | --- | --- |
| **A**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **B**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **C**  | -   | -   | -   | -   | -   | -   | c6  | c7  |
| **D**  | -   | -   | -   | -   | -   | -   | -   | -   |
| **E**  | -   | -   | -   | -   | -   | -   | -   | -   |

### Funciones soportadas
Las funciones que contiene la API entradas o salidas digitales, conversor analogico a digital, modulación pwm y comunicación serial.

| name                     | description                                        |
| ------------------------ | -------------------------------------------------- |
| `pin.high(pin)`          | Modo alto `pin`                                    |
| `pin.low(pin)`           | Modo bajo `pin`                                    |
| `pin.write(pin, val)`    | Escribe `val` en `pin`                             |
| `pin.read(pin)`          | Lee `pin`                                          |
| `pin.setup(pin, mode)`   | Configura pines I/O     `pin`                      |
| `port.setup(port, mode)` | Configura puertos I/O   `pin`                      |
| `port.write(port, val)`  | Escribe `val` en `port`                            |
| `port.read(port)`        | Lee `port`                                         |
| `adc.setup()`            | Configura el `adc`                                 |
| `adc.read(channel)`      | Configura el canal `channel` del `adc`             |
| `adc.reading()`          | Almacena el valor del `adc`                        |
| `pwm.setup(pin1, pin2)`  | Configura el registro `pin1` y la salida en `pin2` |
| `pwm.write(duty, pin)`   | Calcula el `duty` del `pwm` y lo alamcena en `pin` |
| `uart.setup()`           | Configura el `uart`                                |
| `uart.write()`           | Configura el `TX`                                  |
| `uart.read()`            | Configura el `RX`                                  |
| `time.sleep(TIME)`       | Retardo en `seg`                                   |
| `time.sleep_us(TIME)`    | Retardo en `microseg`                              |
| `time.sleep_ms(TIME) `   | Retardo en `miliseg`                               |

## Configuración de pines 
```v
pin.setup(pin.d3, pin.output)      // Función para configurar el pin como salida 
pin.setup(pin.a2, pin.output)      // Función para configurar el pin como salida
pin.setup(pin.b5, pin.input)    // Función para configurar el pin como entrada
pin.setup(pin.d1, pin.input)    // Función para configurar el pin como entrada

pin.high(pin.b3)    // Función para encender el pin           
pin.low(pin.b3)     // Función para apagar el pin

pin.write(pin.d1, 0)  // Función sobre escribir el pin
pin.write(pin.d1, 1)  // Función sobre escribir el pin

pin.read(pin.a4)      // Función para leer el pin
pin.read(pin.b3)      // Función para leer el pin

```
## Configuración de puertos
```v

port.setup(port.d3, pin.output)      // Función para configurar el pin como salida 
port.setup(port.b5, pin.input)    // Función para configurar el pin como entrada

port.write(port.d1, 0b01010101)  // Función sobre escribir el pin
port.write(port.d1, 0x00)  // Función sobre escribir el pin

port.read(port.a4)      // Función para leer el pin
port.read(port.b3)      // Función para leer el pin

```
Ejemplo de prender y apagar un led:

```v
      
for {
    pin.high(pin.d4)
    time.sleep_ms(500)
    pin.low(pin.d4)
    time.sleep_ms(500)
}
```
Ejemplo de prender y apagar un led con una entrada digital:

```v

for {
    
    if(d4 == 0){        // Condición si encuentra un 0 en el d4
        
        pin.high(pin.c3)
        pin.high(pin.c5)
    }
    
    else if(d2 == 1){   // Condición si encuentra un 1 en el d2
        
        pin.low(pin.a4)
        pin.low(pin.a2)
    }

}
        
```
## Configuración del ADC
```v

    adc.setup()
    
// CONFIGURAMOS EL PUERTO B COMO SALIDA

    port.setup(port.b, pin.port.output)
    
    // CONFIGURAMOS EL PUERTO C COMO SALIDA

    port.setup(port.c, pin.port.output)

    // LIMPIAMOS EL PUERTO B

    port.write(port.b, 0x00)

    // LIMPIAMOS EL PUERTO c

    port.write(port.c, 0x00)
   
    for
    {

        adc.read(0)
        valor := adc.reading()
        port.write(port.b, valor & 0xFF)                   // Muestra el dato de la parte baja en el puerto B
        port.write(port.c, (valor>>8) & 0x03 )                 // Muestra el dato de la parte alta en el puerto C
        time.sleep_ms(10)
    }

```
## Configuración del PWM
```v
pwm.setup(1, 2)     // Inicializa el pwm
pwm.write(val, 1)     // Calcula el ciclo de trabajo 

```
Ejemplo de variar la intensidad de un led:

```v
 for {    
        adc_value := adc.read(0)  // Almacena el valor del ADC
        pwm.write(adc_value,1)  // Calcula el ciclo de trabajo y lo establece en el módulo PWM CCP1        
    }

```




## Configuración del UART Transmisión
```v
   
       //CONFIG DE LOS PINES
    pin.setup(pin.c6,output)   //RC6 = TX

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

```v

    port.setup(port.b, pin.port.output)

    // LIMPIAMOS EL PUERTO B

    port.write(port.b, pin.port.output)
    
   
   // CONFIGURAMOS EL C7 PARA LA RECEPCIÓN DE DATOS
    pin.setup(pin.c7,input)

   // INICIALIZAMOS LA COMUNICACION SERIAL EN 9600 BAUDIOS
    uart.setup()             

     for {
         port.write(port.b, uart.read())
     }





```