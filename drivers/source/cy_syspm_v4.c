/***************************************************************************//**
* \file cy_syspm_v4.c
* \version 5.92
*
* This driver provides the source code for API power management.
*
********************************************************************************
* \copyright
* Copyright (c) (2016-2022), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cy_device.h"
#include "cy_sysclk.h"

#if defined (CY_IP_MXS22SRSS)

#include "cy_syspm.h"

#include "cy_syspm_ppu.h"



/*******************************************************************************
*       Internal Functions
*******************************************************************************/


/*******************************************************************************
*       Internal Defines
*******************************************************************************/

/* The define for number of callback roots */
#define CALLBACK_ROOT_NR                (8U)

/* The mask to unlock the Hibernate power mode */
#define HIBERNATE_UNLOCK_VAL                 ((uint32_t) 0x3Au << SRSS_PWR_HIBERNATE_UNLOCK_Pos)

/* The mask to set the Hibernate power mode */
#define SET_HIBERNATE_MODE                   ((HIBERNATE_UNLOCK_VAL |\
                                               SRSS_PWR_HIBERNATE_FREEZE_Msk |\
                                               SRSS_PWR_HIBERNATE_HIBERNATE_Msk))

/* The mask to retain the Hibernate power mode status */
#define HIBERNATE_RETAIN_STATUS_MASK         ((SRSS_PWR_HIBERNATE_TOKEN_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBALARM_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBWDT_Msk |\
                                               SRSS_PWR_HIBERNATE_POLARITY_HIBPIN_Msk |\
                                               SRSS_PWR_HIBERNATE_MASK_HIBPIN_Msk))

/** The mask for the Hibernate wakeup sources */
#define HIBERNATE_WAKEUP_MASK               ((SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_SRC_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_CSV_BAK_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_RTC_Msk |\
                                              SRSS_PWR_HIB_WAKE_CTL_HIB_WAKE_WDT_Msk))

/** The define to update the token to indicate the transition into Hibernate */
#define HIBERNATE_TOKEN                    ((uint32_t) 0x1BU << SRSS_PWR_HIBERNATE_TOKEN_Pos)

/* The wait time for transition into the minimum regulator current mode
*/
#define SET_MIN_CURRENT_MODE_DELAY_US        (1U)

/* The wait delay time that occurs before the active reference is settled.
*  Intermediate delay is used in transition into the normal regulator current
*  mode, it should be two IHO cycles, which is (2 x 1/50000000)
*  = 1 micro second(Approximated)
*/
#define ACT_REF_SETTLE_DELAY_US              (1U)

/* The wait delay time that occurs after the active reference is settled.
*  Final delay is used in transition into the normal regulator current mode
*/
#define SET_NORMAL_CURRENT_MODE_DELAY_US     (1U)

/* The internal define of the tries number in the
* Cy_SysPm_SystemSetMinRegulatorCurrent() function
*/
#define WAIT_DELAY_TRIES                (100U)

/* The internal define of the tries number in the
* Cy_SysPm_SystemSetMinRegulatorCurrent() function
*/
#define CY_SYSPM_CBUCK_BUSY_RETRY_COUNT         (100U)
#define CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_MS      (1U)

/* Define for ROM trim for 0.9V */
#define CPUSS_TRIM_ROM_VOLT_0_900         (0x00000012U)

/* Define for ROM trim for 1.0V */
#define CPUSS_TRIM_ROM_VOLT_1_000         (0x00000012U)

/* Define for ROM trim for 1.1V */
#define CPUSS_TRIM_ROM_VOLT_1_100         (0x00000013U)

/* Define for RAM trim for 0.9V */
#define CPUSS_TRIM_RAM_VOLT_0_900         (0x00006012U)

/* Define for RAM trim for 1.0V */
#define CPUSS_TRIM_RAM_VOLT_1_000         (0x00005012U)

/* Define for RAM trim for 1.1V */
#define CPUSS_TRIM_RAM_VOLT_1_100         (0x00004013U)

/* Mask for the RAM write check bits */
#define CPUSS_TRIM_RAM_CTL_WC_MASK        (0x3UL << 10U)

/*******************************************************************************
*       Internal Variables
*******************************************************************************/

/* Array of the callback roots */
static cy_stc_syspm_callback_t* pmCallbackRoot[CALLBACK_ROOT_NR] = {(void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0};

/* The array of the pointers to failed callback */
static cy_stc_syspm_callback_t* failedCallback[CALLBACK_ROOT_NR] = {(void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0, (void *)0};


void Cy_SysPm_Init(void)
{
    if(CY_SYSPM_WARM_BOOT_MODE != Cy_SysPm_GetBootMode())
    {
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_MAIN_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_PD1_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_SRAM0_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_SRAM1_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_SYSCPU_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_APPSS_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE); /* Suppress a compiler warning about unused return value */
        (void)cy_pd_ppu_init((struct ppu_v1_reg *)CY_PPU_U55_BASE); /* Suppress a compiler warning about unused return value */

        /* Set Default mode to DEEPSLEEP */
        (void)Cy_SysPm_SetDeepSleepMode(CY_SYSPM_MODE_DEEPSLEEP);

        /* Clear Reset reason, this ensures that API:Cy_SysPm_IsSystemDeepsleep works
         * fine to capture the DEEP SLEEP state from which system has wake up.
         */
        Cy_SysLib_ClearResetReason();
    }
    else
    {
        /* Call the registered callback functions with the CY_SYSPM_AFTER_TRANSITION
        *  parameter
        */
        if (pmCallbackRoot[CY_SYSPM_DEEPSLEEP_RAM] != NULL)
        {
            (void)Cy_SysPm_ExecuteCallback(((cy_en_syspm_callback_type_t)CY_SYSPM_DEEPSLEEP_RAM), CY_SYSPM_AFTER_TRANSITION); /* Suppress a compiler warning about unused return value */
        }

    }

}

cy_en_syspm_status_t Cy_SysPm_CpuEnterSleep(cy_en_syspm_waitfor_t waitFor)
{
    uint32_t interruptState;
    uint32_t cbSleepRootIdx = (uint32_t) CY_SYSPM_SLEEP;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_ASSERT_L3(CY_SYSPM_IS_WAIT_FOR_VALID(waitFor));

    /* Call registered callback functions with CY_SYSPM_CHECK_READY parameter */
    if (pmCallbackRoot[cbSleepRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_CHECK_READY);
    }

    /* The CPU can switch into the Sleep power mode only when
    *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
    *  parameter return CY_SYSPM_SUCCESS.
    */
    if(retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_BEFORE_TRANSITION);
        }

        /* The CPU enters the Sleep power mode upon execution of WFI/WFE */
        SCB_SCR &= (uint32_t) ~SCB_SCR_SLEEPDEEP_Msk;

        if(waitFor != CY_SYSPM_WAIT_FOR_EVENT)
        {
            __WFI();
        }
        else
        {
            __WFE();
        }
        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        *  CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbSleepRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_SLEEP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }
    return retVal;
}


