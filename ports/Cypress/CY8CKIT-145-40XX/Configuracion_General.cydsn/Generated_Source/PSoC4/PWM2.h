/*******************************************************************************
* File Name: pwm2.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the pwm2
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

#if !defined(CY_TCPWM_pwm2_H)
#define CY_TCPWM_pwm2_H


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
} pwm2_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  pwm2_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define pwm2_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define pwm2_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define pwm2_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define pwm2_QUAD_ENCODING_MODES            (0lu)
#define pwm2_QUAD_AUTO_START                (1lu)

/* Signal modes */
#define pwm2_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define pwm2_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define pwm2_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define pwm2_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define pwm2_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define pwm2_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define pwm2_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define pwm2_TC_RUN_MODE                    (0lu)
#define pwm2_TC_COUNTER_MODE                (0lu)
#define pwm2_TC_COMP_CAP_MODE               (2lu)
#define pwm2_TC_PRESCALER                   (0lu)

/* Signal modes */
#define pwm2_TC_RELOAD_SIGNAL_MODE          (0lu)
#define pwm2_TC_COUNT_SIGNAL_MODE           (3lu)
#define pwm2_TC_START_SIGNAL_MODE           (0lu)
#define pwm2_TC_STOP_SIGNAL_MODE            (0lu)
#define pwm2_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm2_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define pwm2_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define pwm2_TC_START_SIGNAL_PRESENT        (0lu)
#define pwm2_TC_STOP_SIGNAL_PRESENT         (0lu)
#define pwm2_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm2_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define pwm2_PWM_KILL_EVENT                 (0lu)
#define pwm2_PWM_STOP_EVENT                 (0lu)
#define pwm2_PWM_MODE                       (4lu)
#define pwm2_PWM_OUT_N_INVERT               (0lu)
#define pwm2_PWM_OUT_INVERT                 (0lu)
#define pwm2_PWM_ALIGN                      (0lu)
#define pwm2_PWM_RUN_MODE                   (0lu)
#define pwm2_PWM_DEAD_TIME_CYCLE            (0lu)
#define pwm2_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define pwm2_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define pwm2_PWM_COUNT_SIGNAL_MODE          (3lu)
#define pwm2_PWM_START_SIGNAL_MODE          (0lu)
#define pwm2_PWM_STOP_SIGNAL_MODE           (0lu)
#define pwm2_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define pwm2_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define pwm2_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define pwm2_PWM_START_SIGNAL_PRESENT       (0lu)
#define pwm2_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define pwm2_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define pwm2_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define pwm2_TC_PERIOD_VALUE                (65535lu)
#define pwm2_TC_COMPARE_VALUE               (65535lu)
#define pwm2_TC_COMPARE_BUF_VALUE           (65535lu)
#define pwm2_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define pwm2_PWM_PERIOD_VALUE               (65535lu)
#define pwm2_PWM_PERIOD_BUF_VALUE           (65535lu)
#define pwm2_PWM_PERIOD_SWAP                (0lu)
#define pwm2_PWM_COMPARE_VALUE              (65535lu)
#define pwm2_PWM_COMPARE_BUF_VALUE          (65535lu)
#define pwm2_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define pwm2__LEFT 0
#define pwm2__RIGHT 1
#define pwm2__CENTER 2
#define pwm2__ASYMMETRIC 3

#define pwm2__X1 0
#define pwm2__X2 1
#define pwm2__X4 2

#define pwm2__PWM 4
#define pwm2__PWM_DT 5
#define pwm2__PWM_PR 6

#define pwm2__INVERSE 1
#define pwm2__DIRECT 0

#define pwm2__CAPTURE 2
#define pwm2__COMPARE 0

#define pwm2__TRIG_LEVEL 3
#define pwm2__TRIG_RISING 0
#define pwm2__TRIG_FALLING 1
#define pwm2__TRIG_BOTH 2

#define pwm2__INTR_MASK_TC 1
#define pwm2__INTR_MASK_CC_MATCH 2
#define pwm2__INTR_MASK_NONE 0
#define pwm2__INTR_MASK_TC_CC 3

