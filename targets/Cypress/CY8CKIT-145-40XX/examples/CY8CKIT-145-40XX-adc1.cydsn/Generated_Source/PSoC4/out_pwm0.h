/*******************************************************************************
* File Name: out_pwm0.h  
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

#if !defined(CY_PINS_out_pwm0_H) /* Pins out_pwm0_H */
#define CY_PINS_out_pwm0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "out_pwm0_aliases.h"


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
} out_pwm0_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   out_pwm0_Read(void);
void    out_pwm0_Write(uint8 value);
uint8   out_pwm0_ReadDataReg(void);
#if defined(out_pwm0__PC) || (CY_PSOC4_4200L) 
    void    out_pwm0_SetDriveMode(uint8 mode);
#endif
void    out_pwm0_SetInterruptMode(uint16 position, uint16 mode);
uint8   out_pwm0_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void out_pwm0_Sleep(void); 
void out_pwm0_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(out_pwm0__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define out_pwm0_DRIVE_MODE_BITS        (3)
    #define out_pwm0_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - out_pwm0_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the out_pwm0_SetDriveMode() function.
         *  @{
         */
        #define out_pwm0_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define out_pwm0_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define out_pwm0_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define out_pwm0_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define out_pwm0_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define out_pwm0_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define out_pwm0_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define out_pwm0_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define out_pwm0_MASK               out_pwm0__MASK
#define out_pwm0_SHIFT              out_pwm0__SHIFT
#define out_pwm0_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in out_pwm0_SetInterruptMode() function.
     *  @{
     */
        #define out_pwm0_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define out_pwm0_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define out_pwm0_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define out_pwm0_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(out_pwm0__SIO)
    #define out_pwm0_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(out_pwm0__PC) && (CY_PSOC4_4200L)
    #define out_pwm0_USBIO_ENABLE               ((uint32)0x80000000u)
    #define out_pwm0_USBIO_DISABLE              ((uint32)(~out_pwm0_USBIO_ENABLE))
    #define out_pwm0_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define out_pwm0_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define out_pwm0_USBIO_ENTER_SLEEP          ((uint32)((1u << out_pwm0_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << out_pwm0_USBIO_SUSPEND_DEL_SHIFT)))
    #define out_pwm0_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << out_pwm0_USBIO_SUSPEND_SHIFT)))
    #define out_pwm0_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << out_pwm0_USBIO_SUSPEND_DEL_SHIFT)))
    #define out_pwm0_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(out_pwm0__PC)
    /* Port Configuration */
    #define out_pwm0_PC                 (* (reg32 *) out_pwm0__PC)
#endif
/* Pin State */
#define out_pwm0_PS                     (* (reg32 *) out_pwm0__PS)
/* Data Register */
#define out_pwm0_DR                     (* (reg32 *) out_pwm0__DR)
/* Input Buffer Disable Override */
#define out_pwm0_INP_DIS                (* (reg32 *) out_pwm0__PC2)

/* Interrupt configuration Registers */
#define out_pwm0_INTCFG                 (* (reg32 *) out_pwm0__INTCFG)
#define out_pwm0_INTSTAT                (* (reg32 *) out_pwm0__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define out_pwm0_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(out_pwm0__SIO)
    #define out_pwm0_SIO_REG            (* (reg32 *) out_pwm0__SIO)
#endif /* (out_pwm0__SIO_CFG) */

/* USBIO registers */
#if !defined(out_pwm0__PC) && (CY_PSOC4_4200L)
    #define out_pwm0_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define out_pwm0_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define out_pwm0_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define out_pwm0_DRIVE_MODE_SHIFT       (0x00u)
#define out_pwm0_DRIVE_MODE_MASK        (0x07u << out_pwm0_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins out_pwm0_H */


/* [] END OF FILE */
