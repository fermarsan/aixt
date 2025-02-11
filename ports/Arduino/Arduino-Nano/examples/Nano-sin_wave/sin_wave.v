import vsl.plot
import vsl.util
import math

// Generates a 60Hz sine wave from 0 to 255 (value levels)
f := 60.0	// Hz
v_min := 0		// steps
v_max := 255	// steps

samples := 100

t := util.lin_space(0, 1/f, samples+1)		// 1 period
y := t.map((math.sin(2*math.pi*f*it) + 1) * (v_max-v_min) / 2)	// sin wave: y = sin(2πft)

// ploting the wave
mut plt := plot.Plot.new()

plt.scatter(
	x: t
	y: y
)

plt.layout(
	title: 'Sin wave (60Hz)'
	xaxis: plot.Axis { 
		title: plot.AxisTitle { 'time [s]' } 
	}
	yaxis: plot.Axis { 
		title: plot.AxisTitle { 'amplitude [steps]' } 
	}
)

plt.show()!

// generate the table to copy on Aixt
print('const y = [\n\tu8(${u8(y[0])}), ')
for n in 1 .. y.len-1 {
	if (n % 10) == 0 {
		print('\n\t')
	}
	print('${u8(y[n])}, ')
}
println('\n]')

// sampling frequency
println('// sampling frequency: ${(1/f)/samples}')