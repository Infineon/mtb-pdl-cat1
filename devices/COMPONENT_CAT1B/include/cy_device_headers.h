/***************************************************************************//**
* \file cy_device_headers.h
*
* \brief
* Common header file to be included by the drivers.
*
********************************************************************************
* \copyright
* (c) (2016-2023), Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.
*
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

#ifndef _CY_DEVICE_HEADERS_H_
#define _CY_DEVICE_HEADERS_H_

#if defined (COMPONENT_SECURE_DEVICE)

#if defined (BOY2_PSVP)
    #include "boy2_psvp_s.h"
#elif defined (BOY2_LQFP_80)
    #include "boy2_lqfp_80_s.h"
#elif defined (BOY2_LQFP_64)
    #include "boy2_lqfp_64_s.h"
#elif defined (BOY2_VQFN_64)
    #include "boy2_vqfn_64_s.h"
#elif defined (BOY2_VQFN_48)
    #include "boy2_vqfn_48_s.h"
#elif defined (BOY2_LQFP_48)
    #include "boy2_lqfp_48_s.h"
#else
    #error Undefined part number
#endif

#else
#if defined (CYW89829A0KML)
    #include "cyw89829a0kml.h"
#elif defined (CYW20829B0LKML)
    #include "cyw20829b0lkml.h"
#elif defined (CYW20829B0KML)
    #include "cyw20829b0kml.h"
#elif defined (CYW89829B0KML)
    #include "cyw89829b0kml.h"
#elif defined (CYW89829B01MKSBG)
    #include "cyw89829b01mksbg.h"
#elif defined (BOY2_PSVP)
    #include "boy2_psvp.h"
#elif defined (BOY2_LQFP_80)
    #include "boy2_lqfp_80.h"
#elif defined (BOY2_LQFP_64)
    #include "boy2_lqfp_64.h"
#elif defined (BOY2_VQFN_64)
    #include "boy2_vqfn_64.h"
#elif defined (BOY2_VQFN_48)
    #include "boy2_vqfn_48.h"
#elif defined (BOY2_LQFP_48)
    #include "boy2_lqfp_48.h"
#else
    #error Undefined part number
#endif

#endif

#endif /* _CY_DEVICE_HEADERS_H_ */


/* [] END OF FILE */
