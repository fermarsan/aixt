/*******************************************************************************
* File Name: pwm3.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the pwm3
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

#if !defined(CY_TCPWM_pwm3_H)
#define CY_TCPWM_pwm3_H


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
} pwm3_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  pwm3_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define pwm3_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define pwm3_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define pwm3_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define pwm3_QUAD_ENCODING_MODES            (0lu)
#define pwm3_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define pwm3_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define pwm3_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define pwm3_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define pwm3_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define pwm3_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define pwm3_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define pwm3_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define pwm3_TC_RUN_MODE                    (0lu)
#define pwm3_TC_COUNTER_MODE                (0lu)
#define pwm3_TC_COMP_CAP_MODE               (2lu)
#define pwm3_TC_PRESCALER                   (0lu)

/* Signal modes */
#define pwm3_TC_RELOAD_SIGNAL_MODE          (0lu)
#define pwm3_TC_COUNT_SIGNAL_MODE           (3lu)
#define pwm3_TC_START_SIGNAL_MODE           (0lu)
#define pwm3_TC_STOP_SIGNAL_MODE            (0lu)
#define pwm3_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm3_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define pwm3_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define pwm3_TC_START_SIGNAL_PRESENT        (0lu)
#define pwm3_TC_STOP_SIGNAL_PRESENT         (0lu)
#define pwm3_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm3_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define pwm3_PWM_KILL_EVENT                 (0lu)
#define pwm3_PWM_STOP_EVENT                 (0lu)
#define pwm3_PWM_MODE                       (4lu)
#define pwm3_PWM_OUT_N_INVERT               (0lu)
#define pwm3_PWM_OUT_INVERT                 (0lu)
#define pwm3_PWM_ALIGN                      (0lu)
#define pwm3_PWM_RUN_MODE                   (0lu)
#define pwm3_PWM_DEAD_TIME_CYCLE            (0lu)
#define pwm3_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define pwm3_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define pwm3_PWM_COUNT_SIGNAL_MODE          (3lu)
#define pwm3_PWM_START_SIGNAL_MODE          (0lu)
#define pwm3_PWM_STOP_SIGNAL_MODE           (0lu)
#define pwm3_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm3_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define pwm3_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define pwm3_PWM_START_SIGNAL_PRESENT       (0lu)
#define pwm3_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define pwm3_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm3_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define pwm3_TC_PERIOD_VALUE                (65535lu)
#define pwm3_TC_COMPARE_VALUE               (65535lu)
#define pwm3_TC_COMPARE_BUF_VALUE           (65535lu)
#define pwm3_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define pwm3_PWM_PERIOD_VALUE               (65535lu)
#define pwm3_PWM_PERIOD_BUF_VALUE           (65535lu)
#define pwm3_PWM_PERIOD_SWAP                (0lu)
#define pwm3_PWM_COMPARE_VALUE              (65535lu)
#define pwm3_PWM_COMPARE_BUF_VALUE          (65535lu)
#define pwm3_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define pwm3__LEFT 0
#define pwm3__RIGHT 1
#define pwm3__CENTER 2
#define pwm3__ASYMMETRIC 3

#define pwm3__X1 0
#define pwm3__X2 1
#define pwm3__X4 2

#define pwm3__PWM 4
#define pwm3__PWM_DT 5
#define pwm3__PWM_PR 6

#define pwm3__INVERSE 1
#define pwm3__DIRECT 0

#define pwm3__CAPTURE 2
#define pwm3__COMPARE 0

#define pwm3__TRIG_LEVEL 3
#define pwm3__TRIG_RISING 0
#define pwm3__TRIG_FALLING 1
#define pwm3__TRIG_BOTH 2

#define pwm3__INTR_MASK_TC 1
#define pwm3__INTR_MASK_CC_MATCH 2
#define pwm3__INTR_MASK_NONE 0
#define pwm3__INTR_MASK_TC_CC 3

#define pwm3__UNCONFIG 8
#define pwm3__TIMER 1
#define pwm3__QUAD 3
#define pwm3__PWM_SEL 7

