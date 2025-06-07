// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT

// Description: This file contains the C code generation functions of the Aixt.
module builder

import aixt.setup as aixt_setup
import v.builder as v_builder

// Gen is the struct that defines all the necessary data for the code generation
pub struct Builder {
	v_builder.Builder
pub:
	setup			aixt_setup.Setup
	aixt_path		string
}