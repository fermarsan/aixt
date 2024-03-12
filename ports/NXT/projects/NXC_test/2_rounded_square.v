// "Draw" a rounded square with a differential
// platform (motors A and B)
import motor

const t_on = 2000
const t_turn = 500

motor.forward(ab, 60) // move forward
sleep_ms(t_on)
motor.off(a) // off motor A to turn
sleep_ms(t_turn)

motor.forward(ab, 60)
sleep_ms(t_on)
motor.off(a)
sleep_ms(t_turn)

motor.forward(ab, 60)
sleep_ms(t_on)
motor.off(a)
sleep_ms(t_turn)

motor.forward(ab, 60)
sleep_ms(t_on)
motor.off(a)
sleep_ms(t_turn)

motor.off(ab) // stop
