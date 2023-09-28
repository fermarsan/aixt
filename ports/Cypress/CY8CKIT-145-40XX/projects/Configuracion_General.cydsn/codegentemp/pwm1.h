/*******************************************************************************
* File Name: pwm1.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the pwm1
*  component.
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

#if !defined(CY_TCPWM_pwm1_H)
#define CY_TCPWM_pwm1_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} pwm1_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  pwm1_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define pwm1_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define pwm1_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define pwm1_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define pwm1_QUAD_ENCODING_MODES            (0lu)
#define pwm1_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define pwm1_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define pwm1_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define pwm1_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define pwm1_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define pwm1_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define pwm1_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define pwm1_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define pwm1_TC_RUN_MODE                    (0lu)
#define pwm1_TC_COUNTER_MODE                (0lu)
#define pwm1_TC_COMP_CAP_MODE               (2lu)
#define pwm1_TC_PRESCALER                   (0lu)

/* Signal modes */
#define pwm1_TC_RELOAD_SIGNAL_MODE          (0lu)
#define pwm1_TC_COUNT_SIGNAL_MODE           (3lu)
#define pwm1_TC_START_SIGNAL_MODE           (0lu)
#define pwm1_TC_STOP_SIGNAL_MODE            (0lu)
#define pwm1_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm1_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define pwm1_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define pwm1_TC_START_SIGNAL_PRESENT        (0lu)
#define pwm1_TC_STOP_SIGNAL_PRESENT         (0lu)
#define pwm1_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm1_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define pwm1_PWM_KILL_EVENT                 (0lu)
#define pwm1_PWM_STOP_EVENT                 (0lu)
#define pwm1_PWM_MODE                       (4lu)
#define pwm1_PWM_OUT_N_INVERT               (0lu)
#define pwm1_PWM_OUT_INVERT                 (0lu)
#define pwm1_PWM_ALIGN                      (0lu)
#define pwm1_PWM_RUN_MODE                   (0lu)
#define pwm1_PWM_DEAD_TIME_CYCLE            (0lu)
#define pwm1_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define pwm1_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define pwm1_PWM_COUNT_SIGNAL_MODE          (3lu)
#define pwm1_PWM_START_SIGNAL_MODE          (0lu)
#define pwm1_PWM_STOP_SIGNAL_MODE           (0lu)
#define pwm1_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm1_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define pwm1_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define pwm1_PWM_START_SIGNAL_PRESENT       (0lu)
#define pwm1_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define pwm1_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm1_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define pwm1_TC_PERIOD_VALUE                (65535lu)
#define pwm1_TC_COMPARE_VALUE               (65535lu)
#define pwm1_TC_COMPARE_BUF_VALUE           (65535lu)
#define pwm1_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define pwm1_PWM_PERIOD_VALUE               (65535lu)
#define pwm1_PWM_PERIOD_BUF_VALUE           (65535lu)
#define pwm1_PWM_PERIOD_SWAP                (0lu)
#define pwm1_PWM_COMPARE_VALUE              (32767lu)
#define pwm1_PWM_COMPARE_BUF_VALUE          (65535lu)
#define pwm1_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define pwm1__LEFT 0
#define pwm1__RIGHT 1
#define pwm1__CENTER 2
#define pwm1__ASYMMETRIC 3

#define pwm1__X1 0
#define pwm1__X2 1
#define pwm1__X4 2

#define pwm1__PWM 4
#define pwm1__PWM_DT 5
#define pwm1__PWM_PR 6

#define pwm1__INVERSE 1
#define pwm1__DIRECT 0

#define pwm1__CAPTURE 2
#define pwm1__COMPARE 0

#define pwm1__TRIG_LEVEL 3
#define pwm1__TRIG_RISING 0
#define pwm1__TRIG_FALLING 1
#define pwm1__TRIG_BOTH 2

#define pwm1__INTR_MASK_TC 1
#define pwm1__INTR_MASK_CC_MATCH 2
#define pwm1__INTR_MASK_NONE 0
#define pwm1__INTR_MASK_TC_CC 3

