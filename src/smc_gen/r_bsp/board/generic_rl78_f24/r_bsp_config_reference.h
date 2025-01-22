/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_bsp_config_reference.h
* H/W Platform : GENERIC_RL78_F24
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 28.02.2022 1.20     First Release
*         : 31.05.2022 1.30     Added the following macro definition.
*                                - BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE
*         : 11.11.2022 1.40     Changed the initial values of the following macro definitions from 0 to 1.
*                                - BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE
*                                - BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE
*                               Deleted the contents of setting prohibition from the comment of
*                               the macro definition BSP_CFG_HOCO_DIVIDE.
*         : 31.01.2023 1.50     Fixed typo in history.
*         : 28.02.2023 1.60     Deleted the macro definition BSP_CFG_ADC_ENABLE and BSP_CFG_ADCLK_DIVIDE.
*                               Added the version number of Smart Configurator.
*                               Modified the comment related to the version number of Smart Configurator.
***********************************************************************************************************************/

#ifndef R_BSP_CONFIG_REF_HEADER_FILE
#define R_BSP_CONFIG_REF_HEADER_FILE
/*************************************************
 * MCU information
 *************************************************/
/*
 R 7 F 124F P J 3 AFB
 | | |  |   | | |  |__not used                   Package type
 | | |  |   | | |_____not used                   Ambient operating temperature range
 | | |  |   | |_______BSP_CFG_MCU_PART_ROM_SIZE  ROM capacity
 | | |  |   |_________BSP_CFG_MCU_PART_PIN_NUM   Pin count
 | | |  |_____________not used                   RL78/F24
 | | |________________BSP_CFG_MCU_PART_ROM_TYPE  Device type
 | |__________________not used                   Renesas MCU
 |____________________not used                   Renesas semiconductor product
*/

/* ROM capacity
   (Code Flash/Data Flash/RAM)
 J = 256KB/16KB/24KB : 0x0
*/
#define BSP_CFG_MCU_PART_ROM_SIZE (0x0)

/* Pin count
 B = 32-pin  : 0x0
 G = 48-pin  : 0x1
 L = 64-pin  : 0x2
 M = 80-pin  : 0x3
 P = 100-pin : 0x4
*/
#define BSP_CFG_MCU_PART_PIN_NUM (0x4)

/* group
 124F = RL78/F24 : (true)
*/
#define BSP_CFG_MCU_PART_HAS_DATA_FLASH (true)

/* Device type
 F = Flash memory : 0
*/
#define BSP_CFG_MCU_PART_ROM_TYPE (0)

#if defined(__ICCRL78__)
/* Option byte setting(When using IAR) */
#define BSP_CFG_OPTBYTE0_VALUE (0xFFU)
#define BSP_CFG_OPTBYTE1_VALUE (0xFFU)
#define BSP_CFG_OPTBYTE2_VALUE (0xFFU)
#define BSP_CFG_OPTBYTE3_VALUE (0xFFU)
#define BSP_CFG_OPTBYTE4_VALUE (0xFFU)
/* Security ID Codes for On-Chip Debugging setting(When using IAR) */
#define BSP_CFG_SECUID0_VALUE (0xFFU)
#define BSP_CFG_SECUID1_VALUE (0xFFU)
#define BSP_CFG_SECUID2_VALUE (0xFFU)
#define BSP_CFG_SECUID3_VALUE (0xFFU)
#define BSP_CFG_SECUID4_VALUE (0xFFU)
#define BSP_CFG_SECUID5_VALUE (0xFFU)
#define BSP_CFG_SECUID6_VALUE (0xFFU)
#define BSP_CFG_SECUID7_VALUE (0xFFU)
#define BSP_CFG_SECUID8_VALUE (0xFFU)
#define BSP_CFG_SECUID9_VALUE (0xFFU)
#define BSP_CFG_SECUIDA_VALUE (0xFFU)
#define BSP_CFG_SECUIDB_VALUE (0xFFU)
#define BSP_CFG_SECUIDC_VALUE (0xFFU)
#define BSP_CFG_SECUIDD_VALUE (0xFFU)
#define BSP_CFG_SECUIDE_VALUE (0xFFU)
#define BSP_CFG_SECUIDF_VALUE (0xFFU)
#endif

/*************************************************
 * Pin assignment setting
 *************************************************/
/* Peripheral I/O redirection register(PIOR0-PIOR00)
   100/80-pin
 0 : TI00 - P17
 1 : TI00 - P66

   64/48-pin
 0 : TI00 - P17
 1 : TI00 - -
*/
#define BSP_CFG_PIOR00 (0)

/* Peripheral I/O redirection register(PIOR0-PIOR01)
   100/80-pin
 0 : TI01 - P30
 1 : TI01 - P126

   64/48-pin
 0 : TI01 - P30
 1 : TI01 - -
*/
#define BSP_CFG_PIOR01 (0)

/* Peripheral I/O redirection register(PIOR0-PIOR02)
   100/80-pin
 0 : TI02 - P16
 1 : TI02 - P67

   64/48-pin
 0 : TI02 - P16
 1 : TI02 - -
*/
#define BSP_CFG_PIOR02 (0)

/* Peripheral I/O redirection register(PIOR0-PIOR03)
   100-pin
 0 : TI03 - P125
 1 : TI03 - P127

   80/64/48-pin
 0 : TI03 - P125
 1 : TI03 - -
*/
#define BSP_CFG_PIOR03 (0)

/* Peripheral I/O redirection register(PIOR0-PIOR04)
   100/80-pin
 0 : TI04 - P13
 1 : TI04 - P01

   64/48-pin
 0 : TI04 - P13
 1 : TI04 - -
*/
#define BSP_CFG_PIOR04 (0)

