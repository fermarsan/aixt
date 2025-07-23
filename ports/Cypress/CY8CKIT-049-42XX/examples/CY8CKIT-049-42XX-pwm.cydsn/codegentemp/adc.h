/*******************************************************************************
* File Name: adc.h
* Version 2.50
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Sequencing Successive Approximation ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ADC_SAR_SEQ_adc_H)
#define CY_ADC_SAR_SEQ_adc_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint32 dftRegVal;
} adc_BACKUP_STRUCT;


/**************************************
*    Enumerated Types and Parameters
**************************************/

/*  Clock Source setting constants */
#define adc__EXTERNAL 0
#define adc__INTERNAL 1

/*  Sample Mode setting constants */
#define adc__FREERUNNING 0
#define adc__HARDWARESOC 1

/*  Reference type setting constants */
#define adc__VDDA_2 0
#define adc__VDDA 1
#define adc__INTERNAL1024 2
#define adc__INTERNAL1024BYPASSED 3
#define adc__INTERNALVREF 4
#define adc__INTERNALVREFBYPASSED 5
#define adc__VDDA_2BYPASSED 6
#define adc__EXTERNALVREF 7

/* Input buffer gain setting constants */
#define adc__DISABLED 0
#define adc__ONE 1
#define adc__TWO 2
#define adc__FOUR 3
#define adc__EIGHT 4
#define adc__SIXTEEN 5

/* Negative input setting sonstants in single ended mode */
#define adc__VSS 0
#define adc__VREF 1
#define adc__OTHER 2

/* Compare mode setting constants:
*    Mode0 - Disable
*    Mode1 - Result < Low_Limit
*    Mode2 - Low_Limit <= Result < High_Limit
*    Mode3 - High_Limit <= Result
*    Mode4 - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define adc__MODE0 0
#define adc__MODE1 1
#define adc__MODE2 2
#define adc__MODE3 3

#define adc__RES8 0
#define adc__RES10 1

#define adc__RIGHT 0
#define adc__LEFT 1

#define adc__FSIGNED 1
#define adc__FUNSIGNED 0

#define adc__ACCUMULATE 0
#define adc__FIXEDRESOLUTION 1



/***************************************
*   Conditional Compilation Parameters
****************************************/ 

#define adc_CY_SAR_IP_VER0               	(0u)
#define adc_CY_SAR_IP_VER1               	(1u)

#if (CY_PSOC4_4100 || CY_PSOC4_4200)
    #define adc_CY_SAR_IP_VER              (adc_CY_SAR_IP_VER0)
#else /* Other devices */
    #define adc_CY_SAR_IP_VER              (adc_CY_SAR_IP_VER1)
#endif  /* (CY_PSOC4_4100 || CY_PSOC4_4200) */


/***************************************
*    Initial Parameter Constants
***************************************/
#define adc_DEFAULT_SAMPLE_MODE_SEL        (0u)
#define adc_DEFAULT_VREF_SEL               (1u)
#define adc_DEFAULT_NEG_INPUT_SEL          (0u)
#define adc_DEFAULT_ALT_RESOLUTION_SEL     (1u)
#define adc_DEFAULT_JUSTIFICATION_SEL      (0u)
#define adc_DEFAULT_DIFF_RESULT_FORMAT_SEL (0u)
#define adc_DEFAULT_SE_RESULT_FORMAT_SEL   (1u)
#define adc_DEFAULT_CLOCK_SOURCE           (1u)
#define adc_DEFAULT_VREF_MV_VALUE          (5000)
#define adc_DEFAULT_BUFFER_GAIN            (0u)
#define adc_DEFAULT_AVG_SAMPLES_NUM        (0u)
#define adc_DEFAULT_AVG_SAMPLES_DIV        (0u < 4u) ? (int16)(0x100u >> (7u - 0u)) : (int16)(0x100u >> 4u)
#define adc_DEFAULT_AVG_MODE               (1u)
#define adc_MAX_RESOLUTION                 (12u)
#define adc_DEFAULT_LOW_LIMIT              (0u)
#define adc_DEFAULT_HIGH_LIMIT             (2047u)
#define adc_DEFAULT_COMPARE_MODE           (0u)
#define adc_DEFAULT_ACLKS_NUM              (4u)
#define adc_DEFAULT_BCLKS_NUM              (4u)
#define adc_DEFAULT_CCLKS_NUM              (4u)
#define adc_DEFAULT_DCLKS_NUM              (4u)
#define adc_TOTAL_CHANNELS_NUM             (1u)
#define adc_SEQUENCED_CHANNELS_NUM         (1u)
#define adc_DEFAULT_EN_CHANNELS            (1u)
#define adc_NOMINAL_CLOCK_FREQ             (3000000)
#define adc_INJ_CHANNEL_ENABLED            (0u)
#define adc_IRQ_REMOVE                     (0u)

