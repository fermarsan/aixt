/***************************************************************************//**
* \file capsense_INT.c
* \version 7.10
*
* \brief
*   This file contains the source code for implementation of the Component's
*   Interrupt Service Routine (ISR).
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
#include "cytypes.h"
#include "cyfitter.h"
#include "capsense_Configuration.h"
#include "capsense_Structure.h"
#include "capsense_Sensing.h"
#if (capsense_ENABLE == capsense_CSD_EN)
    #include "capsense_SensingCSD_LL.h"
#endif /* (capsense_ENABLE == capsense_CSD_EN) */
#include "cyapicallbacks.h"

/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/
/**
* \cond SECTION_C_INTERNAL
* \addtogroup group_c_internal
* \{
*/

#if (((capsense_ENABLE == capsense_CSD_EN) || (capsense_ENABLE == capsense_CSD_CSX_EN)) && \
     (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN))
    static void capsense_SsNextFrequencyScan(void);
#endif /* (((capsense_ENABLE == capsense_CSD_EN) || (capsense_ENABLE == capsense_CSD_CSX_EN)) && \
            (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)) */

#if ((capsense_ENABLE == capsense_CSD_EN) || (capsense_ENABLE == capsense_CSD_CSX_EN))
    static void capsense_SsCSDPostScan(void);
    static void capsense_SsCSDInitNextScan(void);
#endif /* ((capsense_ENABLE == capsense_CSD_EN) || (capsense_ENABLE == capsense_CSD_CSX_EN)) */
/** \}
* \endcond */


/**
* \cond SECTION_C_INTERRUPT
* \addtogroup group_c_interrupt
* \{
*/


#if ((capsense_ENABLE == capsense_CSD_EN) || (capsense_ENABLE == capsense_CSD_CSX_EN))

