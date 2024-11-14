#define PIN_SETUP(NAME, MODE)	\	
	if MODE == 1 { /* as input (1) */ \
		*(&TRISA + (NAME >> 3)) |= (0x01 << (NAME - ((NAME >> 3) << 3))) \
	/*  *(&TRISA + (NAME / 8))  |= (0x01 << (NAME % 8))  */ \
	} else { /* as output (0) */ \
		*(&TRISA + (NAME >> 3)) &= ~(0x01 << (NAME - ((NAME >> 3) << 3))) \	
	/*  *(&TRISA + (NAME / 8))  &= ~(0x01 << (NAME % 8)) */ \
	} \