#define pwm1__UNCONFIG 8
#define pwm1__TIMER 1
#define pwm1__QUAD 3
#define pwm1__PWM_SEL 7

#define pwm1__COUNT_UP 0
#define pwm1__COUNT_DOWN 1
#define pwm1__COUNT_UPDOWN0 2
#define pwm1__COUNT_UPDOWN1 3


/* Prescaler */
#define pwm1_PRESCALE_DIVBY1                ((uint32)(0u << pwm1_PRESCALER_SHIFT))
#define pwm1_PRESCALE_DIVBY2                ((uint32)(1u << pwm1_PRESCALER_SHIFT))
#define pwm1_PRESCALE_DIVBY4                ((uint32)(2u << pwm1_PRESCALER_SHIFT))
#define pwm1_PRESCALE_DIVBY8                ((uint32)(3u << pwm1_PRESCALER_SHIFT))
#define pwm1_PRESCALE_DIVBY16               ((uint32)(4u << pwm1_PRESCALER_SHIFT))
#define pwm1_PRESCALE_DIVBY32               ((uint32)(5u << pwm1_PRESCALER_SHIFT))
#define pwm1_PRESCALE_DIVBY64               ((uint32)(6u << pwm1_PRESCALER_SHIFT))
#define pwm1_PRESCALE_DIVBY128              ((uint32)(7u << pwm1_PRESCALER_SHIFT))

/* TCPWM set modes */
#define pwm1_MODE_TIMER_COMPARE             ((uint32)(pwm1__COMPARE         <<  \
                                                                  pwm1_MODE_SHIFT))
#define pwm1_MODE_TIMER_CAPTURE             ((uint32)(pwm1__CAPTURE         <<  \
                                                                  pwm1_MODE_SHIFT))
#define pwm1_MODE_QUAD                      ((uint32)(pwm1__QUAD            <<  \
                                                                  pwm1_MODE_SHIFT))
#define pwm1_MODE_PWM                       ((uint32)(pwm1__PWM             <<  \
                                                                  pwm1_MODE_SHIFT))
#define pwm1_MODE_PWM_DT                    ((uint32)(pwm1__PWM_DT          <<  \
                                                                  pwm1_MODE_SHIFT))
#define pwm1_MODE_PWM_PR                    ((uint32)(pwm1__PWM_PR          <<  \
                                                                  pwm1_MODE_SHIFT))

/* Quad Modes */
#define pwm1_MODE_X1                        ((uint32)(pwm1__X1              <<  \
                                                                  pwm1_QUAD_MODE_SHIFT))
#define pwm1_MODE_X2                        ((uint32)(pwm1__X2              <<  \
                                                                  pwm1_QUAD_MODE_SHIFT))
#define pwm1_MODE_X4                        ((uint32)(pwm1__X4              <<  \
                                                                  pwm1_QUAD_MODE_SHIFT))

/* Counter modes */
#define pwm1_COUNT_UP                       ((uint32)(pwm1__COUNT_UP        <<  \
                                                                  pwm1_UPDOWN_SHIFT))
#define pwm1_COUNT_DOWN                     ((uint32)(pwm1__COUNT_DOWN      <<  \
                                                                  pwm1_UPDOWN_SHIFT))
#define pwm1_COUNT_UPDOWN0                  ((uint32)(pwm1__COUNT_UPDOWN0   <<  \
                                                                  pwm1_UPDOWN_SHIFT))
#define pwm1_COUNT_UPDOWN1                  ((uint32)(pwm1__COUNT_UPDOWN1   <<  \
                                                                  pwm1_UPDOWN_SHIFT))

/* PWM output invert */
#define pwm1_INVERT_LINE                    ((uint32)(pwm1__INVERSE         <<  \
                                                                  pwm1_INV_OUT_SHIFT))
#define pwm1_INVERT_LINE_N                  ((uint32)(pwm1__INVERSE         <<  \
                                                                  pwm1_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define pwm1_TRIG_RISING                    ((uint32)pwm1__TRIG_RISING)
