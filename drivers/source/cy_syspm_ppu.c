/***************************************************************************//**
* \file cy_syspm_ppu.c
* \version 5.120
*
* This file provides the source code for ARM PPU Platform PD specific driver,
* where the API's are used by Syspm driver for Power Management.
*
*
********************************************************************************
* \copyright
* Copyright 2016-2020 Cypress Semiconductor Corporation
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

#if defined (CY_IP_MXS28SRSS) || defined (CY_IP_MXS40SSRSS) || defined (CY_IP_MXS22SRSS)

#include <stdbool.h>
#include <ppu_v1.h>
#include <cy_syspm_ppu.h>
#include "cy_syslib.h"
#include "cy_syspm.h"
#if defined (CY_IP_MXS22SRSS) && !defined (COMPONENT_SECURE_DEVICE)
#include "cy_secure_services.h"
#endif
/**
* \addtogroup group_syspm_ppu_functions
* \{
*/

/*******************************************************************************
* Function Name: cy_pd_ppu_init
****************************************************************************//**
*
* Initializes the PD PPU Driver.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has 
*  to be done.
*
*  \return the PD PPU API status \ref cy_en_syspm_status_t.
*
*******************************************************************************/
cy_en_syspm_status_t cy_pd_ppu_init(struct ppu_v1_reg *ppu)
{
    CY_ASSERT(ppu != NULL);

    ppu_v1_init(ppu);

    return CY_SYSPM_SUCCESS;
}

/*******************************************************************************
* Function Name: cy_pd_ppu_get_programmed_power_mode
****************************************************************************//**
*
* Gets the programmed power mode of the particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has 
*  to be done.
*
*  \return Returns the PPU Programmed Power mode
*
*******************************************************************************/

enum ppu_v1_mode cy_pd_ppu_get_programmed_power_mode(struct ppu_v1_reg *ppu)
{
    CY_ASSERT(ppu != NULL);
#if defined(NO_RPC_CALL) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    return ppu_v1_get_programmed_power_mode(ppu);
#else
    cy_rpc_args_t rpcArgs;
    rpcArgs.argc = 1;
    rpcArgs.argv[0] = (uint32_t)ppu;
    return (enum ppu_v1_mode)Cy_Send_RPC(CY_SECURE_SERVICE_TYPE_PM,
                  (uint32_t)CY_SECURE_SERVICE_PM_GET_PROGRAMMED_POWER_MODE, &rpcArgs);
#endif
}


/*******************************************************************************
* Function Name: cy_pd_ppu_get_power_mode
****************************************************************************//**
*
* Gets the current power mode of the particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has 
*  to be done.
*
*  \return Returns the PPU Current Power mode
*
*******************************************************************************/

enum ppu_v1_mode cy_pd_ppu_get_power_mode(struct ppu_v1_reg *ppu)
{
    CY_ASSERT(ppu != NULL);
#if defined(NO_RPC_CALL) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    return ppu_v1_get_power_mode(ppu);
#else
    cy_rpc_args_t rpcArgs;
    rpcArgs.argc = 1;
    rpcArgs.argv[0] = (uint32_t)ppu;
    return (enum ppu_v1_mode)Cy_Send_RPC(CY_SECURE_SERVICE_TYPE_PM,
                  (uint32_t)CY_SECURE_SERVICE_PM_GET_POWER_MODE, &rpcArgs);
#endif
}

/*******************************************************************************
* Function Name: cy_pd_ppu_set_power_mode
****************************************************************************//**
*
* Sets the required power mode of the particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has 
*  to be done.
*
*  \param mode
*  Contains the future power mode to be set for the PPU.
*
*  \return the PD PPU API status \ref cy_en_syspm_status_t.
*
*******************************************************************************/

cy_en_syspm_status_t cy_pd_ppu_set_power_mode(struct ppu_v1_reg *ppu, uint32_t mode)
{
#if defined(NO_RPC_CALL) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    cy_en_syspm_status_t status = CY_SYSPM_INVALID_STATE;
    CY_ASSERT(ppu != NULL);
    CY_ASSERT(mode < PPU_V1_MODE_COUNT);

    (void)ppu_v1_dynamic_enable(ppu, (enum ppu_v1_mode) mode); /* Suppress a compiler warning about unused return value */

    return status;
#else
    cy_rpc_args_t rpcArgs;
    rpcArgs.argc = 2;
    rpcArgs.argv[0] = (uint32_t)ppu;
    rpcArgs.argv[1] = mode;
    return (cy_en_syspm_status_t)Cy_Send_RPC(CY_SECURE_SERVICE_TYPE_PM,
              (uint32_t)CY_SECURE_SERVICE_PM_SET_POWER_MODE, &rpcArgs);
#endif
}

