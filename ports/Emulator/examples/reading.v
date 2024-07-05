import adc

// j, k := 0, 0

fn addition(a int, b int) int {
	return a + b
}

i := addition(1, 2)
j := adc.read(adc.ch0)
k := adc.read(adc.ch1)