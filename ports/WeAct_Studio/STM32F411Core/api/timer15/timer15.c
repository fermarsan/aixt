#define TIMER15_SETOVERFLOW(VALUE, FORMAT) timer15->setOverflow(VALUE, FORMAT)
#define TIMER15_ATTACHINTERRUPT(HANDLER)  timer15->attachInterrupt(HANDLER)
#define TIMER15_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer15->attachInterrupt(CH, HANDLER)
#define TIMER15_RESUME() timer15->resume()
#define TIMER15_WRITE_PERCENT_CHANNEL(CH, VAL) timer15->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER15_WRITE_PERCENT(VALUE) timer15->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER15_SETMODE(channel, mode, pin) timer15->setMode(channel, mode, pin)
#define TIMER15__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER15_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM15;
HardwareTimer *timer15 = new HardwareTimer(inst);