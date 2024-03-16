# Guia Rápida para PIC18F2550
## Referencia del PIC18 utilizado de la marca MICROCHIP
- PIC18F2550

**NOTA:** Este microcontrolador PIC18F cuenta con salidas digitales, entradas digitales, ADC, PWM y comunicación serial.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `a3` indica el pin 3 del puerto A. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Nombres de los pines del PIC18F2550
| Puerto | - | - | - | - | - | - | - | - | 
| **A**  | a0| a1| a2| a3| a4| a5| a6| - |
| **B**  | b0| b1| b2| b3| b4| b5| b6| b7|
| **C**  | c0| c1| c2| - | c4| c5| c6| c7|

En las familias de microcontroladores del _PIC18F2550_, los registros del puerto se dividen en: 

- `TRIS` Para configurar cada pin del puerto
- `PORT` Lee los niveles en los pines del dispositivo 

Luego, para facilitar la implementación (y no generar código inncesario) de este port _Aixt_, el nombre de cada pin difiere de su configuración, entrada y salida como en el siguiente ejemplo: 

- `b2_s`  Nombre del bit para configurar el `b2` pin como entrada o salida 
- `b2_i`  Nombre del bit para leer el pin como entrada `b2`
- `b2`    Nombre del bit para leer el pin como salida  `b2`

### Componentes Integrados 
- Cuenta con seis pines analogicos que se encuentran distribuidas en el puerto A.

| Puerto     | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
|:------:    |---|---|---|---|---|---|---|---|
| **A**      |AN0|AN1|AN2|AN3| - |AN4| - | - |
| **B**   |AN12|AN10|AN8|AN9|AN11| - | - | - |
| **C**      | - | - | - | - | - | - | - | - |


- Cuenta con dos pines para la modulacion del PWM.

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | - | - | - | - | - | - | - | - |
| **B**  | - | - | - |b3 | - | - | - | - |
| **C**  | - | c1| c2| - | - | - | - | - |

- Note 1: RB3 es el pin alternativo para el registro CCP2

- Cuenta con dos pines para la cominicación serial.   

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|:------:|---|---|---|---|---|---|---|---|
| **A**  | - | - | - | - | - | - | - | - |
| **B**  | - | - | - | - | - | - | - | - |
| **C**  | - | - | - | - | - | - | c6| c7|


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
`adc_setup()`                    | Configura el `adc` 
`adc_read(channel)`              | Configura el canal `channel` del `adc`
`adc_reading()`                  | Alamacena el valor del `adc`
`pwm_setup(pin1, pin2)`          | Configura el resgitro `pin1` y la salida en `pin2`
`pwm_write(duty, pin)`           | Calcula el `duty` del `pwm` y lo alamcena en `pin` 
`uart_setup()`                   | Configura el `uart`
`uart__write()`                  | Configura el `TX`
`uart__read()`                   | Configura el `RX`
`sleep(time)`                    | Retardo en `seg`
`sleep_us(time)`                 | Retardo en `microseg`
`sleep_ms(time)`                 | Retardo en `miliseg`

## Configuración de pines 
```go
pin__setup(b3, output)      // Función para configurar el pin como salida 
pin__setup(a2, output)      // Función para configurar el pin como salida
pin__setup(b2, input)    // Función para configurar el pin como entrada
pin__setup(a1, input)    // Función para configurar el pin como entrada

pin__high(b3)    // Función para encender el pin           
pin__low(b3)     // Función para apagar el pin

pin__write(a4, 0)  // Función sobre escribir el pin
pin__write(a4, 1)  // Función sobre escribir el pin

pin__read(c4)      // Función para leer el pin
pin__read(b0)      // Función para leer el pin
```
Ejemplo de prender y apagar un led:

```go
      
while (1) {
    pin__high(b4);
    sleep__us(700);
    pin__low(b4);
    sleep__us(700);
}
```
Ejemplo de prender y apagar un led con una entrada digital:

```go

while(1){
    
    if(a4 == 0){        // Condición si encuentra un 0 en el pin a4
        
        pin_high(c0);
        pin_high(c2);
    }
    
    else if(b2 == 1){   // Condición si encuentra un 1 en el pin b2
        
        pin_low(a1);
        pin_low(c2);
    }

}
        
```
## Configuración del ADC
```go
adc_setup()     // Iicializa el ADC
adc_read(0)     // Escoge el pin denl canal analogico
adc_reading();  // Almacena el valor del ADC en una función

```

Ejemplo de prender y apagar leds dependiendo del valor del ADC:
```go
unsigned int adc_RTA;  // Declaración de variable para almacenar el valor del ADC
        
while(1){
            
    adc_RTA = adc_reading(); // Almacena el valor del ADC
    
    if ( adc_RTA >= 1000 ){
        
        pin__high(C4);
        pin__high(C1);
        pin__high(C2);           
    }
    
    else if ( adc_RTA >= 600 ){
        
        pin_high(b5);
        pin_high(b1);
        pin_low(b3);
    }
    
    else if ( adc_RTA >= 340 ){
        
        pin_high(a0);
        pin_low(a1);
        pin_low(a2);   
    }
        
    else {
        
        pin_low(c7);
        pin_low(c6);
        pin_low(c5);      
    }

}

```
## Configuración del PWM
```go
pwm_setup()     // Inicializa el pwm
pwm_write()     // Calcula el ciclo de trabajo 

```
Ejemplo de variar la intensidad de un led:

```go
 while(1){
    
        adc := adc_read(3)  // Almacena el valor del ADC
        pwm_write(adc)  // Calcula el ciclo de trabajo y lo establece en el módulo PWM CCP1
        
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

