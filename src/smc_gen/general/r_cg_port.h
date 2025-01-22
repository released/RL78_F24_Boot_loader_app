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
* File Name        : r_cg_port.h
* Version          : 1.0.30
* Device(s)        : R7F124FPJ5xFB
* Description      : General header file for PORT peripheral.
***********************************************************************************************************************/

#ifndef PORT_H
#define PORT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Port Mode Registers (PMn)
*/
/* Pn7 pin I/O mode selection (PMn7) */
#define _00_PMn7_MODE_OUTPUT                    (0x00U)    /* use Pn7 as output mode */
#define _80_PMn7_MODE_INPUT                     (0x80U)    /* use Pn7 as input mode */
#define _80_PMn7_NOT_USE                        (0x80U)    /* not use Pn7 as digital I/O */
/* Pn6 pin I/O mode selection (PMn6) */
#define _00_PMn6_MODE_OUTPUT                    (0x00U)    /* use Pn6 as output mode */
#define _40_PMn6_MODE_INPUT                     (0x40U)    /* use Pn6 as input mode */
#define _40_PMn6_NOT_USE                        (0x40U)    /* not use Pn6 as digital I/O */
/* Pn5 pin I/O mode selection (PMn5) */
#define _00_PMn5_MODE_OUTPUT                    (0x00U)    /* use Pn5 as output mode */
#define _20_PMn5_MODE_INPUT                     (0x20U)    /* use Pn5 as input mode */
#define _20_PMn5_NOT_USE                        (0x20U)    /* not use Pn5 as digital I/O */
/* Pn4 pin I/O mode selection (PMn4) */
#define _00_PMn4_MODE_OUTPUT                    (0x00U)    /* use Pn4 as output mode */
#define _10_PMn4_MODE_INPUT                     (0x10U)    /* use Pn4 as input mode */
#define _10_PMn4_NOT_USE                        (0x10U)    /* not use Pn4 as digital I/O */
/* Pn3 pin I/O mode selection (PMn3) */
#define _00_PMn3_MODE_OUTPUT                    (0x00U)    /* use Pn3 as output mode */
#define _08_PMn3_MODE_INPUT                     (0x08U)    /* use Pn3 as input mode */
#define _08_PMn3_NOT_USE                        (0x08U)    /* not use Pn3 as digital I/O */
/* Pn2 pin I/O mode selection (PMn2) */
#define _00_PMn2_MODE_OUTPUT                    (0x00U)    /* use Pn2 as output mode */
#define _04_PMn2_MODE_INPUT                     (0x04U)    /* use Pn2 as input mode */
#define _04_PMn2_NOT_USE                        (0x04U)    /* not use Pn2 as digital I/O */
/* Pn1 pin I/O mode selection (PMn1) */
#define _00_PMn1_MODE_OUTPUT                    (0x00U)    /* use Pn1 as output mode */
#define _02_PMn1_MODE_INPUT                     (0x02U)    /* use Pn1 as input mode */
#define _02_PMn1_NOT_USE                        (0x02U)    /* not use Pn1 as digital I/O */
/* Pn0 pin I/O mode selection (PMn0) */
#define _00_PMn0_MODE_OUTPUT                    (0x00U)    /* use Pn0 as output mode */
#define _01_PMn0_MODE_INPUT                     (0x01U)    /* use Pn0 as input mode */
#define _01_PMn0_NOT_USE                        (0x01U)    /* not use Pn0 as digital I/O */

