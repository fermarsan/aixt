module i2c

// // Constants for the SetI2COptions function.
// // These values are combined with a bitwise OR operation. 
// #define 	option_standard 	I2C_OPTION_STANDARD 
// #define 	option_norestart	I2C_OPTION_NORESTART
// #define 	option_fast     	I2C_OPTION_FAST  

// // Constants for use with standard I2C devices. 
// #define 	addr_default 		I2C_ADDR_DEFAULT 
// #define 	reg_version  		I2C_REG_VERSION  
// #define 	reg_vendor_id		I2C_REG_VENDOR_ID
// #define 	reg_device_id		I2C_REG_DEVICE_ID
// #define 	reg_cmd      		I2C_REG_CMD  

// // Constants for LEGO I2C device addresses. 
// #define 	lego_addr_us    	LEGO_ADDR_US    
// #define 	lego_addr_temp  	LEGO_ADDR_TEMP  
// #define 	lego_addr_emeter	LEGO_ADDR_EMETER

// Functions
@[inline] status() { return C.I2CStatus() } 
@[inline] check_status() { return C.I2CCheckStatus() } 
@[inline] bytes_ready() { return C.I2CBytesReady() } 
@[inline] write() { return C.I2CWrite() } 
@[inline] read() { return C.I2CRead() } 
@[inline] bytes() { return C.I2CBytes() } 
@[inline] read_register() { return C.ReadI2CRegister() } 
@[inline] write_register() { return C.WriteI2CRegister() } 
@[inline] device_info() { return C.I2CDeviceInfo() } 
@[inline] version() { return C.I2CVersion() } 
@[inline] vendor_id() { return C.I2CVendorId() } 
@[inline] device_id() { return C.I2CDeviceId() } 
@[inline] send_command() { return C.I2CSendCommand() }
