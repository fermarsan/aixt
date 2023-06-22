import v.ast
import v.pref
import aixt_cgen

fn main() {
	mut my_gen := aixt_cgen.Gen{
		file: &ast.File{}
		pref: &pref.Preferences{}
		table: ast.new_table()
		out: ''
	}

	my_gen.pref.is_script = true
	
	println(my_gen.gen('tst2.v'))
}
