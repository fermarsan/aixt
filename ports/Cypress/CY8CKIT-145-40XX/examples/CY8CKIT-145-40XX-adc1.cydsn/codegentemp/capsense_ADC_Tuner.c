/***************************************************************************//**
* \file capsense_ADC_Tuner.c
* \version 7.10
*
* \brief
*   This file provides the source code for the Tuner module API of the Component.
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

#include "cytypes.h"
#include "CyLib.h"
#include "capsense_ADC_Structure.h"
#include "capsense_ADC_Tuner.h"
#include "capsense_ADC_Control.h"
#include "capsense_ADC_Configuration.h"

/* Tuner states definition */
#define TU_FSM_RUNNING      (0u)
#define TU_FSM_SUSPENDED    (1u)
#define TU_FSM_SNR_TEST     (2u)
#define TU_FSM_ONE_SCAN     (3u)

/* Tuner state variable */
static uint32 tunerFsm = TU_FSM_RUNNING;


/*******************************************************************************
* Function Name: capsense_ADC_TuInitialize
****************************************************************************//**
*
* \brief
*   This function initializes the communication interface with the Tuner GUI.
*
* \details
*   This API sets the tuner state machine to the default state. It is called by
*   the capsense_ADC_Start() API.
*
*******************************************************************************/
void capsense_ADC_TuInitialize(void)
{
    volatile capsense_ADC_RAM_STRUCT *ptrDsRam = &capsense_ADC_dsRam;

    ptrDsRam->tunerCmd = (uint16)capsense_ADC_TU_CMD_NONE_E;
    tunerFsm = TU_FSM_RUNNING;
}

/*******************************************************************************
* Function Name: capsense_ADC_RunTuner
****************************************************************************//**
*
* \brief
*  Establishes synchronized communication with the Tuner application.
*
* \details
*  This function is used to establish synchronized communication between the
*  capsense_ADC Component and Tuner application (or other host controllers).
*  This function is called periodically in the application program loop
*  to serve the Tuner application (or host controller) requests and commands.
*  In most cases, the best place to call this function is after processing and
*  before next scanning.
*
*  If this function is absent in the application program, then communication is
*  asynchronous and the following disadvantages are applicable:
*    - The raw counts displayed in the tuner may be filtered and/or unfiltered.
*      As a result, noise and SNR measurements will not be accurate.
*    - The Tuner tool may read the sensor data such as raw counts from a scan
*      multiple times, as a result, noise and SNR measurement will not be
*      accurate.
*    - The Tuner tool and host controller should not change the Component parameters
*      via the tuner interface. Changing the Component parameters via the tuner
*      interface in the async mode will result in Component abnormal behavior.
*
*  Note that calling this function is not mandatory for the application, but
*  required only to synchronize the communication with the host controller or
*  tuner application.
*
* \return
*  In some cases, the application program may need to know if the Component was
*  re-initialized. The return indicates if a restart command was executed or not:
*    - capsense_ADC_STATUS_RESTART_DONE - Based on a received command, the
*      Component was restarted.
*    -  capsense_ADC_STATUS_RESTART_NONE - No restart was executed by this
*      function.
*
*******************************************************************************/
uint32 capsense_ADC_RunTuner(void)
{
    uint8 interruptState;
    uint32 widgetId;
    uint32 sensorId;
    uint32 updateFlag = 0Lu;
    capsense_ADC_TU_CMD_ENUM command;
    uint32 tunerStatus = capsense_ADC_STATUS_RESTART_NONE;

    volatile capsense_ADC_RAM_STRUCT *ptrDsRam;
    volatile capsense_ADC_RAM_SNS_STRUCT *ptrSnsTmp;

    ptrDsRam = &capsense_ADC_dsRam;

    do
    {
        /* ONE_SCAN command could be interpreted as two commands:
        * RESUME till next call of this function and then
        * SUSPEND till next command receiving.
        */
        if (TU_FSM_ONE_SCAN == tunerFsm)
        {
            interruptState = CyEnterCriticalSection();
            ptrDsRam->tunerCmd = (uint16)capsense_ADC_TU_CMD_SUSPEND_E;
            CyExitCriticalSection(interruptState);
        }
        command = (capsense_ADC_TU_CMD_ENUM)ptrDsRam->tunerCmd;

        /* Check command register */
        switch (command)
        {
        case capsense_ADC_TU_CMD_SUSPEND_E:
            tunerFsm = TU_FSM_SUSPENDED;
            updateFlag = 1Lu;
            break;

        case capsense_ADC_TU_CMD_RESUME_E:
            tunerFsm = TU_FSM_RUNNING;
            updateFlag = 1Lu;
            break;

        case capsense_ADC_TU_CMD_RESTART_E:
            (void)capsense_ADC_Start();
            tunerStatus = capsense_ADC_STATUS_RESTART_DONE;
            tunerFsm = TU_FSM_RUNNING;
            updateFlag = 1Lu;
            break;

        case capsense_ADC_TU_CMD_RUN_SNR_TEST_E:
            tunerFsm = TU_FSM_SNR_TEST;
            updateFlag = 1Lu;
            break;

        case capsense_ADC_TU_CMD_PING_E:
            tunerFsm = TU_FSM_RUNNING;
            updateFlag = 1Lu;
            break;

        case capsense_ADC_TU_CMD_ONE_SCAN_E:
            tunerFsm = TU_FSM_ONE_SCAN;
            updateFlag = 0Lu;
            break;

        default:
            break;
        }

        /* Set Complete flag in command register if needed */
        if (0Lu != updateFlag)
        {
            interruptState = CyEnterCriticalSection();

            /* Check if command wasn't overwritten with new command */
            if (command == (capsense_ADC_TU_CMD_ENUM)ptrDsRam->tunerCmd)
            {
                ptrDsRam->tunerCmd |= capsense_ADC_TU_CMD_COMPLETE_BIT;
            }
            CyExitCriticalSection(interruptState);

            updateFlag = 0Lu;
        }
    } while (TU_FSM_SUSPENDED == tunerFsm);

    /* Check for SNR Test mode and do appropriate actions */
    if (TU_FSM_SNR_TEST == tunerFsm)
    {
        widgetId = ptrDsRam->snrTestWidgetId;
        sensorId = ptrDsRam->snrTestSensorId;

        /* Check if widgetId and sensorId are in range,
         * and data was updated in RAM (scan counter changed)
         */
        if ((widgetId < capsense_ADC_TOTAL_WIDGETS)              &&
            (sensorId < capsense_ADC_GET_SENSOR_COUNT(widgetId)) &&
            (ptrDsRam->scanCounter != ptrDsRam->snrTestScanCounter))
        {
            /* Get access to the Sensor Object */
            ptrSnsTmp = capsense_ADC_dsFlash.wdgtArray[widgetId].ptr2SnsRam;
            ptrSnsTmp += sensorId;

            /* Update data in SNR Test Object */
            interruptState = CyEnterCriticalSection();
            ptrDsRam->snrTestScanCounter = ptrDsRam->scanCounter;
            ptrDsRam->snrTestRawCount[0u] = ptrSnsTmp->raw[0u];

            #if (0u != capsense_ADC_MULTI_FREQ_SCAN_EN)
                ptrDsRam->snrTestRawCount[1u] = ptrSnsTmp->raw[1u];
                ptrDsRam->snrTestRawCount[2u] = ptrSnsTmp->raw[2u];
            #endif

            CyExitCriticalSection(interruptState);
        }
    }
    return tunerStatus;
}


/* [] END OF FILE */
