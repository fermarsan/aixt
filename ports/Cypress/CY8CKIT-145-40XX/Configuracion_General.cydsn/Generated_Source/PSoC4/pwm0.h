/*******************************************************************************
* File Name: pwm0.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the pwm0
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

#if !defined(CY_TCPWM_pwm0_H)
#define CY_TCPWM_pwm0_H


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
} pwm0_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  pwm0_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define pwm0_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define pwm0_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define pwm0_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define pwm0_QUAD_ENCODING_MODES            (0lu)
#define pwm0_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define pwm0_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define pwm0_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define pwm0_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define pwm0_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define pwm0_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define pwm0_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define pwm0_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define pwm0_TC_RUN_MODE                    (0lu)
#define pwm0_TC_COUNTER_MODE                (0lu)
#define pwm0_TC_COMP_CAP_MODE               (2lu)
#define pwm0_TC_PRESCALER                   (0lu)

/* Signal modes */
#define pwm0_TC_RELOAD_SIGNAL_MODE          (0lu)
#define pwm0_TC_COUNT_SIGNAL_MODE           (3lu)
#define pwm0_TC_START_SIGNAL_MODE           (0lu)
#define pwm0_TC_STOP_SIGNAL_MODE            (0lu)
#define pwm0_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm0_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define pwm0_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define pwm0_TC_START_SIGNAL_PRESENT        (0lu)
#define pwm0_TC_STOP_SIGNAL_PRESENT         (0lu)
#define pwm0_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm0_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define pwm0_PWM_KILL_EVENT                 (0lu)
#define pwm0_PWM_STOP_EVENT                 (0lu)
#define pwm0_PWM_MODE                       (4lu)
#define pwm0_PWM_OUT_N_INVERT               (0lu)
#define pwm0_PWM_OUT_INVERT                 (0lu)
#define pwm0_PWM_ALIGN                      (0lu)
#define pwm0_PWM_RUN_MODE                   (0lu)
#define pwm0_PWM_DEAD_TIME_CYCLE            (0lu)
#define pwm0_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define pwm0_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define pwm0_PWM_COUNT_SIGNAL_MODE          (3lu)
#define pwm0_PWM_START_SIGNAL_MODE          (0lu)
#define pwm0_PWM_STOP_SIGNAL_MODE           (0lu)
#define pwm0_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm0_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define pwm0_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define pwm0_PWM_START_SIGNAL_PRESENT       (0lu)
#define pwm0_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define pwm0_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm0_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define pwm0_TC_PERIOD_VALUE                (65535lu)
#define pwm0_TC_COMPARE_VALUE               (65535lu)
#define pwm0_TC_COMPARE_BUF_VALUE           (65535lu)
#define pwm0_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define pwm0_PWM_PERIOD_VALUE               (65535lu)
#define pwm0_PWM_PERIOD_BUF_VALUE           (65535lu)
#define pwm0_PWM_PERIOD_SWAP                (0lu)
#define pwm0_PWM_COMPARE_VALUE              (32767lu)
#define pwm0_PWM_COMPARE_BUF_VALUE          (65535lu)
#define pwm0_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define pwm0__LEFT 0
#define pwm0__RIGHT 1
#define pwm0__CENTER 2
#define pwm0__ASYMMETRIC 3

#define pwm0__X1 0
#define pwm0__X2 1
#define pwm0__X4 2

#define pwm0__PWM 4
#define pwm0__PWM_DT 5
#define pwm0__PWM_PR 6

#define pwm0__INVERSE 1
#define pwm0__DIRECT 0

#define pwm0__CAPTURE 2
#define pwm0__COMPARE 0

#define pwm0__TRIG_LEVEL 3
#define pwm0__TRIG_RISING 0
#define pwm0__TRIG_FALLING 1
#define pwm0__TRIG_BOTH 2

#define pwm0__INTR_MASK_TC 1
#define pwm0__INTR_MASK_CC_MATCH 2
#define pwm0__INTR_MASK_NONE 0
#define pwm0__INTR_MASK_TC_CC 3

