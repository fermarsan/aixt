/***************************************************************************//**
* \file capsense_ADC_Structure.h
* \version 7.10
*
* \brief
*   This file provides the top level declarations of the Component data structure.
*   Also, the file declares the high-level and low-level APIs for data access.
*
* \see capsense_ADC v7.10 Datasheet
*
*//*****************************************************************************
* Copyright (2016-2019), Cypress Semiconductor Corporation.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress) and is
* protected by and subject to worldwide patent protection (United States and
* foreign), United States copyright laws and international treaty provisions.
* Cypress hereby grants to licensee a personal, non-exclusive, non-transferable
* license to copy, use, modify, create derivative works of, and compile the
* Cypress Source Code and derivative works for the sole purpose of creating
* custom software in support of licensee product to be used only in conjunction
* with a Cypress integrated circuit as specified in the applicable agreement.
* Any reproduction, modification, translation, compilation, or representation of
* this software except as specified above is prohibited without the express
* written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the
* materials described herein. Cypress does not assume any liability arising out
* of the application or use of any product or circuit described herein. Cypress
* does not authorize its products for use as critical components in life-support
* systems where a malfunction or failure may reasonably be expected to result in
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of
* such use and in doing so indemnifies Cypress against all charges. Use may be
* limited by and subject to the applicable Cypress software license agreement.
*******************************************************************************/

#if !defined(CY_SENSE_capsense_ADC_STRUCTURE_H)
#define CY_SENSE_capsense_ADC_STRUCTURE_H

#include <cytypes.h>
#include "capsense_ADC_Configuration.h"

/**
* \cond SECTION_STRUCTURES
* \addtogroup group_structures
* \{
*/

/***************************************************************************//**
* \brief Declares the top-level RAM Data Structure
*******************************************************************************/
typedef struct
{
    /**
     *  Stores the latest ADC result for the channel. The array size is 
     *  equal to the number of ADC channels used in the project.
     */
    uint16 adcResult [capsense_ADC_ADC_TOTAL_CHANNELS];

    /**
     *  Stores the latest ADC conversion result for the channel. The 
     *  array size is equal to the number of ADC channels used in the project.
     */
    uint16 adcCode [capsense_ADC_ADC_TOTAL_CHANNELS];

    /**
     *  Stores the status of ADC.
     */
    volatile uint8 adcStatus;

    /**
     *  ADC IDAC
     */
    uint8  adcIdac;

    /**
     *  The last scanned ADC channel.
     */
    uint8  adcActiveCh;

    /**
     *  Stores the ADC resolution.
     */
    uint8  adcResolution;

    /**
     *  Stores the AZ time used for ADC conversion.
     */
    uint8  adcAzTime;
} capsense_ADC_RAM_STRUCT;


/***************************************************************************//**
* \brief Declares the Flash IO object
*******************************************************************************/
typedef struct
{
    /**
     *  Pointer to the HSIOM configuration register of the IO.
     */
    reg32 *hsiomPtr;

    /**
     *  Pointer to the port configuration register of the IO.
     */
    reg32 *pcPtr;

    /**
     *  Pointer to the port data register of the IO.
     */
    reg32 *drPtr;

    /**
     *  Pointer to the pin state data register of the IO.
     */
    reg32 *psPtr;

    /**
     *  IO mask in the HSIOM configuration register.
     */
    uint32 hsiomMask;

    /**
     *  IO mask in the DR and PS registers.
     */
    uint32 mask;

    /**
     *  Position of the IO configuration bits in the HSIOM register.
     */
    uint8 hsiomShift;

    /**
     *  Position of the IO configuration bits in the DR and PS registers.
     */
    uint8 drShift;

    /**
     *  Position of the IO configuration bits in the PC register.
     */
    uint8 shift;

} capsense_ADC_FLASH_IO_STRUCT;

/** \}
* \endcond */


/*******************************************************************************
* Declares Flash and RAM Data Structure variables
*******************************************************************************/
extern capsense_ADC_RAM_STRUCT            capsense_ADC_dsRam;
extern const capsense_ADC_FLASH_IO_STRUCT capsense_ADC_adcIoList[capsense_ADC_ADC_TOTAL_CHANNELS];


/*******************************************************************************
* Function Prototypes - internal functions
*******************************************************************************/

/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

void capsense_ADC_AdcDsInitialize(void);

/** \}
* \endcond */

#endif /* End CY_SENSE_capsense_ADC_STRUCTURE_H */


/* [] END OF FILE */
