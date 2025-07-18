#define TIMER8_SETOVERFLOW(VALUE, FORMAT) timer8->setOverflow(VALUE, FORMAT)
#define TIMER8_ATTACHINTERRUPT(HANDLER)  timer8->attachInterrupt(HANDLER)
#define TIMER8_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer8->attachInterrupt(CH, HANDLER)
#define TIMER8_RESUME() timer8->resume()
#define TIMER8_WRITE_PERCENT_CHANNEL(CH, VAL) timer8->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER8_WRITE_PERCENT(VALUE) timer8->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER8_SETMODE(channel, mode, pin) timer8->setMode(channel, mode, pin)
#define TIMER8__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER8_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM8;
HardwareTimer *timer8 = new HardwareTimer(inst);