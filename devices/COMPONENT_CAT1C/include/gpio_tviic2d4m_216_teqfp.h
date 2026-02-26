/***************************************************************************//**
* TVIIC2D4M device GPIO header for 216-TEQFP package
*
********************************************************************************
* \copyright
* (c) 2016-2026, Infineon Technologies AG or an affiliate of
* Infineon Technologies AG.
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

#ifndef _GPIO_TVIIC2D4M_216_TEQFP_H_
#define _GPIO_TVIIC2D4M_216_TEQFP_H_

/* Package type */
enum
{
    CY_GPIO_PACKAGE_QFN,
    CY_GPIO_PACKAGE_BGA,
    CY_GPIO_PACKAGE_CSP,
    CY_GPIO_PACKAGE_WLCSP,
    CY_GPIO_PACKAGE_LQFP,
    CY_GPIO_PACKAGE_TQFP,
    CY_GPIO_PACKAGE_TEQFP,
    CY_GPIO_PACKAGE_SMT,
    CY_GPIO_PACKAGE_LGA,
};

#define CY_GPIO_PACKAGE_TYPE            CY_GPIO_PACKAGE_TEQFP
#define CY_GPIO_PIN_COUNT               216u

/* AMUXBUS Segments */
enum
{
    AMUXBUS_ECT,
    AMUXBUS_EFUSE,
    AMUXBUS_FPDLINK0,
    AMUXBUS_MAIN,
    AMUXBUS_MIPI,
    AMUXBUS_TEST,
    AMUXBUS_TESTSRSS,
};

/* AMUX Splitter Controls */
typedef enum
{
    AMUX_SPLIT_CTL_0                = 0x0000u,  /* Left = AMUXBUS_TEST; Right = AMUXBUS_TESTSRSS */
    AMUX_SPLIT_CTL_1                = 0x0001u,  /* Left = AMUXBUS_ECT; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_2                = 0x0002u,  /* Left = AMUXBUS_MIPI; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_3                = 0x0003u,  /* Left = AMUXBUS_FPDLINK0; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_4                = 0x0004u,  /* Left = AMUXBUS_MAIN; Right = AMUXBUS_TEST */
    AMUX_SPLIT_CTL_5                = 0x0005u   /* Left = AMUXBUS_MAIN; Right = AMUXBUS_EFUSE */
} cy_en_amux_split_t;

/* Port List */
/* PORT 0 (GPIO) */
#define P0_0_PORT                       GPIO_PRT0
#define P0_0_PIN                        0u
#define P0_0_NUM                        0u
#define P0_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_1_PORT                       GPIO_PRT0
#define P0_1_PIN                        1u
#define P0_1_NUM                        1u
#define P0_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_2_PORT                       GPIO_PRT0
#define P0_2_PIN                        2u
#define P0_2_NUM                        2u
#define P0_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P0_3_PORT                       GPIO_PRT0
#define P0_3_PIN                        3u
#define P0_3_NUM                        3u
#define P0_3_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 1 (GPIO) */
#define P1_4_PORT                       GPIO_PRT1
#define P1_4_PIN                        4u
#define P1_4_NUM                        4u
#define P1_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_5_PORT                       GPIO_PRT1
#define P1_5_PIN                        5u
#define P1_5_NUM                        5u
#define P1_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_6_PORT                       GPIO_PRT1
#define P1_6_PIN                        6u
#define P1_6_NUM                        6u
#define P1_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P1_7_PORT                       GPIO_PRT1
#define P1_7_PIN                        7u
#define P1_7_NUM                        7u
#define P1_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 2 (GPIO) */
#define P2_1_PORT                       GPIO_PRT2
#define P2_1_PIN                        1u
#define P2_1_NUM                        1u
#define P2_1_AMUXSEGMENT                AMUXBUS_TEST
#define P2_2_PORT                       GPIO_PRT2
#define P2_2_PIN                        2u
#define P2_2_NUM                        2u
#define P2_2_AMUXSEGMENT                AMUXBUS_TEST
#define P2_4_PORT                       GPIO_PRT2
#define P2_4_PIN                        4u
#define P2_4_NUM                        4u
#define P2_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P2_5_PORT                       GPIO_PRT2
#define P2_5_PIN                        5u
#define P2_5_NUM                        5u
#define P2_5_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 3 (GPIO) */
#define P3_0_PORT                       GPIO_PRT3
#define P3_0_PIN                        0u
#define P3_0_NUM                        0u
#define P3_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P3_1_PORT                       GPIO_PRT3
#define P3_1_PIN                        1u
#define P3_1_NUM                        1u
#define P3_1_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 4 (GPIO) */
#define P4_4_PORT                       GPIO_PRT4
#define P4_4_PIN                        4u
#define P4_4_NUM                        4u
#define P4_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_5_PORT                       GPIO_PRT4
#define P4_5_PIN                        5u
#define P4_5_NUM                        5u
#define P4_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_6_PORT                       GPIO_PRT4
#define P4_6_PIN                        6u
#define P4_6_NUM                        6u
#define P4_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P4_7_PORT                       GPIO_PRT4
#define P4_7_PIN                        7u
#define P4_7_NUM                        7u
#define P4_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 5 (GPIO) */
#define P5_0_PORT                       GPIO_PRT5
#define P5_0_PIN                        0u
#define P5_0_NUM                        0u
#define P5_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_1_PORT                       GPIO_PRT5
#define P5_1_PIN                        1u
#define P5_1_NUM                        1u
#define P5_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_2_PORT                       GPIO_PRT5
#define P5_2_PIN                        2u
#define P5_2_NUM                        2u
#define P5_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_3_PORT                       GPIO_PRT5
#define P5_3_PIN                        3u
#define P5_3_NUM                        3u
#define P5_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_4_PORT                       GPIO_PRT5
#define P5_4_PIN                        4u
#define P5_4_NUM                        4u
#define P5_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P5_5_PORT                       GPIO_PRT5
#define P5_5_PIN                        5u
#define P5_5_NUM                        5u
#define P5_5_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 6 (GPIO) */
#define P6_0_PORT                       GPIO_PRT6
#define P6_0_PIN                        0u
#define P6_0_NUM                        0u
#define P6_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_1_PORT                       GPIO_PRT6
#define P6_1_PIN                        1u
#define P6_1_NUM                        1u
#define P6_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_2_PORT                       GPIO_PRT6
#define P6_2_PIN                        2u
#define P6_2_NUM                        2u
#define P6_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P6_3_PORT                       GPIO_PRT6
#define P6_3_PIN                        3u
#define P6_3_NUM                        3u
#define P6_3_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 7 (GPIO) */
#define P7_0_PORT                       GPIO_PRT7
#define P7_0_PIN                        0u
#define P7_0_NUM                        0u
#define P7_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_1_PORT                       GPIO_PRT7
#define P7_1_PIN                        1u
#define P7_1_NUM                        1u
#define P7_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_2_PORT                       GPIO_PRT7
#define P7_2_PIN                        2u
#define P7_2_NUM                        2u
#define P7_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_3_PORT                       GPIO_PRT7
#define P7_3_PIN                        3u
#define P7_3_NUM                        3u
#define P7_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_4_PORT                       GPIO_PRT7
#define P7_4_PIN                        4u
#define P7_4_NUM                        4u
#define P7_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_5_PORT                       GPIO_PRT7
#define P7_5_PIN                        5u
#define P7_5_NUM                        5u
#define P7_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_6_PORT                       GPIO_PRT7
#define P7_6_PIN                        6u
#define P7_6_NUM                        6u
#define P7_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P7_7_PORT                       GPIO_PRT7
#define P7_7_PIN                        7u
#define P7_7_NUM                        7u
#define P7_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 8 (GPIO) */
#define P8_0_PORT                       GPIO_PRT8
#define P8_0_PIN                        0u
#define P8_0_NUM                        0u
#define P8_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_1_PORT                       GPIO_PRT8
#define P8_1_PIN                        1u
#define P8_1_NUM                        1u
#define P8_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_2_PORT                       GPIO_PRT8
#define P8_2_PIN                        2u
#define P8_2_NUM                        2u
#define P8_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_3_PORT                       GPIO_PRT8
#define P8_3_PIN                        3u
#define P8_3_NUM                        3u
#define P8_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_4_PORT                       GPIO_PRT8
#define P8_4_PIN                        4u
#define P8_4_NUM                        4u
#define P8_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_5_PORT                       GPIO_PRT8
#define P8_5_PIN                        5u
#define P8_5_NUM                        5u
#define P8_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_6_PORT                       GPIO_PRT8
#define P8_6_PIN                        6u
#define P8_6_NUM                        6u
#define P8_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P8_7_PORT                       GPIO_PRT8
#define P8_7_PIN                        7u
#define P8_7_NUM                        7u
#define P8_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 9 (GPIO) */
#define P9_0_PORT                       GPIO_PRT9
#define P9_0_PIN                        0u
#define P9_0_NUM                        0u
#define P9_0_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_1_PORT                       GPIO_PRT9
#define P9_1_PIN                        1u
#define P9_1_NUM                        1u
#define P9_1_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_2_PORT                       GPIO_PRT9
#define P9_2_PIN                        2u
#define P9_2_NUM                        2u
#define P9_2_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_3_PORT                       GPIO_PRT9
#define P9_3_PIN                        3u
#define P9_3_NUM                        3u
#define P9_3_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_4_PORT                       GPIO_PRT9
#define P9_4_PIN                        4u
#define P9_4_NUM                        4u
#define P9_4_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_5_PORT                       GPIO_PRT9
#define P9_5_PIN                        5u
#define P9_5_NUM                        5u
#define P9_5_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_6_PORT                       GPIO_PRT9
#define P9_6_PIN                        6u
#define P9_6_NUM                        6u
#define P9_6_AMUXSEGMENT                AMUXBUS_MAIN
#define P9_7_PORT                       GPIO_PRT9
#define P9_7_PIN                        7u
#define P9_7_NUM                        7u
#define P9_7_AMUXSEGMENT                AMUXBUS_MAIN

/* PORT 11 (GPIO) */
#define P11_0_PORT                      GPIO_PRT11
#define P11_0_PIN                       0u
#define P11_0_NUM                       0u
#define P11_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_1_PORT                      GPIO_PRT11
#define P11_1_PIN                       1u
#define P11_1_NUM                       1u
#define P11_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_2_PORT                      GPIO_PRT11
#define P11_2_PIN                       2u
#define P11_2_NUM                       2u
#define P11_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_3_PORT                      GPIO_PRT11
#define P11_3_PIN                       3u
#define P11_3_NUM                       3u
#define P11_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_4_PORT                      GPIO_PRT11
#define P11_4_PIN                       4u
#define P11_4_NUM                       4u
#define P11_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_5_PORT                      GPIO_PRT11
#define P11_5_PIN                       5u
#define P11_5_NUM                       5u
#define P11_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_6_PORT                      GPIO_PRT11
#define P11_6_PIN                       6u
#define P11_6_NUM                       6u
#define P11_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P11_7_PORT                      GPIO_PRT11
#define P11_7_PIN                       7u
#define P11_7_NUM                       7u
#define P11_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 12 (GPIO) */
#define P12_0_PORT                      GPIO_PRT12
#define P12_0_PIN                       0u
#define P12_0_NUM                       0u
#define P12_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P12_1_PORT                      GPIO_PRT12
#define P12_1_PIN                       1u
#define P12_1_NUM                       1u
#define P12_1_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 14 (GPIO) */
#define P14_2_PORT                      GPIO_PRT14
#define P14_2_PIN                       2u
#define P14_2_NUM                       2u
#define P14_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_3_PORT                      GPIO_PRT14
#define P14_3_PIN                       3u
#define P14_3_NUM                       3u
#define P14_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_4_PORT                      GPIO_PRT14
#define P14_4_PIN                       4u
#define P14_4_NUM                       4u
#define P14_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_5_PORT                      GPIO_PRT14
#define P14_5_PIN                       5u
#define P14_5_NUM                       5u
#define P14_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_6_PORT                      GPIO_PRT14
#define P14_6_PIN                       6u
#define P14_6_NUM                       6u
#define P14_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P14_7_PORT                      GPIO_PRT14
#define P14_7_PIN                       7u
#define P14_7_NUM                       7u
#define P14_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 15 (GPIO) */
#define P15_0_PORT                      GPIO_PRT15
#define P15_0_PIN                       0u
#define P15_0_NUM                       0u
#define P15_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_1_PORT                      GPIO_PRT15
#define P15_1_PIN                       1u
#define P15_1_NUM                       1u
#define P15_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_2_PORT                      GPIO_PRT15
#define P15_2_PIN                       2u
#define P15_2_NUM                       2u
#define P15_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_3_PORT                      GPIO_PRT15
#define P15_3_PIN                       3u
#define P15_3_NUM                       3u
#define P15_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_4_PORT                      GPIO_PRT15
#define P15_4_PIN                       4u
#define P15_4_NUM                       4u
#define P15_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_5_PORT                      GPIO_PRT15
#define P15_5_PIN                       5u
#define P15_5_NUM                       5u
#define P15_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_6_PORT                      GPIO_PRT15
#define P15_6_PIN                       6u
#define P15_6_NUM                       6u
#define P15_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P15_7_PORT                      GPIO_PRT15
#define P15_7_PIN                       7u
#define P15_7_NUM                       7u
#define P15_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 16 (GPIO) */
#define P16_0_PORT                      GPIO_PRT16
#define P16_0_PIN                       0u
#define P16_0_NUM                       0u
#define P16_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_1_PORT                      GPIO_PRT16
#define P16_1_PIN                       1u
#define P16_1_NUM                       1u
#define P16_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_2_PORT                      GPIO_PRT16
#define P16_2_PIN                       2u
#define P16_2_NUM                       2u
#define P16_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_3_PORT                      GPIO_PRT16
#define P16_3_PIN                       3u
#define P16_3_NUM                       3u
#define P16_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_4_PORT                      GPIO_PRT16
#define P16_4_PIN                       4u
#define P16_4_NUM                       4u
#define P16_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_5_PORT                      GPIO_PRT16
#define P16_5_PIN                       5u
#define P16_5_NUM                       5u
#define P16_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P16_6_PORT                      GPIO_PRT16
#define P16_6_PIN                       6u
#define P16_6_NUM                       6u
#define P16_6_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 18 (GPIO) */
#define P18_0_PORT                      GPIO_PRT18
#define P18_0_PIN                       0u
#define P18_0_NUM                       0u
#define P18_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_1_PORT                      GPIO_PRT18
#define P18_1_PIN                       1u
#define P18_1_NUM                       1u
#define P18_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_2_PORT                      GPIO_PRT18
#define P18_2_PIN                       2u
#define P18_2_NUM                       2u
#define P18_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_3_PORT                      GPIO_PRT18
#define P18_3_PIN                       3u
#define P18_3_NUM                       3u
#define P18_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_4_PORT                      GPIO_PRT18
#define P18_4_PIN                       4u
#define P18_4_NUM                       4u
#define P18_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_5_PORT                      GPIO_PRT18
#define P18_5_PIN                       5u
#define P18_5_NUM                       5u
#define P18_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_6_PORT                      GPIO_PRT18
#define P18_6_PIN                       6u
#define P18_6_NUM                       6u
#define P18_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P18_7_PORT                      GPIO_PRT18
#define P18_7_PIN                       7u
#define P18_7_NUM                       7u
#define P18_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 19 (GPIO) */
#define P19_0_PORT                      GPIO_PRT19
#define P19_0_PIN                       0u
#define P19_0_NUM                       0u
#define P19_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_1_PORT                      GPIO_PRT19
#define P19_1_PIN                       1u
#define P19_1_NUM                       1u
#define P19_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_2_PORT                      GPIO_PRT19
#define P19_2_PIN                       2u
#define P19_2_NUM                       2u
#define P19_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P19_3_PORT                      GPIO_PRT19
#define P19_3_PIN                       3u
#define P19_3_NUM                       3u
#define P19_3_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 20 (GPIO) */
#define P20_0_PORT                      GPIO_PRT20
#define P20_0_PIN                       0u
#define P20_0_NUM                       0u
#define P20_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P20_1_PORT                      GPIO_PRT20
#define P20_1_PIN                       1u
#define P20_1_NUM                       1u
#define P20_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P20_2_PORT                      GPIO_PRT20
#define P20_2_PIN                       2u
#define P20_2_NUM                       2u
#define P20_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P20_3_PORT                      GPIO_PRT20
#define P20_3_PIN                       3u
#define P20_3_NUM                       3u
#define P20_3_AMUXSEGMENT               AMUXBUS_MAIN
#define P20_4_PORT                      GPIO_PRT20
#define P20_4_PIN                       4u
#define P20_4_NUM                       4u
#define P20_4_AMUXSEGMENT               AMUXBUS_MAIN
#define P20_5_PORT                      GPIO_PRT20
#define P20_5_PIN                       5u
#define P20_5_NUM                       5u
#define P20_5_AMUXSEGMENT               AMUXBUS_MAIN
#define P20_6_PORT                      GPIO_PRT20
#define P20_6_PIN                       6u
#define P20_6_NUM                       6u
#define P20_6_AMUXSEGMENT               AMUXBUS_MAIN
#define P20_7_PORT                      GPIO_PRT20
#define P20_7_PIN                       7u
#define P20_7_NUM                       7u
#define P20_7_AMUXSEGMENT               AMUXBUS_MAIN

