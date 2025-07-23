/*******************************************************************************
* File Name: led8.h  
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

#if !defined(CY_PINS_led8_H) /* Pins led8_H */
#define CY_PINS_led8_H

#include "cytypes.h"
#include "cyfitter.h"
#include "led8_aliases.h"


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
} led8_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   led8_Read(void);
void    led8_Write(uint8 value);
uint8   led8_ReadDataReg(void);
#if defined(led8__PC) || (CY_PSOC4_4200L) 
    void    led8_SetDriveMode(uint8 mode);
#endif
void    led8_SetInterruptMode(uint16 position, uint16 mode);
uint8   led8_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void led8_Sleep(void); 
void led8_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(led8__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define led8_DRIVE_MODE_BITS        (3)
    #define led8_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - led8_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the led8_SetDriveMode() function.
         *  @{
         */
        #define led8_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define led8_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define led8_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define led8_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define led8_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define led8_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define led8_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define led8_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define led8_MASK               led8__MASK
#define led8_SHIFT              led8__SHIFT
#define led8_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in led8_SetInterruptMode() function.
     *  @{
     */
        #define led8_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define led8_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define led8_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define led8_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(led8__SIO)
    #define led8_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(led8__PC) && (CY_PSOC4_4200L)
    #define led8_USBIO_ENABLE               ((uint32)0x80000000u)
    #define led8_USBIO_DISABLE              ((uint32)(~led8_USBIO_ENABLE))
    #define led8_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define led8_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define led8_USBIO_ENTER_SLEEP          ((uint32)((1u << led8_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << led8_USBIO_SUSPEND_DEL_SHIFT)))
    #define led8_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << led8_USBIO_SUSPEND_SHIFT)))
    #define led8_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << led8_USBIO_SUSPEND_DEL_SHIFT)))
    #define led8_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(led8__PC)
    /* Port Configuration */
    #define led8_PC                 (* (reg32 *) led8__PC)
#endif
/* Pin State */
#define led8_PS                     (* (reg32 *) led8__PS)
/* Data Register */
#define led8_DR                     (* (reg32 *) led8__DR)
/* Input Buffer Disable Override */
#define led8_INP_DIS                (* (reg32 *) led8__PC2)

/* Interrupt configuration Registers */
#define led8_INTCFG                 (* (reg32 *) led8__INTCFG)
#define led8_INTSTAT                (* (reg32 *) led8__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define led8_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(led8__SIO)
    #define led8_SIO_REG            (* (reg32 *) led8__SIO)
#endif /* (led8__SIO_CFG) */

/* USBIO registers */
#if !defined(led8__PC) && (CY_PSOC4_4200L)
    #define led8_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define led8_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define led8_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define led8_DRIVE_MODE_SHIFT       (0x00u)
#define led8_DRIVE_MODE_MASK        (0x07u << led8_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins led8_H */


/* [] END OF FILE */