/* Determines whether the configuration contains external negative input. */
#define adc_SINGLE_PRESENT                 (0u)
#define adc_CHANNELS_MODE                  (0u)
#define adc_MAX_CHANNELS_EN_MASK           (0xffffu >> (16u - adc_SEQUENCED_CHANNELS_NUM))


/***************************************
*        Function Prototypes
***************************************/

void adc_Start(void);
void adc_Stop(void);
void adc_Init(void);
void adc_Enable(void);
void adc_StartConvert(void);
void adc_StopConvert(void);
uint32 adc_IsEndConversion(uint32 retMode);
int16 adc_GetResult16(uint32 chan);
void adc_SetChanMask(uint32 mask);
void adc_SetLowLimit(uint32 lowLimit);
void adc_SetHighLimit(uint32 highLimit);
void adc_SetLimitMask(uint32 mask);
void adc_SetSatMask(uint32 mask);
void adc_SetOffset(uint32 chan, int16 offset);
void adc_SetGain(uint32 chan, int32 adcGain);
#if(adc_INJ_CHANNEL_ENABLED)
    void adc_EnableInjection(void);
#endif /* adc_INJ_CHANNEL_ENABLED */
#if(adc_DEFAULT_JUSTIFICATION_SEL == adc__RIGHT)
    int16 adc_CountsTo_mVolts(uint32 chan, int16 adcCounts);
    int32 adc_CountsTo_uVolts(uint32 chan, int16 adcCounts);
    float32 adc_CountsTo_Volts(uint32 chan, int16 adcCounts);
#endif /* End adc_DEFAULT_JUSTIFICATION_SEL == adc__RIGHT */
void adc_Sleep(void);
void adc_Wakeup(void);
void adc_SaveConfig(void);
void adc_RestoreConfig(void);

CY_ISR_PROTO( adc_ISR );


/**************************************
*           API Constants
**************************************/
/* Constants for Sleep mode states */
#define adc_DISABLED                   (0x00u)
#define adc_ENABLED                    (0x01u)
#define adc_STARTED                    (0x02u)
#define adc_BOOSTPUMP_ENABLED          (0x04u)

/*   Constants for IsEndConversion() "retMode" parameter  */
#define adc_RETURN_STATUS              (0x01u)
#define adc_WAIT_FOR_RESULT            (0x02u)
#define adc_RETURN_STATUS_INJ          (0x04u)
#define adc_WAIT_FOR_RESULT_INJ        (0x08u)

#define adc_MAX_FREQUENCY              (18000000)       /*18Mhz*/

#define adc_RESOLUTION_12              (12u)
#define adc_RESOLUTION_10              (10u)
#define adc_RESOLUTION_8               (8u)

#define adc_10US_DELAY                 (10u)

#define adc_10V_COUNTS                 (10.0F)
#define adc_10MV_COUNTS                (10000)
#define adc_10UV_COUNTS                (10000000L)


/***************************************
* Global variables external identifier
***************************************/

extern uint8 adc_initVar;
extern volatile int16 adc_offset[adc_TOTAL_CHANNELS_NUM];
extern volatile int32 adc_countsPer10Volt[adc_TOTAL_CHANNELS_NUM];


/***************************************
*              Registers
***************************************/

#define adc_SAR_CTRL_REG                (*(reg32 *) adc_cy_psoc4_sar__SAR_CTRL )
#define adc_SAR_CTRL_PTR                ( (reg32 *) adc_cy_psoc4_sar__SAR_CTRL )

#define adc_SAR_SAMPLE_CTRL_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_SAMPLE_CTRL )
#define adc_SAR_SAMPLE_CTRL_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_SAMPLE_CTRL )

#define adc_SAR_SAMPLE_TIME01_REG       (*(reg32 *) adc_cy_psoc4_sar__SAR_SAMPLE_TIME01 )
#define adc_SAR_SAMPLE_TIME01_PTR       ( (reg32 *) adc_cy_psoc4_sar__SAR_SAMPLE_TIME01 )

#define adc_SAR_SAMPLE_TIME23_REG       (*(reg32 *) adc_cy_psoc4_sar__SAR_SAMPLE_TIME23 )
#define adc_SAR_SAMPLE_TIME23_PTR       ( (reg32 *) adc_cy_psoc4_sar__SAR_SAMPLE_TIME23 )

#define adc_SAR_RANGE_THRES_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_RANGE_THRES )
#define adc_SAR_RANGE_THRES_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_RANGE_THRES )

#define adc_SAR_RANGE_COND_REG          (*(reg32 *) adc_cy_psoc4_sar__SAR_RANGE_COND )
#define adc_SAR_RANGE_COND_PTR          ( (reg32 *) adc_cy_psoc4_sar__SAR_RANGE_COND )

#define adc_SAR_CHAN_EN_REG             (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_EN )
#define adc_SAR_CHAN_EN_PTR             ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_EN )