#if (capsense_ENABLE == capsense_CSDV2)
    /* Fourth-generation HW block part */

    /*******************************************************************************
    * Function Name: capsense_CSDPostSingleScan
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for the single-sensor scanning implementation.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  capsense_CSDScanExt() function.
    *
    *  The following tasks are performed for Third-generation HW block:
    *    1. Disable the CSD interrupt.
    *    2. Read the Counter register and update the data structure with raw data.
    *    3. Connect the Vref buffer to the AMUX bus.
    *    4. Update the Scan Counter.
    *    5. Reset the BUSY flag.
    *    6. Enable the CSD interrupt.
    *
    *  The following tasks are performed for Fourth-generation HW block:
    *    1. Check if the raw data is not noisy.
    *    2. Read the Counter register and update the data structure with raw data.
    *    3. Configure and start the scan for the next frequency if the
    *      multi-frequency is enabled.
    *    4. Update the Scan Counter.
    *    5. Reset the BUSY flag.
    *    6. Enable the CSD interrupt.
    *
    *  The ISR handler changes the IMO and initializes scanning for the next frequency
    *  channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user code
    *  from macros specified in Component's generated code. Refer to the
    *  \ref group_c_macrocallbacks section of the PSoC Creator User Guide
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(capsense_CSDPostSingleScan)
    {
        #ifdef capsense_ENTRY_CALLBACK
            capsense_EntryCallback();
        #endif /* capsense_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_SET_MASK);

        #if (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN)
            if ((capsense_CSD_NOISE_METRIC_TH < ((CY_GET_REG32(capsense_RESULT_VAL1_PTR) &
                                                        capsense_RESULT_VAL1_BAD_CONVS_MASK) >>
                                                        capsense_RESULT_VAL1_BAD_CONVS_SHIFT)) &&
                                                        (0u < capsense_badConversionsNum))
            {
                /* Decrement bad conversions number */
                capsense_badConversionsNum--;

                /* Start the re-scan */
                CY_SET_REG32(capsense_SEQ_START_PTR, capsense_SEQ_START_AZ0_SKIP_MASK |
                                                             capsense_SEQ_START_AZ1_SKIP_MASK |
                                                             capsense_SEQ_START_START_MASK);
            }
            else
            {
        #endif /* (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN) */

            capsense_SsCSDPostScan();

            #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
                if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
                {
                    /* Scan the next channel */
                    capsense_SsNextFrequencyScan();
                }
                else
                {
                    /* All channels are scanned. Set IMO to zero channel */
                    capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                    #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                        capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                    #else
                        capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                    #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

                    #if (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN)
                        /* Disable Fourth-generation HW block */
                        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd);
                    #endif /* (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN) */

                    /* Update Scan Counter */
                    capsense_dsRam.scanCounter++;

                    /* Sensor is totally scanned. Reset BUSY flag */
                    capsense_dsRam.status &= ~(capsense_SW_STS_BUSY | capsense_WDGT_SW_STS_BUSY);
                }
            #else
                {
                    #if (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN)
                        /* Disable Fourth-generation HW block */
                        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd);
                    #endif /* (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN) */

                    /* Update Scan Counter */
                    capsense_dsRam.scanCounter++;

                    /* Sensor is totally scanned. Reset BUSY flag */
                    capsense_dsRam.status &= ~(capsense_SW_STS_BUSY | capsense_WDGT_SW_STS_BUSY);
                }
            #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */
    #if (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN)
        }
    #endif /* (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN) */

        #ifdef capsense_EXIT_CALLBACK
            capsense_ExitCallback();
        #endif /* capsense_EXIT_CALLBACK */
    }


    /*******************************************************************************
    * Function Name: capsense_CSDPostMultiScan
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for the multiple-sensor scanning
    *  implementation.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  capsense_Scan() or capsense_ScanAllWidgets() APIs.
    *
    *  The following tasks are performed:
    *    1. Disable the CSD interrupt.
    *    2. Read the Counter register and update the data structure with raw data.
    *    3. Connect the Vref buffer to the AMUX bus.
    *    4. Disable the CSD block (after the widget has been scanned).
    *    5. Update the Scan Counter.
    *    6. Reset the BUSY flag.
    *    7. Enable the CSD interrupt.
    *
    *  The ISR handler initializes scanning for the previous sensor when the
    *  widget has more than one sensor.
    *  The ISR handler initializes scanning for the next widget when the
    *  capsense_ScanAllWidgets() APIs are called and the project has
    *  more than one widget.
    *  The ISR handler changes the IMO and initializes scanning for the next
    *  frequency channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user
    *  code from macros specified in Component's generated code. Refer to the
    *  \ref group_c_macrocallbacks section of the PSoC Creator User Guide
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(capsense_CSDPostMultiScan)
    {
        /* Declare and initialize ptr to sensor IO structure to appropriate address */
        capsense_FLASH_IO_STRUCT const *curSnsIOPtr = (capsense_FLASH_IO_STRUCT const *)
                                                          capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2SnsFlash
                                                          + capsense_sensorIndex;

        #ifdef capsense_ENTRY_CALLBACK
            capsense_EntryCallback();
        #endif /* capsense_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_SET_MASK);

        #if (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN)
            if ((capsense_CSD_NOISE_METRIC_TH < ((CY_GET_REG32(capsense_RESULT_VAL1_PTR) &
                                                      capsense_RESULT_VAL1_BAD_CONVS_MASK) >>
                                                      capsense_RESULT_VAL1_BAD_CONVS_SHIFT)) &&
                                                      (0u < capsense_badConversionsNum))
            {
                /* Decrement bad conversions number */
                capsense_badConversionsNum--;

                /* Start the re-scan */
                CY_SET_REG32(capsense_SEQ_START_PTR, capsense_SEQ_START_AZ0_SKIP_MASK |
                                                             capsense_SEQ_START_AZ1_SKIP_MASK |
                                                             capsense_SEQ_START_START_MASK);
            }
            else
            {
        #endif /* (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN) */

            capsense_SsCSDPostScan();

            /* Disable sensor when all frequency channels are scanned */
            #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
                if (capsense_FREQ_CHANNEL_2 == capsense_scanFreqIndex)
            #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */
            {
                /* Disable sensor */
                capsense_CSDDisconnectSns(curSnsIOPtr);
            }

            #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
                if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
                {
                     /* Scan the next channel */
                    capsense_SsNextFrequencyScan();
                }
                else
                {
                     /* All channels are scanned. Set IMO to zero channel */
                    capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                    #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                        capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                    #else
                        capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                    #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

                     /* Scan the next sensor */
                    capsense_SsCSDInitNextScan();
                }
            #else
                /* Scan the next sensor */
                capsense_SsCSDInitNextScan();
            #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */
        #if (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN)
            }
        #endif /* (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN) */

        #ifdef capsense_EXIT_CALLBACK
            capsense_ExitCallback();
        #endif /* capsense_EXIT_CALLBACK */
    }


    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
    /*******************************************************************************
    * Function Name: capsense_CSDPostMultiScanGanged
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for the multiple-sensor scanning
    *  implementation for ganged sensors.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  capsense_Scan() API for a ganged sensor or the
    *  capsense_ScanAllWidgets() API in the project with ganged sensors.
    *
    *  The following tasks are performed:
    *    1. Disable the CSD interrupt.
    *    2. Read the Counter register and update the data structure with raw data.
    *    3. Connect the Vref buffer to the AMUX bus.
    *    4. Disable the CSD block (after the widget has been scanned).
    *    5. Update the Scan Counter.
    *    6. Reset the BUSY flag.
    *    7. Enable the CSD interrupt.
    *
    *  The ISR handler initializes scanning for the previous sensor when the
    *  widget has more than one sensor.
    *  The ISR handler initializes scanning for the next widget when the
    *  capsense_ScanAllWidgets() APIs are called and the project has
    *  more than one widget.
    *  The ISR handler changes the IMO and initializes scanning for the next
    *  frequency channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user
    *  code from macros specified in Component's generated code. Refer to the
    *  \ref group_c_macrocallbacks section of the PSoC Creator User Guide
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(capsense_CSDPostMultiScanGanged)
    {
        #ifdef capsense_ENTRY_CALLBACK
            capsense_EntryCallback();
        #endif /* capsense_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_SET_MASK);

        #if (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN)
            if ((capsense_CSD_NOISE_METRIC_TH < ((CY_GET_REG32(capsense_RESULT_VAL1_PTR) &
                                                      capsense_RESULT_VAL1_BAD_CONVS_MASK) >>
                                                      capsense_RESULT_VAL1_BAD_CONVS_SHIFT)) &&
                                                      (0u < capsense_badConversionsNum))
            {
                /* Decrement bad conversions number */
                capsense_badConversionsNum--;

                /* Start the re-scan */
                CY_SET_REG32(capsense_SEQ_START_PTR, capsense_SEQ_START_AZ0_SKIP_MASK |
                                                             capsense_SEQ_START_AZ1_SKIP_MASK |
                                                             capsense_SEQ_START_START_MASK);
            }
            else
            {
        #endif /* (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN) */

            capsense_SsCSDPostScan();

            #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
                if (capsense_FREQ_CHANNEL_2 == capsense_scanFreqIndex)
            #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */
            {
                capsense_SsCSDDisconnectSnsExt((uint32)capsense_widgetIndex, (uint32)capsense_sensorIndex);
            }

            #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
                if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
                {
                     /* Scan the next channel */
                    capsense_SsNextFrequencyScan();
                }
                else
                {
                    /* All channels are scanned. Set IMO to zero channel */
                    capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                    #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                        capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                    #else
                        capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                    #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

                     /* Scan the next sensor */
                    capsense_SsCSDInitNextScan();
                }
            #else
                 /* Scan the next sensor */
                capsense_SsCSDInitNextScan();
            #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */
        #if (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN)
            }
        #endif /* (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN) */

        #ifdef capsense_EXIT_CALLBACK
            capsense_ExitCallback();
        #endif /* capsense_EXIT_CALLBACK */
    }
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN) */