#define pwm1_TRIG_FALLING                   ((uint32)pwm1__TRIG_FALLING)
#define pwm1_TRIG_BOTH                      ((uint32)pwm1__TRIG_BOTH)
#define pwm1_TRIG_LEVEL                     ((uint32)pwm1__TRIG_LEVEL)

/* Interrupt mask */
#define pwm1_INTR_MASK_TC                   ((uint32)pwm1__INTR_MASK_TC)
#define pwm1_INTR_MASK_CC_MATCH             ((uint32)pwm1__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define pwm1_CC_MATCH_SET                   (0x00u)
#define pwm1_CC_MATCH_CLEAR                 (0x01u)
#define pwm1_CC_MATCH_INVERT                (0x02u)
#define pwm1_CC_MATCH_NO_CHANGE             (0x03u)
#define pwm1_OVERLOW_SET                    (0x00u)
#define pwm1_OVERLOW_CLEAR                  (0x04u)
#define pwm1_OVERLOW_INVERT                 (0x08u)
#define pwm1_OVERLOW_NO_CHANGE              (0x0Cu)
#define pwm1_UNDERFLOW_SET                  (0x00u)
#define pwm1_UNDERFLOW_CLEAR                (0x10u)
#define pwm1_UNDERFLOW_INVERT               (0x20u)
#define pwm1_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define pwm1_PWM_MODE_LEFT                  (pwm1_CC_MATCH_CLEAR        |   \
                                                         pwm1_OVERLOW_SET           |   \
                                                         pwm1_UNDERFLOW_NO_CHANGE)
#define pwm1_PWM_MODE_RIGHT                 (pwm1_CC_MATCH_SET          |   \
                                                         pwm1_OVERLOW_NO_CHANGE     |   \
                                                         pwm1_UNDERFLOW_CLEAR)
#define pwm1_PWM_MODE_ASYM                  (pwm1_CC_MATCH_INVERT       |   \
                                                         pwm1_OVERLOW_SET           |   \
                                                         pwm1_UNDERFLOW_CLEAR)

#if (pwm1_CY_TCPWM_V2)
    #if(pwm1_CY_TCPWM_4000)
        #define pwm1_PWM_MODE_CENTER                (pwm1_CC_MATCH_INVERT       |   \
                                                                 pwm1_OVERLOW_NO_CHANGE     |   \
                                                                 pwm1_UNDERFLOW_CLEAR)
    #else
        #define pwm1_PWM_MODE_CENTER                (pwm1_CC_MATCH_INVERT       |   \
                                                                 pwm1_OVERLOW_SET           |   \
                                                                 pwm1_UNDERFLOW_CLEAR)
    #endif /* (pwm1_CY_TCPWM_4000) */
#else
    #define pwm1_PWM_MODE_CENTER                (pwm1_CC_MATCH_INVERT       |   \
                                                             pwm1_OVERLOW_NO_CHANGE     |   \
                                                             pwm1_UNDERFLOW_CLEAR)
#endif /* (pwm1_CY_TCPWM_NEW) */

/* Command operations without condition */
#define pwm1_CMD_CAPTURE                    (0u)
#define pwm1_CMD_RELOAD                     (8u)
#define pwm1_CMD_STOP                       (16u)
#define pwm1_CMD_START                      (24u)

/* Status */
#define pwm1_STATUS_DOWN                    (1u)
#define pwm1_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   pwm1_Init(void);
void   pwm1_Enable(void);
void   pwm1_Start(void);
void   pwm1_Stop(void);

void   pwm1_SetMode(uint32 mode);
void   pwm1_SetCounterMode(uint32 counterMode);
void   pwm1_SetPWMMode(uint32 modeMask);
void   pwm1_SetQDMode(uint32 qdMode);

void   pwm1_SetPrescaler(uint32 prescaler);
void   pwm1_TriggerCommand(uint32 mask, uint32 command);
void   pwm1_SetOneShot(uint32 oneShotEnable);
uint32 pwm1_ReadStatus(void);

