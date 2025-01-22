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
* File Name        : r_cg_tau.h
* Version          : 1.0.30
* Device(s)        : R7F124FPJ5xFB
* Description      : General header file for TAU peripheral.
***********************************************************************************************************************/

#ifndef TAU_H
#define TAU_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of timer array unit 1 input clock (TAU1EN) */
#define _00_TAU1_CLOCK_STOP               (0x00U)    /* stops supply of input clock */
#define _02_TAU1_CLOCK_SUPPLY             (0x02U)    /* supplies input clock */
/* Control of timer array unit 0 input clock (TAU0EN) */
#define _00_TAU0_CLOCK_STOP               (0x00U)    /* stops supply of input clock */
#define _01_TAU0_CLOCK_SUPPLY             (0x01U)    /* supplies input clock */

/*
    Timer Clock Select Register m (TPSm)
*/
/* Selection of operation clock CKm3 (PRSm33 - PRSm30) */
#define _0000_TAU_CKM3_FCLK_0             (0x0000U)    /* ckm3 - fCLK */
#define _1000_TAU_CKM3_FCLK_1             (0x1000U)    /* ckm3 - fCLK/2 */
#define _2000_TAU_CKM3_FCLK_2             (0x2000U)    /* ckm3 - fCLK/2^2 */
#define _3000_TAU_CKM3_FCLK_3             (0x3000U)    /* ckm3 - fCLK/2^3 */
#define _4000_TAU_CKM3_FCLK_4             (0x4000U)    /* ckm3 - fCLK/2^4 */
#define _5000_TAU_CKM3_FCLK_5             (0x5000U)    /* ckm3 - fCLK/2^5 */
#define _6000_TAU_CKM3_FCLK_6             (0x6000U)    /* ckm3 - fCLK/2^6 */
#define _7000_TAU_CKM3_FCLK_7             (0x7000U)    /* ckm3 - fCLK/2^7 */
#define _8000_TAU_CKM3_FCLK_8             (0x8000U)    /* ckm3 - fCLK/2^8 */
#define _9000_TAU_CKM3_FCLK_9             (0x9000U)    /* ckm3 - fCLK/2^9 */
#define _A000_TAU_CKM3_FCLK_10            (0xA000U)    /* ckm3 - fCLK/2^10 */
#define _B000_TAU_CKM3_FCLK_11            (0xB000U)    /* ckm3 - fCLK/2^11 */
#define _C000_TAU_CKM3_FCLK_12            (0xC000U)    /* ckm3 - fCLK/2^12 */
#define _D000_TAU_CKM3_FCLK_13            (0xD000U)    /* ckm3 - fCLK/2^13 */
#define _E000_TAU_CKM3_FCLK_14            (0xE000U)    /* ckm3 - fCLK/2^14 */
#define _F000_TAU_CKM3_FCLK_15            (0xF000U)    /* ckm3 - fCLK/2^15 */
/* Selection of operation clock CK13 (PRS131 - PRS130) */
#define _0000_TAU_CKM3_FCLK_8             (0x0000U)    /* ckm3 - fCLK/2^8 */
#define _1000_TAU_CKM3_FCLK_10            (0x1000U)    /* ckm3 - fCLK/2^10 */
#define _2000_TAU_CKM3_FCLK_12            (0x2000U)    /* ckm3 - fCLK/2^12 */
#define _3000_TAU_CKM3_FCLK_14            (0x3000U)    /* ckm3 - fCLK/2^14 */
/* Selection of operation clock CKm2 (PRSm23 - PRSm20) */
#define _0000_TAU_CKM2_FCLK_0             (0x0000U)    /* ckm2 - fCLK */
#define _0100_TAU_CKM2_FCLK_1             (0x0100U)    /* ckm2 - fCLK/2 */
#define _0200_TAU_CKM2_FCLK_2             (0x0200U)    /* ckm2 - fCLK/2^2 */
#define _0300_TAU_CKM2_FCLK_3             (0x0300U)    /* ckm2 - fCLK/2^3 */
#define _0400_TAU_CKM2_FCLK_4             (0x0400U)    /* ckm2 - fCLK/2^4 */
#define _0500_TAU_CKM2_FCLK_5             (0x0500U)    /* ckm2 - fCLK/2^5 */
#define _0600_TAU_CKM2_FCLK_6             (0x0600U)    /* ckm2 - fCLK/2^6 */
#define _0700_TAU_CKM2_FCLK_7             (0x0700U)    /* ckm2 - fCLK/2^7 */
#define _0800_TAU_CKM2_FCLK_8             (0x0800U)    /* ckm2 - fCLK/2^8 */
#define _0900_TAU_CKM2_FCLK_9             (0x0900U)    /* ckm2 - fCLK/2^9 */
#define _0A00_TAU_CKM2_FCLK_10            (0x0A00U)    /* ckm2 - fCLK/2^10 */
#define _0B00_TAU_CKM2_FCLK_11            (0x0B00U)    /* ckm2 - fCLK/2^11 */
#define _0C00_TAU_CKM2_FCLK_12            (0x0C00U)    /* ckm2 - fCLK/2^12 */
#define _0D00_TAU_CKM2_FCLK_13            (0x0D00U)    /* ckm2 - fCLK/2^13 */
#define _0E00_TAU_CKM2_FCLK_14            (0x0E00U)    /* ckm2 - fCLK/2^14 */
#define _0F00_TAU_CKM2_FCLK_15            (0x0F00U)    /* ckm2 - fCLK/2^15 */
/* Selection of operation clock CK12 (PRS121 - PRS120) */
#define _0000_TAU_CKM2_FCLK_1             (0x0000U)    /* ckm2 - fCLK/2 */
#define _0100_TAU_CKM2_FCLK_2             (0x0100U)    /* ckm2 - fCLK/2^2 */
#define _0200_TAU_CKM2_FCLK_4             (0x0200U)    /* ckm2 - fCLK/2^4 */
#define _0300_TAU_CKM2_FCLK_6             (0x0300U)    /* ckm2 - fCLK/2^6 */
/* Selection of operation clock CKm1 (PRSm13 - PRSm10) */
#define _0000_TAU_CKM1_FCLK_0             (0x0000U)    /* ckm1 - fCLK */
#define _0010_TAU_CKM1_FCLK_1             (0x0010U)    /* ckm1 - fCLK/2 */
#define _0020_TAU_CKM1_FCLK_2             (0x0020U)    /* ckm1 - fCLK/2^2 */
#define _0030_TAU_CKM1_FCLK_3             (0x0030U)    /* ckm1 - fCLK/2^3 */
#define _0040_TAU_CKM1_FCLK_4             (0x0040U)    /* ckm1 - fCLK/2^4 */
#define _0050_TAU_CKM1_FCLK_5             (0x0050U)    /* ckm1 - fCLK/2^5 */
#define _0060_TAU_CKM1_FCLK_6             (0x0060U)    /* ckm1 - fCLK/2^6 */
#define _0070_TAU_CKM1_FCLK_7             (0x0070U)    /* ckm1 - fCLK/2^7 */
#define _0080_TAU_CKM1_FCLK_8             (0x0080U)    /* ckm1 - fCLK/2^8 */
#define _0090_TAU_CKM1_FCLK_9             (0x0090U)    /* ckm1 - fCLK/2^9 */
#define _00A0_TAU_CKM1_FCLK_10            (0x00A0U)    /* ckm1 - fCLK/2^10 */
#define _00B0_TAU_CKM1_FCLK_11            (0x00B0U)    /* ckm1 - fCLK/2^11 */
#define _00C0_TAU_CKM1_FCLK_12            (0x00C0U)    /* ckm1 - fCLK/2^12 */
#define _00D0_TAU_CKM1_FCLK_13            (0x00D0U)    /* ckm1 - fCLK/2^13 */
#define _00E0_TAU_CKM1_FCLK_14            (0x00E0U)    /* ckm1 - fCLK/2^14 */
#define _00F0_TAU_CKM1_FCLK_15            (0x00F0U)    /* ckm1 - fCLK/2^15 */
/* Selection of operation clock CKm0 (PRSm03 - PRSm00) */
#define _0000_TAU_CKM0_FCLK_0             (0x0000U)    /* ckm0 - fCLK */
#define _0001_TAU_CKM0_FCLK_1             (0x0001U)    /* ckm0 - fCLK/2 */
#define _0002_TAU_CKM0_FCLK_2             (0x0002U)    /* ckm0 - fCLK/2^2 */
#define _0003_TAU_CKM0_FCLK_3             (0x0003U)    /* ckm0 - fCLK/2^3 */
#define _0004_TAU_CKM0_FCLK_4             (0x0004U)    /* ckm0 - fCLK/2^4 */
#define _0005_TAU_CKM0_FCLK_5             (0x0005U)    /* ckm0 - fCLK/2^5 */
#define _0006_TAU_CKM0_FCLK_6             (0x0006U)    /* ckm0 - fCLK/2^6 */
#define _0007_TAU_CKM0_FCLK_7             (0x0007U)    /* ckm0 - fCLK/2^7 */
#define _0008_TAU_CKM0_FCLK_8             (0x0008U)    /* ckm0 - fCLK/2^8 */
#define _0009_TAU_CKM0_FCLK_9             (0x0009U)    /* ckm0 - fCLK/2^9 */
#define _000A_TAU_CKM0_FCLK_10            (0x000AU)    /* ckm0 - fCLK/2^10 */
#define _000B_TAU_CKM0_FCLK_11            (0x000BU)    /* ckm0 - fCLK/2^11 */
#define _000C_TAU_CKM0_FCLK_12            (0x000CU)    /* ckm0 - fCLK/2^12 */
#define _000D_TAU_CKM0_FCLK_13            (0x000DU)    /* ckm0 - fCLK/2^13 */
#define _000E_TAU_CKM0_FCLK_14            (0x000EU)    /* ckm0 - fCLK/2^14 */
#define _000F_TAU_CKM0_FCLK_15            (0x000FU)    /* ckm0 - fCLK/2^15 */
/* Clear selection of operation clock CKmk */
#define _0FFF_TAU_CKM3_CLEAR              (0x0FFFU)    /* ckm3 - clear */
#define _F0FF_TAU_CKM2_CLEAR              (0xF0FFU)    /* ckm2 - clear */
#define _FF0F_TAU_CKM1_CLEAR              (0xFF0FU)    /* ckm1 - clear */
#define _FFF0_TAU_CKM0_CLEAR              (0xFFF0U)    /* ckm0 - clear */

