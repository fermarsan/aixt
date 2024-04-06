

asm rv32 {
	add		x1, x2, x3
	add		x4, x1, x0 
	AD1PCFG = 0xFFDF;     // Analog inputs for Explorer16 POT and TSENS
	AD1CSSL = 0;           	// no scanning required
}