#define pwm2__UNCONFIG 8
#define pwm2__TIMER 1
#define pwm2__QUAD 3
#define pwm2__PWM_SEL 7

#define pwm2__COUNT_UP 0
#define pwm2__COUNT_DOWN 1
#define pwm2__COUNT_UPDOWN0 2
#define pwm2__COUNT_UPDOWN1 3


/* Prescaler */
#define pwm2_PRESCALE_DIVBY1                ((uint32)(0u << pwm2_PRESCALER_SHIFT))
#define pwm2_PRESCALE_DIVBY2                ((uint32)(1u << pwm2_PRESCALER_SHIFT))
#define pwm2_PRESCALE_DIVBY4                ((uint32)(2u << pwm2_PRESCALER_SHIFT))
#define pwm2_PRESCALE_DIVBY8                ((uint32)(3u << pwm2_PRESCALER_SHIFT))
#define pwm2_PRESCALE_DIVBY16               ((uint32)(4u << pwm2_PRESCALER_SHIFT))
#define pwm2_PRESCALE_DIVBY32               ((uint32)(5u << pwm2_PRESCALER_SHIFT))
#define pwm2_PRESCALE_DIVBY64               ((uint32)(6u << pwm2_PRESCALER_SHIFT))
#define pwm2_PRESCALE_DIVBY128              ((uint32)(7u << pwm2_PRESCALER_SHIFT))

/* TCPWM set modes */
#define pwm2_MODE_TIMER_COMPARE             ((uint32)(pwm2__COMPARE         <<  \
                                                                  pwm2_MODE_SHIFT))
#define pwm2_MODE_TIMER_CAPTURE             ((uint32)(pwm2__CAPTURE         <<  \
                                                                  pwm2_MODE_SHIFT))
#define pwm2_MODE_QUAD                      ((uint32)(pwm2__QUAD            <<  \
                                                                  pwm2_MODE_SHIFT))
#define pwm2_MODE_PWM                       ((uint32)(pwm2__PWM             <<  \
                                                                  pwm2_MODE_SHIFT))
#define pwm2_MODE_PWM_DT                    ((uint32)(pwm2__PWM_DT          <<  \
                                                                  pwm2_MODE_SHIFT))
#define pwm2_MODE_PWM_PR                    ((uint32)(pwm2__PWM_PR          <<  \
                                                                  pwm2_MODE_SHIFT))

/* Quad Modes */
#define pwm2_MODE_X1                        ((uint32)(pwm2__X1              <<  \
                                                                  pwm2_QUAD_MODE_SHIFT))
#define pwm2_MODE_X2                        ((uint32)(pwm2__X2              <<  \
                                                                  pwm2_QUAD_MODE_SHIFT))
#define pwm2_MODE_X4                        ((uint32)(pwm2__X4              <<  \
                                                                  pwm2_QUAD_MODE_SHIFT))

/* Counter modes */
#define pwm2_COUNT_UP                       ((uint32)(pwm2__COUNT_UP        <<  \
                                                                  pwm2_UPDOWN_SHIFT))
#define pwm2_COUNT_DOWN                     ((uint32)(pwm2__COUNT_DOWN      <<  \
                                                                  pwm2_UPDOWN_SHIFT))
#define pwm2_COUNT_UPDOWN0                  ((uint32)(pwm2__COUNT_UPDOWN0   <<  \
                                                                  pwm2_UPDOWN_SHIFT))
#define pwm2_COUNT_UPDOWN1                  ((uint32)(pwm2__COUNT_UPDOWN1   <<  \
                                                                  pwm2_UPDOWN_SHIFT))

/* PWM output invert */
#define pwm2_INVERT_LINE                    ((uint32)(pwm2__INVERSE         <<  \
                                                                  pwm2_INV_OUT_SHIFT))
#define pwm2_INVERT_LINE_N                  ((uint32)(pwm2__INVERSE         <<  \
                                                                  pwm2_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define pwm2_TRIG_RISING                    ((uint32)pwm2__TRIG_RISING)
