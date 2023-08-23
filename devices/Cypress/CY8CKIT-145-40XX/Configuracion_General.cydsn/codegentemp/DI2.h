/*******************************************************************************
* File Name: DI2.h  
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

#if !defined(CY_PINS_DI2_H) /* Pins DI2_H */
#define CY_PINS_DI2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "DI2_aliases.h"


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
} DI2_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   DI2_Read(void);
void    DI2_Write(uint8 value);
uint8   DI2_ReadDataReg(void);
#if defined(DI2__PC) || (CY_PSOC4_4200L) 
    void    DI2_SetDriveMode(uint8 mode);
#endif
void    DI2_SetInterruptMode(uint16 position, uint16 mode);
uint8   DI2_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void DI2_Sleep(void); 
void DI2_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(DI2__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define DI2_DRIVE_MODE_BITS        (3)
    #define DI2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - DI2_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the DI2_SetDriveMode() function.
         *  @{
         */
        #define DI2_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define DI2_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define DI2_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define DI2_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define DI2_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define DI2_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define DI2_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define DI2_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define DI2_MASK               DI2__MASK
#define DI2_SHIFT              DI2__SHIFT
#define DI2_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DI2_SetInterruptMode() function.
     *  @{
     */
        #define DI2_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define DI2_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define DI2_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define DI2_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(DI2__SIO)
    #define DI2_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(DI2__PC) && (CY_PSOC4_4200L)
    #define DI2_USBIO_ENABLE               ((uint32)0x80000000u)
    #define DI2_USBIO_DISABLE              ((uint32)(~DI2_USBIO_ENABLE))
    #define DI2_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define DI2_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define DI2_USBIO_ENTER_SLEEP          ((uint32)((1u << DI2_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << DI2_USBIO_SUSPEND_DEL_SHIFT)))
    #define DI2_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << DI2_USBIO_SUSPEND_SHIFT)))
    #define DI2_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << DI2_USBIO_SUSPEND_DEL_SHIFT)))
    #define DI2_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(DI2__PC)
    /* Port Configuration */
    #define DI2_PC                 (* (reg32 *) DI2__PC)
#endif
/* Pin State */
#define DI2_PS                     (* (reg32 *) DI2__PS)
/* Data Register */
#define DI2_DR                     (* (reg32 *) DI2__DR)
/* Input Buffer Disable Override */
#define DI2_INP_DIS                (* (reg32 *) DI2__PC2)

/* Interrupt configuration Registers */
#define DI2_INTCFG                 (* (reg32 *) DI2__INTCFG)
#define DI2_INTSTAT                (* (reg32 *) DI2__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define DI2_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(DI2__SIO)
    #define DI2_SIO_REG            (* (reg32 *) DI2__SIO)
#endif /* (DI2__SIO_CFG) */

/* USBIO registers */
#if !defined(DI2__PC) && (CY_PSOC4_4200L)
    #define DI2_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define DI2_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define DI2_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define DI2_DRIVE_MODE_SHIFT       (0x00u)
#define DI2_DRIVE_MODE_MASK        (0x07u << DI2_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins DI2_H */


/* [] END OF FILE */