/* PORT 21 (GPIO) */
#define P21_0_PORT                      GPIO_PRT21
#define P21_0_PIN                       0u
#define P21_0_NUM                       0u
#define P21_0_AMUXSEGMENT               AMUXBUS_MAIN
#define P21_1_PORT                      GPIO_PRT21
#define P21_1_PIN                       1u
#define P21_1_NUM                       1u
#define P21_1_AMUXSEGMENT               AMUXBUS_MAIN
#define P21_2_PORT                      GPIO_PRT21
#define P21_2_PIN                       2u
#define P21_2_NUM                       2u
#define P21_2_AMUXSEGMENT               AMUXBUS_MAIN
#define P21_3_PORT                      GPIO_PRT21
#define P21_3_PIN                       3u
#define P21_3_NUM                       3u
#define P21_3_AMUXSEGMENT               AMUXBUS_MAIN

/* Analog Connections */
#define PASS0_I_TEMP_KELVIN_PORT        0u
#define PASS0_I_TEMP_KELVIN_PIN         2u
#define PASS0_SARMUX_PADS1_PORT         1u
#define PASS0_SARMUX_PADS1_PIN          4u
#define PASS0_SARMUX_PADS10_PORT        5u
#define PASS0_SARMUX_PADS10_PIN         0u
#define PASS0_SARMUX_PADS11_PORT        5u
#define PASS0_SARMUX_PADS11_PIN         1u
#define PASS0_SARMUX_PADS12_PORT        5u
#define PASS0_SARMUX_PADS12_PIN         2u
#define PASS0_SARMUX_PADS13_PORT        5u
#define PASS0_SARMUX_PADS13_PIN         3u
#define PASS0_SARMUX_PADS14_PORT        5u
#define PASS0_SARMUX_PADS14_PIN         4u
#define PASS0_SARMUX_PADS15_PORT        5u
#define PASS0_SARMUX_PADS15_PIN         5u
#define PASS0_SARMUX_PADS16_PORT        4u
#define PASS0_SARMUX_PADS16_PIN         4u
#define PASS0_SARMUX_PADS17_PORT        4u
#define PASS0_SARMUX_PADS17_PIN         5u
#define PASS0_SARMUX_PADS18_PORT        4u
#define PASS0_SARMUX_PADS18_PIN         6u
#define PASS0_SARMUX_PADS19_PORT        4u
#define PASS0_SARMUX_PADS19_PIN         7u
#define PASS0_SARMUX_PADS2_PORT         1u
#define PASS0_SARMUX_PADS2_PIN          5u
#define PASS0_SARMUX_PADS20_PORT        6u
#define PASS0_SARMUX_PADS20_PIN         0u
#define PASS0_SARMUX_PADS21_PORT        6u
#define PASS0_SARMUX_PADS21_PIN         1u
#define PASS0_SARMUX_PADS22_PORT        6u
#define PASS0_SARMUX_PADS22_PIN         2u
#define PASS0_SARMUX_PADS23_PORT        6u
#define PASS0_SARMUX_PADS23_PIN         3u
#define PASS0_SARMUX_PADS3_PORT         1u
#define PASS0_SARMUX_PADS3_PIN          6u
#define PASS0_SARMUX_PADS32_PORT        7u
#define PASS0_SARMUX_PADS32_PIN         0u
#define PASS0_SARMUX_PADS33_PORT        7u
#define PASS0_SARMUX_PADS33_PIN         1u
#define PASS0_SARMUX_PADS34_PORT        7u
#define PASS0_SARMUX_PADS34_PIN         2u
#define PASS0_SARMUX_PADS35_PORT        7u
#define PASS0_SARMUX_PADS35_PIN         3u
#define PASS0_SARMUX_PADS36_PORT        7u
#define PASS0_SARMUX_PADS36_PIN         4u
#define PASS0_SARMUX_PADS37_PORT        7u
#define PASS0_SARMUX_PADS37_PIN         5u
#define PASS0_SARMUX_PADS38_PORT        7u
#define PASS0_SARMUX_PADS38_PIN         6u
#define PASS0_SARMUX_PADS39_PORT        7u
#define PASS0_SARMUX_PADS39_PIN         7u
#define PASS0_SARMUX_PADS4_PORT         1u
#define PASS0_SARMUX_PADS4_PIN          7u
#define PASS0_SARMUX_PADS40_PORT        8u
#define PASS0_SARMUX_PADS40_PIN         0u
#define PASS0_SARMUX_PADS41_PORT        8u
#define PASS0_SARMUX_PADS41_PIN         1u
#define PASS0_SARMUX_PADS42_PORT        8u
#define PASS0_SARMUX_PADS42_PIN         2u
#define PASS0_SARMUX_PADS43_PORT        8u
#define PASS0_SARMUX_PADS43_PIN         3u
#define PASS0_SARMUX_PADS44_PORT        8u
#define PASS0_SARMUX_PADS44_PIN         4u
#define PASS0_SARMUX_PADS45_PORT        8u
#define PASS0_SARMUX_PADS45_PIN         5u
#define PASS0_SARMUX_PADS46_PORT        8u
#define PASS0_SARMUX_PADS46_PIN         6u
#define PASS0_SARMUX_PADS47_PORT        8u
#define PASS0_SARMUX_PADS47_PIN         7u
#define PASS0_SARMUX_PADS48_PORT        9u
#define PASS0_SARMUX_PADS48_PIN         0u
#define PASS0_SARMUX_PADS49_PORT        9u
#define PASS0_SARMUX_PADS49_PIN         1u
#define PASS0_SARMUX_PADS50_PORT        9u
#define PASS0_SARMUX_PADS50_PIN         2u
#define PASS0_SARMUX_PADS51_PORT        9u
#define PASS0_SARMUX_PADS51_PIN         3u
#define PASS0_SARMUX_PADS52_PORT        9u
#define PASS0_SARMUX_PADS52_PIN         4u
#define PASS0_SARMUX_PADS53_PORT        9u
#define PASS0_SARMUX_PADS53_PIN         5u
#define PASS0_SARMUX_PADS54_PORT        9u
#define PASS0_SARMUX_PADS54_PIN         6u
#define PASS0_SARMUX_PADS55_PORT        9u
#define PASS0_SARMUX_PADS55_PIN         7u
#define PASS0_SARMUX_PADS6_PORT         2u
#define PASS0_SARMUX_PADS6_PIN          4u
#define PASS0_SARMUX_PADS7_PORT         2u
#define PASS0_SARMUX_PADS7_PIN          5u
#define PASS0_SARMUX_PADS8_PORT         3u
#define PASS0_SARMUX_PADS8_PIN          0u
#define PASS0_SARMUX_PADS9_PORT         3u
#define PASS0_SARMUX_PADS9_PIN          1u
#define PASS0_VB_TEMP_KELVIN_PORT       2u
#define PASS0_VB_TEMP_KELVIN_PIN        2u
#define PASS0_VE_TEMP_KELVIN_PORT       1u
#define PASS0_VE_TEMP_KELVIN_PIN        6u
#define SRSS_ADFT_PIN0_PORT             2u
#define SRSS_ADFT_PIN0_PIN              2u
#define SRSS_ADFT_PIN1_PORT             2u
#define SRSS_ADFT_PIN1_PIN              1u
#define SRSS_ADFT_POR_PAD_HV_PORT       2u
#define SRSS_ADFT_POR_PAD_HV_PIN        1u
#define SRSS_ECO_IN_PORT                0u
#define SRSS_ECO_IN_PIN                 2u
#define SRSS_ECO_OUT_PORT               0u
#define SRSS_ECO_OUT_PIN                3u
#define SRSS_LPECO_IN_PORT              0u
#define SRSS_LPECO_IN_PIN               0u
#define SRSS_LPECO_OUT_PORT             0u
#define SRSS_LPECO_OUT_PIN              1u
#define SRSS_VEXT_REF_REG_PORT          0u
#define SRSS_VEXT_REF_REG_PIN           3u
#define SRSS_WCO_IN_PORT                0u
#define SRSS_WCO_IN_PIN                 0u
#define SRSS_WCO_OUT_PORT               0u
#define SRSS_WCO_OUT_PIN                1u