#define pwm2_TRIG_FALLING                   ((uint32)pwm2__TRIG_FALLING)
#define pwm2_TRIG_BOTH                      ((uint32)pwm2__TRIG_BOTH)
#define pwm2_TRIG_LEVEL                     ((uint32)pwm2__TRIG_LEVEL)

/* Interrupt mask */
#define pwm2_INTR_MASK_TC                   ((uint32)pwm2__INTR_MASK_TC)
#define pwm2_INTR_MASK_CC_MATCH             ((uint32)pwm2__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define pwm2_CC_MATCH_SET                   (0x00u)
#define pwm2_CC_MATCH_CLEAR                 (0x01u)
#define pwm2_CC_MATCH_INVERT                (0x02u)
#define pwm2_CC_MATCH_NO_CHANGE             (0x03u)
#define pwm2_OVERLOW_SET                    (0x00u)
#define pwm2_OVERLOW_CLEAR                  (0x04u)
#define pwm2_OVERLOW_INVERT                 (0x08u)
#define pwm2_OVERLOW_NO_CHANGE              (0x0Cu)
#define pwm2_UNDERFLOW_SET                  (0x00u)
#define pwm2_UNDERFLOW_CLEAR                (0x10u)
#define pwm2_UNDERFLOW_INVERT               (0x20u)
#define pwm2_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define pwm2_PWM_MODE_LEFT                  (pwm2_CC_MATCH_CLEAR        |   \
                                                         pwm2_OVERLOW_SET           |   \
                                                         pwm2_UNDERFLOW_NO_CHANGE)
#define pwm2_PWM_MODE_RIGHT                 (pwm2_CC_MATCH_SET          |   \
                                                         pwm2_OVERLOW_NO_CHANGE     |   \
                                                         pwm2_UNDERFLOW_CLEAR)
#define pwm2_PWM_MODE_ASYM                  (pwm2_CC_MATCH_INVERT       |   \
                                                         pwm2_OVERLOW_SET           |   \
                                                         pwm2_UNDERFLOW_CLEAR)

#if (pwm2_CY_TCPWM_V2)
    #if(pwm2_CY_TCPWM_4000)
        #define pwm2_PWM_MODE_CENTER                (pwm2_CC_MATCH_INVERT       |   \
                                                                 pwm2_OVERLOW_NO_CHANGE     |   \
                                                                 pwm2_UNDERFLOW_CLEAR)
    #else
        #define pwm2_PWM_MODE_CENTER                (pwm2_CC_MATCH_INVERT       |   \
                                                                 pwm2_OVERLOW_SET           |   \
                                                                 pwm2_UNDERFLOW_CLEAR)
    #endif /* (pwm2_CY_TCPWM_4000) */
#else
    #define pwm2_PWM_MODE_CENTER                (pwm2_CC_MATCH_INVERT       |   \
                                                             pwm2_OVERLOW_NO_CHANGE     |   \
                                                             pwm2_UNDERFLOW_CLEAR)
#endif /* (pwm2_CY_TCPWM_NEW) */

/* Command operations without condition */
#define pwm2_CMD_CAPTURE                    (0u)
#define pwm2_CMD_RELOAD                     (8u)
#define pwm2_CMD_STOP                       (16u)
#define pwm2_CMD_START                      (24u)

/* Status */
#define pwm2_STATUS_DOWN                    (1u)
#define pwm2_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   pwm2_Init(void);
void   pwm2_Enable(void);
void   pwm2_Start(void);
void   pwm2_Stop(void);

void   pwm2_SetMode(uint32 mode);
void   pwm2_SetCounterMode(uint32 counterMode);
void   pwm2_SetPWMMode(uint32 modeMask);
void   pwm2_SetQDMode(uint32 qdMode);

void   pwm2_SetPrescaler(uint32 prescaler);
void   pwm2_TriggerCommand(uint32 mask, uint32 command);
void   pwm2_SetOneShot(uint32 oneShotEnable);
uint32 pwm2_ReadStatus(void);

void   pwm2_SetPWMSyncKill(uint32 syncKillEnable);
void   pwm2_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   pwm2_SetPWMDeadTime(uint32 deadTime);
void   pwm2_SetPWMInvert(uint32 mask);

