#define TIMER1_SETOVERFLOW(VALUE, FORMAT) timer1->setOverflow(VALUE, FORMAT)
#define TIMER1_ATTACHINTERRUPT(HANDLER)  timer1->attachInterrupt(HANDLER)
#define TIMER1_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer1->attachInterrupt(CH, HANDLER)
#define TIMER1_RESUME() timer1->resume()
#define TIMER1_WRITE_PERCENT_CHANNEL(CH, VAL) timer1->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER1_WRITE_PERCENT(VALUE) timer1->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER1_SETMODE(channel, mode, pin) timer1->setMode(channel, mode, pin)
#define TIMER1__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER1_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM1;
HardwareTimer *timer1 = new HardwareTimer(inst);