cy_en_syspm_status_t Cy_SysPm_SetDeepSleepMode(cy_en_syspm_deep_sleep_mode_t deepSleepMode)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_FAIL;

    switch(deepSleepMode)
    {
        case CY_SYSPM_MODE_DEEPSLEEP:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE, (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM0_BASE, (uint32_t)CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM1_BASE, (uint32_t)CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SYSCPU_BASE, (uint32_t)CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPSS_BASE, (uint32_t)CY_SYSTEM_APPSS_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_U55_BASE, (uint32_t)CY_SYSTEM_U55_PPU_DEEPSLEEP_MODE); /* Suppress a compiler warning about unused return value */
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_RAM:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE, (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM0_BASE, (uint32_t)CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM1_BASE, (uint32_t)CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SYSCPU_BASE, (uint32_t)CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPSS_BASE, (uint32_t)CY_SYSTEM_APPSS_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_U55_BASE, (uint32_t)CY_SYSTEM_U55_PPU_DEEPSLEEP_RAM_MODE); /* Suppress a compiler warning about unused return value */
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        case CY_SYSPM_MODE_DEEPSLEEP_OFF:
        {
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE, (uint32_t)CY_SYSTEM_MAIN_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_PD1_BASE, (uint32_t)CY_SYSTEM_PD1_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM0_BASE, (uint32_t)CY_SYSTEM_SRAM0_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SRAM1_BASE, (uint32_t)CY_SYSTEM_SRAM1_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SYSCPU_BASE, (uint32_t)CY_SYSTEM_SYSCPU_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPSS_BASE, (uint32_t)CY_SYSTEM_APPSS_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_APPCPU_BASE, (uint32_t)CY_SYSTEM_APPCPU_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_SOCMEM_BASE, (uint32_t)CY_SYSTEM_SOCMEM_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            (void)cy_pd_ppu_set_power_mode((struct ppu_v1_reg *)CY_PPU_U55_BASE, (uint32_t)CY_SYSTEM_U55_PPU_DEEPSLEEP_OFF_MODE); /* Suppress a compiler warning about unused return value */
            retVal = CY_SYSPM_SUCCESS;
        }
        break;

        default:
            retVal = CY_SYSPM_BAD_PARAM;
        break;
    }
    return retVal;
}

cy_en_syspm_deep_sleep_mode_t Cy_SysPm_GetDeepSleepMode(void)
{
    uint32_t mode;
    cy_en_syspm_deep_sleep_mode_t deepSleepMode;

    mode = (uint32_t)cy_pd_ppu_get_programmed_power_mode((struct ppu_v1_reg *)CY_PPU_MAIN_BASE);

    switch(mode)
    {
        case CY_SYSTEM_DEEPSLEEP_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP;
        }
        break;

        case CY_SYSTEM_DEEPSLEEP_RAM_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_RAM;
        }
        break;

        case CY_SYSTEM_DEEPSLEEP_OFF_PPU_MODES:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_OFF;
        }
        break;

        default:
        {
            deepSleepMode = CY_SYSPM_MODE_DEEPSLEEP_NONE;
        }
        break;
    }

    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_deep_sleep_mode_t enum.');
    return ((cy_en_syspm_deep_sleep_mode_t)deepSleepMode);
}

cy_en_syspm_boot_mode_t Cy_SysPm_GetBootMode(void)
{
    uint32_t resCause, resCause2;
    cy_en_syspm_boot_mode_t deepSleepWakeMode = CY_SYSPM_POR_BOOT_MODE;

    resCause = SRSS_RES_CAUSE;
    resCause2 = SRSS_RES_CAUSE2;

    if((resCause == 0UL) || (resCause2 == 0UL))
    {
        switch(Cy_SysPm_GetDeepSleepMode())
        {
            case CY_SYSPM_MODE_DEEPSLEEP_RAM:
            {
                deepSleepWakeMode = CY_SYSPM_WARM_BOOT_MODE;
            }
            break;

            case CY_SYSPM_MODE_DEEPSLEEP_OFF:
            {
                deepSleepWakeMode = CY_SYSPM_COLD_BOOT_MODE;
            }
            break;

            default:
            {
                deepSleepWakeMode = CY_SYSPM_POR_BOOT_MODE;
            }
            break;
        }

    }

    return ((cy_en_syspm_boot_mode_t)deepSleepWakeMode);
}

