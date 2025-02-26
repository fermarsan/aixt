module time

fn C.Wait(t any)
fn C.FirstTick() u32
fn C.CurrentTick() u32


@[as_macro] 
pub fn sleep_ms(ms any) { 
	C.Wait(ms) 
}	

@[as_macro] 
pub fn sleep(ts any) {
	C.Wait(ts*1000) 
}	

@[as_macro] 
pub fn read_tick() u32 {
	return C.CurrentTick()
}	

@[as_macro] 
pub fn read_first_tick() u32 {
	return C.FirstTick()
}