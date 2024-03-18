module i2c

// Constants for the SetI2COptions function.
// These values are combined with a bitwise OR operation. 
#define 	option_standard 	I2C_OPTION_STANDARD 
#define 	option_norestart	I2C_OPTION_NORESTART
#define 	option_fast     	I2C_OPTION_FAST  

// Constants for use with standard I2C devices. 
#define 	addr_default 		I2C_ADDR_DEFAULT 
#define 	reg_version  		I2C_REG_VERSION  
#define 	reg_vendor_id		I2C_REG_VENDOR_ID
#define 	reg_device_id		I2C_REG_DEVICE_ID
#define 	reg_cmd      		I2C_REG_CMD  

// Constants for LEGO I2C device addresses. 
#define 	lego_addr_us    	LEGO_ADDR_US    
#define 	lego_addr_temp  	LEGO_ADDR_TEMP  
#define 	lego_addr_emeter	LEGO_ADDR_EMETER

// Functions
#define		i2c__status(...) 			I2CStatus(__VA_ARGS__) 
#define		i2c__check_status(...) 		I2CCheckStatus(__VA_ARGS__) 
#define		i2c__bytes_ready(...) 		I2CBytesReady(__VA_ARGS__) 
#define		i2c__write(...) 			I2CWrite(__VA_ARGS__) 
#define		i2c__read(...) 				I2CRead(__VA_ARGS__) 
#define		i2c__bytes(...) 			I2CBytes(__VA_ARGS__) 
#define		i2c__read_register(...) 	ReadI2CRegister(__VA_ARGS__) 
#define		i2c__write_register(...) 	WriteI2CRegister(__VA_ARGS__) 
#define		i2c__device_info(...) 		I2CDeviceInfo(__VA_ARGS__) 
#define		i2c__version(...) 			I2CVersion(__VA_ARGS__) 
#define		i2c__vendor_id(...) 		I2CVendorId(__VA_ARGS__) 
#define		i2c__device_id(...) 		I2CDeviceId(__VA_ARGS__) 
#define		i2c__send_command(...)		I2CSendCommand(__VA_ARGS__)


fn init() {

}