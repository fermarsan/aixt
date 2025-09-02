/*******************************************************************************
* File Name: pwm4.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the pwm4
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

#if !defined(CY_TCPWM_pwm4_H)
#define CY_TCPWM_pwm4_H


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
} pwm4_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  pwm4_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define pwm4_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define pwm4_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define pwm4_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define pwm4_QUAD_ENCODING_MODES            (0lu)
#define pwm4_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define pwm4_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define pwm4_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define pwm4_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define pwm4_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define pwm4_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define pwm4_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define pwm4_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define pwm4_TC_RUN_MODE                    (0lu)
#define pwm4_TC_COUNTER_MODE                (0lu)
#define pwm4_TC_COMP_CAP_MODE               (2lu)
#define pwm4_TC_PRESCALER                   (0lu)

/* Signal modes */
#define pwm4_TC_RELOAD_SIGNAL_MODE          (0lu)
#define pwm4_TC_COUNT_SIGNAL_MODE           (3lu)
#define pwm4_TC_START_SIGNAL_MODE           (0lu)
#define pwm4_TC_STOP_SIGNAL_MODE            (0lu)
#define pwm4_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm4_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define pwm4_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define pwm4_TC_START_SIGNAL_PRESENT        (0lu)
#define pwm4_TC_STOP_SIGNAL_PRESENT         (0lu)
#define pwm4_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm4_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define pwm4_PWM_KILL_EVENT                 (0lu)
#define pwm4_PWM_STOP_EVENT                 (0lu)
#define pwm4_PWM_MODE                       (4lu)
#define pwm4_PWM_OUT_N_INVERT               (0lu)
#define pwm4_PWM_OUT_INVERT                 (0lu)
#define pwm4_PWM_ALIGN                      (0lu)
#define pwm4_PWM_RUN_MODE                   (0lu)
#define pwm4_PWM_DEAD_TIME_CYCLE            (0lu)
#define pwm4_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define pwm4_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define pwm4_PWM_COUNT_SIGNAL_MODE          (3lu)
#define pwm4_PWM_START_SIGNAL_MODE          (0lu)
#define pwm4_PWM_STOP_SIGNAL_MODE           (0lu)
#define pwm4_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm4_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define pwm4_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define pwm4_PWM_START_SIGNAL_PRESENT       (0lu)
#define pwm4_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define pwm4_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm4_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define pwm4_TC_PERIOD_VALUE                (65535lu)
#define pwm4_TC_COMPARE_VALUE               (65535lu)
#define pwm4_TC_COMPARE_BUF_VALUE           (65535lu)
#define pwm4_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define pwm4_PWM_PERIOD_VALUE               (65535lu)
#define pwm4_PWM_PERIOD_BUF_VALUE           (65535lu)
#define pwm4_PWM_PERIOD_SWAP                (0lu)
#define pwm4_PWM_COMPARE_VALUE              (65535lu)
#define pwm4_PWM_COMPARE_BUF_VALUE          (65535lu)
#define pwm4_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define pwm4__LEFT 0
#define pwm4__RIGHT 1
#define pwm4__CENTER 2
#define pwm4__ASYMMETRIC 3

#define pwm4__X1 0
#define pwm4__X2 1
#define pwm4__X4 2

#define pwm4__PWM 4
#define pwm4__PWM_DT 5
#define pwm4__PWM_PR 6

#define pwm4__INVERSE 1
#define pwm4__DIRECT 0

#define pwm4__CAPTURE 2
#define pwm4__COMPARE 0

#define pwm4__TRIG_LEVEL 3
#define pwm4__TRIG_RISING 0
#define pwm4__TRIG_FALLING 1
#define pwm4__TRIG_BOTH 2

#define pwm4__INTR_MASK_TC 1
#define pwm4__INTR_MASK_CC_MATCH 2
#define pwm4__INTR_MASK_NONE 0
#define pwm4__INTR_MASK_TC_CC 3

#define pwm4__UNCONFIG 8
#define pwm4__TIMER 1
#define pwm4__QUAD 3
#define pwm4__PWM_SEL 7

