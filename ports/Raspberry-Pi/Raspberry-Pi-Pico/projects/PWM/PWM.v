import time {sleep_ms}
import pin

BRILLO := 0

pin_setup(gp10, output)

for {

BRILLO = adc_read(gp28)/4
pwm_write(gp10, BRILLO)

}