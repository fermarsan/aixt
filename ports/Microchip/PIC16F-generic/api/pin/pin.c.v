// Project Name: Aixt project, https://github.com/fermarsan/aixt.git
// Author: Fernando M. Santa
// Date: 2024
// License: MIT
//
// Description: Pin management functions (PIC16F8x port)
module pin

enum Pin_names as u8 {
	pin__a0 = 0
	pin__a1
	pin__a2
	pin__a3
	pin__a4
	pin__a5
	pin__a6
	pin__a7
	pin__b0
	pin__b1
	pin__b2
	pin__b3
	pin__b4
	pin__b5
	pin__b6
	pin__b7
	pin__c0
	pin__c1
	pin__c2
	pin__c3
	pin__c4
	pin__c5
	pin__c6
	pin__c7
	pin__d0
	pin__d1
	pin__d2
	pin__d3
	pin__d4
	pin__d5
	pin__d6
	pin__d7
	pin__e0
	pin__e1
	pin__e2
	pin__e3
	pin__e4
	pin__e5
	pin__e6
	pin__e7
}

enum Pin_modes as u8 {
	pin__output = 0
	pin__input
}