/* Peripheral I/O redirection register(PIOR0-PIOR05)
   100/80/64/48-pin
 0 : TI05 - P15
 1 : TI05 - P00
*/
#define BSP_CFG_PIOR05 (0)

/* Peripheral I/O redirection register(PIOR0-PIOR06)
   100/80-pin
 0 : TI06 - P14
 1 : TI06 - P02

   64/48-pin
 0 : TI06 - P14
 1 : TI06 - -
*/
#define BSP_CFG_PIOR06 (0)

/* Peripheral I/O redirection register(PIOR0-PIOR07)
   100/80-pin
 0 : TI07 - P120
 1 : TI07 - P44

   64/48-pin
 0 : TI07 - P120
 1 : TI07 - -
*/
#define BSP_CFG_PIOR07 (0)

/* Peripheral I/O redirection register(PIOR1-PIOR10)
   100/80-pin
 0 : TO00 - P17
 1 : TO00 - P66

   64/48/32-pin
 0 : TO00 - P17
 1 : TO00 - -
*/
#define BSP_CFG_PIOR10 (0)

/* Peripheral I/O redirection register(PIOR1-PIOR11)
 (PIOR90=0)
   100/80-pin
 0 : TO01 - P30
 1 : TO01 - P126

   64/48/32-pin
 0 : TO01 - P30
 1 : TO01 - -

 (PIOR90=1)
   100/80/64/48/32-pin
 0 : TO01 - P30
 1 : TO01 - P60
*/
#define BSP_CFG_PIOR11 (0)

/* Peripheral I/O redirection register(PIOR1-PIOR12)
 (PIOR90=0)
   100/80-pin
 0 : TO02 - P16
 1 : TO02 - P67

   64/48/32-pin
 0 : TO02 - P16
 1 : TO02 - -

 (PIOR90=1)
   100/80/64/48/32-pin
 0 : TO02 - P16
 1 : TO02 - P61
*/
#define BSP_CFG_PIOR12 (0)

/* Peripheral I/O redirection register(PIOR1-PIOR13)
 (PIOR90=0)
   100-pin
 0 : TO03 - P125
 1 : TO03 - P127

   80/64/48/32-pin
 0 : TO03 - P125
 1 : TO03 - -

 (PIOR90=1)
   100/80/64/48/32-pin
 0 : TO03 - P125
 1 : TO03 - P62
*/
#define BSP_CFG_PIOR13 (0)

/* Peripheral I/O redirection register(PIOR1-PIOR14)
   100/80-pin
 0 : TO04 - P13
 1 : TO04 - P01

   64/48/32-pin
 0 : TO04 - P13
 1 : TO04 - -
*/
#define BSP_CFG_PIOR14 (0)

/* Peripheral I/O redirection register(PIOR1-PIOR15)
   100/80/64/48-pin
 0 : TO05 - P15
 1 : TO05 - P00

   32-pin
 0 : TO05 - P15
 1 : TO05 - -
*/
#define BSP_CFG_PIOR15 (0)

/* Peripheral I/O redirection register(PIOR1-PIOR16)
   100/80-pin
 0 : TO06 - P14
 1 : TO06 - P02

   64/48/32-pin
 0 : TO06 - P14
 1 : TO06 - -
*/
#define BSP_CFG_PIOR16 (0)

/* Peripheral I/O redirection register(PIOR1-PIOR17)
 (PIOR90=0)
   100/80-pin
 0 : TO07 - P120
 1 : TO07 - P44

   64/48/32-pin
 0 : TO07 - P120
 1 : TO07 - -

 (PIOR90=1)
   100/80/64/48/32-pin
 0 : TO07 - P120
 1 : TO07 - P63
*/
#define BSP_CFG_PIOR17 (0)

/* Peripheral I/O redirection register(PIOR2-PIOR20)
   100/80-pin
 0 : TI10 - P41
 1 : TI10 - P45
*/
#define BSP_CFG_PIOR20 (0)

/* Peripheral I/O redirection register(PIOR2-PIOR21)
   100/80-pin
 0 : TI11 - P12
 1 : TI11 - P54
*/
#define BSP_CFG_PIOR21 (0)

/* Peripheral I/O redirection register(PIOR2-PIOR22)
   100/80-pin
 0 : TI12 - P11
 1 : TI12 - P46
*/
#define BSP_CFG_PIOR22 (0)

/* Peripheral I/O redirection register(PIOR2-PIOR23)
   100/80-pin
 0 : TI13 - P10
 1 : TI13 - P55
*/
#define BSP_CFG_PIOR23 (0)

/* Peripheral I/O redirection register(PIOR2-PIOR24)
   100/80-pin
 0 : TI14 - P31
 1 : TI14 - P64
*/
#define BSP_CFG_PIOR24 (0)

/* Peripheral I/O redirection register(PIOR2-PIOR25)
   100/80-pin
 0 : TI15 - P70
 1 : TI15 - P56
*/
#define BSP_CFG_PIOR25 (0)

/* Peripheral I/O redirection register(PIOR2-PIOR26)
   100/80-pin
 0 : TI16 - P32
 1 : TI16 - P65
*/
#define BSP_CFG_PIOR26 (0)

/* Peripheral I/O redirection register(PIOR2-PIOR27)
   100/80-pin
 0 : TI17 - P71
 1 : TI17 - P57
*/
#define BSP_CFG_PIOR27 (0)

/* Peripheral I/O redirection register(PIOR3-PIOR30)
   100/80-pin
 0 : TO10 - P41
 1 : TO10 - P45
*/
#define BSP_CFG_PIOR30 (0)

