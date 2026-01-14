// "Draw" a rounded square with a differential
// platform (motors A and B)
import motor_fn as motor
import time


const t_on = 2000
const t_turn = 500

motor.write(motor.ab, 60) // move write
time.sleep_ms(t_on)
motor.off(motor.a) // off motor A to turn
time.sleep_ms(t_turn)

motor.write(motor.ab, 60)
time.sleep_ms(t_on)
motor.off(motor.a)
time.sleep_ms(t_turn)

motor.write(motor.ab, 60)
time.sleep_ms(t_on)
motor.off(motor.a)
time.sleep_ms(t_turn)

motor.write(motor.ab, 60)
time.sleep_ms(t_on)
motor.off(motor.a)
time.sleep_ms(t_turn)

motor.off(motor.ab) // stop
