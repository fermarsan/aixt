import motor_fn as motor
import sound
import time

sound.play_tone(5000, 30)
motor.write_sync(motor.ac, 50, 0)
time.sleep_ms(1000)
sound.play_tone(5000, 30)
motor.write_sync(motor.ac, 50, 20)
time.sleep_ms(1000)
sound.play_tone(5000, 30)
motor.write_sync(motor.ac, 50, -40)
time.sleep_ms(1000)
sound.play_tone(5000, 30)
motor.write_sync(motor.ac, -50, 90)
time.sleep_ms(1000)
motor.off(motor.ac)
