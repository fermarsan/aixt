// Project name: Aixt,
 https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F87x port)
module adc


@[as_macro] pub const all_analogs		= 0b0000_0000
@[as_macro] pub const all_analogs_rp	= 0b0000_0001
@[as_macro] pub const in0_to_in4		= 0b0000_0010
@[as_macro] pub const in0_to_in4_rp	= 0b0000_0011
@[as_macro] pub const in0_in1_in3		= 0b0000_0100
@[as_macro] pub const in0_in1_rp		= 0b0000_0101
@[as_macro] pub const all_digitals		= 0b0000_0110
// @[as_macro] pub const all_digitals		= 0b0000_0111
@[as_macro] pub const all_analogs_rp_rn	= 0b0000_1000
@[as_macro] pub const in0_to_in5		= 0b0000_1001
@[as_macro] pub const in0_to_in5_rp	= 0b0000_1010
@[as_macro] pub const in0_to_in5_rp_rn	= 0b0000_1011
@[as_macro] pub const in0_to_in4_rp_rn	= 0b0000_1100
@[as_macro] pub const in0_in1_rp_rn		= 0b0000_1101
@[as_macro] pub const in0				= 0b0000_1110
@[as_macro] pub const in0_rp_rn		= 0b0000_1111

// Project name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F87x port)


@[inline]
pub fn read(channel u16) u16 {
    C.ADCON0bits.CHS = channel  // Assigns the ADC channel
    C.ADCON0bits.GO_DONE = 1    // Starts conversion
    for C.ADCON0bits.GO_DONE == 1 {}	// Waits for conversion to end
    return (C.ADRESH << 8) | C.ADRESL   // Return the ADC value
}

// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Cesar Alejandro Roa Acosta and Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: ADC management functions
//              (PIC16F87x port)


@[inline]
pub fn setup() {
	C.ADCON1 = 0b10000000
    C.ADCON0 = 0b11001000
    C.ADCON0bits.ADON = 1
}

/*fn setup() u16 {
    ADCON1 = 0b10000000       /* Vref = VSS y GND, Configuracion de entradas analogicas */ 
    ADCON0 = 0b11001000       /* Configura el modulo ADC */
    ADCON0bits.ADON = 1       /* Tiempo de adquisicion, Justificacion hacia la derecha */
}
*/




/*@[inline]
pub fn setup() {
	C.\
}
    ADCON1 = 0b10000000 /* Ajusta todos los canales como analogicos */ \
    ADCON0 = 0b11001000 /* Ajusta todos las entradas como analogicos */\
    ADCON0bits.ADON = 1
*/