void   pwm2_SetInterruptMode(uint32 interruptMask);
uint32 pwm2_GetInterruptSourceMasked(void);
uint32 pwm2_GetInterruptSource(void);
void   pwm2_ClearInterrupt(uint32 interruptMask);
void   pwm2_SetInterrupt(uint32 interruptMask);

void   pwm2_WriteCounter(uint32 count);
uint32 pwm2_ReadCounter(void);

uint32 pwm2_ReadCapture(void);
uint32 pwm2_ReadCaptureBuf(void);

void   pwm2_WritePeriod(uint32 period);
uint32 pwm2_ReadPeriod(void);
void   pwm2_WritePeriodBuf(uint32 periodBuf);
uint32 pwm2_ReadPeriodBuf(void);

void   pwm2_WriteCompare(uint32 compare);
uint32 pwm2_ReadCompare(void);
void   pwm2_WriteCompareBuf(uint32 compareBuf);
uint32 pwm2_ReadCompareBuf(void);

void   pwm2_SetPeriodSwap(uint32 swapEnable);
void   pwm2_SetCompareSwap(uint32 swapEnable);

void   pwm2_SetCaptureMode(uint32 triggerMode);
void   pwm2_SetReloadMode(uint32 triggerMode);
void   pwm2_SetStartMode(uint32 triggerMode);
void   pwm2_SetStopMode(uint32 triggerMode);
void   pwm2_SetCountMode(uint32 triggerMode);

void   pwm2_SaveConfig(void);
void   pwm2_RestoreConfig(void);
void   pwm2_Sleep(void);
void   pwm2_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define pwm2_BLOCK_CONTROL_REG              (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm2_BLOCK_CONTROL_PTR              ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define pwm2_COMMAND_REG                    (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm2_COMMAND_PTR                    ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define pwm2_INTRRUPT_CAUSE_REG             (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm2_INTRRUPT_CAUSE_PTR             ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define pwm2_CONTROL_REG                    (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__CTRL )
#define pwm2_CONTROL_PTR                    ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__CTRL )
#define pwm2_STATUS_REG                     (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__STATUS )
#define pwm2_STATUS_PTR                     ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__STATUS )
#define pwm2_COUNTER_REG                    (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__COUNTER )
#define pwm2_COUNTER_PTR                    ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__COUNTER )
#define pwm2_COMP_CAP_REG                   (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__CC )
#define pwm2_COMP_CAP_PTR                   ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__CC )
#define pwm2_COMP_CAP_BUF_REG               (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm2_COMP_CAP_BUF_PTR               ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__CC_BUFF )
#define pwm2_PERIOD_REG                     (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__PERIOD )
#define pwm2_PERIOD_PTR                     ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__PERIOD )
#define pwm2_PERIOD_BUF_REG                 (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm2_PERIOD_BUF_PTR                 ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define pwm2_TRIG_CONTROL0_REG              (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm2_TRIG_CONTROL0_PTR              ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define pwm2_TRIG_CONTROL1_REG              (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm2_TRIG_CONTROL1_PTR              ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define pwm2_TRIG_CONTROL2_REG              (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm2_TRIG_CONTROL2_PTR              ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define pwm2_INTERRUPT_REQ_REG              (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__INTR )
#define pwm2_INTERRUPT_REQ_PTR              ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__INTR )
#define pwm2_INTERRUPT_SET_REG              (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm2_INTERRUPT_SET_PTR              ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__INTR_SET )
#define pwm2_INTERRUPT_MASK_REG             (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm2_INTERRUPT_MASK_PTR             ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__INTR_MASK )
#define pwm2_INTERRUPT_MASKED_REG           (*(reg32 *) pwm2_cy_m0s8_tcpwm_1__INTR_MASKED )
#define pwm2_INTERRUPT_MASKED_PTR           ( (reg32 *) pwm2_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define pwm2_MASK                           ((uint32)pwm2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define pwm2_RELOAD_CC_SHIFT                (0u)
#define pwm2_RELOAD_PERIOD_SHIFT            (1u)
#define pwm2_PWM_SYNC_KILL_SHIFT            (2u)
#define pwm2_PWM_STOP_KILL_SHIFT            (3u)
#define pwm2_PRESCALER_SHIFT                (8u)
#define pwm2_UPDOWN_SHIFT                   (16u)
#define pwm2_ONESHOT_SHIFT                  (18u)
#define pwm2_QUAD_MODE_SHIFT                (20u)
#define pwm2_INV_OUT_SHIFT                  (20u)
#define pwm2_INV_COMPL_OUT_SHIFT            (21u)
#define pwm2_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define pwm2_RELOAD_CC_MASK                 ((uint32)(pwm2_1BIT_MASK        <<  \
                                                                            pwm2_RELOAD_CC_SHIFT))
#define pwm2_RELOAD_PERIOD_MASK             ((uint32)(pwm2_1BIT_MASK        <<  \
                                                                            pwm2_RELOAD_PERIOD_SHIFT))
