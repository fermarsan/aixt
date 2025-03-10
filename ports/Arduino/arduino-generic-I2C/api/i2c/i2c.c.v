// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Date: 2024
// Description: I2C module.

//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN I2C
#include <Wire.h>
#include "i2c.c"

fn C.WIRE_BEGIN(args ...any) //Inicializar el bus I2C "define comunicación"
fn C.WIRE_END() // Cerrar el bus I2C
fn C.WIRE_REQUESTFROM(args ...any)// Solicitar bytes de un dispositivo periférico
fn C.WIRE_BEGINTRANSMISSION(args ...any) // Comienza a poner en cola una transmisión
fn C.WIRE_ENDTRANSMISSION(args ...any) // Transmitir los bytes que se han puesto en cola y finalizar la transmisión
fn C.WIRE_WRITE(args ...any) // Escribe datos desde el periférico al controlador o viceversa
fn C.WIRE_AVAILABLE(args ...any) int // Devuelve el número de bytes disponibles para la recuperación
fn C.WIRE_READ(args ...any) u8 // Lee un byte que se transmitió desde un periférico a un controlador.
fn C.WIRE_SETCLOCK(args ...any) // Modificar la frecuencia del reloj
fn C.WIRE_ONRECEIVE(args ...any) // Registrar una función a la que se llamará cuando un periférico reciba una transmisión
fn C.WIRE_ONREQUEST(args ...any) // Registrar una función que se llamará cuando un controlador solicite datos
fn C.WIRE_SETWIRETIMEOUT(args ...any) // Establece el tiempo de espera para las transmisiones en el modo de controlador
fn C.WIRE_CLEARWIRETIMEOUTFLAG(args ...any) // Borra el indicador de tiempo de espera
fn C.WIRE_GETWIRETIMEOUTFLAG(args ...any) bool // Comprueba si se ha agotado el tiempo de espera desde la última vez que se borró el indicador.
