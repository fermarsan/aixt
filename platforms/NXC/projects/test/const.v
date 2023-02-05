const (
	t_on  = 1000
	t_off = 500
)

// const t_on = 1000
// const t_off = 500
// const a = 34.67

on_fwd(out_ab)
wait(t_on)

off(out_ab)
wait(t_off)

on_fwd(out_ab)
wait(t_on)

off(out_ab)