#else

    /* Third-generation HW block part */

    /*******************************************************************************
    * Function Name: capsense_CSDPostSingleScan
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for the single-sensor scanning implementation.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  capsense_CSDScanExt() function.
    *
    *  The following tasks are performed for Third-generation HW block:
    *    1. Disable the CSD interrupt.
    *    2. Read the Counter register and update the data structure with raw data.
    *    3. Connect the Vref buffer to the AMUX bus.
    *    4. Update the Scan Counter.
    *    5. Reset the BUSY flag.
    *    6. Enable the CSD interrupt.
    *
    *  The following tasks are performed for Fourth-generation HW block:
    *    1. Check if the raw data is not noisy.
    *    2. Read the Counter register and update the data structure with raw data.
    *    3. Configure and start the scan for the next frequency if the
    *      multi-frequency is enabled.
    *    4. Update the Scan Counter.
    *    5. Reset the BUSY flag.
    *    6. Enable the CSD interrupt.
    *
    *  The ISR handler changes the IMO and initializes scanning for the next frequency
    *  channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user code
    *  from macros specified in Component's generated code. Refer to the
    *  \ref group_c_macrocallbacks section of the PSoC Creator User Guide
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(capsense_CSDPostSingleScan)
    {
        #ifdef capsense_ENTRY_CALLBACK
            capsense_EntryCallback();
        #endif /* capsense_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_SET_MASK);

        /* Read Rawdata */
        capsense_SsCSDPostScan();

        #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
            if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
            {
                /* Connect Vref Buffer to AMUX bus. Third-generation HW block is enabled */
                CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG_CSD_EN);

                capsense_SsNextFrequencyScan();
            }
            else
            {
                capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                    capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                #else
                    capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

                #if (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN)
                    /* Disable Third-generation HW block. Connect Vref Buffer to AMUX bus */
                    #if ((capsense_CSH_PRECHARGE_IO_BUF == capsense_CSD_CSH_PRECHARGE_SRC) &&\
                         (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN))
                        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CMOD_PRECHARGE_CONFIG);
                    #else
                        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG);
                    #endif
                #else
                    /* Connect Vref Buffer to AMUX bus. Third-generation HW block is enabled */
                    CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG_CSD_EN);
                #endif

                /* Update Scan Counter */
                capsense_dsRam.scanCounter++;

                /* Sensor is totally scanned. Reset BUSY flag */
                capsense_dsRam.status &= ~(capsense_SW_STS_BUSY | capsense_WDGT_SW_STS_BUSY);
            }
        #else
            {
                #if (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN)
                    /* Disable Third-generation HW block. Connect Vref Buffer to AMUX bus */
                    #if ((capsense_CSH_PRECHARGE_IO_BUF == capsense_CSD_CSH_PRECHARGE_SRC) &&\
                         (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN))
                        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CMOD_PRECHARGE_CONFIG);
                    #else
                        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG);
                    #endif
                #else
                    /* Connect Vref Buffer to AMUX bus. Third-generation HW block is enabled */
                    CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG_CSD_EN);
                #endif

                /* Update Scan Counter */
                capsense_dsRam.scanCounter++;

                /* Sensor is totally scanned. Reset BUSY flag */
                capsense_dsRam.status &= ~(capsense_SW_STS_BUSY | capsense_WDGT_SW_STS_BUSY);
            }
        #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

        #ifdef capsense_EXIT_CALLBACK
            capsense_ExitCallback();
        #endif /* capsense_EXIT_CALLBACK */
    }


    /*******************************************************************************
    * Function Name: capsense_CSDPostMultiScan
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for the multiple-sensor scanning
    *  implementation.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  capsense_Scan() or capsense_ScanAllWidgets() APIs.
    *
    *  The following tasks are performed:
    *    1. Disable the CSD interrupt.
    *    2. Read the Counter register and update the data structure with raw data.
    *    3. Connect the Vref buffer to the AMUX bus.
    *    4. Disable the CSD block (after the widget has been scanned).
    *    5. Update the Scan Counter.
    *    6. Reset the BUSY flag.
    *    7. Enable the CSD interrupt.
    *
    *  The ISR handler initializes scanning for the previous sensor when the
    *  widget has more than one sensor.
    *  The ISR handler initializes scanning for the next widget when the
    *  capsense_ScanAllWidgets() APIs are called and the project has
    *  more than one widget.
    *  The ISR handler changes the IMO and initializes scanning for the next
    *  frequency channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user
    *  code from macros specified in Component's generated code. Refer to the
    *  \ref group_c_macrocallbacks section of the PSoC Creator User Guide
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(capsense_CSDPostMultiScan)
    {
        /* Declare and initialize ptr to sensor IO structure to appropriate address        */
        capsense_FLASH_IO_STRUCT const *curSnsIOPtr = (capsense_FLASH_IO_STRUCT const *)
                                                          capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2SnsFlash
                                                          + capsense_sensorIndex;

        #ifdef capsense_ENTRY_CALLBACK
            capsense_EntryCallback();
        #endif /* capsense_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_SET_MASK);

         /* Read Rawdata */
        capsense_SsCSDPostScan();

        /* Connect Vref Buffer to AMUX bus */
        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG_CSD_EN);

        #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
            /* Disable sensor when all frequency channels are scanned */
            if (capsense_FREQ_CHANNEL_2 == capsense_scanFreqIndex)
            {
                /* Disable sensor */
                capsense_CSDDisconnectSns(curSnsIOPtr);
            }
        #else
            /* Disable sensor */
            capsense_CSDDisconnectSns(curSnsIOPtr);
        #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

        #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
            if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
            {
                 /* Scan the next channel */
                capsense_SsNextFrequencyScan();
            }
            else
            {
                 /* All channels are scanned. Set IMO to zero channel */
                capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                    capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                #else
                    capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

                 /* Scan the next sensor */
                capsense_SsCSDInitNextScan();
            }
        #else
            /* Scan the next sensor */
            capsense_SsCSDInitNextScan();
        #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

        #ifdef capsense_EXIT_CALLBACK
            capsense_ExitCallback();
        #endif /* capsense_EXIT_CALLBACK */
    }


    #if (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN)
    /*******************************************************************************
    * Function Name: capsense_CSDPostMultiScanGanged
    ****************************************************************************//**
    *
    * \brief
    *  This is an internal ISR function for the multiple-sensor scanning
    *  implementation for ganged sensors.
    *
    * \details
    *  This ISR handler is triggered when the user calls the
    *  capsense_Scan() API for a ganged sensor or the
    *  capsense_ScanAllWidgets() API in the project with ganged sensors.
    *
    *  The following tasks are performed:
    *    1. Disable the CSD interrupt.
    *    2. Read the Counter register and update the data structure with raw data.
    *    3. Connect the Vref buffer to the AMUX bus.
    *    4. Disable the CSD block (after the widget has been scanned).
    *    5. Update the Scan Counter.
    *    6. Reset the BUSY flag.
    *    7. Enable the CSD interrupt.
    *
    *  The ISR handler initializes scanning for the previous sensor when the
    *  widget has more than one sensor.
    *  The ISR handler initializes scanning for the next widget when the
    *  capsense_ScanAllWidgets() APIs are called and the project has
    *  more than one widget.
    *  The ISR handler changes the IMO and initializes scanning for the next
    *  frequency channels when multi-frequency scanning is enabled.
    *
    *  This function has two Macro Callbacks that allow calling the user
    *  code from macros specified in Component's generated code. Refer to the
    *  \ref group_c_macrocallbacks section of the PSoC Creator User Guide
    *  for details.
    *
    *******************************************************************************/
    CY_ISR(capsense_CSDPostMultiScanGanged)
    {
        #ifdef capsense_ENTRY_CALLBACK
            capsense_EntryCallback();
        #endif /* capsense_ENTRY_CALLBACK */

        /* Clear pending interrupt */
        CY_SET_REG32(capsense_INTR_PTR, capsense_INTR_SET_MASK);

         /* Read Rawdata */
        capsense_SsCSDPostScan();

        /* Connect Vref Buffer to AMUX bus */
        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG_CSD_EN);

        #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
            if (capsense_FREQ_CHANNEL_2 == capsense_scanFreqIndex)
            {
                capsense_SsCSDDisconnectSnsExt((uint32)capsense_widgetIndex, (uint32)capsense_sensorIndex);
            }
        #else
            capsense_SsCSDDisconnectSnsExt((uint32)capsense_widgetIndex, (uint32)capsense_sensorIndex);
        #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

        #if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
            if (capsense_FREQ_CHANNEL_2 > capsense_scanFreqIndex)
            {
                 /* Scan the next channel */
                capsense_SsNextFrequencyScan();
            }
            else
            {
                /* All channels are scanned. Set IMO to zero channel */
                capsense_scanFreqIndex = capsense_FREQ_CHANNEL_0;

                #if (capsense_MFS_IMO == capsense_MFS_METHOD)
                    capsense_SsChangeImoFreq(capsense_FREQ_CHANNEL_0);
                #else
                    capsense_SsChangeClkFreq(capsense_FREQ_CHANNEL_0);
                #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

                 /* Scan the next sensor */
                capsense_SsCSDInitNextScan();
            }
        #else
             /* Scan the next sensor */
            capsense_SsCSDInitNextScan();
        #endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

        #ifdef capsense_EXIT_CALLBACK
            capsense_ExitCallback();
        #endif /* capsense_EXIT_CALLBACK */
    }
    #endif /* (capsense_ENABLE == capsense_CSD_GANGED_SNS_EN) */

