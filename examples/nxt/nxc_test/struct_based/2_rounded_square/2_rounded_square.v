// "Draw" a rounded square with a differential
// platform (motors A and B)
import motor
import time


const t_on = 2000
const t_turn = 500

motor_ab.write(60) // move write
time.sleep_ms(t_on)
motor_a.off() // off motor A to turn
time.sleep_ms(t_turn)

motor_ab.write(60)
time.sleep_ms(t_on)
motor_a.off()
time.sleep_ms(t_turn)

motor_ab.write(60)
time.sleep_ms(t_on)
motor_a.off()
time.sleep_ms(t_turn)

motor_ab.write(60)
time.sleep_ms(t_on)
motor_a.off()
time.sleep_ms(t_turn)

motor_ab.off() // stop