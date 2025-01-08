module time

@[inline] 
time.sleep_ms(ms u32) { 
	C.Wait(ms) 
}	

@[inline] 
time.sleep(ts u32) {
	 C.Wait(ts*1000) 
}	