#endif /* (capsense_ENABLE == capsense_CSDV2) */

#endif /* ((capsense_ENABLE == capsense_CSD_EN) || (capsense_ENABLE == capsense_CSD_CSX_EN)) */

/** \}
 * \endcond */


#if ((capsense_ENABLE == capsense_CSD_EN) || (capsense_ENABLE == capsense_CSD_CSX_EN))

/*******************************************************************************
* Function Name: capsense_SsCSDPostScan
****************************************************************************//**
*
* \brief
*   This function reads rawdata and releases required HW resources after scan.
*
* \details
*   This function performs following tasks after scan:
*   - Reads SlotResult from Raw Counter;
*   - Inits bad Conversions number;
*   - Disconnects Vrefhi from AMUBUF positive input;
*   - Disconnects AMUBUF output from CSDBUSB with sych PHI2+HSCMP;
*   - Opens HCBV and HCBG switches.
*
*******************************************************************************/
static void capsense_SsCSDPostScan(void)
{
    #if (capsense_ENABLE == capsense_CSDV2)

        uint32 tmpRawData;
        uint32 tmpMaxCount;
        capsense_RAM_WD_BASE_STRUCT const *ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
                                            capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2WdgtRam;

        /* Read SlotResult from Raw Counter */
        tmpRawData = capsense_RESULT_VAL1_VALUE_MASK & CY_GET_REG32(capsense_COUNTER_PTR);

        tmpMaxCount = ((1uL << ptrWdgt->resolution) - 1uL);
        if(tmpRawData < tmpMaxCount)
        {
            capsense_curRamSnsPtr->raw[capsense_scanFreqIndex] = LO16(tmpRawData);
        }
        else
        {
            capsense_curRamSnsPtr->raw[capsense_scanFreqIndex] = LO16(tmpMaxCount);
        }

        #if (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN)
            /* Init bad Conversions number */
            capsense_badConversionsNum = capsense_BAD_CONVERSIONS_NUM;
        #endif /* (capsense_ENABLE == capsense_CSD_NOISE_METRIC_EN) */

        #if (capsense_ENABLE == capsense_CSD_SHIELD_EN)
            /* Open HCBV and HCBG switches */
            CY_SET_REG32(capsense_SW_SHIELD_SEL_PTR, capsense_SW_SHIELD_SEL_SW_HCBV_STATIC_OPEN |
                                                             capsense_SW_SHIELD_SEL_SW_HCBG_STATIC_OPEN);
        #endif /* (capsense_ENABLE == capsense_CSD_SHIELD_EN) */

    #else

        /* Read SlotResult from Raw Counter */
       capsense_curRamSnsPtr->raw[capsense_scanFreqIndex] = (uint16)CY_GET_REG32(capsense_COUNTER_PTR);

    #endif /* (capsense_ENABLE == capsense_CSDV2) */
}


