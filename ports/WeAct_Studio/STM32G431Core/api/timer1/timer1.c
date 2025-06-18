#define TIMER1_SETOVERFLOW(VALUE, FORMAT) timer1->setOverflow(VALUE, FORMAT)
#define TIMER1_ATTACHINTERRUPT(HANDLER)  timer1->attachInterrupt(HANDLER)
#define TIMER1_RESUME() timer1->resume()

TIM_TypeDef *inst = TIM1;
HardwareTimer *timer1 = new HardwareTimer(inst);