#define pwm4__COUNT_UP 0
#define pwm4__COUNT_DOWN 1
#define pwm4__COUNT_UPDOWN0 2
#define pwm4__COUNT_UPDOWN1 3


/* Prescaler */
#define pwm4_PRESCALE_DIVBY1                ((uint32)(0u << pwm4_PRESCALER_SHIFT))
#define pwm4_PRESCALE_DIVBY2                ((uint32)(1u << pwm4_PRESCALER_SHIFT))
#define pwm4_PRESCALE_DIVBY4                ((uint32)(2u << pwm4_PRESCALER_SHIFT))
#define pwm4_PRESCALE_DIVBY8                ((uint32)(3u << pwm4_PRESCALER_SHIFT))
#define pwm4_PRESCALE_DIVBY16               ((uint32)(4u << pwm4_PRESCALER_SHIFT))
#define pwm4_PRESCALE_DIVBY32               ((uint32)(5u << pwm4_PRESCALER_SHIFT))
#define pwm4_PRESCALE_DIVBY64               ((uint32)(6u << pwm4_PRESCALER_SHIFT))
#define pwm4_PRESCALE_DIVBY128              ((uint32)(7u << pwm4_PRESCALER_SHIFT))

/* TCPWM set modes */
#define pwm4_MODE_TIMER_COMPARE             ((uint32)(pwm4__COMPARE         <<  \
                                                                  pwm4_MODE_SHIFT))
#define pwm4_MODE_TIMER_CAPTURE             ((uint32)(pwm4__CAPTURE         <<  \
                                                                  pwm4_MODE_SHIFT))
#define pwm4_MODE_QUAD                      ((uint32)(pwm4__QUAD            <<  \
                                                                  pwm4_MODE_SHIFT))
#define pwm4_MODE_PWM                       ((uint32)(pwm4__PWM             <<  \
                                                                  pwm4_MODE_SHIFT))
#define pwm4_MODE_PWM_DT                    ((uint32)(pwm4__PWM_DT          <<  \
                                                                  pwm4_MODE_SHIFT))
#define pwm4_MODE_PWM_PR                    ((uint32)(pwm4__PWM_PR          <<  \
                                                                  pwm4_MODE_SHIFT))

/* Quad Modes */
#define pwm4_MODE_X1                        ((uint32)(pwm4__X1              <<  \
                                                                  pwm4_QUAD_MODE_SHIFT))
#define pwm4_MODE_X2                        ((uint32)(pwm4__X2              <<  \
                                                                  pwm4_QUAD_MODE_SHIFT))
#define pwm4_MODE_X4                        ((uint32)(pwm4__X4              <<  \
                                                                  pwm4_QUAD_MODE_SHIFT))

/* Counter modes */
#define pwm4_COUNT_UP                       ((uint32)(pwm4__COUNT_UP        <<  \
                                                                  pwm4_UPDOWN_SHIFT))
#define pwm4_COUNT_DOWN                     ((uint32)(pwm4__COUNT_DOWN      <<  \
                                                                  pwm4_UPDOWN_SHIFT))
#define pwm4_COUNT_UPDOWN0                  ((uint32)(pwm4__COUNT_UPDOWN0   <<  \
                                                                  pwm4_UPDOWN_SHIFT))
#define pwm4_COUNT_UPDOWN1                  ((uint32)(pwm4__COUNT_UPDOWN1   <<  \
                                                                  pwm4_UPDOWN_SHIFT))

/* PWM output invert */
#define pwm4_INVERT_LINE                    ((uint32)(pwm4__INVERSE         <<  \
                                                                  pwm4_INV_OUT_SHIFT))
#define pwm4_INVERT_LINE_N                  ((uint32)(pwm4__INVERSE         <<  \
                                                                  pwm4_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define pwm4_TRIG_RISING                    ((uint32)pwm4__TRIG_RISING)
