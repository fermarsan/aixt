/***************************************************************************//**
* \file capsense_ADC_Structure.c
* \version 7.10
*
* \brief
*   This file defines the data structure global variables and provides implementation
*   for the high-level and low-level APIs of the Data Structure module.
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

#include <string.h>
#include <cytypes.h>
#include "CyLib.h"
#include "capsense_ADC_Structure.h"
#include "capsense_ADC_Configuration.h"

#if (capsense_ADC_ENABLE == capsense_ADC_ADC_EN)
    #include "capsense_ADC_Adc.h"
#endif /* (capsense_ADC_ENABLE == capsense_ADC_ADC_EN) */

/*******************************************************************************
* Defines the RAM Data Structure variables and their init data in flash
*******************************************************************************/

/**
* \cond SECTION_GLOBAL_VARIABLES
* \addtogroup group_global_variables
* \{
*/

/**
* The variable that contains the capsense_ADC configuration, settings and
* scanning results. capsense_ADC_dsRam represents RAM Data Structure.
*/
capsense_ADC_RAM_STRUCT capsense_ADC_dsRam;

/** \}
* \endcond */

/**
* \cond SECTION_API_CONSTANTS
* \addtogroup group_api_constants
* \{
*/


/**
 *  The array of the pointers to the ADC input channels specific register.
 */
const capsense_ADC_FLASH_IO_STRUCT capsense_ADC_adcIoList[capsense_ADC_ADC_TOTAL_CHANNELS] =
{
    {
        (reg32 *)capsense_ADC_AdcInput__0__HSIOM,
        (reg32 *)capsense_ADC_AdcInput__0__PC,
        (reg32 *)capsense_ADC_AdcInput__0__DR,
        (reg32 *)capsense_ADC_AdcInput__0__PS,
        capsense_ADC_AdcInput__0__HSIOM_MASK,
        capsense_ADC_AdcInput__0__MASK,
        capsense_ADC_AdcInput__0__HSIOM_SHIFT,
        (uint8)capsense_ADC_AdcInput__0__SHIFT,
        (uint8)capsense_ADC_AdcInput__0__SHIFT * 3u,
    },
};



/** \}
* \endcond */


/*******************************************************************************
* Function Name: capsense_ADC_AdcDsInitialize
****************************************************************************//**
*
* \brief
*   This function initializes the Data Structure storage.
*
* \details
*   Configures the initial Adc datastructure members.
*
*******************************************************************************/
void capsense_ADC_AdcDsInitialize(void)
{
    /* Reset RAM data structure content */
    (void)memset(&capsense_ADC_dsRam, 0, sizeof(capsense_ADC_dsRam));

    capsense_ADC_dsRam.adcResolution = capsense_ADC_ADC_RESOLUTION;
    capsense_ADC_dsRam.adcIdac = (uint8)(capsense_ADC_ADC_IDAC_DEFAULT);
    capsense_ADC_dsRam.adcActiveCh = capsense_ADC_AdcNO_CHANNEL;
}

/* [] END OF FILE */
