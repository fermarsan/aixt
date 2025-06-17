#define TIMER1_SETOVERFLOW(VALUE, FORMAT) timer1->setOverflow(VALUE, FORMAT)
#define TIMER1_ATTACHINTERRUPT(HANDLER)  timer1->attachInterrupt(HANDLER)
#define TIMER1_RESUME() timer1->resume()

HardwareTimer *timer;
TIM_TypeDef *inst = TIM1;
timer1 = new HardwareTimer(inst);sa