#define pwm3__COUNT_UP 0
#define pwm3__COUNT_DOWN 1
#define pwm3__COUNT_UPDOWN0 2
#define pwm3__COUNT_UPDOWN1 3


/* Prescaler */
#define pwm3_PRESCALE_DIVBY1                ((uint32)(0u << pwm3_PRESCALER_SHIFT))
#define pwm3_PRESCALE_DIVBY2                ((uint32)(1u << pwm3_PRESCALER_SHIFT))
#define pwm3_PRESCALE_DIVBY4                ((uint32)(2u << pwm3_PRESCALER_SHIFT))
#define pwm3_PRESCALE_DIVBY8                ((uint32)(3u << pwm3_PRESCALER_SHIFT))
#define pwm3_PRESCALE_DIVBY16               ((uint32)(4u << pwm3_PRESCALER_SHIFT))
#define pwm3_PRESCALE_DIVBY32               ((uint32)(5u << pwm3_PRESCALER_SHIFT))
#define pwm3_PRESCALE_DIVBY64               ((uint32)(6u << pwm3_PRESCALER_SHIFT))
#define pwm3_PRESCALE_DIVBY128              ((uint32)(7u << pwm3_PRESCALER_SHIFT))

/* TCPWM set modes */
#define pwm3_MODE_TIMER_COMPARE             ((uint32)(pwm3__COMPARE         <<  \
                                                                  pwm3_MODE_SHIFT))
#define pwm3_MODE_TIMER_CAPTURE             ((uint32)(pwm3__CAPTURE         <<  \
                                                                  pwm3_MODE_SHIFT))
#define pwm3_MODE_QUAD                      ((uint32)(pwm3__QUAD            <<  \
                                                                  pwm3_MODE_SHIFT))
#define pwm3_MODE_PWM                       ((uint32)(pwm3__PWM             <<  \
                                                                  pwm3_MODE_SHIFT))
#define pwm3_MODE_PWM_DT                    ((uint32)(pwm3__PWM_DT          <<  \
                                                                  pwm3_MODE_SHIFT))
#define pwm3_MODE_PWM_PR                    ((uint32)(pwm3__PWM_PR          <<  \
                                                                  pwm3_MODE_SHIFT))

/* Quad Modes */
#define pwm3_MODE_X1                        ((uint32)(pwm3__X1              <<  \
                                                                  pwm3_QUAD_MODE_SHIFT))
#define pwm3_MODE_X2                        ((uint32)(pwm3__X2              <<  \
                                                                  pwm3_QUAD_MODE_SHIFT))
#define pwm3_MODE_X4                        ((uint32)(pwm3__X4              <<  \
                                                                  pwm3_QUAD_MODE_SHIFT))

/* Counter modes */
#define pwm3_COUNT_UP                       ((uint32)(pwm3__COUNT_UP        <<  \
                                                                  pwm3_UPDOWN_SHIFT))
#define pwm3_COUNT_DOWN                     ((uint32)(pwm3__COUNT_DOWN      <<  \
                                                                  pwm3_UPDOWN_SHIFT))
#define pwm3_COUNT_UPDOWN0                  ((uint32)(pwm3__COUNT_UPDOWN0   <<  \
                                                                  pwm3_UPDOWN_SHIFT))
#define pwm3_COUNT_UPDOWN1                  ((uint32)(pwm3__COUNT_UPDOWN1   <<  \
                                                                  pwm3_UPDOWN_SHIFT))

/* PWM output invert */
#define pwm3_INVERT_LINE                    ((uint32)(pwm3__INVERSE         <<  \
                                                                  pwm3_INV_OUT_SHIFT))
#define pwm3_INVERT_LINE_N                  ((uint32)(pwm3__INVERSE         <<  \
                                                                  pwm3_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define pwm3_TRIG_RISING                    ((uint32)pwm3__TRIG_RISING)