/*******************************************************************************
* Function Name: cy_pd_ppu_enable_dynamic_mode
****************************************************************************//**
*
* Enables/Disable Dynamic Mode of particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \param enable
*  true  - Enables the Dynamic mode for the PD.
*  false - Disables the Dynamic mode for the PD.
*
*******************************************************************************/

void cy_pd_ppu_enable_dynamic_mode(struct ppu_v1_reg *ppu, bool enable)
{
    CY_ASSERT(ppu != NULL);

    if(enable)
    {
        ppu->PWPR |= PPU_V1_PWPR_DYNAMIC_EN;
    }
    else
    {
        ppu->PWPR &= ~(PPU_V1_PWPR_DYNAMIC_EN);
    }
}

/*******************************************************************************
* Function Name: cy_pd_ppu_set_static_power_mode
****************************************************************************//**
*
* Sets the required static power mode of the particular PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \param mode
*  Contains the future power mode to be set for the PPU.
*
*  \return the PD PPU API status \ref cy_en_syspm_status_t.
*
*******************************************************************************/

cy_en_syspm_status_t cy_pd_ppu_set_static_power_mode(struct ppu_v1_reg *ppu, uint32_t mode)
{
#if defined(NO_RPC_CALL) || !defined (CY_IP_MXS22SRSS) || (defined (COMPONENT_SECURE_DEVICE) && defined (CY_IP_MXS22SRSS))
    cy_en_syspm_status_t status = CY_SYSPM_INVALID_STATE;
    CY_ASSERT(ppu != NULL);
    CY_ASSERT(mode < PPU_V1_MODE_COUNT);

    (void)ppu_v1_set_power_mode(ppu, (enum ppu_v1_mode) mode); /* Suppress a compiler warning about unused return value */

    return status;
#else
    cy_rpc_args_t rpcArgs;
    rpcArgs.argc = 2;
    rpcArgs.argv[0] = (uint32_t)ppu;
    rpcArgs.argv[1] = mode;
    return (cy_en_syspm_status_t)Cy_Send_RPC(CY_SECURE_SERVICE_TYPE_PM,
              (uint32_t)CY_SECURE_SERVICE_PM_SET_STATIC_POWER_MODE, &rpcArgs);
#endif
}



/*******************************************************************************
* Function Name: cy_pd_ppu_reset
****************************************************************************//**
*
* Resets the PD using PPU.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has 
*  to be done.
*
*  \return the PD PPU API status \ref cy_en_syspm_status_t.
*
*******************************************************************************/

cy_en_syspm_status_t cy_pd_ppu_reset(struct ppu_v1_reg *ppu)
{
    cy_en_syspm_status_t status;
    CY_ASSERT(ppu != NULL);

    status = cy_pd_ppu_set_power_mode(ppu, (uint32_t)PPU_V1_MODE_OFF);
    if (status == CY_SYSPM_SUCCESS)
    {
        status = cy_pd_ppu_set_power_mode(ppu, (uint32_t)PPU_V1_MODE_ON);
    }

    return status;
}

/*******************************************************************************
* Function Name: cy_pd_ppu_get_ds_fail_device
****************************************************************************//**
*
* Gets the PPU's device ID(s) which caused the Deepsleep Failure.
*
*  \param ppu
*  This parameter contains PPU base pointer for which the initialization has
*  to be done.
*
*  \return Returns the PPU's device ID which caused the Deepsleep Failure
*
*******************************************************************************/
cy_pd_ppu_device_status_t cy_pd_ppu_get_ds_fail_device(struct ppu_v1_reg *ppu)
{
    CY_ASSERT(ppu != NULL);
    return (cy_pd_ppu_device_status_t)ppu_v1_get_failure_device_id(ppu);
}

/** \} group_syspm_ppu_functions */

#endif /* CY_IP_MXS28SRSS,CY_IP_MXS40SSRSS */
