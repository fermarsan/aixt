// Project Name:
// Author: 
// Date: 
// Explorer16-PIC24FJ128GA010 fosc = 32Mhz (8Mhz + PLL)

import time
import uart2

uart2.setup(115200)


for {
	uart2.write( u8(uart2.read()) + 1 )
	time.sleep_ms(200)
}
