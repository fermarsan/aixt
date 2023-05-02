const (
	t_ON  = 1000
	t_OFF = 500
)

// const t_ON = 1000
// const t_OFF = 500
// const a = 34.67

on_fwd(out_ab,70)
wait(t_ON)

off(out_ab)
wait(t_OFF)

on_fwd(out_ab,70)
wait(t_ON)

off(out_ab)
