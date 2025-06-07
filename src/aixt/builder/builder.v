// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2025
// License: MIT

// Description: This file contains the C code generation functions of the Aixt.
module builder

import aixt.setup
import v.ast
import v.token
import v.pref
import v.builder
import v.parser
import v.checker
import os

// Gen is the struct that defines all the necessary data for the code generation
pub struct Builder {
pub mut:
	builder.Builder
	setup			setup.Setup
	aixt_path		string
}