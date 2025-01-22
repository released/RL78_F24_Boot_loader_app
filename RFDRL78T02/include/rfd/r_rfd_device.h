/**********************************************************************************************************************
    Program Name    : Renesas Flash Driver (RFD RL78 Type02)
    
    File Name       : r_rfd_device.h
    Program Version : V1.00
    Device(s)       : RL78/F24 microcontroller
    Description     : Device dependent header file
**********************************************************************************************************************/

/**********************************************************************************************************************
    DISCLAIMER
    This software is supplied by Renesas Electronics Corporation and is only intended for use with
    Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
    Corporation and is protected under all applicable laws, including copyright laws.
    THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
    TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
    ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
    BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
    Renesas reserves the right, without notice, to make changes to this software and to discontinue the
    availability of this software. By using this software, you agree to the additional terms and conditions
    found by accessing the following link:
    http://www.renesas.com/disclaimer
    
    Copyright (C) 2021-2022 Renesas Electronics Corporation. All rights reserved.
**********************************************************************************************************************/

#ifndef R_RFD_DEVICE_H
#define R_RFD_DEVICE_H

/* Flash memory control registers (2nd SFR) */
#define R_RFD_REG_U08_DFLCTL       (*(volatile __near unsigned char  *)0x0090u)
#define R_RFD_REG_U01_DFLCTL_DFLEN (((volatile __near bitf08_rfd_t   *)0x0090u)->no0)
#define R_RFD_REG_U16_FLSEC        (*(volatile __near unsigned short *)0xFFB0u)
#define R_RFD_REG_U16_FLFSWS       (*(volatile __near unsigned short *)0xFFB2u)
#define R_RFD_REG_U16_FLFSWE       (*(volatile __near unsigned short *)0xFFB4u)
#define R_RFD_REG_U08_FSSET        (*(volatile __near unsigned char  *)0xFFB6u)
#define R_RFD_REG_U08_FSSE         (*(volatile __near unsigned char  *)0xFFB7u)
#define R_RFD_REG_U08_PFCMD        (*(volatile __near unsigned char  *)0xFFC0u)
#define R_RFD_REG_U08_PFS          (*(volatile __near unsigned char  *)0xFFC1u)
#define R_RFD_REG_U08_FLPMC        (*(volatile __near unsigned char  *)0x00C0u)
#define R_RFD_REG_U08_FLARS        (*(volatile __near unsigned char  *)0x00C1u)
#define R_RFD_REG_U16_FLAPL        (*(volatile __near unsigned short *)0x00C2u)
#define R_RFD_REG_U08_FLAPH        (*(volatile __near unsigned char  *)0x00C4u)
#define R_RFD_REG_U08_FSSQ         (*(volatile __near unsigned char  *)0x00C5u)
#define R_RFD_REG_U01_FSSQ_FSSTP   (((volatile __near bitf08_rfd_t   *)0x00C5u)->no6)
#define R_RFD_REG_U16_FLSEDL       (*(volatile __near unsigned short *)0x00C6u)
#define R_RFD_REG_U08_FLSEDH       (*(volatile __near unsigned char  *)0x00C8u)
#define R_RFD_REG_U08_FLRST        (*(volatile __near unsigned char  *)0x00C9u)
#define R_RFD_REG_U08_FSASTL       (*(volatile __near unsigned char  *)0x00CAu)
#define R_RFD_REG_U08_FSASTH       (*(volatile __near unsigned char  *)0x00CBu)
#define R_RFD_REG_U16_FLWL         (*(volatile __near unsigned short *)0x00CCu)
#define R_RFD_REG_U16_FLWH         (*(volatile __near unsigned short *)0x00CEu)

/* Internal definitions */
#define R_RFD_VALUE_U01_DFLEN_DATA_FLASH_ACCESS_DISABLE          (0u)
#define R_RFD_VALUE_U01_DFLEN_DATA_FLASH_ACCESS_ENABLE           (1u)
#define R_RFD_VALUE_U08_FLARS_USER_AREA                          (0x00u)
#define R_RFD_VALUE_U08_FLARS_EXTRA_AREA                         (0x01u)
#define R_RFD_VALUE_U08_FSSQ_WRITE                               (0x81u)
#define R_RFD_VALUE_U08_FSSQ_IVERIFY_CF                          (0x82u)
#define R_RFD_VALUE_U08_FSSQ_IVERIFY_DF                          (0x8Au)
#define R_RFD_VALUE_U08_FSSQ_BLANKCHECK_CF                       (0x83u)
#define R_RFD_VALUE_U08_FSSQ_BLANKCHECK_DF                       (0x8Bu)
#define R_RFD_VALUE_U08_FSSQ_ERASE                               (0x84u)
#define R_RFD_VALUE_U08_FSSQ_CLEAR                               (0x00u)
#define R_RFD_VALUE_U08_FSSE_FSW                                 (0x82u)
#define R_RFD_VALUE_U08_FSSE_SECURITY_FLAG                       (0x81u)
#define R_RFD_VALUE_U08_FSSE_CLEAR                               (0x00u)
#define R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE            (0xA5u)
#define R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE               (0x08u)
#define R_RFD_VALUE_U08_FLPMC_MODE_CODE_FLASH_PROGRAMMING        (0x82u)
#define R_RFD_VALUE_U08_FLPMC_MODE_DATA_FLASH_PROGRAMMING        (0x10u)
#define R_RFD_VALUE_U08_FLPMC_TRANSFER_1ST_LAYER                 (0x12u)
#define R_RFD_VALUE_U08_FLPMC_TRANSFER_1ST_LAYER_INVERSION       (0xEDu)
#define R_RFD_VALUE_U08_FLPMC_TRANSFER_2ND_LAYER                 (0x92u)
#define R_RFD_VALUE_U08_FLPMC_TRANSFER_2ND_LAYER_INVERSION       (0x6Du)
#define R_RFD_VALUE_U08_FLRST_ON                                 (0x01u)
#define R_RFD_VALUE_U08_FLRST_OFF                                (0x00u)
#define R_RFD_VALUE_U01_FSSQ_FSSTP_ON                            (1u)
#define R_RFD_VALUE_U08_FSSET_BOOT_CLUSTER_0                     (0x80u)
#define R_RFD_VALUE_U08_FSSET_BOOT_CLUSTER_1                     (0xC0u)

