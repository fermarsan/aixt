import v.ast
import v.token
import v.pref
import v.parser
import v.checker
import v.ast.walker
import v.transformer


fn main() {

	path := './tst.v'

	mut vpref := &pref.Preferences{}
	vpref.is_script = true	// enable script mode
	table := ast.new_table()	

	// ---------- Parsing ----------
	mut tree := parser.parse_file(path, table, .skip_comments, vpref)
	mut checker_ := checker.new_checker(table, vpref)
	checker_.check(tree)

	// println(tree)
	// println('_'.repeat(60) + '\n')

	walker.inspect(tree, unsafe { nil }, unsafe{ gen } )

}

fn gen(node &ast.Node, data voidptr) bool {
	// match node {
	// 	ast.Stmt {
	// 		match node {
	// 			ast.FnDecl {
	// 				if node.is_main {
	// 					attrs	 := ''
	// 					ret_type := if node.return_type == ast.void_type_idx { 'void' } else { 'int' }
	// 					params 	 := if node.params == [] { 'void' } else { 'int' }
	// 					// stmts	 := 
	// 					println(node.stmts)
	// 					gen.output += '${attrs} ${ret_type} main(${params}) {\n${gen.stmt_list.reverse().join('\n')}\n}'
	// 					gen.stmt_list = []
	// 					gen.output = if gen.output[0] == ` ` { gen.output[1..] } else { gen.output } 
	// 					// println(node.stmts)
	// 				} else {}
	// 			}
	// 			ast.AssignStmt {
	// 				println('posx: ${node.pos}')
	// 				if node.op == token.Kind.decl_assign {
	// 					for i in 0..node.left.len {
	// 						var_type := ast.new_table().type_symbols[ node.right_types[i].idx() ]
	// 						gen.stmt_list << '${i}\t${var_type} ${node.left[i]} = ${node.right[i]};'
	// 					}
	// 				} 
	// 			}
	// 			else{} 
	// 		}
	// 	} 
	// 	ast.IfBranch {
	// 		gen.output += 'if(${node.cond}){\n}\n'
	// 		println(node.scope)
	// 	}
	// 	else {}
	// }
	println(node.type_name())
	println('${node}\n')		
	return true
}


