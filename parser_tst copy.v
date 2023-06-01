import v.ast
import v.token
import v.pref
import v.parser
import v.checker
import v.ast.walker
import v.transformer


struct AixtGen {
mut:
	output		string
	curr_id		int
	id_count	int
}

fn main() {

	path := './tst.v'

	mut vpref := &pref.Preferences{}
	vpref.is_script = true	// enable script mode
	table := ast.new_table()	

	// ---------- Parsing ----------
	mut tree := parser.parse_file(path, table, .skip_comments, vpref)
	mut checker_ := checker.new_checker(table, vpref)
	checker_.check(tree)
	mut t := transformer.new_transformer(vpref)
	t.transform(mut tree)

	mut aixt_gen := AixtGen{
		output:		''
		curr_id:	1
		id_count: 	1
	}

	walker.inspect(tree, unsafe { nil }, unsafe{ aixt_gen.gen } )
	// println(aixt_gen.output)

}

fn (mut gen AixtGen) gen(node &ast.Node, data voidptr) bool {
	match node {
		ast.Stmt {
			match node {
				ast.FnDecl {
					if node.is_main {
						attrs	 := ''
						ret_type := if node.return_type == ast.void_type_idx { 'void' } else { 'int' }
						params 	 := if node.params == [] { 'void' } else { 'int' }
						gen.output += '${attrs} ${ret_type} main(${params}) {\n${gen.temp_block_stmts(node.stmts.len)}}'
						gen.output = if gen.output[0] == ` ` { gen.output[1..] } else { gen.output } 
					} else {
						// attrs	 := ''
						// ret_type := if node.return_type == ast.void_type_idx { 'void' } else { 'int' }
						// params 	 := if node.params == [] { 'void' } else { 'int' }
						// gen.output += '${attrs} ${ret_type} main(${params}) {\n${gen.temp_block_stmts(node.stmts.len)}}'
						// gen.output = if gen.output[0] == ` ` { gen.output[1..] } else { gen.output } 
					}
				}
				ast.AssignStmt {
					mut assign := ''
					for i in 0 .. node.left.len {
						if node.op == token.Kind.decl_assign {	// in case of declaration 
							var_type := ast.new_table().type_symbols[ node.right_types[i].idx() ] 
							assign += '${var_type} ${node.left[i]} ${node.op} ${node.right[i]};\n'
						} else {	// for the rest of assignments
							assign += '${node.left[i]} ${node.op} ${node.right[i]};\n'
						}
					}
					gen.output = gen.output.replace('__stmt_${gen.curr_id++}__\n', assign) 
				}
				else{} 
			}
		} 
		ast.IfBranch {
			// mut output := 'if-else'
			mut output := if node.cond.type_name() == 'v.ast.InfixExpr' { 'if(${node.cond})' }	// 'if' token 
						  else { 'else' }	// 'else' token
			output += '{\n${gen.temp_block_stmts(node.stmts.len)}}\n'
			println(output + '-'.repeat(30))
			// println(gen.output)
			gen.output = gen.output.replace('__stmt_${gen.curr_id++}__\n', output) 
			// println('cond: ${node.cond.type_name()}')
			// println(node.stmts)
			// println(gen.output)
		}
		else {}
	}
	println(gen.output + '\n' + '_'.repeat(60))	
	return true
}

fn (mut gen AixtGen) temp_block_stmts(n int) string {
	mut output := ''
	for id in gen.id_count .. gen.id_count + n {
		output += '__stmt_${id}__\n'
		// println('generated: ${output}')
	}
	gen.id_count += n
	return output
}