/*
    Port Registers (Pn)
*/
/* Pn7 pin output latch selection (Pn7) */
#define _00_Pn7_OUTPUT_0                        (0x00U)    /* Pn7 output 0 */
#define _80_Pn7_OUTPUT_1                        (0x80U)    /* Pn7 output 1 */
/* Pn6 pin output latch selection (Pn6) */
#define _00_Pn6_OUTPUT_0                        (0x00U)    /* Pn6 output 0 */
#define _40_Pn6_OUTPUT_1                        (0x40U)    /* Pn6 output 1 */
/* Pn5 pin output latch selection (Pn5) */
#define _00_Pn5_OUTPUT_0                        (0x00U)    /* Pn5 output 0 */
#define _20_Pn5_OUTPUT_1                        (0x20U)    /* Pn5 output 1 */
/* Pn4 pin output latch selection (Pn4) */
#define _00_Pn4_OUTPUT_0                        (0x00U)    /* Pn4 output 0 */
#define _10_Pn4_OUTPUT_1                        (0x10U)    /* Pn4 output 1 */
/* Pn3 pin output latch selection (Pn3) */
#define _00_Pn3_OUTPUT_0                        (0x00U)    /* Pn3 output 0 */
#define _08_Pn3_OUTPUT_1                        (0x08U)    /* Pn3 output 1 */
/* Pn2 pin output latch selection (Pn2) */
#define _00_Pn2_OUTPUT_0                        (0x00U)    /* Pn2 output 0 */
#define _04_Pn2_OUTPUT_1                        (0x04U)    /* Pn2 output 1 */
/* Pn1 pin output latch selection (Pn1) */
#define _00_Pn1_OUTPUT_0                        (0x00U)    /* Pn1 output 0 */
#define _02_Pn1_OUTPUT_1                        (0x02U)    /* Pn1 output 1 */
/* Pn0 pin output latch selection (Pn0) */
#define _00_Pn0_OUTPUT_0                        (0x00U)    /* Pn0 output 0 */
#define _01_Pn0_OUTPUT_1                        (0x01U)    /* Pn0 output 1 */

/*
    Pull-up Resistor Option Registers (PUn)
*/
/* Pn7 pin on-chip pull-up resistor selection (PUn7) */
#define _00_PUn7_PULLUP_OFF                     (0x00U)    /* Pn7 pull-up resistor not connected */
#define _80_PUn7_PULLUP_ON                      (0x80U)    /* Pn7 pull-up resistor connected */
/* Pn6 pin on-chip pull-up resistor selection (PUn6) */
#define _00_PUn6_PULLUP_OFF                     (0x00U)    /* Pn6 pull-up resistor not connected */
#define _40_PUn6_PULLUP_ON                      (0x40U)    /* Pn6 pull-up resistor connected */
/* Pn5 pin on-chip pull-up resistor selection (PUn5) */
#define _00_PUn5_PULLUP_OFF                     (0x00U)    /* Pn5 pull-up resistor not connected */
#define _20_PUn5_PULLUP_ON                      (0x20U)    /* Pn5 pull-up resistor connected */
/* Pn4 pin on-chip pull-up resistor selection (PUn4) */
#define _00_PUn4_PULLUP_OFF                     (0x00U)    /* Pn4 pull-up resistor not connected */
#define _10_PUn4_PULLUP_ON                      (0x10U)    /* Pn4 pull-up resistor connected */
/* Pn3 pin on-chip pull-up resistor selection (PUn3) */
#define _00_PUn3_PULLUP_OFF                     (0x00U)    /* Pn3 pull-up resistor not connected */
#define _08_PUn3_PULLUP_ON                      (0x08U)    /* Pn3 pull-up resistor connected */
/* Pn2 pin on-chip pull-up resistor selection (PUn2) */
#define _00_PUn2_PULLUP_OFF                     (0x00U)    /* Pn2 Pull-up resistor not connected */
#define _04_PUn2_PULLUP_ON                      (0x04U)    /* Pn2 pull-up resistor connected */
/* Pn1 pin on-chip pull-up resistor selection (PUn1) */
#define _00_PUn1_PULLUP_OFF                     (0x00U)    /* Pn1 pull-up resistor not connected */
#define _02_PUn1_PULLUP_ON                      (0x02U)    /* Pn1 pull-up resistor connected */
/* Pn0 pin on-chip pull-up resistor selection (PUn0) */
#define _00_PUn0_PULLUP_OFF                     (0x00U)    /* Pn0 pull-up resistor not connected */
#define _01_PUn0_PULLUP_ON                      (0x01U)    /* Pn0 pull-up resistor connected */