/* Peripheral I/O redirection register(PIOR3-PIOR31)
   100/80-pin
 0 : TO11 - P12
 1 : TO11 - P54
*/
#define BSP_CFG_PIOR31 (0)

/* Peripheral I/O redirection register(PIOR3-PIOR32)
   100/80-pin
 0 : TO12 - P11
 1 : TO12 - P46
*/
#define BSP_CFG_PIOR32 (0)

/* Peripheral I/O redirection register(PIOR3-PIOR33)
   100/80-pin
 0 : TO13 - P10
 1 : TO13 - P55
*/
#define BSP_CFG_PIOR33 (0)

/* Peripheral I/O redirection register(PIOR3-PIOR34)
   100/80-pin
 0 : TO14 - P31
 1 : TO14 - P64
*/
#define BSP_CFG_PIOR34 (0)

/* Peripheral I/O redirection register(PIOR3-PIOR35)
   100/80-pin
 0 : TO15 - P70
 1 : TO15 - P56
*/
#define BSP_CFG_PIOR35 (0)

/* Peripheral I/O redirection register(PIOR3-PIOR36)
   100/80-pin
 0 : TO16 - P32
 1 : TO16 - P65
*/
#define BSP_CFG_PIOR36 (0)

/* Peripheral I/O redirection register(PIOR3-PIOR37)
   100/80-pin
 0 : TO17 - P71
 1 : TO17 - P57
*/
#define BSP_CFG_PIOR37 (0)

/* Peripheral I/O redirection register(PIOR4-PIOR40)
   100/80/64/48/32-pin
 0 : SI00/SDA00/RxD0 - P16
     SO00/TxD0       - P15
     SCL00/SCK00     - P17
     SSI00           - P30
 1 : SI00/SDA00/RxD0 - P61
     SO00/TxD0       - P62
     SCL00/SCK00     - P60
     SSI00           - P63
*/
#define BSP_CFG_PIOR40 (0)

/* Peripheral I/O redirection register(PIOR4-PIOR41)
   100/80/64-pin
 0 : SI01  - P13
     SO01  - P120
     SCK01 - P14
     SSI01 - P125
 1 : SI01  - P53
     SO01  - P51
     SCK01 - P52
     SSI01 - P50

   48/32-pin
 0 : SI01  - P13
     SO01  - P120
     SCK01 - P14
     SSI01 - P125
 1 : SI01  - -
     SO01  - -
     SCK01 - -
     SSI01 - -
*/
#define BSP_CFG_PIOR41 (0)

/* Peripheral I/O redirection register(PIOR4-PIOR42)
 (PIOR91=0)
   100/80-pin
 0 : SI10/RxD1 - P11
     SO10/TxD1 - P12
     SCK10     - P10
     SSI10     - P54
 1 : SI10/RxD1 - P75
     SO10/TxD1 - P74
     SCK10     - P76
     SSI10     - P77

   64-pin
 0 : SI10/RxD1 - P11
     SO10/TxD1 - P12
     SCK10     - P10
     SSI10     - -
 1 : SI10/RxD1 - P75
     SO10/TxD1 - P74
     SCK10     - P76
     SSI10     - P77

   48/32-pin
 0 : SI10/RxD1 - P11
     SO10/TxD1 - P12
     SCK10     - P10
     SSI10     - -
 1 : SI10/RxD1 - -
     SO10/TxD1 - -
     SCK10     - -
     SSI10     - -

 (PIOR91=1)
   100/80-pin
 0 : SI10/RxD1 - P41
     SO10/TxD1 - P12
     SCK10     - P120
     SSI10     - P54
 1 : SI10/RxD1 - P75
     SO10/TxD1 - P74
     SCK10     - P76
     SSI10     - P77

   64-pin
 0 : SI10/RxD1 - P41
     SO10/TxD1 - P12
     SCK10     - P120
     SSI10     - -
 1 : SI10/RxD1 - P75
     SO10/TxD1 - P74
     SCK10     - P76
     SSI10     - P77

   48/32-pin
 0 : SI10/RxD1 - P41
     SO10/TxD1 - P12
     SCK10     - P120
     SSI10     - -
 1 : SI10/RxD1 - -
     SO10/TxD1 - -
     SCK10     - -
     SSI10     - -
*/
#define BSP_CFG_PIOR42 (0)

/* Peripheral I/O redirection register(PIOR4-PIOR43)
 (PIOR92=0)
   100-pin
 0 : SI11  - P70
     SO11  - P72
     SCK11 - P71
     SSI11 - P73
 1 : SI11  - P152
     SO11  - P151
     SCK11 - P153
     SSI11 - P150

   80/64/48-pin
 0 : SI11  - P70
     SO11  - P72
     SCK11 - P71
     SSI11 - P73
 1 : SI11  - -
     SO11  - -
     SCK11 - -
     SSI11 - -

 (PIOR92=1)
   100-pin
 0 : SI11  - P70
     SO11  - P32
     SCK11 - P71
     SSI11 - P73
 1 : SI11  - P152
     SO11  - P151
     SCK11 - P153
     SSI11 - P150

   80/64/48-pin
 0 : SI11  - P70
     SO11  - P32
     SCK11 - P71
     SSI11 - P73
 1 : SI11  - -
     SO11  - -
     SCK11 - -
     SSI11 - -
*/
#define BSP_CFG_PIOR43 (0)

/* Peripheral I/O redirection register(PIOR4-PIOR44)
   100/80/64-pin
 0 : LRxD0 - P14
     LTxD0 - P13
 1 : LRxD0 - P43
     LTxD0 - P42

   48/32-pin
 0 : LRxD0 - P14
     LTxD0 - P13
 1 : LRxD0 - -
     LTxD0 - -
*/
#define BSP_CFG_PIOR44 (0)