#define pwm0__UNCONFIG 8
#define pwm0__TIMER 1
#define pwm0__QUAD 3
#define pwm0__PWM_SEL 7

#define pwm0__COUNT_UP 0
#define pwm0__COUNT_DOWN 1
#define pwm0__COUNT_UPDOWN0 2
#define pwm0__COUNT_UPDOWN1 3


/* Prescaler */
#define pwm0_PRESCALE_DIVBY1                ((uint32)(0u << pwm0_PRESCALER_SHIFT))
#define pwm0_PRESCALE_DIVBY2                ((uint32)(1u << pwm0_PRESCALER_SHIFT))
#define pwm0_PRESCALE_DIVBY4                ((uint32)(2u << pwm0_PRESCALER_SHIFT))
#define pwm0_PRESCALE_DIVBY8                ((uint32)(3u << pwm0_PRESCALER_SHIFT))
#define pwm0_PRESCALE_DIVBY16               ((uint32)(4u << pwm0_PRESCALER_SHIFT))
#define pwm0_PRESCALE_DIVBY32               ((uint32)(5u << pwm0_PRESCALER_SHIFT))
#define pwm0_PRESCALE_DIVBY64               ((uint32)(6u << pwm0_PRESCALER_SHIFT))
#define pwm0_PRESCALE_DIVBY128              ((uint32)(7u << pwm0_PRESCALER_SHIFT))

/* TCPWM set modes */
#define pwm0_MODE_TIMER_COMPARE             ((uint32)(pwm0__COMPARE         <<  \
                                                                  pwm0_MODE_SHIFT))
#define pwm0_MODE_TIMER_CAPTURE             ((uint32)(pwm0__CAPTURE         <<  \
                                                                  pwm0_MODE_SHIFT))
#define pwm0_MODE_QUAD                      ((uint32)(pwm0__QUAD            <<  \
                                                                  pwm0_MODE_SHIFT))
#define pwm0_MODE_PWM                       ((uint32)(pwm0__PWM             <<  \
                                                                  pwm0_MODE_SHIFT))
#define pwm0_MODE_PWM_DT                    ((uint32)(pwm0__PWM_DT          <<  \
                                                                  pwm0_MODE_SHIFT))
#define pwm0_MODE_PWM_PR                    ((uint32)(pwm0__PWM_PR          <<  \
                                                                  pwm0_MODE_SHIFT))

/* Quad Modes */
#define pwm0_MODE_X1                        ((uint32)(pwm0__X1              <<  \
                                                                  pwm0_QUAD_MODE_SHIFT))
#define pwm0_MODE_X2                        ((uint32)(pwm0__X2              <<  \
                                                                  pwm0_QUAD_MODE_SHIFT))
#define pwm0_MODE_X4                        ((uint32)(pwm0__X4              <<  \
                                                                  pwm0_QUAD_MODE_SHIFT))

/* Counter modes */
#define pwm0_COUNT_UP                       ((uint32)(pwm0__COUNT_UP        <<  \
                                                                  pwm0_UPDOWN_SHIFT))
#define pwm0_COUNT_DOWN                     ((uint32)(pwm0__COUNT_DOWN      <<  \
                                                                  pwm0_UPDOWN_SHIFT))
#define pwm0_COUNT_UPDOWN0                  ((uint32)(pwm0__COUNT_UPDOWN0   <<  \
                                                                  pwm0_UPDOWN_SHIFT))
#define pwm0_COUNT_UPDOWN1                  ((uint32)(pwm0__COUNT_UPDOWN1   <<  \
                                                                  pwm0_UPDOWN_SHIFT))

/* PWM output invert */
#define pwm0_INVERT_LINE                    ((uint32)(pwm0__INVERSE         <<  \
                                                                  pwm0_INV_OUT_SHIFT))
#define pwm0_INVERT_LINE_N                  ((uint32)(pwm0__INVERSE         <<  \
                                                                  pwm0_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define pwm0_TRIG_RISING                    ((uint32)pwm0__TRIG_RISING)