#define pwm4_TRIG_FALLING                   ((uint32)pwm4__TRIG_FALLING)
#define pwm4_TRIG_BOTH                      ((uint32)pwm4__TRIG_BOTH)
#define pwm4_TRIG_LEVEL                     ((uint32)pwm4__TRIG_LEVEL)

/* Interrupt mask */
#define pwm4_INTR_MASK_TC                   ((uint32)pwm4__INTR_MASK_TC)
#define pwm4_INTR_MASK_CC_MATCH             ((uint32)pwm4__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define pwm4_CC_MATCH_SET                   (0x00u)
#define pwm4_CC_MATCH_CLEAR                 (0x01u)
#define pwm4_CC_MATCH_INVERT                (0x02u)
#define pwm4_CC_MATCH_NO_CHANGE             (0x03u)
#define pwm4_OVERLOW_SET                    (0x00u)
#define pwm4_OVERLOW_CLEAR                  (0x04u)
#define pwm4_OVERLOW_INVERT                 (0x08u)
#define pwm4_OVERLOW_NO_CHANGE              (0x0Cu)
#define pwm4_UNDERFLOW_SET                  (0x00u)
#define pwm4_UNDERFLOW_CLEAR                (0x10u)
#define pwm4_UNDERFLOW_INVERT               (0x20u)
#define pwm4_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define pwm4_PWM_MODE_LEFT                  (pwm4_CC_MATCH_CLEAR        |   \
                                                         pwm4_OVERLOW_SET           |   \
                                                         pwm4_UNDERFLOW_NO_CHANGE)
#define pwm4_PWM_MODE_RIGHT                 (pwm4_CC_MATCH_SET          |   \
                                                         pwm4_OVERLOW_NO_CHANGE     |   \
                                                         pwm4_UNDERFLOW_CLEAR)
#define pwm4_PWM_MODE_ASYM                  (pwm4_CC_MATCH_INVERT       |   \
                                                         pwm4_OVERLOW_SET           |   \
                                                         pwm4_UNDERFLOW_CLEAR)

#if (pwm4_CY_TCPWM_V2)
    #if(pwm4_CY_TCPWM_4000)
        #define pwm4_PWM_MODE_CENTER                (pwm4_CC_MATCH_INVERT       |   \
                                                                 pwm4_OVERLOW_NO_CHANGE     |   \
                                                                 pwm4_UNDERFLOW_CLEAR)
    #else
        #define pwm4_PWM_MODE_CENTER                (pwm4_CC_MATCH_INVERT       |   \
                                                                 pwm4_OVERLOW_SET           |   \
                                                                 pwm4_UNDERFLOW_CLEAR)
    #endif /* (pwm4_CY_TCPWM_4000) */
#else
    #define pwm4_PWM_MODE_CENTER                (pwm4_CC_MATCH_INVERT       |   \
                                                             pwm4_OVERLOW_NO_CHANGE     |   \
                                                             pwm4_UNDERFLOW_CLEAR)
#endif /* (pwm4_CY_TCPWM_NEW) */

/* Command operations without condition */
#define pwm4_CMD_CAPTURE                    (0u)
#define pwm4_CMD_RELOAD                     (8u)
#define pwm4_CMD_STOP                       (16u)
#define pwm4_CMD_START                      (24u)

/* Status */
#define pwm4_STATUS_DOWN                    (1u)
#define pwm4_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   pwm4_Init(void);
void   pwm4_Enable(void);
void   pwm4_Start(void);
void   pwm4_Stop(void);

void   pwm4_SetMode(uint32 mode);
void   pwm4_SetCounterMode(uint32 counterMode);
void   pwm4_SetPWMMode(uint32 modeMask);
void   pwm4_SetQDMode(uint32 qdMode);

void   pwm4_SetPrescaler(uint32 prescaler);
void   pwm4_TriggerCommand(uint32 mask, uint32 command);
void   pwm4_SetOneShot(uint32 oneShotEnable);
uint32 pwm4_ReadStatus(void);

void   pwm4_SetPWMSyncKill(uint32 syncKillEnable);
void   pwm4_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   pwm4_SetPWMDeadTime(uint32 deadTime);
void   pwm4_SetPWMInvert(uint32 mask);

