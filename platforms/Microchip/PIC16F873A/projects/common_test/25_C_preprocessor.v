// Aixt supports any C preprocessor directive

#define	time	1500

import time { sleep }

a := 0

for {
	sleep(time)
	a++
}