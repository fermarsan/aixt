/*******************************************************************************
* File Name: in1_adc.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_in1_adc_H) /* Pins in1_adc_H */
#define CY_PINS_in1_adc_H

#include "cytypes.h"
#include "cyfitter.h"
#include "in1_adc_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} in1_adc_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   in1_adc_Read(void);
void    in1_adc_Write(uint8 value);
uint8   in1_adc_ReadDataReg(void);
#if defined(in1_adc__PC) || (CY_PSOC4_4200L) 
    void    in1_adc_SetDriveMode(uint8 mode);
#endif
void    in1_adc_SetInterruptMode(uint16 position, uint16 mode);
uint8   in1_adc_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void in1_adc_Sleep(void); 
void in1_adc_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(in1_adc__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define in1_adc_DRIVE_MODE_BITS        (3)
    #define in1_adc_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - in1_adc_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the in1_adc_SetDriveMode() function.
         *  @{
         */
        #define in1_adc_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define in1_adc_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define in1_adc_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define in1_adc_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define in1_adc_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define in1_adc_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define in1_adc_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define in1_adc_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define in1_adc_MASK               in1_adc__MASK
#define in1_adc_SHIFT              in1_adc__SHIFT
#define in1_adc_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in in1_adc_SetInterruptMode() function.
     *  @{
     */
        #define in1_adc_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define in1_adc_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define in1_adc_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define in1_adc_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(in1_adc__SIO)
    #define in1_adc_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(in1_adc__PC) && (CY_PSOC4_4200L)
    #define in1_adc_USBIO_ENABLE               ((uint32)0x80000000u)
    #define in1_adc_USBIO_DISABLE              ((uint32)(~in1_adc_USBIO_ENABLE))
    #define in1_adc_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define in1_adc_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define in1_adc_USBIO_ENTER_SLEEP          ((uint32)((1u << in1_adc_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << in1_adc_USBIO_SUSPEND_DEL_SHIFT)))
    #define in1_adc_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << in1_adc_USBIO_SUSPEND_SHIFT)))
    #define in1_adc_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << in1_adc_USBIO_SUSPEND_DEL_SHIFT)))
    #define in1_adc_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(in1_adc__PC)
    /* Port Configuration */
    #define in1_adc_PC                 (* (reg32 *) in1_adc__PC)
#endif
/* Pin State */
#define in1_adc_PS                     (* (reg32 *) in1_adc__PS)
/* Data Register */
#define in1_adc_DR                     (* (reg32 *) in1_adc__DR)
/* Input Buffer Disable Override */
#define in1_adc_INP_DIS                (* (reg32 *) in1_adc__PC2)

/* Interrupt configuration Registers */
#define in1_adc_INTCFG                 (* (reg32 *) in1_adc__INTCFG)
#define in1_adc_INTSTAT                (* (reg32 *) in1_adc__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define in1_adc_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(in1_adc__SIO)
    #define in1_adc_SIO_REG            (* (reg32 *) in1_adc__SIO)
#endif /* (in1_adc__SIO_CFG) */

/* USBIO registers */
#if !defined(in1_adc__PC) && (CY_PSOC4_4200L)
    #define in1_adc_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define in1_adc_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define in1_adc_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define in1_adc_DRIVE_MODE_SHIFT       (0x00u)
#define in1_adc_DRIVE_MODE_MASK        (0x07u << in1_adc_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins in1_adc_H */


/* [] END OF FILE */
