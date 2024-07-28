module math

// Miscellaneous NBC/NXC constants
#define 	pi					  PI
#define 	rad_to_deg			  RADIANS_PER_DEGREE
#define 	deg_to_rad			  DEGREES_PER_RADIAN

// cmath.h
@[inline] sqrt() { return C.sqrt() }
@[inline] cos() { return C.cos() }
@[inline] sin() { return C.sin() }
@[inline] tan() { return C.tan() }
@[inline] acos() { return C.acos() }
@[inline] asin() { return C.asin() }
@[inline] atan() { return C.atan() }
@[inline] atan2() { return C.atan2() }
@[inline] cosh() { return C.cosh() }
@[inline] sinh() { return C.sinh() }
@[inline] tanh() { return C.tanh() }
@[inline] exp() { return C.exp() }
@[inline] log() { return C.log() }
@[inline] log10() { return C.log10() }
@[inline] trunc() { return C.trunc() }
@[inline] frac() { return C.frac() }
@[inline] pow() { return C.pow() }
@[inline] ceil() { return C.ceil() }
@[inline] floor() { return C.floor() }
@[inline] muldiv32() { return C.muldiv32() }
@[inline] cosd() { return C.cosd() }
@[inline] sind() { return C.sind() }
@[inline] tand() { return C.tand() }
@[inline] acosd() { return C.acosd() }
@[inline] asind() { return C.asind() }
@[inline] atand() { return C.atand() }
@[inline] atan2d() { return C.atan2d() }
@[inline] coshd() { return C.coshd() }
@[inline] sinhd() { return C.sinhd() }
@[inline] tanhd() { return C.tanhd() }
@[inline] bcd2dec() { return C.bcd2dec() }
@[inline] is_nan() { return C.isNAN() }
@[inline] sign() { return C.sign() }
@[inline] vector_cross() { return C.VectorCross() }
@[inline] vector_dot() { return C.VectorDot() }
@[inline] vector_normalize() { return C.VectorNormalize() }

// cstdlib.c
@[inline] abs() { return C.abs() }
@[inline] labs() { return C.labs() }
@[inline] div() { return C.div() }
@[inline] ldiv() { return C.ldiv() }