#define adc_SAR_START_CTRL_REG          (*(reg32 *) adc_cy_psoc4_sar__SAR_START_CTRL )
#define adc_SAR_START_CTRL_PTR          ( (reg32 *) adc_cy_psoc4_sar__SAR_START_CTRL )

#define adc_SAR_DFT_CTRL_REG            (*(reg32 *) adc_cy_psoc4_sar__SAR_DFT_CTRL )
#define adc_SAR_DFT_CTRL_PTR            ( (reg32 *) adc_cy_psoc4_sar__SAR_DFT_CTRL )

#define adc_SAR_CHAN_CONFIG_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define adc_SAR_CHAN_CONFIG_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define adc_SAR_CHAN_CONFIG_IND         adc_cy_psoc4_sar__SAR_CHAN_CONFIG00

#define adc_SAR_CHAN_WORK_REG           (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_WORK00 )
#define adc_SAR_CHAN_WORK_PTR           ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_WORK00 )

#define adc_SAR_CHAN_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adc_SAR_CHAN_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adc_SAR_CHAN_RESULT_IND         adc_cy_psoc4_sar__SAR_CHAN_RESULT00

#define adc_SAR_CHAN0_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define adc_SAR_CHAN0_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT00 )

#define adc_SAR_CHAN1_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT01 )
#define adc_SAR_CHAN1_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT01 )

#define adc_SAR_CHAN2_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT02 )
#define adc_SAR_CHAN2_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT02 )

#define adc_SAR_CHAN3_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT03 )
#define adc_SAR_CHAN3_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT03 )

#define adc_SAR_CHAN4_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT04 )
#define adc_SAR_CHAN4_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT04 )

#define adc_SAR_CHAN5_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT05 )
#define adc_SAR_CHAN5_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT05 )

#define adc_SAR_CHAN6_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT06 )
#define adc_SAR_CHAN6_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT06 )

#define adc_SAR_CHAN7_RESULT_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT07 )
#define adc_SAR_CHAN7_RESULT_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT07 )

#if(adc_CY_SAR_IP_VER != adc_CY_SAR_IP_VER0)
    #define adc_SAR_CHAN8_RESULT_REG     (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT08 )
    #define adc_SAR_CHAN8_RESULT_PTR     ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT08 )

    #define adc_SAR_CHAN9_RESULT_REG     (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT09 )
    #define adc_SAR_CHAN9_RESULT_PTR     ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT09 )

    #define adc_SAR_CHAN10_RESULT_REG    (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT10 )
    #define adc_SAR_CHAN10_RESULT_PTR    ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT10 )

    #define adc_SAR_CHAN11_RESULT_REG    (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT11 )
    #define adc_SAR_CHAN11_RESULT_PTR    ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT11 )

    #define adc_SAR_CHAN12_RESULT_REG    (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT12 )
    #define adc_SAR_CHAN12_RESULT_PTR    ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT12 )

    #define adc_SAR_CHAN13_RESULT_REG    (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT13 )
    #define adc_SAR_CHAN13_RESULT_PTR    ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT13 )

    #define adc_SAR_CHAN14_RESULT_REG    (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT14 )
    #define adc_SAR_CHAN14_RESULT_PTR    ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT14 )

    #define adc_SAR_CHAN15_RESULT_REG    (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT15 )
    #define adc_SAR_CHAN15_RESULT_PTR    ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT15 )
#endif /* (adc_CY_SAR_IP_VER != adc_CY_SAR_IP_VER0) */

#define adc_SAR_CHAN_WORK_VALID_REG     (*(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_WORK_VALID)
#define adc_SAR_CHAN_WORK_VALID_PTR     ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_WORK_VALID)

#define adc_SAR_CHAN_RESULT_VALID_REG  ( *(reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )
#define adc_SAR_CHAN_RESULT_VALID_PTR  ( (reg32 *) adc_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )

#define adc_SAR_STATUS_REG              (*(reg32 *) adc_cy_psoc4_sar__SAR_STATUS )
#define adc_SAR_STATUS_PTR              ( (reg32 *) adc_cy_psoc4_sar__SAR_STATUS )

#define adc_SAR_AVG_START_REG           (*(reg32 *) adc_cy_psoc4_sar__SAR_AVG_STAT )
#define adc_SAR_AVG_START_PTR           ( (reg32 *) adc_cy_psoc4_sar__SAR_AVG_STAT )

#define adc_SAR_INTR_REG                (*(reg32 *) adc_cy_psoc4_sar__SAR_INTR )
#define adc_SAR_INTR_PTR                ( (reg32 *) adc_cy_psoc4_sar__SAR_INTR )

#define adc_SAR_INTR_SET_REG            (*(reg32 *) adc_cy_psoc4_sar__SAR_INTR_SET )
#define adc_SAR_INTR_SET_PTR            ( (reg32 *) adc_cy_psoc4_sar__SAR_INTR_SET )

