const forward = true

if forward {
	on_fwd(out_ab, 60)
	wait(1000)
} else if ! forward {
	on_rev(out_ab, 60)
	wait(1000)
}