#define pwm2_PWM_SYNC_KILL_MASK             ((uint32)(pwm2_1BIT_MASK        <<  \
                                                                            pwm2_PWM_SYNC_KILL_SHIFT))
#define pwm2_PWM_STOP_KILL_MASK             ((uint32)(pwm2_1BIT_MASK        <<  \
                                                                            pwm2_PWM_STOP_KILL_SHIFT))
#define pwm2_PRESCALER_MASK                 ((uint32)(pwm2_8BIT_MASK        <<  \
                                                                            pwm2_PRESCALER_SHIFT))
#define pwm2_UPDOWN_MASK                    ((uint32)(pwm2_2BIT_MASK        <<  \
                                                                            pwm2_UPDOWN_SHIFT))
#define pwm2_ONESHOT_MASK                   ((uint32)(pwm2_1BIT_MASK        <<  \
                                                                            pwm2_ONESHOT_SHIFT))
#define pwm2_QUAD_MODE_MASK                 ((uint32)(pwm2_3BIT_MASK        <<  \
                                                                            pwm2_QUAD_MODE_SHIFT))
#define pwm2_INV_OUT_MASK                   ((uint32)(pwm2_2BIT_MASK        <<  \
                                                                            pwm2_INV_OUT_SHIFT))
#define pwm2_MODE_MASK                      ((uint32)(pwm2_3BIT_MASK        <<  \
                                                                            pwm2_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define pwm2_CAPTURE_SHIFT                  (0u)
#define pwm2_COUNT_SHIFT                    (2u)
#define pwm2_RELOAD_SHIFT                   (4u)
#define pwm2_STOP_SHIFT                     (6u)
#define pwm2_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define pwm2_CAPTURE_MASK                   ((uint32)(pwm2_2BIT_MASK        <<  \
                                                                  pwm2_CAPTURE_SHIFT))
#define pwm2_COUNT_MASK                     ((uint32)(pwm2_2BIT_MASK        <<  \
                                                                  pwm2_COUNT_SHIFT))
#define pwm2_RELOAD_MASK                    ((uint32)(pwm2_2BIT_MASK        <<  \
                                                                  pwm2_RELOAD_SHIFT))
#define pwm2_STOP_MASK                      ((uint32)(pwm2_2BIT_MASK        <<  \
                                                                  pwm2_STOP_SHIFT))
#define pwm2_START_MASK                     ((uint32)(pwm2_2BIT_MASK        <<  \
                                                                  pwm2_START_SHIFT))

/* MASK */
#define pwm2_1BIT_MASK                      ((uint32)0x01u)
#define pwm2_2BIT_MASK                      ((uint32)0x03u)
#define pwm2_3BIT_MASK                      ((uint32)0x07u)
#define pwm2_6BIT_MASK                      ((uint32)0x3Fu)
#define pwm2_8BIT_MASK                      ((uint32)0xFFu)
#define pwm2_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define pwm2_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define pwm2_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(pwm2_QUAD_ENCODING_MODES     << pwm2_QUAD_MODE_SHIFT))       |\
         ((uint32)(pwm2_CONFIG                  << pwm2_MODE_SHIFT)))

