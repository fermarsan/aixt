// Project Name:
// Author: 
// Date: 
// W801 fosc = 10Mhz

import time
import pin

pin__setup(led1, pin__output)

for {
	pin__high(led1)
	time__sleep_ms(500)
	pin__low(led1)
}