/*
    Port Input Mode Registers (PIMn)
*/
/* Pn7 pin input buffer selection (PIMn7) */
#define _00_PIMn7_TTL_OFF                       (0x00U)    /* Pn7 normal input buffer */
#define _80_PIMn7_TTL_ON                        (0x80U)    /* Pn7 TTL input buffer */
/* Pn6 pin input buffer selection (PIMn6) */
#define _00_PIMn6_TTL_OFF                       (0x00U)    /* Pn6 normal input buffer */
#define _40_PIMn6_TTL_ON                        (0x40U)    /* Pn6 TTL input buffer */
/* Pn5 pin input buffer selection (PIMn5) */
#define _00_PIMn5_TTL_OFF                       (0x00U)    /* Pn5 normal input buffer */
#define _20_PIMn5_TTL_ON                        (0x20U)    /* Pn5 TTL input buffer */
/* Pn4 pin input buffer selection (PIMn4) */
#define _00_PIMn4_TTL_OFF                       (0x00U)    /* Pn4 normal input buffer */
#define _10_PIMn4_TTL_ON                        (0x10U)    /* Pn4 TTL input buffer */
/* Pn3 pin input buffer selection (PIMn3) */
#define _00_PIMn3_TTL_OFF                       (0x00U)    /* Pn3 normal input buffer */
#define _08_PIMn3_TTL_ON                        (0x08U)    /* Pn3 TTL input buffer */
/* Pn2 pin input buffer selection (PIMn2) */
#define _00_PIMn2_TTL_OFF                       (0x00U)    /* Pn2 normal input buffer */
#define _04_PIMn2_TTL_ON                        (0x04U)    /* Pn2 TTL input buffer */
/* Pn1 pin input buffer selection (PIMn1) */
#define _00_PIMn1_TTL_OFF                       (0x00U)    /* Pn1 normal input buffer */
#define _02_PIMn1_TTL_ON                        (0x02U)    /* Pn1 TTL input buffer */
/* Pn0 pin input buffer selection (PIMn0) */
#define _00_PIMn0_TTL_OFF                       (0x00U)    /* Pn0 normal input buffer */
#define _01_PIMn0_TTL_ON                        (0x01U)    /* Pn0 TTL input buffer */

/*
    Port Output Mode Registers (POMn)
*/
/* Pn7 pin output mode selection (POMn7) */
#define _00_POMn7_NCH_OFF                       (0x00U)    /* Pn7 normal output mode */
#define _80_POMn7_NCH_ON                        (0x80U)    /* Pn7 N-ch open-drain output mode */
/* Pn6 pin output mode selection (POMn6) */
#define _00_POMn6_NCH_OFF                       (0x00U)    /* Pn6 normal output mode */
#define _40_POMn6_NCH_ON                        (0x40U)    /* Pn6 N-ch open-drain output mode */
/* Pn5 pin output mode selection (POMn5) */
#define _00_POMn5_NCH_OFF                       (0x00U)    /* Pn5 normal output mode */
#define _20_POMn5_NCH_ON                        (0x20U)    /* Pn5 N-ch open-drain output mode */
/* Pn4 pin output mode selection (POMn4) */
#define _00_POMn4_NCH_OFF                       (0x00U)    /* Pn4 normal output mode */
#define _10_POMn4_NCH_ON                        (0x10U)    /* Pn4 N-ch open-drain output mode */
/* Pn3 pin output mode selection (POMn3) */
#define _00_POMn3_NCH_OFF                       (0x00U)    /* Pn3 normal output mode */
#define _08_POMn3_NCH_ON                        (0x08U)    /* Pn3 N-ch open-drain output mode */
/* Pn2 pin output mode selection (POMn2) */
#define _00_POMn2_NCH_OFF                       (0x00U)    /* Pn2 normal output mode */
#define _04_POMn2_NCH_ON                        (0x04U)    /* Pn2 N-ch open-drain output mode */
/* Pn1 pin output mode selection (POMn1) */
#define _00_POMn1_NCH_OFF                       (0x00U)    /* Pn1 normal output mode */
#define _02_POMn1_NCH_ON                        (0x02U)    /* Pn1 N-ch open-drain output mode */
/* Pn0 pin output mode selection (POMn0) */
#define _00_POMn0_NCH_OFF                       (0x00U)    /* Pn0 normal output mode */
#define _01_POMn0_NCH_ON                        (0x01U)    /* Pn0 N-ch open-drain output mode */

