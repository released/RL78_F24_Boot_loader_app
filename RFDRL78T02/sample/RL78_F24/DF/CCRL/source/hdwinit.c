/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type02) (Data Flash)
    
    File Name       : hdwinit.c
    Program Version : V1.00.00
    Device(s)       : RL78/F24 microcontroller
    Description     : Sample hardware initialization
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

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "iodefine.h"

/**********************************************************************************************************************
  Prototype declaration
**********************************************************************************************************************/
void hdwinit(void);

/**********************************************************************************************************************
 * Function name : hdwinit
 *********************************************************************************************************************/
/**
 *  Hardware initialization.
 *  
 *  @param[in]      -
 *  @return         ---
 */
/*********************************************************************************************************************/
void hdwinit(void)
{
    __DI();
    
    /* Set clock */
    CMC     = 0x00u;
    MSTOP   = 1u;       /* CSC(Oscillation circuit stop X1) */
    
    MCM0    = 0u;
    
    XTSTOP  = 1u;       /* CSC(Oscillation circuit stop XT1) */
    OSMC    = 0x10u;
    
    CSS     = 0u;
    
    /* Start HOCO. It must be started before flash control. */
    HIOSTOP = 0u;
}
/**********************************************************************************************************************
 End of function hdwinit
 *********************************************************************************************************************/
