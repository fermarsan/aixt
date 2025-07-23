// Project name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module cgen

import v.ast
// import regex

// for_in_stmt is the code generation function for the 'for in' statements.
fn (mut gen Gen) for_in_stmt(node ast.ForInStmt) []string {
	// println('>>>>>>>>>>>>>>>>>> ${node} <<<<<<<<<<<<<<<<<<')
	mut out := []string{}
	init_or_name := gen.ast_node(node.cond).join('')
	mut stmts := []string{}
	if node.is_range { // in a range
		index_name := node.val_var
		max_val := gen.ast_node(node.high).join('')
		for st in node.stmts {
			stmts << gen.ast_node(st).join('')
		}
		out << $tmpl('c_templates/for_in_range.tmpl.c')#[..-1]
	} else if node.kind.str() in ['array', 'string'] {
		gen.level_count++
		index_name := '__i_${gen.level_count}' // temporal variables (indexes) by levels
		_, var_type := gen.get_str_c_type(ast.idx_to_type(node.val_type.idx()), false)
		obj := gen.find_obj_all_scopes(node.cond.str()) or {
			panic('Identifier "${node.cond.str()}" not found.')
		}
		var_name := node.val_var
		for st in node.stmts {
			stmts << gen.ast_node(st).join('')
		}
		mut mut_var_write := ''
		if node.val_is_mut {
			mut_var_write = $tmpl('c_templates/mut_var_in_array_write.tmpl.c')#[..-1] // var writing
		}
		if node.kind.str() == 'array' {
			len := match obj {
				// limit value
				ast.Var, ast.ConstField, ast.GlobalField { (obj.expr as ast.ArrayInit).exprs.len }
				else { panic('Identifier "${node.cond.str()}" not found.') }
			}
			out << $tmpl('c_templates/for_in_array.tmpl.c')#[..-1]
		} else if node.kind.str() == 'string' {
			out << $tmpl('c_templates/for_in_string.tmpl.c')#[..-1]
		}
		gen.level_count--
	}
	return out
}
