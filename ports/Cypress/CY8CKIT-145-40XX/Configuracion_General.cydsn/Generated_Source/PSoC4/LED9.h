/*******************************************************************************
* File Name: led9.h  
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

#if !defined(CY_PINS_led9_H) /* Pins led9_H */
#define CY_PINS_led9_H

#include "cytypes.h"
#include "cyfitter.h"
#include "led9_aliases.h"


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
} led9_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   led9_Read(void);
void    led9_Write(uint8 value);
uint8   led9_ReadDataReg(void);
#if defined(led9__PC) || (CY_PSOC4_4200L) 
    void    led9_SetDriveMode(uint8 mode);
#endif
void    led9_SetInterruptMode(uint16 position, uint16 mode);
uint8   led9_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void led9_Sleep(void); 
void led9_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(led9__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define led9_DRIVE_MODE_BITS        (3)
    #define led9_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - led9_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the led9_SetDriveMode() function.
         *  @{
         */
        #define led9_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define led9_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define led9_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define led9_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define led9_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define led9_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define led9_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define led9_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define led9_MASK               led9__MASK
#define led9_SHIFT              led9__SHIFT
#define led9_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in led9_SetInterruptMode() function.
     *  @{
     */
        #define led9_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define led9_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define led9_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define led9_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(led9__SIO)
    #define led9_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(led9__PC) && (CY_PSOC4_4200L)
    #define led9_USBIO_ENABLE               ((uint32)0x80000000u)
    #define led9_USBIO_DISABLE              ((uint32)(~led9_USBIO_ENABLE))
    #define led9_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define led9_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define led9_USBIO_ENTER_SLEEP          ((uint32)((1u << led9_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << led9_USBIO_SUSPEND_DEL_SHIFT)))
    #define led9_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << led9_USBIO_SUSPEND_SHIFT)))
    #define led9_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << led9_USBIO_SUSPEND_DEL_SHIFT)))
    #define led9_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(led9__PC)
    /* Port Configuration */
    #define led9_PC                 (* (reg32 *) led9__PC)
#endif
/* Pin State */
#define led9_PS                     (* (reg32 *) led9__PS)
/* Data Register */
#define led9_DR                     (* (reg32 *) led9__DR)
/* Input Buffer Disable Override */
#define led9_INP_DIS                (* (reg32 *) led9__PC2)

/* Interrupt configuration Registers */
#define led9_INTCFG                 (* (reg32 *) led9__INTCFG)
#define led9_INTSTAT                (* (reg32 *) led9__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define led9_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(led9__SIO)
    #define led9_SIO_REG            (* (reg32 *) led9__SIO)
#endif /* (led9__SIO_CFG) */

/* USBIO registers */
#if !defined(led9__PC) && (CY_PSOC4_4200L)
    #define led9_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define led9_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define led9_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define led9_DRIVE_MODE_SHIFT       (0x00u)
#define led9_DRIVE_MODE_MASK        (0x07u << led9_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins led9_H */


/* [] END OF FILE */