#define pwm3_TRIG_FALLING                   ((uint32)pwm3__TRIG_FALLING)
#define pwm3_TRIG_BOTH                      ((uint32)pwm3__TRIG_BOTH)
#define pwm3_TRIG_LEVEL                     ((uint32)pwm3__TRIG_LEVEL)

/* Interrupt mask */
#define pwm3_INTR_MASK_TC                   ((uint32)pwm3__INTR_MASK_TC)
#define pwm3_INTR_MASK_CC_MATCH             ((uint32)pwm3__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define pwm3_CC_MATCH_SET                   (0x00u)
#define pwm3_CC_MATCH_CLEAR                 (0x01u)
#define pwm3_CC_MATCH_INVERT                (0x02u)
#define pwm3_CC_MATCH_NO_CHANGE             (0x03u)
#define pwm3_OVERLOW_SET                    (0x00u)
#define pwm3_OVERLOW_CLEAR                  (0x04u)
#define pwm3_OVERLOW_INVERT                 (0x08u)
#define pwm3_OVERLOW_NO_CHANGE              (0x0Cu)
#define pwm3_UNDERFLOW_SET                  (0x00u)
#define pwm3_UNDERFLOW_CLEAR                (0x10u)
#define pwm3_UNDERFLOW_INVERT               (0x20u)
#define pwm3_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define pwm3_PWM_MODE_LEFT                  (pwm3_CC_MATCH_CLEAR        |   \
                                                         pwm3_OVERLOW_SET           |   \
                                                         pwm3_UNDERFLOW_NO_CHANGE)
#define pwm3_PWM_MODE_RIGHT                 (pwm3_CC_MATCH_SET          |   \
                                                         pwm3_OVERLOW_NO_CHANGE     |   \
                                                         pwm3_UNDERFLOW_CLEAR)
#define pwm3_PWM_MODE_ASYM                  (pwm3_CC_MATCH_INVERT       |   \
                                                         pwm3_OVERLOW_SET           |   \
                                                         pwm3_UNDERFLOW_CLEAR)

#if (pwm3_CY_TCPWM_V2)
    #if(pwm3_CY_TCPWM_4000)
        #define pwm3_PWM_MODE_CENTER                (pwm3_CC_MATCH_INVERT       |   \
                                                                 pwm3_OVERLOW_NO_CHANGE     |   \
                                                                 pwm3_UNDERFLOW_CLEAR)
    #else
        #define pwm3_PWM_MODE_CENTER                (pwm3_CC_MATCH_INVERT       |   \
                                                                 pwm3_OVERLOW_SET           |   \
                                                                 pwm3_UNDERFLOW_CLEAR)
    #endif /* (pwm3_CY_TCPWM_4000) */
#else
    #define pwm3_PWM_MODE_CENTER                (pwm3_CC_MATCH_INVERT       |   \
                                                             pwm3_OVERLOW_NO_CHANGE     |   \
                                                             pwm3_UNDERFLOW_CLEAR)
#endif /* (pwm3_CY_TCPWM_NEW) */

/* Command operations without condition */
#define pwm3_CMD_CAPTURE                    (0u)
#define pwm3_CMD_RELOAD                     (8u)
#define pwm3_CMD_STOP                       (16u)
#define pwm3_CMD_START                      (24u)

/* Status */
#define pwm3_STATUS_DOWN                    (1u)
#define pwm3_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   pwm3_Init(void);
void   pwm3_Enable(void);
void   pwm3_Start(void);
void   pwm3_Stop(void);

void   pwm3_SetMode(uint32 mode);
void   pwm3_SetCounterMode(uint32 counterMode);
void   pwm3_SetPWMMode(uint32 modeMask);
void   pwm3_SetQDMode(uint32 qdMode);

void   pwm3_SetPrescaler(uint32 prescaler);
void   pwm3_TriggerCommand(uint32 mask, uint32 command);
void   pwm3_SetOneShot(uint32 oneShotEnable);
uint32 pwm3_ReadStatus(void);

void   pwm3_SetPWMSyncKill(uint32 syncKillEnable);
void   pwm3_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   pwm3_SetPWMDeadTime(uint32 deadTime);
void   pwm3_SetPWMInvert(uint32 mask);

