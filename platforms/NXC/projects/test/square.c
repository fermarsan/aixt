//Generated NXC file for:  Device = Atmel AT91SAM7S256  Board = LEGO Mindstorms NXC intelligent brick//User defined headers files

int main(void) {

	//AD1PCFG = 0xFFFF; // set all I/O digital
	OnFwd(OUT_AB);
	Wait(1000);
	Off(OUT_A);
	Wait(500);
	OnFwd(OUT_AB);
	Wait(1000);
	Off(OUT_A);
	Wait(500);
	OnFwd(OUT_AB);
	Wait(1000);
	Off(OUT_A);
	Wait(500);
	OnFwd(OUT_AB);
	Wait(1000);
	Off(OUT_A);
	Wait(500);
	
	return 0;
}