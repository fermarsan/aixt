/*******************************************************************************
* File Name: do7.h  
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

#if !defined(CY_PINS_do7_H) /* Pins do7_H */
#define CY_PINS_do7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "do7_aliases.h"


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
} do7_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   do7_Read(void);
void    do7_Write(uint8 value);
uint8   do7_ReadDataReg(void);
#if defined(do7__PC) || (CY_PSOC4_4200L) 
    void    do7_SetDriveMode(uint8 mode);
#endif
void    do7_SetInterruptMode(uint16 position, uint16 mode);
uint8   do7_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void do7_Sleep(void); 
void do7_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(do7__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define do7_DRIVE_MODE_BITS        (3)
    #define do7_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - do7_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the do7_SetDriveMode() function.
         *  @{
         */
        #define do7_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define do7_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define do7_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define do7_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define do7_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define do7_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define do7_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define do7_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define do7_MASK               do7__MASK
#define do7_SHIFT              do7__SHIFT
#define do7_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in do7_SetInterruptMode() function.
     *  @{
     */
        #define do7_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define do7_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define do7_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define do7_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(do7__SIO)
    #define do7_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(do7__PC) && (CY_PSOC4_4200L)
    #define do7_USBIO_ENABLE               ((uint32)0x80000000u)
    #define do7_USBIO_DISABLE              ((uint32)(~do7_USBIO_ENABLE))
    #define do7_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define do7_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define do7_USBIO_ENTER_SLEEP          ((uint32)((1u << do7_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << do7_USBIO_SUSPEND_DEL_SHIFT)))
    #define do7_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << do7_USBIO_SUSPEND_SHIFT)))
    #define do7_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << do7_USBIO_SUSPEND_DEL_SHIFT)))
    #define do7_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(do7__PC)
    /* Port Configuration */
    #define do7_PC                 (* (reg32 *) do7__PC)
#endif
/* Pin State */
#define do7_PS                     (* (reg32 *) do7__PS)
/* Data Register */
#define do7_DR                     (* (reg32 *) do7__DR)
/* Input Buffer Disable Override */
#define do7_INP_DIS                (* (reg32 *) do7__PC2)

/* Interrupt configuration Registers */
#define do7_INTCFG                 (* (reg32 *) do7__INTCFG)
#define do7_INTSTAT                (* (reg32 *) do7__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define do7_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(do7__SIO)
    #define do7_SIO_REG            (* (reg32 *) do7__SIO)
#endif /* (do7__SIO_CFG) */

/* USBIO registers */
#if !defined(do7__PC) && (CY_PSOC4_4200L)
    #define do7_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define do7_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define do7_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define do7_DRIVE_MODE_SHIFT       (0x00u)
#define do7_DRIVE_MODE_MASK        (0x07u << do7_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins do7_H */


/* [] END OF FILE */