void   pwm3_SetInterruptMode(uint32 interruptMask);
uint32 pwm3_GetInterruptSourceMasked(void);
uint32 pwm3_GetInterruptSource(void);
void   pwm3_ClearInterrupt(uint32 interruptMask);
void   pwm3_SetInterrupt(uint32 interruptMask);

void   pwm3_WriteCounter(uint32 count);
uint32 pwm3_ReadCounter(void);

uint32 pwm3_ReadCapture(void);
uint32 pwm3_ReadCaptureBuf(void);

void   pwm3_WritePeriod(uint32 period);
uint32 pwm3_ReadPeriod(void);
void   pwm3_WritePeriodBuf(uint32 periodBuf);
uint32 pwm3_ReadPeriodBuf(void);

void   pwm3_WriteCompare(uint32 compare);
uint32 pwm3_ReadCompare(void);
void   pwm3_WriteCompareBuf(uint32 compareBuf);
uint32 pwm3_ReadCompareBuf(void);

void   pwm3_SetPeriodSwap(uint32 swapEnable);
void   pwm3_SetCompareSwap(uint32 swapEnable);

void   pwm3_SetCaptureMode(uint32 triggerMode);
void   pwm3_SetReloadMode(uint32 triggerMode);
void   pwm3_SetStartMode(uint32 triggerMode);
void   pwm3_SetStopMode(uint32 triggerMode);
void   pwm3_SetCountMode(uint32 triggerMode);

void   pwm3_SaveConfig(void);
void   pwm3_RestoreConfig(void);
void   pwm3_Sleep(void);
void   pwm3_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define pwm3_BLOCK_CONTROL_REG              (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm3_BLOCK_CONTROL_PTR              ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm3_COMMAND_REG                    (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm3_COMMAND_PTR                    ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm3_INTRRUPT_CAUSE_REG             (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm3_INTRRUPT_CAUSE_PTR             ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm3_CONTROL_REG                    (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__CTRL )
#define pwm3_CONTROL_PTR                    ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__CTRL )
#define pwm3_STATUS_REG                     (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__STATUS )
#define pwm3_STATUS_PTR                     ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__STATUS )
#define pwm3_COUNTER_REG                    (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__COUNTER )
#define pwm3_COUNTER_PTR                    ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__COUNTER )
#define pwm3_COMP_CAP_REG                   (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__CC )
#define pwm3_COMP_CAP_PTR                   ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__CC )
#define pwm3_COMP_CAP_BUF_REG               (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm3_COMP_CAP_BUF_PTR               ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm3_PERIOD_REG                     (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__PERIOD )
#define pwm3_PERIOD_PTR                     ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__PERIOD )
#define pwm3_PERIOD_BUF_REG                 (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm3_PERIOD_BUF_PTR                 ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm3_TRIG_CONTROL0_REG              (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm3_TRIG_CONTROL0_PTR              ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm3_TRIG_CONTROL1_REG              (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm3_TRIG_CONTROL1_PTR              ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm3_TRIG_CONTROL2_REG              (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm3_TRIG_CONTROL2_PTR              ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm3_INTERRUPT_REQ_REG              (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__INTR )
#define pwm3_INTERRUPT_REQ_PTR              ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__INTR )
#define pwm3_INTERRUPT_SET_REG              (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm3_INTERRUPT_SET_PTR              ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm3_INTERRUPT_MASK_REG             (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm3_INTERRUPT_MASK_PTR             ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm3_INTERRUPT_MASKED_REG           (*(reg32 *) pwm3_cy_m0s8_tcpwm_1__INTR_MASKED )
#define pwm3_INTERRUPT_MASKED_PTR           ( (reg32 *) pwm3_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define pwm3_MASK                           ((uint32)pwm3_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define pwm3_RELOAD_CC_SHIFT                (0u)
#define pwm3_RELOAD_PERIOD_SHIFT            (1u)
#define pwm3_PWM_SYNC_KILL_SHIFT            (2u)
#define pwm3_PWM_STOP_KILL_SHIFT            (3u)
#define pwm3_PRESCALER_SHIFT                (8u)
#define pwm3_UPDOWN_SHIFT                   (16u)
#define pwm3_ONESHOT_SHIFT                  (18u)
#define pwm3_QUAD_MODE_SHIFT                (20u)
#define pwm3_INV_OUT_SHIFT                  (20u)
#define pwm3_INV_COMPL_OUT_SHIFT            (21u)
#define pwm3_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define pwm3_RELOAD_CC_MASK                 ((uint32)(pwm3_1BIT_MASK        <<  \
                                                                            pwm3_RELOAD_CC_SHIFT))
#define pwm3_RELOAD_PERIOD_MASK             ((uint32)(pwm3_1BIT_MASK        <<  \
                                                                            pwm3_RELOAD_PERIOD_SHIFT))