/*
    Port Mode Control Registers (PMCn)
*/
/* Selection of digital I/O or analog input for Pn7 (PMCn7) */
#define _00_PMCn7_DI_ON                         (0x00U)    /* digital I/O */
#define _80_PMCn7_NOT_USE                       (0x80U)    /* analog input */
/* Selection of digital I/O or analog input for Pn6 (PMCn6) */
#define _00_PMCn6_DI_ON                         (0x00U)    /* digital I/O */
#define _40_PMCn6_NOT_USE                       (0x40U)    /* analog input */
/* Selection of digital I/O or analog input for Pn5 (PMCn5) */
#define _00_PMCn5_DI_ON                         (0x00U)    /* digital I/O */
#define _20_PMCn5_NOT_USE                       (0x20U)    /* analog input */
/* Selection of digital I/O or analog input for Pn4 (PMCn4) */
#define _00_PMCn4_DI_ON                         (0x00U)    /* digital I/O */
#define _10_PMCn4_NOT_USE                       (0x10U)    /* analog input */
/* Selection of digital I/O or analog input for Pn3 (PMCn3) */
#define _00_PMCn3_DI_ON                         (0x00U)    /* digital I/O */
#define _08_PMCn3_NOT_USE                       (0x08U)    /* analog input */
/* Selection of digital I/O or analog input for Pn2 (PMCn2) */
#define _00_PMCn2_DI_ON                         (0x00U)     /* digital I/O */
#define _04_PMCn2_NOT_USE                       (0x04U)    /* analog input */
/* Selection of digital I/O or analog input for Pn1 (PMCn1) */
#define _00_PMCn1_DI_ON                         (0x00U)    /* digital I/O */
#define _02_PMCn1_NOT_USE                       (0x02U)    /* analog input */
/* Selection of digital I/O or analog input for Pn0 (PMCn0) */
#define _00_PMCn0_DI_ON                         (0x00U)    /* digital I/O */
#define _01_PMCn0_NOT_USE                       (0x01U)    /* analog input */

/*
    Port Input Threshold Control Register (PITHLn)
*/
/* Pn7 pin input threshold selection (PITHLn7) */
#define _00_PITHLn7_SCHMITT3_OFF                (0x00U)    /* schmitt1 input */
#define _80_PITHLn7_SCHMITT3_ON                 (0x80U)    /* schmitt3 input */
/* Pn6 pin input threshold selection (PITHLn6) */
#define _00_PITHLn6_SCHMITT3_OFF                (0x00U)    /* schmitt1 input */
#define _40_PITHLn6_SCHMITT3_ON                 (0x40U)    /* schmitt3 input */
/* Pn5 pin input threshold selection (PITHLn5) */
#define _00_PITHLn5_SCHMITT3_OFF                (0x00U)    /* schmitt1 input */
#define _20_PITHLn5_SCHMITT3_ON                 (0x20U)    /* schmitt3 input */
/* Pn4 pin input threshold selection (PITHLn4) */
#define _00_PITHLn4_SCHMITT3_OFF                (0x00U)    /* schmitt1 input */
#define _10_PITHLn4_SCHMITT3_ON                 (0x10U)    /* schmitt3 input */
/* Pn3 pin input threshold selection (PITHLn3) */
#define _00_PITHLn3_SCHMITT3_OFF                (0x00U)    /* schmitt1 input */
#define _08_PITHLn3_SCHMITT3_ON                 (0x08U)    /* schmitt3 input */
/* Pn2 pin input threshold selection (PITHLn2) */
#define _00_PITHLn2_SCHMITT3_OFF                (0x00U)    /* schmitt1 input */
#define _04_PITHLn2_SCHMITT3_ON                 (0x04U)    /* schmitt3 input */
/* Pn1 pin input threshold selection (PITHLn1) */
#define _00_PITHLn1_SCHMITT3_OFF                (0x00U)    /* schmitt1 input */
#define _02_PITHLn1_SCHMITT3_ON                 (0x02U)    /* schmitt3 input */
/* Pn0 pin input threshold selection (PITHLn0) */
#define _00_PITHLn0_SCHMITT3_OFF                (0x00U)    /* schmitt1 input */
#define _01_PITHLn0_SCHMITT3_ON                 (0x01U)    /* schmitt3 input */

