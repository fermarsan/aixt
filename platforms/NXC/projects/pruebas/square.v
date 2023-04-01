#define	t_fwd	1000
#define	t_turn	500

for {
	on_fwd(OUT_AB)
	wait(t_fwd)
	off(OUT_A)
	wait(t_turn)
}