#define adc_SAR_INTR_MASK_REG           (*(reg32 *) adc_cy_psoc4_sar__SAR_INTR_MASK )
#define adc_SAR_INTR_MASK_PTR           ( (reg32 *) adc_cy_psoc4_sar__SAR_INTR_MASK )

#define adc_SAR_INTR_MASKED_REG         (*(reg32 *) adc_cy_psoc4_sar__SAR_INTR_MASKED )
#define adc_SAR_INTR_MASKED_PTR         ( (reg32 *) adc_cy_psoc4_sar__SAR_INTR_MASKED )

#define adc_SAR_SATURATE_INTR_REG       (*(reg32 *) adc_cy_psoc4_sar__SAR_SATURATE_INTR )
#define adc_SAR_SATURATE_INTR_PTR       ( (reg32 *) adc_cy_psoc4_sar__SAR_SATURATE_INTR )

#define adc_SAR_SATURATE_INTR_SET_REG   (*(reg32 *) adc_cy_psoc4_sar__SAR_SATURATE_INTR_SET )
#define adc_SAR_SATURATE_INTR_SET_PTR   ( (reg32 *) adc_cy_psoc4_sar__SAR_SATURATE_INTR_SET )

#define adc_SAR_SATURATE_INTR_MASK_REG (*(reg32 *) adc_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )
#define adc_SAR_SATURATE_INTR_MASK_PTR ( (reg32 *) adc_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )

#define adc_SAR_SATURATE_INTR_MASKED_REG \
                                                 (*(reg32 *) adc_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )
#define adc_SAR_SATURATE_INTR_MASKED_PTR \
                                                 ( (reg32 *) adc_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )

#define adc_SAR_RANGE_INTR_REG          (*(reg32 *) adc_cy_psoc4_sar__SAR_RANGE_INTR )
#define adc_SAR_RANGE_INTR_PTR          ( (reg32 *) adc_cy_psoc4_sar__SAR_RANGE_INTR )

#define adc_SAR_RANGE_INTR_SET_REG      (*(reg32 *) adc_cy_psoc4_sar__SAR_RANGE_INTR_SET )
#define adc_SAR_RANGE_INTR_SET_PTR      ( (reg32 *) adc_cy_psoc4_sar__SAR_RANGE_INTR_SET )

#define adc_SAR_RANGE_INTR_MASK_REG     (*(reg32 *) adc_cy_psoc4_sar__SAR_RANGE_INTR_MASK )
#define adc_SAR_RANGE_INTR_MASK_PTR     ( (reg32 *) adc_cy_psoc4_sar__SAR_RANGE_INTR_MASK )

#define adc_SAR_RANGE_INTR_MASKED_REG   (*(reg32 *) adc_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )
#define adc_SAR_RANGE_INTR_MASKED_PTR   ( (reg32 *) adc_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )

#define adc_SAR_INTR_CAUSE_REG          (*(reg32 *) adc_cy_psoc4_sar__SAR_INTR_CAUSE )
#define adc_SAR_INTR_CAUSE_PTR          ( (reg32 *) adc_cy_psoc4_sar__SAR_INTR_CAUSE )

#if(adc_INJ_CHANNEL_ENABLED)
    #define adc_SAR_INJ_CHAN_CONFIG_REG \
                                                 (*(reg32 *) adc_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )
    #define adc_SAR_INJ_CHAN_CONFIG_PTR    \
                                                 ( (reg32 *) adc_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )

    #define adc_SAR_INJ_RESULT_REG    (*(reg32 *) adc_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
    #define adc_SAR_INJ_RESULT_PTR    ( (reg32 *) adc_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
#endif /* adc_INJ_CHANNEL_ENABLED */
    
#define adc_MUX_SWITCH0_REG           (*(reg32 *)  adc_cy_psoc4_sar__SAR_MUX_SWITCH0 )
#define adc_MUX_SWITCH0_PTR           ( (reg32 *)  adc_cy_psoc4_sar__SAR_MUX_SWITCH0 )

#define adc_MUX_SWITCH_HW_CTRL_REG    (*(reg32 *)  adc_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )
#define adc_MUX_SWITCH_HW_CTRL_PTR    ( (reg32 *)  adc_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )

#define adc_PUMP_CTRL_REG             (*(reg32 *)  adc_cy_psoc4_sar__SAR_PUMP_CTRL )
#define adc_PUMP_CTRL_PTR             ( (reg32 *)  adc_cy_psoc4_sar__SAR_PUMP_CTRL )

#define adc_ANA_TRIM_REG              (*(reg32 *)  adc_cy_psoc4_sar__SAR_ANA_TRIM )
#define adc_ANA_TRIM_PTR              ( (reg32 *)  adc_cy_psoc4_sar__SAR_ANA_TRIM )

#define adc_WOUNDING_REG              (*(reg32 *)  adc_cy_psoc4_sar__SAR_WOUNDING )
#define adc_WOUNDING_PTR              ( (reg32 *)  adc_cy_psoc4_sar__SAR_WOUNDING )


