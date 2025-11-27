/*******************************************************************************
* File Name: pwm_3.h  
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

#if !defined(CY_PINS_pwm_3_H) /* Pins pwm_3_H */
#define CY_PINS_pwm_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "pwm_3_aliases.h"


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
} pwm_3_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   pwm_3_Read(void);
void    pwm_3_Write(uint8 value);
uint8   pwm_3_ReadDataReg(void);
#if defined(pwm_3__PC) || (CY_PSOC4_4200L) 
    void    pwm_3_SetDriveMode(uint8 mode);
#endif
void    pwm_3_SetInterruptMode(uint16 position, uint16 mode);
uint8   pwm_3_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void pwm_3_Sleep(void); 
void pwm_3_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(pwm_3__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define pwm_3_DRIVE_MODE_BITS        (3)
    #define pwm_3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - pwm_3_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the pwm_3_SetDriveMode() function.
         *  @{
         */
        #define pwm_3_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define pwm_3_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define pwm_3_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define pwm_3_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define pwm_3_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define pwm_3_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define pwm_3_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define pwm_3_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define pwm_3_MASK               pwm_3__MASK
#define pwm_3_SHIFT              pwm_3__SHIFT
#define pwm_3_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pwm_3_SetInterruptMode() function.
     *  @{
     */
        #define pwm_3_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define pwm_3_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define pwm_3_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define pwm_3_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(pwm_3__SIO)
    #define pwm_3_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(pwm_3__PC) && (CY_PSOC4_4200L)
    #define pwm_3_USBIO_ENABLE               ((uint32)0x80000000u)
    #define pwm_3_USBIO_DISABLE              ((uint32)(~pwm_3_USBIO_ENABLE))
    #define pwm_3_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define pwm_3_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define pwm_3_USBIO_ENTER_SLEEP          ((uint32)((1u << pwm_3_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << pwm_3_USBIO_SUSPEND_DEL_SHIFT)))
    #define pwm_3_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << pwm_3_USBIO_SUSPEND_SHIFT)))
    #define pwm_3_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << pwm_3_USBIO_SUSPEND_DEL_SHIFT)))
    #define pwm_3_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(pwm_3__PC)
    /* Port Configuration */
    #define pwm_3_PC                 (* (reg32 *) pwm_3__PC)
#endif
/* Pin State */
#define pwm_3_PS                     (* (reg32 *) pwm_3__PS)
/* Data Register */
#define pwm_3_DR                     (* (reg32 *) pwm_3__DR)
/* Input Buffer Disable Override */
#define pwm_3_INP_DIS                (* (reg32 *) pwm_3__PC2)

/* Interrupt configuration Registers */
#define pwm_3_INTCFG                 (* (reg32 *) pwm_3__INTCFG)
#define pwm_3_INTSTAT                (* (reg32 *) pwm_3__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define pwm_3_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(pwm_3__SIO)
    #define pwm_3_SIO_REG            (* (reg32 *) pwm_3__SIO)
#endif /* (pwm_3__SIO_CFG) */

/* USBIO registers */
#if !defined(pwm_3__PC) && (CY_PSOC4_4200L)
    #define pwm_3_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define pwm_3_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define pwm_3_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define pwm_3_DRIVE_MODE_SHIFT       (0x00u)
#define pwm_3_DRIVE_MODE_MASK        (0x07u << pwm_3_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins pwm_3_H */


/* [] END OF FILE */