#define pwm2_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(pwm2_PWM_STOP_EVENT          << pwm2_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(pwm2_PWM_OUT_INVERT          << pwm2_INV_OUT_SHIFT))         |\
         ((uint32)(pwm2_PWM_OUT_N_INVERT        << pwm2_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(pwm2_PWM_MODE                << pwm2_MODE_SHIFT)))

#define pwm2_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(pwm2_PWM_RUN_MODE         << pwm2_ONESHOT_SHIFT))
            
#define pwm2_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(pwm2_PWM_ALIGN            << pwm2_UPDOWN_SHIFT))

#define pwm2_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(pwm2_PWM_KILL_EVENT      << pwm2_PWM_SYNC_KILL_SHIFT))

#define pwm2_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(pwm2_PWM_DEAD_TIME_CYCLE  << pwm2_PRESCALER_SHIFT))

#define pwm2_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(pwm2_PWM_PRESCALER        << pwm2_PRESCALER_SHIFT))

#define pwm2_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(pwm2_TC_PRESCALER            << pwm2_PRESCALER_SHIFT))       |\
         ((uint32)(pwm2_TC_COUNTER_MODE         << pwm2_UPDOWN_SHIFT))          |\
         ((uint32)(pwm2_TC_RUN_MODE             << pwm2_ONESHOT_SHIFT))         |\
         ((uint32)(pwm2_TC_COMP_CAP_MODE        << pwm2_MODE_SHIFT)))
        
#define pwm2_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(pwm2_QUAD_PHIA_SIGNAL_MODE   << pwm2_COUNT_SHIFT))           |\
         ((uint32)(pwm2_QUAD_INDEX_SIGNAL_MODE  << pwm2_RELOAD_SHIFT))          |\
         ((uint32)(pwm2_QUAD_STOP_SIGNAL_MODE   << pwm2_STOP_SHIFT))            |\
         ((uint32)(pwm2_QUAD_PHIB_SIGNAL_MODE   << pwm2_START_SHIFT)))

#define pwm2_PWM_SIGNALS_MODES                                                              \
        (((uint32)(pwm2_PWM_SWITCH_SIGNAL_MODE  << pwm2_CAPTURE_SHIFT))         |\
         ((uint32)(pwm2_PWM_COUNT_SIGNAL_MODE   << pwm2_COUNT_SHIFT))           |\
         ((uint32)(pwm2_PWM_RELOAD_SIGNAL_MODE  << pwm2_RELOAD_SHIFT))          |\
         ((uint32)(pwm2_PWM_STOP_SIGNAL_MODE    << pwm2_STOP_SHIFT))            |\
         ((uint32)(pwm2_PWM_START_SIGNAL_MODE   << pwm2_START_SHIFT)))

#define pwm2_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(pwm2_TC_CAPTURE_SIGNAL_MODE  << pwm2_CAPTURE_SHIFT))         |\
         ((uint32)(pwm2_TC_COUNT_SIGNAL_MODE    << pwm2_COUNT_SHIFT))           |\
         ((uint32)(pwm2_TC_RELOAD_SIGNAL_MODE   << pwm2_RELOAD_SHIFT))          |\
         ((uint32)(pwm2_TC_STOP_SIGNAL_MODE     << pwm2_STOP_SHIFT))            |\
         ((uint32)(pwm2_TC_START_SIGNAL_MODE    << pwm2_START_SHIFT)))
        
#define pwm2_TIMER_UPDOWN_CNT_USED                                                          \
                ((pwm2__COUNT_UPDOWN0 == pwm2_TC_COUNTER_MODE)                  ||\
                 (pwm2__COUNT_UPDOWN1 == pwm2_TC_COUNTER_MODE))

#define pwm2_PWM_UPDOWN_CNT_USED                                                            \
                ((pwm2__CENTER == pwm2_PWM_ALIGN)                               ||\
                 (pwm2__ASYMMETRIC == pwm2_PWM_ALIGN))               
        
#define pwm2_PWM_PR_INIT_VALUE              (1u)
#define pwm2_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_pwm2_H */

/* [] END OF FILE */