/*
    Port Output Slew Rate Select Register (PSRSEL)
*/
/* P140/PCLBUZ0 pin output mode selection (PSR140) */
#define _DF_PSR140_NORMAL                       (0xDFU)    /* normal mode */
#define _20_PSR140_SLOW                         (0x20U)    /* slow mode */
/* P14/SCK01/SCL01/TO06/TRDIOC0 pin output mode selection (PSR14) */
#define _EF_PSR14_NORMAL                        (0xEFU)    /* normal mode */
#define _10_PSR14_SLOW                          (0x10U)    /* slow mode */
/* P120/SO01/TO07/TRDIOD0 pin output mode selection (PSR120) */
#define _F7_PSR120_NORMAL                       (0xF7U)    /* normal mode */
#define _08_PSR120_SLOW                         (0x08U)    /* slow mode */
/* P30/TO01/TRDIOD1/SNZOUT0 pin output mode selection (PSR30) */
#define _FB_PSR30_NORMAL                        (0xFBU)    /* normal mode */
#define _04_PSR30_SLOW                          (0x04U)    /* slow mode */
/* P12/SO10/TO11/(TRDIOD0)/TXD1/SNZOUT3 pin output mode selection (PSR12) */
#define _FD_PSR12_NORMAL                        (0xFDU)    /* normal mode */
#define _02_PSR12_SLOW                          (0x02U)    /* slow mode */
/* P10/SCK10/TO13/TRJO0/SCL10/LTXD1/CTXD0 pin output mode selection (PSR10) */
#define _FE_PSR10_NORMAL                        (0xFEU)    /* normal mode */
#define _01_PSR10_SLOW                          (0x01U)    /* slow mode */

/*
    SNOOZE Status Output Control Register 0 (PSNZCNT0)
*/
/* SNZOUT1 active level (SNZACT1) */
/* for PIOR61 = 0 */
#define _00_P125_SNZOUT1_ACTIVE_H               (0x00U)    /* active level of SNOOZE status output to P125 is "H" */
#define _20_P125_SNZOUT1_ACTIVE_L               (0x20U)    /* active level of SNOOZE status output to P125 is "L" */
/* for PIOR61 = 1 */
#define _00_P56_SNZOUT1_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P56 is "H" */
#define _20_P56_SNZOUT1_ACTIVE_L                (0x20U)    /* active level of SNOOZE status output to P56 is "L" */
/* SNZOUT1 enable/disable (OUTEN1) */
/* for PIOR61 = 0 */
#define _00_P125_SNZOUT1_DISABLE                (0x00U)    /* SNOOZE status output to P125 is disabled */
#define _10_P125_SNZOUT1_ENABLE                 (0x10U)    /* SNOOZE status output to P125 is enabled */
/* for PIOR61 = 1 */
#define _00_P56_SNZOUT1_DISABLE                 (0x00U)    /* SNOOZE status output to P56 is disabled */
#define _10_P56_SNZOUT1_ENABLE                  (0x10U)    /* SNOOZE status output to P56 is enabled */
/* SNZOUT0 active level (SNZACT0) */
/* for PIOR60 = 0 */
#define _00_P30_SNZOUT0_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P30 is "H" */
#define _02_P30_SNZOUT0_ACTIVE_L                (0x02U)    /* active level of SNOOZE status output to P30 is "L" */
/* for PIOR60 = 1 */
#define _00_P57_SNZOUT0_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P57 is "H" */
#define _02_P57_SNZOUT0_ACTIVE_L                (0x02U)    /* active level of SNOOZE status output to P57 is "L" */
/* SNZOUT0 enable/disable (OUTEN0) */
/* for PIOR60 = 0 */
#define _00_P30_SNZOUT0_DISABLE                 (0x00U)    /* SNOOZE status output to P30 is disabled */
#define _01_P30_SNZOUT0_ENABLE                  (0x01U)    /* SNOOZE status output to P30 is enabled */
/* for PIOR60 = 1 */
#define _00_P57_SNZOUT0_DISABLE                 (0x00U)    /* SNOOZE status output to P57 is disabled */
#define _01_P57_SNZOUT0_ENABLE                  (0x01U)    /* SNOOZE status output to P57 is enabled */

