import sound
import time { sleep_ms }

const vol = 3

sound.play_tone_ex(262, 400, vol, false)
sleep_ms(500)

sound.play_tone_ex(294, 400, vol, false)
sleep_ms(500)

sound.play_tone_ex(330, 400, vol, false)
sleep_ms(500)

sound.play_tone_ex(294, 400, vol, false)
sleep_ms(500)

sound.play_tone_ex(262, 1600, vol, false)
sleep_ms(2000)