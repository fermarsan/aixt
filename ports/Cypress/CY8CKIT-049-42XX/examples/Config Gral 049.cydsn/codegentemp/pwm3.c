/*******************************************************************************
* File Name: pwm3.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the pwm3
*  component
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "pwm3.h"

uint8 pwm3_initVar = 0u;


/*******************************************************************************
* Function Name: pwm3_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default pwm3 configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (pwm3__QUAD == pwm3_CONFIG)
        pwm3_CONTROL_REG = pwm3_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        pwm3_TRIG_CONTROL1_REG  = pwm3_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        pwm3_SetInterruptMode(pwm3_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        pwm3_SetCounterMode(pwm3_COUNT_DOWN);
        pwm3_WritePeriod(pwm3_QUAD_PERIOD_INIT_VALUE);
        pwm3_WriteCounter(pwm3_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (pwm3__QUAD == pwm3_CONFIG) */

    #if (pwm3__TIMER == pwm3_CONFIG)
        pwm3_CONTROL_REG = pwm3_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        pwm3_TRIG_CONTROL1_REG  = pwm3_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        pwm3_SetInterruptMode(pwm3_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        pwm3_WritePeriod(pwm3_TC_PERIOD_VALUE );

        #if (pwm3__COMPARE == pwm3_TC_COMP_CAP_MODE)
            pwm3_WriteCompare(pwm3_TC_COMPARE_VALUE);

            #if (1u == pwm3_TC_COMPARE_SWAP)
                pwm3_SetCompareSwap(1u);
                pwm3_WriteCompareBuf(pwm3_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == pwm3_TC_COMPARE_SWAP) */
        #endif  /* (pwm3__COMPARE == pwm3_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (pwm3_CY_TCPWM_V2 && pwm3_TIMER_UPDOWN_CNT_USED && !pwm3_CY_TCPWM_4000)
            pwm3_WriteCounter(1u);
        #elif(pwm3__COUNT_DOWN == pwm3_TC_COUNTER_MODE)
            pwm3_WriteCounter(pwm3_TC_PERIOD_VALUE);
        #else
            pwm3_WriteCounter(0u);
        #endif /* (pwm3_CY_TCPWM_V2 && pwm3_TIMER_UPDOWN_CNT_USED && !pwm3_CY_TCPWM_4000) */
    #endif  /* (pwm3__TIMER == pwm3_CONFIG) */

    #if (pwm3__PWM_SEL == pwm3_CONFIG)
        pwm3_CONTROL_REG = pwm3_CTRL_PWM_BASE_CONFIG;

        #if (pwm3__PWM_PR == pwm3_PWM_MODE)
            pwm3_CONTROL_REG |= pwm3_CTRL_PWM_RUN_MODE;
            pwm3_WriteCounter(pwm3_PWM_PR_INIT_VALUE);
        #else
            pwm3_CONTROL_REG |= pwm3_CTRL_PWM_ALIGN | pwm3_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (pwm3_CY_TCPWM_V2 && pwm3_PWM_UPDOWN_CNT_USED && !pwm3_CY_TCPWM_4000)
                pwm3_WriteCounter(1u);
            #elif (pwm3__RIGHT == pwm3_PWM_ALIGN)
                pwm3_WriteCounter(pwm3_PWM_PERIOD_VALUE);
            #else 
                pwm3_WriteCounter(0u);
            #endif  /* (pwm3_CY_TCPWM_V2 && pwm3_PWM_UPDOWN_CNT_USED && !pwm3_CY_TCPWM_4000) */
        #endif  /* (pwm3__PWM_PR == pwm3_PWM_MODE) */

        #if (pwm3__PWM_DT == pwm3_PWM_MODE)
            pwm3_CONTROL_REG |= pwm3_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (pwm3__PWM_DT == pwm3_PWM_MODE) */

        #if (pwm3__PWM == pwm3_PWM_MODE)
            pwm3_CONTROL_REG |= pwm3_CTRL_PWM_PRESCALER;
        #endif  /* (pwm3__PWM == pwm3_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        pwm3_TRIG_CONTROL1_REG  = pwm3_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        pwm3_SetInterruptMode(pwm3_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (pwm3__PWM_PR == pwm3_PWM_MODE)
            pwm3_TRIG_CONTROL2_REG =
                    (pwm3_CC_MATCH_NO_CHANGE    |
                    pwm3_OVERLOW_NO_CHANGE      |
                    pwm3_UNDERFLOW_NO_CHANGE);
        #else
            #if (pwm3__LEFT == pwm3_PWM_ALIGN)
                pwm3_TRIG_CONTROL2_REG = pwm3_PWM_MODE_LEFT;
            #endif  /* ( pwm3_PWM_LEFT == pwm3_PWM_ALIGN) */

            #if (pwm3__RIGHT == pwm3_PWM_ALIGN)
                pwm3_TRIG_CONTROL2_REG = pwm3_PWM_MODE_RIGHT;
            #endif  /* ( pwm3_PWM_RIGHT == pwm3_PWM_ALIGN) */

            #if (pwm3__CENTER == pwm3_PWM_ALIGN)
                pwm3_TRIG_CONTROL2_REG = pwm3_PWM_MODE_CENTER;
            #endif  /* ( pwm3_PWM_CENTER == pwm3_PWM_ALIGN) */

            #if (pwm3__ASYMMETRIC == pwm3_PWM_ALIGN)
                pwm3_TRIG_CONTROL2_REG = pwm3_PWM_MODE_ASYM;
            #endif  /* (pwm3__ASYMMETRIC == pwm3_PWM_ALIGN) */
        #endif  /* (pwm3__PWM_PR == pwm3_PWM_MODE) */

        /* Set other values from customizer */
        pwm3_WritePeriod(pwm3_PWM_PERIOD_VALUE );
        pwm3_WriteCompare(pwm3_PWM_COMPARE_VALUE);

        #if (1u == pwm3_PWM_COMPARE_SWAP)
            pwm3_SetCompareSwap(1u);
            pwm3_WriteCompareBuf(pwm3_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == pwm3_PWM_COMPARE_SWAP) */

        #if (1u == pwm3_PWM_PERIOD_SWAP)
            pwm3_SetPeriodSwap(1u);
            pwm3_WritePeriodBuf(pwm3_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == pwm3_PWM_PERIOD_SWAP) */
    #endif  /* (pwm3__PWM_SEL == pwm3_CONFIG) */
    
}