/* Peripheral I/O redirection register(PIOR4-PIOR45)
 (PIOR93=0)
   100-pin
 0 : LRxD1 - P11
     LTxD1 - P10
 1 : LRxD1 - P107
     LTxD1 - P106

   80/64/48/32-pin
 0 : LRxD1 - P11
     LTxD1 - P10
 1 : LRxD1 - -
     LTxD1 - -

 (PIOR93=1)
   100/80/64/48/32-pin
 0 : LRxD1 - P11
     LTxD1 - P10
 1 : LRxD1 - P125
     LTxD1 - P120
*/
#define BSP_CFG_PIOR45 (0)

/* Peripheral I/O redirection register(PIOR4-PIOR46)
   100/80/64/48-pin
 0 : CRxD0 - P11
     CTxD0 - P10
 1 : CRxD0 - P73
     CTxD0 - P72

   32-pin
 0 : CRxD0 - P11
     CTxD0 - P10
 1 : CRxD0 - -
     CTxD0 - -
*/
#define BSP_CFG_PIOR46 (0)

/* Peripheral I/O redirection register(PIOR5-PIOR50)
   100/80-pin
 0 : KR0 - P70
     KR1 - P71
     KR2 - P72
     KR3 - P73
     KR4 - P74
     KR5 - P75
     KR6 - P76
     KR7 - P77
 1 : KR0 - -
     KR1 - -
     KR2 - -
     KR3 - -
     KR4 - -
     KR5 - -
     KR6 - -
     KR7 - -

   64-pin
 0 : KR0 - P70
     KR1 - P71
     KR2 - P72
     KR3 - P73
     KR4 - P74
     KR5 - P75
     KR6 - P76
     KR7 - P77
 1 : KR0 - P87
     KR1 - P90
     KR2 - P91
     KR3 - P92
     KR4 - P93
     KR5 - P94
     KR6 - P95
     KR7 - P96

   48-pin
 0 : KR0 - P70
     KR1 - P71
     KR2 - P72
     KR3 - P73
     KR4 - -
     KR5 - -
     KR6 - -
     KR7 - -
 1 : KR0 - P83
     KR1 - P84
     KR2 - P85
     KR3 - P86
     KR4 - P87
     KR5 - P90
     KR6 - P91
     KR7 - P92

   32-pin
 0 : KR0 - -
     KR1 - -
     KR2 - -
     KR3 - -
     KR4 - -
     KR5 - -
     KR6 - -
     KR7 - -
 1 : KR0 - P80
     KR1 - P81
     KR2 - P82
     KR3 - P83
     KR4 - P84
     KR5 - P85
     KR6 - -
     KR7 - -
*/
#define BSP_CFG_PIOR50 (0)

/* Peripheral I/O redirection register(PIOR5-PIOR52)
   100/80/64/48-pin
 0 : INTP2 - P30
 1 : INTP2 - P31

   32-pin
 0 : INTP2 - P30
 1 : INTP2 - -
*/
#define BSP_CFG_PIOR52 (0)

/* Peripheral I/O redirection register(PIOR5-PIOR53)
   100/80/64-pin
 0 : INTP3 - P17
 1 : INTP3 - P50

   48/32-pin
 0 : INTP3 - P17
 1 : INTP3 - -
*/
#define BSP_CFG_PIOR53 (0)

/* Peripheral I/O redirection register(PIOR6-PIOR60)
   100/80-pin
 0 : SNZOUT0 - P30
 1 : SNZOUT0 - P57
*/
#define BSP_CFG_PIOR60 (0)

/* Peripheral I/O redirection register(PIOR6-PIOR61)
   100/80-pin
 0 : SNZOUT1 - P125
 1 : SNZOUT1 - P56
*/
#define BSP_CFG_PIOR61 (0)

/* Peripheral I/O redirection register(PIOR6-PIOR62)
   100/80-pin
 0 : SNZOUT2 - P41
 1 : SNZOUT2 - P65
*/
#define BSP_CFG_PIOR62 (0)

/* Peripheral I/O redirection register(PIOR6-PIOR63)
   100/80-pin
 0 : SNZOUT3 - P12
 1 : SNZOUT3 - P64
*/
#define BSP_CFG_PIOR63 (0)

/* Peripheral I/O redirection register(PIOR6-PIOR64)
   100-pin
 0 : SNZOUT4 - P70
 1 : SNZOUT4 - P157

   80-pin
 0 : SNZOUT4 - P70
 1 : SNZOUT4 - -
*/
#define BSP_CFG_PIOR64 (0)

/* Peripheral I/O redirection register(PIOR6-PIOR65)
   100-pin
 0 : SNZOUT5 - P71
 1 : SNZOUT5 - P156

   80-pin
 0 : SNZOUT5 - P71
 1 : SNZOUT5 - -
*/
#define BSP_CFG_PIOR65 (0)

/* Peripheral I/O redirection register(PIOR6-PIOR66)
   100-pin
 0 : SNZOUT6 - P72
 1 : SNZOUT6 - P155

   80-pin
 0 : SNZOUT6 - P72
 1 : SNZOUT6 - -
*/
#define BSP_CFG_PIOR66 (0)

/* Peripheral I/O redirection register(PIOR6-PIOR67)
   100-pin
 0 : SNZOUT7 - P73
 1 : SNZOUT7 - P154

   80-pin
 0 : SNZOUT7 - P73
 1 : SNZOUT7 - -
*/
#define BSP_CFG_PIOR67 (0)