void   pwm1_SetPWMSyncKill(uint32 syncKillEnable);
void   pwm1_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   pwm1_SetPWMDeadTime(uint32 deadTime);
void   pwm1_SetPWMInvert(uint32 mask);

void   pwm1_SetInterruptMode(uint32 interruptMask);
uint32 pwm1_GetInterruptSourceMasked(void);
uint32 pwm1_GetInterruptSource(void);
void   pwm1_ClearInterrupt(uint32 interruptMask);
void   pwm1_SetInterrupt(uint32 interruptMask);

void   pwm1_WriteCounter(uint32 count);
uint32 pwm1_ReadCounter(void);

uint32 pwm1_ReadCapture(void);
uint32 pwm1_ReadCaptureBuf(void);

void   pwm1_WritePeriod(uint32 period);
uint32 pwm1_ReadPeriod(void);
void   pwm1_WritePeriodBuf(uint32 periodBuf);
uint32 pwm1_ReadPeriodBuf(void);

void   pwm1_WriteCompare(uint32 compare);
uint32 pwm1_ReadCompare(void);
void   pwm1_WriteCompareBuf(uint32 compareBuf);
uint32 pwm1_ReadCompareBuf(void);

void   pwm1_SetPeriodSwap(uint32 swapEnable);
void   pwm1_SetCompareSwap(uint32 swapEnable);

void   pwm1_SetCaptureMode(uint32 triggerMode);
void   pwm1_SetReloadMode(uint32 triggerMode);
void   pwm1_SetStartMode(uint32 triggerMode);
void   pwm1_SetStopMode(uint32 triggerMode);
void   pwm1_SetCountMode(uint32 triggerMode);

void   pwm1_SaveConfig(void);
void   pwm1_RestoreConfig(void);
void   pwm1_Sleep(void);
void   pwm1_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define pwm1_BLOCK_CONTROL_REG              (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm1_BLOCK_CONTROL_PTR              ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm1_COMMAND_REG                    (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm1_COMMAND_PTR                    ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm1_INTRRUPT_CAUSE_REG             (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm1_INTRRUPT_CAUSE_PTR             ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm1_CONTROL_REG                    (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__CTRL )
#define pwm1_CONTROL_PTR                    ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__CTRL )
#define pwm1_STATUS_REG                     (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__STATUS )
#define pwm1_STATUS_PTR                     ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__STATUS )
#define pwm1_COUNTER_REG                    (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__COUNTER )
#define pwm1_COUNTER_PTR                    ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__COUNTER )
#define pwm1_COMP_CAP_REG                   (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__CC )
#define pwm1_COMP_CAP_PTR                   ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__CC )
#define pwm1_COMP_CAP_BUF_REG               (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm1_COMP_CAP_BUF_PTR               ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm1_PERIOD_REG                     (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__PERIOD )
#define pwm1_PERIOD_PTR                     ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__PERIOD )
#define pwm1_PERIOD_BUF_REG                 (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm1_PERIOD_BUF_PTR                 ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm1_TRIG_CONTROL0_REG              (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm1_TRIG_CONTROL0_PTR              ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm1_TRIG_CONTROL1_REG              (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm1_TRIG_CONTROL1_PTR              ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm1_TRIG_CONTROL2_REG              (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm1_TRIG_CONTROL2_PTR              ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm1_INTERRUPT_REQ_REG              (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__INTR )
#define pwm1_INTERRUPT_REQ_PTR              ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__INTR )
#define pwm1_INTERRUPT_SET_REG              (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm1_INTERRUPT_SET_PTR              ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm1_INTERRUPT_MASK_REG             (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm1_INTERRUPT_MASK_PTR             ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm1_INTERRUPT_MASKED_REG           (*(reg32 *) pwm1_cy_m0s8_tcpwm_1__INTR_MASKED )
#define pwm1_INTERRUPT_MASKED_PTR           ( (reg32 *) pwm1_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define pwm1_MASK                           ((uint32)pwm1_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define pwm1_RELOAD_CC_SHIFT                (0u)
#define pwm1_RELOAD_PERIOD_SHIFT            (1u)
#define pwm1_PWM_SYNC_KILL_SHIFT            (2u)
#define pwm1_PWM_STOP_KILL_SHIFT            (3u)
#define pwm1_PRESCALER_SHIFT                (8u)
#define pwm1_UPDOWN_SHIFT                   (16u)
#define pwm1_ONESHOT_SHIFT                  (18u)
#define pwm1_QUAD_MODE_SHIFT                (20u)
#define pwm1_INV_OUT_SHIFT                  (20u)
#define pwm1_INV_COMPL_OUT_SHIFT            (21u)
#define pwm1_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define pwm1_RELOAD_CC_MASK                 ((uint32)(pwm1_1BIT_MASK        <<  \
                                                                            pwm1_RELOAD_CC_SHIFT))
#define pwm1_RELOAD_PERIOD_MASK             ((uint32)(pwm1_1BIT_MASK        <<  \
                                                                            pwm1_RELOAD_PERIOD_SHIFT))
