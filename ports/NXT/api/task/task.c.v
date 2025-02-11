// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024-2025
// License: MIT
//
// Description: Tasks module for NXT (NXC backend)

module task

fn C.Yield() 
fn C.StopAllTasks() 
fn C.ExitTo(args ...any)
fn C.Precedes(args ...any)
fn C.Follows(args ...any)
fn C.Acquire(args ...any)
fn C.Release(args ...any)
fn C.StartTask(args ...any)
fn C.StopTask(args ...any)



@[as_macro]
pub fn yield() {
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
pub fn priority(tasks ...any) {
	C.Precedes(...tasks) 
}

@[as_macro]
pub fn inv_priority(tasks ...any) {
	C.Follows(...tasks) 
}

@[as_macro]
pub fn mutex_lock(m any) {
	C.Acquire(m) 
}

@[as_macro]
pub fn mutex_unlock(m any) {
	C.Release(m) 
}

@[as_macro]
pub fn spawn(t any) {
	C.StartTask(t) 
}

@[as_macro]
pub fn stop(t any) {
	C.StopTask(t) 
}
