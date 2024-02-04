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

name                    | description
------------------------|------------------------------
`pin_high(pin)`         | Encender `pin`
`pin_low(pin)`          | Apagar `pin`
`pin_write(pin, val)`   | Escribe `val` en `pin`
`pin_read(pin)`         | lee `pin`
`sleep(time)`           | Retardo en `seg`
`sleep_us(time)`        | Retardo en `microseg`
`sleep_ms(time)`        | Retardo en `miliseg`

## Tiempo
```go
sleep(5)	// Tiempo de 5 segundos
sleep_us(10)	// Tiempo de 10 microsegundos
sleep_ms(500)	// Tiempo de 500 milisegundos

```

## Configuración de pines 
```go
pin_setup(a4_s, out)      // Función para configurar el pin como salida 
pin_setup(b2_s, out)      // Función para configurar el pin como salida
pin_setup(a2_s, input)    // Función para configurar el pin como entrada
pin_setup(b4_s, input)    // Función para configurar el pin como entrada

pin_high(a4)    // Función para encender el pin           
pin_low(a4)     // Función para apagar el pin

pin_write(a2, 0)  // Función sobre escribir el pin
pin_write(a2, 1)  // Función sobre escribir el pin

pin_read(a1)  // Función para leer el pin
pin_read(a1)  // Función para leer el pin

```

Ejemplo de prender y apagar un led:

```go
      
while (1) {

    pin_high(b1);
    sleep_us(500);
    pin_low(b1);
    sleep_us(500);

}

```
Ejemplo de prender y apagar un led con una entrada digital:

```go

ANSEL = 0b00000000; // Todas los pin son I/O digitales

while(1){
    
    if(b2 == 1){        // Condición si encuentra un 1 en el pin b2
        
        pin_high(b1);
        pin_high(b0);
    }
    
    else if(b4 == 1){   // Condición si encuentra un 1 en el pin b4
        
        pin_low(b1);
        pin_low(b0);
    }

}
        
```