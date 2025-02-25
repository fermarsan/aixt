// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// Date: 2024

// module i2c

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