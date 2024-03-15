import motor
import sound

sound.play_tone(5000, 30)
motor.forward_sync(, ac, 50, 0)
sleep_ms(1000)
sound.play_tone(5000, 30)
motor.forward_sync(, ac, 50, 20)
sleep_ms(1000)
sound.play_tone(5000, 30)
motor.forward_sync(, ac, 50, -40)
sleep_ms(1000)
sound.play_tone(5000, 30)
motor.reverse_sync(, ac, 50, 90)
sleep_ms(1000)
motor.off(, ac)