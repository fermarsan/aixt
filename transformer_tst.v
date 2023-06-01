import v.ast
import v.pref
import v.parser
import v.checker
import v.ast.walker
import v.transformer


nodes := []ast.Node{len: 100, init: unsafe {nil}}

path := './tst.v'

mut vpref := &pref.Preferences{}
vpref.is_script = true
table := ast.new_table()	

// ---------- Parsing ----------
mut tree := parser.parse_file(path, table, .skip_comments, vpref)
mut checker_ := checker.new_checker(table, vpref)
checker_.check(tree)

println(tree)
println('_'.repeat(60) + '\n')

walker.inspect(tree, unsafe { nil }, unsafe { fn (node &ast.Node, data voidptr) bool {
	println(node)
	// nodes[i] = nodeprintln(tree)
println('_'.repeat(60) + '\n')
	// i++
	return true
}})
println('_'.repeat(60) + '\n')

mut transf := transformer.new_transformer(vpref)
transf.transform(mut tree)
println(tree)
println('_'.repeat(60) + '\n')