/*******************************************************************************
* Function Name: capsense_SsCSDInitNextScan
****************************************************************************//**
*
* \brief
*   This function initializes the next sensor scan.
*
* \details
*   The function increments the sensor index, updates sense clock for matrix
*   or touchpad widgets only, sets up Compensation IDAC, enables the sensor and
*   scans it. When all the sensors are scanned it continues to set up the next widget
*   until all the widgets are scanned. The CSD block is disabled when all the widgets are
*   scanned.
*
*******************************************************************************/
static void capsense_SsCSDInitNextScan(void)
{
    /* Declare and initialize ptr to widget and sensor structures to appropriate address */
    #if (((capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) || \
          (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)) || \
          (((capsense_DISABLE == capsense_CSD_COMMON_SNS_CLK_EN) && \
          (capsense_ENABLE == capsense_CSDV2) && \
          (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN))))
        capsense_RAM_WD_BASE_STRUCT *ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
                                                        capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2WdgtRam;
    #endif

    /* Check if all the sensors are scanned in widget */
    if (((uint8)capsense_dsFlash.wdgtArray[(capsense_widgetIndex)].totalNumSns - 1u) > capsense_sensorIndex)
    {
        /* Increment sensor index to configure next sensor in widget */
        capsense_sensorIndex++;

        /* Update global pointer to capsense_RAM_SNS_STRUCT to current sensor  */
        capsense_curRamSnsPtr = (capsense_RAM_SNS_STRUCT *)
                                                  capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2SnsRam
                                                  + capsense_sensorIndex;

        /* Configure clock divider to row or column */
        #if ((capsense_DISABLE == capsense_CSD_COMMON_SNS_CLK_EN) && \
             (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN))
            capsense_SsCSDConfigClock();

            #if (capsense_ENABLE == capsense_CSDV2)
                 /* Set up scanning resolution */
                capsense_SsCSDCalculateScanDuration(ptrWdgt);
            #endif
        #endif

        /* Setup Compensation IDAC for next sensor in widget */
        #if ((capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) || \
             (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN))
            capsense_SsCSDSetUpIdacs(ptrWdgt);
        #endif /* ((capsense_ENABLE == capsense_CSD_IDAC_COMP_EN) || \
                   (capsense_CSD_MATRIX_WIDGET_EN || capsense_CSD_TOUCHPAD_WIDGET_EN)) */

        /* Enable sensor */
        capsense_SsCSDConnectSensorExt((uint32)capsense_widgetIndex, (uint32)capsense_sensorIndex);

        /* Proceed scanning */
        capsense_SsCSDStartSample();
    }
    /* Call scan next widget API if requested, if not, complete the scan  */
    else
    {
        capsense_sensorIndex = 0u;

        /* Current widget is totally scanned. Reset WIDGET BUSY flag */
        capsense_dsRam.status &= ~capsense_WDGT_SW_STS_BUSY;

        /* Check if all the widgets have been scanned */
        if (capsense_ENABLE == capsense_requestScanAllWidget)
        {
            /* Configure and begin scanning next widget */
            capsense_SsPostAllWidgetsScan();
        }
        else
        {
            #if (capsense_ENABLE == capsense_BLOCK_OFF_AFTER_SCAN_EN)
                #if (capsense_ENABLE == capsense_CSDV2)
                    /* Disable the CSD block */
                    CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd);
                #else
                    /* Disable the CSD block. Connect Vref Buffer to AMUX bus */
                    #if ((capsense_CSH_PRECHARGE_IO_BUF == capsense_CSD_CSH_PRECHARGE_SRC) &&\
                         (capsense_ENABLE == capsense_CSD_SHIELD_TANK_EN))
                        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CMOD_PRECHARGE_CONFIG);
                    #else
                        CY_SET_REG32(capsense_CONFIG_PTR, capsense_configCsd | capsense_CTANK_PRECHARGE_CONFIG);
                    #endif
                #endif
            #endif

            /* All widgets are totally scanned. Reset BUSY flag */
            capsense_dsRam.status &= ~capsense_SW_STS_BUSY;

            /* Update scan Counter */
            capsense_dsRam.scanCounter++;
        }
    }
}