#define pwm0_TRIG_FALLING                   ((uint32)pwm0__TRIG_FALLING)
#define pwm0_TRIG_BOTH                      ((uint32)pwm0__TRIG_BOTH)
#define pwm0_TRIG_LEVEL                     ((uint32)pwm0__TRIG_LEVEL)

/* Interrupt mask */
#define pwm0_INTR_MASK_TC                   ((uint32)pwm0__INTR_MASK_TC)
#define pwm0_INTR_MASK_CC_MATCH             ((uint32)pwm0__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define pwm0_CC_MATCH_SET                   (0x00u)
#define pwm0_CC_MATCH_CLEAR                 (0x01u)
#define pwm0_CC_MATCH_INVERT                (0x02u)
#define pwm0_CC_MATCH_NO_CHANGE             (0x03u)
#define pwm0_OVERLOW_SET                    (0x00u)
#define pwm0_OVERLOW_CLEAR                  (0x04u)
#define pwm0_OVERLOW_INVERT                 (0x08u)
#define pwm0_OVERLOW_NO_CHANGE              (0x0Cu)
#define pwm0_UNDERFLOW_SET                  (0x00u)
#define pwm0_UNDERFLOW_CLEAR                (0x10u)
#define pwm0_UNDERFLOW_INVERT               (0x20u)
#define pwm0_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define pwm0_PWM_MODE_LEFT                  (pwm0_CC_MATCH_CLEAR        |   \
                                                         pwm0_OVERLOW_SET           |   \
                                                         pwm0_UNDERFLOW_NO_CHANGE)
#define pwm0_PWM_MODE_RIGHT                 (pwm0_CC_MATCH_SET          |   \
                                                         pwm0_OVERLOW_NO_CHANGE     |   \
                                                         pwm0_UNDERFLOW_CLEAR)
#define pwm0_PWM_MODE_ASYM                  (pwm0_CC_MATCH_INVERT       |   \
                                                         pwm0_OVERLOW_SET           |   \
                                                         pwm0_UNDERFLOW_CLEAR)

#if (pwm0_CY_TCPWM_V2)
    #if(pwm0_CY_TCPWM_4000)
        #define pwm0_PWM_MODE_CENTER                (pwm0_CC_MATCH_INVERT       |   \
                                                                 pwm0_OVERLOW_NO_CHANGE     |   \
                                                                 pwm0_UNDERFLOW_CLEAR)
    #else
        #define pwm0_PWM_MODE_CENTER                (pwm0_CC_MATCH_INVERT       |   \
                                                                 pwm0_OVERLOW_SET           |   \
                                                                 pwm0_UNDERFLOW_CLEAR)
    #endif /* (pwm0_CY_TCPWM_4000) */
#else
    #define pwm0_PWM_MODE_CENTER                (pwm0_CC_MATCH_INVERT       |   \
                                                             pwm0_OVERLOW_NO_CHANGE     |   \
                                                             pwm0_UNDERFLOW_CLEAR)
#endif /* (pwm0_CY_TCPWM_NEW) */

/* Command operations without condition */
#define pwm0_CMD_CAPTURE                    (0u)
#define pwm0_CMD_RELOAD                     (8u)
#define pwm0_CMD_STOP                       (16u)
#define pwm0_CMD_START                      (24u)

/* Status */
#define pwm0_STATUS_DOWN                    (1u)
#define pwm0_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   pwm0_Init(void);
void   pwm0_Enable(void);
void   pwm0_Start(void);
void   pwm0_Stop(void);

void   pwm0_SetMode(uint32 mode);
void   pwm0_SetCounterMode(uint32 counterMode);
void   pwm0_SetPWMMode(uint32 modeMask);
void   pwm0_SetQDMode(uint32 qdMode);

void   pwm0_SetPrescaler(uint32 prescaler);
void   pwm0_TriggerCommand(uint32 mask, uint32 command);
void   pwm0_SetOneShot(uint32 oneShotEnable);
uint32 pwm0_ReadStatus(void);

