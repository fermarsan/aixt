/*******************************************************************************
* File Name: pwm_1.h  
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

#if !defined(CY_PINS_pwm_1_H) /* Pins pwm_1_H */
#define CY_PINS_pwm_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pwm_1_aliases.h"


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
} pwm_1_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   pwm_1_Read(void);
void    pwm_1_Write(uint8 value);
uint8   pwm_1_ReadDataReg(void);
#if defined(pwm_1__PC) || (CY_PSOC4_4200L) 
    void    pwm_1_SetDriveMode(uint8 mode);
#endif
void    pwm_1_SetInterruptMode(uint16 position, uint16 mode);
uint8   pwm_1_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void pwm_1_Sleep(void); 
void pwm_1_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(pwm_1__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define pwm_1_DRIVE_MODE_BITS        (3)
    #define pwm_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pwm_1_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the pwm_1_SetDriveMode() function.
         *  @{
         */
        #define pwm_1_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define pwm_1_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define pwm_1_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define pwm_1_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define pwm_1_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define pwm_1_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define pwm_1_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define pwm_1_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define pwm_1_MASK               pwm_1__MASK
#define pwm_1_SHIFT              pwm_1__SHIFT
#define pwm_1_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pwm_1_SetInterruptMode() function.
     *  @{
     */
        #define pwm_1_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define pwm_1_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define pwm_1_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define pwm_1_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(pwm_1__SIO)
    #define pwm_1_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(pwm_1__PC) && (CY_PSOC4_4200L)
    #define pwm_1_USBIO_ENABLE               ((uint32)0x80000000u)
    #define pwm_1_USBIO_DISABLE              ((uint32)(~pwm_1_USBIO_ENABLE))
    #define pwm_1_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define pwm_1_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define pwm_1_USBIO_ENTER_SLEEP          ((uint32)((1u << pwm_1_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << pwm_1_USBIO_SUSPEND_DEL_SHIFT)))
    #define pwm_1_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << pwm_1_USBIO_SUSPEND_SHIFT)))
    #define pwm_1_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << pwm_1_USBIO_SUSPEND_DEL_SHIFT)))
    #define pwm_1_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(pwm_1__PC)
    /* Port Configuration */
    #define pwm_1_PC                 (* (reg32 *) pwm_1__PC)
#endif
/* Pin State */
#define pwm_1_PS                     (* (reg32 *) pwm_1__PS)
/* Data Register */
#define pwm_1_DR                     (* (reg32 *) pwm_1__DR)
/* Input Buffer Disable Override */
#define pwm_1_INP_DIS                (* (reg32 *) pwm_1__PC2)

/* Interrupt configuration Registers */
#define pwm_1_INTCFG                 (* (reg32 *) pwm_1__INTCFG)
#define pwm_1_INTSTAT                (* (reg32 *) pwm_1__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define pwm_1_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(pwm_1__SIO)
    #define pwm_1_SIO_REG            (* (reg32 *) pwm_1__SIO)
#endif /* (pwm_1__SIO_CFG) */

/* USBIO registers */
#if !defined(pwm_1__PC) && (CY_PSOC4_4200L)
    #define pwm_1_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define pwm_1_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define pwm_1_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define pwm_1_DRIVE_MODE_SHIFT       (0x00u)
#define pwm_1_DRIVE_MODE_MASK        (0x07u << pwm_1_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins pwm_1_H */


/* [] END OF FILE */
