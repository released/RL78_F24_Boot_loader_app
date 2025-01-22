/**********************************************************************************************************************
    Program Name    : Renesas Flash Driver (RFD RL78 Type02)
    
    File Name       : r_rfd_common_api.c
    Program Version : V1.00
    Device(s)       : RL78/F24 microcontroller
    Description     : Common Flash Control program
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
#include "r_rfd_common_api.h"
#include "r_rfd_common_userown.h"

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_DATA
#include "r_rfd_memmap.h"
    /* CPU Frequency configuration for r_rfd_wait_count */
    uint8_t g_u08_cpu_frequency                = R_RFD_VALUE_U08_INIT_VARIABLE;
#define  R_RFD_END_SECTION_RFD_DATA
#include "r_rfd_memmap.h"

#define  R_RFD_START_SECTION_RFD_DATA
#include "r_rfd_memmap.h"
    /* CPU Frequency configuration for FSET */
    uint8_t g_u08_fset_cpu_frequency           = R_RFD_VALUE_U08_INIT_VARIABLE;
#define  R_RFD_END_SECTION_RFD_DATA
#include "r_rfd_memmap.h"

/**********************************************************************************************************************
 * Function name : R_RFD_Init
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Initialize the RFD.
 *  
 *  @param[in]      i_u08_cpu_frequency : 
 *                    CPU operating frequency
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :        Successful completion
 *                  - R_RFD_ENUM_RET_ERR_PARAMETER : Out of parameter range
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_Init(uint8_t i_u08_cpu_frequency)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    
    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
    if ((R_RFD_VALUE_U08_FREQUENCY_LOWER_LIMIT <= i_u08_cpu_frequency) 
       && (R_RFD_VALUE_U08_FREQUENCY_UPPER_LIMIT >= i_u08_cpu_frequency))
    {
        /* Adjust the CPU frequency variable for r_rfd_wait_count */
        g_u08_cpu_frequency = i_u08_cpu_frequency - R_RFD_VALUE_U08_FREQUENCY_ADJUST;
        
        if (R_RFD_VALUE_U08_FREQUENCY_CALC_THRESHOLD >= i_u08_cpu_frequency)
        {
            /* Adjust the sequencer frequency variable */
            g_u08_fset_cpu_frequency = g_u08_cpu_frequency;
        }
        else /* (R_RFD_VALUE_U08_FREQUENCY_CALC_THRESHOLD < i_u08_cpu_frequency) */
        {
            /* Adjust the sequencer frequency variable */
            g_u08_fset_cpu_frequency = ((i_u08_cpu_frequency + R_RFD_VALUE_U08_FREQUENCY_CALC_THRESHOLD) 
                                       >> R_RFD_VALUE_U08_FREQUENCY_SHIFT_ADJUST);
        }
    }
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_ERR_PARAMETER;
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_Init
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_SetDataFlashAccessMode
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Enable or disable to access the data flash.
 *  
 *  @param[in]      i_e_df_access : 
 *                    Data flash access enable or disable
 *  @return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void R_RFD_SetDataFlashAccessMode(e_rfd_df_access_t i_e_df_access)
{
    /* Local variable definitions */
    
    /* Parameter is Data Flash Access Enable Request */
    if (R_RFD_ENUM_DF_ACCESS_ENABLE == i_e_df_access)
    {
        /* Set the value for DFLCTL register DFLEN bit */
        R_RFD_REG_U01_DFLCTL_DFLEN = R_RFD_VALUE_U01_DFLEN_DATA_FLASH_ACCESS_ENABLE;
        
        /* Wait for the setup time of DFLCTL register */
        r_rfd_wait_count(4u);
    }
    /* Parameter is Data Flash Access Disable Request */
    else
    {
        /* Set the value for DFLCTL register DFLEN bit */
        R_RFD_REG_U01_DFLCTL_DFLEN = R_RFD_VALUE_U01_DFLEN_DATA_FLASH_ACCESS_DISABLE;
    }
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_SetDataFlashAccessMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_SetFlashMemoryMode
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Set the flash memory mode to the specified mode and set the flash operating frequency.
 *  
 *  @param[in]      i_e_flash_mode : 
 *                    Flash memory mode
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Failed to change flash memory mode
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_SetFlashMemoryMode(e_rfd_flash_memory_mode_t i_e_flash_mode)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_fsset_value;
    uint8_t     l_u08_set_flpmc_value;
    uint8_t     l_u08_pfs_value;
    
    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
    R_RFD_HOOK_EnterCriticalSection();
    
    /* Set code flash programming mode */
    if (R_RFD_ENUM_FLASH_MODE_CODE_PROGRAMMING == i_e_flash_mode)
    {
        /* Code flash programming mode */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_CODE_FLASH_PROGRAMMING;
        
        /* Start specific sequence for writing */
        R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
        
        /* Prepare to transfer the flash memory control mode */
        R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_1ST_LAYER;
        R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_1ST_LAYER_INVERSION;
        R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_1ST_LAYER;
        
        /* Wait for setting */
        r_rfd_wait_count(3u);
        
        /* Read PFS register */
        l_u08_pfs_value = R_RFD_REG_U08_PFS;
        
        /* Check specific sequence writing error */
        if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
        {
            l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
        }
        else
        {
            /* Start specific sequence for writing */
            R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
            
            /* Prepare to transfer the flash memory control mode */
            R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_2ND_LAYER;
            R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_2ND_LAYER_INVERSION;
            R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_2ND_LAYER;
            
            /* Read PFS register */
            l_u08_pfs_value = R_RFD_REG_U08_PFS;
            
            /* Check specific sequence writing error */
            if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
            {
                l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
            }
            else
            {
                /* No operation */
            }
        }
    }
    /* Set data flash programming mode */
    else if (R_RFD_ENUM_FLASH_MODE_DATA_PROGRAMMING == i_e_flash_mode)
    {
        /* Data flash programming mode */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_DATA_FLASH_PROGRAMMING;
    }
    /* Set non-programing mode from code flash programming mode */
    else if (R_RFD_ENUM_FLASH_MODE_CODE_TO_NONPROGRAMMABLE == i_e_flash_mode)
    {
        /* Non-programmable mode */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE;
        
        /* Start specific sequence for writing */
        R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
        
        /* Prepare to transfer the flash memory control mode */
        R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_2ND_LAYER;
        R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_2ND_LAYER_INVERSION;
        R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_2ND_LAYER;
        
        /* Wait for setting */
        r_rfd_wait_count(3u);
        
        /* Read PFS register */
        l_u08_pfs_value = R_RFD_REG_U08_PFS;
        
        /* Check specific sequence writing error */
        if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
        {
            l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
        }
        else
        {
            /* Start specific sequence for writing */
            R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
            
            /* Prepare to transfer the flash memory control mode */
            R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_1ST_LAYER;
            R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_1ST_LAYER_INVERSION;
            R_RFD_REG_U08_FLPMC = R_RFD_VALUE_U08_FLPMC_TRANSFER_1ST_LAYER;
            
            /* Read PFS register */
            l_u08_pfs_value = R_RFD_REG_U08_PFS;
            
            /* Check specific sequence writing error */
            if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
            {
                l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
            }
            else
            {
                /* No operation */
            }
        }
    }
    /* Set non-programing mode from data flash programming mode */
    else /* (R_RFD_ENUM_FLASH_MODE_DATA_TO_NONPROGRAMMABLE == i_e_flash_mode) */
    {
        /* Non-programmable mode */
        l_u08_set_flpmc_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE;
    }
    
    if (R_RFD_ENUM_RET_STS_OK == l_e_ret_value)
    {
        /* Start specific sequence for writing */
        R_RFD_REG_U08_PFCMD = R_RFD_VALUE_U08_PFCMD_SPECIFIC_SEQUENCE_WRITE;
        
        /* Set the flash memory control mode */
        R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
        R_RFD_REG_U08_FLPMC = ~l_u08_set_flpmc_value;
        R_RFD_REG_U08_FLPMC = l_u08_set_flpmc_value;
        
        /* Wait for mode setup time */
        r_rfd_wait_count(10u);
        
        /* Read PFS register */
        l_u08_pfs_value = R_RFD_REG_U08_PFS;
        
        /* Check specific sequence writing error */
        if (0u != (l_u08_pfs_value & R_RFD_VALUE_U08_MASK1_PFS_FPRERR))
        {
            l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
        }
        else
        {
            /* Check mode */
            l_e_ret_value = R_RFD_CheckFlashMemoryMode(i_e_flash_mode);
            
            if (R_RFD_ENUM_RET_STS_OK == l_e_ret_value)
            {
                if ((R_RFD_ENUM_FLASH_MODE_CODE_PROGRAMMING == i_e_flash_mode) 
                   || (R_RFD_ENUM_FLASH_MODE_DATA_PROGRAMMING == i_e_flash_mode))
                {
                    /* Read FSSET register */
                    l_u08_fsset_value = R_RFD_REG_U08_FSSET;
                    
                    /* Set frequency */
                    R_RFD_REG_U08_FSSET = (l_u08_fsset_value & R_RFD_VALUE_U08_MASK1_FSSET_TMSPMD_AND_TMBTSEL) 
                                          | g_u08_fset_cpu_frequency;
                }
                else
                {
                    /* No operation */
                }
            }
            else
            {
                l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
            }
        }
    }
    else
    {
        /* No operation */
    }
    
    R_RFD_HOOK_ExitCriticalSection();
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_SetFlashMemoryMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : R_RFD_CheckFlashMemoryMode
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/*********************************************************************************************************************/
/**
 *  Check whether the current flash memory mode is same as specified mode.
 *  
 *  @param[in]      i_e_flash_mode : 
 *                    Flash memory mode
 *  @return         Execution result status
 *                  - R_RFD_ENUM_RET_STS_OK :              Successful completion
 *                  - R_RFD_ENUM_RET_ERR_MODE_MISMATCHED : Mode mismatch error (Not same)
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_rfd_ret_t R_RFD_CheckFlashMemoryMode(e_rfd_flash_memory_mode_t i_e_flash_mode)
{
    /* Local variable definitions */
    e_rfd_ret_t l_e_ret_value;
    uint8_t     l_u08_flpmc_value;
    uint8_t     l_u08_flpmc_expected_value;
    
    /* Local variables initialization */
    l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    
    /* Acquire the value of FLPMC register */
    l_u08_flpmc_value  = R_RFD_REG_U08_FLPMC;
    
    if (R_RFD_ENUM_FLASH_MODE_DATA_PROGRAMMING == i_e_flash_mode)
    {
        l_u08_flpmc_expected_value = R_RFD_VALUE_U08_FLPMC_MODE_DATA_FLASH_PROGRAMMING;
    }
    else if (R_RFD_ENUM_FLASH_MODE_CODE_PROGRAMMING == i_e_flash_mode)
    {
        l_u08_flpmc_expected_value = R_RFD_VALUE_U08_FLPMC_MODE_CODE_FLASH_PROGRAMMING;
    }
    else /* (R_RFD_ENUM_FLASH_MODE_*_TO_NONPROGRAMMABLE == i_e_flash_mode) */
    {
        l_u08_flpmc_expected_value = R_RFD_VALUE_U08_FLPMC_MODE_NONPROGRAMMABLE;
    }
    
    if (l_u08_flpmc_expected_value == l_u08_flpmc_value)
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_STS_OK;
    }
    else
    {
        /* Set return value */
        l_e_ret_value = R_RFD_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    
    return (l_e_ret_value);
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function R_RFD_CheckFlashMemoryMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Internal functions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function name : r_rfd_wait_count
 *********************************************************************************************************************/
#define  R_RFD_START_SECTION_RFD_CMN
#include "r_rfd_memmap.h"

#if (COMPILER_CC == COMPILER)
    #pragma inline_asm r_rfd_wait_count
#endif
/*********************************************************************************************************************/
/**
 *  Wait until the target count value (microsecond) is reached.
 *  
 *  @param[in]      i_u08_count : 
 *                    Target count value (us)
 *  @return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void r_rfd_wait_count(uint8_t i_u08_count)
{
    #if (COMPILER_CC == COMPILER)
    /* CC-RL compiler uses the register A as this function argument */
    PUSH  AX
    
    /* Calculate the counter of the waiting loop */
    MOV   X, !_g_u08_cpu_frequency
    INC   X
    MULU  X
    SHRW  AX, 3
    INCW  AX
    
    /* Start the waiting loop that has 8 clocks (1+1+1+1+4) */
    .LOCAL _WAIT_LOOP
    _WAIT_LOOP:
    NOP
    NOP
    DECW  AX
    CMPW  AX, #0
    BNZ   $_WAIT_LOOP
    POP   AX
    
    #elif (COMPILER_IAR == COMPILER)
    /* IAR compiler uses the register A as this function argument */
    __asm("PUSH  AX");
    
    /* Calculate the counter of the waiting loop */
    __asm("MOV   X, N:_g_u08_cpu_frequency");
    __asm("INC   X");
    __asm("MULU  X");
    __asm("SHRW  AX, 3");
    __asm("INCW  AX");
    
    /* Start the waiting loop that has 8 clocks (1+1+1+1+4) */
    __asm("NOP");
    __asm("NOP");
    __asm("DECW  AX");
    __asm("CMPW  AX, #0");
    __asm("BNZ   $-0x06");
    __asm("POP   AX");
    
    #endif
}

#define  R_RFD_END_SECTION_RFD_CMN
#include "r_rfd_memmap.h"
/**********************************************************************************************************************
 End of function r_rfd_wait_count
 *********************************************************************************************************************/

/**********************************************************************************************************************
 End of internal functions
 *********************************************************************************************************************/