/*
    Timer Mode Register mn (TMRmn)
*/
/* Selection of macro clock (MCK) of channel n (CKSmn1 - CKSmn0) */
#define _0000_TAU_CLOCK_SELECT_CKM0       (0x0000U)    /* operation clock CK0 set by PRS register */
#define _8000_TAU_CLOCK_SELECT_CKM1       (0x8000U)    /* operation clock CK1 set by PRS register */
#define _4000_TAU_CLOCK_SELECT_CKM2       (0x4000U)    /* operation clock CK2 set by PRS register */
#define _C000_TAU_CLOCK_SELECT_CKM3       (0xC000U)    /* operation clock CK3 set by PRS register */
/* Selection of count clock (CCK) of channel n (CCSmn) */
#define _0000_TAU_CLOCK_MODE_CKS          (0x0000U)    /* macro clock MCK specified by CKSmn bit */
#define _1000_TAU_CLOCK_MODE_TIMN         (0x1000U)    /* valid edge of input signal input from TImn pin */
/* Selection of slave/master of channel n (MASTERmn) */
#define _0000_TAU_COMBINATION_SLAVE       (0x0000U)    /* operates as slave channel */
#define _0800_TAU_COMBINATION_MASTER      (0x0800U)    /* channel2, 4, 6 operates as master channel */
/* Operation explanation of channel 1 or 3 (SPLIT) */
#define _0000_TAU_16BITS_MODE             (0x0000U)    /* operates as 16 bits timer */
#define _0800_TAU_8BITS_MODE              (0x0800U)    /* operates as 8 bits timer */
/* Setting of start trigger or capture trigger of channel n (STSmn2 - STSmn0) */
#define _0000_TAU_TRIGGER_SOFTWARE        (0x0000U)    /* only software trigger start is valid */
#define _0100_TAU_TRIGGER_TIMN_VALID      (0x0100U)    /* TImn input edge is used as a start/capture trigger */
#define _0200_TAU_TRIGGER_TIMN_BOTH       (0x0200U)    /* TImn input edges are used as a start/capture trigger */
#define _0400_TAU_TRIGGER_MASTER_INT      (0x0400U)    /* interrupt signal of the master channel is used */
/* Selection of TImn pin input valid edge (CISmn1 - CISmn0) */
#define _0000_TAU_TIMN_EDGE_FALLING       (0x0000U)    /* falling edge */
#define _0040_TAU_TIMN_EDGE_RISING        (0x0040U)    /* rising edge */
#define _0080_TAU_TIMN_EDGE_BOTH_LOW      (0x0080U)    /* both edges (when low-level width is measured) */
#define _00C0_TAU_TIMN_EDGE_BOTH_HIGH     (0x00C0U)    /* both edges (when high-level width is measured) */
/* Operation mode of channel n (MDmn3 - MDmn0) */
#define _0000_TAU_MODE_INTERVAL_TIMER     (0x0000U)    /* interval timer mode */
#define _0004_TAU_MODE_CAPTURE            (0x0004U)    /* capture mode */
#define _0006_TAU_MODE_EVENT_COUNT        (0x0006U)    /* event counter mode */
#define _0008_TAU_MODE_ONE_COUNT          (0x0008U)    /* one count mode */
#define _000C_TAU_MODE_HIGHLOW_MEASURE    (0x000CU)    /* high-/low-level width measurement mode */
#define _0001_TAU_MODE_PWM_MASTER         (0x0001U)    /* PWM Function (Master Channel) mode */
#define _0009_TAU_MODE_PWM_SLAVE          (0x0009U)    /* PWM Function (Slave Channel) mode */
#define _0008_TAU_MODE_ONESHOT            (0x0008U)    /* one-shot pulse output mode */
/* Setting of starting counting and interrupt (MDmn0) */
#define _0000_TAU_START_INT_UNUSED        (0x0000U)    /* interrupt is not generated when counting is started */
#define _0001_TAU_START_INT_USED          (0x0001U)    /* interrupt is generated when counting is started */

