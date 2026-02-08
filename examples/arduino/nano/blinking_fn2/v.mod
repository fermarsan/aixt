Module {
	name: 'main'
	description: ''
	version: ''
	license: ''
	dependencies: []
	target: ['nano']
	port: ['/dev/ttyUSB0']
	cc: [
		'/home/fercho/.local/bin/arduino-cli', 
		'compile -b arduino:avr:nano -v --output-dir ~/blinking_fn2/build'
		]
	flasher: ['', '']
}
