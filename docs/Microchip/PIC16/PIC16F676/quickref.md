# Guia Rápida para PIC16F676
## Referencia del PIC16 utilizado de la marca MICROCHIP
- PIC16F676

**NOTA:** Este microcontrolador PIC16F solo cuenta con salidas digitales, entradas digitales y ADC.

## Nombres de los Pines
Los nombres de los pines se nombran con una letra que indica el puerto y un número que indica el pin. Por ejemplo `a6` indica el pin 6 del puerto A. Todos los nombres en **Aixt** estan escritos en minúsculas, para seguir [V variable naming rules.](https://github.com/vlang/v/blob/master/doc/docs.md#variables).


### Nombres de pines PIC16F676
| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 
|:------:|---|---|---|---|---|---|
| **A**  | a0| a1| a2| a3| a4| a5|
| **C**  | c0| c1| c2| c3| c4| c5|

En las familias de microcontroladores del _PIC16_, los registros del puerto se dividen en: 

- `TRIS` Para configurar cada pin del puerto
- `PORT` Para gestionar los pines como entradas o salidas

Luego, para facilitar la implementación (y generar código inncesario) de este port _Aixt_, el nombre de cada pin difiere de su configuración, entrada y salida como en el siguiente ejemplo: 

- `a5_s` Nombre del bit para configurar el `a5` pin como entrada o salida 
- `a5`   Nombre del bit para leer el pin como entrada o salida `a5`

### Componentes Integrados 
Cuenta con siete entradas analogicas que se encuentran distribuidas entre en el puerto A y el puerto C.

| Puerto | 0 | 1 | 2 | 3 | 4 | 5 | 
|:------:|---|---|---|---|---|---|
| **A**  |AN0|AN1|AN2|-  |AN3|-  |
| **C**  |AN4|AN5|AN6|AN7|-  |-  |

#### Supported functions
Las funciones que contiene la API entradas o salidas digital y para realizar una conversión analogico a digital.

name                    | description
------------------------|------------------------------
`pin_high(pin)`         | Encender `pin`
`pin_low(pin)`          | Apagar `pin`
`pin_write(pin, val)`   | Escribe `val` en `pin`
`pin_read(pin)`         | lee `pin`
`adc_setup()`           | Configura el `adc` 
`adc_setup()`           | Configura el canal del `adc`
`sleep(time)`           | Retardo en `seg`
`sleep_us(time)`        | Retardo en `microseg`
`sleep_ms(time)`        | Retardo en `miliseg`

## Tiempo
```go
sleep(5)		// Tiempo de 5 segundos
sleep_us(10)	// Tiempo de 10 microsegundos
sleep_ms(500)	// Tiempo de 500 milisegundos

```

## Configuración de pines 
```go
pin_setup(a5_s, out)      // Función para configurar el pin como salida 
pin_setup(c2_s, out)      // Función para configurar el pin como salida
pin_setup(a2_s, input)    // Función para configurar el pin como entrada
pin_setup(c4_s, input)    // Función para configurar el pin como entrada

pin_high(a5)    // Función para encender el pin           
pin_low(a5)     // Función para apagar el pin

pin_write(a2, 0)  // Función sobre escribir el pin en 0
pin_write(a2, 1)  // Función sobre escribir el pin en 1 

```

Ejemplo de prender y apagar un led:

```go

ANSEL = 0b00000000; // Todas los pines son I/O digitales
      
while (1) {

    pin_high(c1);
    sleep_us(500);
    pin_low(c1);
    sleep_us(500);

}

```
Ejemplo de prender y apagar un led con una entrada digital:

```go

ANSEL = 0b00000000; // Todas los pin son I/O digitales

while(1){
    
    if(c2 == 1){        // Condición si encuentra un 1 en el pin c2
        
        pin_high(c1);
        pin_high(c0);
    }
    
    else if(c4 == 1){   // Condición si encuentra un 1 en el pin c4
        
        pin_low(c1);
        pin_low(c0);
    }

}
        
```

## Configuración del ADC
```go
adc_setup()     // Inicializa el ADC
adc_read(0)     // Escoge el pin del canal analogico

```

Ejemplo de prender y apagar leds dependiendo del valor del ADC:
```go
unsigned int adc_result;  // Declaración de variable para guardar el valor del ADC
        
while(1){
            
    adc_result = adc_read(0); // Almacena el valor del ADC
    
    if ( adc_result >= 1020 ){
        
        c0 = 1;
        c1 = 1;
        c2 = 1;           
    }
    
    else if ( adc_result >= 820 ){
        
        c0 = 1;
        c1 = 1;
        c2 = 0;
    }
    
    else if ( adc_result >= 620 ){
        
        c0 = 1;
        c1 = 0;
        c2 = 0;    
    }
        
    else {
        
        c0 = 0;
        c1 = 0;
        c2 = 0;      
    }

}

```