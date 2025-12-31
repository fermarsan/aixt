// Author: Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
// Date: 2022-2025
//
// ## Description
// time functions (CY8CKIT-145-40XX)

module time

// sleep is a delay function in microseconds for Arduino devices
@[as_macro]
pub fn sleep_us(tus any) {
	C.CyDelayUs(tus)
}