cy_en_syspm_status_t Cy_SysPm_CpuEnterDeepSleep(cy_en_syspm_waitfor_t waitFor)
{
    uint32_t interruptState;
    uint32_t cbDeepSleepRootIdx = (uint32_t) Cy_SysPm_GetDeepSleepMode();
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    CY_ASSERT_L3(CY_SYSPM_IS_WAIT_FOR_VALID(waitFor));
    CY_ASSERT_L3(CY_SYSPM_IS_DEEPSLEEP_MODE_VALID(cbDeepSleepRootIdx));

    //Check if LPM is ready
    if(!Cy_SysPm_IsLpmReady())
    {
        retVal = CY_SYSPM_FAIL;
    }
    else
    {
        /* Call the registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter
        */
        if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
        {
            retVal = Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_READY);
        }

        /* The CPU can switch into the Deep Sleep power mode only when
        *  all executed registered callback functions with the CY_SYSPM_CHECK_READY
        *  parameter return CY_SYSPM_SUCCESS
        */
        if (retVal == CY_SYSPM_SUCCESS)
        {
            /* Call the registered callback functions with the
            * CY_SYSPM_BEFORE_TRANSITION parameter
            */
            interruptState = Cy_SysLib_EnterCriticalSection();
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_BEFORE_TRANSITION);
            }
                /* The CPU enters Deep Sleep mode upon execution of WFI/WFE
                 * use Cy_SysPm_SetDeepSleepMode to set various deepsleep modes */
                SCB_SCR |= SCB_SCR_SLEEPDEEP_Msk;

                if(waitFor != CY_SYSPM_WAIT_FOR_EVENT)
                {
                    __WFI();
                }
                else
                {
                    __WFE();
                }

            Cy_SysLib_ExitCriticalSection(interruptState);
        }
        if (retVal == CY_SYSPM_SUCCESS)
        {
            /* Call the registered callback functions with the CY_SYSPM_AFTER_TRANSITION
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_AFTER_TRANSITION);
            }
        }
        else
        {
            /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
            *  undo everything done in the callback with the CY_SYSPM_CHECK_READY
            *  parameter
            */
            if (pmCallbackRoot[cbDeepSleepRootIdx] != NULL)
            {
                (void) Cy_SysPm_ExecuteCallback((cy_en_syspm_callback_type_t)cbDeepSleepRootIdx, CY_SYSPM_CHECK_FAIL);
            }
        }
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemEnterHibernate(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    uint32_t cbHibernateRootIdx = (uint32_t) CY_SYSPM_HIBERNATE;
    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbHibernateRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into Hibernate power mode only when
    *  all executed registered callback functions with CY_SYSPM_CHECK_READY
    *  parameter return CY_SYSPM_SUCCESS.
    */
    if(retVal == CY_SYSPM_SUCCESS)
    {
        /* Call registered callback functions with CY_SYSPM_BEFORE_TRANSITION
        *  parameter
        */
        (void) Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbHibernateRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_BEFORE_TRANSITION);
        }

        /* Preserve the token that will be retained through a wakeup sequence.
         * This could be used by Cy_SysLib_GetResetReason() to differentiate
         * Wakeup from a general reset event.
         * Preserve the wakeup source(s) configuration.
         */
        SRSS_PWR_HIBERNATE = (SRSS_PWR_HIBERNATE  | HIBERNATE_TOKEN);

        /* Clear Previous Wakeup Reasons */
        Cy_SysPm_ClearHibernateWakeupCause();

        /* Disable overriding by the peripherals the next pin-freeze command */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* The second write causes freezing of I/O cells to save the I/O-cell state */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* Third write cause system to enter Hibernate */
        SRSS_PWR_HIBERNATE |= SET_HIBERNATE_MODE;

        /* Read register to make sure it is settled */
        (void) SRSS_PWR_HIBERNATE;

        /* Wait for transition */
        __WFI();

        /* The callback function calls with the CY_SYSPM_AFTER_TRANSITION
        * parameter in the Hibernate power mode are not applicable as system
        * wake-up was made on system reboot.
        */

        /* A wakeup from Hibernate is performed by toggling of the wakeup
        * pins, or WDT matches, or Backup domain alarm expires. This depends on
        * what item is configured in the Hibernate register. After a wakeup
        * event, a normal Boot procedure occurs.
        * There is no need to exit from the critical section.
        */
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter. The return value should be CY_SYSPM_SUCCESS.
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_HIBERNATE, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }
    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemSetMinRegulatorCurrent(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_CANCELED;

    /* Check if the power circuits are ready to enter into regulator minimum
    *  current mode
    */
    if (Cy_SysPm_IsLpmReady())
    {
        SRSS_PWR_CTL2 |= (SRSS_PWR_CTL2_BGREF_LPMODE_Msk);

        /* This wait time allows the circuits to remove their dependence on
        *  the Active mode circuits, such as active Reference
        */
        Cy_SysLib_DelayUs(SET_MIN_CURRENT_MODE_DELAY_US);

        /* Disable active reference */
        SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_REFSYS_VBUF_DIS_Msk;

        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;


}

cy_en_syspm_status_t Cy_SysPm_SystemSetNormalRegulatorCurrent(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;

    uint32_t timeOut = WAIT_DELAY_TRIES;

    /* Configure the regulator normal current mode for the POR/BOD circuits
    *  and for the Voltage References
    */

    /* Bring Regulators Power Circuit out of LPMODE */
    SRSS_PWR_CTL2 &= (uint32_t)~(SRSS_PWR_CTL2_REFSYS_VBUF_DIS_Msk);

    /* This wait time allows setting active Reference */
    Cy_SysLib_DelayUs(ACT_REF_SETTLE_DELAY_US);

    while ((0U == _FLD2VAL(SRSS_PWR_CTL2_REFSYS_VREF_OK, SRSS_PWR_CTL2)) && (0U != timeOut))
    {
        timeOut--;
    }

    if (0U != timeOut)
    {
        /* Disable the low-power for Bandgap reference circuit */
        SRSS_PWR_CTL2 &= (uint32_t) ~SRSS_PWR_CTL2_BGREF_LPMODE_Msk;

        /* Delay to finally set the normal current mode */
        Cy_SysLib_DelayUs(SET_NORMAL_CURRENT_MODE_DELAY_US);

        retVal= CY_SYSPM_SUCCESS;
    }

    return retVal;

}

bool Cy_SysPm_SystemIsMinRegulatorCurrentSet(void)
{
    return ((0U != _FLD2VAL(SRSS_PWR_CTL2_REFSYS_VBUF_DIS, SRSS_PWR_CTL2)) ? false : true);
}

cy_en_syspm_status_t Cy_SysPm_LdoSetMode(cy_en_syspm_ldo_mode_t mode)
{
    CY_ASSERT_L3(CY_SYSPM_IS_LDO_MODE_VALID(mode));

    cy_en_syspm_status_t retVal = CY_SYSPM_CANCELED;

    switch (mode)
    {
        case CY_SYSPM_LDO_MODE_NORMAL:
        {
            retVal = Cy_SysPm_SystemSetNormalRegulatorCurrent();
        }
        break;

        case CY_SYSPM_LDO_MODE_MIN:
        {
            retVal = Cy_SysPm_SystemSetMinRegulatorCurrent();
        }
        break;

        default:
            retVal = CY_SYSPM_FAIL;
        break;
    }

    return retVal;
}

cy_en_syspm_ldo_mode_t Cy_SysPm_LdoGetMode(void)
{
    cy_en_syspm_ldo_mode_t retVal;

    if (Cy_SysPm_SystemIsMinRegulatorCurrentSet())
    {
        retVal = CY_SYSPM_LDO_MODE_MIN;
    }
    else
    {
        retVal = CY_SYSPM_LDO_MODE_NORMAL;
    }

    return retVal;
}

void Cy_SysPm_CpuSleepOnExit(bool enable)
{
    if(enable)
    {
        /* Enable sleep-on-exit feature */
        SCB_SCR |= SCB_SCR_SLEEPONEXIT_Msk;
    }
    else
    {
        /* Disable sleep-on-exit feature */
        SCB_SCR &= (uint32_t) ~(SCB_SCR_SLEEPONEXIT_Msk);
    }
}

void Cy_SysPm_SetHibernateWakeupSource(uint32_t wakeupSource)
{
    CY_ASSERT_L3(CY_SYSPM_IS_WAKE_UP_SOURCE_VALID(wakeupSource));

    uint32_t polarityMask = 0U;
    uint32_t wakeSrcMask = 0U;

    /* LPCOMP0 & LPCOMP1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK;
    }

    /* PIN0 & PIN1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN1_MASK;
    }

    /* RTC */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_RTC_MASK;
    }

    /* WDT */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_WDT))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_WDT_MASK;
    }

    /* Polarity Mask */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK;
    }

    SRSS_PWR_HIB_WAKE_CTL = (SRSS_PWR_HIB_WAKE_CTL | wakeSrcMask);
    SRSS_PWR_HIB_WAKE_CTL2 = (SRSS_PWR_HIB_WAKE_CTL2 | polarityMask);

    /* Read registers to make sure it is settled */
    (void) SRSS_PWR_HIB_WAKE_CTL;
    (void) SRSS_PWR_HIB_WAKE_CTL2;

}