/**************************************
*       Register Constants
**************************************/
#define adc_INTC_NUMBER                (adc_IRQ__INTC_NUMBER)
#define adc_INTC_PRIOR_NUMBER          (adc_IRQ__INTC_PRIOR_NUM)

/* defines for CTRL register */
#define adc_VREF_INTERNAL1024          (0x00000040Lu)
#define adc_VREF_EXTERNAL              (0x00000050Lu)
#define adc_VREF_VDDA_2                (0x00000060Lu)
#define adc_VREF_VDDA                  (0x00000070Lu)
#define adc_VREF_INTERNAL1024BYPASSED  (0x000000C0Lu)
#define adc_VREF_VDDA_2BYPASSED        (0x000000E0Lu)
#define adc_VREF_INTERNALVREF          (0x00000040Lu)
#define adc_VREF_INTERNALVREFBYPASSED  (0x000000C0Lu)

#define adc_NEG_VSSA_KELVIN            (0x00000000Lu)
#define adc_NEG_VSSA                   (0x00000200Lu)
#define adc_NEG_VREF                   (0x00000E00Lu)
#if(adc_TOTAL_CHANNELS_NUM > 1u)
    #define adc_NEG_OTHER              (uint16)((uint16)adc_cy_psoc4_sarmux_8__VNEG0 << 9u)
#else
    #define adc_NEG_OTHER              (0)
#endif /* adc_TOTAL_CHANNELS_NUM > 1u */

#define adc_SAR_HW_CTRL_NEGVREF        (0x00002000Lu)

#define adc_BOOSTPUMP_EN               (0x00100000Lu)

#define adc_NORMAL_PWR                 (0x00000000Lu)
#define adc_HALF_PWR                   (0x01000000Lu)
#define adc_MORE_PWR                   (0x02000000Lu)
#define adc_QUARTER_PWR                (0x03000000Lu)
#define adc_DEEPSLEEP_ON               (0x08000000Lu)

#define adc_DSI_SYNC_CONFIG            (0x10000000Lu)
#define adc_DSI_MODE                   (0x20000000Lu)
#define adc_SWITCH_DISABLE             (0x40000000Lu)
#define adc_ENABLE                     (0x80000000Lu)

/* defines for STATUS register */
#define adc_STATUS_BUSY                (0x80000000Lu)

/* defines for SAMPLE_CTRL register */
#define adc_ALT_RESOLUTION_10BIT       (0x00000001Lu)
#define adc_ALT_RESOLUTION_8BIT        (0x00000000Lu)

#define adc_DATA_ALIGN_LEFT            (0x00000002Lu)
#define adc_DATA_ALIGN_RIGHT           (0x00000000Lu)

#define adc_SE_SIGNED_RESULT           (0x00000004Lu)
#define adc_SE_UNSIGNED_RESULT         (0x00000000Lu)

#define adc_DIFF_SIGNED_RESULT         (0x00000008Lu)
#define adc_DIFF_UNSIGNED_RESULT       (0x00000000Lu)

#define adc_AVG_CNT_OFFSET             (4u)
#define adc_AVG_CNT_MASK               (0x00000070Lu)
#define adc_AVG_SHIFT                  (0x00000080Lu)

#define adc_CONTINUOUS_EN              (0x00010000Lu)
#define adc_DSI_TRIGGER_EN             (0x00020000Lu)
#define adc_DSI_TRIGGER_LEVEL          (0x00040000Lu)
#define adc_DSI_SYNC_TRIGGER           (0x00080000Lu)
#define adc_EOS_DSI_OUT_EN             (0x80000000Lu)

/* defines for SAMPLE_TIME01 / SAMPLE_TIME23 registers */
#define adc_SAMPLE_TIME13_OFFSET       (16u)
#define adc_SAMPLE_TIME02_MASK         (0x000003FFLu)
#define adc_SAMPLE_TIME13_MASK         (0x03FF0000Lu)

/* defines for RANGE_THRES registers */
#define adc_RANGE_HIGH_OFFSET          (16u)
#define adc_RANGE_HIGH_MASK            (0xFFFF0000Lu)
#define adc_RANGE_LOW_MASK             (0x0000FFFFLu)

/* defines for RANGE_COND register */
/* Compare mode setting constants:
*    BELOW   - Result < Low_Limit
*    INSIDE  - Low_Limit <= Result < High_Limit
*    ABOVE   - High_Limit <= Result
*    OUTSIDE - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define adc_CMP_MODE_BELOW             (0x00000000Lu)
#define adc_CMP_MODE_INSIDE            (0x40000000Lu)
#define adc_CMP_MODE_ABOVE             (0x80000000Lu)
#define adc_CMP_MODE_OUTSIDE           (0xC0000000Lu)
#define adc_CMP_OFFSET                 (30u)

/* defines for _START_CTRL register */
#define adc_FW_TRIGGER                 (0x00000001Lu)

