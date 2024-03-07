
import sys
import motor

#define	t_fwd	1
#define	t_turn	500

for {
	motor.forward(ab, 50)
	sleep(t_fwd)
	motor.off(a)
	sleep_ms(t_turn)
}

