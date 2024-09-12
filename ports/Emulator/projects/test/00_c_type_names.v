__global (
	w_ = 5.0
)
const y_ = 5.0 

fn sum(a_ f64, b_ f64) f64 {
	c_ := a_ + b_
	return c_
}

x_ := 5.0

z_ := sum(x_, w_) + y_