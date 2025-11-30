/*******************************************************************************
* File Name: di2.h  
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

#if !defined(CY_PINS_di2_H) /* Pins di2_H */
#define CY_PINS_di2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "di2_aliases.h"


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
} di2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   di2_Read(void);
void    di2_Write(uint8 value);
uint8   di2_ReadDataReg(void);
#if defined(di2__PC) || (CY_PSOC4_4200L) 
    void    di2_SetDriveMode(uint8 mode);
#endif
void    di2_SetInterruptMode(uint16 position, uint16 mode);
uint8   di2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void di2_Sleep(void); 
void di2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(di2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define di2_DRIVE_MODE_BITS        (3)
    #define di2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - di2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the di2_SetDriveMode() function.
         *  @{
         */
        #define di2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define di2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define di2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define di2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define di2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define di2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define di2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define di2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define di2_MASK               di2__MASK
#define di2_SHIFT              di2__SHIFT
#define di2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in di2_SetInterruptMode() function.
     *  @{
     */
        #define di2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define di2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define di2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define di2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(di2__SIO)
    #define di2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(di2__PC) && (CY_PSOC4_4200L)
    #define di2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define di2_USBIO_DISABLE              ((uint32)(~di2_USBIO_ENABLE))
    #define di2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define di2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define di2_USBIO_ENTER_SLEEP          ((uint32)((1u << di2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << di2_USBIO_SUSPEND_DEL_SHIFT)))
    #define di2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << di2_USBIO_SUSPEND_SHIFT)))
    #define di2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << di2_USBIO_SUSPEND_DEL_SHIFT)))
    #define di2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(di2__PC)
    /* Port Configuration */
    #define di2_PC                 (* (reg32 *) di2__PC)
#endif
/* Pin State */
#define di2_PS                     (* (reg32 *) di2__PS)
/* Data Register */
#define di2_DR                     (* (reg32 *) di2__DR)
/* Input Buffer Disable Override */
#define di2_INP_DIS                (* (reg32 *) di2__PC2)

/* Interrupt configuration Registers */
#define di2_INTCFG                 (* (reg32 *) di2__INTCFG)
#define di2_INTSTAT                (* (reg32 *) di2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define di2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(di2__SIO)
    #define di2_SIO_REG            (* (reg32 *) di2__SIO)
#endif /* (di2__SIO_CFG) */

/* USBIO registers */
#if !defined(di2__PC) && (CY_PSOC4_4200L)
    #define di2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define di2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define di2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define di2_DRIVE_MODE_SHIFT       (0x00u)
#define di2_DRIVE_MODE_MASK        (0x07u << di2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins di2_H */


/* [] END OF FILE */