void   pwm4_SetInterruptMode(uint32 interruptMask);
uint32 pwm4_GetInterruptSourceMasked(void);
uint32 pwm4_GetInterruptSource(void);
void   pwm4_ClearInterrupt(uint32 interruptMask);
void   pwm4_SetInterrupt(uint32 interruptMask);

void   pwm4_WriteCounter(uint32 count);
uint32 pwm4_ReadCounter(void);

uint32 pwm4_ReadCapture(void);
uint32 pwm4_ReadCaptureBuf(void);

void   pwm4_WritePeriod(uint32 period);
uint32 pwm4_ReadPeriod(void);
void   pwm4_WritePeriodBuf(uint32 periodBuf);
uint32 pwm4_ReadPeriodBuf(void);

void   pwm4_WriteCompare(uint32 compare);
uint32 pwm4_ReadCompare(void);
void   pwm4_WriteCompareBuf(uint32 compareBuf);
uint32 pwm4_ReadCompareBuf(void);

void   pwm4_SetPeriodSwap(uint32 swapEnable);
void   pwm4_SetCompareSwap(uint32 swapEnable);

void   pwm4_SetCaptureMode(uint32 triggerMode);
void   pwm4_SetReloadMode(uint32 triggerMode);
void   pwm4_SetStartMode(uint32 triggerMode);
void   pwm4_SetStopMode(uint32 triggerMode);
void   pwm4_SetCountMode(uint32 triggerMode);

void   pwm4_SaveConfig(void);
void   pwm4_RestoreConfig(void);
void   pwm4_Sleep(void);
void   pwm4_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define pwm4_BLOCK_CONTROL_REG              (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm4_BLOCK_CONTROL_PTR              ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm4_COMMAND_REG                    (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm4_COMMAND_PTR                    ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm4_INTRRUPT_CAUSE_REG             (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm4_INTRRUPT_CAUSE_PTR             ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm4_CONTROL_REG                    (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__CTRL )
#define pwm4_CONTROL_PTR                    ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__CTRL )
#define pwm4_STATUS_REG                     (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__STATUS )
#define pwm4_STATUS_PTR                     ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__STATUS )
#define pwm4_COUNTER_REG                    (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__COUNTER )
#define pwm4_COUNTER_PTR                    ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__COUNTER )
#define pwm4_COMP_CAP_REG                   (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__CC )
#define pwm4_COMP_CAP_PTR                   ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__CC )
#define pwm4_COMP_CAP_BUF_REG               (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm4_COMP_CAP_BUF_PTR               ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm4_PERIOD_REG                     (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__PERIOD )
#define pwm4_PERIOD_PTR                     ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__PERIOD )
#define pwm4_PERIOD_BUF_REG                 (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm4_PERIOD_BUF_PTR                 ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm4_TRIG_CONTROL0_REG              (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm4_TRIG_CONTROL0_PTR              ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm4_TRIG_CONTROL1_REG              (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm4_TRIG_CONTROL1_PTR              ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm4_TRIG_CONTROL2_REG              (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm4_TRIG_CONTROL2_PTR              ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm4_INTERRUPT_REQ_REG              (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__INTR )
#define pwm4_INTERRUPT_REQ_PTR              ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__INTR )
#define pwm4_INTERRUPT_SET_REG              (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm4_INTERRUPT_SET_PTR              ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm4_INTERRUPT_MASK_REG             (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm4_INTERRUPT_MASK_PTR             ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm4_INTERRUPT_MASKED_REG           (*(reg32 *) pwm4_cy_m0s8_tcpwm_1__INTR_MASKED )
#define pwm4_INTERRUPT_MASKED_PTR           ( (reg32 *) pwm4_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define pwm4_MASK                           ((uint32)pwm4_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define pwm4_RELOAD_CC_SHIFT                (0u)
#define pwm4_RELOAD_PERIOD_SHIFT            (1u)
#define pwm4_PWM_SYNC_KILL_SHIFT            (2u)
#define pwm4_PWM_STOP_KILL_SHIFT            (3u)
#define pwm4_PRESCALER_SHIFT                (8u)
#define pwm4_UPDOWN_SHIFT                   (16u)
#define pwm4_ONESHOT_SHIFT                  (18u)
#define pwm4_QUAD_MODE_SHIFT                (20u)
#define pwm4_INV_OUT_SHIFT                  (20u)
#define pwm4_INV_COMPL_OUT_SHIFT            (21u)
#define pwm4_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define pwm4_RELOAD_CC_MASK                 ((uint32)(pwm4_1BIT_MASK        <<  \
                                                                            pwm4_RELOAD_CC_SHIFT))
#define pwm4_RELOAD_PERIOD_MASK             ((uint32)(pwm4_1BIT_MASK        <<  \
                                                                            pwm4_RELOAD_PERIOD_SHIFT))