/* Peripheral I/O redirection register(PIOR7-PIOR70)
   100/80/64/48/32-pin
 0 : TRDIOA0/TRDCLK0 - P13
 1 : TRDIOA0/TRDCLK0 - P15
*/
#define BSP_CFG_PIOR70 (0)

/* Peripheral I/O redirection register(PIOR7-PIOR71)
   100/80/64/48/32-pin
 0 : TRDIOB0 - P125
 1 : TRDIOB0 - P11
*/
#define BSP_CFG_PIOR71 (0)

/* Peripheral I/O redirection register(PIOR7-PIOR73)
   100/80/64/48/32-pin
 0 : TRDIOD0 - P120
 1 : TRDIOD0 - P12
*/
#define BSP_CFG_PIOR73 (0)

/* Peripheral I/O redirection register(PIOR8-PIOR80)
   100-pin
 0 : RTC1HZ - P15
 1 : RTC1HZ - P03
*/
#define BSP_CFG_PIOR80 (0)

/* Peripheral I/O redirection register(PIOR9-PIOR90)
 (PIOR11=0)
   100/80/64/48/32-pin
 0 : TO01 - P30
 1 : TO01 - P30

 (PIOR11=1)
   100/80-pin
 0 : TO01 - P126
 1 : TO01 - P60

   64/48/32-pin
 0 : TO01 - -
 1 : TO01 - P60

 (PIOR12=0)
   100/80/64/48/32-pin
 0 : TO02 - P16
 1 : TO02 - P16

 (PIOR12=1)
   100/80-pin
 0 : TO02 - P67
 1 : TO02 - P61

   64/48/32-pin
 0 : TO02 - -
 1 : TO02 - P61

 (PIOR13=0)
   100/80/64/48/32-pin
 0 : TO03 - P125
 1 : TO03 - P125

 (PIOR13=1)
   100-pin
 0 : TO03 - P127
 1 : TO03 - P62

   80/64/48/32-pin
 0 : TO03 - -
 1 : TO03 - P62

 (PIOR17=0)
   100/80/64/48/32-pin
 0 : TO07 - P120
 1 : TO07 - P120

 (PIOR17=1)
   100/80-pin
 0 : TO07 - P44
 1 : TO07 - P63

   64/48/32-pin
 0 : TO07 - -
 1 : TO07 - P63
*/
#define BSP_CFG_PIOR90 (0)

/* Peripheral I/O redirection register(PIOR9-PIOR91)
 (PIOR42=0)
   100/80/64/48/32-pin
 0 : SI10/RXD1 - P11
     SCK10     - P10
 1 : SI10/RXD1 - P41
     SCK10     - P120

 (PIOR42=1)
   100/80/64-pin
 0 : SI10/RXD1 - P75
     SCK10     - P76
 1 : SI10/RXD1 - P75
     SCK10     - P76

   48/32-pin
 0 : SI10/RXD1 - -
     SCK10     - -
 1 : SI10/RXD1 - -
     SCK10     - -
*/
#define BSP_CFG_PIOR91 (0)

/* Peripheral I/O redirection register(PIOR9-PIOR92)
 (PIOR43=0)
   100/80/64/48-pin
 0 : SO11 - P72
 1 : SO11 - P32

 (PIOR43=1)
   100-pin
 0 : SO11 - P151
 1 : SO11 - P151

   80/64/48-pin
 0 : SO11 - -
 1 : SO11 - -
*/
#define BSP_CFG_PIOR92 (0)

/* Peripheral I/O redirection register(PIOR9-PIOR93)
 (PIOR45=0)
   100/80/64/48/32-pin
 0 : LRXD1 - P11
     LTXD1 - P10
 1 : LRXD1 - P11
     LTXD1 - P10

 (PIOR45=1)
   100-pin
 0 : LRXD1 - P107
     LTXD1 - P106
 1 : LRXD1 - P125
     LTXD1 - P120

   80/64/48/32-pin
 0 : LRXD1 - -
     LTXD1 - -
 1 : LRXD1 - P125
     LTXD1 - P120
*/
#define BSP_CFG_PIOR93 (0)

/***********************************************************
 * Invalid memory access detection control register (IAWCTL)
 ***********************************************************/
/* Control of invalid memory access detection
   Invalid Memory Access Detection Control Register(IAWCTL)
   IAWEN
 0 : Disable the detection of invalid memory access.
 1 : Enable the detection of invalid memory access.
*/
#define BSP_CFG_INVALID_MEMORY_ACCESS_DETECTION_ENABLE (0)

/* RAM guard space
   Invalid Memory Access Detection Control Register(IAWCTL)
   GRAM1/GRAM0
 0 : Disabled. RAM can be written to.
 1 : The 128 bytes of space starting at the start address in the RAM specified with RAMSAR register.
 2 : The 256 bytes of space starting at the start address in the RAM specified with RAMSAR register.
 3 : The 512 bytes of space starting at the start address in the RAM specified with RAMSAR register.
*/
#define BSP_CFG_RAM_GUARD_FUNC (0)

/* Port function SFR guard control bit
   Invalid Memory Access Detection Control Register(IAWCTL)
   GPORT
 0 : Disabled. Control registers of port function can be read or written to.
 1 : Enabled. Writing to control registers of port function is disabled. Reading is enabled.
 [Guarded SFR] PMxx, PUxx, PIMxx, POMxx, PMCxx, PITHLxx, PIORx
*/
#define BSP_CFG_PORT_FUNCTION_GUARD (0)

/* Interrupt function SFR guard control bit
   Invalid Memory Access Detection Control Register(IAWCTL)
   GINT
 0 : Disabled. Registers of interrupt function can be read or written to.
 1 : Enabled. Writing to registers of interrupt function is disabled. Reading is enabled.
 [Guarded SFR] IFxx, MKxx, PRxx, EGPx, EGNx
*/
#define BSP_CFG_INT_FUNCTION_GUARD (0)

