import sound
import time

const vol = 3

sound.play_tone_ex(262, 400, vol, false)
time.sleep_ms(500)

sound.play_tone_ex(294, 400, vol, false)
time.sleep_ms(500)

sound.play_tone_ex(330, 400, vol, false)
time.sleep_ms(500)

sound.play_tone_ex(294, 400, vol, false)
time.sleep_ms(500)

sound.play_tone_ex(262, 1600, vol, false)
time.sleep_ms(2000)