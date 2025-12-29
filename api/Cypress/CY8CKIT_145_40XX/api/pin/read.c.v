// _File:_ https://github.com/fermarsan/aixt/blob/main/
//
// _Author:_ Fernando M. Santa - Daniel Polo - Edwin Barrera - Javier Leon - Camilo Lucas
//
// _Date:_ 2022-2025
//
// // ## Description
// pin read functions (CY8CKIT-145-40XX)

module pin

@[as_macro]
pub fn read(name any) u8 {
	return C.PIN_READ(name)
}