/* Clock control function SFR guard control bit
   Invalid Memory Access Detection Control Register(IAWCTL)
   GCSC
 0 : Disabled. Control registers of clock control function and voltage detector can be read or written to.
 1 : Enabled. Writing to control registers of clock control function and voltage detector is disabled.
     Reading is enabled.
 [Guarded SFR] CMC, CSC, OSTS, CKC, PERx, OSMC, LVIM, LVIS, CANCKSEL, LINCKSEL,
               CKSEL, PLLCTL, MDIV, RTCCL, POCRES, STPSTC, CLMTES, ADCKS
*/
#define BSP_CFG_CHIP_STATE_CTRL_GUARD (0)

/*************************************************
 * Data flash
 *************************************************/
/* Data flash access control
   Data Flash Control Register(DFLCTL)
   DFLEN
 0 : Disables data flash access
 1 : Enables data flash access
*/
#define BSP_CFG_DATA_FLASH_ACCESS_ENABLE (0)

/*************************************************
 * Definition for switching functions
 *************************************************/
/* Startup select
 0 : Enable BSP startup program.
 1 : Disable BSP startup program.(e.g. Using user startup program.)
*/
#define BSP_CFG_STARTUP_DISABLE (0)

/* Initialization of peripheral functions by Code Generator/Smart Configurator
 0 : Disable initialization of peripheral functions by Code Generator/Smart Configurator.
 1 : Enable initialization of peripheral functions by Code Generator/Smart Configurator.
*/
#define BSP_CFG_CONFIGURATOR_SELECT (0)

/* Version number of Smart Configurator.
   This macro definitions is updated by Smart Configurator.
   If you are using e2studio, set the following values.
   2021-04 : 1001
   2021-07 : 1010
   2021-10 : 1010
   2022-01 : 1030
   2023-04 : 1060
   If you are using the standalone version of Smart Configurator,
   set the following values.
   v1.0.1  : 1001
   v1.1.0  : 1010
   v1.3.0  : 1030
   v1.6.0  : 1060
*/
#define BSP_CFG_CONFIGURATOR_VERSION    (1001)

/* API function disable(R_BSP_StartClock, R_BSP_StopClock)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_GetFclkFreqHz)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE (0)

/* API function disable(R_BSP_SetClockSource)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_ChangeClockSetting)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE (1)

/* API function disable(R_BSP_SoftwareDelay)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE (1)

/* Parameter check enable
 0 : Disable parameter check.
 1 : Enable parameter check.
*/
#define BSP_CFG_PARAM_CHECKING_ENABLE (1)

/*************************************************
 * Clock settings
 *************************************************/
/* High-speed system clock pin operation mode
   Clock Operation Mode Control Register(CMC)
   EXCLK/OSCSEL
 0 : Input port mode
 1 : X1 oscillation mode
 2 : External clock input mode
*/
#define BSP_CFG_HISYSCLK_SOURCE (0)

/* Subsystem clock pin operation mode
   Clock Operation Mode Control Register(CMC)
   EXCLKS/OSCSELS
   (Note) The 32-pin products do not have a subsystem clock(fSUB)
 0 : Input port mode
 1 : XT1 oscillation mode
 2 : External clock input mode
*/
#define BSP_CFG_SUBCLK_SOURCE (0)

/* XT1 oscillator oscillation mode selection
   Clock Operation Mode Control Register(CMC)
   AMPHS1/AMPHS0
 0 : Low power consumption oscillation (default) Oscillation margin : Medium
 1 : Normal oscillation                          Oscillation margin : High
 2 : Ultra-low power consumption oscillation     Oscillation margin : Low
*/
#define BSP_CFG_XT1_OSCMODE (0)

/* Input clock frequency in Hz(High-speed system clock(fMX))
*/
#define BSP_CFG_FMX_HZ (20000000)

/* Control of X1 clock oscillation frequency
   Clock Operation Mode Control Register(CMC)
   AMPH
 0 : 2 MHz <= fX <= 10 MHz
 1 : 2 MHz <= fX <= 20 MHz
 Set the value corresponding to the setting of BSP_CFG_FMX_HZ
*/

/* Selection of CPU/peripheral hardware clock(fCLK)
   System Clock Control Register(CKC)
   CSS
 0 : Main system/PLL select clock (fMP)
 1 : Subsystem/low-speed on-chip oscillator select clock (fSL)
*/
#define BSP_CFG_FCLK_SOURCE (0)

/* Main system clock (fMAIN) operation control
   System Clock Control Register(CKC)
   MCM0
 0 : Selects the high-speed on-chip oscillator clock (fIH) as the main system clock (fMAIN)
 1 : Selects the high-speed system clock (fMX) as the main system clock (fMAIN)
*/
#define BSP_CFG_MAINCLK_SOURCE (0)

/* High-speed system clock operation control
   Clock Operation Status Control Register(CSC)
   MSTOP
 (X1 oscillation mode)
  0 : X1 oscillator operating
  1 : X1 oscillator stopped
 (External clock input mode)
  0 : External clock from EXCLK pin is valid
  1 : External clock from EXCLK pin is invalid
 (Input port mode)
  0 : Input port
  1 : Input port
*/
#define BSP_CFG_HISYSCLK_OPERATION (1)

/* Subsystem clock operation control
   Clock Operation Status Control Register(CSC)
   XTSTOP
   (Note) In the 32-pin products, use the this macro set to 1
          without changing from the default.
 (XT1 oscillation mode)
  0 : XT1 oscillator operating
  1 : XT1 oscillator stopped
 (External clock input mode)
  0 : External clock from EXCLKS pin is valid
  1 : External clock from EXCLKS pin is invalid
 (Input port mode)
  0 : Input port
  1 : Input port
*/
#define BSP_CFG_SUBCLK_OPERATION (1)

