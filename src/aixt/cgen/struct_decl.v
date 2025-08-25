// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
module cgen

import v.ast

// struct_decl is the code generation function for struct declaration
fn (mut gen Gen) struct_decl(node ast.StructDecl) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	match node.language {
		.v {
			name := node.name.replace('.', '__')
			if gen.setup.backend != 'nxc' {
				gen.definitions << 'typedef struct ${name} ${name};'
			}
			// type_def := if gen.setup.backend == 'nxc' {''} else {'typedef'}
			attrs := node.attrs.map(it.name).join(' ')
			mut fields := []string{}
			for field in node.fields {
				fields << gen.ast_node(field)
			}
			out << $tmpl('c_templates/struct_decl.tmpl.c')
		}
		else {
			out = ['']
		}
	}
	return out
}