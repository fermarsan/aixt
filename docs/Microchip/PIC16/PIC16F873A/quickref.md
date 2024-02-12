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

name                             | description
---------------------------------|------------------------------------------------------
`pin_high(pin)`                  | Encender `pin`
`pin_low(pin)`                   | Apagar `pin`
`pin_write(pin, val)`            | Escribe `val` en `pin`
`pin_read(pin)`                  | lee `pin`
`adc_setup()`                    | Configura el `adc` 
`adc_read(channel)`              | Configura el canal `channel` del `adc`
`adc_reading()`                  | Alamacena el valor del `adc`
`pwm_setup(pin1, pin2)`          | Configura el resgitro `pin1` y la salida en `pin2`
`pwm_write(duty, pin)`           | Calcula el `duty` del `pwm` y lo alamcena en `pin` 
`uart_setup()`                   | Configura el `uart`
`print(menssage)`                | Configura el `menssage` y lo `print`
`sleep(time)`                    | Retardo en `seg`
`sleep_us(time)`                 | Retardo en `microseg`
`sleep_ms(time)`                 | Retardo en `miliseg`

## Tiempo
```go
sleep(5)	// Tiempo de 5 segundos
sleep_us(10)	// Tiempo de 10 microsegundos
sleep_ms(500)	// Tiempo de 500 milisegundos

```

## Configuración de pines 
```go
pin_setup(a5_s, out)      // Función para configurar el pin como salida 
pin_setup(b7_s, out)      // Función para configurar el pin como salida
pin_setup(a0_s, input)    // Función para configurar el pin como entrada
pin_setup(c4_s, input)    // Función para configurar el pin como entrada

pin_high(a5)    // Función para encender el pin           
pin_low(a5)     // Función para apagar el pin

pin_write(a2, 0)  // Función sobre escribir el pin
pin_write(a2, 1)  // Función sobre escribir el pin

pin_read(b4)      // Función para leer el pin
pin_read(c7)      // Función para leer el pin
```

Ejemplo de prender y apagar un led:

```go
      
while (1) {

    pin_high(c7);
    sleep_us(500);
    pin_low(c7);
    sleep_us(500);

}

```
Ejemplo de prender y apagar un led con una entrada digital:

```go

while(1){
    
    if(b4 == 1){        // Condición si encuentra un 1 en el pin c2
        
        pin_high(a4);
        pin_high(a5);
    }
    
    else if(b5 == 1){   // Condición si encuentra un 1 en el pin c4
        
        pin_low(a4);
        pin_low(a5);
    }

}
        
```
## Configuración del ADC
```go
adc_setup()     // Inicializa el ADC
adc_read(0)     // Escoge el pin del canal analogico
adc_reading();  // Almacena el valor del ADC en una función

```

Ejemplo de prender y apagar leds dependiendo del valor del ADC:
```go
unsigned int adc_result;  // Declaración de variable para almacenar el valor del ADC
        
while(1){
            
    adc_result = adc_reading(); // Almacena el valor del ADC
    
    if ( adc_result >= 1020 ){
        
        pin_high(b0);
        pin_high(b1);
        pin_high(b2);           
    }
    
    else if ( adc_result >= 820 ){
        
        pin_high(b0);
        pin_high(b1);
        pin_low(b2);
    }
    
    else if ( adc_result >= 620 ){
        
        pin_high(b0);
        pin_low(b1);
        pin_low(b2);   
    }
        
    else {
        
        pin_low(b0);
        pin_low(b1);
        pin_low(b2);      
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
    
        adc_read(2);  // Escoge el canal analogico AN2
        adc = adc_reading();  // Almacena el valor del ADC
        
        pwm_write(adc,2);  // Realiza el calculo del Duty y lo guarda en CCP2
        
    }

```

## Configuración del UART Transmisión
```go
uart_setup()     // Inicializa la comunicación serial
print()          // Alamacena los caracteres, revisa que no haya ningún caracter nulo

```
Ejemplo de variar el valor del ADC y visualizarlo en un mensaje:

```go

while(1){
        
    adc_read(0);
              
    adc = adc_reading();
         
    sprintf(caracteres, "ADC CH0: %u\r\n", adc); // Cambia el formato del ADC
    print(caracteres);   // Imprime el mensaje
    __delay_ms(200);     // Tiempo para no saturar la ventana de mensajes 
    
    }

```

## Configuración del UART Recepción
```go
uart_setup()     // Inicializa la comunicación serial
print()          // Alamacena los caracteres, revisa que no haya ningún caracter nulo
uart_read()      // Almacena los datos recibidos que envia el otro dispositivo

```
Ejemplo de variar el valor del ADC y visualizarlo en un mensaje:

```go

char datos;    // Variable almacena los datos de la función uart_read

void main(void) {
    
    ADCON1bits.PCFG = 0;   // Declara todos los pines como digitales 
    
    pin_setup(b0_s,out);   // Configuracion del pin
    pin_setup(b1_s,out);   // Configuracion del pin
    
    pin_write(b0,0);       // Incializa el pin como apagado
    pin_write(b1,0);       // Incializa el pin como apagado
    
    while(1){
        
        if(uart_input ()> 0){    // Verifica si hay datos para ser leidos
                       
            datos = uart_read();  // Almacena los datos de la funcion uart_read
        
        }
        
        switch (datos){
            
            case 'a':                         // Si el dato enviado es el caracter "a" 
                
                pin_high(b0);                 // Enciende el led que se encuentra en el pin b0
                print("led1: Encendido\r\n"); // Imprime el mensaje en la pantalla 
                break;  
                
            case 'b':                         // Si el dato enviado es el caracter "b" 
                
                pin_low(b0);                 // Apaga el led que se encuentra en el pin b0
                print("led1: Apagado\r\n");  // Imprime el mensaje en la pantalla 
                break;
        }
    }

```