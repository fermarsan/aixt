import pwm
import pin
import adc

__global (
  val = 0
)

pin.setup(gp10, pin.output)

for {

val = adc.read(gp28)
pwm.write(gp10, val)

}