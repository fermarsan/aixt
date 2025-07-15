/*******************************************************************************
* File Name: LEDPWM.h  
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

#if !defined(CY_PINS_LEDPWM_H) /* Pins LEDPWM_H */
#define CY_PINS_LEDPWM_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LEDPWM_aliases.h"


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
} LEDPWM_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   LEDPWM_Read(void);
void    LEDPWM_Write(uint8 value);
uint8   LEDPWM_ReadDataReg(void);
#if defined(LEDPWM__PC) || (CY_PSOC4_4200L) 
    void    LEDPWM_SetDriveMode(uint8 mode);
#endif
void    LEDPWM_SetInterruptMode(uint16 position, uint16 mode);
uint8   LEDPWM_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void LEDPWM_Sleep(void); 
void LEDPWM_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(LEDPWM__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define LEDPWM_DRIVE_MODE_BITS        (3)
    #define LEDPWM_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LEDPWM_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the LEDPWM_SetDriveMode() function.
         *  @{
         */
        #define LEDPWM_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define LEDPWM_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define LEDPWM_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define LEDPWM_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define LEDPWM_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define LEDPWM_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define LEDPWM_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define LEDPWM_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define LEDPWM_MASK               LEDPWM__MASK
#define LEDPWM_SHIFT              LEDPWM__SHIFT
#define LEDPWM_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LEDPWM_SetInterruptMode() function.
     *  @{
     */
        #define LEDPWM_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define LEDPWM_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define LEDPWM_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define LEDPWM_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(LEDPWM__SIO)
    #define LEDPWM_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(LEDPWM__PC) && (CY_PSOC4_4200L)
    #define LEDPWM_USBIO_ENABLE               ((uint32)0x80000000u)
    #define LEDPWM_USBIO_DISABLE              ((uint32)(~LEDPWM_USBIO_ENABLE))
    #define LEDPWM_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define LEDPWM_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define LEDPWM_USBIO_ENTER_SLEEP          ((uint32)((1u << LEDPWM_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << LEDPWM_USBIO_SUSPEND_DEL_SHIFT)))
    #define LEDPWM_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << LEDPWM_USBIO_SUSPEND_SHIFT)))
    #define LEDPWM_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << LEDPWM_USBIO_SUSPEND_DEL_SHIFT)))
    #define LEDPWM_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(LEDPWM__PC)
    /* Port Configuration */
    #define LEDPWM_PC                 (* (reg32 *) LEDPWM__PC)
#endif
/* Pin State */
#define LEDPWM_PS                     (* (reg32 *) LEDPWM__PS)
/* Data Register */
#define LEDPWM_DR                     (* (reg32 *) LEDPWM__DR)
/* Input Buffer Disable Override */
#define LEDPWM_INP_DIS                (* (reg32 *) LEDPWM__PC2)

/* Interrupt configuration Registers */
#define LEDPWM_INTCFG                 (* (reg32 *) LEDPWM__INTCFG)
#define LEDPWM_INTSTAT                (* (reg32 *) LEDPWM__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define LEDPWM_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(LEDPWM__SIO)
    #define LEDPWM_SIO_REG            (* (reg32 *) LEDPWM__SIO)
#endif /* (LEDPWM__SIO_CFG) */

/* USBIO registers */
#if !defined(LEDPWM__PC) && (CY_PSOC4_4200L)
    #define LEDPWM_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define LEDPWM_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define LEDPWM_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define LEDPWM_DRIVE_MODE_SHIFT       (0x00u)
#define LEDPWM_DRIVE_MODE_MASK        (0x07u << LEDPWM_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins LEDPWM_H */


/* [] END OF FILE */
