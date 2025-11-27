// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Authors:
//        - Juan Pablo Bernal
//        - Daniela Mendoza Deantonio
//        - Fernando M. Santa
// Date: 2024

#define WIRE_BEGIN(...)                         Wire.begin(__VA_ARGS__)  
#define WIRE_END()                              Wire.end()
#define WIRE_REQUESTFROM(ADDRESS,QUANTITY)      Wire.requestFrom(ADDRESS,QUANTITY)
#define WIRE_BEGINTRANSMISSION(ADDRESS)         Wire.beginTransmission(ADDRESS)
#define WIRE_ENDTRANSMISSION()                  Wire.endTransmission()     
#define WIRE_WRITE(DATA)                        Wire.write(DATA)
#define WIRE_AVAILABLE()                        Wire.available()
#define WIRE_READ()                             Wire.read()
#define WIRE_SETCLOCK(CLOCK_SPEED)              Wire.setClock(CLOCK_SPEED)
#define WIRE_ONRECEIVE(FUNCTION_POINTER)        Wire.onReceive(FUNCTION_POINTER)    
#define WIRE_ONREQUEST(FUNCTION_POINTER)        Wire.onRequest(FUNCTION_POINTER)
#define WIRE_SETWIRETIMEOUT(TIME_OUT)           Wire.setWireTimeout(TIME_OUT)
#define WIRE_CLEARWIRETIMEOUTFLAG()             Wire.clearWireTimeoutFlag()
#define WIRE_GETWIRETIMEOUTFLAG()               Wire.getWireTimeoutFlag()