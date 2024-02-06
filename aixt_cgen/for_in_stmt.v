// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando Martínez Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast

// for_in_stmt is the code generation function for the 'for in' statements.
fn (mut gen Gen) for_in_stmt(node ast.ForInStmt) string {
	mut out := ''
	if node.high.type_name() == 'v.ast.EmptyExpr' { // in an array
		gen.level_cont++
		temp_name := '_t${gen.level_cont}'	// temp variables by levels
		if !gen.files[gen.file_count].scope.known_var(temp_name) {	//if doesn't exits, create it
			mut temp_var := ast.Var {
				name: temp_name
				typ: ast.Type(ast.Kind.int)
			}
			gen.files[gen.file_count].scope.objects[temp_name] = temp_var //
			gen.definitions << 'int ${temp_name};\n'
		}
		var := *gen.files[gen.file_count].scope.children[0].find_var(node.cond.str()) or { }
		out += 'for(int ${temp_name} = 0;'
		out += ' ${temp_name} < ${(var.expr as ast.ArrayInit).exprs.len};'
		out += ' ${temp_name}++) {\n'
		for st in node.stmts {
			out += gen.ast_node(st)
		}
		out = out.replace(node.val_var, '${gen.ast_node(node.cond)}[${temp_name}]')
	} else { // in a range
		out += 'for(int ${node.val_var}=${gen.ast_node(node.cond)}; '
		out += '${node.val_var}<${gen.ast_node(node.high)}; ${node.val_var}++) {\n'
		for st in node.stmts {
			out += gen.ast_node(st)
		}
	}
	gen.level_cont--
	return out + '}\n'
}