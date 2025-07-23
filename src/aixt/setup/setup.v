// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
// Description: setup files loading for the device and the compiler
module setup


// Setup is the struct load the setup files data
pub struct Setup {
pub mut:
	device				string	@[skip]
	port 				string
	board 				string
	backend 			string
	cc_linux 			string
	cc_windows 			string
	cc_make_flags		string
	flasher_linux 		string
	flasher_windows 	string
	flasher_flags		string
	api_paths			[]string
	v_defines			[]string
	default_cpu_freq	int
	default_string_len	int
	compiler_setup_path string
	main_ret_type		string 
	main_params  		string 
	compiler_types		map[string]string
}
