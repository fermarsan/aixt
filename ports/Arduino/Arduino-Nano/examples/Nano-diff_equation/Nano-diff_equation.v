import time
import pin
import port
import adc

// R = 100 Ohm, C = 10 uF, fs = 5000 Hz, Ts = 200us

pin.setup(adc.ch0, pin.input)	// entrada
port.setup(port.d, port.all_outputs)	// salidas

pin.setup(pin.d8, pin.output)	// salida de referencia par el Ts

mut vck := 0 	// variables para los estados
mut vfk := 0	// actuales y anteriores
mut vck_1 := 0	// de la entrada y la salida
mut vfk_1 := 0

for {
    // paso 1: rotar los vectores de datos
    vfk_1 = vfk
    vck_1 = vck
    // paso 2: tomar una muestra nueva de la entrada
    vfk = adc.read(adc.ch0) >> 2   
    // paso 3: calcular el nuevo valor de la salida 
    //      (ecuación en diferencias)
    vck = int(f32(vck_1)*0.8187 + f32(vfk_1)*0.1813)
    // paso 4: actualizar la salida
    port.write(port.d, u8(vck))
	// paso 5: garantizar el Ts
	pin.high(pin.d8)
	pin.low(pin.d8)
	// time.sleep_us(66)
}