/*
    Timer Status Register mn (TSRmn)
*/
/* Counter overflow status of channel n (OVF) */
#define _0000_TAU_OVERFLOW_NOT_OCCURS     (0x0000U)    /* overflow does not occur */
#define _0001_TAU_OVERFLOW_OCCURS         (0x0001U)    /* overflow occurs */

/*
    Timer Channel Enable Status Register m (TEm)
*/
/* Indication of operation enable/stop status of channel 3 higher 8 bits (TEHm3) */
#define _0000_TAU_CH3_H8_OPERATION_STOP   (0x0000U)    /* operation is stopped */
#define _0800_TAU_CH3_H8_OPERATION_ENABLE (0x0800U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 1 higher 8 bits (TEHm1) */
#define _0000_TAU_CH1_H8_OPERATION_STOP   (0x0000U)    /* operation is stopped */
#define _0200_TAU_CH1_H8_OPERATION_ENABLE (0x0200U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 7 (TEm7) */
#define _0000_TAU_CH7_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0080_TAU_CH7_OPERATION_ENABLE    (0x0080U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 6 (TEm6) */
#define _0000_TAU_CH6_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0040_TAU_CH6_OPERATION_ENABLE    (0x0040U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 5 (TEm5) */
#define _0000_TAU_CH5_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0020_TAU_CH5_OPERATION_ENABLE    (0x0020U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 4 (TEm4) */
#define _0000_TAU_CH4_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0010_TAU_CH4_OPERATION_ENABLE    (0x0010U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 3 (TEm3) */
#define _0000_TAU_CH3_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0008_TAU_CH3_OPERATION_ENABLE    (0x0008U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 2 (TEm2) */
#define _0000_TAU_CH2_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0004_TAU_CH2_OPERATION_ENABLE    (0x0004U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 1 (TEm1) */
#define _0000_TAU_CH1_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0002_TAU_CH1_OPERATION_ENABLE    (0x0002U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 0 (TEm0) */
#define _0000_TAU_CH0_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0001_TAU_CH0_OPERATION_ENABLE    (0x0001U)    /* operation is enabled */

