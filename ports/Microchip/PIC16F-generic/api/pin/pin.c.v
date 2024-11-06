// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions for 16F family
module pin

enum Pin_names as u8 {
	a0 = 0
	a1
	a2
	a3
	a4
	a5
	a6
	a7
	b0
	b1
	b2
	b3
	b4
	b5
	b6
	b7
	c0
	c1
	c2
	c3
	c4
	c5
	c6
	c7
	d0
	d1
	d2
	d3
	d4
	d5
	d6
	d7
	e0
	e1
	e2
	e3
	e4
	e5
	e6
	e7
}

enum Pin_modes as u8 {
	output = 0
	input
}