#define pwm4_PWM_SYNC_KILL_MASK             ((uint32)(pwm4_1BIT_MASK        <<  \
                                                                            pwm4_PWM_SYNC_KILL_SHIFT))
#define pwm4_PWM_STOP_KILL_MASK             ((uint32)(pwm4_1BIT_MASK        <<  \
                                                                            pwm4_PWM_STOP_KILL_SHIFT))
#define pwm4_PRESCALER_MASK                 ((uint32)(pwm4_8BIT_MASK        <<  \
                                                                            pwm4_PRESCALER_SHIFT))
#define pwm4_UPDOWN_MASK                    ((uint32)(pwm4_2BIT_MASK        <<  \
                                                                            pwm4_UPDOWN_SHIFT))
#define pwm4_ONESHOT_MASK                   ((uint32)(pwm4_1BIT_MASK        <<  \
                                                                            pwm4_ONESHOT_SHIFT))
#define pwm4_QUAD_MODE_MASK                 ((uint32)(pwm4_3BIT_MASK        <<  \
                                                                            pwm4_QUAD_MODE_SHIFT))
#define pwm4_INV_OUT_MASK                   ((uint32)(pwm4_2BIT_MASK        <<  \
                                                                            pwm4_INV_OUT_SHIFT))
#define pwm4_MODE_MASK                      ((uint32)(pwm4_3BIT_MASK        <<  \
                                                                            pwm4_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define pwm4_CAPTURE_SHIFT                  (0u)
#define pwm4_COUNT_SHIFT                    (2u)
#define pwm4_RELOAD_SHIFT                   (4u)
#define pwm4_STOP_SHIFT                     (6u)
#define pwm4_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define pwm4_CAPTURE_MASK                   ((uint32)(pwm4_2BIT_MASK        <<  \
                                                                  pwm4_CAPTURE_SHIFT))
#define pwm4_COUNT_MASK                     ((uint32)(pwm4_2BIT_MASK        <<  \
                                                                  pwm4_COUNT_SHIFT))
#define pwm4_RELOAD_MASK                    ((uint32)(pwm4_2BIT_MASK        <<  \
                                                                  pwm4_RELOAD_SHIFT))
#define pwm4_STOP_MASK                      ((uint32)(pwm4_2BIT_MASK        <<  \
                                                                  pwm4_STOP_SHIFT))
#define pwm4_START_MASK                     ((uint32)(pwm4_2BIT_MASK        <<  \
                                                                  pwm4_START_SHIFT))

/* MASK */
#define pwm4_1BIT_MASK                      ((uint32)0x01u)
#define pwm4_2BIT_MASK                      ((uint32)0x03u)
#define pwm4_3BIT_MASK                      ((uint32)0x07u)
#define pwm4_6BIT_MASK                      ((uint32)0x3Fu)
#define pwm4_8BIT_MASK                      ((uint32)0xFFu)
#define pwm4_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define pwm4_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define pwm4_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(pwm4_QUAD_ENCODING_MODES     << pwm4_QUAD_MODE_SHIFT))       |\
         ((uint32)(pwm4_CONFIG                  << pwm4_MODE_SHIFT)))