/*
    Timer Channel Start Register m (TSm)
*/
/* Operation enable (start) trigger of channel 3 higher 8 bits (TSHm3) */
#define _0000_TAU_CH3_H8_START_TRG_OFF    (0x0000U)    /* no trigger operation */
#define _0800_TAU_CH3_H8_START_TRG_ON     (0x0800U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 1 higher 8 bits (TSHm1) */
#define _0000_TAU_CH1_H8_START_TRG_OFF    (0x0000U)    /* no trigger operation */
#define _0200_TAU_CH1_H8_START_TRG_ON     (0x0200U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 7 (TSm7) */
#define _0000_TAU_CH7_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0080_TAU_CH7_START_TRG_ON        (0x0080U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 6 (TSm6) */
#define _0000_TAU_CH6_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0040_TAU_CH6_START_TRG_ON        (0x0040U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 5 (TSm5) */
#define _0000_TAU_CH5_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0020_TAU_CH5_START_TRG_ON        (0x0020U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 4 (TSm4) */
#define _0000_TAU_CH4_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0010_TAU_CH4_START_TRG_ON        (0x0010U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 3 (TSm3) */
#define _0000_TAU_CH3_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0008_TAU_CH3_START_TRG_ON        (0x0008U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 2 (TSm2) */
#define _0000_TAU_CH2_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0004_TAU_CH2_START_TRG_ON        (0x0004U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 1 (TSm1) */
#define _0000_TAU_CH1_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0002_TAU_CH1_START_TRG_ON        (0x0002U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 0 (TSm0) */
#define _0000_TAU_CH0_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0001_TAU_CH0_START_TRG_ON        (0x0001U)    /* operation is enabled (start trigger is generated) */

/*
    Timer Channel Stop Register m (TTm)
*/
/* Operation stop trigger of channel 3 higher 8 bits (TTHm3) */
#define _0000_TAU_CH3_H8_STOP_TRG_OFF     (0x0000U)    /* no trigger operation */
#define _0800_TAU_CH3_H8_STOP_TRG_ON      (0x0800U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 higher 8 bits (TTHm1) */
#define _0000_TAU_CH1_H8_STOP_TRG_OFF     (0x0000U)    /* no trigger operation */
#define _0200_TAU_CH1_H8_STOP_TRG_ON      (0x0200U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 7 (TTm7) */
#define _0000_TAU_CH7_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0080_TAU_CH7_STOP_TRG_ON         (0x0080U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 6 (TTm6) */
#define _0000_TAU_CH6_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0040_TAU_CH6_STOP_TRG_ON         (0x0040U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 5 (TTm5) */
#define _0000_TAU_CH5_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0020_TAU_CH5_STOP_TRG_ON         (0x0020U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 4 (TTm4) */
#define _0000_TAU_CH4_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0010_TAU_CH4_STOP_TRG_ON         (0x0010U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 3 (TTm3) */
#define _0000_TAU_CH3_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0008_TAU_CH3_STOP_TRG_ON         (0x0008U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 2 (TTm2) */
#define _0000_TAU_CH2_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0004_TAU_CH2_STOP_TRG_ON         (0x0004U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 (TTm1) */
#define _0000_TAU_CH1_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0002_TAU_CH1_STOP_TRG_ON         (0x0002U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 0 (TTm0) */
#define _0000_TAU_CH0_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0001_TAU_CH0_STOP_TRG_ON         (0x0001U)    /* operation is stopped (stop trigger is generated) */

