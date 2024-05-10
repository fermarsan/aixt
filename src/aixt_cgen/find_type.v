// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2024
// License: MIT
module aixt_cgen

import v.ast

// find_type recursively finds the type of a expresion.
fn (mut gen Gen) find_type(node ast.Expr) ast.Kind {
	// gen.sym_table_print()
	// println(gen.files[gen.file_count].scope)
	mut expr_type := ast.new_type(1)	// initialized void
	match node {
		ast.Ident {
			// ident_name := '${(node as ast.Ident).mod}.${(node as ast.Ident).name}'
			ident_name := (node as ast.Ident).name
			obj := gen.find_object(ident_name) or {
				panic('Identifier "${ident_name}" not found.') 
			}
			expr_type = obj.typ
		}
		else {
			return .void
		}
	}
	return gen.table.type_kind(expr_type)
}