/* defines for DFT_CTRL register */
#define adc_DLY_INC                    (0x00000001Lu)
#define adc_HIZ                        (0x00000002Lu)
#define adc_DFT_INC_MASK               (0x000F0000Lu)
#define adc_DFT_OUTC_MASK              (0x00700000Lu)
#define adc_SEL_CSEL_DFT_MASK          (0x0F000000Lu)

/* configuration for clock speed > 9 Mhz based on
* characterization results
*/
#define adc_SEL_CSEL_DFT_CHAR          (0x03000000Lu)
#define adc_EN_CSEL_DFT                (0x10000000Lu)
#define adc_DCEN                       (0x20000000Lu)
#define adc_ADFT_OVERRIDE              (0x80000000Lu)

/* defines for CHAN_CONFIG / DIE_CHAN_CONFIG register
*  and channelsConfig parameter
*/
#define adc_SARMUX_VIRT_SELECT         (0x00000070Lu)
#define adc_DIFFERENTIAL_EN            (0x00000100Lu)
#define adc_ALT_RESOLUTION_ON          (0x00000200Lu)
#define adc_AVERAGING_EN               (0x00000400Lu)

#define adc_SAMPLE_TIME_SEL_SHIFT      (12u)
#define adc_SAMPLE_TIME_SEL_MASK       (0x00003000Lu)

#define adc_CHANNEL_CONFIG_MASK        (0x00003700Lu)

/* for CHAN_CONFIG only */
#define adc_DSI_OUT_EN                 (0x80000000Lu)

/* for INJ_CHAN_CONFIG only */
#define adc_INJ_TAILGATING             (0x40000000Lu)
#define adc_INJ_CHAN_EN                (0x80000000Lu)

/* defines for CHAN_WORK register */
#define adc_SAR_WRK_MAX_12BIT          (0x00001000Lu)
#define adc_SAR_WRK_MAX_10BIT          (0x00000400Lu)
#define adc_SAR_WRK_MAX_8BIT           (0x00000100Lu)

/* defines for CHAN_RESULT register */
#define adc_RESULT_MASK                (0x0000FFFFLu)
#define adc_SATURATE_INTR_MIR          (0x20000000Lu)
#define adc_RANGE_INTR_MIR             (0x40000000Lu)
#define adc_CHAN_RESULT_VALID_MIR      (0x80000000Lu)

/* defines for INTR_MASK register */
#define adc_EOS_MASK                   (0x00000001Lu)
#define adc_OVERFLOW_MASK              (0x00000002Lu)
#define adc_FW_COLLISION_MASK          (0x00000004Lu)
#define adc_DSI_COLLISION_MASK         (0x00000008Lu)
#define adc_INJ_EOC_MASK               (0x00000010Lu)
#define adc_INJ_SATURATE_MASK          (0x00000020Lu)
#define adc_INJ_RANGE_MASK             (0x00000040Lu)
#define adc_INJ_COLLISION_MASK         (0x00000080Lu)

/* defines for INJ_RESULT register */
#define adc_INJ_COLLISION_INTR_MIR     (0x10000000Lu)
#define adc_INJ_SATURATE_INTR_MIR      (0x20000000Lu)
#define adc_INJ_RANGE_INTR_MIR         (0x40000000Lu)
#define adc_INJ_EOC_INTR_MIR           (0x80000000Lu)

/* defines for MUX_SWITCH0 register */
#define adc_MUX_FW_VSSA_VMINUS         (0x00010000Lu)

/* defines for PUMP_CTRL register */
#define adc_PUMP_CTRL_ENABLED          (0x80000000Lu)

/* additional defines for channelsConfig parameter */
#define adc_IS_SATURATE_EN_MASK        (0x00000001Lu)
#define adc_IS_RANGE_CTRL_EN_MASK      (0x00000002Lu)

/* defines for WOUNDING register */
#define adc_WOUNDING_12BIT             (0x00000000Lu)
#define adc_WOUNDING_10BIT             (0x00000001Lu)
#define adc_WOUNDING_8BIT              (0x00000002Lu)

/* Trim value based on characterization */
#define adc_TRIM_COEF                  (2u)

#if(adc_MAX_RESOLUTION == adc_RESOLUTION_10)
    #define adc_ALT_WOUNDING           adc_WOUNDING_10BIT
#else
    #define adc_ALT_WOUNDING           adc_WOUNDING_8BIT
#endif /* adc_MAX_RESOLUTION == adc_RESOLUTION_10 */

#if(adc_DEFAULT_VREF_SEL == adc__VDDA_2)
    #define adc_DEFAULT_VREF_SOURCE    adc_VREF_VDDA_2
#elif(adc_DEFAULT_VREF_SEL == adc__VDDA)
    #define adc_DEFAULT_VREF_SOURCE    adc_VREF_VDDA
