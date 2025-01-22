/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type02) (Extra Area FSW)
    
    File Name       : sample_control_extra_fsw.c
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
#include "sample_control_common.h"
#include "sample_defines.h"

#include "r_rfd_common_api.h"
#include "r_rfd_common_get_api.h"
#include "r_rfd_extra_area_api.h"

/**********************************************************************************************************************
 * Function name : Sample_ExtraFSWControl
 *********************************************************************************************************************/
#define  SAMPLE_START_SECTION_SMP_EX
#include "sample_memmap.h"
/*********************************************************************************************************************/
/**
 *  Sample extra area FSW control.
 *  Set FSW
 *  
 *  @param[in]      i_u16_start_block_number : 
 *                    Start block number for FSW
 *  @param[in]      i_u16_end_block_number : 
 *                    End block number for FSW
 *  @return         Execution result status
 *                  - SAMPLE_ENUM_RET_STS_OK                 : Successful completion
 *                  - SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED    : Mode mismatched error
 *                  - SAMPLE_ENUM_RET_ERR_CHECK_WRITE_DATA   : Check write data (FSW) error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_SET_EXTRA_AREA : Set extra area command (FSW) error
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_sample_ret_t Sample_ExtraFSWControl(uint16_t i_u16_start_block_number, 
                                                     uint16_t i_u16_end_block_number)
{
    /* Local variable definition */
    e_rfd_ret_t      l_e_rfd_ret_status;
    e_sample_ret_t   l_e_sam_ret_status;
    e_sample_ret_t   l_e_sam_ret_value;
    bool             l_e_sam_error_flag;
    uint16_t         l_u16_get_start_block_number;
    uint16_t         l_u16_get_end_block_number;
    
    /* Set local variables */
    l_e_sam_ret_value            = SAMPLE_ENUM_RET_STS_OK;
    l_e_sam_error_flag           = false;
    l_u16_get_start_block_number = 0u;
    l_u16_get_end_block_number   = 0u;
    
    /******************************************************************************************************************
     * Set the code flash programming mode
     *****************************************************************************************************************/
    l_e_rfd_ret_status = R_RFD_SetFlashMemoryMode(R_RFD_ENUM_FLASH_MODE_CODE_PROGRAMMING);
    
    if (R_RFD_ENUM_RET_STS_OK != l_e_rfd_ret_status)
    {
        l_e_sam_error_flag = true;
        l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * Set FSW
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        R_RFD_SetExtraFSWReq(i_u16_start_block_number, i_u16_end_block_number);
        l_e_sam_ret_status = Sample_CheckExtraSeqEnd();
        
        if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_SET_EXTRA_AREA;
        }
        else
        {
            /* No operation */
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * Set non-programmable mode
     *****************************************************************************************************************/
    l_e_rfd_ret_status = R_RFD_SetFlashMemoryMode(R_RFD_ENUM_FLASH_MODE_CODE_TO_NONPROGRAMMABLE);
    
    if (R_RFD_ENUM_RET_STS_OK != l_e_rfd_ret_status)
    {
        l_e_sam_error_flag = true;
        l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * Check write data (FSW)
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        R_RFD_GetFSW(&l_u16_get_start_block_number, &l_u16_get_end_block_number);
        if ((i_u16_start_block_number != l_u16_get_start_block_number) 
            || (i_u16_end_block_number != l_u16_get_end_block_number))
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CHECK_WRITE_DATA;
            }
        else
        {
            /* No operation */
        }
    }
    
    return (l_e_sam_ret_value);
}

#define  SAMPLE_END_SECTION_SMP_EX
#include "sample_memmap.h"
/**********************************************************************************************************************
 End of function Sample_ExtraFSWControl
 *********************************************************************************************************************/
