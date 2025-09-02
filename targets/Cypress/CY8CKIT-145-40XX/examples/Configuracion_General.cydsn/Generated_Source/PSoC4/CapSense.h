/***************************************************************************//**
* \file capsense.h
* \version 7.10
*
* \brief
*   This file includes all header files of the capsense Component modules.
*
* \see capsense v7.10 Datasheet
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

#if !defined(CY_SENSE_capsense_H)

#define CY_SENSE_capsense_H

#include "capsense_Configuration.h"
#include "capsense_Control.h"
#include "capsense_Filter.h"
#include "capsense_Processing.h"
#include "capsense_Sensing.h"
#if (capsense_ENABLE == capsense_CSD_EN)
    #include "capsense_SensingCSD_LL.h"
#endif /* (capsense_ENABLE == capsense_CSD_EN) */
#if (capsense_ENABLE == capsense_CSX_EN)
    #include "capsense_SensingCSX_LL.h"
#endif /* (capsense_ENABLE == capsense_CSX_EN) */
#if (capsense_ENABLE == capsense_ISX_EN)
    #include "capsense_SensingISX_LL.h"
#endif /* (capsense_ENABLE == capsense_ISX_EN) */
#include "capsense_Structure.h"
#include "capsense_Tuner.h"

#endif /* End CY_SENSE_capsense_H */


/* [] END OF FILE */
