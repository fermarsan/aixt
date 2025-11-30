#define TIMER4_SETOVERFLOW(VALUE, FORMAT) timer4->setOverflow(VALUE, FORMAT)
#define TIMER4_ATTACHINTERRUPT(HANDLER)  timer4->attachInterrupt(HANDLER)
#define TIMER4_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer4->attachInterrupt(CH, HANDLER)
#define TIMER4_RESUME() timer4->resume()
#define TIMER4_WRITE_PERCENT_CHANNEL(CH, VAL) timer4->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER4_WRITE_PERCENT(VALUE) timer4->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER4_SETMODE(channel, mode, pin) timer4->setMode(channel, mode, pin)
#define TIMER4__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER4_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM4;
HardwareTimer *timer4 = new HardwareTimer(inst);