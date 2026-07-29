Module {
  target: "fire",
  board: "M5Stack FIRE",
  backend: "arduino",

  cc_name: "arduino_cli",
  cc_path: "arduino-cli",
  cc_args: "compile -b m5stack:esp32:m5stack_fire -v --output-dir @{file_dir_name}/build"
  
  flasher_name: "arduino_cli",
  flasher_path: "arduino-cli",
  flasher_args: "upload @{file_dir_name} -p @{port} -b m5stack:esp32:m5stack_fire"
  
  api_paths: [
    "m5stack/fire",
    "m5stack/core",
    "arduino/esp32",
    "arduino/core",
    "arduino/uart",
    "arduino/i2c"
  ],
  
  v_defines: [],
  default_cpu_freq: "240000000",
  default_string_len: "50",
  compiler_setup_path: "setup/arduino32.v.mod"
}