/*
    Timer Input Select Register 0 (TIS0)
*/
/* Selection of timer input used with channel 3 of unit 0 (TIS07) */
#define _57_TAU_CH3_INPUT_TI03           (0x57U)    /* input signal of timer input pin (TI03) */
#define _80_TAU_CH3_INPUT_ELC            (0x80U)    /* event input signal from ELC */
/* Selection of timer input used with channel 2 of unit 0 (TIS06) */
#define _97_TAU_CH2_INPUT_TI02           (0x97U)    /* input signal of timer input pin (TI02) */
#define _40_TAU_CH2_INPUT_ELC            (0x40U)    /* event input signal from ELC */
/* Selection of timer input used with channel 0 of unit 0 (TIS04) */
#define _C7_TAU_CH0_INPUT_TI00           (0xC7U)    /* input signal of timer input pin (TI00) */
#define _10_TAU_CH0_INPUT_ELC            (0x10U)    /* event input signal from ELC */
/* Selection of timer input used with channel 1 of unit 0 (TIS02 - TIS00) */
#define _00_TAU_CH1_INPUT_TI01           (0x00U)    /* input signal of timer input pin (TI01) */
#define _01_TAU_CH1_INPUT_ELC            (0x01U)    /* event input signal from ELC */
#define _02_TAU_CH1_INPUT_TI01           (0x02U)    /* input signal of timer input pin (TI01) */
#define _03_TAU_CH1_INPUT_TI01           (0x03U)    /* input signal of timer input pin (TI01) */
#define _04_TAU_CH1_INPUT_FIL            (0x04U)    /* low-speed on-chip oscillator clock (fIL) */
#define _05_TAU_CH1_INPUT_FSL            (0x05U)    /* sub/low-speed on-chip oscillator select clock (fSL) */
#define _D0_TAU_CH1_INPUT_CLEAR          (0xD0U)    /* bits of TIS02 - TIS00 clear */

/*
    Timer Input Select Register 1 (TIS1)
*/
/* Selection of timer input used with channel 7 of unit 0 (TIS17 - TIS16) */
#define _00_TAU_CH7_INPUT_TI07           (0x00U)    /* input signal of timer input pin (TI07) */
#define _40_TAU_CH7_INPUT_RTC1HZ         (0x40U)    /* RTC1HZ output signal */
#define _80_TAU_CH7_INPUT_RXD0           (0x80U)    /* RxD0 pin */
#define _15_TAU_CH7_INPUT_CLEAR          (0x15U)    /* bits of TIS17 - TIS16 clear */
/* Selection of timer input used with channel 6 of unit 0 (TIS14) */
#define _C5_TAU_CH6_INPUT_TI06           (0xC5U)    /* input signal of timer input pin (TI06) */
#define _10_TAU_CH6_INPUT_RTC1HZ         (0x10U)    /* RTC1HZ output signal */
/* Selection of timer input used with channel 5 of unit 0 (TIS12) */
#define _D1_TAU_CH5_INPUT_TI05           (0xD1U)    /* input signal of timer input pin (TI05) */
#define _04_TAU_CH5_INPUT_TI03           (0x04U)    /* input signal of timer input pin (TI03) */
/* Selection of timer input used with channel 4 of unit 0 (TIS10) */
#define _D4_TAU_CH4_INPUT_TI04           (0xD4U)    /* input signal of timer input pin (TI04) */
#define _01_TAU_CH4_INPUT_TI03           (0x01U)    /* input signal of timer input pin (TI03) */

/*
    Timer Input Select Register 2 (TIS2)
*/
/* Selection of timer input used with channel 7 of unit 1 (TIS23) */
#define _04_TAU_CH7_INPUT_TI17           (0x04U)    /* input signal of timer input pin (TI17) */
#define _08_TAU_CH7_INPUT_RTC1HZ         (0x08U)    /* RTC1HZ output signal */
/* Selection of timer input used with channel 6 of unit 1 (TIS22) */
#define _08_TAU_CH6_INPUT_TI16           (0x08U)    /* input signal of timer input pin (TI16) */
#define _04_TAU_CH6_INPUT_RTC1HZ         (0x04U)    /* RTC1HZ output signal */

