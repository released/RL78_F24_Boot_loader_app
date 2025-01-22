/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_iica.h
* Version          : 1.0.30
* Device(s)        : R7F124FPJ5xFB
* Description      : General header file for IICA peripheral.
***********************************************************************************************************************/

#ifndef IICA_H
#define IICA_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of serial interface IICA0 input clock supply (IICA0EN) */
#define _00_IICA0_CLOCK_STOP             (0x00U)    /* stops supply of input clock */
#define _10_IICA0_CLOCK_SUPPLY           (0x10U)    /* enables input clock supply */
    
/*  
    IICA Control Register 00 (IICCTL00)
*/
/* IIC operation enable (IICE0) */
#define _00_IICA_OPERATION_DISABLE       (0x00U)    /* stop operation. reset the IICA status register 0 (IICS0).
                                                       stop internal operation */
#define _80_IICA_OPERATION_ENABLE        (0x80U)    /* enable operation */
/* Exit from communications (LREL0) */
#define _00_IICA_COMMUNICATION_NORMAL    (0x00U)    /* normal operation */
#define _40_IICA_COMMUNICATION_EXIT      (0x40U)    /* exit from current communications and sets standby mode*/
/* Wait cancellation (WREL0) */
#define _00_IICA_WAIT_NOTCANCEL          (0x00U)    /* do not cancel wait */
#define _20_IICA_WAIT_CANCEL             (0x20U)    /* cancel wait */
/* Enable/disable generation of interrupt when stop condition is detected (SPIE0) */
#define _00_IICA_STOPINT_DISABLE         (0x00U)    /* disable */
#define _10_IICA_STOPINT_ENABLE          (0x10U)    /* enable */
/* Control of wait and interrupt request generation (WTIM0) */
#define _00_IICA_WAITINT_CLK8FALLING     (0x00U)    /* interrupt request is generated
                                                       at the eighth clock's falling edge */
#define _08_IICA_WAITINT_CLK9FALLING     (0x08U)    /* interrupt request is generated
                                                       at the ninth clock's falling edge */
/* Acknowledgement control (ACKE0) */
#define _00_IICA_ACK_DISABLE             (0x00U)    /* disable acknowledgement */
#define _04_IICA_ACK_ENABLE              (0x04U)    /* enable acknowledgement */
/* Start condition trigger (STT0) */
#define _00_IICA_START_NOTGENERATE       (0x00U)    /* do not generate start condition */
#define _02_IICA_START_GENERATE          (0x02U)    /* generate start condition */
/* Stop condition trigger (SPT0) */
#define _00_IICA_STOP_NOTGENERATE        (0x00U)    /* do not generate stop condition */
#define _01_IICA_STOP_GENERATE           (0x01U)    /* generate stop condition */
    
/*  
    IICA Status Register 0 (IICS0)
*/
/* Master device status (MSTS0) */
#define _00_IICA_STATUS_NOTMASTER        (0x00U)    /* slave device status or communication standby status */
#define _80_IICA_STATUS_MASTER           (0x80U)    /* master device communication status */
/* Detection of arbitration loss (ALD0) */
#define _00_IICA_ARBITRATION_NO          (0x00U)    /* this status means either that there was no arbitration or
                                                       that the arbitration result was a ¡§win¡¨ */
