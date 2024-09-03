// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
// Description: setup files loading for the device and the compiler
module aixt_setup


// Setup is the struct load the setup files data
pub struct Setup {
pub mut:
	device				string
	port 				string
	board 				string
	backend 			string
	cc_linux 			string
	cc_windows 			string
	cc_flags			string
	cc_output_flag		string
	cc_input_flag 		string	
	makefile_flags		string
	api_paths			[]string
	v_defines			[]string
	string_default_len	int
	main_ret_type		string 
	main_params  		string 
	compiler_types		map[string]string
}
