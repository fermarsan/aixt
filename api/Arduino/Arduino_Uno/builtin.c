
#ifdef SPI_IRQ_IN_USE    
void (*ptr_spi_isr)(void);      // Interrupt Service Routine pointer
   
ISR (SPI_STC_vect) {
    ptr_spi_isr();
//   Slavereceived = SPDR;         
//   received = true;                        
}
#endif  // SPI_IRQ_IN_USE 