#define pwm3_PWM_SYNC_KILL_MASK             ((uint32)(pwm3_1BIT_MASK        <<  \
                                                                            pwm3_PWM_SYNC_KILL_SHIFT))
#define pwm3_PWM_STOP_KILL_MASK             ((uint32)(pwm3_1BIT_MASK        <<  \
                                                                            pwm3_PWM_STOP_KILL_SHIFT))
#define pwm3_PRESCALER_MASK                 ((uint32)(pwm3_8BIT_MASK        <<  \
                                                                            pwm3_PRESCALER_SHIFT))
#define pwm3_UPDOWN_MASK                    ((uint32)(pwm3_2BIT_MASK        <<  \
                                                                            pwm3_UPDOWN_SHIFT))
#define pwm3_ONESHOT_MASK                   ((uint32)(pwm3_1BIT_MASK        <<  \
                                                                            pwm3_ONESHOT_SHIFT))
#define pwm3_QUAD_MODE_MASK                 ((uint32)(pwm3_3BIT_MASK        <<  \
                                                                            pwm3_QUAD_MODE_SHIFT))
#define pwm3_INV_OUT_MASK                   ((uint32)(pwm3_2BIT_MASK        <<  \
                                                                            pwm3_INV_OUT_SHIFT))
#define pwm3_MODE_MASK                      ((uint32)(pwm3_3BIT_MASK        <<  \
                                                                            pwm3_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define pwm3_CAPTURE_SHIFT                  (0u)
#define pwm3_COUNT_SHIFT                    (2u)
#define pwm3_RELOAD_SHIFT                   (4u)
#define pwm3_STOP_SHIFT                     (6u)
#define pwm3_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define pwm3_CAPTURE_MASK                   ((uint32)(pwm3_2BIT_MASK        <<  \
                                                                  pwm3_CAPTURE_SHIFT))
#define pwm3_COUNT_MASK                     ((uint32)(pwm3_2BIT_MASK        <<  \
                                                                  pwm3_COUNT_SHIFT))
#define pwm3_RELOAD_MASK                    ((uint32)(pwm3_2BIT_MASK        <<  \
                                                                  pwm3_RELOAD_SHIFT))
#define pwm3_STOP_MASK                      ((uint32)(pwm3_2BIT_MASK        <<  \
                                                                  pwm3_STOP_SHIFT))
#define pwm3_START_MASK                     ((uint32)(pwm3_2BIT_MASK        <<  \
                                                                  pwm3_START_SHIFT))

/* MASK */
#define pwm3_1BIT_MASK                      ((uint32)0x01u)
#define pwm3_2BIT_MASK                      ((uint32)0x03u)
#define pwm3_3BIT_MASK                      ((uint32)0x07u)
#define pwm3_6BIT_MASK                      ((uint32)0x3Fu)
#define pwm3_8BIT_MASK                      ((uint32)0xFFu)
#define pwm3_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define pwm3_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define pwm3_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(pwm3_QUAD_ENCODING_MODES     << pwm3_QUAD_MODE_SHIFT))       |\
         ((uint32)(pwm3_CONFIG                  << pwm3_MODE_SHIFT)))