#define pwm1_PWM_SYNC_KILL_MASK             ((uint32)(pwm1_1BIT_MASK        <<  \
                                                                            pwm1_PWM_SYNC_KILL_SHIFT))
#define pwm1_PWM_STOP_KILL_MASK             ((uint32)(pwm1_1BIT_MASK        <<  \
                                                                            pwm1_PWM_STOP_KILL_SHIFT))
#define pwm1_PRESCALER_MASK                 ((uint32)(pwm1_8BIT_MASK        <<  \
                                                                            pwm1_PRESCALER_SHIFT))
#define pwm1_UPDOWN_MASK                    ((uint32)(pwm1_2BIT_MASK        <<  \
                                                                            pwm1_UPDOWN_SHIFT))
#define pwm1_ONESHOT_MASK                   ((uint32)(pwm1_1BIT_MASK        <<  \
                                                                            pwm1_ONESHOT_SHIFT))
#define pwm1_QUAD_MODE_MASK                 ((uint32)(pwm1_3BIT_MASK        <<  \
                                                                            pwm1_QUAD_MODE_SHIFT))
#define pwm1_INV_OUT_MASK                   ((uint32)(pwm1_2BIT_MASK        <<  \
                                                                            pwm1_INV_OUT_SHIFT))
#define pwm1_MODE_MASK                      ((uint32)(pwm1_3BIT_MASK        <<  \
                                                                            pwm1_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define pwm1_CAPTURE_SHIFT                  (0u)
#define pwm1_COUNT_SHIFT                    (2u)
#define pwm1_RELOAD_SHIFT                   (4u)
#define pwm1_STOP_SHIFT                     (6u)
#define pwm1_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define pwm1_CAPTURE_MASK                   ((uint32)(pwm1_2BIT_MASK        <<  \
                                                                  pwm1_CAPTURE_SHIFT))
#define pwm1_COUNT_MASK                     ((uint32)(pwm1_2BIT_MASK        <<  \
                                                                  pwm1_COUNT_SHIFT))
#define pwm1_RELOAD_MASK                    ((uint32)(pwm1_2BIT_MASK        <<  \
                                                                  pwm1_RELOAD_SHIFT))
#define pwm1_STOP_MASK                      ((uint32)(pwm1_2BIT_MASK        <<  \
                                                                  pwm1_STOP_SHIFT))
#define pwm1_START_MASK                     ((uint32)(pwm1_2BIT_MASK        <<  \
                                                                  pwm1_START_SHIFT))

/* MASK */
#define pwm1_1BIT_MASK                      ((uint32)0x01u)
#define pwm1_2BIT_MASK                      ((uint32)0x03u)
#define pwm1_3BIT_MASK                      ((uint32)0x07u)
#define pwm1_6BIT_MASK                      ((uint32)0x3Fu)
#define pwm1_8BIT_MASK                      ((uint32)0xFFu)
#define pwm1_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define pwm1_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define pwm1_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(pwm1_QUAD_ENCODING_MODES     << pwm1_QUAD_MODE_SHIFT))       |\
         ((uint32)(pwm1_CONFIG                  << pwm1_MODE_SHIFT)))