/*
    Timer Output Enable Register m (TOEm)
*/
/* Timer output enable/disable of channel 7 (TOEm7) */
#define _0000_TAU_CH7_OUTPUT_DISABLE      (0x0000U)    /* the TOm7 operation stopped by count operation */
#define _0080_TAU_CH7_OUTPUT_ENABLE       (0x0080U)    /* the TOm7 operation enabled by count operation */
/* Timer output enable/disable of channel 6 (TOEm6) */
#define _0000_TAU_CH6_OUTPUT_DISABLE      (0x0000U)    /* the TOm6 operation stopped by count operation */
#define _0040_TAU_CH6_OUTPUT_ENABLE       (0x0040U)    /* the TOm6 operation enabled by count operation */
/* Timer output enable/disable of channel 5 (TOEm5) */
#define _0000_TAU_CH5_OUTPUT_DISABLE      (0x0000U)    /* the TOm5 operation stopped by count operation */
#define _0020_TAU_CH5_OUTPUT_ENABLE       (0x0020U)    /* the TOm5 operation enabled by count operation */
/* Timer output enable/disable of channel 4 (TOEm4) */
#define _0000_TAU_CH4_OUTPUT_DISABLE      (0x0000U)    /* the TOm4 operation stopped by count operation */
#define _0010_TAU_CH4_OUTPUT_ENABLE       (0x0010U)    /* the TOm4 operation enabled by count operation */
/* Timer output enable/disable of channel 3 (TOEm3) */
#define _0000_TAU_CH3_OUTPUT_DISABLE      (0x0000U)    /* the TOm3 operation stopped by count operation */
#define _0008_TAU_CH3_OUTPUT_ENABLE       (0x0008U)    /* the TOm3 operation enabled by count operation */
/* Timer output enable/disable of channel 2 (TOEm2) */
#define _0000_TAU_CH2_OUTPUT_DISABLE      (0x0000U)    /* the TOm2 operation stopped by count operation */
#define _0004_TAU_CH2_OUTPUT_ENABLE       (0x0004U)    /* the TOm2 operation enabled by count operation */
/* Timer output enable/disable of channel 1 (TOEm1) */
#define _0000_TAU_CH1_OUTPUT_DISABLE      (0x0000U)    /* the TOm1 operation stopped by count operation */
#define _0002_TAU_CH1_OUTPUT_ENABLE       (0x0002U)    /* the TOm1 operation enabled by count operation */
/* Timer output enable/disable of channel 0 (TOEm0) */
#define _0000_TAU_CH0_OUTPUT_DISABLE      (0x0000U)    /* the TOm0 operation stopped by count operation */
#define _0001_TAU_CH0_OUTPUT_ENABLE       (0x0001U)    /* the TOm0 operation enabled by count operation */

/*
    Timer Output Register m (TOm)
*/
/* Timer output of channel 7 (TOm7) */
#define _0000_TAU_CH7_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0080_TAU_CH7_OUTPUT_VALUE_1      (0x0080U)    /* timer output value is "1" */
/* Timer output of channel 6 (TOm6) */
#define _0000_TAU_CH6_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0040_TAU_CH6_OUTPUT_VALUE_1      (0x0040U)    /* timer output value is "1" */
/* Timer output of channel 5 (TOm5) */
#define _0000_TAU_CH5_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0020_TAU_CH5_OUTPUT_VALUE_1      (0x0020U)    /* timer output value is "1" */
/* Timer output of channel 4 (TOm4) */
#define _0000_TAU_CH4_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0010_TAU_CH4_OUTPUT_VALUE_1      (0x0010U)    /* timer output value is "1" */
/* Timer output of channel 3 (TOm3) */
#define _0000_TAU_CH3_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0008_TAU_CH3_OUTPUT_VALUE_1      (0x0008U)    /* timer output value is "1" */
/* Timer output of channel 2 (TOm2) */
#define _0000_TAU_CH2_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0004_TAU_CH2_OUTPUT_VALUE_1      (0x0004U)    /* timer output value is "1" */
/* Timer output of channel 1 (TOm1) */
#define _0000_TAU_CH1_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0002_TAU_CH1_OUTPUT_VALUE_1      (0x0002U)    /* timer output value is "1" */
/* Timer output of channel 0 (TOm0) */
#define _0000_TAU_CH0_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0001_TAU_CH0_OUTPUT_VALUE_1      (0x0001U)    /* timer output value is "1" */