/*******************************************************************************
* Function Name: pwm3_Enable
********************************************************************************
*
* Summary:
*  Enables the pwm3.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    pwm3_BLOCK_CONTROL_REG |= pwm3_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (pwm3__PWM_SEL == pwm3_CONFIG)
        #if (0u == pwm3_PWM_START_SIGNAL_PRESENT)
            pwm3_TriggerCommand(pwm3_MASK, pwm3_CMD_START);
        #endif /* (0u == pwm3_PWM_START_SIGNAL_PRESENT) */
    #endif /* (pwm3__PWM_SEL == pwm3_CONFIG) */

    #if (pwm3__TIMER == pwm3_CONFIG)
        #if (0u == pwm3_TC_START_SIGNAL_PRESENT)
            pwm3_TriggerCommand(pwm3_MASK, pwm3_CMD_START);
        #endif /* (0u == pwm3_TC_START_SIGNAL_PRESENT) */
    #endif /* (pwm3__TIMER == pwm3_CONFIG) */
    
    #if (pwm3__QUAD == pwm3_CONFIG)
        #if (0u != pwm3_QUAD_AUTO_START)
            pwm3_TriggerCommand(pwm3_MASK, pwm3_CMD_RELOAD);
        #endif /* (0u != pwm3_QUAD_AUTO_START) */
    #endif  /* (pwm3__QUAD == pwm3_CONFIG) */
}


/*******************************************************************************
* Function Name: pwm3_Start
********************************************************************************
*
* Summary:
*  Initializes the pwm3 with default customizer
*  values when called the first time and enables the pwm3.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  pwm3_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time pwm3_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the pwm3_Start() routine.
*
*******************************************************************************/
void pwm3_Start(void)
{
    if (0u == pwm3_initVar)
    {
        pwm3_Init();
        pwm3_initVar = 1u;
    }

    pwm3_Enable();
}


