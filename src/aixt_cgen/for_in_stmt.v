// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2023-2024
// License: MIT
module aixt_cgen

import v.ast
// import regex

// for_in_stmt is the code generation function for the 'for in' statements.
fn (mut gen Gen) for_in_stmt(node ast.ForInStmt) []string {
	mut out := []string{}
	mut c_line := ''
	init_or_name := gen.ast_node(node.cond).join('')
	if node.is_range { // in a range
		c_line += 'for(int ${node.val_var}=${init_or_name}; '	// initialization
		c_line += '${node.val_var}<${gen.ast_node(node.high).join('')}; '	// limit value
		out << c_line + '${node.val_var}++) {'	// increment
		for st in node.stmts {
			out << gen.ast_node(st).join('')
		}
	} else if node.kind.str() == 'array' {
		gen.level_count++
		index_name := '__i_${gen.level_count}'	// temporal variables (indexes) by levels

		val_var_kind := gen.table.type_kind( if node.val_is_mut {
												node.val_type ^ 0x10000	// for mutable vars
											 } else {
												node.val_type
											 } ).str()
		c_line += 'for(int ${index_name} = 0;'	// initialization		
		obj := gen.find_obj_all_scopes(node.cond.str()) or {
			panic('Identifier "${node.cond.str()}" not found.')
		}
		c_line += ' ${index_name} < ' + match obj {	// limit value
			ast.Var, ast.ConstField, ast.GlobalField { '${(obj.expr as ast.ArrayInit).exprs.len};' }
			else { panic('Identifier "${node.cond.str()}" not found..') }
		}
		out << c_line + ' ${index_name}++) {' // increment
		c_line = '${gen.setup.compiler_types[val_var_kind]} ${node.val_var} '	// var declaration
		out << c_line + '= ${init_or_name}[${index_name}];'	// var reading
		for st in node.stmts {
			out << gen.ast_node(st).join('')
		}
		if node.val_is_mut {
			out << '${init_or_name}[${index_name}] = ${node.val_var};'	// var writing
		} 
		gen.level_count--
	} 
	out << '}'
	return out
}

		// CREATING TEMPORAL VARIABLES

		// if !gen.files[gen.file_count].scope.known_var(index_name) {	//if doesn't exits, create it
		// 	mut temp_var := ast.Var {
		// 		name: index_name
		// 		typ: ast.Type(ast.Kind.int)
		// 	}
		// 	gen.files[gen.file_count].scope.objects[index_name] = temp_var //
		// 	gen.definitions << 'int ${index_name};'
		// }




	// USING REGULAR EXPRESSIONS AN POINTERS

	// } else if node.kind.str() == 'array' {
	// 	gen.level_count++
	// 	index_name := '__t${gen.level_count}'	// temporal variables (indexes) by levels
	// 	if !gen.files[gen.file_count].scope.known_var(index_name) {	//if doesn't exits, create it
	// 		mut temp_var := ast.Var {
	// 			name: index_name
	// 			typ: ast.Type(ast.Kind.int)
	// 		}
	// 		gen.files[gen.file_count].scope.objects[index_name] = temp_var //
	// 		gen.definitions << 'int ${index_name};'
	// 	}
	// 	obj := gen.find_obj_all_scopes(node.cond.str()) or { 
	// 		panic('Identifier "${node.cond.str()}" not found.') 
	// 	}
	// 	// println('=============== ${obj} ===============')
	// 	val_var_kind := gen.table.type_kind(node.val_type).str()
	// 	// declare the element variable as pointer
	// 	out << '${gen.setup.value(val_var_kind).string()} *${node.val_var} = &${gen.ast_node(node.cond).join('')}[0];'
	// 	c_line += 'for(int ${index_name} = 0;'
	// 	c_line += ' ${index_name} < ' + match obj {
	// 		ast.Var, ast.ConstField, ast.GlobalField { '${(obj.expr as ast.ArrayInit).exprs.len};' }
	// 		else { '__not_found__;' }
	// 	}
	// 	out << c_line + ' ${index_name}++) {'
	// 	// a RE for looking for the var name
	// 	mut re := regex.regex_opt('(\\W)(${node.val_var})(\\W)') or { panic(err) }	
	// 	for st in node.stmts {
	// 		stmt := ' ' + gen.ast_node(st).join('')	// each statement plus initial space
	// 		// replace the val_var for the equivalent pointer syntax
	// 		out_stmt := re.replace_by_fn(stmt, 
	// 			fn (re regex.RE, in_txt string, start int, end int) string {
	// 				g0 := re.get_group_by_id(in_txt, 0)
	// 				g1 := re.get_group_by_id(in_txt, 1)
	// 				g2 := re.get_group_by_id(in_txt, 2)
	// 				return'${g0}*(${g1})${g2}'	// pointer syntax
	// 			}
	// 		)
	// 		out << out_stmt[1..]	// ommit the added space
	// 	}
	// 	// if node.val_is_mut {
	// 	// 	out << '${gen.ast_node(node.cond).join('')}[${index_name}] = ${node.val_var};'	// write the element by index
	// 	// } 
	// 	out << '${node.val_var}++;'
	// } 