void Cy_SysPm_ClearHibernateWakeupSource(uint32_t wakeupSource)
{
    CY_ASSERT_L3(CY_SYSPM_IS_WAKE_UP_SOURCE_VALID(wakeupSource));

    uint32_t polarityMask = 0U;
    uint32_t wakeSrcMask = 0U;

    /* LPCOMP0 & LPCOMP1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_MASK;
    }

    /* PIN0 & PIN1 */
    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN0_MASK;
    }

    if ((0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW)) || (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH)))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_PIN1_MASK;
    }

    /* RTC */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_RTC_MASK;
    }

    /* WDT */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_WDT))
    {
        wakeSrcMask |= CY_SYSPM_HIB_WAKEUP_WDT_MASK;
    }

    /* Polarity Mask */
    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK;
    }

    if (0U != (wakeupSource & (uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH))
    {
        polarityMask |= CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK;
    }

    SRSS_PWR_HIB_WAKE_CTL = (SRSS_PWR_HIB_WAKE_CTL & (~wakeSrcMask));
    SRSS_PWR_HIB_WAKE_CTL2 = (SRSS_PWR_HIB_WAKE_CTL2 & (~polarityMask));

    /* Read registers to make sure it is settled */
    (void) SRSS_PWR_HIB_WAKE_CTL;
    (void) SRSS_PWR_HIB_WAKE_CTL2;
}

cy_en_syspm_hibernate_wakeup_source_t Cy_SysPm_GetHibernateWakeupCause(void)
{
    uint32_t wakeupCause;
    uint32_t wakeupCausePolarity;

    wakeupCause = SRSS_PWR_HIB_WAKE_CAUSE;

    wakeupCausePolarity = (wakeupCause & (uint32_t)(CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK |
                                          CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK |
                                          CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK    |
                                          CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK ));

    switch(wakeupCause)
    {
        case CY_SYSPM_HIB_WAKEUP_PIN0_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_PIN0_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN0_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN0_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_PIN1_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_PIN1_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN1_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_PIN1_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_LPCOMP0_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_LPCOMP0_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP0_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_LPCOMP1_POS:
        {
            if (0U != (wakeupCausePolarity & (uint32_t)CY_SYSPM_HIB_WAKEUP_LPCOMP1_POLARITY_HIGH_MASK))
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_HIGH);
            }
            else
            {
                wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_LPCOMP1_LOW);
            }
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_RTC_MASK:
        {
            wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_RTC_ALARM);
        }
        break;

        case CY_SYSPM_HIB_WAKEUP_WDT_MASK:
        {
            wakeupCause = ((uint32_t)CY_SYSPM_HIBERNATE_WDT);
        }
        break;

        default:
            CY_ASSERT_L2(false);
        break;
    }

    return (cy_en_syspm_hibernate_wakeup_source_t)wakeupCause;
}

void Cy_SysPm_ClearHibernateWakeupCause(void)
{
    uint32_t temp = SRSS_PWR_HIB_WAKE_CAUSE;
    SRSS_PWR_HIB_WAKE_CAUSE = temp;
}

cy_en_syspm_status_t Cy_SysPm_CoreBuckSetVoltage(cy_en_syspm_core_buck_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(voltage));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL, SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, voltage);

    return Cy_SysPm_CoreBuckStatus();
}

cy_en_syspm_core_buck_voltage_t Cy_SysPm_CoreBuckGetVoltage(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_voltage_t enum.');
    return (cy_en_syspm_core_buck_voltage_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL_CBUCK_VSEL, SRSS_PWR_CBUCK_CTL));
}

void Cy_SysPm_CoreBuckSetMode(cy_en_syspm_core_buck_mode_t mode)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(mode));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL, SRSS_PWR_CBUCK_CTL_CBUCK_MODE, mode);
}

cy_en_syspm_core_buck_mode_t Cy_SysPm_CoreBuckGetMode(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_mode_t enum.');
    return (cy_en_syspm_core_buck_mode_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL_CBUCK_MODE, SRSS_PWR_CBUCK_CTL));
}

cy_en_syspm_status_t Cy_SysPm_CoreBuckDpslpSetVoltage(cy_en_syspm_core_buck_voltage_t voltage)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_VOLTAGE_VALID(voltage));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_DPSLP_CTL, SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_VSEL, voltage);

    return Cy_SysPm_CoreBuckStatus();
}

cy_en_syspm_core_buck_voltage_t Cy_SysPm_CoreBuckDpslpGetVoltage(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_voltage_t enum.');
    return (cy_en_syspm_core_buck_voltage_t)(_FLD2VAL(SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_VSEL, SRSS_PWR_CBUCK_DPSLP_CTL));
}

void Cy_SysPm_CoreBuckDpslpSetMode(cy_en_syspm_core_buck_mode_t mode)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_MODE_VALID(mode));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_DPSLP_CTL, SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_MODE, mode);
}

cy_en_syspm_core_buck_mode_t Cy_SysPm_CoreBuckDpslpGetMode(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_mode_t enum.');
    return (cy_en_syspm_core_buck_mode_t)(_FLD2VAL(SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_MODE, SRSS_PWR_CBUCK_DPSLP_CTL));
}

void Cy_SysPm_CoreBuckDpslpEnableOverride(bool enable)
{
    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_DPSLP_CTL, SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_OVERRIDE, ((enable) ? 1UL : 0UL));
}

bool Cy_SysPm_CoreBuckDpslpIsOverrideEnabled(void)
{
    return (_FLD2BOOL(SRSS_PWR_CBUCK_DPSLP_CTL_CBUCK_DPSLP_OVERRIDE, SRSS_PWR_CBUCK_DPSLP_CTL)? true : false);
}


void Cy_SysPm_CoreBuckSetProfile(cy_en_syspm_core_buck_profile_t profile)
{
    CY_ASSERT_L2(CY_SYSPM_IS_CORE_BUCK_PROFILE_VALID(profile));

    CY_REG32_CLR_SET(SRSS_PWR_CBUCK_CTL2, SRSS_PWR_CBUCK_CTL2_CBUCK_PROFILE, profile);
}