/* Oscillation stabilization time selection
   Oscillation Stabilization Time Select Register(OSTS)
   OSTS2/OSTS1/OSTS0
 0 : 2^8/fX(fX = 10 MHz : 25.6us, fX = 20 MHz : 12.8us)
 1 : 2^9/fX(fX = 10 MHz : 51.2us, fX = 20 MHz : 25.6us)
 2 : 2^10/fX(fX = 10 MHz : 102.4us, fX = 20 MHz : 51.2us)
 3 : 2^11/fX(fX = 10 MHz : 204.8us, fX = 20 MHz : 102.4us)
 4 : 2^13/fX(fX = 10 MHz : 819.2us, fX = 20 MHz : 409.6us)
 5 : 2^15/fX(fX = 10 MHz : 3.27ms, fX = 20 MHz : 1.63ms)
 6 : 2^17/fX(fX = 10 MHz : 13.10ms, fX = 20 MHz : 6.55ms)
 7 : 2^18/fX(fX = 10 MHz : 26.21ms, fX = 20 MHz : 13.10ms)
*/
#define BSP_CFG_X1_WAIT_TIME_SEL (7)

/* Setting in STOP mode or HALT mode while subsystem/low-speed on-chip oscillator select clock is selected as CPU clock
   Operation Speed Mode Control Register(OSMC)
   RTCLPC
 0 : Enables supply of subsystem/low-speed on-chip oscillator select clock to peripheral functions.
 1 : Stops supply of subsystem/low-speed on-chip oscillator select clock to peripheral functions.
*/
#define BSP_CFG_ALLOW_FSL_IN_STOPHALT (0)

/* Low-speed on-chip oscillator operation control
   Operation Speed Mode Control Register(OSMC)
   WUTMMCK0
 0 : Low-speed on-chip oscillator stopped
 1 : Low-speed on-chip oscillator operating
*/
#define BSP_CFG_FIL_OPERATION (0)

/* Selection of high-speed on-chip oscillator clock frequency
   High-Speed On-Chip Oscillator Frequency Select Register(HOCODIV)
   HOCODIV2/HOCODIV1/HOCODIV0
 (FRQSEL4 = 0, FRQSEL3 = 0)
  0 : fIH = 32 MHz
  1 : fIH = 16 MHz
  2 : fIH =  8 MHz
  3 : fIH =  4 MHz
  4 : fIH =  2 MHz
 (FRQSEL4 = 0, FRQSEL3 = 1)
  0 : fIH = 40 MHz
  1 : fIH = 20 MHz
  2 : fIH = 10 MHz
  3 : fIH =  5 MHz
 (FRQSEL4 = 1, FRQSEL3 = 0)
  0 : fIH = 64 MHz
  1 : fIH = 32 MHz
  2 : fIH = 16 MHz
  3 : fIH =  8 MHz
  4 : fIH =  4 MHz
 (FRQSEL4 = 1, FRQSEL3 = 1)
  0 : fIH = 80 MHz
  1 : fIH = 40 MHz
  2 : fIH = 20 MHz
  3 : fIH = 10 MHz
  4 : fIH =  5 MHz
*/
#define BSP_CFG_HOCO_DIVIDE (0)

/* Control of supplying or stopping CAN X1 clock (fX)
   CAN Clock Select Register(CANCKSEL)
   CAN0MCKE
 0 : Stops CAN X1 clock (fX) supply.
 1 : Enables CAN X1 clock (fX) supply.
*/
#define BSP_CFG_CAN_CLOCK_OPERATION (0)

/* Control of supplying or stopping LIN1 communication clock source
   LIN Clock Select Register(LINCKSEL)
   LIN1MCKE
 0 : Stops LIN communication clock source supply.
 1 : Enables LIN communication clock source supply.
*/
#define BSP_CFG_LIN1_CLOCK_OPERATION (0)

/* Control of supplying or stopping LIN0 communication clock source
   LIN Clock Select Register(LINCKSEL)
   LIN0MCKE
 0 : Stops LIN communication clock source supply.
 1 : Enables LIN communication clock source supply.
*/
#define BSP_CFG_LIN0_CLOCK_OPERATION (0)

/* Control of selecting LIN1 communication clock source
   LIN Clock Select Register(LINCKSEL)
   LIN1MCK
 0 : Selects the fCLK clock.
 1 : Selects the fMX clock.
*/
#define BSP_CFG_LIN1_CLOCK_SOURCE (0)

/* Control of selecting LIN0 communication clock source
   LIN Clock Select Register(LINCKSEL)
   LIN0MCK
 0 : Selects the fCLK clock.
 1 : Selects the fMX clock.
*/
#define BSP_CFG_LIN0_CLOCK_SOURCE (0)

/* Control of PLL frequency division selection
   Clock Select Register(CKSEL)
   FPLLDIV
   Control of PLL division selection
   PLL Control Register(PLLCTL)
   PLLDIV0
 0 : No division
 1 : Divides the clock frequency by 2.
 2 : Divides the clock frequency by 4.
*/
#define BSP_CFG_PLL_DIVIDE (1)

/* Control of PLL input clock (fPLLI) division selection
   Clock Select Register(CKSEL)
   FMAINDIV1/FMAINDIV0
 0 : No division
 1 : Divided by 2 (fMAIN = 16 MHz input only)
 2 : Divided by 4 (fMAIN = 20 MHz input only)
*/
#define BSP_CFG_FMAIN_DIVIDE (0)

