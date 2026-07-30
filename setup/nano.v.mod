Module {
  target: ['nano']
  board: ['Arduino Nano']
  backend: ['arduino']

  cc_name: ['arduino_cli']
  cc_path: ['arduino-cli']
  cc_args: ['compile -b arduino:avr:nano -v --output-dir @{file_dir_name}/build']

  flasher_name: ['arduino_cli']
  flasher_path: ['arduino-cli']
  flasher_args: ['upload @{file_dir_name} -p @{port} -b arduino:avr:nano']
  
  api_paths: [
    'arduino/nano',
    'arduino/avr',
    'arduino/core',
    'arduino/uart',
    'arduino/i2c'
  ]

  v_defines: []
  default_cpu_freq: ['16000000']
  default_string_len: ['50']
  compiler_setup_path: ['setup/arduino8.v.mod']
}