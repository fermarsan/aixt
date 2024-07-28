module time

@[inline] 
sleep_ms(ms u32) { 
	C.Wait(ms) 
}	

@[inline] 
sleep(ts u32) {
	 C.Wait(ts*1000) 
}	