cy_en_syspm_core_buck_profile_t Cy_SysPm_CoreBuckGetProfile(void)
{
    CY_MISRA_DEVIATE_LINE('MISRA C-2012 Rule 10.8','Intentional typecast to cy_en_syspm_core_buck_profile_t enum.');
    return (cy_en_syspm_core_buck_profile_t)(_FLD2VAL(SRSS_PWR_CBUCK_CTL2_CBUCK_PROFILE, SRSS_PWR_CBUCK_CTL2));
}

cy_en_syspm_status_t Cy_SysPm_CoreBuckStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_PMU_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_Delay(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_MS);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_RetLdoStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_RETLDO_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_Delay(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_MS);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_RetLdoConfigure(cy_stc_syspm_retldo_params_t *retLdoParam)
{
    CY_ASSERT_L2(CY_SYSPM_IS_RETLDO_VOLTAGE_VALID(retLdoParam->activeVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_RETLDO_VOLTAGE_VALID(retLdoParam->deepsleepVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_RETLDO_GAIN_VALID(retLdoParam->activeGain));
    CY_ASSERT_L2(CY_SYSPM_IS_RETLDO_GAIN_VALID(retLdoParam->deepsleepGain));

    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_RETLDO_CTL_RETLDO_LVL, retLdoParam->activeVoltSel);
    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_RETLDO_CTL_RETLDO_GAIN, retLdoParam->activeGain);

    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_RETLDO_CTL_RETLDO_LVL_DPSLP, retLdoParam->deepsleepVoltSel);
    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_RETLDO_CTL_RETLDO_GAIN_DPSLP, retLdoParam->deepsleepGain);

    return Cy_SysPm_RetLdoStatus();
}

cy_en_syspm_status_t Cy_SysPm_SramLdoStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_SRAMLDO_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_Delay(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_MS);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SramLdoConfigure(cy_stc_syspm_sramldo_params_t *sramLdoParam)
{
    CY_ASSERT_L2(CY_SYSPM_IS_SRAMLDO_VOLTAGE_VALID(sramLdoParam->sramLdoVoltSel));

    CY_REG32_CLR_SET(SRSS_PWR_SRAMLDO_CTL, SRSS_PWR_SRAMLDO_CTL_SRAMLDO_EN, (sramLdoParam->sramLdoEnable ? 1U : 0U));

    CY_REG32_CLR_SET(SRSS_PWR_SRAMLDO_CTL, SRSS_PWR_SRAMLDO_CTL_SRAMLDO_DPSLP_EN, (sramLdoParam->deepsleepSramLdoEnable ? 1U : 0U));

    CY_REG32_CLR_SET(SRSS_PWR_RETLDO_CTL, SRSS_PWR_SRAMLDO_CTL_SRAMLDO_VOUT, sramLdoParam->sramLdoVoltSel);

    return Cy_SysPm_SramLdoStatus();
}

