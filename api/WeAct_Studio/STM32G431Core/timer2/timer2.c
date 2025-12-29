#define TIMER2_SETOVERFLOW(VALUE, FORMAT) timer2->setOverflow(VALUE, FORMAT)
#define TIMER2_ATTACHINTERRUPT(HANDLER)  timer2->attachInterrupt(HANDLER)
#define TIMER2_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer2->attachInterrupt(CH, HANDLER)
#define TIMER2_RESUME() timer2->resume()
#define TIMER2_WRITE_PERCENT_CHANNEL(CH, VAL) timer2->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER2_WRITE_PERCENT(VALUE) timer2->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER2_SETMODE(channel, mode, pin) timer2->setMode(channel, mode, pin)
#define TIMER2__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER2_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM2;
HardwareTimer *timer2 = new HardwareTimer(inst);