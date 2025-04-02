/*******************************************************************************
* File Name: di8.h  
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

#if !defined(CY_PINS_di8_H) /* Pins di8_H */
#define CY_PINS_di8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "di8_aliases.h"


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
} di8_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   di8_Read(void);
void    di8_Write(uint8 value);
uint8   di8_ReadDataReg(void);
#if defined(di8__PC) || (CY_PSOC4_4200L) 
    void    di8_SetDriveMode(uint8 mode);
#endif
void    di8_SetInterruptMode(uint16 position, uint16 mode);
uint8   di8_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void di8_Sleep(void); 
void di8_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(di8__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define di8_DRIVE_MODE_BITS        (3)
    #define di8_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - di8_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the di8_SetDriveMode() function.
         *  @{
         */
        #define di8_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define di8_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define di8_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define di8_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define di8_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define di8_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define di8_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define di8_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define di8_MASK               di8__MASK
#define di8_SHIFT              di8__SHIFT
#define di8_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in di8_SetInterruptMode() function.
     *  @{
     */
        #define di8_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define di8_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define di8_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define di8_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(di8__SIO)
    #define di8_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(di8__PC) && (CY_PSOC4_4200L)
    #define di8_USBIO_ENABLE               ((uint32)0x80000000u)
    #define di8_USBIO_DISABLE              ((uint32)(~di8_USBIO_ENABLE))
    #define di8_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define di8_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define di8_USBIO_ENTER_SLEEP          ((uint32)((1u << di8_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << di8_USBIO_SUSPEND_DEL_SHIFT)))
    #define di8_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << di8_USBIO_SUSPEND_SHIFT)))
    #define di8_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << di8_USBIO_SUSPEND_DEL_SHIFT)))
    #define di8_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(di8__PC)
    /* Port Configuration */
    #define di8_PC                 (* (reg32 *) di8__PC)
#endif
/* Pin State */
#define di8_PS                     (* (reg32 *) di8__PS)
/* Data Register */
#define di8_DR                     (* (reg32 *) di8__DR)
/* Input Buffer Disable Override */
#define di8_INP_DIS                (* (reg32 *) di8__PC2)

/* Interrupt configuration Registers */
#define di8_INTCFG                 (* (reg32 *) di8__INTCFG)
#define di8_INTSTAT                (* (reg32 *) di8__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define di8_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(di8__SIO)
    #define di8_SIO_REG            (* (reg32 *) di8__SIO)
#endif /* (di8__SIO_CFG) */

/* USBIO registers */
#if !defined(di8__PC) && (CY_PSOC4_4200L)
    #define di8_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define di8_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define di8_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define di8_DRIVE_MODE_SHIFT       (0x00u)
#define di8_DRIVE_MODE_MASK        (0x07u << di8_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins di8_H */


/* [] END OF FILE */
