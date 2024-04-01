#include <FreeRTOS.h>
#include <task.h>
#include <timers.h>

#include "bflb_platform.h"

void vAssertCalled(void)
{
    MSG("vAssertCalled\r\n");

    while (1)
        ;
}

void vApplicationTickHook(void)
{
    // MSG("vApplicationTickHook\r\n");
}

void vApplicationStackOverflowHook(void)
{
    MSG("vApplicationStackOverflowHook\r\n");

    while (1)
        ;
}

void vApplicationMallocFailedHook(void)
{
    MSG("vApplicationMallocFailedHook\r\n");

    while (1)
        ;
}
void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer,
                                   uint32_t *pulIdleTaskStackSize)
{
    /* If the buffers to be provided to the Idle task are declared inside this
    function then they must be declared static - otherwise they will be allocated
    on the stack and so not exists after this function exits. */
    static StaticTask_t xIdleTaskTCB;
    static StackType_t uxIdleTaskStack[configMINIMAL_STACK_SIZE];

    /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
    state will be stored. */
    *ppxIdleTaskTCBBuffer = &xIdleTaskTCB;

    /* Pass out the array that will be used as the Idle task's stack. */
    *ppxIdleTaskStackBuffer = uxIdleTaskStack;

    /* Pass out the size of the array pointed to by *ppxIdleTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configMINIMAL_STACK_SIZE is specified in words, not bytes. */
    *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
}

/* configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are both set to 1, so
the application must provide an implementation of
vApplicationGetTimerTaskMemory() to provide the memory that is used by the Timer
service task. */
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer,
                                    uint32_t *pulTimerTaskStackSize)
{
    /* If the buffers to be provided to the Timer task are declared inside this
    function then they must be declared static - otherwise they will be allocated
    on the stack and so not exists after this function exits. */
    static StaticTask_t xTimerTaskTCB;
    static StackType_t uxTimerTaskStack[configTIMER_TASK_STACK_DEPTH];

    /* Pass out a pointer to the StaticTask_t structure in which the Timer
    task's state will be stored. */
    *ppxTimerTaskTCBBuffer = &xTimerTaskTCB;

    /* Pass out the array that will be used as the Timer task's stack. */
    *ppxTimerTaskStackBuffer = uxTimerTaskStack;

    /* Pass out the size of the array pointed to by *ppxTimerTaskStackBuffer.
    Note that, as the array is necessarily of type StackType_t,
    configTIMER_TASK_STACK_DEPTH is specified in words, not bytes. */
    *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

extern uint64_t ullNextTime;
extern const size_t uxTimerIncrementsForOneTick;
void vApplicationSleep(uint32_t xExpectedIdleTime)
{
    uint64_t sleep_start_time = 0;
    uint64_t sleep_end_time = 0;
    uint64_t record_ullNextTime = 0;
    uint32_t actual_compensate_mstime = 0;
    static uint32_t actual_compensate_ustime = 0;
    if (eTaskConfirmSleepModeStatus() != eAbortSleep) {
        MSG("enter wfi,xExpectedIdleTime:%d\r\n", xExpectedIdleTime);
        if (xExpectedIdleTime > 60 * 1000) {
            xExpectedIdleTime = 60 * 1000;
        }

        cpu_global_irq_disable();

        /*prepare to enter wfi, record start time*/
        sleep_start_time = bflb_platform_get_time_us();
        /*minus one tick, bacause ullNextTime has increased one tick in last mtimer
         * interrupt */
        ullNextTime -= uxTimerIncrementsForOneTick;
        /*record current ullNextTime*/
        record_ullNextTime = ullNextTime;
        /*set mtimer cmp reg for xExpectedIdleTime ticks*/
        ullNextTime += uxTimerIncrementsForOneTick * (xExpectedIdleTime - 1);
        *(volatile uint64_t *)(0x02000000 + 0x4000) = ullNextTime;
        /* Prepare the time to use after the next tick interrupt. */
        ullNextTime += uxTimerIncrementsForOneTick;

        __WFI();

        /*exit wfi, record end time*/
        sleep_end_time = bflb_platform_get_time_us();

        /*mtimer interrupt cause*/
        if (xExpectedIdleTime == pdMS_TO_TICKS((sleep_end_time - sleep_start_time + 500) / 1000)) {
            /*compensate os tick*/
            vTaskStepTick(xExpectedIdleTime);
        } else { /*external interrupt cause*/
            ullNextTime = record_ullNextTime;
            /*caculate actual sleep time*/
            ullNextTime += (sleep_end_time - sleep_start_time);
            *(volatile uint64_t *)(0x02000000 + 0x4000) = ullNextTime;
            /* Prepare the time to use after the next tick interrupt. */
            ullNextTime += uxTimerIncrementsForOneTick;

            actual_compensate_ustime += (sleep_end_time - sleep_start_time);
            if (actual_compensate_ustime / 1000) {
                actual_compensate_mstime = actual_compensate_ustime / 1000;         /*How many ms to increase*/
                actual_compensate_ustime -= actual_compensate_ustime / 1000 * 1000; /*How many us to be remainded*/
            }
            MSG("ms:%d\r\n", actual_compensate_mstime);
            /*compensate os tick*/
            vTaskStepTick(pdMS_TO_TICKS(actual_compensate_mstime));
        }
        MSG("exit,sleep_time:%dus\r\n", (uint32_t)(sleep_end_time - sleep_start_time));
        cpu_global_irq_enable();
    }
}