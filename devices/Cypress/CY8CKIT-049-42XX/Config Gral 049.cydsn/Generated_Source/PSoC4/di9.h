/*******************************************************************************
* File Name: di9.h  
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

#if !defined(CY_PINS_di9_H) /* Pins di9_H */
#define CY_PINS_di9_H

#include "cytypes.h"
#include "cyfitter.h"
#include "di9_aliases.h"


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
} di9_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   di9_Read(void);
void    di9_Write(uint8 value);
uint8   di9_ReadDataReg(void);
#if defined(di9__PC) || (CY_PSOC4_4200L) 
    void    di9_SetDriveMode(uint8 mode);
#endif
void    di9_SetInterruptMode(uint16 position, uint16 mode);
uint8   di9_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void di9_Sleep(void); 
void di9_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(di9__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define di9_DRIVE_MODE_BITS        (3)
    #define di9_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - di9_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the di9_SetDriveMode() function.
         *  @{
         */
        #define di9_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define di9_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define di9_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define di9_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define di9_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define di9_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define di9_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define di9_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define di9_MASK               di9__MASK
#define di9_SHIFT              di9__SHIFT
#define di9_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in di9_SetInterruptMode() function.
     *  @{
     */
        #define di9_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define di9_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define di9_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define di9_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(di9__SIO)
    #define di9_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(di9__PC) && (CY_PSOC4_4200L)
    #define di9_USBIO_ENABLE               ((uint32)0x80000000u)
    #define di9_USBIO_DISABLE              ((uint32)(~di9_USBIO_ENABLE))
    #define di9_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define di9_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define di9_USBIO_ENTER_SLEEP          ((uint32)((1u << di9_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << di9_USBIO_SUSPEND_DEL_SHIFT)))
    #define di9_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << di9_USBIO_SUSPEND_SHIFT)))
    #define di9_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << di9_USBIO_SUSPEND_DEL_SHIFT)))
    #define di9_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(di9__PC)
    /* Port Configuration */
    #define di9_PC                 (* (reg32 *) di9__PC)
#endif
/* Pin State */
#define di9_PS                     (* (reg32 *) di9__PS)
/* Data Register */
#define di9_DR                     (* (reg32 *) di9__DR)
/* Input Buffer Disable Override */
#define di9_INP_DIS                (* (reg32 *) di9__PC2)

/* Interrupt configuration Registers */
#define di9_INTCFG                 (* (reg32 *) di9__INTCFG)
#define di9_INTSTAT                (* (reg32 *) di9__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define di9_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(di9__SIO)
    #define di9_SIO_REG            (* (reg32 *) di9__SIO)
#endif /* (di9__SIO_CFG) */

/* USBIO registers */
#if !defined(di9__PC) && (CY_PSOC4_4200L)
    #define di9_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define di9_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define di9_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define di9_DRIVE_MODE_SHIFT       (0x00u)
#define di9_DRIVE_MODE_MASK        (0x07u << di9_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins di9_H */


/* [] END OF FILE */