#define pwm4_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(pwm4_PWM_STOP_EVENT          << pwm4_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(pwm4_PWM_OUT_INVERT          << pwm4_INV_OUT_SHIFT))         |\
         ((uint32)(pwm4_PWM_OUT_N_INVERT        << pwm4_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(pwm4_PWM_MODE                << pwm4_MODE_SHIFT)))

#define pwm4_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(pwm4_PWM_RUN_MODE         << pwm4_ONESHOT_SHIFT))
            
#define pwm4_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(pwm4_PWM_ALIGN            << pwm4_UPDOWN_SHIFT))

#define pwm4_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(pwm4_PWM_KILL_EVENT      << pwm4_PWM_SYNC_KILL_SHIFT))

#define pwm4_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(pwm4_PWM_DEAD_TIME_CYCLE  << pwm4_PRESCALER_SHIFT))

#define pwm4_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(pwm4_PWM_PRESCALER        << pwm4_PRESCALER_SHIFT))

#define pwm4_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(pwm4_TC_PRESCALER            << pwm4_PRESCALER_SHIFT))       |\
         ((uint32)(pwm4_TC_COUNTER_MODE         << pwm4_UPDOWN_SHIFT))          |\
         ((uint32)(pwm4_TC_RUN_MODE             << pwm4_ONESHOT_SHIFT))         |\
         ((uint32)(pwm4_TC_COMP_CAP_MODE        << pwm4_MODE_SHIFT)))
        
#define pwm4_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(pwm4_QUAD_PHIA_SIGNAL_MODE   << pwm4_COUNT_SHIFT))           |\
         ((uint32)(pwm4_QUAD_INDEX_SIGNAL_MODE  << pwm4_RELOAD_SHIFT))          |\
         ((uint32)(pwm4_QUAD_STOP_SIGNAL_MODE   << pwm4_STOP_SHIFT))            |\
         ((uint32)(pwm4_QUAD_PHIB_SIGNAL_MODE   << pwm4_START_SHIFT)))

#define pwm4_PWM_SIGNALS_MODES                                                              \
        (((uint32)(pwm4_PWM_SWITCH_SIGNAL_MODE  << pwm4_CAPTURE_SHIFT))         |\
         ((uint32)(pwm4_PWM_COUNT_SIGNAL_MODE   << pwm4_COUNT_SHIFT))           |\
         ((uint32)(pwm4_PWM_RELOAD_SIGNAL_MODE  << pwm4_RELOAD_SHIFT))          |\
         ((uint32)(pwm4_PWM_STOP_SIGNAL_MODE    << pwm4_STOP_SHIFT))            |\
         ((uint32)(pwm4_PWM_START_SIGNAL_MODE   << pwm4_START_SHIFT)))

#define pwm4_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(pwm4_TC_CAPTURE_SIGNAL_MODE  << pwm4_CAPTURE_SHIFT))         |\
         ((uint32)(pwm4_TC_COUNT_SIGNAL_MODE    << pwm4_COUNT_SHIFT))           |\
         ((uint32)(pwm4_TC_RELOAD_SIGNAL_MODE   << pwm4_RELOAD_SHIFT))          |\
         ((uint32)(pwm4_TC_STOP_SIGNAL_MODE     << pwm4_STOP_SHIFT))            |\
         ((uint32)(pwm4_TC_START_SIGNAL_MODE    << pwm4_START_SHIFT)))
        
#define pwm4_TIMER_UPDOWN_CNT_USED                                                          \
                ((pwm4__COUNT_UPDOWN0 == pwm4_TC_COUNTER_MODE)                  ||\
                 (pwm4__COUNT_UPDOWN1 == pwm4_TC_COUNTER_MODE))

#define pwm4_PWM_UPDOWN_CNT_USED                                                            \
                ((pwm4__CENTER == pwm4_PWM_ALIGN)                               ||\
                 (pwm4__ASYMMETRIC == pwm4_PWM_ALIGN))               
        
#define pwm4_PWM_PR_INIT_VALUE              (1u)
#define pwm4_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_pwm4_H */

/* [] END OF FILE */
