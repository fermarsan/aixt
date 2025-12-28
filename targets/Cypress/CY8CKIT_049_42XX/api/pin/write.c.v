// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
//
// _Date:_ 2022-2025
//
// // ## Description
// pin write functions (CY8CKIT-049-42XX)

module pin

@[as_macro]
pub fn write(name any, value any) {
	C.PIN_WRITE(name, value)
}
