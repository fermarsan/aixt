#define TIMER17_SETOVERFLOW(VALUE, FORMAT) timer17->setOverflow(VALUE, FORMAT)
#define TIMER17_ATTACHINTERRUPT(HANDLER)  timer17->attachInterrupt(HANDLER)
#define TIMER17_COMPARE_ATTACHINTERRUPT(CH, HANDLER)  timer17->attachInterrupt(CH, HANDLER)
#define TIMER17_RESUME() timer17->resume()
#define TIMER17_WRITE_PERCENT_CHANNEL(CH, VAL) timer17->setCaptureCompare(CH, VAL, PERCENT_COMPARE_FORMAT)
#define TIMER17_WRITE_PERCENT(VALUE) timer17->setCaptureCompare(1, VALUE, PERCENT_COMPARE_FORMAT)
#define TIMER17_SETMODE(channel, mode, pin) timer17->setMode(channel, mode, pin)
#define TIMER17__PWM1 TIMER_OUTPUT_COMPARE_PWM1

#define TIMER17_COMPARE_CHANNEL_ISR(CH, HANDLER) HANDLER ## _ ## CH


TIM_TypeDef *inst = TIM17;
HardwareTimer *timer17 = new HardwareTimer(inst);