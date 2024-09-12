__global (
	w_ = 5
)
const y_ = 5 

fn sum(a_ int, b_ int) int {
	c_ := a_ + b_
	return c_
}

x_ := 5

z_ := sum(x_, w_) + y_