/* HSIOM Connections */
typedef enum
{
    /* Generic HSIOM connections */
    HSIOM_SEL_GPIO                  =  0,       /* GPIO controls 'out' */
    HSIOM_SEL_GPIO_DSI              =  1,       /* GPIO controls 'out', DSI controls 'output enable' */
    HSIOM_SEL_DSI_DSI               =  2,       /* DSI controls 'out' and 'output enable' */
    HSIOM_SEL_DSI_GPIO              =  3,       /* DSI controls 'out', GPIO controls 'output enable' */
    HSIOM_SEL_AMUXA                 =  4,       /* Analog mux bus A */
    HSIOM_SEL_AMUXB                 =  5,       /* Analog mux bus B */
    HSIOM_SEL_AMUXA_DSI             =  6,       /* Analog mux bus A, DSI control */
    HSIOM_SEL_AMUXB_DSI             =  7,       /* Analog mux bus B, DSI control */
    HSIOM_SEL_ACT_0                 =  8,       /* Active functionality 0 */
    HSIOM_SEL_ACT_1                 =  9,       /* Active functionality 1 */
    HSIOM_SEL_ACT_2                 = 10,       /* Active functionality 2 */
    HSIOM_SEL_ACT_3                 = 11,       /* Active functionality 3 */
    HSIOM_SEL_DS_0                  = 12,       /* DeepSleep functionality 0 */
    HSIOM_SEL_DS_1                  = 13,       /* DeepSleep functionality 1 */
    HSIOM_SEL_DS_2                  = 14,       /* DeepSleep functionality 2 */
    HSIOM_SEL_DS_3                  = 15,       /* DeepSleep functionality 3 */
    HSIOM_SEL_ACT_4                 = 16,       /* Active functionality 4 */
    HSIOM_SEL_ACT_5                 = 17,       /* Active functionality 5 */
    HSIOM_SEL_ACT_6                 = 18,       /* Active functionality 6 */
    HSIOM_SEL_ACT_7                 = 19,       /* Active functionality 7 */
    HSIOM_SEL_ACT_8                 = 20,       /* Active functionality 8 */
    HSIOM_SEL_ACT_9                 = 21,       /* Active functionality 9 */
    HSIOM_SEL_ACT_10                = 22,       /* Active functionality 10 */
    HSIOM_SEL_ACT_11                = 23,       /* Active functionality 11 */
    HSIOM_SEL_ACT_12                = 24,       /* Active functionality 12 */
    HSIOM_SEL_ACT_13                = 25,       /* Active functionality 13 */
    HSIOM_SEL_ACT_14                = 26,       /* Active functionality 14 */
    HSIOM_SEL_ACT_15                = 27,       /* Active functionality 15 */
    HSIOM_SEL_DS_4                  = 28,       /* DeepSleep functionality 4 */
    HSIOM_SEL_DS_5                  = 29,       /* DeepSleep functionality 5 */
    HSIOM_SEL_DS_6                  = 30,       /* DeepSleep functionality 6 */
    HSIOM_SEL_DS_7                  = 31,       /* DeepSleep functionality 7 */

    /* P0.0 */
    P0_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_0_AMUXA                      =  4,       /* Analog mux bus A */
    P0_0_AMUXB                      =  5,       /* Analog mux bus B */

    /* P0.1 */
    P0_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_1_AMUXA                      =  4,       /* Analog mux bus A */
    P0_1_AMUXB                      =  5,       /* Analog mux bus B */

    /* P0.2 */
    P0_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_2_AMUXA                      =  4,       /* Analog mux bus A */
    P0_2_AMUXB                      =  5,       /* Analog mux bus B */
    P0_2_SRSS_EXT_CLK               = 22,       /* Digital Active - srss.ext_clk:0 */
    P0_2_SRSS_DDFT_PIN_IN1          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:1 */

    /* P0.3 */
    P0_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P0_3_AMUXA                      =  4,       /* Analog mux bus A */
    P0_3_AMUXB                      =  5,       /* Analog mux bus B */

    /* P1.4 */
    P1_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_4_AMUXA                      =  4,       /* Analog mux bus A */
    P1_4_AMUXB                      =  5,       /* Analog mux bus B */
    P1_4_TCPWM0_LINE520             =  8,       /* Digital Active - tcpwm[0].line[520]:0 */
    P1_4_TCPWM0_LINE_COMPL519       =  9,       /* Digital Active - tcpwm[0].line_compl[519]:0 */
    P1_4_TCPWM0_TR_ONE_CNT_IN518    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[518]:0 */
    P1_4_PERI_TR_IO_INPUT1          = 21,       /* Digital Active - peri.tr_io_input[1]:0 */
    P1_4_SCB7_SPI_MISO              = 25,       /* Digital Active - scb[7].spi_miso:0 */
    P1_4_SCB7_UART_RTS              = 26,       /* Digital Active - scb[7].uart_rts:0 */
    P1_4_SCB7_I2C_SDA               = 27,       /* Digital Active - scb[7].i2c_sda:0 */

    /* P1.5 */
    P1_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_5_AMUXA                      =  4,       /* Analog mux bus A */
    P1_5_AMUXB                      =  5,       /* Analog mux bus B */
    P1_5_TCPWM0_LINE521             =  8,       /* Digital Active - tcpwm[0].line[521]:0 */
    P1_5_TCPWM0_LINE_COMPL520       =  9,       /* Digital Active - tcpwm[0].line_compl[520]:0 */
    P1_5_TCPWM0_TR_ONE_CNT_IN519    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[519]:0 */
    P1_5_PERI_TR_IO_INPUT2          = 21,       /* Digital Active - peri.tr_io_input[2]:0 */
    P1_5_SCB7_SPI_SELECT0           = 25,       /* Digital Active - scb[7].spi_select0:0 */
    P1_5_SCB7_UART_CTS              = 26,       /* Digital Active - scb[7].uart_cts:0 */
    P1_5_SCB7_I2C_SCL               = 27,       /* Digital Active - scb[7].i2c_scl:0 */

    /* P1.6 */
    P1_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_6_AMUXA                      =  4,       /* Analog mux bus A */
    P1_6_AMUXB                      =  5,       /* Analog mux bus B */
    P1_6_TCPWM0_LINE522             =  8,       /* Digital Active - tcpwm[0].line[522]:0 */
    P1_6_TCPWM0_LINE_COMPL522       =  9,       /* Digital Active - tcpwm[0].line_compl[522]:0 */
    P1_6_TCPWM0_TR_ONE_CNT_IN522    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[522]:0 */
    P1_6_PERI_TR_IO_INPUT3          = 21,       /* Digital Active - peri.tr_io_input[3]:0 */
    P1_6_DAC0_DAC_MCK               = 23,       /* Digital Active - dac[0].dac_mck:0 */
    P1_6_LIN0_LIN_TX0               = 24,       /* Digital Active - lin[0].lin_tx[0]:0 */
    P1_6_CANFD0_TTCAN_TX0           = 25,       /* Digital Active - canfd[0].ttcan_tx[0]:0 */
    P1_6_CXPI0_CXPI_TX0             = 26,       /* Digital Active - cxpi[0].cxpi_tx[0]:0 */

    /* P1.7 */
    P1_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P1_7_AMUXA                      =  4,       /* Analog mux bus A */
    P1_7_AMUXB                      =  5,       /* Analog mux bus B */
    P1_7_TCPWM0_LINE523             =  8,       /* Digital Active - tcpwm[0].line[523]:0 */
    P1_7_TCPWM0_LINE_COMPL523       =  9,       /* Digital Active - tcpwm[0].line_compl[523]:0 */
    P1_7_TCPWM0_TR_ONE_CNT_IN523    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[523]:0 */
    P1_7_PERI_TR_IO_INPUT4          = 21,       /* Digital Active - peri.tr_io_input[4]:0 */
    P1_7_LIN0_LIN_RX0               = 24,       /* Digital Active - lin[0].lin_rx[0]:0 */
    P1_7_CANFD0_TTCAN_RX0           = 25,       /* Digital Active - canfd[0].ttcan_rx[0]:0 */
    P1_7_CXPI0_CXPI_RX0             = 26,       /* Digital Active - cxpi[0].cxpi_rx[0]:0 */
    P1_7_SRSS_DDFT_PIN_IN0          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:1 */

    /* P2.1 */
    P2_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_1_AMUXA                      =  4,       /* Analog mux bus A */
    P2_1_AMUXB                      =  5,       /* Analog mux bus B */
    P2_1_TCPWM0_LINE525             =  8,       /* Digital Active - tcpwm[0].line[525]:0 */
    P2_1_TCPWM0_LINE_COMPL527       =  9,       /* Digital Active - tcpwm[0].line_compl[527]:0 */
    P2_1_TCPWM0_TR_ONE_CNT_IN526    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[526]:0 */
    P2_1_PERI_TR_IO_OUTPUT0         = 21,       /* Digital Active - peri.tr_io_output[0]:0 */
    P2_1_CPUSS_CAL_SUP_NZ           = 23,       /* Digital Active - cpuss.cal_sup_nz:0 */
    P2_1_LIN0_LIN_EN0               = 24,       /* Digital Active - lin[0].lin_en[0]:1 */
    P2_1_CANFD0_TTCAN_RX1           = 25,       /* Digital Active - canfd[0].ttcan_rx[1]:0 */
    P2_1_CXPI0_CXPI_EN0             = 26,       /* Digital Active - cxpi[0].cxpi_en[0]:1 */
    P2_1_CPUSS_FAULT_OUT0           = 27,       /* Digital Active - cpuss.fault_out[0]:0 */
    P2_1_SRSS_CAL_WAVE              = 29,       /* Digital Deep Sleep - srss.cal_wave:0 */
    P2_1_SRSS_DDFT_PIN_IN1          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[1]:0 */

    /* P2.2 */
    P2_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_2_AMUXA                      =  4,       /* Analog mux bus A */
    P2_2_AMUXB                      =  5,       /* Analog mux bus B */
    P2_2_TCPWM0_LINE526             =  8,       /* Digital Active - tcpwm[0].line[526]:0 */
    P2_2_TCPWM0_LINE_COMPL525       =  9,       /* Digital Active - tcpwm[0].line_compl[525]:0 */
    P2_2_TCPWM0_TR_ONE_CNT_IN527    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[527]:0 */
    P2_2_PERI_TR_IO_INPUT0          = 21,       /* Digital Active - peri.tr_io_input[0]:0 */
    P2_2_LIN0_LIN_RX1               = 24,       /* Digital Active - lin[0].lin_rx[1]:0 */
    P2_2_CXPI0_CXPI_RX1             = 25,       /* Digital Active - cxpi[0].cxpi_rx[1]:0 */
    P2_2_CPUSS_SWJ_SWO_TDO          = 29,       /* Digital Deep Sleep - cpuss.swj_swo_tdo:0 */
    P2_2_SRSS_DDFT_PIN_IN0          = 31,       /* Digital Deep Sleep - srss.ddft_pin_in[0]:0 */

    /* P2.4 */
    P2_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_4_AMUXA                      =  4,       /* Analog mux bus A */
    P2_4_AMUXB                      =  5,       /* Analog mux bus B */
    P2_4_TCPWM0_LINE527             =  8,       /* Digital Active - tcpwm[0].line[527]:0 */
    P2_4_TCPWM0_LINE_COMPL526       =  9,       /* Digital Active - tcpwm[0].line_compl[526]:0 */
    P2_4_TCPWM0_TR_ONE_CNT_IN525    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[525]:0 */
    P2_4_PERI_TR_IO_INPUT6          = 21,       /* Digital Active - peri.tr_io_input[6]:0 */
    P2_4_LIN0_LIN_TX1               = 24,       /* Digital Active - lin[0].lin_tx[1]:0 */
    P2_4_CXPI0_CXPI_TX1             = 25,       /* Digital Active - cxpi[0].cxpi_tx[1]:0 */
    P2_4_CPUSS_SWJ_SWCLK_TCLK       = 29,       /* Digital Deep Sleep - cpuss.swj_swclk_tclk:0 */

    /* P2.5 */
    P2_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P2_5_AMUXA                      =  4,       /* Analog mux bus A */
    P2_5_AMUXB                      =  5,       /* Analog mux bus B */
    P2_5_TCPWM0_LINE0               =  8,       /* Digital Active - tcpwm[0].line[0]:0 */
    P2_5_TCPWM0_LINE_COMPL2         =  9,       /* Digital Active - tcpwm[0].line_compl[2]:0 */
    P2_5_PERI_TR_IO_INPUT7          = 21,       /* Digital Active - peri.tr_io_input[7]:0 */
    P2_5_LIN0_LIN_EN1               = 24,       /* Digital Active - lin[0].lin_en[1]:0 */
    P2_5_CXPI0_CXPI_EN1             = 25,       /* Digital Active - cxpi[0].cxpi_en[1]:0 */
    P2_5_CPUSS_SWJ_SWDIO_TMS        = 29,       /* Digital Deep Sleep - cpuss.swj_swdio_tms:0 */

    /* P3.0 */
    P3_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_0_AMUXA                      =  4,       /* Analog mux bus A */
    P3_0_AMUXB                      =  5,       /* Analog mux bus B */
    P3_0_TCPWM0_LINE1               =  8,       /* Digital Active - tcpwm[0].line[1]:0 */
    P3_0_TCPWM0_LINE_COMPL0         =  9,       /* Digital Active - tcpwm[0].line_compl[0]:0 */
    P3_0_PERI_TR_IO_INPUT8          = 21,       /* Digital Active - peri.tr_io_input[8]:0 */
    P3_0_CPUSS_SWJ_SWDOE_TDI        = 29,       /* Digital Deep Sleep - cpuss.swj_swdoe_tdi:0 */
    P3_0_SCB0_I2C_SDA               = 30,       /* Digital Deep Sleep - scb[0].i2c_sda:0 */

    /* P3.1 */
    P3_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P3_1_AMUXA                      =  4,       /* Analog mux bus A */
    P3_1_AMUXB                      =  5,       /* Analog mux bus B */
    P3_1_TCPWM0_LINE2               =  8,       /* Digital Active - tcpwm[0].line[2]:0 */
    P3_1_TCPWM0_LINE_COMPL1         =  9,       /* Digital Active - tcpwm[0].line_compl[1]:0 */
    P3_1_PERI_TR_IO_INPUT9          = 21,       /* Digital Active - peri.tr_io_input[9]:0 */
    P3_1_CPUSS_SWJ_TRSTN            = 29,       /* Digital Deep Sleep - cpuss.swj_trstn:0 */
    P3_1_SCB0_I2C_SCL               = 30,       /* Digital Deep Sleep - scb[0].i2c_scl:0 */

    /* P4.4 */
    P4_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_4_AMUXA                      =  4,       /* Analog mux bus A */
    P4_4_AMUXB                      =  5,       /* Analog mux bus B */
    P4_4_TCPWM0_LINE9               =  8,       /* Digital Active - tcpwm[0].line[9]:0 */
    P4_4_TCPWM0_LINE_COMPL8         =  9,       /* Digital Active - tcpwm[0].line_compl[8]:0 */
    P4_4_PASS0_SAR_EXT_MUX_SEL2     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[2] */
    P4_4_PERI_TR_IO_INPUT16         = 21,       /* Digital Active - peri.tr_io_input[16]:0 */
    P4_4_SG0_SG_AMPL1               = 22,       /* Digital Active - sg[0].sg_ampl[1]:2 */
    P4_4_CANFD0_TTCAN_TX1           = 25,       /* Digital Active - canfd[0].ttcan_tx[1]:1 */
    P4_4_SCB3_I2C_SDA               = 27,       /* Digital Active - scb[3].i2c_sda:1 */
    P4_4_SCB0_SPI_SELECT3           = 30,       /* Digital Deep Sleep - scb[0].spi_select3:0 */

    /* P4.5 */
    P4_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_5_AMUXA                      =  4,       /* Analog mux bus A */
    P4_5_AMUXB                      =  5,       /* Analog mux bus B */
    P4_5_TCPWM0_LINE10              =  8,       /* Digital Active - tcpwm[0].line[10]:0 */
    P4_5_TCPWM0_LINE_COMPL9         =  9,       /* Digital Active - tcpwm[0].line_compl[9]:0 */
    P4_5_PASS0_SAR_EXT_MUX_SEL3     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[3] */
    P4_5_PERI_TR_IO_INPUT17         = 21,       /* Digital Active - peri.tr_io_input[17]:0 */
    P4_5_SG0_SG_TONE1               = 22,       /* Digital Active - sg[0].sg_tone[1]:2 */
    P4_5_CANFD0_TTCAN_RX1           = 25,       /* Digital Active - canfd[0].ttcan_rx[1]:1 */
    P4_5_SCB3_I2C_SCL               = 27,       /* Digital Active - scb[3].i2c_scl:1 */
    P4_5_SCB0_I2C_SDA               = 30,       /* Digital Deep Sleep - scb[0].i2c_sda:1 */

    /* P4.6 */
    P4_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_6_AMUXA                      =  4,       /* Analog mux bus A */
    P4_6_AMUXB                      =  5,       /* Analog mux bus B */
    P4_6_TCPWM0_LINE11              =  8,       /* Digital Active - tcpwm[0].line[11]:0 */
    P4_6_TCPWM0_LINE_COMPL10        =  9,       /* Digital Active - tcpwm[0].line_compl[10]:0 */
    P4_6_PASS0_SAR_EXT_MUX_SEL4     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[4] */
    P4_6_PERI_TR_IO_INPUT18         = 21,       /* Digital Active - peri.tr_io_input[18]:0 */
    P4_6_SG0_SG_AMPL2               = 22,       /* Digital Active - sg[0].sg_ampl[2]:2 */
    P4_6_CANFD1_TTCAN_TX0           = 25,       /* Digital Active - canfd[1].ttcan_tx[0]:0 */
    P4_6_SCB0_I2C_SCL               = 30,       /* Digital Deep Sleep - scb[0].i2c_scl:1 */

    /* P4.7 */
    P4_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P4_7_AMUXA                      =  4,       /* Analog mux bus A */
    P4_7_AMUXB                      =  5,       /* Analog mux bus B */
    P4_7_TCPWM0_LINE12              =  8,       /* Digital Active - tcpwm[0].line[12]:0 */
    P4_7_TCPWM0_LINE_COMPL11        =  9,       /* Digital Active - tcpwm[0].line_compl[11]:0 */
    P4_7_PASS0_SAR_EXT_MUX_SEL5     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[5] */
    P4_7_PERI_TR_IO_INPUT19         = 21,       /* Digital Active - peri.tr_io_input[19]:0 */
    P4_7_SG0_SG_TONE2               = 22,       /* Digital Active - sg[0].sg_tone[2]:2 */
    P4_7_CANFD1_TTCAN_RX0           = 25,       /* Digital Active - canfd[1].ttcan_rx[0]:0 */

    /* P5.0 */
    P5_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_0_AMUXA                      =  4,       /* Analog mux bus A */
    P5_0_AMUXB                      =  5,       /* Analog mux bus B */
    P5_0_TCPWM0_LINE3               =  8,       /* Digital Active - tcpwm[0].line[3]:0 */
    P5_0_TCPWM0_LINE_COMPL16        =  9,       /* Digital Active - tcpwm[0].line_compl[16]:0 */
    P5_0_PERI_TR_IO_INPUT10         = 21,       /* Digital Active - peri.tr_io_input[10]:0 */
    P5_0_CPUSS_CLK_FM_PUMP          = 22,       /* Digital Active - cpuss.clk_fm_pump */
    P5_0_SCB0_UART_RX               = 23,       /* Digital Active - scb[0].uart_rx:0 */
    P5_0_CPUSS_FAULT_OUT1           = 27,       /* Digital Active - cpuss.fault_out[1]:0 */
    P5_0_SCB0_SPI_CLK               = 30,       /* Digital Deep Sleep - scb[0].spi_clk:0 */

    /* P5.1 */
    P5_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_1_AMUXA                      =  4,       /* Analog mux bus A */
    P5_1_AMUXB                      =  5,       /* Analog mux bus B */
    P5_1_TCPWM0_LINE4               =  8,       /* Digital Active - tcpwm[0].line[4]:0 */
    P5_1_TCPWM0_LINE_COMPL3         =  9,       /* Digital Active - tcpwm[0].line_compl[3]:0 */
    P5_1_PERI_TR_IO_INPUT11         = 21,       /* Digital Active - peri.tr_io_input[11]:0 */
    P5_1_SCB0_UART_TX               = 23,       /* Digital Active - scb[0].uart_tx:0 */
    P5_1_LIN0_LIN_TX1               = 24,       /* Digital Active - lin[0].lin_tx[1]:1 */
    P5_1_CXPI0_CXPI_EN1             = 25,       /* Digital Active - cxpi[0].cxpi_en[1]:1 */
    P5_1_CPUSS_FAULT_OUT2           = 27,       /* Digital Active - cpuss.fault_out[2]:0 */
    P5_1_SCB0_SPI_MOSI              = 30,       /* Digital Deep Sleep - scb[0].spi_mosi:0 */

    /* P5.2 */
    P5_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_2_AMUXA                      =  4,       /* Analog mux bus A */
    P5_2_AMUXB                      =  5,       /* Analog mux bus B */
    P5_2_TCPWM0_LINE5               =  8,       /* Digital Active - tcpwm[0].line[5]:0 */
    P5_2_TCPWM0_LINE_COMPL4         =  9,       /* Digital Active - tcpwm[0].line_compl[4]:0 */
    P5_2_PERI_TR_IO_INPUT12         = 21,       /* Digital Active - peri.tr_io_input[12]:0 */
    P5_2_SCB0_UART_RTS              = 23,       /* Digital Active - scb[0].uart_rts:0 */
    P5_2_LIN0_LIN_RX1               = 24,       /* Digital Active - lin[0].lin_rx[1]:1 */
    P5_2_CXPI0_CXPI_RX1             = 25,       /* Digital Active - cxpi[0].cxpi_rx[1]:1 */
    P5_2_SCB1_I2C_SDA               = 26,       /* Digital Active - scb[1].i2c_sda:1 */
    P5_2_CPUSS_FAULT_OUT3           = 27,       /* Digital Active - cpuss.fault_out[3]:0 */
    P5_2_SCB0_SPI_MISO              = 30,       /* Digital Deep Sleep - scb[0].spi_miso:0 */

    /* P5.3 */
    P5_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_3_AMUXA                      =  4,       /* Analog mux bus A */
    P5_3_AMUXB                      =  5,       /* Analog mux bus B */
    P5_3_TCPWM0_LINE6               =  8,       /* Digital Active - tcpwm[0].line[6]:0 */
    P5_3_TCPWM0_LINE_COMPL5         =  9,       /* Digital Active - tcpwm[0].line_compl[5]:0 */
    P5_3_PERI_TR_IO_INPUT13         = 21,       /* Digital Active - peri.tr_io_input[13]:0 */
    P5_3_SCB0_UART_CTS              = 23,       /* Digital Active - scb[0].uart_cts:0 */
    P5_3_LIN0_LIN_EN1               = 24,       /* Digital Active - lin[0].lin_en[1]:1 */
    P5_3_CXPI0_CXPI_TX1             = 25,       /* Digital Active - cxpi[0].cxpi_tx[1]:1 */
    P5_3_SCB1_I2C_SCL               = 26,       /* Digital Active - scb[1].i2c_scl:1 */
    P5_3_SCB0_SPI_SELECT0           = 30,       /* Digital Deep Sleep - scb[0].spi_select0:0 */

    /* P5.4 */
    P5_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_4_AMUXA                      =  4,       /* Analog mux bus A */
    P5_4_AMUXB                      =  5,       /* Analog mux bus B */
    P5_4_TCPWM0_LINE7               =  8,       /* Digital Active - tcpwm[0].line[7]:0 */
    P5_4_TCPWM0_LINE_COMPL6         =  9,       /* Digital Active - tcpwm[0].line_compl[6]:0 */
    P5_4_PASS0_SAR_EXT_MUX_SEL0     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[0] */
    P5_4_PERI_TR_IO_INPUT14         = 21,       /* Digital Active - peri.tr_io_input[14]:0 */
    P5_4_SG0_SG_AMPL0               = 22,       /* Digital Active - sg[0].sg_ampl[0]:2 */
    P5_4_CANFD0_TTCAN_TX0           = 25,       /* Digital Active - canfd[0].ttcan_tx[0]:1 */
    P5_4_SCB2_I2C_SDA               = 26,       /* Digital Active - scb[2].i2c_sda:1 */
    P5_4_SCB0_SPI_SELECT1           = 30,       /* Digital Deep Sleep - scb[0].spi_select1:0 */

    /* P5.5 */
    P5_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P5_5_AMUXA                      =  4,       /* Analog mux bus A */
    P5_5_AMUXB                      =  5,       /* Analog mux bus B */
    P5_5_TCPWM0_LINE8               =  8,       /* Digital Active - tcpwm[0].line[8]:0 */
    P5_5_TCPWM0_LINE_COMPL7         =  9,       /* Digital Active - tcpwm[0].line_compl[7]:0 */
    P5_5_PASS0_SAR_EXT_MUX_SEL1     = 16,       /* Digital Active - pass[0].sar_ext_mux_sel[1] */
    P5_5_PERI_TR_IO_INPUT15         = 21,       /* Digital Active - peri.tr_io_input[15]:0 */
    P5_5_SG0_SG_TONE0               = 22,       /* Digital Active - sg[0].sg_tone[0]:2 */
    P5_5_CANFD0_TTCAN_RX0           = 25,       /* Digital Active - canfd[0].ttcan_rx[0]:1 */
    P5_5_SCB2_I2C_SCL               = 26,       /* Digital Active - scb[2].i2c_scl:1 */
    P5_5_SCB0_SPI_SELECT2           = 30,       /* Digital Deep Sleep - scb[0].spi_select2:0 */

    /* P6.0 */
    P6_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_0_AMUXA                      =  4,       /* Analog mux bus A */
    P6_0_AMUXB                      =  5,       /* Analog mux bus B */
    P6_0_TCPWM0_LINE13              =  8,       /* Digital Active - tcpwm[0].line[13]:0 */
    P6_0_TCPWM0_LINE_COMPL12        =  9,       /* Digital Active - tcpwm[0].line_compl[12]:0 */
    P6_0_PASS0_SAR_EXT_MUX_EN0      = 16,       /* Digital Active - pass[0].sar_ext_mux_en[0] */
    P6_0_PERI_TR_IO_INPUT20         = 21,       /* Digital Active - peri.tr_io_input[20]:0 */
    P6_0_SG0_SG_AMPL3               = 22,       /* Digital Active - sg[0].sg_ampl[3]:2 */
    P6_0_CANFD1_TTCAN_TX1           = 25,       /* Digital Active - canfd[1].ttcan_tx[1]:0 */

    /* P6.1 */
    P6_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_1_AMUXA                      =  4,       /* Analog mux bus A */
    P6_1_AMUXB                      =  5,       /* Analog mux bus B */
    P6_1_TCPWM0_LINE14              =  8,       /* Digital Active - tcpwm[0].line[14]:0 */
    P6_1_TCPWM0_LINE_COMPL13        =  9,       /* Digital Active - tcpwm[0].line_compl[13]:0 */
    P6_1_PASS0_SAR_EXT_MUX_EN1      = 16,       /* Digital Active - pass[0].sar_ext_mux_en[1] */
    P6_1_PERI_TR_IO_INPUT21         = 21,       /* Digital Active - peri.tr_io_input[21]:0 */
    P6_1_SG0_SG_TONE3               = 22,       /* Digital Active - sg[0].sg_tone[3]:2 */
    P6_1_CANFD1_TTCAN_RX1           = 25,       /* Digital Active - canfd[1].ttcan_rx[1]:0 */

    /* P6.2 */
    P6_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_2_AMUXA                      =  4,       /* Analog mux bus A */
    P6_2_AMUXB                      =  5,       /* Analog mux bus B */
    P6_2_TCPWM0_LINE15              =  8,       /* Digital Active - tcpwm[0].line[15]:0 */
    P6_2_TCPWM0_LINE_COMPL14        =  9,       /* Digital Active - tcpwm[0].line_compl[14]:0 */
    P6_2_PERI_TR_IO_INPUT22         = 21,       /* Digital Active - peri.tr_io_input[22]:0 */
    P6_2_SG0_SG_AMPL4               = 22,       /* Digital Active - sg[0].sg_ampl[4]:0 */

    /* P6.3 */
    P6_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P6_3_AMUXA                      =  4,       /* Analog mux bus A */
    P6_3_AMUXB                      =  5,       /* Analog mux bus B */
    P6_3_TCPWM0_LINE16              =  8,       /* Digital Active - tcpwm[0].line[16]:0 */
    P6_3_TCPWM0_LINE_COMPL15        =  9,       /* Digital Active - tcpwm[0].line_compl[15]:0 */
    P6_3_PERI_TR_IO_INPUT23         = 21,       /* Digital Active - peri.tr_io_input[23]:0 */
    P6_3_SG0_SG_TONE4               = 22,       /* Digital Active - sg[0].sg_tone[4]:0 */

    /* P7.0 */
    P7_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_0_AMUXA                      =  4,       /* Analog mux bus A */
    P7_0_AMUXB                      =  5,       /* Analog mux bus B */
    P7_0_TCPWM0_LINE256             =  8,       /* Digital Active - tcpwm[0].line[256]:0 */
    P7_0_TCPWM0_LINE_COMPL533       =  9,       /* Digital Active - tcpwm[0].line_compl[533]:0 */
    P7_0_PERI_TR_IO_INPUT24         = 21,       /* Digital Active - peri.tr_io_input[24]:0 */

    /* P7.1 */
    P7_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_1_AMUXA                      =  4,       /* Analog mux bus A */
    P7_1_AMUXB                      =  5,       /* Analog mux bus B */
    P7_1_TCPWM0_LINE528             =  8,       /* Digital Active - tcpwm[0].line[528]:0 */
    P7_1_TCPWM0_LINE_COMPL256       =  9,       /* Digital Active - tcpwm[0].line_compl[256]:0 */
    P7_1_TCPWM0_TR_ONE_CNT_IN533    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[533]:0 */
    P7_1_PERI_TR_IO_INPUT25         = 21,       /* Digital Active - peri.tr_io_input[25]:0 */

    /* P7.2 */
    P7_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_2_AMUXA                      =  4,       /* Analog mux bus A */
    P7_2_AMUXB                      =  5,       /* Analog mux bus B */
    P7_2_TCPWM0_LINE257             =  8,       /* Digital Active - tcpwm[0].line[257]:0 */
    P7_2_TCPWM0_LINE_COMPL528       =  9,       /* Digital Active - tcpwm[0].line_compl[528]:0 */
    P7_2_PERI_TR_IO_INPUT26         = 21,       /* Digital Active - peri.tr_io_input[26]:0 */

    /* P7.3 */
    P7_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_3_AMUXA                      =  4,       /* Analog mux bus A */
    P7_3_AMUXB                      =  5,       /* Analog mux bus B */
    P7_3_TCPWM0_LINE529             =  8,       /* Digital Active - tcpwm[0].line[529]:0 */
    P7_3_TCPWM0_LINE_COMPL257       =  9,       /* Digital Active - tcpwm[0].line_compl[257]:0 */
    P7_3_TCPWM0_TR_ONE_CNT_IN528    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[528]:0 */
    P7_3_PERI_TR_IO_INPUT27         = 21,       /* Digital Active - peri.tr_io_input[27]:0 */

    /* P7.4 */
    P7_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_4_AMUXA                      =  4,       /* Analog mux bus A */
    P7_4_AMUXB                      =  5,       /* Analog mux bus B */
    P7_4_TCPWM0_LINE258             =  8,       /* Digital Active - tcpwm[0].line[258]:0 */
    P7_4_TCPWM0_LINE_COMPL529       =  9,       /* Digital Active - tcpwm[0].line_compl[529]:0 */
    P7_4_PERI_TR_IO_INPUT28         = 21,       /* Digital Active - peri.tr_io_input[28]:0 */

    /* P7.5 */
    P7_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_5_AMUXA                      =  4,       /* Analog mux bus A */
    P7_5_AMUXB                      =  5,       /* Analog mux bus B */
    P7_5_TCPWM0_LINE530             =  8,       /* Digital Active - tcpwm[0].line[530]:0 */
    P7_5_TCPWM0_LINE_COMPL258       =  9,       /* Digital Active - tcpwm[0].line_compl[258]:0 */
    P7_5_TCPWM0_TR_ONE_CNT_IN529    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[529]:0 */
    P7_5_PERI_TR_IO_INPUT29         = 21,       /* Digital Active - peri.tr_io_input[29]:0 */
    P7_5_VIDEOSS0_TTL_CAP0_DATA26   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[26]:2 */

    /* P7.6 */
    P7_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_6_AMUXA                      =  4,       /* Analog mux bus A */
    P7_6_AMUXB                      =  5,       /* Analog mux bus B */
    P7_6_TCPWM0_LINE259             =  8,       /* Digital Active - tcpwm[0].line[259]:0 */
    P7_6_TCPWM0_LINE_COMPL530       =  9,       /* Digital Active - tcpwm[0].line_compl[530]:0 */
    P7_6_PERI_TR_IO_INPUT30         = 21,       /* Digital Active - peri.tr_io_input[30]:0 */
    P7_6_VIDEOSS0_TTL_CAP0_DATA25   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[25]:2 */
    P7_6_CPUSS_FAULT_OUT0           = 27,       /* Digital Active - cpuss.fault_out[0]:1 */

    /* P7.7 */
    P7_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P7_7_AMUXA                      =  4,       /* Analog mux bus A */
    P7_7_AMUXB                      =  5,       /* Analog mux bus B */
    P7_7_TCPWM0_LINE531             =  8,       /* Digital Active - tcpwm[0].line[531]:0 */
    P7_7_TCPWM0_LINE_COMPL259       =  9,       /* Digital Active - tcpwm[0].line_compl[259]:0 */
    P7_7_TCPWM0_TR_ONE_CNT_IN530    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[530]:0 */
    P7_7_PERI_TR_IO_INPUT31         = 21,       /* Digital Active - peri.tr_io_input[31]:0 */
    P7_7_VIDEOSS0_TTL_CAP0_DATA24   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[24]:2 */
    P7_7_CPUSS_FAULT_OUT1           = 27,       /* Digital Active - cpuss.fault_out[1]:1 */

    /* P8.0 */
    P8_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_0_AMUXA                      =  4,       /* Analog mux bus A */
    P8_0_AMUXB                      =  5,       /* Analog mux bus B */
    P8_0_TCPWM0_LINE260             =  8,       /* Digital Active - tcpwm[0].line[260]:0 */
    P8_0_TCPWM0_LINE_COMPL531       =  9,       /* Digital Active - tcpwm[0].line_compl[531]:0 */
    P8_0_VIDEOSS0_TTL_CAP0_DATA23   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[23]:2 */
    P8_0_PERI_TR_IO_INPUT32         = 21,       /* Digital Active - peri.tr_io_input[32]:0 */

    /* P8.1 */
    P8_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_1_AMUXA                      =  4,       /* Analog mux bus A */
    P8_1_AMUXB                      =  5,       /* Analog mux bus B */
    P8_1_TCPWM0_LINE532             =  8,       /* Digital Active - tcpwm[0].line[532]:0 */
    P8_1_TCPWM0_LINE_COMPL260       =  9,       /* Digital Active - tcpwm[0].line_compl[260]:0 */
    P8_1_TCPWM0_TR_ONE_CNT_IN531    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[531]:0 */
    P8_1_VIDEOSS0_TTL_CAP0_DATA22   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[22]:2 */
    P8_1_PERI_TR_IO_INPUT33         = 21,       /* Digital Active - peri.tr_io_input[33]:0 */
    P8_1_SG0_SG_MCK0                = 22,       /* Digital Active - sg[0].sg_mck[0]:0 */

    /* P8.2 */
    P8_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_2_AMUXA                      =  4,       /* Analog mux bus A */
    P8_2_AMUXB                      =  5,       /* Analog mux bus B */
    P8_2_TCPWM0_LINE261             =  8,       /* Digital Active - tcpwm[0].line[261]:0 */
    P8_2_TCPWM0_LINE_COMPL532       =  9,       /* Digital Active - tcpwm[0].line_compl[532]:0 */
    P8_2_VIDEOSS0_TTL_CAP0_DATA21   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[21]:2 */
    P8_2_PERI_TR_IO_INPUT34         = 21,       /* Digital Active - peri.tr_io_input[34]:0 */
    P8_2_SG0_SG_AMPL0               = 22,       /* Digital Active - sg[0].sg_ampl[0]:3 */

    /* P8.3 */
    P8_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_3_AMUXA                      =  4,       /* Analog mux bus A */
    P8_3_AMUXB                      =  5,       /* Analog mux bus B */
    P8_3_TCPWM0_LINE533             =  8,       /* Digital Active - tcpwm[0].line[533]:0 */
    P8_3_TCPWM0_LINE_COMPL261       =  9,       /* Digital Active - tcpwm[0].line_compl[261]:0 */
    P8_3_TCPWM0_TR_ONE_CNT_IN532    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[532]:0 */
    P8_3_VIDEOSS0_TTL_CAP0_DATA20   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[20]:2 */
    P8_3_PERI_TR_IO_INPUT35         = 21,       /* Digital Active - peri.tr_io_input[35]:0 */
    P8_3_SG0_SG_TONE0               = 22,       /* Digital Active - sg[0].sg_tone[0]:3 */

    /* P8.4 */
    P8_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_4_AMUXA                      =  4,       /* Analog mux bus A */
    P8_4_AMUXB                      =  5,       /* Analog mux bus B */
    P8_4_TCPWM0_LINE262             =  8,       /* Digital Active - tcpwm[0].line[262]:0 */
    P8_4_TCPWM0_LINE_COMPL17        =  9,       /* Digital Active - tcpwm[0].line_compl[17]:0 */
    P8_4_VIDEOSS0_TTL_CAP0_DATA19   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[19]:2 */
    P8_4_PERI_TR_IO_INPUT36         = 21,       /* Digital Active - peri.tr_io_input[36]:0 */
    P8_4_SG0_SG_AMPL1               = 22,       /* Digital Active - sg[0].sg_ampl[1]:3 */

    /* P8.5 */
    P8_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_5_AMUXA                      =  4,       /* Analog mux bus A */
    P8_5_AMUXB                      =  5,       /* Analog mux bus B */
    P8_5_TCPWM0_LINE17              =  8,       /* Digital Active - tcpwm[0].line[17]:0 */
    P8_5_TCPWM0_LINE_COMPL262       =  9,       /* Digital Active - tcpwm[0].line_compl[262]:0 */
    P8_5_TCPWM0_TR_ONE_CNT_IN22     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[22]:0 */
    P8_5_VIDEOSS0_TTL_CAP0_DATA18   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[18]:2 */
    P8_5_PERI_TR_IO_INPUT37         = 21,       /* Digital Active - peri.tr_io_input[37]:0 */
    P8_5_SG0_SG_TONE1               = 22,       /* Digital Active - sg[0].sg_tone[1]:3 */

    /* P8.6 */
    P8_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_6_AMUXA                      =  4,       /* Analog mux bus A */
    P8_6_AMUXB                      =  5,       /* Analog mux bus B */
    P8_6_TCPWM0_LINE263             =  8,       /* Digital Active - tcpwm[0].line[263]:0 */
    P8_6_TCPWM0_LINE_COMPL18        =  9,       /* Digital Active - tcpwm[0].line_compl[18]:0 */
    P8_6_VIDEOSS0_TTL_CAP0_DATA17   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[17]:2 */
    P8_6_PERI_TR_IO_INPUT38         = 21,       /* Digital Active - peri.tr_io_input[38]:0 */
    P8_6_SG0_SG_AMPL2               = 22,       /* Digital Active - sg[0].sg_ampl[2]:3 */

    /* P8.7 */
    P8_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P8_7_AMUXA                      =  4,       /* Analog mux bus A */
    P8_7_AMUXB                      =  5,       /* Analog mux bus B */
    P8_7_TCPWM0_LINE18              =  8,       /* Digital Active - tcpwm[0].line[18]:0 */
    P8_7_TCPWM0_LINE_COMPL263       =  9,       /* Digital Active - tcpwm[0].line_compl[263]:0 */
    P8_7_VIDEOSS0_TTL_CAP0_DATA16   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[16]:2 */
    P8_7_PERI_TR_IO_INPUT39         = 21,       /* Digital Active - peri.tr_io_input[39]:0 */
    P8_7_SG0_SG_TONE2               = 22,       /* Digital Active - sg[0].sg_tone[2]:3 */

    /* P9.0 */
    P9_0_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_0_AMUXA                      =  4,       /* Analog mux bus A */
    P9_0_AMUXB                      =  5,       /* Analog mux bus B */
    P9_0_TCPWM0_LINE264             =  8,       /* Digital Active - tcpwm[0].line[264]:0 */
    P9_0_TCPWM0_LINE_COMPL19        =  9,       /* Digital Active - tcpwm[0].line_compl[19]:0 */
    P9_0_VIDEOSS0_TTL_CAP0_DATA15   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[15]:2 */
    P9_0_PERI_TR_IO_INPUT40         = 21,       /* Digital Active - peri.tr_io_input[40]:0 */
    P9_0_SG0_SG_AMPL3               = 22,       /* Digital Active - sg[0].sg_ampl[3]:3 */

    /* P9.1 */
    P9_1_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_1_AMUXA                      =  4,       /* Analog mux bus A */
    P9_1_AMUXB                      =  5,       /* Analog mux bus B */
    P9_1_TCPWM0_LINE19              =  8,       /* Digital Active - tcpwm[0].line[19]:0 */
    P9_1_TCPWM0_LINE_COMPL264       =  9,       /* Digital Active - tcpwm[0].line_compl[264]:0 */
    P9_1_VIDEOSS0_TTL_CAP0_DATA14   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[14]:2 */
    P9_1_PERI_TR_IO_INPUT41         = 21,       /* Digital Active - peri.tr_io_input[41]:0 */
    P9_1_SG0_SG_TONE3               = 22,       /* Digital Active - sg[0].sg_tone[3]:3 */

    /* P9.2 */
    P9_2_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_2_AMUXA                      =  4,       /* Analog mux bus A */
    P9_2_AMUXB                      =  5,       /* Analog mux bus B */
    P9_2_TCPWM0_LINE265             =  8,       /* Digital Active - tcpwm[0].line[265]:0 */
    P9_2_TCPWM0_LINE_COMPL20        =  9,       /* Digital Active - tcpwm[0].line_compl[20]:0 */
    P9_2_VIDEOSS0_TTL_CAP0_DATA13   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[13]:2 */
    P9_2_PERI_TR_IO_INPUT42         = 21,       /* Digital Active - peri.tr_io_input[42]:0 */
    P9_2_SG0_SG_AMPL4               = 22,       /* Digital Active - sg[0].sg_ampl[4]:1 */

    /* P9.3 */
    P9_3_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_3_AMUXA                      =  4,       /* Analog mux bus A */
    P9_3_AMUXB                      =  5,       /* Analog mux bus B */
    P9_3_TCPWM0_LINE20              =  8,       /* Digital Active - tcpwm[0].line[20]:0 */
    P9_3_TCPWM0_LINE_COMPL265       =  9,       /* Digital Active - tcpwm[0].line_compl[265]:0 */
    P9_3_VIDEOSS0_TTL_CAP0_DATA12   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[12]:2 */
    P9_3_PERI_TR_IO_INPUT43         = 21,       /* Digital Active - peri.tr_io_input[43]:0 */
    P9_3_SG0_SG_TONE4               = 22,       /* Digital Active - sg[0].sg_tone[4]:1 */
    P9_3_SCB8_SPI_SELECT1           = 25,       /* Digital Active - scb[8].spi_select1:0 */

    /* P9.4 */
    P9_4_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_4_AMUXA                      =  4,       /* Analog mux bus A */
    P9_4_AMUXB                      =  5,       /* Analog mux bus B */
    P9_4_TCPWM0_LINE266             =  8,       /* Digital Active - tcpwm[0].line[266]:0 */
    P9_4_TCPWM0_LINE_COMPL21        =  9,       /* Digital Active - tcpwm[0].line_compl[21]:0 */
    P9_4_VIDEOSS0_TTL_CAP0_DATA11   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[11]:2 */
    P9_4_PERI_TR_IO_INPUT44         = 21,       /* Digital Active - peri.tr_io_input[44]:0 */
    P9_4_SG0_SG_MCK1                = 22,       /* Digital Active - sg[0].sg_mck[1]:0 */
    P9_4_SCB8_SPI_CLK               = 25,       /* Digital Active - scb[8].spi_clk:0 */
    P9_4_SCB8_UART_RX               = 26,       /* Digital Active - scb[8].uart_rx:0 */
    P9_4_SCB8_I2C_SDA               = 27,       /* Digital Active - scb[8].i2c_sda:0 */

    /* P9.5 */
    P9_5_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_5_AMUXA                      =  4,       /* Analog mux bus A */
    P9_5_AMUXB                      =  5,       /* Analog mux bus B */
    P9_5_TCPWM0_LINE21              =  8,       /* Digital Active - tcpwm[0].line[21]:0 */
    P9_5_TCPWM0_LINE_COMPL266       =  9,       /* Digital Active - tcpwm[0].line_compl[266]:0 */
    P9_5_TCPWM0_TR_ONE_CNT_IN20     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[20]:0 */
    P9_5_VIDEOSS0_TTL_CAP0_DATA10   = 18,       /* Digital Active - videoss[0].ttl_cap0_data[10]:2 */
    P9_5_PERI_TR_IO_INPUT45         = 21,       /* Digital Active - peri.tr_io_input[45]:0 */
    P9_5_SG0_SG_MCK2                = 22,       /* Digital Active - sg[0].sg_mck[2]:0 */
    P9_5_SCB8_SPI_MOSI              = 25,       /* Digital Active - scb[8].spi_mosi:0 */
    P9_5_SCB8_UART_TX               = 26,       /* Digital Active - scb[8].uart_tx:0 */
    P9_5_SCB8_I2C_SCL               = 27,       /* Digital Active - scb[8].i2c_scl:0 */

    /* P9.6 */
    P9_6_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_6_AMUXA                      =  4,       /* Analog mux bus A */
    P9_6_AMUXB                      =  5,       /* Analog mux bus B */
    P9_6_TCPWM0_LINE267             =  8,       /* Digital Active - tcpwm[0].line[267]:0 */
    P9_6_TCPWM0_LINE_COMPL22        =  9,       /* Digital Active - tcpwm[0].line_compl[22]:0 */
    P9_6_PERI_TR_IO_INPUT46         = 21,       /* Digital Active - peri.tr_io_input[46]:0 */
    P9_6_SG0_SG_MCK3                = 22,       /* Digital Active - sg[0].sg_mck[3]:0 */
    P9_6_VIDEOSS0_TTL_CAP0_DATA9    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[9]:2 */
    P9_6_SCB8_SPI_MISO              = 25,       /* Digital Active - scb[8].spi_miso:0 */
    P9_6_SCB8_UART_RTS              = 26,       /* Digital Active - scb[8].uart_rts:0 */

    /* P9.7 */
    P9_7_GPIO                       =  0,       /* GPIO controls 'out' */
    P9_7_AMUXA                      =  4,       /* Analog mux bus A */
    P9_7_AMUXB                      =  5,       /* Analog mux bus B */
    P9_7_TCPWM0_LINE22              =  8,       /* Digital Active - tcpwm[0].line[22]:0 */
    P9_7_TCPWM0_LINE_COMPL267       =  9,       /* Digital Active - tcpwm[0].line_compl[267]:0 */
    P9_7_TCPWM0_TR_ONE_CNT_IN21     = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[21]:0 */
    P9_7_PERI_TR_IO_INPUT47         = 21,       /* Digital Active - peri.tr_io_input[47]:0 */
    P9_7_SG0_SG_MCK4                = 22,       /* Digital Active - sg[0].sg_mck[4]:0 */
    P9_7_VIDEOSS0_TTL_CAP0_DATA8    = 23,       /* Digital Active - videoss[0].ttl_cap0_data[8]:2 */
    P9_7_SCB8_SPI_SELECT0           = 25,       /* Digital Active - scb[8].spi_select0:0 */
    P9_7_SCB8_UART_CTS              = 26,       /* Digital Active - scb[8].uart_cts:0 */

    /* P11.0 */
    P11_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_0_AMUXA                     =  4,       /* Analog mux bus A */
    P11_0_AMUXB                     =  5,       /* Analog mux bus B */
    P11_0_ETH0_REF_CLK              = 11,       /* Digital Active - eth[0].ref_clk */
    P11_0_VIDEOSS0_TTL_CAP0_DATA7   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[7]:3 */
    P11_0_VIDEOSS0_TTL_DSP1_DATA_A111 = 24,     /* Digital Active - videoss[0].ttl_dsp1_data_a1[11]:1 */
    P11_0_SCB1_UART_RX              = 25,       /* Digital Active - scb[1].uart_rx:0 */
    P11_0_SCB1_I2C_SDA              = 26,       /* Digital Active - scb[1].i2c_sda:0 */
    P11_0_SCB1_SPI_CLK              = 27,       /* Digital Active - scb[1].spi_clk:0 */

    /* P11.1 */
    P11_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_1_AMUXA                     =  4,       /* Analog mux bus A */
    P11_1_AMUXB                     =  5,       /* Analog mux bus B */
    P11_1_ETH0_RX_ER                = 11,       /* Digital Active - eth[0].rx_er */
    P11_1_VIDEOSS0_TTL_CAP0_DATA6   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[6]:3 */
    P11_1_VIDEOSS0_TTL_DSP1_DATA_A011 = 24,     /* Digital Active - videoss[0].ttl_dsp1_data_a0[11]:1 */
    P11_1_SCB1_UART_TX              = 25,       /* Digital Active - scb[1].uart_tx:0 */
    P11_1_SCB1_I2C_SCL              = 26,       /* Digital Active - scb[1].i2c_scl:0 */
    P11_1_SCB1_SPI_MOSI             = 27,       /* Digital Active - scb[1].spi_mosi:0 */

    /* P11.2 */
    P11_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_2_AMUXA                     =  4,       /* Analog mux bus A */
    P11_2_AMUXB                     =  5,       /* Analog mux bus B */
    P11_2_ETH0_RXD0                 = 11,       /* Digital Active - eth[0].rxd[0] */
    P11_2_VIDEOSS0_TTL_CAP0_DATA5   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[5]:3 */
    P11_2_VIDEOSS0_TTL_DSP1_DATA_A110 = 24,     /* Digital Active - videoss[0].ttl_dsp1_data_a1[10]:1 */
    P11_2_SCB1_UART_RTS             = 25,       /* Digital Active - scb[1].uart_rts:0 */
    P11_2_SCB1_SPI_MISO             = 27,       /* Digital Active - scb[1].spi_miso:0 */

    /* P11.3 */
    P11_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_3_AMUXA                     =  4,       /* Analog mux bus A */
    P11_3_AMUXB                     =  5,       /* Analog mux bus B */
    P11_3_ETH0_RXD1                 = 11,       /* Digital Active - eth[0].rxd[1] */
    P11_3_VIDEOSS0_TTL_CAP0_DATA4   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[4]:3 */
    P11_3_VIDEOSS0_TTL_DSP1_DATA_A010 = 24,     /* Digital Active - videoss[0].ttl_dsp1_data_a0[10]:1 */
    P11_3_SCB1_UART_CTS             = 25,       /* Digital Active - scb[1].uart_cts:0 */
    P11_3_SCB1_SPI_SELECT0          = 27,       /* Digital Active - scb[1].spi_select0:0 */

    /* P11.4 */
    P11_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_4_AMUXA                     =  4,       /* Analog mux bus A */
    P11_4_AMUXB                     =  5,       /* Analog mux bus B */
    P11_4_ETH0_TXD0                 = 11,       /* Digital Active - eth[0].txd[0] */
    P11_4_VIDEOSS0_TTL_CAP0_DATA3   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[3]:3 */
    P11_4_VIDEOSS0_TTL_DSP1_CONTROL2 = 25,      /* Digital Active - videoss[0].ttl_dsp1_control[2]:3 */
    P11_4_SCB1_SPI_SELECT1          = 27,       /* Digital Active - scb[1].spi_select1:0 */

    /* P11.5 */
    P11_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_5_AMUXA                     =  4,       /* Analog mux bus A */
    P11_5_AMUXB                     =  5,       /* Analog mux bus B */
    P11_5_ETH0_TXD1                 = 11,       /* Digital Active - eth[0].txd[1] */
    P11_5_VIDEOSS0_TTL_CAP0_DATA2   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[2]:3 */
    P11_5_SCB2_UART_RX              = 25,       /* Digital Active - scb[2].uart_rx:0 */
    P11_5_SCB2_I2C_SDA              = 26,       /* Digital Active - scb[2].i2c_sda:0 */
    P11_5_SCB2_SPI_CLK              = 27,       /* Digital Active - scb[2].spi_clk:0 */

    /* P11.6 */
    P11_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_6_AMUXA                     =  4,       /* Analog mux bus A */
    P11_6_AMUXB                     =  5,       /* Analog mux bus B */
    P11_6_ETH0_TX_CTL               = 11,       /* Digital Active - eth[0].tx_ctl */
    P11_6_VIDEOSS0_TTL_CAP0_DATA1   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[1]:3 */
    P11_6_VIDEOSS0_TTL_DSP1_DATA_A19 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[9]:1 */
    P11_6_SCB2_UART_TX              = 25,       /* Digital Active - scb[2].uart_tx:0 */
    P11_6_SCB2_I2C_SCL              = 26,       /* Digital Active - scb[2].i2c_scl:0 */
    P11_6_SCB2_SPI_MOSI             = 27,       /* Digital Active - scb[2].spi_mosi:0 */

    /* P11.7 */
    P11_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P11_7_AMUXA                     =  4,       /* Analog mux bus A */
    P11_7_AMUXB                     =  5,       /* Analog mux bus B */
    P11_7_ETH0_RX_CTL               = 11,       /* Digital Active - eth[0].rx_ctl */
    P11_7_VIDEOSS0_TTL_CAP0_DATA0   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[0]:3 */
    P11_7_VIDEOSS0_TTL_DSP1_DATA_A09 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[9]:1 */
    P11_7_SCB2_UART_RTS             = 25,       /* Digital Active - scb[2].uart_rts:0 */
    P11_7_SCB2_SPI_MISO             = 27,       /* Digital Active - scb[2].spi_miso:0 */

    /* P12.0 */
    P12_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_0_AMUXA                     =  4,       /* Analog mux bus A */
    P12_0_AMUXB                     =  5,       /* Analog mux bus B */
    P12_0_ETH0_MDC                  = 11,       /* Digital Active - eth[0].mdc:0 */
    P12_0_VIDEOSS0_TTL_CAP0_CLK     = 18,       /* Digital Active - videoss[0].ttl_cap0_clk:2 */
    P12_0_VIDEOSS0_TTL_DSP1_DATA_A18 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[8]:1 */
    P12_0_SCB2_UART_CTS             = 25,       /* Digital Active - scb[2].uart_cts:0 */
    P12_0_SCB2_SPI_SELECT0          = 27,       /* Digital Active - scb[2].spi_select0:0 */

    /* P12.1 */
    P12_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P12_1_AMUXA                     =  4,       /* Analog mux bus A */
    P12_1_AMUXB                     =  5,       /* Analog mux bus B */
    P12_1_ETH0_MDIO                 = 11,       /* Digital Active - eth[0].mdio:0 */
    P12_1_VIDEOSS0_TTL_CAP0_DATA7   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[7]:2 */
    P12_1_VIDEOSS0_TTL_DSP1_DATA_A08 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[8]:1 */
    P12_1_VIDEOSS0_TTL_DSP0_CONTROL11 = 25,     /* Digital Active - videoss[0].ttl_dsp0_control[11]:0 */
    P12_1_SCB2_SPI_SELECT1          = 27,       /* Digital Active - scb[2].spi_select1:0 */

    /* P14.2 */
    P14_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_2_AMUXA                     =  4,       /* Analog mux bus A */
    P14_2_AMUXB                     =  5,       /* Analog mux bus B */
    P14_2_TCPWM0_LINE536            =  8,       /* Digital Active - tcpwm[0].line[536]:0 */
    P14_2_TCPWM0_LINE_COMPL535      =  9,       /* Digital Active - tcpwm[0].line_compl[535]:0 */
    P14_2_TCPWM0_TR_ONE_CNT_IN534   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[534]:0 */
    P14_2_TDM0_TDM_TX_MCK2          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[2]:0 */
    P14_2_TDM0_TDM_RX_MCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[0]:0 */
    P14_2_VIDEOSS0_TTL_CAP0_DATA15  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[15]:0 */
    P14_2_PWM0_PWM_LINE1_P0         = 21,       /* Digital Active - pwm[0].pwm_line1_p[0]:1 */
    P14_2_SG0_SG_TONE0              = 22,       /* Digital Active - sg[0].sg_tone[0]:1 */
    P14_2_VIDEOSS0_TTL_CAP0_DATA4   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[4]:1 */
    P14_2_VIDEOSS0_TTL_DSP1_DATA_A17 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[7]:0 */
    P14_2_VIDEOSS0_TTL_DSP1_CONTROL2 = 25,      /* Digital Active - videoss[0].ttl_dsp1_control[2]:2 */
    P14_2_CPUSS_TRACE_CLOCK         = 26,       /* Digital Active - cpuss.trace_clock:0 */

    /* P14.3 */
    P14_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_3_AMUXA                     =  4,       /* Analog mux bus A */
    P14_3_AMUXB                     =  5,       /* Analog mux bus B */
    P14_3_TCPWM0_LINE537            =  8,       /* Digital Active - tcpwm[0].line[537]:0 */
    P14_3_TCPWM0_LINE_COMPL536      =  9,       /* Digital Active - tcpwm[0].line_compl[536]:0 */
    P14_3_TCPWM0_TR_ONE_CNT_IN535   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[535]:0 */
    P14_3_TDM0_TDM_TX_SCK2          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[2]:0 */
    P14_3_TDM0_TDM_RX_SCK0          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[0]:0 */
    P14_3_VIDEOSS0_TTL_CAP0_DATA14  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[14]:0 */
    P14_3_PWM0_PWM_LINE1_N0         = 21,       /* Digital Active - pwm[0].pwm_line1_n[0]:1 */
    P14_3_SG0_SG_AMPL0              = 22,       /* Digital Active - sg[0].sg_ampl[0]:1 */
    P14_3_VIDEOSS0_TTL_CAP0_DATA5   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[5]:1 */
    P14_3_VIDEOSS0_TTL_DSP1_DATA_A07 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[7]:0 */
    P14_3_CPUSS_TRACE_DATA0         = 26,       /* Digital Active - cpuss.trace_data[0]:0 */

    /* P14.4 */
    P14_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_4_AMUXA                     =  4,       /* Analog mux bus A */
    P14_4_AMUXB                     =  5,       /* Analog mux bus B */
    P14_4_TCPWM0_LINE538            =  8,       /* Digital Active - tcpwm[0].line[538]:0 */
    P14_4_TCPWM0_LINE_COMPL537      =  9,       /* Digital Active - tcpwm[0].line_compl[537]:0 */
    P14_4_TCPWM0_TR_ONE_CNT_IN536   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[536]:0 */
    P14_4_TDM0_TDM_TX_FSYNC2        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[2]:0 */
    P14_4_TDM0_TDM_RX_FSYNC0        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[0]:0 */
    P14_4_VIDEOSS0_TTL_CAP0_DATA13  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[13]:0 */
    P14_4_PWM0_PWM_LINE2_P0         = 21,       /* Digital Active - pwm[0].pwm_line2_p[0]:1 */
    P14_4_SG0_SG_TONE1              = 22,       /* Digital Active - sg[0].sg_tone[1]:1 */
    P14_4_VIDEOSS0_TTL_CAP0_DATA6   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[6]:1 */
    P14_4_VIDEOSS0_TTL_DSP1_DATA_A16 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[6]:0 */
    P14_4_CPUSS_TRACE_DATA1         = 26,       /* Digital Active - cpuss.trace_data[1]:0 */

    /* P14.5 */
    P14_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_5_AMUXA                     =  4,       /* Analog mux bus A */
    P14_5_AMUXB                     =  5,       /* Analog mux bus B */
    P14_5_TCPWM0_LINE539            =  8,       /* Digital Active - tcpwm[0].line[539]:0 */
    P14_5_TCPWM0_LINE_COMPL538      =  9,       /* Digital Active - tcpwm[0].line_compl[538]:0 */
    P14_5_TCPWM0_TR_ONE_CNT_IN537   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[537]:0 */
    P14_5_TDM0_TDM_TX_SD2           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[2]:0 */
    P14_5_TDM0_TDM_RX_SD0           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[0]:0 */
    P14_5_VIDEOSS0_TTL_CAP0_DATA12  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[12]:0 */
    P14_5_PWM0_PWM_LINE2_N0         = 21,       /* Digital Active - pwm[0].pwm_line2_n[0]:1 */
    P14_5_SG0_SG_AMPL1              = 22,       /* Digital Active - sg[0].sg_ampl[1]:1 */
    P14_5_VIDEOSS0_TTL_CAP0_DATA7   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[7]:1 */
    P14_5_VIDEOSS0_TTL_DSP1_DATA_A06 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[6]:0 */
    P14_5_CPUSS_TRACE_DATA2         = 26,       /* Digital Active - cpuss.trace_data[2]:0 */

    /* P14.6 */
    P14_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_6_AMUXA                     =  4,       /* Analog mux bus A */
    P14_6_AMUXB                     =  5,       /* Analog mux bus B */
    P14_6_TCPWM0_LINE540            =  8,       /* Digital Active - tcpwm[0].line[540]:0 */
    P14_6_TCPWM0_LINE_COMPL539      =  9,       /* Digital Active - tcpwm[0].line_compl[539]:0 */
    P14_6_TCPWM0_TR_ONE_CNT_IN538   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[538]:0 */
    P14_6_TDM0_TDM_TX_MCK3          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[3]:0 */
    P14_6_TDM0_TDM_RX_MCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[1]:0 */
    P14_6_VIDEOSS0_TTL_CAP0_DATA11  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[11]:0 */
    P14_6_PWM0_PWM_LINE1_P1         = 21,       /* Digital Active - pwm[0].pwm_line1_p[1]:1 */
    P14_6_SG0_SG_TONE2              = 22,       /* Digital Active - sg[0].sg_tone[2]:1 */
    P14_6_VIDEOSS0_TTL_CAP0_DATA8   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[8]:1 */
    P14_6_VIDEOSS0_TTL_DSP1_DATA_A15 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[5]:0 */
    P14_6_CPUSS_TRACE_DATA3         = 26,       /* Digital Active - cpuss.trace_data[3]:0 */

    /* P14.7 */
    P14_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P14_7_AMUXA                     =  4,       /* Analog mux bus A */
    P14_7_AMUXB                     =  5,       /* Analog mux bus B */
    P14_7_TCPWM0_LINE541            =  8,       /* Digital Active - tcpwm[0].line[541]:0 */
    P14_7_TCPWM0_LINE_COMPL540      =  9,       /* Digital Active - tcpwm[0].line_compl[540]:0 */
    P14_7_TCPWM0_TR_ONE_CNT_IN539   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[539]:0 */
    P14_7_TDM0_TDM_TX_SCK3          = 16,       /* Digital Active - tdm[0].tdm_tx_sck[3]:0 */
    P14_7_TDM0_TDM_RX_SCK1          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[1]:0 */
    P14_7_VIDEOSS0_TTL_CAP0_DATA10  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[10]:0 */
    P14_7_PWM0_PWM_LINE1_N1         = 21,       /* Digital Active - pwm[0].pwm_line1_n[1]:1 */
    P14_7_SG0_SG_AMPL2              = 22,       /* Digital Active - sg[0].sg_ampl[2]:1 */
    P14_7_VIDEOSS0_TTL_CAP0_DATA9   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[9]:1 */
    P14_7_VIDEOSS0_TTL_DSP1_DATA_A05 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[5]:0 */

    /* P15.0 */
    P15_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_0_AMUXA                     =  4,       /* Analog mux bus A */
    P15_0_AMUXB                     =  5,       /* Analog mux bus B */
    P15_0_TCPWM0_LINE542            =  8,       /* Digital Active - tcpwm[0].line[542]:0 */
    P15_0_TCPWM0_LINE_COMPL541      =  9,       /* Digital Active - tcpwm[0].line_compl[541]:0 */
    P15_0_TCPWM0_TR_ONE_CNT_IN540   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[540]:0 */
    P15_0_TDM0_TDM_TX_FSYNC3        = 16,       /* Digital Active - tdm[0].tdm_tx_fsync[3]:0 */
    P15_0_TDM0_TDM_RX_FSYNC1        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[1]:0 */
    P15_0_VIDEOSS0_TTL_CAP0_CLK     = 18,       /* Digital Active - videoss[0].ttl_cap0_clk:0 */
    P15_0_PWM0_PWM_LINE2_P1         = 21,       /* Digital Active - pwm[0].pwm_line2_p[1]:1 */
    P15_0_SG0_SG_TONE3              = 22,       /* Digital Active - sg[0].sg_tone[3]:1 */
    P15_0_VIDEOSS0_TTL_DSP1_DATA_A14 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[4]:0 */

    /* P15.1 */
    P15_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_1_AMUXA                     =  4,       /* Analog mux bus A */
    P15_1_AMUXB                     =  5,       /* Analog mux bus B */
    P15_1_TCPWM0_LINE543            =  8,       /* Digital Active - tcpwm[0].line[543]:0 */
    P15_1_TCPWM0_LINE_COMPL542      =  9,       /* Digital Active - tcpwm[0].line_compl[542]:0 */
    P15_1_TCPWM0_TR_ONE_CNT_IN541   = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[541]:0 */
    P15_1_TDM0_TDM_TX_SD3           = 16,       /* Digital Active - tdm[0].tdm_tx_sd[3]:0 */
    P15_1_TDM0_TDM_RX_SD1           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[1]:0 */
    P15_1_VIDEOSS0_TTL_CAP0_DATA10  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[10]:1 */
    P15_1_PWM0_PWM_LINE2_N1         = 21,       /* Digital Active - pwm[0].pwm_line2_n[1]:1 */
    P15_1_SG0_SG_AMPL3              = 22,       /* Digital Active - sg[0].sg_ampl[3]:1 */
    P15_1_VIDEOSS0_TTL_CAP0_DATA9   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[9]:0 */
    P15_1_VIDEOSS0_TTL_DSP1_DATA_A04 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[4]:0 */

    /* P15.2 */
    P15_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_2_AMUXA                     =  4,       /* Analog mux bus A */
    P15_2_AMUXB                     =  5,       /* Analog mux bus B */
    P15_2_TCPWM0_LINE23             =  8,       /* Digital Active - tcpwm[0].line[23]:0 */
    P15_2_TCPWM0_LINE_COMPL29       =  9,       /* Digital Active - tcpwm[0].line_compl[29]:0 */
    P15_2_TCPWM0_TR_ONE_CNT_IN28    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[28]:0 */
    P15_2_VIDEOSS0_TTL_CAP0_DATA11  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[11]:1 */
    P15_2_VIDEOSS0_TTL_CAP0_DATA8   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[8]:0 */
    P15_2_VIDEOSS0_TTL_DSP1_DATA_A13 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[3]:0 */
    P15_2_SCB3_SPI_CLK              = 25,       /* Digital Active - scb[3].spi_clk:0 */
    P15_2_SCB3_UART_RX              = 26,       /* Digital Active - scb[3].uart_rx:0 */
    P15_2_SCB3_I2C_SDA              = 27,       /* Digital Active - scb[3].i2c_sda:0 */

    /* P15.3 */
    P15_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_3_AMUXA                     =  4,       /* Analog mux bus A */
    P15_3_AMUXB                     =  5,       /* Analog mux bus B */
    P15_3_TCPWM0_LINE24             =  8,       /* Digital Active - tcpwm[0].line[24]:0 */
    P15_3_TCPWM0_LINE_COMPL30       =  9,       /* Digital Active - tcpwm[0].line_compl[30]:0 */
    P15_3_TCPWM0_TR_ONE_CNT_IN29    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[29]:0 */
    P15_3_VIDEOSS0_TTL_CAP0_DATA12  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[12]:1 */
    P15_3_VIDEOSS0_TTL_CAP0_DATA7   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[7]:0 */
    P15_3_VIDEOSS0_TTL_DSP1_DATA_A03 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[3]:0 */
    P15_3_SCB3_SPI_MOSI             = 25,       /* Digital Active - scb[3].spi_mosi:0 */
    P15_3_SCB3_UART_TX              = 26,       /* Digital Active - scb[3].uart_tx:0 */
    P15_3_SCB3_I2C_SCL              = 27,       /* Digital Active - scb[3].i2c_scl:0 */

    /* P15.4 */
    P15_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_4_AMUXA                     =  4,       /* Analog mux bus A */
    P15_4_AMUXB                     =  5,       /* Analog mux bus B */
    P15_4_TCPWM0_LINE25             =  8,       /* Digital Active - tcpwm[0].line[25]:0 */
    P15_4_TCPWM0_LINE_COMPL23       =  9,       /* Digital Active - tcpwm[0].line_compl[23]:0 */
    P15_4_TCPWM0_TR_ONE_CNT_IN30    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[30]:0 */
    P15_4_VIDEOSS0_TTL_CAP0_DATA13  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[13]:1 */
    P15_4_VIDEOSS0_TTL_CAP0_DATA6   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[6]:0 */
    P15_4_VIDEOSS0_TTL_DSP1_DATA_A12 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[2]:0 */
    P15_4_SCB3_SPI_MISO             = 25,       /* Digital Active - scb[3].spi_miso:0 */
    P15_4_SCB3_UART_RTS             = 26,       /* Digital Active - scb[3].uart_rts:0 */

    /* P15.5 */
    P15_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_5_AMUXA                     =  4,       /* Analog mux bus A */
    P15_5_AMUXB                     =  5,       /* Analog mux bus B */
    P15_5_TCPWM0_LINE26             =  8,       /* Digital Active - tcpwm[0].line[26]:0 */
    P15_5_TCPWM0_LINE_COMPL24       =  9,       /* Digital Active - tcpwm[0].line_compl[24]:0 */
    P15_5_TCPWM0_TR_ONE_CNT_IN23    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[23]:0 */
    P15_5_VIDEOSS0_TTL_CAP0_DATA14  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[14]:1 */
    P15_5_VIDEOSS0_TTL_CAP0_DATA5   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[5]:0 */
    P15_5_VIDEOSS0_TTL_DSP1_DATA_A02 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[2]:0 */
    P15_5_SCB3_SPI_SELECT0          = 25,       /* Digital Active - scb[3].spi_select0:0 */
    P15_5_SCB3_UART_CTS             = 26,       /* Digital Active - scb[3].uart_cts:0 */

    /* P15.6 */
    P15_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_6_AMUXA                     =  4,       /* Analog mux bus A */
    P15_6_AMUXB                     =  5,       /* Analog mux bus B */
    P15_6_TCPWM0_LINE27             =  8,       /* Digital Active - tcpwm[0].line[27]:0 */
    P15_6_TCPWM0_LINE_COMPL25       =  9,       /* Digital Active - tcpwm[0].line_compl[25]:0 */
    P15_6_TCPWM0_TR_ONE_CNT_IN24    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[24]:0 */
    P15_6_VIDEOSS0_TTL_CAP0_DATA15  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[15]:1 */
    P15_6_VIDEOSS0_TTL_CAP0_DATA4   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[4]:0 */
    P15_6_VIDEOSS0_TTL_DSP1_DATA_A11 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[1]:0 */
    P15_6_SCB3_SPI_SELECT1          = 25,       /* Digital Active - scb[3].spi_select1:0 */

    /* P15.7 */
    P15_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P15_7_AMUXA                     =  4,       /* Analog mux bus A */
    P15_7_AMUXB                     =  5,       /* Analog mux bus B */
    P15_7_TCPWM0_LINE28             =  8,       /* Digital Active - tcpwm[0].line[28]:0 */
    P15_7_TCPWM0_LINE_COMPL26       =  9,       /* Digital Active - tcpwm[0].line_compl[26]:0 */
    P15_7_TCPWM0_TR_ONE_CNT_IN25    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[25]:0 */
    P15_7_VIDEOSS0_TTL_CAP0_DATA16  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[16]:1 */
    P15_7_VIDEOSS0_TTL_CAP0_DATA3   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[3]:0 */
    P15_7_VIDEOSS0_TTL_DSP1_DATA_A01 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[1]:0 */
    P15_7_SCB4_SPI_CLK              = 25,       /* Digital Active - scb[4].spi_clk:0 */
    P15_7_SCB4_UART_RX              = 26,       /* Digital Active - scb[4].uart_rx:0 */
    P15_7_SCB4_I2C_SDA              = 27,       /* Digital Active - scb[4].i2c_sda:0 */

    /* P16.0 */
    P16_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_0_AMUXA                     =  4,       /* Analog mux bus A */
    P16_0_AMUXB                     =  5,       /* Analog mux bus B */
    P16_0_TCPWM0_LINE29             =  8,       /* Digital Active - tcpwm[0].line[29]:0 */
    P16_0_TCPWM0_LINE_COMPL27       =  9,       /* Digital Active - tcpwm[0].line_compl[27]:0 */
    P16_0_TCPWM0_TR_ONE_CNT_IN26    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[26]:0 */
    P16_0_VIDEOSS0_TTL_CAP0_DATA17  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[17]:1 */
    P16_0_VIDEOSS0_TTL_CAP0_DATA2   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[2]:0 */
    P16_0_VIDEOSS0_TTL_DSP1_DATA_A10 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[0]:0 */
    P16_0_SCB4_SPI_MOSI             = 25,       /* Digital Active - scb[4].spi_mosi:0 */
    P16_0_SCB4_UART_TX              = 26,       /* Digital Active - scb[4].uart_tx:0 */
    P16_0_SCB4_I2C_SCL              = 27,       /* Digital Active - scb[4].i2c_scl:0 */

    /* P16.1 */
    P16_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_1_AMUXA                     =  4,       /* Analog mux bus A */
    P16_1_AMUXB                     =  5,       /* Analog mux bus B */
    P16_1_TCPWM0_LINE30             =  8,       /* Digital Active - tcpwm[0].line[30]:0 */
    P16_1_TCPWM0_LINE_COMPL28       =  9,       /* Digital Active - tcpwm[0].line_compl[28]:0 */
    P16_1_TCPWM0_TR_ONE_CNT_IN27    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[27]:0 */
    P16_1_VIDEOSS0_TTL_CAP0_DATA18  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[18]:1 */
    P16_1_VIDEOSS0_TTL_CAP0_DATA1   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[1]:0 */
    P16_1_VIDEOSS0_TTL_DSP1_DATA_A00 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[0]:0 */
    P16_1_SCB4_SPI_MISO             = 25,       /* Digital Active - scb[4].spi_miso:0 */
    P16_1_SCB4_UART_RTS             = 26,       /* Digital Active - scb[4].uart_rts:0 */

    /* P16.2 */
    P16_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_2_AMUXA                     =  4,       /* Analog mux bus A */
    P16_2_AMUXB                     =  5,       /* Analog mux bus B */
    P16_2_TCPWM0_LINE31             =  8,       /* Digital Active - tcpwm[0].line[31]:0 */
    P16_2_TCPWM0_LINE_COMPL37       =  9,       /* Digital Active - tcpwm[0].line_compl[37]:0 */
    P16_2_TCPWM0_TR_ONE_CNT_IN36    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[36]:0 */
    P16_2_TDM0_TDM_RX_MCK2          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[2]:0 */
    P16_2_VIDEOSS0_TTL_CAP0_DATA19  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[19]:1 */
    P16_2_PWM0_PWM_LINE1_P0         = 21,       /* Digital Active - pwm[0].pwm_line1_p[0]:2 */
    P16_2_SRSS_EXT_CLK              = 22,       /* Digital Active - srss.ext_clk:2 */
    P16_2_VIDEOSS0_TTL_CAP0_DATA0   = 23,       /* Digital Active - videoss[0].ttl_cap0_data[0]:0 */
    P16_2_VIDEOSS0_TTL_DSP1_CLOCK   = 24,       /* Digital Active - videoss[0].ttl_dsp1_clock:0 */
    P16_2_SCB4_SPI_SELECT0          = 25,       /* Digital Active - scb[4].spi_select0:0 */
    P16_2_SCB4_UART_CTS             = 26,       /* Digital Active - scb[4].uart_cts:0 */

    /* P16.3 */
    P16_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_3_AMUXA                     =  4,       /* Analog mux bus A */
    P16_3_AMUXB                     =  5,       /* Analog mux bus B */
    P16_3_TCPWM0_LINE32             =  8,       /* Digital Active - tcpwm[0].line[32]:0 */
    P16_3_TCPWM0_LINE_COMPL31       =  9,       /* Digital Active - tcpwm[0].line_compl[31]:0 */
    P16_3_TCPWM0_TR_ONE_CNT_IN37    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[37]:0 */
    P16_3_TDM0_TDM_RX_SCK2          = 17,       /* Digital Active - tdm[0].tdm_rx_sck[2]:0 */
    P16_3_VIDEOSS0_TTL_CAP0_DATA20  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[20]:1 */
    P16_3_PWM0_PWM_LINE1_N0         = 21,       /* Digital Active - pwm[0].pwm_line1_n[0]:2 */
    P16_3_SRSS_DDFT_CLK_DIRECT      = 22,       /* Digital Active - srss.ddft_clk_direct */
    P16_3_VIDEOSS0_TTL_CAP0_DATA24  = 23,       /* Digital Active - videoss[0].ttl_cap0_data[24]:0 */
    P16_3_VIDEOSS0_TTL_DSP1_CONTROL0 = 24,      /* Digital Active - videoss[0].ttl_dsp1_control[0]:0 */
    P16_3_SCB4_SPI_SELECT1          = 25,       /* Digital Active - scb[4].spi_select1:0 */

    /* P16.4 */
    P16_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_4_AMUXA                     =  4,       /* Analog mux bus A */
    P16_4_AMUXB                     =  5,       /* Analog mux bus B */
    P16_4_TCPWM0_LINE33             =  8,       /* Digital Active - tcpwm[0].line[33]:0 */
    P16_4_TCPWM0_LINE_COMPL32       =  9,       /* Digital Active - tcpwm[0].line_compl[32]:0 */
    P16_4_TCPWM0_TR_ONE_CNT_IN31    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[31]:0 */
    P16_4_TDM0_TDM_RX_FSYNC2        = 17,       /* Digital Active - tdm[0].tdm_rx_fsync[2]:0 */
    P16_4_VIDEOSS0_TTL_CAP0_DATA21  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[21]:1 */
    P16_4_PWM0_PWM_LINE2_P0         = 21,       /* Digital Active - pwm[0].pwm_line2_p[0]:2 */
    P16_4_SRSS_IO_CLK_HF5           = 22,       /* Digital Active - srss.io_clk_hf[5]:0 */
    P16_4_VIDEOSS0_TTL_CAP0_DATA25  = 23,       /* Digital Active - videoss[0].ttl_cap0_data[25]:0 */
    P16_4_VIDEOSS0_TTL_DSP1_CONTROL1 = 24,      /* Digital Active - videoss[0].ttl_dsp1_control[1]:0 */
    P16_4_VIDEOSS0_TTL_DSP1_CONTROL2 = 25,      /* Digital Active - videoss[0].ttl_dsp1_control[2]:1 */
    P16_4_VIDEOSS0_FPDLINK_CLKREF_GPIO = 27,    /* Digital Active - videoss[0].fpdlink_clkref_gpio */

    /* P16.5 */
    P16_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_5_AMUXA                     =  4,       /* Analog mux bus A */
    P16_5_AMUXB                     =  5,       /* Analog mux bus B */
    P16_5_TCPWM0_LINE34             =  8,       /* Digital Active - tcpwm[0].line[34]:0 */
    P16_5_TCPWM0_LINE_COMPL33       =  9,       /* Digital Active - tcpwm[0].line_compl[33]:0 */
    P16_5_TCPWM0_TR_ONE_CNT_IN32    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[32]:0 */
    P16_5_TDM0_TDM_RX_SD2           = 17,       /* Digital Active - tdm[0].tdm_rx_sd[2]:0 */
    P16_5_VIDEOSS0_TTL_CAP0_DATA22  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[22]:1 */
    P16_5_PWM0_PWM_LINE2_N0         = 21,       /* Digital Active - pwm[0].pwm_line2_n[0]:2 */
    P16_5_VIDEOSS0_TTL_CAP0_DATA26  = 23,       /* Digital Active - videoss[0].ttl_cap0_data[26]:0 */
    P16_5_SCB5_SPI_SELECT1          = 24,       /* Digital Active - scb[5].spi_select1:0 */
    P16_5_VIDEOSS0_TTL_DSP1_CONTROL2 = 25,      /* Digital Active - videoss[0].ttl_dsp1_control[2]:0 */

    /* P16.6 */
    P16_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P16_6_AMUXA                     =  4,       /* Analog mux bus A */
    P16_6_AMUXB                     =  5,       /* Analog mux bus B */
    P16_6_TCPWM0_LINE35             =  8,       /* Digital Active - tcpwm[0].line[35]:0 */
    P16_6_TCPWM0_LINE_COMPL34       =  9,       /* Digital Active - tcpwm[0].line_compl[34]:0 */
    P16_6_TCPWM0_TR_ONE_CNT_IN33    = 10,       /* Digital Active - tcpwm[0].tr_one_cnt_in[33]:0 */
    P16_6_TDM0_TDM_TX_MCK2          = 16,       /* Digital Active - tdm[0].tdm_tx_mck[2]:1 */
    P16_6_TDM0_TDM_RX_MCK3          = 17,       /* Digital Active - tdm[0].tdm_rx_mck[3]:0 */
    P16_6_VIDEOSS0_TTL_CAP0_DATA23  = 18,       /* Digital Active - videoss[0].ttl_cap0_data[23]:1 */
    P16_6_PWM0_PWM_LINE1_P1         = 21,       /* Digital Active - pwm[0].pwm_line1_p[1]:2 */
    P16_6_VIDEOSS0_TTL_DSP1_CONTROL11 = 24,     /* Digital Active - videoss[0].ttl_dsp1_control[11]:0 */
    P16_6_SCB5_SPI_CLK              = 25,       /* Digital Active - scb[5].spi_clk:0 */
    P16_6_SCB5_UART_RX              = 26,       /* Digital Active - scb[5].uart_rx:0 */
    P16_6_SCB5_I2C_SDA              = 27,       /* Digital Active - scb[5].i2c_sda:0 */

    /* P18.0 */
    P18_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_0_AMUXA                     =  4,       /* Analog mux bus A */
    P18_0_AMUXB                     =  5,       /* Analog mux bus B */
    P18_0_SCB9_SPI_CLK              = 20,       /* Digital Active - scb[9].spi_clk:0 */
    P18_0_SCB9_UART_RX              = 21,       /* Digital Active - scb[9].uart_rx:0 */
    P18_0_SCB9_I2C_SDA              = 22,       /* Digital Active - scb[9].i2c_sda:0 */
    P18_0_SMIF0_SPIHB_DATA4         = 27,       /* Digital Active - smif[0].spihb_data4 */

    /* P18.1 */
    P18_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_1_AMUXA                     =  4,       /* Analog mux bus A */
    P18_1_AMUXB                     =  5,       /* Analog mux bus B */
    P18_1_SCB9_SPI_MOSI             = 20,       /* Digital Active - scb[9].spi_mosi:0 */
    P18_1_SCB9_UART_TX              = 21,       /* Digital Active - scb[9].uart_tx:0 */
    P18_1_SCB9_I2C_SCL              = 22,       /* Digital Active - scb[9].i2c_scl:0 */
    P18_1_SMIF0_SPIHB_DATA2         = 27,       /* Digital Active - smif[0].spihb_data2 */

    /* P18.2 */
    P18_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_2_AMUXA                     =  4,       /* Analog mux bus A */
    P18_2_AMUXB                     =  5,       /* Analog mux bus B */
    P18_2_SCB9_SPI_MISO             = 20,       /* Digital Active - scb[9].spi_miso:0 */
    P18_2_SCB9_UART_RTS             = 21,       /* Digital Active - scb[9].uart_rts:0 */
    P18_2_SMIF0_SPIHB_DATA3         = 27,       /* Digital Active - smif[0].spihb_data3 */

    /* P18.3 */
    P18_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_3_AMUXA                     =  4,       /* Analog mux bus A */
    P18_3_AMUXB                     =  5,       /* Analog mux bus B */
    P18_3_SCB9_SPI_SELECT0          = 20,       /* Digital Active - scb[9].spi_select0:0 */
    P18_3_SCB9_UART_CTS             = 21,       /* Digital Active - scb[9].uart_cts:0 */
    P18_3_SMIF0_SPIHB_DATA5         = 27,       /* Digital Active - smif[0].spihb_data5 */

    /* P18.4 */
    P18_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_4_AMUXA                     =  4,       /* Analog mux bus A */
    P18_4_AMUXB                     =  5,       /* Analog mux bus B */
    P18_4_SCB10_SPI_CLK             = 20,       /* Digital Active - scb[10].spi_clk:0 */
    P18_4_SCB10_UART_RX             = 21,       /* Digital Active - scb[10].uart_rx:0 */
    P18_4_SCB10_I2C_SDA             = 22,       /* Digital Active - scb[10].i2c_sda:0 */
    P18_4_SMIF0_SPIHB_DATA0         = 27,       /* Digital Active - smif[0].spihb_data0 */

    /* P18.5 */
    P18_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_5_AMUXA                     =  4,       /* Analog mux bus A */
    P18_5_AMUXB                     =  5,       /* Analog mux bus B */
    P18_5_SCB10_SPI_MOSI            = 20,       /* Digital Active - scb[10].spi_mosi:0 */
    P18_5_SCB10_UART_TX             = 21,       /* Digital Active - scb[10].uart_tx:0 */
    P18_5_SCB10_I2C_SCL             = 22,       /* Digital Active - scb[10].i2c_scl:0 */
    P18_5_SMIF0_SPIHB_DATA6         = 27,       /* Digital Active - smif[0].spihb_data6 */

    /* P18.6 */
    P18_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_6_AMUXA                     =  4,       /* Analog mux bus A */
    P18_6_AMUXB                     =  5,       /* Analog mux bus B */
    P18_6_SCB10_SPI_MISO            = 20,       /* Digital Active - scb[10].spi_miso:0 */
    P18_6_SCB10_UART_RTS            = 21,       /* Digital Active - scb[10].uart_rts:0 */
    P18_6_SMIF0_SPIHB_DATA1         = 27,       /* Digital Active - smif[0].spihb_data1 */

    /* P18.7 */
    P18_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P18_7_AMUXA                     =  4,       /* Analog mux bus A */
    P18_7_AMUXB                     =  5,       /* Analog mux bus B */
    P18_7_SCB10_SPI_SELECT0         = 20,       /* Digital Active - scb[10].spi_select0:0 */
    P18_7_SCB10_UART_CTS            = 21,       /* Digital Active - scb[10].uart_cts:0 */
    P18_7_SMIF0_SPIHB_DATA7         = 27,       /* Digital Active - smif[0].spihb_data7 */

    /* P19.0 */
    P19_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_0_AMUXA                     =  4,       /* Analog mux bus A */
    P19_0_AMUXB                     =  5,       /* Analog mux bus B */
    P19_0_SCB11_SPI_CLK             = 20,       /* Digital Active - scb[11].spi_clk:0 */
    P19_0_SCB11_UART_RX             = 21,       /* Digital Active - scb[11].uart_rx:0 */
    P19_0_SCB11_I2C_SDA             = 22,       /* Digital Active - scb[11].i2c_sda:0 */
    P19_0_SMIF0_SPIHB_CLK           = 27,       /* Digital Active - smif[0].spihb_clk */

    /* P19.1 */
    P19_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_1_AMUXA                     =  4,       /* Analog mux bus A */
    P19_1_AMUXB                     =  5,       /* Analog mux bus B */
    P19_1_SCB11_SPI_MOSI            = 20,       /* Digital Active - scb[11].spi_mosi:0 */
    P19_1_SCB11_UART_TX             = 21,       /* Digital Active - scb[11].uart_tx:0 */
    P19_1_SCB11_I2C_SCL             = 22,       /* Digital Active - scb[11].i2c_scl:0 */
    P19_1_SMIF0_SPIHB_RWDS          = 27,       /* Digital Active - smif[0].spihb_rwds */

    /* P19.2 */
    P19_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_2_AMUXA                     =  4,       /* Analog mux bus A */
    P19_2_AMUXB                     =  5,       /* Analog mux bus B */
    P19_2_SCB11_SPI_MISO            = 20,       /* Digital Active - scb[11].spi_miso:0 */
    P19_2_SCB11_UART_RTS            = 21,       /* Digital Active - scb[11].uart_rts:0 */
    P19_2_SMIF0_SPIHB_SELECT0       = 27,       /* Digital Active - smif[0].spihb_select0 */

    /* P19.3 */
    P19_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P19_3_AMUXA                     =  4,       /* Analog mux bus A */
    P19_3_AMUXB                     =  5,       /* Analog mux bus B */
    P19_3_SCB11_SPI_SELECT0         = 20,       /* Digital Active - scb[11].spi_select0:0 */
    P19_3_SCB11_UART_CTS            = 21,       /* Digital Active - scb[11].uart_cts:0 */
    P19_3_SMIF0_SPIHB_SELECT1       = 27,       /* Digital Active - smif[0].spihb_select1 */

    /* P20.0 */
    P20_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_0_AMUXA                     =  4,       /* Analog mux bus A */
    P20_0_AMUXB                     =  5,       /* Analog mux bus B */
    P20_0_SMIF1_SPIHB_DATA4         = 11,       /* Digital Active - smif[1].spihb_data4 */

    /* P20.1 */
    P20_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_1_AMUXA                     =  4,       /* Analog mux bus A */
    P20_1_AMUXB                     =  5,       /* Analog mux bus B */
    P20_1_SMIF1_SPIHB_DATA2         = 11,       /* Digital Active - smif[1].spihb_data2 */

    /* P20.2 */
    P20_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_2_AMUXA                     =  4,       /* Analog mux bus A */
    P20_2_AMUXB                     =  5,       /* Analog mux bus B */
    P20_2_SMIF1_SPIHB_DATA3         = 11,       /* Digital Active - smif[1].spihb_data3 */

    /* P20.3 */
    P20_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_3_AMUXA                     =  4,       /* Analog mux bus A */
    P20_3_AMUXB                     =  5,       /* Analog mux bus B */
    P20_3_SMIF1_SPIHB_DATA5         = 11,       /* Digital Active - smif[1].spihb_data5 */
    P20_3_VIDEOSS0_TTL_DSP1_CONTROL2 = 25,      /* Digital Active - videoss[0].ttl_dsp1_control[2]:4 */

    /* P20.4 */
    P20_4_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_4_AMUXA                     =  4,       /* Analog mux bus A */
    P20_4_AMUXB                     =  5,       /* Analog mux bus B */
    P20_4_SMIF1_SPIHB_DATA0         = 11,       /* Digital Active - smif[1].spihb_data0 */
    P20_4_VIDEOSS0_TTL_DSP1_DATA_A111 = 24,     /* Digital Active - videoss[0].ttl_dsp1_data_a1[11]:2 */

    /* P20.5 */
    P20_5_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_5_AMUXA                     =  4,       /* Analog mux bus A */
    P20_5_AMUXB                     =  5,       /* Analog mux bus B */
    P20_5_SMIF1_SPIHB_DATA6         = 11,       /* Digital Active - smif[1].spihb_data6 */
    P20_5_VIDEOSS0_TTL_DSP1_DATA_A011 = 24,     /* Digital Active - videoss[0].ttl_dsp1_data_a0[11]:2 */

    /* P20.6 */
    P20_6_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_6_AMUXA                     =  4,       /* Analog mux bus A */
    P20_6_AMUXB                     =  5,       /* Analog mux bus B */
    P20_6_SMIF1_SPIHB_DATA1         = 11,       /* Digital Active - smif[1].spihb_data1 */
    P20_6_VIDEOSS0_TTL_DSP1_DATA_A110 = 24,     /* Digital Active - videoss[0].ttl_dsp1_data_a1[10]:2 */

    /* P20.7 */
    P20_7_GPIO                      =  0,       /* GPIO controls 'out' */
    P20_7_AMUXA                     =  4,       /* Analog mux bus A */
    P20_7_AMUXB                     =  5,       /* Analog mux bus B */
    P20_7_SMIF1_SPIHB_DATA7         = 11,       /* Digital Active - smif[1].spihb_data7 */
    P20_7_VIDEOSS0_TTL_DSP1_DATA_A010 = 24,     /* Digital Active - videoss[0].ttl_dsp1_data_a0[10]:2 */

    /* P21.0 */
    P21_0_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_0_AMUXA                     =  4,       /* Analog mux bus A */
    P21_0_AMUXB                     =  5,       /* Analog mux bus B */
    P21_0_SMIF1_SPIHB_CLK           = 11,       /* Digital Active - smif[1].spihb_clk */
    P21_0_VIDEOSS0_TTL_DSP1_DATA_A19 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[9]:2 */

    /* P21.1 */
    P21_1_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_1_AMUXA                     =  4,       /* Analog mux bus A */
    P21_1_AMUXB                     =  5,       /* Analog mux bus B */
    P21_1_SMIF1_SPIHB_RWDS          = 11,       /* Digital Active - smif[1].spihb_rwds */
    P21_1_VIDEOSS0_TTL_DSP1_DATA_A09 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a0[9]:2 */

    /* P21.2 */
    P21_2_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_2_AMUXA                     =  4,       /* Analog mux bus A */
    P21_2_AMUXB                     =  5,       /* Analog mux bus B */
    P21_2_SMIF1_SPIHB_SELECT0       = 11,       /* Digital Active - smif[1].spihb_select0 */
    P21_2_VIDEOSS0_TTL_DSP1_DATA_A18 = 24,      /* Digital Active - videoss[0].ttl_dsp1_data_a1[8]:2 */

    /* P21.3 */
    P21_3_GPIO                      =  0,       /* GPIO controls 'out' */
    P21_3_AMUXA                     =  4,       /* Analog mux bus A */
    P21_3_AMUXB                     =  5,       /* Analog mux bus B */
    P21_3_SMIF1_SPIHB_SELECT1       = 11,       /* Digital Active - smif[1].spihb_select1 */
    P21_3_VIDEOSS0_TTL_DSP1_DATA_A08 = 24       /* Digital Active - videoss[0].ttl_dsp1_data_a0[8]:2 */
} en_hsiom_sel_t;

#endif /* _GPIO_TVIIC2D4M_216_TEQFP_H_ */


/* [] END OF FILE */