/*******************************************************************************
* Function Name: pwm3_Stop
********************************************************************************
*
* Summary:
*  Disables the pwm3.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_BLOCK_CONTROL_REG &= (uint32)~pwm3_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the pwm3. This function is used when
*  configured as a generic pwm3 and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the pwm3 to operate in
*   Values:
*   - pwm3_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - pwm3_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - pwm3_MODE_QUAD - Quadrature decoder
*         - pwm3_MODE_PWM - PWM
*         - pwm3_MODE_PWM_DT - PWM with dead time
*         - pwm3_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_MODE_MASK;
    pwm3_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - pwm3_MODE_X1 - Counts on phi 1 rising
*         - pwm3_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - pwm3_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_QUAD_MODE_MASK;
    pwm3_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - pwm3_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - pwm3_PRESCALE_DIVBY2    - Divide by 2
*         - pwm3_PRESCALE_DIVBY4    - Divide by 4
*         - pwm3_PRESCALE_DIVBY8    - Divide by 8
*         - pwm3_PRESCALE_DIVBY16   - Divide by 16
*         - pwm3_PRESCALE_DIVBY32   - Divide by 32
*         - pwm3_PRESCALE_DIVBY64   - Divide by 64
*         - pwm3_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_PRESCALER_MASK;
    pwm3_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the pwm3 runs
*  continuously or stops when terminal count is reached.  By default the
*  pwm3 operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_ONESHOT_MASK;
    pwm3_CONTROL_REG |= ((uint32)((oneShotEnable & pwm3_1BIT_MASK) <<
                                                               pwm3_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetPWMMode(uint32 modeMask)
{
    pwm3_TRIG_CONTROL2_REG = (modeMask & pwm3_6BIT_MASK);
}



/*******************************************************************************
* Function Name: pwm3_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_PWM_SYNC_KILL_MASK;
    pwm3_CONTROL_REG |= ((uint32)((syncKillEnable & pwm3_1BIT_MASK)  <<
                                               pwm3_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_PWM_STOP_KILL_MASK;
    pwm3_CONTROL_REG |= ((uint32)((stopOnKillEnable & pwm3_1BIT_MASK)  <<
                                                         pwm3_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_PRESCALER_MASK;
    pwm3_CONTROL_REG |= ((uint32)((deadTime & pwm3_8BIT_MASK) <<
                                                          pwm3_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - pwm3_INVERT_LINE   - Inverts the line output
*         - pwm3_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_INV_OUT_MASK;
    pwm3_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: pwm3_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_WriteCounter(uint32 count)
{
    pwm3_COUNTER_REG = (count & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 pwm3_ReadCounter(void)
{
    return (pwm3_COUNTER_REG & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - pwm3_COUNT_UP       - Counts up
*     - pwm3_COUNT_DOWN     - Counts down
*     - pwm3_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - pwm3_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_UPDOWN_MASK;
    pwm3_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_WritePeriod(uint32 period)
{
    pwm3_PERIOD_REG = (period & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 pwm3_ReadPeriod(void)
{
    return (pwm3_PERIOD_REG & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_RELOAD_CC_MASK;
    pwm3_CONTROL_REG |= (swapEnable & pwm3_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_WritePeriodBuf(uint32 periodBuf)
{
    pwm3_PERIOD_BUF_REG = (periodBuf & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 pwm3_ReadPeriodBuf(void)
{
    return (pwm3_PERIOD_BUF_REG & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_CONTROL_REG &= (uint32)~pwm3_RELOAD_PERIOD_MASK;
    pwm3_CONTROL_REG |= ((uint32)((swapEnable & pwm3_1BIT_MASK) <<
                                                            pwm3_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void pwm3_WriteCompare(uint32 compare)
{
    #if (pwm3_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (pwm3_CY_TCPWM_4000) */

    #if (pwm3_CY_TCPWM_4000)
        currentMode = ((pwm3_CONTROL_REG & pwm3_UPDOWN_MASK) >> pwm3_UPDOWN_SHIFT);

        if (((uint32)pwm3__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)pwm3__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (pwm3_CY_TCPWM_4000) */
    
    pwm3_COMP_CAP_REG = (compare & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 pwm3_ReadCompare(void)
{
    #if (pwm3_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (pwm3_CY_TCPWM_4000) */

    #if (pwm3_CY_TCPWM_4000)
        currentMode = ((pwm3_CONTROL_REG & pwm3_UPDOWN_MASK) >> pwm3_UPDOWN_SHIFT);
        
        regVal = pwm3_COMP_CAP_REG;
        
        if (((uint32)pwm3__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)pwm3__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & pwm3_16BIT_MASK);
    #else
        return (pwm3_COMP_CAP_REG & pwm3_16BIT_MASK);
    #endif /* (pwm3_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: pwm3_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void pwm3_WriteCompareBuf(uint32 compareBuf)
{
    #if (pwm3_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (pwm3_CY_TCPWM_4000) */

    #if (pwm3_CY_TCPWM_4000)
        currentMode = ((pwm3_CONTROL_REG & pwm3_UPDOWN_MASK) >> pwm3_UPDOWN_SHIFT);

        if (((uint32)pwm3__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)pwm3__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (pwm3_CY_TCPWM_4000) */
    
    pwm3_COMP_CAP_BUF_REG = (compareBuf & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 pwm3_ReadCompareBuf(void)
{
    #if (pwm3_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (pwm3_CY_TCPWM_4000) */

    #if (pwm3_CY_TCPWM_4000)
        currentMode = ((pwm3_CONTROL_REG & pwm3_UPDOWN_MASK) >> pwm3_UPDOWN_SHIFT);

        regVal = pwm3_COMP_CAP_BUF_REG;
        
        if (((uint32)pwm3__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)pwm3__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & pwm3_16BIT_MASK);
    #else
        return (pwm3_COMP_CAP_BUF_REG & pwm3_16BIT_MASK);
    #endif /* (pwm3_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: pwm3_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 pwm3_ReadCapture(void)
{
    return (pwm3_COMP_CAP_REG & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 pwm3_ReadCaptureBuf(void)
{
    return (pwm3_COMP_CAP_BUF_REG & pwm3_16BIT_MASK);
}


/*******************************************************************************
* Function Name: pwm3_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - pwm3_TRIG_LEVEL     - Level
*     - pwm3_TRIG_RISING    - Rising edge
*     - pwm3_TRIG_FALLING   - Falling edge
*     - pwm3_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_TRIG_CONTROL1_REG &= (uint32)~pwm3_CAPTURE_MASK;
    pwm3_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - pwm3_TRIG_LEVEL     - Level
*     - pwm3_TRIG_RISING    - Rising edge
*     - pwm3_TRIG_FALLING   - Falling edge
*     - pwm3_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_TRIG_CONTROL1_REG &= (uint32)~pwm3_RELOAD_MASK;
    pwm3_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << pwm3_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - pwm3_TRIG_LEVEL     - Level
*     - pwm3_TRIG_RISING    - Rising edge
*     - pwm3_TRIG_FALLING   - Falling edge
*     - pwm3_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_TRIG_CONTROL1_REG &= (uint32)~pwm3_START_MASK;
    pwm3_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << pwm3_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - pwm3_TRIG_LEVEL     - Level
*     - pwm3_TRIG_RISING    - Rising edge
*     - pwm3_TRIG_FALLING   - Falling edge
*     - pwm3_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_TRIG_CONTROL1_REG &= (uint32)~pwm3_STOP_MASK;
    pwm3_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << pwm3_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - pwm3_TRIG_LEVEL     - Level
*     - pwm3_TRIG_RISING    - Rising edge
*     - pwm3_TRIG_FALLING   - Falling edge
*     - pwm3_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_TRIG_CONTROL1_REG &= (uint32)~pwm3_COUNT_MASK;
    pwm3_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << pwm3_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - pwm3_CMD_CAPTURE    - Trigger Capture/Switch command
*     - pwm3_CMD_RELOAD     - Trigger Reload/Index command
*     - pwm3_CMD_STOP       - Trigger Stop/Kill command
*     - pwm3_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    pwm3_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: pwm3_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the pwm3.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - pwm3_STATUS_DOWN    - Set if counting down
*     - pwm3_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 pwm3_ReadStatus(void)
{
    return ((pwm3_STATUS_REG >> pwm3_RUNNING_STATUS_SHIFT) |
            (pwm3_STATUS_REG & pwm3_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: pwm3_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - pwm3_INTR_MASK_TC       - Terminal count mask
*     - pwm3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetInterruptMode(uint32 interruptMask)
{
    pwm3_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: pwm3_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - pwm3_INTR_MASK_TC       - Terminal count mask
*     - pwm3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 pwm3_GetInterruptSourceMasked(void)
{
    return (pwm3_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: pwm3_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - pwm3_INTR_MASK_TC       - Terminal count mask
*     - pwm3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 pwm3_GetInterruptSource(void)
{
    return (pwm3_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: pwm3_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - pwm3_INTR_MASK_TC       - Terminal count mask
*     - pwm3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_ClearInterrupt(uint32 interruptMask)
{
    pwm3_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: pwm3_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - pwm3_INTR_MASK_TC       - Terminal count mask
*     - pwm3_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void pwm3_SetInterrupt(uint32 interruptMask)
{
    pwm3_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