void   pwm0_SetPWMSyncKill(uint32 syncKillEnable);
void   pwm0_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   pwm0_SetPWMDeadTime(uint32 deadTime);
void   pwm0_SetPWMInvert(uint32 mask);

void   pwm0_SetInterruptMode(uint32 interruptMask);
uint32 pwm0_GetInterruptSourceMasked(void);
uint32 pwm0_GetInterruptSource(void);
void   pwm0_ClearInterrupt(uint32 interruptMask);
void   pwm0_SetInterrupt(uint32 interruptMask);

void   pwm0_WriteCounter(uint32 count);
uint32 pwm0_ReadCounter(void);

uint32 pwm0_ReadCapture(void);
uint32 pwm0_ReadCaptureBuf(void);

void   pwm0_WritePeriod(uint32 period);
uint32 pwm0_ReadPeriod(void);
void   pwm0_WritePeriodBuf(uint32 periodBuf);
uint32 pwm0_ReadPeriodBuf(void);

void   pwm0_WriteCompare(uint32 compare);
uint32 pwm0_ReadCompare(void);
void   pwm0_WriteCompareBuf(uint32 compareBuf);
uint32 pwm0_ReadCompareBuf(void);

void   pwm0_SetPeriodSwap(uint32 swapEnable);
void   pwm0_SetCompareSwap(uint32 swapEnable);

void   pwm0_SetCaptureMode(uint32 triggerMode);
void   pwm0_SetReloadMode(uint32 triggerMode);
void   pwm0_SetStartMode(uint32 triggerMode);
void   pwm0_SetStopMode(uint32 triggerMode);
void   pwm0_SetCountMode(uint32 triggerMode);

void   pwm0_SaveConfig(void);
void   pwm0_RestoreConfig(void);
void   pwm0_Sleep(void);
void   pwm0_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define pwm0_BLOCK_CONTROL_REG              (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm0_BLOCK_CONTROL_PTR              ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm0_COMMAND_REG                    (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm0_COMMAND_PTR                    ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm0_INTRRUPT_CAUSE_REG             (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm0_INTRRUPT_CAUSE_PTR             ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm0_CONTROL_REG                    (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__CTRL )
#define pwm0_CONTROL_PTR                    ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__CTRL )
#define pwm0_STATUS_REG                     (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__STATUS )
#define pwm0_STATUS_PTR                     ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__STATUS )
#define pwm0_COUNTER_REG                    (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__COUNTER )
#define pwm0_COUNTER_PTR                    ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__COUNTER )
#define pwm0_COMP_CAP_REG                   (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__CC )
#define pwm0_COMP_CAP_PTR                   ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__CC )
#define pwm0_COMP_CAP_BUF_REG               (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm0_COMP_CAP_BUF_PTR               ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm0_PERIOD_REG                     (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__PERIOD )
#define pwm0_PERIOD_PTR                     ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__PERIOD )
#define pwm0_PERIOD_BUF_REG                 (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm0_PERIOD_BUF_PTR                 ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm0_TRIG_CONTROL0_REG              (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm0_TRIG_CONTROL0_PTR              ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm0_TRIG_CONTROL1_REG              (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm0_TRIG_CONTROL1_PTR              ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm0_TRIG_CONTROL2_REG              (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm0_TRIG_CONTROL2_PTR              ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm0_INTERRUPT_REQ_REG              (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__INTR )
#define pwm0_INTERRUPT_REQ_PTR              ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__INTR )
#define pwm0_INTERRUPT_SET_REG              (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm0_INTERRUPT_SET_PTR              ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm0_INTERRUPT_MASK_REG             (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm0_INTERRUPT_MASK_PTR             ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm0_INTERRUPT_MASKED_REG           (*(reg32 *) pwm0_cy_m0s8_tcpwm_1__INTR_MASKED )
#define pwm0_INTERRUPT_MASKED_PTR           ( (reg32 *) pwm0_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define pwm0_MASK                           ((uint32)pwm0_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define pwm0_RELOAD_CC_SHIFT                (0u)
#define pwm0_RELOAD_PERIOD_SHIFT            (1u)
#define pwm0_PWM_SYNC_KILL_SHIFT            (2u)
#define pwm0_PWM_STOP_KILL_SHIFT            (3u)
#define pwm0_PRESCALER_SHIFT                (8u)
#define pwm0_UPDOWN_SHIFT                   (16u)
#define pwm0_ONESHOT_SHIFT                  (18u)
#define pwm0_QUAD_MODE_SHIFT                (20u)
#define pwm0_INV_OUT_SHIFT                  (20u)
#define pwm0_INV_COMPL_OUT_SHIFT            (21u)
#define pwm0_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define pwm0_RELOAD_CC_MASK                 ((uint32)(pwm0_1BIT_MASK        <<  \
                                                                            pwm0_RELOAD_CC_SHIFT))
#define pwm0_RELOAD_PERIOD_MASK             ((uint32)(pwm0_1BIT_MASK        <<  \
                                                                            pwm0_RELOAD_PERIOD_SHIFT))
