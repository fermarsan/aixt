import motor_fn as motor
import sound
import time

motor.write_reg(motor.ac, 50, motor.regmode_idle)

time.sleep_ms(2000)

motor.off(motor.ac)
sound.play_tone(4000, 50)
time.sleep_ms(1000)
motor.reset_tacho_count(motor.ac)
motor.write_reg(motor.ac,  50,  motor.regmode_speed)
time.sleep_ms(2000)
motor.off(motor.ac)
sound.play_tone(4000, 50)
time.sleep_ms(1000)
motor.write_reg(motor.ac,  50,  motor.regmode_sync)
time.sleep_ms(2000)
motor.off(motor.ac)
