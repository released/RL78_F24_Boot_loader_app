/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type02) (Extra Area FSW)
    
    File Name       : main.c
    Program Version : V1.00.00
    Device(s)       : RL78/F24 microcontroller
    Description     : Sample program for extra area FSW control
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
#include "sample_control_extra_fsw.h"
#include "sample_defines.h"
#include "sample_config.h"

#include "r_rfd_common_api.h"

#include "iodefine.h"

/**********************************************************************************************************************
  Prototype declaration
**********************************************************************************************************************/
int main(void);

/**********************************************************************************************************************
 * Function name : main
 *********************************************************************************************************************/
/**
 *  Sample main.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - SAMPLE_ENUM_RET_STS_OK                 : Successful completion
 *                  - SAMPLE_ENUM_RET_ERR_PARAMETER          : Parameter error
 *                  - SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED    : Mode mismatched error
 *                  - SAMPLE_ENUM_RET_ERR_CONFIGURATION      : Configuration error
 *                  - SAMPLE_ENUM_RET_ERR_CHECK_WRITE_DATA   : Check write data error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_SET_EXTRA_AREA : Set extra area command error
 */
/*********************************************************************************************************************/
int main(void)
{
    /* Local variable definition */
    e_rfd_ret_t    l_e_rfd_status_flag;
    e_sample_ret_t l_e_sam_ret_value;
    
    /* Check whether HOCO is already started */
    if (SAMPLE_VALUE_U01_MASK0_1BIT == HIOSTOP)
    {
        /* Initialize RFD */
        l_e_rfd_status_flag = R_RFD_Init(CPU_FREQUENCY);
        
        if (R_RFD_ENUM_RET_STS_OK == l_e_rfd_status_flag)
        {
            /* Set FSW and check */
            l_e_sam_ret_value = Sample_ExtraFSWControl(START_BLOCK, END_BLOCK);
        }
        else
        {
            /* Failed to initialize RFD */
            l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_PARAMETER;
        }
    }
    else
    {
        /* HOCO is not started */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_CONFIGURATION;
    }
    
    return ((int)l_e_sam_ret_value);
}
/**********************************************************************************************************************
 End of function main
 *********************************************************************************************************************/
