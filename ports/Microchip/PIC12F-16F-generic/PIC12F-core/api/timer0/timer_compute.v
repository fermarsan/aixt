cpu_freq_mhz := 4
period := 80_000
mut prescaler := -2
mut initial := -1

for (initial < 0 || initial > 127) && prescaler <= 6 {
	prescaler++
	initial = 256 - int((period*cpu_freq_mhz) / (4*(1<<(prescaler+1))))
	t := (4*(1<<(prescaler+1))*(256-initial))/cpu_freq_mhz
	print('Initial: ${initial}\t')
	print('Prescaler: ${1<<(prescaler+1)}\t')
	println('T output [us]: ${t}')
}