cy_en_syspm_status_t Cy_SysPm_MiscLdoStatus(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_TIMEOUT;
    uint32_t syspmCbuckRetry = CY_SYSPM_CBUCK_BUSY_RETRY_COUNT;

    while((_FLD2VAL(SRSS_PWR_CBUCK_STATUS_MISCLDO_DONE, SRSS_PWR_CBUCK_STATUS) == 0U) && (syspmCbuckRetry != 0U))
    {
        syspmCbuckRetry--;
        Cy_SysLib_Delay(CY_SYSPM_CBUCK_BUSY_RETRY_DELAY_MS);
    }

    if(syspmCbuckRetry != 0UL)
    {
        retVal = CY_SYSPM_SUCCESS;
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_MiscLdoConfigure(cy_stc_syspm_miscldo_params_t *miscLdoParam)
{
    CY_ASSERT_L2(CY_SYSPM_IS_MISCLDO_VOLTAGE_VALID(miscLdoParam->miscLdoVoltSel));
    CY_ASSERT_L2(CY_SYSPM_IS_MISCLDO_VCCACT_TRIM_VALID(miscLdoParam->miscLdoVaccActTrimSel));
    CY_ASSERT_L2(CY_SYSPM_IS_MISCLDO_MODE_VALID(miscLdoParam->miscLdoMode));

    CY_REG32_CLR_SET(SRSS_PWR_MISCLDO_CTL, SRSS_PWR_MISCLDO_CTL_MISCLDO_EN, (miscLdoParam->miscLdoEnable ? 1U : 0U));

    CY_REG32_CLR_SET(SRSS_PWR_MISCLDO_CTL, SRSS_PWR_MISCLDO_CTL_MISCLDO_MODE, miscLdoParam->miscLdoMode);

    CY_REG32_CLR_SET(SRSS_PWR_MISCLDO_CTL, SRSS_PWR_MISCLDO_CTL_MISCLDO_VOUT, miscLdoParam->miscLdoVoltSel);

    CY_REG32_CLR_SET(SRSS_PWR_MISCLDO_CTL, SRSS_PWR_MISCLDO_CTL_MISCLDO_VCCACT_TRIM, miscLdoParam->miscLdoVaccActTrimSel);

    return Cy_SysPm_MiscLdoStatus();
}

bool Cy_SysPm_RegisterCallback(cy_stc_syspm_callback_t* handler)
{
    bool retVal = false;

    /* Verify the input parameters. */
    if ((handler != NULL) && (handler->callbackParams != NULL) && (handler->callback != NULL))
    {
        uint32_t callbackRootIdx = (uint32_t) handler->type;

        /* If the callback list is not empty. */
        if (pmCallbackRoot[callbackRootIdx] != NULL)
        {
            cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[callbackRootIdx];
            cy_stc_syspm_callback_t* insertPos  = curCallback;

            /* Find the callback after which the new callback is to be
             * inserted. Ensure the given callback has not been registered.
             */
            while ((NULL != curCallback->nextItm) && (curCallback != handler))
            {
                curCallback = curCallback->nextItm;
                /* Callbacks with the same order value are stored in the order
                 * they are registered.
                 */
                if (curCallback->order <= handler->order)
                {
                    insertPos = curCallback;
                }
            }
            /* If the callback has not been registered. */
            if (curCallback != handler)
            {
                /* If the callback is to be inserted at the beginning of the list. */
                if ((insertPos->prevItm == NULL) && (handler->order < insertPos->order))
                {
                    handler->nextItm = insertPos;
                    handler->prevItm = NULL;
                    handler->nextItm->prevItm = handler;
                    pmCallbackRoot[callbackRootIdx] = handler;
                }
                else
                {
                    handler->nextItm = insertPos->nextItm;
                    handler->prevItm = insertPos;

                    /* If the callback is not inserted at the end of the list. */
                    if (handler->nextItm != NULL)
                    {
                        handler->nextItm->prevItm = handler;
                    }
                    insertPos->nextItm = handler;
                }
                retVal = true;
            }
        }
        else
        {
            /* The callback list is empty. */
            pmCallbackRoot[callbackRootIdx] = handler;
            handler->nextItm = NULL;
            handler->prevItm = NULL;
            retVal = true;
        }
    }
    return retVal;
}

bool Cy_SysPm_UnregisterCallback(cy_stc_syspm_callback_t const *handler)
{
    bool retVal = false;

    if (handler != NULL)
    {
        uint32_t callbackRootIdx = (uint32_t) handler->type;
        cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[callbackRootIdx];

        /* Search requested callback item in the linked list */
        while (curCallback != NULL)
        {
            /* Requested callback is found */
            if (curCallback == handler)
            {
                retVal = true;
                break;
            }

            /* Go to next callback item in the linked list */
            curCallback = curCallback->nextItm;
        }

        if (retVal)
        {
            /* Requested callback is first in the list */
            if (pmCallbackRoot[callbackRootIdx] == handler)
            {
                /* Check whether this the only callback registered */
                if (pmCallbackRoot[callbackRootIdx]->nextItm != NULL)
                {
                    pmCallbackRoot[callbackRootIdx] = pmCallbackRoot[callbackRootIdx]->nextItm;
                    pmCallbackRoot[callbackRootIdx]->prevItm = NULL;
                }
                else
                {
                    /* We had only one callback */
                    pmCallbackRoot[callbackRootIdx] = NULL;
                }
            }
            else
            {
                /* Update links of related to unregistered callback items */
                curCallback->prevItm->nextItm = curCallback->nextItm;

                if (curCallback->nextItm != NULL)
                {
                    curCallback->nextItm->prevItm = curCallback->prevItm;
                }
            }
        }
    }

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_ExecuteCallback(cy_en_syspm_callback_type_t type, cy_en_syspm_callback_mode_t mode)
{
    CY_ASSERT_L3(CY_SYSPM_IS_CALLBACK_TYPE_VALID(type));
    CY_ASSERT_L3(CY_SYSPM_IS_CALLBACK_MODE_VALID(mode));

    static cy_stc_syspm_callback_t* lastExecutedCallback = NULL;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    cy_stc_syspm_callback_t* curCallback = pmCallbackRoot[(uint32_t) type];
    cy_stc_syspm_callback_params_t curParams;

    if ((mode == CY_SYSPM_BEFORE_TRANSITION) || (mode == CY_SYSPM_CHECK_READY))
    {
        /* Execute registered callbacks with order from first registered to the
        *  last registered. Stop executing if CY_SYSPM_FAIL was returned in
        *  CY_SYSPM_CHECK_READY mode
        */
        while ((curCallback != NULL) && ((retVal != CY_SYSPM_FAIL) || (mode != CY_SYSPM_CHECK_READY)))
        {
            /* The modes defined in the .skipMode element are not executed */
            if (0UL == ((uint32_t) mode & curCallback->skipMode))
            {
                /* Update elements for local callback parameter values */
                curParams.base = curCallback->callbackParams->base;
                curParams.context = curCallback->callbackParams->context;

                retVal = curCallback->callback(&curParams, mode);

                /* Update callback pointer with value of executed callback.
                * Such update is required to execute further callbacks in
                * backward order after exit from LP mode or to undo
                * configuration after callback returned fail: from last called
                * to first registered.
                */
                lastExecutedCallback = curCallback;
            }
            curCallback = curCallback->nextItm;
        }

        if (mode == CY_SYSPM_CHECK_READY)
        {
            /* Update the pointer to  the failed callback with the result of the callback execution.
            *  If the callback fails, the value of the pointer will be updated
            *  with the address of the callback which returned CY_SYSPM_FAIL, else,
            *  it will be updated with NULL.
            */
            if(retVal == CY_SYSPM_FAIL)
            {
                failedCallback[(uint32_t) type] = lastExecutedCallback;
            }
            else
            {
                failedCallback[(uint32_t) type] = NULL;
            }
        }
    }
    else
    {
        /* Execute registered callbacks with order from lastCallback or last
        * executed to the first registered callback. Such a flow is required if
        * a previous callback function returned CY_SYSPM_FAIL or a previous
        * callback mode was CY_SYSPM_BEFORE_TRANSITION. Such an order is
        * required to undo configurations in correct backward order.
        */
        if (mode != CY_SYSPM_CHECK_FAIL)
        {
            while (curCallback->nextItm != NULL)
            {
                curCallback = curCallback->nextItm;
            }
        }
        else
        {
            /* Skip last executed callback that returns CY_SYSPM_FAIL, as this
            *  callback already knows that it failed.
            */
            curCallback = lastExecutedCallback;

            if (curCallback != NULL)
            {
                curCallback = curCallback->prevItm;
            }
        }

        /* Execute callback functions with required type and mode */
        while (curCallback != NULL)
        {
            /* The modes defined in the .skipMode element are not executed */
            if (0UL == ((uint32_t) mode & curCallback->skipMode))
            {
                /* Update elements for local callback parameter values */
                curParams.base = curCallback->callbackParams->base;
                curParams.context = curCallback->callbackParams->context;

                retVal = curCallback->callback(&curParams, mode);
            }
            curCallback = curCallback->prevItm;
        }
    }

    return retVal;
}

cy_stc_syspm_callback_t* Cy_SysPm_GetFailedCallback(cy_en_syspm_callback_type_t type)
{
    return failedCallback[(uint32_t) type];
}

void Cy_SysPm_IoUnfreeze(void)
{
    uint32_t interruptState;
    interruptState = Cy_SysLib_EnterCriticalSection();

    /* Preserve the last reset reason and wakeup polarity. Then, unfreeze I/O:
     * write PWR_HIBERNATE.FREEZE=0, .UNLOCK=0x3A, .HIBERANTE=0
     */
    SRSS_PWR_HIBERNATE = (SRSS_PWR_HIBERNATE & HIBERNATE_RETAIN_STATUS_MASK) | HIBERNATE_UNLOCK_VAL;

    /* Lock the Hibernate mode:
    * write PWR_HIBERNATE.HIBERNATE=0, UNLOCK=0x00, HIBERANTE=0
    */
    SRSS_PWR_HIBERNATE &= HIBERNATE_RETAIN_STATUS_MASK;

    /* Read register to make sure it is settled */
    (void) SRSS_PWR_HIBERNATE;

    Cy_SysLib_ExitCriticalSection(interruptState);
}

bool Cy_SysPm_IoIsFrozen(void)
{
    return (0U != _FLD2VAL(SRSS_PWR_HIBERNATE_FREEZE, SRSS_PWR_HIBERNATE));
}

void Cy_SysPm_DeepSleepIoUnfreeze(void)
{
    uint32_t interruptState;
    interruptState = Cy_SysLib_EnterCriticalSection();

    /* Unfreeze IO's which are frozen during DEEPSLEEP-RAM/OFF
    * Entry
    */
    SRSS_PWR_CTL2 |= SRSS_PWR_CTL2_FREEZE_DPSLP_Msk;

    Cy_SysLib_ExitCriticalSection(interruptState);
}

bool Cy_SysPm_DeepSleepIoIsFrozen(void)
{
    return (0U != _FLD2VAL(SRSS_PWR_CTL2_FREEZE_DPSLP, SRSS_PWR_CTL2));
}


void Cy_SysPm_CpuSendWakeupEvent(void)
{
    __SEV();
}

bool Cy_SysPm_IsLpmReady(void)
{
    return (_FLD2BOOL(SRSS_PWR_CTL_LPM_READY, SRSS_PWR_CTL)? true : false);
}

/* This API is an inline version of Cy_SysPm_SetSRAMMacroPwrMode */
__STATIC_FORCEINLINE cy_en_syspm_status_t Cy_SysPm_SetSRAMMacroPwrModeInline(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    CY_ASSERT_L3(sramNum == CY_SYSPM_SRAM0_MEMORY);
    CY_ASSERT_L3((sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON) || (sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_OFF));
    CY_ASSERT_L3(sramMacroNum < CY_CPUSS_RAMC0_MACRO_NR);

    CY_UNUSED_PARAM(sramNum);

    /* Unlock PWR MACRO Control */
    /* Clear bit 0(CLR0)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR1;

    if(sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON)
    {
        /* Enable the Macro Number */
        MXSRAMC_PWR_MACRO_CTL &= ~(0x1UL << (uint32_t)sramMacroNum);
    }
    else
    {
        /* Disable the Macro Number */
        MXSRAMC_PWR_MACRO_CTL |= (0x1UL << (uint32_t)sramMacroNum);
    }
    /* Wait for the PWR_DONE status */
    while(!_FLD2BOOL(RAMC_STATUS_PWR_DONE, MXSRAMC_STATUS)){}

    /* Lock PWR MACRO Control(Set SET01) */
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_SET01;

    return CY_SYSPM_SUCCESS;
}

cy_en_syspm_status_t Cy_SysPm_SetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    return Cy_SysPm_SetSRAMMacroPwrModeInline(sramNum, sramMacroNum, sramPwrMode);
}

cy_en_syspm_sram_pwr_mode_t Cy_SysPm_GetSRAMMacroPwrMode(cy_en_syspm_sram_index_t sramNum, uint32_t sramMacroNum)
{
    cy_en_syspm_sram_pwr_mode_t value;

    CY_ASSERT_L3(sramNum == CY_SYSPM_SRAM0_MEMORY);
    CY_ASSERT_L3(sramMacroNum < CY_CPUSS_RAMC0_MACRO_NR);

    CY_UNUSED_PARAM(sramNum);

    /* Unlock PWR MACRO Control */
    /* Clear bit 0(CLR0)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR0;
    /* Clear bit 1(CLR1)*/
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_CLR1;

    value = ((MXSRAMC_PWR_MACRO_CTL & (0x1UL << (uint32_t)sramMacroNum)) != 0UL) ? CY_SYSPM_SRAM_PWR_MODE_OFF:CY_SYSPM_SRAM_PWR_MODE_ON;

    /* Lock PWR MACRO Control(Set SET01) */
    MXSRAMC_PWR_MACRO_CTL_LOCK = MXSRAMC_PWR_MACRO_CTL_LOCK_SET01;

    return value;

}


cy_en_syspm_status_t Cy_SysPm_SetSRAMPwrMode(cy_en_syspm_sram_index_t sramNum, cy_en_syspm_sram_pwr_mode_t sramPwrMode)
{
    CY_ASSERT_L3(sramNum == CY_SYSPM_SRAM0_MEMORY);
    CY_ASSERT_L3((sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_ON) || (sramPwrMode == CY_SYSPM_SRAM_PWR_MODE_OFF));

    CY_UNUSED_PARAM(sramNum);

    (void)Cy_SysPm_SetSRAMMacroPwrMode(CY_SYSPM_SRAM0_MEMORY, (uint32_t)CY_SYSPM_SRAM0_MACRO_0, sramPwrMode);
    (void)Cy_SysPm_SetSRAMMacroPwrMode(CY_SYSPM_SRAM0_MEMORY, (uint32_t)CY_SYSPM_SRAM0_MACRO_1, sramPwrMode);

    return CY_SYSPM_SUCCESS;
}

void Cy_SysPm_TriggerSoftReset(void)
{
    SRSS_RES_SOFT_CTL = SRSS_RES_SOFT_CTL_TRIGGER_SOFT_Msk;
}

bool Cy_SysPm_IsSystemLp(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_SYSTEM_LP) != 0U);
}