#elif(adc_DEFAULT_VREF_SEL == adc__INTERNAL1024)
    #define adc_DEFAULT_VREF_SOURCE    adc_VREF_INTERNAL1024
#elif(adc_DEFAULT_VREF_SEL == adc__INTERNAL1024BYPASSED)
    #define adc_DEFAULT_VREF_SOURCE    adc_VREF_INTERNAL1024BYPASSED
#elif(adc_DEFAULT_VREF_SEL == adc__INTERNALVREF)
    #define adc_DEFAULT_VREF_SOURCE    adc_VREF_INTERNALVREF
#elif(adc_DEFAULT_VREF_SEL == adc__INTERNALVREFBYPASSED)
    #define adc_DEFAULT_VREF_SOURCE    adc_VREF_INTERNALVREFBYPASSED
#elif(adc_DEFAULT_VREF_SEL == adc__VDDA_2BYPASSED)
    #define adc_DEFAULT_VREF_SOURCE    adc_VREF_VDDA_2BYPASSED
#else
    #define adc_DEFAULT_VREF_SOURCE    adc_VREF_EXTERNAL
#endif /* adc_DEFAULT_VREF_SEL == adc__VDDA_2 */

#if(adc_DEFAULT_NEG_INPUT_SEL == adc__VSS)
    /* Connect NEG input of SARADC to VSSA close to the SARADC for single channel mode */
    #if(adc_TOTAL_CHANNELS_NUM == 1u)
        #define adc_DEFAULT_SE_NEG_INPUT    adc_NEG_VSSA
    #else
        #define adc_DEFAULT_SE_NEG_INPUT    adc_NEG_VSSA_KELVIN
    #endif /* (adc_TOTAL_CHANNELS_NUM == 1u) */
    /* Do not connect VSSA to VMINUS when one channel in differential mode used */
    #if((adc_TOTAL_CHANNELS_NUM == 1u) && (adc_CHANNELS_MODE != 0u))
        #define adc_DEFAULT_MUX_SWITCH0     0u
    #else    /* miltiple channels or one single channel */
        #define adc_DEFAULT_MUX_SWITCH0     adc_MUX_FW_VSSA_VMINUS
    #endif /* (adc_TOTAL_CHANNELS_NUM == 1u) */
#elif(adc_DEFAULT_NEG_INPUT_SEL == adc__VREF)
    /* Do not connect VNEG to VREF when one channel in differential mode used */
    #if((adc_TOTAL_CHANNELS_NUM == 1u) && (adc_CHANNELS_MODE != 0u))
        #define adc_DEFAULT_SE_NEG_INPUT    0u
    #else    /* miltiple channels or one single channel */
        #define adc_DEFAULT_SE_NEG_INPUT    adc_NEG_VREF
    #endif /* (adc_TOTAL_CHANNELS_NUM == 1u) */
    #define adc_DEFAULT_MUX_SWITCH0     0u
#elif (adc_SINGLE_PRESENT != 0u)
    #define adc_DEFAULT_SE_NEG_INPUT    adc_NEG_OTHER
    #define adc_DEFAULT_MUX_SWITCH0     0u
#else
    #define adc_DEFAULT_SE_NEG_INPUT    0u
    #define adc_DEFAULT_MUX_SWITCH0     0u
#endif /* adc_DEFAULT_NEG_INPUT_SEL == adc__VREF */

/* If the SAR is configured for multiple channels, always set SAR_HW_CTRL_NEGVREF to 1 */
#if(adc_TOTAL_CHANNELS_NUM == 1u)
    #define adc_DEFAULT_HW_CTRL_NEGVREF 0u
#else
    #define adc_DEFAULT_HW_CTRL_NEGVREF adc_SAR_HW_CTRL_NEGVREF
#endif /* (adc_TOTAL_CHANNELS_NUM == 1u) */


#if(adc_DEFAULT_ALT_RESOLUTION_SEL == adc__RES8)
    #define adc_DEFAULT_ALT_RESOLUTION     (adc_ALT_RESOLUTION_8BIT)
    #define adc_DEFAULT_MAX_WRK_ALT        (adc_SAR_WRK_MAX_8BIT)
#else
    #define adc_DEFAULT_ALT_RESOLUTION     (adc_ALT_RESOLUTION_10BIT)
    #define adc_DEFAULT_MAX_WRK_ALT        (adc_SAR_WRK_MAX_10BIT)
#endif /* End adc_DEFAULT_ALT_RESOLUTION_SEL == adc__RES8 */

#if(adc_DEFAULT_JUSTIFICATION_SEL == adc__RIGHT)
    #define adc_DEFAULT_JUSTIFICATION  adc_DATA_ALIGN_RIGHT
#else
    #define adc_DEFAULT_JUSTIFICATION  adc_DATA_ALIGN_LEFT
#endif /* adc_DEFAULT_JUSTIFICATION_SEL == adc__RIGHT */

