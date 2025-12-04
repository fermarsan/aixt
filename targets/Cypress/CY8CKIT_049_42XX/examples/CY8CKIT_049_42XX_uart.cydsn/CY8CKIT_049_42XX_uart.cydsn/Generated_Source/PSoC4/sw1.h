/*******************************************************************************
* File Name: sw1.h  
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

#if !defined(CY_PINS_sw1_H) /* Pins sw1_H */
#define CY_PINS_sw1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "sw1_aliases.h"


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
} sw1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   sw1_Read(void);
void    sw1_Write(uint8 value);
uint8   sw1_ReadDataReg(void);
#if defined(sw1__PC) || (CY_PSOC4_4200L) 
    void    sw1_SetDriveMode(uint8 mode);
#endif
void    sw1_SetInterruptMode(uint16 position, uint16 mode);
uint8   sw1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void sw1_Sleep(void); 
void sw1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(sw1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define sw1_DRIVE_MODE_BITS        (3)
    #define sw1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - sw1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the sw1_SetDriveMode() function.
         *  @{
         */
        #define sw1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define sw1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define sw1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define sw1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define sw1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define sw1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define sw1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define sw1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define sw1_MASK               sw1__MASK
#define sw1_SHIFT              sw1__SHIFT
#define sw1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sw1_SetInterruptMode() function.
     *  @{
     */
        #define sw1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define sw1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define sw1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define sw1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(sw1__SIO)
    #define sw1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(sw1__PC) && (CY_PSOC4_4200L)
    #define sw1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define sw1_USBIO_DISABLE              ((uint32)(~sw1_USBIO_ENABLE))
    #define sw1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define sw1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define sw1_USBIO_ENTER_SLEEP          ((uint32)((1u << sw1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << sw1_USBIO_SUSPEND_DEL_SHIFT)))
    #define sw1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << sw1_USBIO_SUSPEND_SHIFT)))
    #define sw1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << sw1_USBIO_SUSPEND_DEL_SHIFT)))
    #define sw1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(sw1__PC)
    /* Port Configuration */
    #define sw1_PC                 (* (reg32 *) sw1__PC)
#endif
/* Pin State */
#define sw1_PS                     (* (reg32 *) sw1__PS)
/* Data Register */
#define sw1_DR                     (* (reg32 *) sw1__DR)
/* Input Buffer Disable Override */
#define sw1_INP_DIS                (* (reg32 *) sw1__PC2)

/* Interrupt configuration Registers */
#define sw1_INTCFG                 (* (reg32 *) sw1__INTCFG)
#define sw1_INTSTAT                (* (reg32 *) sw1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define sw1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(sw1__SIO)
    #define sw1_SIO_REG            (* (reg32 *) sw1__SIO)
#endif /* (sw1__SIO_CFG) */

/* USBIO registers */
#if !defined(sw1__PC) && (CY_PSOC4_4200L)
    #define sw1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define sw1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define sw1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define sw1_DRIVE_MODE_SHIFT       (0x00u)
#define sw1_DRIVE_MODE_MASK        (0x07u << sw1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins sw1_H */


/* [] END OF FILE */
