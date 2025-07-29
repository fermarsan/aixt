#define TIMER6_SETOVERFLOW(VALUE, FORMAT) timer6->setOverflow(VALUE, FORMAT)
#define TIMER6_ATTACHINTERRUPT(HANDLER)  timer6->attachInterrupt(HANDLER)
#define TIMER6_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer6->attachInterrupt(CH, HANDLER)
#define TIMER6_RESUME() timer6->resume()
#define TIMER6_WRITE_PERCENT_CHANNEL(CH, VAL) timer6->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER6_WRITE_PERCENT(VALUE) timer6->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER6_SETMODE(channel, mode, pin) timer6->setMode(channel, mode, pin)
#define TIMER6__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER6_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM6;
HardwareTimer *timer6 = new HardwareTimer(inst);