#if(adc_DEFAULT_DIFF_RESULT_FORMAT_SEL == adc__FSIGNED)
    #define adc_DEFAULT_DIFF_RESULT_FORMAT adc_DIFF_SIGNED_RESULT
#else
    #define adc_DEFAULT_DIFF_RESULT_FORMAT adc_DIFF_UNSIGNED_RESULT
#endif /* adc_DEFAULT_DIFF_RESULT_FORMAT_SEL == adc__FSIGNED */

#if(adc_DEFAULT_SE_RESULT_FORMAT_SEL == adc__FSIGNED)
    #define adc_DEFAULT_SE_RESULT_FORMAT adc_SE_SIGNED_RESULT
#else
    #define adc_DEFAULT_SE_RESULT_FORMAT adc_SE_UNSIGNED_RESULT
#endif /* adc_DEFAULT_SE_RESULT_FORMAT_SEL == adc__FSIGNED */

#if(adc_DEFAULT_SAMPLE_MODE_SEL == adc__FREERUNNING)
    #define adc_DSI_TRIGGER        0u
#else /* Firmware trigger */
    #define adc_DSI_TRIGGER        (adc_DSI_TRIGGER_EN | adc_DSI_SYNC_TRIGGER)
#endif /* End adc_DEFAULT_SAMPLE_MODE == adc__FREERUNNING */

#if(adc_INJ_CHANNEL_ENABLED)
    #define adc_SAR_INTR_MASK      (adc_EOS_MASK | adc_INJ_EOC_MASK)
#else
    #define adc_SAR_INTR_MASK      (adc_EOS_MASK)
#endif /* adc_INJ_CHANNEL_ENABLED*/

#if(adc_DEFAULT_AVG_MODE == adc__FIXEDRESOLUTION)
    #define adc_AVG_SHIFT_MODE     adc_AVG_SHIFT
#else
    #define adc_AVG_SHIFT_MODE     0u
#endif /* End adc_DEFAULT_AVG_MODE */

#define adc_COMPARE_MODE           (uint32)((uint32)(adc_DEFAULT_COMPARE_MODE) \
                                                << adc_CMP_OFFSET)

#if(adc_TOTAL_CHANNELS_NUM > 1u)
    #define adc_DEFAULT_SWITCH_CONF    0u
#else /* Disable SAR sequencer from enabling routing switches in single channel mode */
    #define adc_DEFAULT_SWITCH_CONF    adc_SWITCH_DISABLE
#endif /* End adc_TOTAL_CHANNELS_NUM > 1 */

#define adc_DEFAULT_POWER \
       ((adc_NOMINAL_CLOCK_FREQ > (adc_MAX_FREQUENCY / 4)) ? adc_NORMAL_PWR : \
       ((adc_NOMINAL_CLOCK_FREQ > (adc_MAX_FREQUENCY / 8)) ? adc_HALF_PWR : \
                                                                                       adc_QUARTER_PWR))

#define adc_DEFAULT_CTRL_REG_CFG       (adc_DEFAULT_VREF_SOURCE \
                                                   | adc_DEFAULT_SE_NEG_INPUT \
                                                   | adc_DEFAULT_HW_CTRL_NEGVREF \
                                                   | adc_DEFAULT_POWER \
                                                   | adc_DSI_SYNC_CONFIG \
                                                   | adc_DEFAULT_SWITCH_CONF)

#define adc_DEFAULT_SAMPLE_CTRL_REG_CFG (adc_DEFAULT_DIFF_RESULT_FORMAT \
                                                    | adc_DEFAULT_SE_RESULT_FORMAT \
                                                    | adc_DEFAULT_JUSTIFICATION \
                                                    | adc_DEFAULT_ALT_RESOLUTION \
                                           | (uint8)(adc_DEFAULT_AVG_SAMPLES_NUM \
                                                   << adc_AVG_CNT_OFFSET) \
                                                    | adc_AVG_SHIFT_MODE \
                                                    | adc_DSI_TRIGGER \
                                                    | adc_EOS_DSI_OUT_EN)

#define adc_DEFAULT_RANGE_THRES_REG_CFG (adc_DEFAULT_LOW_LIMIT \
            | (uint32)((uint32)adc_DEFAULT_HIGH_LIMIT << adc_RANGE_HIGH_OFFSET))

#define adc_DEFAULT_SAMPLE_TIME01_REG_CFG (adc_DEFAULT_ACLKS_NUM \
            | (uint32)((uint32)adc_DEFAULT_BCLKS_NUM << adc_SAMPLE_TIME13_OFFSET))

#define adc_DEFAULT_SAMPLE_TIME23_REG_CFG (adc_DEFAULT_CCLKS_NUM \
            | (uint32)((uint32)adc_DEFAULT_DCLKS_NUM << adc_SAMPLE_TIME13_OFFSET))


#endif /* End CY_ADC_SAR_SEQ_adc_H */


/* [] END OF FILE */
