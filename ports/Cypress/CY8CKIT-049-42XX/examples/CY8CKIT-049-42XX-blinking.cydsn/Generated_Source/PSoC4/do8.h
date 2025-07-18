/*******************************************************************************
* File Name: do8.h  
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

#if !defined(CY_PINS_do8_H) /* Pins do8_H */
#define CY_PINS_do8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "do8_aliases.h"


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
} do8_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   do8_Read(void);
void    do8_Write(uint8 value);
uint8   do8_ReadDataReg(void);
#if defined(do8__PC) || (CY_PSOC4_4200L) 
    void    do8_SetDriveMode(uint8 mode);
#endif
void    do8_SetInterruptMode(uint16 position, uint16 mode);
uint8   do8_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void do8_Sleep(void); 
void do8_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(do8__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define do8_DRIVE_MODE_BITS        (3)
    #define do8_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - do8_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the do8_SetDriveMode() function.
         *  @{
         */
        #define do8_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define do8_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define do8_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define do8_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define do8_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define do8_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define do8_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define do8_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define do8_MASK               do8__MASK
#define do8_SHIFT              do8__SHIFT
#define do8_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in do8_SetInterruptMode() function.
     *  @{
     */
        #define do8_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define do8_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define do8_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define do8_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(do8__SIO)
    #define do8_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(do8__PC) && (CY_PSOC4_4200L)
    #define do8_USBIO_ENABLE               ((uint32)0x80000000u)
    #define do8_USBIO_DISABLE              ((uint32)(~do8_USBIO_ENABLE))
    #define do8_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define do8_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define do8_USBIO_ENTER_SLEEP          ((uint32)((1u << do8_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << do8_USBIO_SUSPEND_DEL_SHIFT)))
    #define do8_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << do8_USBIO_SUSPEND_SHIFT)))
    #define do8_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << do8_USBIO_SUSPEND_DEL_SHIFT)))
    #define do8_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(do8__PC)
    /* Port Configuration */
    #define do8_PC                 (* (reg32 *) do8__PC)
#endif
/* Pin State */
#define do8_PS                     (* (reg32 *) do8__PS)
/* Data Register */
#define do8_DR                     (* (reg32 *) do8__DR)
/* Input Buffer Disable Override */
#define do8_INP_DIS                (* (reg32 *) do8__PC2)

/* Interrupt configuration Registers */
#define do8_INTCFG                 (* (reg32 *) do8__INTCFG)
#define do8_INTSTAT                (* (reg32 *) do8__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define do8_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(do8__SIO)
    #define do8_SIO_REG            (* (reg32 *) do8__SIO)
#endif /* (do8__SIO_CFG) */

/* USBIO registers */
#if !defined(do8__PC) && (CY_PSOC4_4200L)
    #define do8_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define do8_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define do8_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define do8_DRIVE_MODE_SHIFT       (0x00u)
#define do8_DRIVE_MODE_MASK        (0x07u << do8_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins do8_H */


/* [] END OF FILE */
