// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: 
// Date: 
// License: MIT
//
// Description: Pin management functions (Explorer16-PIC24 port)
module pin

#include <pxxx.h>	// device header file

// out macro defines the pin output mode
#define output		0

// in macro defines the pin input mode
#define input		1

#define a0      A, 0      // pin names
#define a1      A, 1 
...

#define b0      B, 0 
#define b1      B, 1 
...

#define c0      C, 0 
#define c1      C, 1 
...

...