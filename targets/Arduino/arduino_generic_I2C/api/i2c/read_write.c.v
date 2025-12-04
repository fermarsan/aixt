// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Date: 2024

module i2c

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn start(address u8) {  
	C.WIRE_BEGINTRANSMISSION(address)
}

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn stop() {  
	C.WIRE_ENDTRANSMISSION()
}

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn write(data u8) {  
	C.WIRE_WRITE(data)
}

// print function prints data to the serial port as human-readable ASCII text
@[as_macro]
pub fn read() u8 {  
	return C.WIRE_READ()
}

// // print function prints data to the serial port as human-readable ASCII text
// @[as_macro]
// pub fn read_from(address u8, quantity int) {  
//     C.WIRE_REQUESTFROM(address, quantity) // Solicitar 'quantity' bytes al esclavo 'address'

//     // Leer y procesar los datos disponibles
//     for {
       
//         if  C.WIRE_AVAILABLE() <= 0 {
//             break // Salir si no hay más datos disponibles
//         }

//         data := C.WIRE_READ() // Leer un byte
//     }
// }