#define _40_IICA_ARBITRATION_LOSS        (0x40U)    /* this status indicates the arbitration result was a ¡§loss¡¨ */
/* Detection of extension code reception (EXC0) */
#define _00_IICA_EXTCODE_UNRECEIVED      (0x00U)    /* extension code was not received */
#define _20_IICA_EXTCODE_RECEIVED        (0x20U)    /* extension code was received */
/* Detection of matching addresses (COI0) */
#define _00_IICA_ADDRESS_MISMATCH        (0x00U)    /* addresses do not match */
#define _10_IICA_ADDRESS_MATCH           (0x10U)    /* addresses match */
/* Detection of transmit/receive status (TRC0) */
#define _00_IICA_STATUS_RECEIVE          (0x00U)    /* receive status */
#define _08_IICA_STATUS_TRANSMIT         (0x08U)    /* transmit status */
/* Detection of acknowledge (ACK) (ACKD0) */
#define _00_IICA_ACK_UNDETECTED          (0x00U)    /* acknowledge was not detected */
#define _04_IICA_ACK_DETECTED            (0x04U)    /* acknowledge was detected */
/* Detection of start condition (STD0) */
#define _00_IICA_START_UNDETECTED        (0x00U)    /* start condition was not detected */
#define _02_IICA_START_DETECTED          (0x02U)    /* start condition was detected */
/* Detection of stop condition (SPD0) */
#define _00_IICA_STOP_UNDETECTED         (0x00U)    /* stop condition was not detected */
#define _01_IICA_STOP_DETECTED           (0x01U)    /* stop condition was detected */
    
/*  
    IICA Flag Register 0 (IICF0)
*/
/* STT clear flag (STCF0) */
#define _00_IICA_STARTFLAG_GENERATE      (0x00U)    /* generate start condition */
#define _80_IICA_STARTFLAG_UNSUCCESSFUL  (0x80U)    /* start condition generation unsuccessful */
/* IIC bus status flag (IICBSY0) */
#define _00_IICA_BUS_RELEASE             (0x00U)    /* bus release status */
#define _40_IICA_BUS_COMMUNICATION       (0x40U)    /* bus communication status */
/* Initial start enable trigger (STCEN0) */
#define _00_IICA_START_WITHSTOP          (0x00U)    /* enable generation of a start condition upon detection of
                                                       a stop condition */
#define _02_IICA_START_WITHOUTSTOP       (0x02U)    /* enable generation of a start condition without detecting
                                                       a stop condition */
/* Communication reservation function disable bit (IICRSV0) */
#define _00_IICA_RESERVATION_ENABLE      (0x00U)    /* enable communication reservation */
#define _01_IICA_RESERVATION_DISABLE     (0x01U)    /* disable communication reservation */
    
/*  
    IICA Control Register 01 (IICCTL01)
*/
/* Control of address match wakeup (WUP0) */
#define _00_IICA_WAKEUP_STOP             (0x00U)    /* stop address match wakeup function in STOP mode */
#define _80_IICA_WAKEUP_ENABLE           (0x80U)    /* enable address match wakeup function in STOP mode */
/* Detection of SCLA0 pin level (CLD0) */
#define _00_IICA_SCLA_LOW                (0x00U)    /* the SCLA0 pin was detected at low level */
#define _20_IICA_SCLA_HIGH               (0x20U)    /* the SCLA0 pin was detected at high level */
/* Detection of SDAA0 pin level (DAD0) */
#define _00_IICA_SDAA_LOW                (0x00U)    /* the SDAA0 pin was detected at low level */
#define _10_IICA_SDAA_HIGH               (0x10U)    /* the SDAA0 pin was detected at high level */
/* Operation mode switching (SMC0) */
#define _00_IICA_MODE_STANDARD           (0x00U)    /* operates in standard mode */
#define _08_IICA_MODE_FAST               (0x08U)    /* operates in fast mode or fast mode plus */
/* Digital filter operation control (DFC0) */
#define _00_IICA_FILTER_OFF              (0x00U)    /* digital filter off */
#define _04_IICA_FILTER_ON               (0x04U)    /* digital filter on */
/* Control of the operation clock for IICA (fMCK) (PRS0) */
#define _00_IICA_FCLK                    (0x00U)    /* selects fCLK (1 MHz <= fCLK <= 20 MHz) */
#define _01_IICA_FCLK_HALF               (0x01U)    /* selects fCLK/2 (20 MHz < fCLK) */
/* IICA used flag */
#define _80_IICA_ADDRESS_COMPLETE        (0x80U)
#define _00_IICA_MASTER_FLAG_CLEAR       (0x00U)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