#define pwm0_PWM_SYNC_KILL_MASK             ((uint32)(pwm0_1BIT_MASK        <<  \
                                                                            pwm0_PWM_SYNC_KILL_SHIFT))
#define pwm0_PWM_STOP_KILL_MASK             ((uint32)(pwm0_1BIT_MASK        <<  \
                                                                            pwm0_PWM_STOP_KILL_SHIFT))
#define pwm0_PRESCALER_MASK                 ((uint32)(pwm0_8BIT_MASK        <<  \
                                                                            pwm0_PRESCALER_SHIFT))
#define pwm0_UPDOWN_MASK                    ((uint32)(pwm0_2BIT_MASK        <<  \
                                                                            pwm0_UPDOWN_SHIFT))
#define pwm0_ONESHOT_MASK                   ((uint32)(pwm0_1BIT_MASK        <<  \
                                                                            pwm0_ONESHOT_SHIFT))
#define pwm0_QUAD_MODE_MASK                 ((uint32)(pwm0_3BIT_MASK        <<  \
                                                                            pwm0_QUAD_MODE_SHIFT))
#define pwm0_INV_OUT_MASK                   ((uint32)(pwm0_2BIT_MASK        <<  \
                                                                            pwm0_INV_OUT_SHIFT))
#define pwm0_MODE_MASK                      ((uint32)(pwm0_3BIT_MASK        <<  \
                                                                            pwm0_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define pwm0_CAPTURE_SHIFT                  (0u)
#define pwm0_COUNT_SHIFT                    (2u)
#define pwm0_RELOAD_SHIFT                   (4u)
#define pwm0_STOP_SHIFT                     (6u)
#define pwm0_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define pwm0_CAPTURE_MASK                   ((uint32)(pwm0_2BIT_MASK        <<  \
                                                                  pwm0_CAPTURE_SHIFT))
#define pwm0_COUNT_MASK                     ((uint32)(pwm0_2BIT_MASK        <<  \
                                                                  pwm0_COUNT_SHIFT))
#define pwm0_RELOAD_MASK                    ((uint32)(pwm0_2BIT_MASK        <<  \
                                                                  pwm0_RELOAD_SHIFT))
#define pwm0_STOP_MASK                      ((uint32)(pwm0_2BIT_MASK        <<  \
                                                                  pwm0_STOP_SHIFT))
#define pwm0_START_MASK                     ((uint32)(pwm0_2BIT_MASK        <<  \
                                                                  pwm0_START_SHIFT))

/* MASK */
#define pwm0_1BIT_MASK                      ((uint32)0x01u)
#define pwm0_2BIT_MASK                      ((uint32)0x03u)
#define pwm0_3BIT_MASK                      ((uint32)0x07u)
#define pwm0_6BIT_MASK                      ((uint32)0x3Fu)
#define pwm0_8BIT_MASK                      ((uint32)0xFFu)
#define pwm0_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define pwm0_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define pwm0_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(pwm0_QUAD_ENCODING_MODES     << pwm0_QUAD_MODE_SHIFT))       |\
         ((uint32)(pwm0_CONFIG                  << pwm0_MODE_SHIFT)))