bool Cy_SysPm_IsSystemUlp(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_SYSTEM_ULP) != 0U);
}

bool Cy_SysPm_IsSystemMf(void)
{
    return((Cy_SysPm_ReadStatus() & CY_SYSPM_STATUS_SYSTEM_MF) != 0U);
}

static cy_en_syspm_status_t Cy_SysPm_SystemEnterLpToMf(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* LP to MF Sequence */

    /* 1) M33 send IPC to m0seccpuss - Operating mode change target */
    //TBD

    /* 2) Retention Level change */
    //TBD

    /* 3) Reduce the frequency so it is at least ??% (400MHz to <=??MHz) below the static timing closure limits at the new voltage setting for SRAM timing margin */
    //TBD

    /* 4) SRAM trim updates - LP->MF(2) through LP->MF(5) */
    //TBD

    /* 5) Change the voltage */
    //TBD

    /* 6) SRAM trim updates - LP->MF(7) */
    //TBD

    /* 7) M33 send IPC to m0seccpuss - Voltage at target level */
    //TBD

    /* 8) Change RRAM to MF mode  */
    //TBD

    /* 9) Change Frequency  */
    //TBD

    /* 10) M33 sends IPC to m0seccpuss - Frequency at target level */
    //TBD

    return retVal;
}

static cy_en_syspm_status_t Cy_SysPm_SystemEnterMfToLp(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* MF to LP Sequence */

    /* 1) M33 send IPC to m0seccpuss - Operating mode change target */
    //TBD

    /* 2) Retention Level change */
    //TBD

    /* 3) Reduce frequency by at least ??% (120MHz to <=??MHz) for SRAM timing margin */
    //TBD

    /* 4) SRAM trim updates - MF->LP(2) through MF->LP(5) */
    //TBD

    /* 5) Change the voltage */
    //TBD

    /* 6) SRAM trim updates - MF->LP(7) & MF->LP(8) */
    //TBD

    /* 7) M33 send IPC to m0seccpuss - Voltage at target level */
    //TBD

    /* 8) Change RRAM to LP mode  */
    //TBD

    /* 9) Change Frequency  */
    //TBD

    /* 10) M33 sends IPC to m0seccpuss - Frequency at target level */
    //TBD

    return retVal;
}