#if (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN)
    /*******************************************************************************
    * Function Name: capsense_SsNextFrequencyScan
    ****************************************************************************//**
    *
    * \brief
    *   This function scans the sensor on the next frequency channel.
    *
    * \details
    *   The function increments the frequency channel, changes IMO and initializes
    *   the scanning process of the same sensor.
    *
    *******************************************************************************/
    static void capsense_SsNextFrequencyScan(void)
    {
        capsense_RAM_WD_BASE_STRUCT const *ptrWdgt = (capsense_RAM_WD_BASE_STRUCT *)
                                                        capsense_dsFlash.wdgtArray[capsense_widgetIndex].ptr2WdgtRam;

        capsense_scanFreqIndex++;

        /* Set Immunity */
        #if (capsense_MFS_IMO == capsense_MFS_METHOD)
            capsense_SsChangeImoFreq((uint32)capsense_scanFreqIndex);
        #else
            capsense_SsChangeClkFreq((uint32)capsense_scanFreqIndex);
        #endif /* (capsense_MFS_IMO == capsense_MFS_METHOD) */

        /* Update IDAC registers */
        capsense_SsCSDSetUpIdacs(ptrWdgt);

        /* Proceed scanning */
        capsense_SsCSDStartSample();
    }
#endif /* (capsense_ENABLE == capsense_MULTI_FREQ_SCAN_EN) */

#endif /* ((capsense_ENABLE == capsense_CSD_EN) || (capsense_ENABLE == capsense_CSD_CSX_EN)) */


/* [] END OF FILE */