/*
    SNOOZE Status Output Control Register 1 (PSNZCNT1)
*/
/* SNZOUT3 active level (SNZACT3) */
/* for PIOR63 = 0 */
#define _00_P12_SNZOUT3_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P12 is "H" */
#define _20_P12_SNZOUT3_ACTIVE_L                (0x20U)    /* active level of SNOOZE status output to P12 is "L" */
/* for PIOR63 = 1 */
#define _00_P64_SNZOUT3_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P64 is "H" */
#define _20_P64_SNZOUT3_ACTIVE_L                (0x20U)    /* active level of SNOOZE status output to P64 is "L" */
/* SNZOUT3 enable/disable (OUTEN3) */
/* for PIOR63 = 0 */
#define _00_P12_SNZOUT3_DISABLE                 (0x00U)    /* SNOOZE status output to P12 is disabled */
#define _10_P12_SNZOUT3_ENABLE                  (0x10U)    /* SNOOZE status output to P12 is enabled */
/* for PIOR63 = 1 */
#define _00_P64_SNZOUT3_DISABLE                 (0x00U)    /* SNOOZE status output to P64 is disabled */
#define _10_P64_SNZOUT3_ENABLE                  (0x10U)    /* SNOOZE status output to P64 is enabled */
/* SNZOUT2 active level (SNZACT2) */
/* for PIOR62 = 0 */
#define _00_P41_SNZOUT2_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P42 is "H" */
#define _02_P41_SNZOUT2_ACTIVE_L                (0x02U)    /* active level of SNOOZE status output to P42 is "L" */
/* for PIOR62 = 1 */
#define _00_P65_SNZOUT2_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P65 is "H" */
#define _02_P65_SNZOUT2_ACTIVE_L                (0x02U)    /* active level of SNOOZE status output to P65 is "L" */
/* SNZOUT2 enable/disable (OUTEN2) */
/* for PIOR62 = 0 */
#define _00_P41_SNZOUT2_DISABLE                 (0x00U)    /* SNOOZE status output to P42 is disabled */
#define _01_P41_SNZOUT2_ENABLE                  (0x01U)    /* SNOOZE status output to P42 is enabled */
/* for PIOR62 = 1 */
#define _00_P65_SNZOUT2_DISABLE                 (0x00U)    /* SNOOZE status output to P65 is disabled */
#define _01_P65_SNZOUT2_ENABLE                  (0x01U)    /* SNOOZE status output to P65 is enabled */

/*
    SNOOZE Status Output Control Register 2 (PSNZCNT2)
*/
/* SNZOUT5 active level (SNZACT5) */
/* for PIOR65 = 0 */
#define _00_P71_SNZOUT5_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P71 is "H" */
#define _20_P71_SNZOUT5_ACTIVE_L                (0x20U)    /* active level of SNOOZE status output to P71 is "L" */
/* for PIOR65 = 1 */
#define _00_P156_SNZOUT5_ACTIVE_H               (0x00U)    /* active level of SNOOZE status output to P156 is "H" */
#define _20_P156_SNZOUT5_ACTIVE_L               (0x20U)    /* active level of SNOOZE status output to P156 is "L" */
/* SNZOUT5 enable/disable (OUTEN5) */
/* for PIOR65 = 0 */
#define _00_P71_SNZOUT5_DISABLE                 (0x00U)    /* SNOOZE status output to P71 is disabled */
#define _10_P71_SNZOUT5_ENABLE                  (0x10U)    /* SNOOZE status output to P71 is enabled */
/* for PIOR65 = 1 */
#define _00_P156_SNZOUT5_DISABLE                (0x00U)    /* SNOOZE status output to P156 is disabled */
#define _10_P156_SNZOUT5_ENABLE                 (0x10U)    /* SNOOZE status output to P156 is enabled */
/* SNZOUT4 active level (SNZACT4) */
/* for PIOR64 = 0 */
#define _00_P70_SNZOUT4_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P70 is "H" */
#define _02_P70_SNZOUT4_ACTIVE_L                (0x02U)    /* active level of SNOOZE status output to P70 is "L" */
/* for PIOR64 = 1 */
#define _00_P157_SNZOUT4_ACTIVE_H               (0x00U)    /* active level of SNOOZE status output to P157 is "H" */
#define _02_P157_SNZOUT4_ACTIVE_L               (0x02U)    /* active level of SNOOZE status output to P157 is "L" */
/* SNZOUT4 enable/disable (OUTEN4) */
/* for PIOR64 = 0 */
#define _00_P70_SNZOUT4_DISABLE                 (0x00U)    /* SNOOZE status output to P70 is disabled */
#define _01_P70_SNZOUT4_ENABLE                  (0x01U)    /* SNOOZE status output to P70 is enabled */
/* for PIOR64 = 1 */
#define _00_P157_SNZOUT4_DISABLE                (0x00U)    /* SNOOZE status output to P157 is disabled */
#define _01_P157_SNZOUT4_ENABLE                 (0x01U)    /* SNOOZE status output to P157 is enabled */

