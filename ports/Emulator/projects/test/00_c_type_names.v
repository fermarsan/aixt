__global (
	w_ = 5
)
const y_ = 5.0 

fn sum(a_ int, b_ int) int {
	c_ := a_ + b_
	return c_
}

mut x_ := 5
x_ = w_*2
z_ := sum(x_, w_) + int(y_)