#define pwm0_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(pwm0_PWM_STOP_EVENT          << pwm0_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(pwm0_PWM_OUT_INVERT          << pwm0_INV_OUT_SHIFT))         |\
         ((uint32)(pwm0_PWM_OUT_N_INVERT        << pwm0_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(pwm0_PWM_MODE                << pwm0_MODE_SHIFT)))

#define pwm0_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(pwm0_PWM_RUN_MODE         << pwm0_ONESHOT_SHIFT))
            
#define pwm0_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(pwm0_PWM_ALIGN            << pwm0_UPDOWN_SHIFT))

#define pwm0_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(pwm0_PWM_KILL_EVENT      << pwm0_PWM_SYNC_KILL_SHIFT))

#define pwm0_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(pwm0_PWM_DEAD_TIME_CYCLE  << pwm0_PRESCALER_SHIFT))

#define pwm0_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(pwm0_PWM_PRESCALER        << pwm0_PRESCALER_SHIFT))

#define pwm0_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(pwm0_TC_PRESCALER            << pwm0_PRESCALER_SHIFT))       |\
         ((uint32)(pwm0_TC_COUNTER_MODE         << pwm0_UPDOWN_SHIFT))          |\
         ((uint32)(pwm0_TC_RUN_MODE             << pwm0_ONESHOT_SHIFT))         |\
         ((uint32)(pwm0_TC_COMP_CAP_MODE        << pwm0_MODE_SHIFT)))
        
#define pwm0_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(pwm0_QUAD_PHIA_SIGNAL_MODE   << pwm0_COUNT_SHIFT))           |\
         ((uint32)(pwm0_QUAD_INDEX_SIGNAL_MODE  << pwm0_RELOAD_SHIFT))          |\
         ((uint32)(pwm0_QUAD_STOP_SIGNAL_MODE   << pwm0_STOP_SHIFT))            |\
         ((uint32)(pwm0_QUAD_PHIB_SIGNAL_MODE   << pwm0_START_SHIFT)))

#define pwm0_PWM_SIGNALS_MODES                                                              \
        (((uint32)(pwm0_PWM_SWITCH_SIGNAL_MODE  << pwm0_CAPTURE_SHIFT))         |\
         ((uint32)(pwm0_PWM_COUNT_SIGNAL_MODE   << pwm0_COUNT_SHIFT))           |\
         ((uint32)(pwm0_PWM_RELOAD_SIGNAL_MODE  << pwm0_RELOAD_SHIFT))          |\
         ((uint32)(pwm0_PWM_STOP_SIGNAL_MODE    << pwm0_STOP_SHIFT))            |\
         ((uint32)(pwm0_PWM_START_SIGNAL_MODE   << pwm0_START_SHIFT)))

#define pwm0_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(pwm0_TC_CAPTURE_SIGNAL_MODE  << pwm0_CAPTURE_SHIFT))         |\
         ((uint32)(pwm0_TC_COUNT_SIGNAL_MODE    << pwm0_COUNT_SHIFT))           |\
         ((uint32)(pwm0_TC_RELOAD_SIGNAL_MODE   << pwm0_RELOAD_SHIFT))          |\
         ((uint32)(pwm0_TC_STOP_SIGNAL_MODE     << pwm0_STOP_SHIFT))            |\
         ((uint32)(pwm0_TC_START_SIGNAL_MODE    << pwm0_START_SHIFT)))
        
#define pwm0_TIMER_UPDOWN_CNT_USED                                                          \
                ((pwm0__COUNT_UPDOWN0 == pwm0_TC_COUNTER_MODE)                  ||\
                 (pwm0__COUNT_UPDOWN1 == pwm0_TC_COUNTER_MODE))

#define pwm0_PWM_UPDOWN_CNT_USED                                                            \
                ((pwm0__CENTER == pwm0_PWM_ALIGN)                               ||\
                 (pwm0__ASYMMETRIC == pwm0_PWM_ALIGN))               
        
#define pwm0_PWM_PR_INIT_VALUE              (1u)
#define pwm0_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_pwm0_H */

/* [] END OF FILE */
