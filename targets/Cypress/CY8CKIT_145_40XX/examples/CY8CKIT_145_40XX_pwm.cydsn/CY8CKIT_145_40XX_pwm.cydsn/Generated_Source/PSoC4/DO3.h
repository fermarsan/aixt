/*******************************************************************************
* File Name: DO3.h  
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

#if !defined(CY_PINS_DO3_H) /* Pins DO3_H */
#define CY_PINS_DO3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DO3_aliases.h"


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
} DO3_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DO3_Read(void);
void    DO3_Write(uint8 value);
uint8   DO3_ReadDataReg(void);
#if defined(DO3__PC) || (CY_PSOC4_4200L) 
    void    DO3_SetDriveMode(uint8 mode);
#endif
void    DO3_SetInterruptMode(uint16 position, uint16 mode);
uint8   DO3_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DO3_Sleep(void); 
void DO3_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DO3__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DO3_DRIVE_MODE_BITS        (3)
    #define DO3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DO3_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DO3_SetDriveMode() function.
         *  @{
         */
        #define DO3_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DO3_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DO3_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DO3_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DO3_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DO3_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DO3_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DO3_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DO3_MASK               DO3__MASK
#define DO3_SHIFT              DO3__SHIFT
#define DO3_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DO3_SetInterruptMode() function.
     *  @{
     */
        #define DO3_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DO3_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DO3_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DO3_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DO3__SIO)
    #define DO3_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DO3__PC) && (CY_PSOC4_4200L)
    #define DO3_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DO3_USBIO_DISABLE              ((uint32)(~DO3_USBIO_ENABLE))
    #define DO3_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DO3_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DO3_USBIO_ENTER_SLEEP          ((uint32)((1u << DO3_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DO3_USBIO_SUSPEND_DEL_SHIFT)))
    #define DO3_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DO3_USBIO_SUSPEND_SHIFT)))
    #define DO3_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DO3_USBIO_SUSPEND_DEL_SHIFT)))
    #define DO3_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DO3__PC)
    /* Port Configuration */
    #define DO3_PC                 (* (reg32 *) DO3__PC)
#endif
/* Pin State */
#define DO3_PS                     (* (reg32 *) DO3__PS)
/* Data Register */
#define DO3_DR                     (* (reg32 *) DO3__DR)
/* Input Buffer Disable Override */
#define DO3_INP_DIS                (* (reg32 *) DO3__PC2)

/* Interrupt configuration Registers */
#define DO3_INTCFG                 (* (reg32 *) DO3__INTCFG)
#define DO3_INTSTAT                (* (reg32 *) DO3__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DO3_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DO3__SIO)
    #define DO3_SIO_REG            (* (reg32 *) DO3__SIO)
#endif /* (DO3__SIO_CFG) */

/* USBIO registers */
#if !defined(DO3__PC) && (CY_PSOC4_4200L)
    #define DO3_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DO3_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DO3_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DO3_DRIVE_MODE_SHIFT       (0x00u)
#define DO3_DRIVE_MODE_MASK        (0x07u << DO3_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DO3_H */


/* [] END OF FILE */