/* Control of TRDe clock selection
   Clock Select Register(CKSEL)
   TRD_CKSEL
 0 : Selects fCLK or fMP
 1 : Selects fSL
*/
#define BSP_CFG_TRD_CLOCK_SOURCE (0)

/* Control of subsystem/low-speed on-chip oscillator selection clock (fSL) selection
   Clock Select Register(CKSEL)
   SELLOSC
   (Note) In the 32-pin products, use the this macro set to 1.
 0 : Selects fSUB and stopping the low-speed on-chip oscillator
 1 : Selects fIL and running the low-speed on-chip oscillator
*/
#define BSP_CFG_SUBSYSCLK_SOURCE (0)

/* Control of setting lock-up wait counter
   PLL Control Register(PLLCTL)
   LCKSEL1/LCKSEL0
 0 : Selects 128/fMAIN
 1 : Selects 256/fMAIN
 2 : Selects 512/fMAIN
 3 : Selects 1024/fMAIN
*/
#define BSP_CFG_LOCKUP_WAIT_COUNT_SEL (0)

/* Control of PLL multiplication selection
   PLL Control Register(PLLCTL)
   PLLMULA/PLLMUL
 0 : Multiples the clock frequency by 12.
 1 : Multiples the clock frequency by 16.
 2 : Multiples the clock frequency by 10.
 3 : Multiples the clock frequency by 20.
*/
#define BSP_CFG_PLL_MULTI (0)

/* Control of clock mode selection
   PLL Control Register(PLLCTL)
   SELPLL
 0 : Clock through mode (fMAIN)
 1 : PLL-clock-selected mode (fPLL)
*/
#define BSP_CFG_PLL_MODE (0)

/* Control of PLL operation
   PLL Control Register(PLLCTL)
   PLLON
 0 : Stops PLL operation.
 1 : Starts PLL operation.
*/
#define BSP_CFG_PLL_OPERATION (0)

/* Input clock frequency in Hz(PLL clock(fPLL))
*/
#define BSP_CFG_FPLL_HZ (40000000)

/* fMP clock division control
   fMP Clock Division Register(MDIV)
   MDIV2/MDIV1/MDIV0
 0 : Selects fMP.
 1 : Selects fMP/2.
 2 : Selects fMP/4.
 3 : Selects fMP/8.
 4 : Selects fMP/16.
 5 : Selects fMP/32.
 6 : Selects fMP/64.
*/
#define BSP_CFG_FMP_DIVIDE (0)

/* Operation setting at initial setting */
/* Starts the high-speed on-chip oscillator at initialization
 0 : Stops the high-speed on-chip oscillator at initialization
 1 : Starts the high-speed on-chip oscillator at initialization
*/
#define BSP_CFG_FIH_START_ON_STARTUP (1)

/* This macro lets other modules no if a RTOS is being used.
 0 : RTOS is not used.
 1 : FreeRTOS is used.(This is not available.)
 2 : embOS is used.(This is not available.)
 3 : MicroC_OS is used.(This is not available.)
 4 : Renesas ITRON is used.
*/
#define BSP_CFG_RTOS_USED (0)

/* Oscillation stabilization wait time setting
   The value to be set is the number of loops in the process of executing the NOP instruction once by the for statement.
   Set an appropriate value according to your environment.
*/
/* Subsystem clock oscillation stabilization wait time */
/* If the main system clock 32 MHz, 800000 means 300 ms. */
#define BSP_CFG_SUBWAITTIME (800000U)

/* High-speed on-chip oscillator clock oscillation stabilization wait time */
/* If the main system clock 32 MHz, 560 means 105.4 us. */
#define BSP_CFG_FIHWAITTIME (560U)

/* PLL multiplication effective wait time */
/* If the main system clock 32 MHz, 5 means 1.15 us. */
#define BSP_CFG_PLLWAITTIME (5U)

/* If the user would like to determine if a warm start reset has occurred, then they may enable one or more of the
   following callback definitions AND provide a call back function name for the respective callback
   function (to be defined by the user). Setting BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED = 1 will result
   in a callback to the user defined my_sw_warmstart_prec_function just prior to the initialization of the C
   runtime environment by bsp_init_system.
   Setting BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED = 1 will result in a callback to the user defined
   my_sw_warmstart_postc_function just after the initialization of the C runtime environment by bsp_init_hardware.
*/
#define BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED (0)
#define BSP_CFG_USER_WARM_START_PRE_C_FUNCTION             my_sw_warmstart_prec_function

#define BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED (0)
#define BSP_CFG_USER_WARM_START_POST_C_FUNCTION             my_sw_warmstart_postc_function

/* If the user sets the window open period of watchdog timer to 50% or 75%,
   set the following macro definition(BSP_CFG_WDT_REFRESH_ENABLE) to 2(50%) or 3(75%)
   and specify the callback function name for each callback function(to be defined by the user).
   Setting BSP_CFG_WDT_REFRESH_ENABLE == 2 or 3 will result in a callback to the user defined
   my_sw_wdt_refresh_init_function just prior to the clock is set by bsp_init_system.
   In addition, a callback to the user defined my_sw_wdt_refresh_setting_function occurs
   during the oscillation stabilization wait time of the subsystem clock.
*/
#define BSP_CFG_WDT_REFRESH_ENABLE                (0)
#define BSP_CFG_USER_WDT_REFRESH_INIT_FUNCTION    my_sw_wdt_refresh_init_function
#define BSP_CFG_USER_WDT_REFRESH_SETTING_FUNCTION my_sw_wdt_refresh_setting_function

#endif /* R_BSP_CONFIG_REF_HEADER_FILE */

