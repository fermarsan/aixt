// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Tasks module for NXT (NXC backend)

module task

@[as_macro]
pub fn yield(task) {
	C.Yield() 
}

@[as_macro]
pub fn stop_all() {
	C.StopAllTasks() 
}

@[as_macro]
pub fn exit_to(new_task any) {
	C.ExitTo(new_task) 
}

@[as_macro]
pub fn precedes(tasks ...any) {
	return C.Precedes(tasks) 
}

@[as_macro]
pub fn follows(tasks ...any) {
	return C.Follows(tasks) 
}

@[as_macro]
pub fn acquire(m any) {
	return C.Acquire(m) 
}

@[as_macro]
pub fn release(m any) {
	return C.Release(m) 
}

@[as_macro]
pub fn start_task(task any) {
	return C.StartTask(task) 
}

@[as_macro]
pub fn stop_task(task any) {
	return C.StopTask(task) 
}
