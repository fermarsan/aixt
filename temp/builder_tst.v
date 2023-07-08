import v.builder
import v.pref

mut aixt_pref := &pref.Preferences{}

mut aixt_builder := builder.new_builder(aixt_pref)

text := 'a, b := 3, 4.5'

println(typeof(aixt_builder).name)

// println(aixt_builder.compiled_dir)
// aixt_builder.interpret_text(text, [''])!
// println(aixt_builder.get_builtin_files())
aixt_builder.info('xxxxx')