/*
    SNOOZE Status Output Control Register 3 (PSNZCNT3)
*/
/* SNZOUT7 active level (SNZACT7) */
/* for PIOR67 = 0 */
#define _00_P73_SNZOUT7_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P73 is "H" */
#define _20_P73_SNZOUT7_ACTIVE_L                (0x20U)    /* active level of SNOOZE status output to P73 is "L" */
/* for PIOR67 = 1 */
#define _00_P154_SNZOUT7_ACTIVE_H               (0x00U)    /* active level of SNOOZE status output to P154 is "H" */
#define _20_P154_SNZOUT7_ACTIVE_L               (0x20U)    /* active level of SNOOZE status output to P154 is "L" */
/* SNZOUT7 enable/disable (OUTEN7) */
/* for PIOR67 = 0 */
#define _00_P73_SNZOUT7_DISABLE                 (0x00U)    /* SNOOZE status output to P73 is disabled */
#define _10_P73_SNZOUT7_ENABLE                  (0x10U)    /* SNOOZE status output to P73 is enabled */
/* for PIOR67 = 1 */
#define _00_P154_SNZOUT7_DISABLE                (0x00U)    /* SNOOZE status output to P154 is disabled */
#define _10_P154_SNZOUT7_ENABLE                 (0x10U)    /* SNOOZE status output to P154 is enabled */
/* SNZOUT6 active level (SNZACT6) */
/* for PIOR66 = 0 */
#define _00_P72_SNZOUT6_ACTIVE_H                (0x00U)    /* active level of SNOOZE status output to P72 is "H" */
#define _02_P72_SNZOUT6_ACTIVE_L                (0x02U)    /* active level of SNOOZE status output to P72 is "L" */
/* for PIOR66 = 1 */
#define _00_P155_SNZOUT6_ACTIVE_H               (0x00U)    /* active level of SNOOZE status output to P155 is "H" */
#define _02_P155_SNZOUT6_ACTIVE_L               (0x02U)    /* active level of SNOOZE status output to P155 is "L" */
/* SNZOUT6 enable/disable (OUTEN6) */
/* for PIOR66 = 0 */
#define _00_P72_SNZOUT6_DISABLE                 (0x00U)    /* SNOOZE status output to P72 is disabled */
#define _01_P72_SNZOUT6_ENABLE                  (0x01U)    /* SNOOZE status output to P72 is enabled */
/* for PIOR66 = 1 */
#define _00_P155_SNZOUT6_DISABLE                (0x00U)    /* SNOOZE status output to P155 is disabled */
#define _01_P155_SNZOUT6_ENABLE                 (0x01U)    /* SNOOZE status output to P155 is enabled */

/*
    Port Mode Select Register (PMS)
*/
/* Select the data read in output mode (PMS0) */
#define _00_PMN_VALUES                          (0x00U)    /* read Pmn register values */
#define _01_DIGITAL_OUTPUT_LEVEL                (0x01U)    /* read digital output level */

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