#define R_RFD_VALUE_U08_INIT_VARIABLE                            (0x00u)
#define R_RFD_VALUE_U08_SHIFT_8BIT                               (8u)
#define R_RFD_VALUE_U08_SHIFT_16BIT                              (16u)

#define R_RFD_VALUE_U08_FREQUENCY_LOWER_LIMIT                    (2u)
#define R_RFD_VALUE_U08_FREQUENCY_UPPER_LIMIT                    (40u)
#define R_RFD_VALUE_U08_FREQUENCY_ADJUST                         (1u)
#define R_RFD_VALUE_U08_FREQUENCY_SHIFT_ADJUST                   (1u)
#define R_RFD_VALUE_U08_FREQUENCY_CALC_THRESHOLD                 (23u)
#define R_RFD_VALUE_U16_CODE_FLASH_BLOCK_ADDR_LOW                (0x003Fu)
#define R_RFD_VALUE_U16_CODE_FLASH_BLOCK_ADDR_HIGH               (0x03C0u)
#define R_RFD_VALUE_U16_CODE_FLASH_BLOCK_ADDR_END                (0x03FFu)
#define R_RFD_VALUE_U08_CODE_FLASH_SHIFT_LOW_ADDR                (10u)
#define R_RFD_VALUE_U08_CODE_FLASH_SHIFT_HIGH_ADDR               (6u)
#define R_RFD_VALUE_U16_DATA_FLASH_ADDR_LOW                      (0x1000u)
#define R_RFD_VALUE_U08_DATA_FLASH_ADDR_HIGH                     (0x0Fu)
#define R_RFD_VALUE_U08_DATA_FLASH_BLOCK_ADDR_LOW                (0x3Fu)
#define R_RFD_VALUE_U16_DATA_FLASH_BLOCK_ADDR_END                (0x03FFu)
#define R_RFD_VALUE_U08_DATA_FLASH_SHIFT_LOW_ADDR                (10u)

#define R_RFD_VALUE_U08_MASK1_8BIT                               (0xFFu)
#define R_RFD_VALUE_U16_MASK1_16BIT                              (0xFFFFu)

#define R_RFD_VALUE_U08_MASK1_PFS_FPRERR                         (0x01u)
#define R_RFD_VALUE_U08_MASK1_FSASTH_SQEND                       (0x40u)
#define R_RFD_VALUE_U08_MASK1_FSASTH_ESQEND                      (0x80u)
#define R_RFD_VALUE_U08_MASK1_FSSET_TMSPMD_AND_TMBTSEL           (0xC0u)
#define R_RFD_VALUE_U08_MASK0_FSSET_TMSPMD_AND_TMBTSEL           (0x3Fu)
#define R_RFD_VALUE_U08_MASK1_FSSET_TMSPMD                       (0x80u)
#define R_RFD_VALUE_U08_MASK1_FSASTL_ERROR_FLAG                  (0x3Fu)
#define R_RFD_VALUE_U16_MASK1_FLFSW_BLOCK_NUMBER                 (0x03FFu)

#define R_RFD_VALUE_U16_MASK0_ERASE_PROTECT_FLAG                 (0xFBFFu)
#define R_RFD_VALUE_U16_MASK0_WRITE_PROTECT_FLAG                 (0xEFFFu)
#define R_RFD_VALUE_U16_MASK0_BOOT_CLUSTER_PROTECT_FLAG          (0xFDFFu)
#define R_RFD_VALUE_U16_MASK0_BOOT_FLAG                          (0xFEFFu)
#define R_RFD_VALUE_U16_MASK1_BOOT_FLAG                          (0x0100u)
#define R_RFD_VALUE_U16_MASK1_FSW_BLOCK_INFO                     (0x03FFu)

#endif /* end of R_RFD_DEVICE_H */