/*
    Timer Output Level Register 0 (TOLm)
*/
/* Control of timer output level of channel 7 (TOLm7) */
#define _0000_TAU_CH7_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0080_TAU_CH7_OUTPUT_LEVEL_L      (0x0080U)    /* inverted output (active-low) */
/* Control of timer output level of channel 6 (TOLm6) */
#define _0000_TAU_CH6_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0040_TAU_CH6_OUTPUT_LEVEL_L      (0x0040U)    /* inverted output (active-low) */
/* Control of timer output level of channel 5 (TOLm5) */
#define _0000_TAU_CH5_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0020_TAU_CH5_OUTPUT_LEVEL_L      (0x0020U)    /* inverted output (active-low) */
/* Control of timer output level of channel 4 (TOLm4) */
#define _0000_TAU_CH4_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0010_TAU_CH4_OUTPUT_LEVEL_L      (0x0010U)    /* inverted output (active-low) */
/* Control of timer output level of channel 3 (TOLm3) */
#define _0000_TAU_CH3_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0008_TAU_CH3_OUTPUT_LEVEL_L      (0x0008U)    /* inverted output (active-low) */
/* Control of timer output level of channel 2 (TOLm2) */
#define _0000_TAU_CH2_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0004_TAU_CH2_OUTPUT_LEVEL_L      (0x0004U)    /* inverted output (active-low) */
/* Control of timer output level of channel 1 (TOLm1) */
#define _0000_TAU_CH1_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0002_TAU_CH1_OUTPUT_LEVEL_L      (0x0002U)    /* inverted output (active-low) */

/*
    Timer Output Mode Register m (TOMm)
*/
/* Control of timer output mode of channel 7 (TOMm7) */
#define _0000_TAU_CH7_MASTER_OUTPUT       (0x0000U)    /* master channel output mode */
#define _0080_TAU_CH7_SLAVE_OUTPUT        (0x0080U)    /* slave channel output mode */
/* Control of timer output mode of channel 6 (TOMm6) */
#define _0000_TAU_CH6_MASTER_OUTPUT       (0x0000U)    /* master channel output mode */
#define _0040_TAU_CH6_SLAVE_OUTPUT        (0x0040U)    /* slave channel output mode */
/* Control of timer output mode of channel 5 (TOMm5) */
#define _0000_TAU_CH5_MASTER_OUTPUT       (0x0000U)    /* master channel output mode */
#define _0020_TAU_CH5_SLAVE_OUTPUT        (0x0020U)    /* slave channel output mode */
/* Control of timer output mode of channel 4 (TOMm4) */
#define _0000_TAU_CH4_MASTER_OUTPUT       (0x0000U)    /* master channel output mode */
#define _0010_TAU_CH4_SLAVE_OUTPUT        (0x0010U)    /* slave channel output mode */
/* Control of timer output mode of channel 3 (TOMm3) */
#define _0000_TAU_CH3_MASTER_OUTPUT       (0x0000U)    /* master channel output mode */
#define _0008_TAU_CH3_SLAVE_OUTPUT        (0x0008U)    /* slave channel output mode */
/* Control of timer output mode of channel 2 (TOMm2) */
#define _0000_TAU_CH2_MASTER_OUTPUT       (0x0000U)    /* master channel output mode */
#define _0004_TAU_CH2_SLAVE_OUTPUT        (0x0004U)    /* slave channel output mode */
/* Control of timer output mode of channel 1 (TOMm1) */
#define _0000_TAU_CH1_MASTER_OUTPUT       (0x0000U)    /* master channel output mode */
#define _0002_TAU_CH1_SLAVE_OUTPUT        (0x0002U)    /* slave channel output mode */

/*
    Noise Filter Enable Register 1,2 (NFEN1, NFEN2)
*/
/* Enable/disable using noise filter of TIm7 pin input signal (TNFENm7) */
#define _00_TAU_CH7_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _80_TAU_CH7_NOISE_ON              (0x80U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm6 pin input signal (TNFENm6) */
#define _00_TAU_CH6_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _40_TAU_CH6_NOISE_ON              (0x40U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm5 pin input signal (TNFENm5) */
#define _00_TAU_CH5_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _20_TAU_CH5_NOISE_ON              (0x20U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm4 pin input signal (TNFENm4) */
#define _00_TAU_CH4_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _10_TAU_CH4_NOISE_ON              (0x10U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm3 pin input signal (TNFENm3) */
#define _00_TAU_CH3_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _08_TAU_CH3_NOISE_ON              (0x08U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm2 pin input signal (TNFENm2) */
#define _00_TAU_CH2_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _04_TAU_CH2_NOISE_ON              (0x04U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm1 pin input signal (TNFENm1) */
#define _00_TAU_CH1_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _02_TAU_CH1_NOISE_ON              (0x02U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm0 pin input signal (TNFENm0) */
#define _00_TAU_CH0_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _01_TAU_CH0_NOISE_ON              (0x01U)    /* noise filter ON */

