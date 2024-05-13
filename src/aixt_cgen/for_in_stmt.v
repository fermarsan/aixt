// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// for_in_stmt is the code generation function for the 'for in' statements.
fn (mut gen Gen) for_in_stmt(node ast.ForInStmt) []string {
	mut out := []string{}
	mut c_line := ''
	if node.high.type_name() == 'v.ast.EmptyExpr' { // in an array
		gen.level_count++
		temp_name := '_t${gen.level_count}'	// temp variables by levels
		if !gen.files[gen.file_count].scope.known_var(temp_name) {	//if doesn't exits, create it
			mut temp_var := ast.Var {
				name: temp_name
				typ: ast.Type(ast.Kind.int)
			}
			gen.files[gen.file_count].scope.objects[temp_name] = temp_var //
			gen.definitions << 'int ${temp_name};'
		}
		var := *gen.files[gen.file_count].scope.children[0].find_var(node.cond.str()) or { }
		c_line += 'for(int ${temp_name} = 0;'
		c_line += ' ${temp_name} < ${(var.expr as ast.ArrayInit).exprs.len};'
		out << c_line + ' ${temp_name}++) {'
		for st in node.stmts {
			out << gen.ast_node(st).join('\n').replace(node.val_var, '${gen.ast_node(node.cond).join('')}[${temp_name}]')
		}
		// out = out.replace(node.val_var, '${gen.ast_node(node.cond)}[${temp_name}]')
	} else { // in a range
		c_line += 'for(int ${node.val_var}=${gen.ast_node(node.cond).join('')}; '
		out << c_line + '${node.val_var}<${gen.ast_node(node.high).join('')}; ${node.val_var}++) {'
		for st in node.stmts {
			out << gen.ast_node(st)
		}
	}
	gen.level_count--
	out << '}'
	return out
}