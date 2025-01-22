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
* File Name    : mcu_clocks.c
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 28.02.2022 1.20     First Release
*         : 11.11.2022 1.40     Changed the frequency table of the high-speed on-chip oscillator.
*                               Changed comment about error in change_clock_setting function.
*                               Changed the error condition when HIOCLK is set to the argument of
*                               the change_clock_setting function.
*                               Changed the error condition when ADCLK is set to the argument of
*                               the change_clock_setting function.
*                               Added processing to set SELPLL
*                               when HIOCLK or SYSCLK is set as an argument of the set_fclk_clock_source function.
*         : 31.01.2023 1.50     Changed comment about error in change_clock_setting function.
*                               Removed IAWCTL from the error check
*                               when ADCLK is set as an argument of the change_clock_setting function.
*                               Removed OSMC and SELLOSC from the error check
*                               when LOCLK is set as an argument of the set_fclk_clock_source function.
*         : 28.02.2023 1.60     Changed the error condition when HIOCLK is set to the argument of
*                               the set_fclk_clock_source function.
*                               Changed the error condition when SYSCLK is set to the argument of
*                               the set_fclk_clock_source function.
*                               Removed the comment related to ADCLK in the change_clock_setting function.
*                               Removed processing on the occasion ADCLK is set as an argument of
*                               the change_clock_setting function.
*                               Removed processing to set ADCKS.
*                               Added processing to put the analog block of A/D converter on standby state.
*         : 31.08.2023 1.61     Changed comment about setting CMC register.
*                               Changed to set EXCLKS and OSCSELS even for 32-pin package.
*         : 30.11.2023 1.62     Added processing to check CLS after setting CSS bit.
*                               Added processing to check MCS after setting MCM0 bit.
*                               Added processing to check SELPLLS after setting SELPLL bit.
*                               Added parentheses to the #if condition to clarify the order of evaluation.
***********************************************************************************************************************/
/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include "platform.h"

/*************************************************
 * Macro definitions
 *************************************************/

/*************************************************
 * External function Prototypes
 *************************************************/

#if (BSP_CFG_WDT_REFRESH_ENABLE == 2) || (BSP_CFG_WDT_REFRESH_ENABLE == 3)
/* If user is requesting Watchdog Timer callback functions then these are the prototypes. */
void BSP_CFG_USER_WDT_REFRESH_SETTING_FUNCTION (void);
#endif

/*************************************************
 * Private global variables and functions
 *************************************************/
/* Frequency of the high-speed on-chip oscillator */
#if BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0
const uint32_t g_fih_hz[] = {
    32000000,
    16000000,
    8000000,
    4000000,
    2000000,
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    40000000,
    20000000,
    10000000,
    5000000,
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    64000000,
    32000000,
    16000000,
    8000000,
    4000000,
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    80000000,
    40000000,
    20000000,
    10000000,
    5000000,
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    0                   /* Setting prohibited */
};
#endif /* BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0 */

/*************************************************
 * Function definition
 *************************************************/
/*************************************************
 * Function name: start_clock
 * Description  : Start the specified clock
 * Arguments    : Clock to start
 * Return value : BSP_OK if the specified clock is started.
 *                BSP_ARG_ERROR if the specified clock is incorrect.
**************************************************/
#if BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t start_clock(e_clock_mode_t mode)
{
    e_bsp_err_t           status = BSP_OK;
#if BSP_CFG_HISYSCLK_SOURCE == 1
    uint8_t               tmp_stab_wait;
    uint8_t               tmp_stab_set;
#endif
    volatile uint32_t     w_count;

    switch (mode)
    {
        case SYSCLK:

            if (1U == MSTOP)
            {
                MSTOP = 0U;

#if BSP_CFG_HISYSCLK_SOURCE == 1
                tmp_stab_set = (uint8_t)~(0x7FU >> OSTS);

                /* WAIT_LOOP */
                do
                {
                    tmp_stab_wait  = OSTC;
                    tmp_stab_wait &= tmp_stab_set;
                }
                while (tmp_stab_wait != tmp_stab_set);
#endif
            }

            break;

        case SXCLK:

            if (1U == XTSTOP)
            {
                XTSTOP = 0U;

#if BSP_CFG_SUBCLK_SOURCE == 1
                /* WAIT_LOOP */
                for (w_count = 0U; w_count <= BSP_CFG_SUBWAITTIME; w_count++)
                {
#if BSP_CFG_WDT_REFRESH_ENABLE == 0
                    BSP_NOP();
#elif BSP_CFG_WDT_REFRESH_ENABLE == 1
                    WDTE = 0xACU;
#else
                    BSP_CFG_USER_WDT_REFRESH_SETTING_FUNCTION();
#endif
                }
#endif
            }

            break;

        case HIOCLK:

            if (1U == HIOSTOP)
            {
                HIOSTOP = 0U;

                /* WAIT_LOOP */
                for (w_count = 0U; w_count <= BSP_CFG_FIHWAITTIME; w_count++)
                {
                    BSP_NOP();
                }
            }

            break;

        case LOCLK:

            if (0U == (OSMC & 0x10U))
            {
                OSMC |= 0x10U;
            }

            break;

        case PLLCLK:

            if (0U == PLLON)
            {
                PLLON = 1U;

                /* WAIT_LOOP */
                /* Confirm that the PLL circuit is locked. */
                while (0U == LOCK)
                {
                    ;
                }
            }

            break;

        default:

            status = BSP_ARG_ERROR;

            break;

    }

    return status;
} /* End of function start_clock() */
#endif /* BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0 */