#define pwm3_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(pwm3_PWM_STOP_EVENT          << pwm3_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(pwm3_PWM_OUT_INVERT          << pwm3_INV_OUT_SHIFT))         |\
         ((uint32)(pwm3_PWM_OUT_N_INVERT        << pwm3_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(pwm3_PWM_MODE                << pwm3_MODE_SHIFT)))

#define pwm3_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(pwm3_PWM_RUN_MODE         << pwm3_ONESHOT_SHIFT))
            
#define pwm3_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(pwm3_PWM_ALIGN            << pwm3_UPDOWN_SHIFT))

#define pwm3_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(pwm3_PWM_KILL_EVENT      << pwm3_PWM_SYNC_KILL_SHIFT))

#define pwm3_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(pwm3_PWM_DEAD_TIME_CYCLE  << pwm3_PRESCALER_SHIFT))

#define pwm3_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(pwm3_PWM_PRESCALER        << pwm3_PRESCALER_SHIFT))

#define pwm3_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(pwm3_TC_PRESCALER            << pwm3_PRESCALER_SHIFT))       |\
         ((uint32)(pwm3_TC_COUNTER_MODE         << pwm3_UPDOWN_SHIFT))          |\
         ((uint32)(pwm3_TC_RUN_MODE             << pwm3_ONESHOT_SHIFT))         |\
         ((uint32)(pwm3_TC_COMP_CAP_MODE        << pwm3_MODE_SHIFT)))
        
#define pwm3_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(pwm3_QUAD_PHIA_SIGNAL_MODE   << pwm3_COUNT_SHIFT))           |\
         ((uint32)(pwm3_QUAD_INDEX_SIGNAL_MODE  << pwm3_RELOAD_SHIFT))          |\
         ((uint32)(pwm3_QUAD_STOP_SIGNAL_MODE   << pwm3_STOP_SHIFT))            |\
         ((uint32)(pwm3_QUAD_PHIB_SIGNAL_MODE   << pwm3_START_SHIFT)))

#define pwm3_PWM_SIGNALS_MODES                                                              \
        (((uint32)(pwm3_PWM_SWITCH_SIGNAL_MODE  << pwm3_CAPTURE_SHIFT))         |\
         ((uint32)(pwm3_PWM_COUNT_SIGNAL_MODE   << pwm3_COUNT_SHIFT))           |\
         ((uint32)(pwm3_PWM_RELOAD_SIGNAL_MODE  << pwm3_RELOAD_SHIFT))          |\
         ((uint32)(pwm3_PWM_STOP_SIGNAL_MODE    << pwm3_STOP_SHIFT))            |\
         ((uint32)(pwm3_PWM_START_SIGNAL_MODE   << pwm3_START_SHIFT)))

#define pwm3_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(pwm3_TC_CAPTURE_SIGNAL_MODE  << pwm3_CAPTURE_SHIFT))         |\
         ((uint32)(pwm3_TC_COUNT_SIGNAL_MODE    << pwm3_COUNT_SHIFT))           |\
         ((uint32)(pwm3_TC_RELOAD_SIGNAL_MODE   << pwm3_RELOAD_SHIFT))          |\
         ((uint32)(pwm3_TC_STOP_SIGNAL_MODE     << pwm3_STOP_SHIFT))            |\
         ((uint32)(pwm3_TC_START_SIGNAL_MODE    << pwm3_START_SHIFT)))
        
#define pwm3_TIMER_UPDOWN_CNT_USED                                                          \
                ((pwm3__COUNT_UPDOWN0 == pwm3_TC_COUNTER_MODE)                  ||\
                 (pwm3__COUNT_UPDOWN1 == pwm3_TC_COUNTER_MODE))

#define pwm3_PWM_UPDOWN_CNT_USED                                                            \
                ((pwm3__CENTER == pwm3_PWM_ALIGN)                               ||\
                 (pwm3__ASYMMETRIC == pwm3_PWM_ALIGN))               
        
#define pwm3_PWM_PR_INIT_VALUE              (1u)
#define pwm3_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_pwm3_H */

/* [] END OF FILE */