static cy_en_syspm_status_t Cy_SysPm_SystemEnterUlpToMf(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* ULP to MF Sequence */

    /* 1) M33 send IPC to m0seccpuss - Operating mode change target */
    //TBD

    /* 2) Retention Level change */
    //TBD

    /* 3) Reduce frequency by at least 12% (50MHz to <=44MHz) for SRAM timing margin */
    //TBD

    /* 4) SRAM trim updates - ULP->MF(3) through ULP->MF(5) */
    //TBD

    /* 5) Change the voltage */
    //TBD

    /* 6) SRAM trim updates - ULP->MF(7) */
    //TBD

    /* 7) M33 send IPC to m0seccpuss - Voltage at target level */
    //TBD

    /* 8) Change RRAM to MF mode  */
    //TBD

    /* 9) Change Frequency  */
    //TBD

    /* 10) M33 sends IPC to m0seccpuss - Frequency at target level */
    //TBD

    return retVal;
}

static cy_en_syspm_status_t Cy_SysPm_SystemEnterMfToUlp(void)
{
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* MF to ULP Sequence */

    /* 1) M33 send IPC to m0seccpuss - Operating mode change target */
    //TBD

    /* 2) Retention Level change */
    //TBD

    /* 3) Reduce the operating frequency so it is at least 12% (50MHz to 44MHz) below the static timing closure limits at the new voltage setting for SRAM timing margin. */
    //TBD

    /* 4) SRAM trim updates - MF->ULP(2) through MF->ULP(3) */
    //TBD

    /* 5) Change the voltage */
    //TBD

    /* 6) SRAM trim updates - ULP->MF(7) */
    //TBD

    /* 7) M33 send IPC to m0seccpuss - Voltage at target level */
    //TBD

    /* 8) Change RRAM to ULP mode  */
    //TBD

    /* 9) Change Frequency  */
    //TBD

    /* 10) M33 sends IPC to m0seccpuss - Frequency at target level */
    //TBD

    return retVal;
}

cy_en_syspm_status_t Cy_SysPm_SystemEnterLp(void)
{
    uint32_t interruptState;
    uint32_t cbLpRootIdx = (uint32_t) CY_SYSPM_LP;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbLpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into LP only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {

        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbLpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_BEFORE_TRANSITION);
        }

        if(Cy_SysPm_IsSystemMf())
        {
            Cy_SysPm_SystemEnterMfToLp();
        }
        else if(Cy_SysPm_IsSystemUlp())
        {
            Cy_SysPm_SystemEnterUlpToMf();
            Cy_SysPm_SystemEnterMfToLp();
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbLpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_LP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}


cy_en_syspm_status_t Cy_SysPm_SystemEnterUlp(void)
{
    uint32_t interruptState;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    uint32_t cbUlpRootIdx = (uint32_t) CY_SYSPM_ULP;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbUlpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into the ULP only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_BEFORE_TRANSITION);
        }

        if(Cy_SysPm_IsSystemMf())
        {
            Cy_SysPm_SystemEnterMfToUlp();
        }
        else if(Cy_SysPm_IsSystemLp())
        {
            Cy_SysPm_SystemEnterLpToMf();
            Cy_SysPm_SystemEnterMfToUlp();
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_ULP, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}


cy_en_syspm_status_t Cy_SysPm_SystemEnterMf(void)
{
    uint32_t interruptState;
    cy_en_syspm_status_t retVal = CY_SYSPM_SUCCESS;
    uint32_t cbUlpRootIdx = (uint32_t) CY_SYSPM_MF;

    /* Call the registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter
    */
    if (pmCallbackRoot[cbUlpRootIdx] != NULL)
    {
        retVal = Cy_SysPm_ExecuteCallback(CY_SYSPM_MF, CY_SYSPM_CHECK_READY);
    }

    /* The system can switch into the ULP only when
    * all executed registered callback functions with the
    * CY_SYSPM_CHECK_READY parameter return CY_SYSPM_SUCCESS
    */
    if (retVal == CY_SYSPM_SUCCESS)
    {
        /* Call the registered callback functions with the
        * CY_SYSPM_BEFORE_TRANSITION parameter
        */
        interruptState = Cy_SysLib_EnterCriticalSection();
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_MF, CY_SYSPM_BEFORE_TRANSITION);
        }

        if(Cy_SysPm_IsSystemLp())
        {
            Cy_SysPm_SystemEnterLpToMf();
        }
        else if(Cy_SysPm_IsSystemUlp())
        {
            Cy_SysPm_SystemEnterUlpToMf();
        }

        Cy_SysLib_ExitCriticalSection(interruptState);

        /* Call the registered callback functions with the
        * CY_SYSPM_AFTER_TRANSITION parameter
        */
        if (pmCallbackRoot[cbUlpRootIdx] != NULL)
        {
            (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_MF, CY_SYSPM_AFTER_TRANSITION);
        }
    }
    else
    {
        /* Execute callback functions with the CY_SYSPM_CHECK_FAIL parameter to
        * undo everything done in the callback with the CY_SYSPM_CHECK_READY
        * parameter
        */
        (void) Cy_SysPm_ExecuteCallback(CY_SYSPM_MF, CY_SYSPM_CHECK_FAIL);
        retVal = CY_SYSPM_FAIL;
    }

    return retVal;
}


uint32_t Cy_SysPm_ReadStatus(void)
{
    uint32_t pmStatus = 0UL;

    /* Check whether the device is in ULP/MFLP mode by reading
    *  the core buck profile:
    *  - 0.7V (nominal) - System ULP mode
    *  - 0.8V (nominal) - System MF mode
    *  - 0.9V (nominal) - System LP mode
    */

    /* Read current active regulator */
    /* Current active regulator is LDO */
    if (Cy_SysPm_CoreBuckGetProfile() == CY_SYSPM_CORE_BUCK_PROFILE_LP)
    {
        pmStatus |= CY_SYSPM_STATUS_SYSTEM_LP;
    }
    else if (Cy_SysPm_CoreBuckGetProfile() == CY_SYSPM_CORE_BUCK_PROFILE_ULP)
    {
        pmStatus |= CY_SYSPM_STATUS_SYSTEM_ULP;
    }
    else
    {
        pmStatus |= CY_SYSPM_STATUS_SYSTEM_MF;
    }

    return pmStatus;
}


#endif /* CY_IP_MXS22SRSS */
/* [] END OF FILE */