/*
    PWM Output Delay Control Register 1, 2 (PWMDLY1, PWMDLY2)
*/
/* Selection of PWM output delay used with channel 7 (TOm71 - TOm70) */
#define _0000_TAU_CH7_OUTPUT_NO_DELAY     (0x0000U)    /* no delay */
#define _4000_TAU_CH7_OUTPUT_DELAY_1      (0x4000U)    /* delayed by one cycle of the fCLK */
#define _8000_TAU_CH7_OUTPUT_DELAY_2      (0x8000U)    /* delayed by two cycles of the fCLK */
#define _C000_TAU_CH7_OUTPUT_DELAY_3      (0xC000U)    /* delayed by three cycles of the fCLK */
#define _3FFF_TAU_CH7_OUTPUT_CLEAR        (0x3FFFU)    /* bits of TOm71 - TOm70 clear */
/* Selection of PWM output delay used with channel 6 (TOm61 - TOm60) */
#define _0000_TAU_CH6_OUTPUT_NO_DELAY     (0x0000U)    /* no delay */
#define _1000_TAU_CH6_OUTPUT_DELAY_1      (0x1000U)    /* delayed by one cycle of the fCLK */
#define _2000_TAU_CH6_OUTPUT_DELAY_2      (0x2000U)    /* delayed by two cycles of the fCLK */
#define _3000_TAU_CH6_OUTPUT_DELAY_3      (0x3000U)    /* delayed by three cycles of the fCLK */
#define _CFFF_TAU_CH6_OUTPUT_CLEAR        (0xCFFFU)    /* bits of TOm61 - TOm60 clear */
/* Selection of PWM output delay used with channel 5 (TOm51 - TOm50) */
#define _0000_TAU_CH5_OUTPUT_NO_DELAY     (0x0000U)    /* no delay */
#define _0400_TAU_CH5_OUTPUT_DELAY_1      (0x0400U)    /* delayed by one cycle of the fCLK */
#define _0800_TAU_CH5_OUTPUT_DELAY_2      (0x0800U)    /* delayed by two cycles of the fCLK */
#define _0C00_TAU_CH5_OUTPUT_DELAY_3      (0x0C00U)    /* delayed by three cycles of the fCLK */
#define _F3FF_TAU_CH5_OUTPUT_CLEAR        (0xF3FFU)    /* bits of TOm51 - TOm50 clear */
/* Selection of PWM output delay used with channel 4 (TOm41 - TOm40) */
#define _0000_TAU_CH4_OUTPUT_NO_DELAY     (0x0000U)    /* no delay */
#define _0100_TAU_CH4_OUTPUT_DELAY_1      (0x0100U)    /* delayed by one cycle of the fCLK */
#define _0200_TAU_CH4_OUTPUT_DELAY_2      (0x0200U)    /* delayed by two cycles of the fCLK */
#define _0300_TAU_CH4_OUTPUT_DELAY_3      (0x0300U)    /* delayed by three cycles of the fCLK */
#define _FCFF_TAU_CH4_OUTPUT_CLEAR        (0xFCFFU)    /* bits of TOm41 - TOm40 clear */
/* Selection of PWM output delay used with channel 3 (TOm31 - TOm30) */
#define _0000_TAU_CH3_OUTPUT_NO_DELAY     (0x0000U)    /* no delay */
#define _0040_TAU_CH3_OUTPUT_DELAY_1      (0x0040U)    /* delayed by one cycle of the fCLK */
#define _0080_TAU_CH3_OUTPUT_DELAY_2      (0x0080U)    /* delayed by two cycles of the fCLK */
#define _00C0_TAU_CH3_OUTPUT_DELAY_3      (0x00C0U)    /* delayed by three cycles of the fCLK */
#define _FF3F_TAU_CH3_OUTPUT_CLEAR        (0xFF3FU)    /* bits of TOm31 - TOm30 clear */
/* Selection of PWM output delay used with channel 2 (TOm21 - TOm20) */
#define _0000_TAU_CH2_OUTPUT_NO_DELAY     (0x0000U)    /* no delay */
#define _0010_TAU_CH2_OUTPUT_DELAY_1      (0x0010U)    /* delayed by one cycle of the fCLK */
#define _0020_TAU_CH2_OUTPUT_DELAY_2      (0x0020U)    /* delayed by two cycles of the fCLK */
#define _0030_TAU_CH2_OUTPUT_DELAY_3      (0x0030U)    /* delayed by three cycles of the fCLK */
#define _FFCF_TAU_CH2_OUTPUT_CLEAR        (0xFFCFU)    /* bits of TOm21 - TOm20 clear */
/* Selection of PWM output delay used with channel 1 (TOm11 - TOm10) */
#define _0000_TAU_CH1_OUTPUT_NO_DELAY     (0x0000U)    /* no delay */
#define _0004_TAU_CH1_OUTPUT_DELAY_1      (0x0004U)    /* delayed by one cycle of the fCLK */
#define _0008_TAU_CH1_OUTPUT_DELAY_2      (0x0008U)    /* delayed by two cycles of the fCLK */
#define _000C_TAU_CH1_OUTPUT_DELAY_3      (0x000CU)    /* delayed by three cycles of the fCLK */
#define _FFF3_TAU_CH1_OUTPUT_CLEAR        (0xFFF3U)    /* bits of TOm11 - TOm10 clear */

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
