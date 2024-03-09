omport motor

const t_on = 1000
const t_off = 500

// const t_on = 1000
// const t_off = 500
// const a = 34.67

motor.forward(ab, 70)
sleep_ms(t_on)

motor.off(ab)
sleep_ms(t_off)

motor.forward(ab, 70)
sleep_ms(t_on)

motor.off(ab)
