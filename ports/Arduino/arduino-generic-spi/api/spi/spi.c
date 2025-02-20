// Project Name: Aixt, https://github.com/fermarsan/aixt.git
// Author: Juan Pablo Bernal - Daniela Mendoza Deantonio - Fernando Martinez Santa 
// SPI


//FUNCIONES DESCRITAS PARA LA LIBRERIA DEL MODULO DE COMUNICACIÓN SPI
#define SPI_BEGIN()                             SPI.begin()
#define SPI_END()                               SPI.end()
#define SPI_BEGINTRANSACTION(settings)          SPI.beginTransaction(settings)
#define SPI_ENDTRANSACTION()                    SPI.endTransaction()
#define SPI_TRANSFER(data)                      SPI.transfer(data)
#define SPI_SETBITORDER(order)                  SPI.setBitOrder(order)
#define SPI_SETDATAMODE(mode)                   SPI.setDataMode(mode)
#define SPI_SETCLOCKDIVIDER(divider)            SPI.setClockDivider(divider)
#define SPI_USINGINTERRUPT(interrupt_num)       SPI.usingInterrupt(interrupt_num)
#define SPI_NOTUSINGINTERRUPT(interrupt_num)    SPI.notUsingInterrupt(interrupt_num)
#define SPI_ATTACHINTERRUPT(handler)            SPI.attachInterrupt(handler)