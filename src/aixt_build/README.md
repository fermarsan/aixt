## Description:

`aixt_build` is the module which contains the functions to transpile and compile **Aixt** source code.

## Example:

```v cgen
import aixt_build

fn main() {
    port, input_name := 'Emulator', 'example.v'
    base_name = input_name.replace('.v', '')
    setup := toml.parse_file('aixt/ports/setup/Emulator.toml') or { return }

    aixt_build.transpile_file(input_name, setup, aixt_path)
    println('\n${input_name} transpiling finished.\n')

    aixt_build.compile_file(base_name, setup)
    ext := match setup.value('backend').string() {
    	'nxc' { 'nxc' }
    	'arduino' { 'ino' }
    	else { 'c' }
    }
    println('\n${base_name}.${ext} compiling finished.\n')
}
```