#define pwm1_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(pwm1_PWM_STOP_EVENT          << pwm1_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(pwm1_PWM_OUT_INVERT          << pwm1_INV_OUT_SHIFT))         |\
         ((uint32)(pwm1_PWM_OUT_N_INVERT        << pwm1_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(pwm1_PWM_MODE                << pwm1_MODE_SHIFT)))

#define pwm1_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(pwm1_PWM_RUN_MODE         << pwm1_ONESHOT_SHIFT))
            
#define pwm1_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(pwm1_PWM_ALIGN            << pwm1_UPDOWN_SHIFT))

#define pwm1_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(pwm1_PWM_KILL_EVENT      << pwm1_PWM_SYNC_KILL_SHIFT))

#define pwm1_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(pwm1_PWM_DEAD_TIME_CYCLE  << pwm1_PRESCALER_SHIFT))

#define pwm1_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(pwm1_PWM_PRESCALER        << pwm1_PRESCALER_SHIFT))

#define pwm1_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(pwm1_TC_PRESCALER            << pwm1_PRESCALER_SHIFT))       |\
         ((uint32)(pwm1_TC_COUNTER_MODE         << pwm1_UPDOWN_SHIFT))          |\
         ((uint32)(pwm1_TC_RUN_MODE             << pwm1_ONESHOT_SHIFT))         |\
         ((uint32)(pwm1_TC_COMP_CAP_MODE        << pwm1_MODE_SHIFT)))
        
#define pwm1_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(pwm1_QUAD_PHIA_SIGNAL_MODE   << pwm1_COUNT_SHIFT))           |\
         ((uint32)(pwm1_QUAD_INDEX_SIGNAL_MODE  << pwm1_RELOAD_SHIFT))          |\
         ((uint32)(pwm1_QUAD_STOP_SIGNAL_MODE   << pwm1_STOP_SHIFT))            |\
         ((uint32)(pwm1_QUAD_PHIB_SIGNAL_MODE   << pwm1_START_SHIFT)))

#define pwm1_PWM_SIGNALS_MODES                                                              \
        (((uint32)(pwm1_PWM_SWITCH_SIGNAL_MODE  << pwm1_CAPTURE_SHIFT))         |\
         ((uint32)(pwm1_PWM_COUNT_SIGNAL_MODE   << pwm1_COUNT_SHIFT))           |\
         ((uint32)(pwm1_PWM_RELOAD_SIGNAL_MODE  << pwm1_RELOAD_SHIFT))          |\
         ((uint32)(pwm1_PWM_STOP_SIGNAL_MODE    << pwm1_STOP_SHIFT))            |\
         ((uint32)(pwm1_PWM_START_SIGNAL_MODE   << pwm1_START_SHIFT)))

#define pwm1_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(pwm1_TC_CAPTURE_SIGNAL_MODE  << pwm1_CAPTURE_SHIFT))         |\
         ((uint32)(pwm1_TC_COUNT_SIGNAL_MODE    << pwm1_COUNT_SHIFT))           |\
         ((uint32)(pwm1_TC_RELOAD_SIGNAL_MODE   << pwm1_RELOAD_SHIFT))          |\
         ((uint32)(pwm1_TC_STOP_SIGNAL_MODE     << pwm1_STOP_SHIFT))            |\
         ((uint32)(pwm1_TC_START_SIGNAL_MODE    << pwm1_START_SHIFT)))
        
#define pwm1_TIMER_UPDOWN_CNT_USED                                                          \
                ((pwm1__COUNT_UPDOWN0 == pwm1_TC_COUNTER_MODE)                  ||\
                 (pwm1__COUNT_UPDOWN1 == pwm1_TC_COUNTER_MODE))

#define pwm1_PWM_UPDOWN_CNT_USED                                                            \
                ((pwm1__CENTER == pwm1_PWM_ALIGN)                               ||\
                 (pwm1__ASYMMETRIC == pwm1_PWM_ALIGN))               
        
#define pwm1_PWM_PR_INIT_VALUE              (1u)
#define pwm1_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_pwm1_H */

/* [] END OF FILE */