/*************************************************
 * Function name: stop_clock
 * Description  : Stop the specified clock
 * Arguments    : Clock to stop
 * Return value : BSP_OK if the specified clock is stopped.
 *                BSP_ARG_ERROR if the specified clock is incorrect.
**************************************************/
#if BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t stop_clock(e_clock_mode_t mode)
{
    e_bsp_err_t    status = BSP_OK;

    switch (mode)
    {
        case SYSCLK:

            MSTOP = 1U;

            break;

        case SXCLK:

            XTSTOP = 1U;

            break;

        case HIOCLK:

            HIOSTOP = 1U;

            break;

        case LOCLK:

            OSMC &= 0xEFU;

            break;

        case PLLCLK:

            PLLON = 0U;

            break;

        default:

            status = BSP_ARG_ERROR;

            break;

    }

    return status;
} /* End of function stop_clock() */
#endif /* BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE == 0 */

/**************************************************
 * Function name: set_fclk_clock_source
 * Description  : Switch CPU/peripheral hardware clock(fCLK) clock source.
 * Arguments    : Clock to switch.
 * Return value : BSP_OK when switching to the specified clock.
 *                BSP_ERROR1 The specified clock is not oscillating.
 *                BSP_ERROR2 When switching between clock resource, a clock resource that is not
 *                           oscillating may have been switched to.
 *                BSP_ERROR3 An unsupported state transition was specified. Refer to the user's manual.
 *                BSP_ARG_ERROR An invalid argument was input.
 * Attention    : Start the clock to switch to before calling this function.
**************************************************/
#if BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t set_fclk_clock_source(e_clock_mode_t mode)
{
    e_bsp_err_t          status = BSP_OK;
    e_clock_mode_t       old_mode;
    volatile uint32_t    w_count;

    /* Get current clock source */
    if (1U == CLS)
    {
        if (1U == SELLOSC)
        {
            old_mode = LOCLK;
        }
        else
        {
            old_mode = SXCLK;
        }
    }
    else
    {
        if ((1U == PLLON) && (1U == SELPLL) && (1U == LOCK) && (1U == SELPLLS))
        {
            old_mode = PLLCLK;
        }
        else
        {
            if (1U == MCS)
            {
                old_mode = SYSCLK;
            }
            else
            {
                old_mode = HIOCLK;
            }
        }
    }

    /* Only switch if the current clock source and the
     * specified clock source are different.
     */
    if (mode != old_mode)
    {
        switch (mode)
        {
            case HIOCLK:

                if (1U == HIOSTOP)
                {
                    /* Error if the high-speed on-chip oscillator is stopped. */
                    status = BSP_ERROR1;
                }
                else if (PLLCLK == old_mode)
                {
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                    if (1U == MCS)
                    {
                        /* Error if PLL input is SYSCLK. */
                        status = BSP_ERROR3;
                    }
                    else
                    {
#endif
                        SELPLL = 0U;

                        /* WAIT_LOOP */
                        /* Confirm that the Clock through mode is selected. */
                        while (1U == SELPLLS)
                        {
                            ;
                        }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                    }
#endif
                }
                else
                {
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                    if ((1U == CLS) && (0U != MCS))
                    {
                        /* Error if the high-speed on-chip oscillator is not selected. */
                        status = BSP_ERROR2;
                    }
                    else if ((SYSCLK == old_mode) && (1U == PLLON))
                    {
                        /* Error if PLL is running. */
                        status = BSP_ERROR3;
                    }
                    else
                    {
#endif
                        SELPLL = 0U;

                        /* WAIT_LOOP */
                        /* Confirm that the Clock through mode is selected. */
                        while (1U == SELPLLS)
                        {
                            ;
                        }

                        CSS  = 0U;

                        /* WAIT_LOOP */
                        /* Confirm that Main system/PLL select clock(fMP) is selected. */
                        while (1U == CLS)
                        {
                            ;
                        }

                        MCM0 = 0U;

                        /* WAIT_LOOP */
                        /* Confirm that high-speed on-chip oscillator clock(fIH) is selected. */
                        while (1U == MCS)
                        {
                            ;
                        }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                    }
#endif
                }

                break;

            case SYSCLK:

                if (1U == MSTOP)
                {
                    /* Error if the high-speed system clock is stopped. */
                    status = BSP_ERROR1;
                }
                else if (PLLCLK == old_mode)
                {
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                    if (0U == MCS)
                    {
                        /* Error if PLL input is HIOCLK. */
                        status = BSP_ERROR3;
                    }
                    else
                    {
#endif
                        SELPLL = 0U;

                        /* WAIT_LOOP */
                        /* Confirm that the Clock through mode is selected. */
                        while (1U == SELPLLS)
                        {
                            ;
                        }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                    }
#endif
                }
                else
                {
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                    if ((CMC & 0x40U) != 0x40U)
                    {
                        /* Error if the high-speed system clock is invalid. */
                        status = BSP_ERROR1;
                    }
                    else if ((1U == CLS) && (1U != MCS))
                    {
                        /* Error if the high-speed system clock in not selected. */
                        status = BSP_ERROR2;
                    }
                    else if ((HIOCLK == old_mode) && (1U == PLLON))
                    {
                        /* Error if PLL is running. */
                        status = BSP_ERROR3;
                    }
                    else
                    {
#endif
                        SELPLL = 0U;

                        /* WAIT_LOOP */
                        /* Confirm that the Clock through mode is selected. */
                        while (1U == SELPLLS)
                        {
                            ;
                        }

                        CSS  = 0U;

                        /* WAIT_LOOP */
                        /* Confirm that Main system/PLL select clock(fMP) is selected. */
                        while (1U == CLS)
                        {
                            ;
                        }

                        MCM0 = 1U;

                        /* WAIT_LOOP */
                        /* Confirm that high-speed system clock(fMX) is selected. */
                        while (0U == MCS)
                        {
                            ;
                        }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                    }
#endif
                }

                break;

            case SXCLK:

#if (BSP_CFG_PARAM_CHECKING_ENABLE == 1) && (BSP_CFG_MCU_PART_PIN_NUM == 0)
                /* Error 32-pin product do not have a subsystem clock. */
                status = BSP_ERROR3;

                break;
#else /* (BSP_CFG_PARAM_CHECKING_ENABLE == 1) && (BSP_CFG_MCU_PART_PIN_NUM == 0) */
                if (1U == XTSTOP)
                {
                    /* Error if the subsystem clock is stopped. */
                    status = BSP_ERROR1;
                }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                else if ((CMC & 0x10U) != 0x10U)
                {
                    /* Error if the subsystem clock is invalid. */
                    status = BSP_ERROR1;
                }
                else if (LOCLK == old_mode)
                {
                    status = BSP_ERROR3;
                }
                else if (PLLCLK == old_mode)
                {
                    status = BSP_ERROR3;
                }
#endif
                else
                {
                    SELLOSC = 0U;
                    CSS     = 1U;

                    /* WAIT_LOOP */
                    /* Confirm that Subsystem/low-speed on-chip oscillator select clock(fSL) is selected. */
                    while (0U == CLS)
                    {
                        ;
                    }
                }

                break;
#endif /* (BSP_CFG_PARAM_CHECKING_ENABLE == 1) && (BSP_CFG_MCU_PART_PIN_NUM == 0) */

            case LOCLK:

                if (0x10U != (CMC & 0x10U))
                {
                    /* Error if the low-speed on-chip oscillator clock is stopped. */
                    status = BSP_ERROR1;
                }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                else if (SXCLK == old_mode)
                {
                    status = BSP_ERROR3;
                }
                else if (PLLCLK == old_mode)
                {
                    status = BSP_ERROR3;
                }
                else
                {
#endif
                    SELLOSC = 1U;

                    CSS = 1U;

                    /* WAIT_LOOP */
                    /* Confirm that Subsystem/low-speed on-chip oscillator select clock(fSL) is selected. */
                    while (0U == CLS)
                    {
                        ;
                    }

#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                }
#endif

                break;

            case PLLCLK:

                if ((0U == PLLON) || (0U == LOCK))
                {
                    /* Error if the PLL operation is stopped. */
                    status = BSP_ERROR1;
                }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
                else if (1U == CLS)
                {
                    status = BSP_ERROR3;
                }
#endif
                else
                {
                    SELPLL = 1U;

                    /* WAIT_LOOP */
                    /* Confirm that the PLL-clock-selected mode is selected. */
                    while (0U == SELPLLS)
                    {
                        ;
                    }
                }

                break;

            default:

                status = BSP_ARG_ERROR;

                break;

        }
    }

    return status;
} /* End of function set_fclk_clock_source() */
#endif /* BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE == 0 */

/*************************************************
 * Function name: get_fclk_freq_hz
 * Description  : Returns CPU/peripheral hardware clock(fCLK) frequency.
 * Arguments    : none
 * Return value : CPU/peripheral hardware clock(fCLK) frequency specified by the r_bsp.
 * Attention    : Error if 0Hz is returned.
 *                When fCLK is a high-speed on-chip oscillator, 0Hz is returned
 *                when the value of the register to which it refers is out of the allowable range.
**************************************************/
#if BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0
uint32_t get_fclk_freq_hz(void)
{
    uint32_t    sys_clock_src_freq;

    /* fCLK clock source is fSL */
    /* fCLK : CPU/peripheral hardware clock */
    /* fSL  : Subsystem/low-speed on-chip oscillator select clock */
    if (1U == CLS)
    {
        /* fSL clock source is fIL */
        /* fSL : Subsystem/low-speed on-chip oscillator select clock */
        /* fIL  : Low-speed on-chip oscillator clock */
        if (1U == SELLOSC)
        {
            sys_clock_src_freq = BSP_LOCO_HZ;
        }
        /* fSL clock source is fSUB */
        /* fSL  : Subsystem/low-speed on-chip oscillator clock */
        /* fSUB : Subsystem clock */
        else
        {
            sys_clock_src_freq = BSP_SUB_CLOCK_HZ;
        }
    }
    /* fCLK clock source is fMP */
    /* fCLK : CPU/peripheral hardware clock */
    /* fMP  : Main system/PLL select clock */
    else
    {
        /* fMAIN clock source is fMX */
        /* fMAIN : Main system clock */
        /* fMX   : High-speed system clock */
        if (1U == MCS)
        {
            sys_clock_src_freq = BSP_CFG_FMX_HZ;
        }
        /* fMAIN clock source is fIH */
        /* fMAIN : Main system clock */
        /* fIH   : High-speed on-chip oscillator clock */
        else
        {
            uint8_t temp1;
            uint8_t temp2;
            temp1              = OPTBYTE_C2;
            temp2              = HOCODIV;
            sys_clock_src_freq = g_fih_hz[(temp1 & 0x18U) | (temp2 & 0x07U)];
        }

        /* fMP clock source is fPLL */
        /* fMP  : Main system/PLL select clock */
        /* fPLL : PLL clock */
        if (1U == SELPLLS)
        {
            uint8_t temp1;

            /* PLL input clock division selection */
            temp1  = CKSEL;
            temp1 &= 0x60U;

            if (0x40U == temp1)
            {
                /* Divided by 2(fMAIN = 16 MHz input only) */
                sys_clock_src_freq /= 2;
            }
            else if (0x60U == temp1)
            {
                /* Divided by 4(fMAIN = 20 MHz input only) */
                sys_clock_src_freq /= 4;
            }
            else
            {
                /* No division or Setting prohibited */
                ;
            }

            /* PLL multiplication selection */
            temp1  = PLLCTL;
            temp1 &= 0x0A;

            if (0x00U == temp1)
            {
                /* Multiples the clock frequency by 12 */
                sys_clock_src_freq *= 12;
            }
            else if (0x02U == temp1)
            {
                /* Multiples the clock frequency by 16 */
                sys_clock_src_freq *= 16;
            }
            else if (0x08U == temp1)
            {
                /* Multiples the clock frequency by 10 */
                sys_clock_src_freq *= 10;
            }
            else
            {
                /* Multiples the clock frequency by 20 */
                sys_clock_src_freq *= 20;
            }

            /* PLL frequency division selection */
            if (0U == FPLLDIV)
            {
                if (0U == PLLDIV0)
                {
                    /* Divides the clock frequency by 2 */
                    sys_clock_src_freq /= 2;
                }
                else
                {
                    /* Divides the clock frequency by 4 */
                    sys_clock_src_freq /= 4;
                }
            }
            else
            {
                /* No division */
                ;
            }
        }
        /* fMP clock source is fMAIN */
        /* fMP   : Main system/PLL select clock */
        /* fMAIN : Main system clock */
        else
        {
            /* Clock through mode (fMAIN) */
            ;
        }

        switch (MDIV)
        {
            case 0U : 

                /* Selects fMP */

                break;

            case 1U :

                /* Selects fMP/2 */
                sys_clock_src_freq /= 2U;

                break;

            case 2U :

                /* Selects fMP/4 */
                sys_clock_src_freq /= 4U;

                break;

            case 3U :

                /* Selects fMP/8 */
                sys_clock_src_freq /= 8U;

                break;

            case 4U :

                /* Selects fMP/16 */
                sys_clock_src_freq /= 16U;

                break;

            case 5U :

                /* Selects fMP/32 */
                sys_clock_src_freq /= 32U;

                break;

            case 6U :

                /* Selects fMP/64 */
                sys_clock_src_freq /= 64U;

                break;

            default :

                /* Setting prohibited */
                sys_clock_src_freq = 0U;

                break;

        }
    }

    return sys_clock_src_freq;
} /* End of function get_fclk_freq_hz() */
#endif /* BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE == 0 */

/**************************************************
 * Function name: change_clock_setting
 * Description  : Change the specified clock setting.
 * Arguments    : Clock to change setting.
 *              : Value to set for the specified clock.
 * Return value : BSP_OK if the specified clock setting is changed.
 *                BSP_ERROR1 (When HIOCLK is specified)
 *                           When the high-speed on-chip oscillator is stopped
 *                           while the high-speed on-chip oscillator is being supplied to fCLK.
 *                           When the high-speed on-chip oscillator is oscillating
 *                           while the high-speed on-chip oscillator is not supplied to fCLK.
 *                           When a PLL with a high-speed on-chip oscillator as input is supplied to fCLK.
 *                           (When SYSCLK or PLLCLK is specified)
 *                           When the specified clock is oscillating.
 *                BSP_ARG_ERROR An invalid argument was input.
 * Attention    : 
**************************************************/
#if BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE == 0
e_bsp_err_t change_clock_setting(e_clock_mode_t mode, uint8_t * set_values)
{
    e_bsp_err_t    status = BSP_OK;
    uint8_t        w_count;

    switch (mode)
    {
        case HIOCLK:

            if ((1U == HIOSTOP) && (0U == CLS) && (0U == MCS))
            {
                status = BSP_ERROR1;
            }
            else if ((0U == HIOSTOP) && ((1U == CLS) || (1U == MCS)))
            {
                status = BSP_ERROR1;
            }
            else if (((1U == SELPLLS) || (1U == SELPLL)) && (0U == CLS) && (0U == MCS))
            {
                status = BSP_ERROR1;
            }
            else
            {
                HOCODIV = set_values[0];
                MDIV    = set_values[1];
            }

            break;

        case SYSCLK:

            if (0U == MSTOP)
            {
                status = BSP_ERROR1;
            }
            else
            {
                MDIV = set_values[0];
            }

            break;

        case PLLCLK:

            if ((1U == PLLON) || (1U == SELPLL) || (1U == LOCK) || (1U == SELPLLS))
            {
                status = BSP_ERROR1;
            }
            else
            {
                /* Control of PLL output clock selection */
                PLLDIV1 = set_values[0];

                /* Control of setting lock-up wait counter */
                if (0U == set_values[1])
                {
                    LCKSEL1 = 0U;
                    LCKSEL0 = 0U;
                }
                else if (1U == set_values[1])
                {
                    LCKSEL1 = 0U;
                    LCKSEL0 = 1U;
                }
                else if (2U == set_values[1])
                {
                    LCKSEL1 = 1U;
                    LCKSEL0 = 0U;
                }
                else
                {
                    LCKSEL1 = 1U;
                    LCKSEL0 = 1U;
                }

                /* Control of PLL input clock (fPLLI) division selection */
                if (0U == set_values[2])
                {
                    FMAINDIV1 = 0U;
                    FMAINDIV0 = 0U;
                }
                else if (1U == set_values[2])
                {
                    FMAINDIV1 = 1U;
                    FMAINDIV0 = 0U;
                }
                else
                {
                    FMAINDIV1 = 1U;
                    FMAINDIV0 = 1U;
                }

                /* Control of PLL division selection */
                if (0U == set_values[3])
                {
                    FPLLDIV = 1U;
                }
                else if (1U == set_values[3])
                {
                    FPLLDIV = 0U;
                    PLLDIV0 = 0U;
                }
                else
                {
                    FPLLDIV = 0U;
                    PLLDIV0 = 1U;
                }

                /* Control of PLL multiplication selection */
                if (0U == set_values[4])
                {
                    PLLMULA = 0U;
                    PLLMUL  = 0U;
                }
                else if (1U == set_values[4])
                {
                    PLLMULA = 0U;
                    PLLMUL  = 1U;
                }
                else if (2U == set_values[4])
                {
                    PLLMULA = 1U;
                    PLLMUL  = 0U;
                }
                else
                {
                    PLLMULA = 1U;
                    PLLMUL  = 1U;
                }

                /* WAIT_LOOP */
                for (w_count = 0U; w_count <= set_values[5]; w_count++)
                {
                    BSP_NOP();
                }

                /* fMP clock division control */
                MDIV = set_values[6];
            }

            break;

        default :

            /* Setting prohibited */
            status = BSP_ARG_ERROR;

            break;

    }

    return status;
} /* End of function change_clock_setting() */
#endif /* BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE == 0 */

/*************************************************
 * Function name: mcu_clock_setup
 * Description  : Clock initialization.
 * Arguments    : none
 * Return value : none
**************************************************/
#if BSP_CFG_STARTUP_DISABLE == 0
void mcu_clock_setup(void)
{
    uint8_t    cmc_tmp;

#if ((BSP_CFG_SUBCLK_OPERATION == 0) && (BSP_CFG_SUBCLK_SOURCE == 1)) || \
    (BSP_CFG_PLL_OPERATION == 1)
    volatile uint32_t    w_count;
#endif

#if (BSP_CFG_HISYSCLK_OPERATION == 0) && (BSP_CFG_HISYSCLK_SOURCE == 1)
    uint8_t    tmp_stab_wait;
    uint8_t    tmp_stab_set;
#endif

    cmc_tmp = 0x00U;

    /* High-speed on-chip oscillator(fIH) setting */
    /* High-Speed On-Chip Oscillator Frequency Select Register(HOCODIV) setting */
    HOCODIV = BSP_CFG_HOCO_DIVIDE;

    /* High-speed system clock(fMX) setting */
#if BSP_CFG_HISYSCLK_SOURCE == 0
    /* Input port mode */
    /* Not used.
     * When using high-speed on-chip oscillator,
     * when not using main system clock
     */
#elif BSP_CFG_HISYSCLK_SOURCE == 1
    /* X1 oscillation mode */
    /* High-speed system clock pin operation mode(EXCLK/OSCSEL) setting */
    /* Control of X1 clock oscillation frequency(AMPH) setting */
#if (BSP_CFG_FMX_HZ >= 2000000) && (BSP_CFG_FMX_HZ <= 10000000)
    /* 2 MHz <= fX <= 10 MHz */
    cmc_tmp |= 0x40U;
#else
    /* 2 MHz <= fX <= 20 MHz */
    cmc_tmp |= 0x41U;
#endif
#else
    /* External clock input mode */
    /* High-speed system clock pin operation mode(EXCLK/OSCSEL) setting */
    cmc_tmp |= 0xC0U;
#endif

    /* Subsystem clock oscillator clock(fSX) setting */
#if BSP_CFG_SUBCLK_SOURCE == 0
    /* Not used.
     * When using the low-speed on-chip oscillator or
     * when not using subsystem clock(fSUB)
     */
#elif BSP_CFG_SUBCLK_SOURCE == 1
#if BSP_CFG_MCU_PART_PIN_NUM < 1
    /* 32-pin device */
    /* Input port mode(low-speed on-chip oscillator operation mode) */
    /* EXCLKS/OSCSELS setting */
    cmc_tmp |= 0x10U;
#else
    /* XT1 oscillation mode */
#if BSP_CFG_XT1_OSCMODE == 0
    /* Low power consumption oscillation (default) Oscillation margin : Medium */
    /* EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
    cmc_tmp |= 0x10U;
#elif BSP_CFG_XT1_OSCMODE == 1
    /* Normal oscillation Oscillation margin : High */
    /* EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
    cmc_tmp |= 0x12U;
#else
    /* Ultra-low power consumption oscillation Oscillation margin : Low */
    /* EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
    cmc_tmp |= 0x14U;
#endif
#endif
#else
#if BSP_CFG_MCU_PART_PIN_NUM < 1
    /* 32-pin device */
    /* Input port mode(low-speed on-chip oscillator operation mode) */
    /* EXCLKS/OSCSELS setting */
    cmc_tmp |= 0x30U;
#else
    /* External clock input mode */
    /* EXCLKS/OSCSELS setting */
    cmc_tmp |= 0x30U;
#endif
#endif /* BSP_CFG_SUBCLK_SOURCE == 0 */

    /* Clock Operation Mode Control Register(CMC) setting */
    CMC = cmc_tmp;

    /* When to use X1 clock oscillator(fX) */
#if BSP_CFG_HISYSCLK_SOURCE == 1
    /* Oscillation Stabilization Time Select Register(OSTS) setting */
    OSTS = BSP_CFG_X1_WAIT_TIME_SEL;
#endif

    /* High-speed system clock oscillation */
#if BSP_CFG_HISYSCLK_OPERATION == 0
    /* Start oscillation */
    MSTOP = 0U;

#if BSP_CFG_HISYSCLK_SOURCE == 1
    /* Wait for oscillation stabilization unless external clock input */
    tmp_stab_set = (uint8_t)~(0x7FU >> OSTS);

    /* WAIT_LOOP */
    do
    {
        tmp_stab_wait  = OSTC;
        tmp_stab_wait &= tmp_stab_set;
    }
    while (tmp_stab_wait != tmp_stab_set);
#endif
#else
    /* X1 oscillation stopped if high-speed system clock is not used */
    MSTOP = 1U;
#endif

    /* Main system clock(fMAIN) setting */
#if BSP_CFG_MAINCLK_SOURCE == 0
    /* High-speed on-chip oscillator clock(fIH) */
    MCM0 = 0U;

    /* WAIT_LOOP */
    /* Confirm that high-speed on-chip oscillator clock(fIH) is selected. */
    while (1U == MCS)
    {
        ;
    }
#else
    /* High-speed system clock(fMX) */
    MCM0 = 1U;

#if (BSP_CFG_HISYSCLK_OPERATION == 0) && (BSP_CFG_HISYSCLK_SOURCE != 0)
    /* WAIT_LOOP */
    /* Confirm that high-speed system clock(fMX) is selected. */
    while (0U == MCS)
    {
        ;
    }
#endif
#endif

    /* Subsystem clock oscillation */

    /* Operation Speed Mode Control Register(OSMC) setting */
#if (BSP_CFG_ALLOW_FSL_IN_STOPHALT == 0) && (BSP_CFG_FIL_OPERATION == 0)
    OSMC |= 0x00U;
#elif (BSP_CFG_ALLOW_FSL_IN_STOPHALT == 1) && (BSP_CFG_FIL_OPERATION == 0)
    OSMC |= 0x80U;
#elif (BSP_CFG_ALLOW_FSL_IN_STOPHALT == 0) && (BSP_CFG_FIL_OPERATION == 1)
    OSMC |= 0x10U;
#else
    OSMC |= 0x90U;
#endif

    /* When to use subsystem clock oscillator clock(fSX) */
    /* Subsystem clock oscillator clock oscillation */
#if BSP_CFG_SUBCLK_OPERATION == 0
    /* Start oscillation */
    XTSTOP = 0U;

#if BSP_CFG_SUBCLK_SOURCE == 1
    /* Wait for oscillation stabilization unless external clock input */
    /* WAIT_LOOP */
    for (w_count = 0U; w_count <= BSP_CFG_SUBWAITTIME; w_count++)
    {
#if BSP_CFG_WDT_REFRESH_ENABLE == 0
        BSP_NOP();
#elif BSP_CFG_WDT_REFRESH_ENABLE == 1
        WDTE = 0xACU;
#else
        BSP_CFG_USER_WDT_REFRESH_SETTING_FUNCTION();
#endif
    }
#endif

#else
    /* XT1 oscillator stopped if subsystem clock oscillator clock is not used */
    XTSTOP = 1U;
#endif

#if BSP_CFG_SUBSYSCLK_SOURCE == 1
    SELLOSC = 1U;
#endif

    /* fCLK selection */
#if BSP_CFG_FCLK_SOURCE == 0
    /* When using a high-speed system clock */
    CSS = 0U;

    /* WAIT_LOOP */
    /* Confirm that Main system/PLL select clock(fMP) is selected. */
    while (1U == CLS)
    {
        ;
    }
#else
    /* When using subsystem clock of low-speed on-chip oscillator */
    CSS = 1U;

#if ((BSP_CFG_SUBCLK_SOURCE != 0) && (BSP_CFG_SUBSYSCLK_SOURCE == 0) && (BSP_CFG_SUBCLK_OPERATION == 0)) || ((BSP_CFG_SUBCLK_SOURCE != 0) && (BSP_CFG_SUBSYSCLK_SOURCE == 1))
    /* WAIT_LOOP */
    /* Confirm that Subsystem/low-speed on-chip oscillator select clock(fSL) is selected. */
    while (0U == CLS)
    {
        ;
    }
#endif
#endif

    /* Control of PLL operation. */
#if BSP_CFG_PLL_OPERATION == 1
    /* Control of PLL output clock selection */
#if BSP_CFG_FPLL_HZ <= 40000000
    PLLDIV1 = 0U;
#else
    PLLDIV1 = 1U;
#endif

    /* Control of setting lock-up wait counter */
#if BSP_CFG_LOCKUP_WAIT_COUNT_SEL == 0
    LCKSEL1 = 0U;
    LCKSEL0 = 0U;
#elif BSP_CFG_LOCKUP_WAIT_COUNT_SEL == 1
    LCKSEL1 = 0U;
    LCKSEL0 = 1U;
#elif BSP_CFG_LOCKUP_WAIT_COUNT_SEL == 2
    LCKSEL1 = 1U;
    LCKSEL0 = 0U;
#else
    LCKSEL1 = 1U;
    LCKSEL0 = 1U;
#endif

    /* Control of PLL input clock (fPLLI) division selection */
#if BSP_CFG_FMAIN_DIVIDE == 0
    FMAINDIV1 = 0U;
    FMAINDIV0 = 0U;
#elif BSP_CFG_FMAIN_DIVIDE == 1
    FMAINDIV1 = 1U;
    FMAINDIV0 = 0U;
#else
    FMAINDIV1 = 1U;
    FMAINDIV0 = 1U;
#endif

    /* Control of PLL division selection */
#if BSP_CFG_PLL_DIVIDE == 0
    FPLLDIV = 1U;
#elif BSP_CFG_PLL_DIVIDE == 1
    FPLLDIV = 0U;
    PLLDIV0 = 0U;
#else
    FPLLDIV = 0U;
    PLLDIV0 = 1U;
#endif

    /* Control of PLL multiplication selection */
#if BSP_CFG_PLL_MULTI == 0
    PLLMULA = 0U;
    PLLMUL  = 0U;
#elif BSP_CFG_PLL_MULTI == 1
    PLLMULA = 0U;
    PLLMUL  = 1U;
#elif BSP_CFG_PLL_MULTI == 2
    PLLMULA = 1U;
    PLLMUL  = 0U;
#else
    PLLMULA = 1U;
    PLLMUL  = 1U;
#endif

    /* WAIT_LOOP */
    for (w_count = 0U; w_count <= BSP_CFG_PLLWAITTIME; w_count++)
    {
        BSP_NOP();
    }

    PLLON = 1U;

    /* WAIT_LOOP */
    /* Confirm that the PLL circuit is locked. */
    while (0U == LOCK)
    {
        ;
    }
#else /* BSP_CFG_PLL_OPERATION == 1 */
    PLLON = 0U;
#endif /* BSP_CFG_PLL_OPERATION == 1 */

    /* fMP clock division control */
    MDIV = BSP_CFG_FMP_DIVIDE;

    /* Control of clock mode selection */
#if BSP_CFG_PLL_MODE == 0
    SELPLL = 0U;

    /* WAIT_LOOP */
    /* Confirm that the Clock through mode is selected. */
    while (1U == SELPLLS)
    {
        ;
    }
#else
    SELPLL = 1U;

#if BSP_CFG_PLL_OPERATION == 1
    /* WAIT_LOOP */
    /* Confirm that the PLL-clock-selected mode is selected. */
    while (0U == SELPLLS)
    {
        ;
    }
#endif
#endif

    /* Starts high-speed on-chip oscillator */
    /* Only the high-speed on-chip oscillator is activated after reset,
     * so stop this clock last.
     */
#if BSP_CFG_FIH_START_ON_STARTUP == 1
    HIOSTOP = 0U;

    /* If main system/PLL select clock is stopped
     * when subsystem/low-speed on-chip oscillator select clock is supplied to fCLK,
     * put the analog block of A/D converter on standby state.
     */
#else
#if BSP_CFG_HISYSCLK_OPERATION == 1
    ADCEN = 1U;
    ADCSR &= 0x7FFFU;
    ADHVREFCNT |= 0x80U;
#endif
    HIOSTOP = 1U;
#endif

    /* Control of timer RDe clock selection */
    TRD_CKSEL = BSP_CFG_TRD_CLOCK_SOURCE;

    /* Control of supplying or stopping CAN X1 clock (fX) */
    CAN0MCKE = BSP_CFG_CAN_CLOCK_OPERATION;

    /* Control of selecting LIN1 communication clock source */
    LIN1MCK = BSP_CFG_LIN1_CLOCK_SOURCE;

    /* Control of supplying or stopping LIN1 communication clock source */
    LIN1MCKE = BSP_CFG_LIN1_CLOCK_OPERATION;

    /* Control of selecting LIN0 communication clock source */
    LIN0MCK = BSP_CFG_LIN0_CLOCK_SOURCE;

    /* Control of supplying or stopping LIN0 communication clock source */
    LIN0MCKE = BSP_CFG_LIN0_CLOCK_OPERATION;
} /* End of function mcu_clock_setup() */
#endif /* BSP_CFG_STARTUP_DISABLE == 0 */
