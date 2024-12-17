/***************************************************************************//**
* \file cyip_tcpwm.h
*
* \brief
* TCPWM IP definitions
*
********************************************************************************
* \copyright
* (c) (2016-2024), Cypress Semiconductor Corporation (an Infineon company) or
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

#ifndef _CYIP_TCPWM_H_
#define _CYIP_TCPWM_H_

#include "cyip_headers.h"

/*******************************************************************************
*                                    TCPWM
*******************************************************************************/

#define TCPWM_GRP_CNT_SECTION_SIZE              0x00000100UL
#define TCPWM_GRP_SECTION_SIZE                  0x00010000UL
#define TCPWM_TR_ALL_GF_SECTION_SIZE            0x00000400UL
#define TCPWM_TR_ALL_SYNC_BYPASS_SECTION_SIZE   0x00000040UL
#define TCPWM_MOTIF_GRP_MOTIF_SECTION_SIZE      0x00000200UL
#define TCPWM_MOTIF_GRP_SECTION_SIZE            0x00004000UL
#define TCPWM_SECTION_SIZE                      0x00100000UL

/**
  * \brief Timer/Counter/PWM Counter Module (TCPWM_GRP_CNT)
  */
typedef struct {
  __IOM uint32_t CTRL;                          /*!< 0x00000000 Counter control register */
   __IM uint32_t STATUS;                        /*!< 0x00000004 Counter status register */
  __IOM uint32_t COUNTER;                       /*!< 0x00000008 Counter count register */
   __IM uint32_t RESERVED;
  __IOM uint32_t CC0;                           /*!< 0x00000010 Counter compare/capture 0 register */
  __IOM uint32_t CC0_BUFF;                      /*!< 0x00000014 Counter buffered compare/capture 0 register */
  __IOM uint32_t CC1;                           /*!< 0x00000018 Counter compare/capture 1 register */
  __IOM uint32_t CC1_BUFF;                      /*!< 0x0000001C Counter buffered compare/capture 1 register */
  __IOM uint32_t PERIOD;                        /*!< 0x00000020 Counter period register */
  __IOM uint32_t PERIOD_BUFF;                   /*!< 0x00000024 Counter buffered period register */
  __IOM uint32_t LINE_SEL;                      /*!< 0x00000028 Counter line selection register */
  __IOM uint32_t LINE_SEL_BUFF;                 /*!< 0x0000002C Counter buffered line selection register */
  __IOM uint32_t DT;                            /*!< 0x00000030 Counter PWM dead time register */
  __IOM uint32_t DT_BUFF;                       /*!< 0x00000034 Counter buffered PWM dead time register */
  __IOM uint32_t PS;                            /*!< 0x00000038 Counter prescalar register */
   __IM uint32_t RESERVED1;
  __IOM uint32_t TR_CMD;                        /*!< 0x00000040 Counter trigger command register */
  __IOM uint32_t TR_IN_SEL0;                    /*!< 0x00000044 Counter input trigger selection register 0 */
  __IOM uint32_t TR_IN_SEL1;                    /*!< 0x00000048 Counter input trigger selection register 1 */
  __IOM uint32_t TR_IN_EDGE_SEL;                /*!< 0x0000004C Counter input trigger edge selection register */
  __IOM uint32_t TR_PWM_CTRL;                   /*!< 0x00000050 Counter trigger PWM control register */
  __IOM uint32_t TR_OUT_SEL;                    /*!< 0x00000054 Counter output trigger selection register */
   __IM uint32_t RESERVED2[6];
  __IOM uint32_t INTR;                          /*!< 0x00000070 Interrupt request register */
  __IOM uint32_t INTR_SET;                      /*!< 0x00000074 Interrupt set request register */
  __IOM uint32_t INTR_MASK;                     /*!< 0x00000078 Interrupt mask register */
   __IM uint32_t INTR_MASKED;                   /*!< 0x0000007C Interrupt masked request register */
  __IOM uint32_t LFSR;                          /*!< 0x00000080 LFSR register */
  __IOM uint32_t ONE_GF[8];                     /*!< 0x00000084 Glitch filter register for one to one trigger */
  __IOM uint32_t TR_ONE_SYNC_BYPASS;            /*!< 0x000000A4 Sync bypass register for one to one trigger */
   __IM uint32_t RESERVED3[2];
  __IOM uint32_t HRPWM_CTRL;                    /*!< 0x000000B0 Counter control register for HRPWM feature */
   __IM uint32_t RESERVED4[19];
} TCPWM_GRP_CNT_Type;                           /*!< Size = 256 (0x100) */

/**
  * \brief Group of counters (TCPWM_GRP)
  */
typedef struct {
        TCPWM_GRP_CNT_Type CNT[256];            /*!< 0x00000000 Timer/Counter/PWM Counter Module */
} TCPWM_GRP_Type;                               /*!< Size = 65536 (0x10000) */

/**
  * \brief Glitch filter module for group trigger (TCPWM_TR_ALL_GF)
  */
typedef struct {
  __IOM uint32_t ALL_GF[254];                   /*!< 0x00000000 Glitch filter register for All Group Triggers */
   __IM uint32_t RESERVED[2];
} TCPWM_TR_ALL_GF_Type;                         /*!< Size = 1024 (0x400) */

/**
  * \brief Glitch filter module for group trigger (TCPWM_TR_ALL_SYNC_BYPASS)
  */
typedef struct {
  __IOM uint32_t TR_ALL_SYNC_BYPASS[8];         /*!< 0x00000000 Trigger Sync bypass for group trigger */
   __IM uint32_t RESERVED[8];
} TCPWM_TR_ALL_SYNC_BYPASS_Type;                /*!< Size = 64 (0x40) */

/**
  * \brief MOTIF Module (TCPWM_MOTIF_GRP_MOTIF)
  */
typedef struct {
  __IOM uint32_t PCONF;                         /*!< 0x00000000 Global control register */
  __IOM uint32_t PSUS;                          /*!< 0x00000004 Suspend Configuration */
  __IOM uint32_t PRUNS;                         /*!< 0x00000008 MOTIF run bit set */
   __IM uint32_t RESERVED;
   __IM uint32_t PRUN;                          /*!< 0x00000010 MOTIF run bit status */
   __IM uint32_t RESERVED1[4];
   __OM uint32_t HIST;                          /*!< 0x00000024 Hall Inputs Sample Trigger */
  __IOM uint32_t HMEC;                          /*!< 0x00000028 Hall Mode Extra Config */
   __IM uint32_t RESERVED2;
   __IM uint32_t HALP;                          /*!< 0x00000030 Hall Current and Expected patterns */
  __IOM uint32_t HALPS;                         /*!< 0x00000034 Hall Current and Expected shadow patterns */
  __IOM uint32_t HOSC;                          /*!< 0x00000038 Hall Sensor Output Config */
   __IM uint32_t RESERVED3;
   __IM uint32_t MCM;                           /*!< 0x00000040 Multi-Channel Mode Pattern */
  __IOM uint32_t MCSM;                          /*!< 0x00000044 Multi-Channel Mode shadow Pattern LUT0 */
   __OM uint32_t MCMS;                          /*!< 0x00000048 Multi-Channel Mode Control set */
   __OM uint32_t MCMC;                          /*!< 0x0000004C Multi-Channel Mode Control clear */
   __IM uint32_t MCMF;                          /*!< 0x00000050 Multi-Channel Mode flag status */
  __IOM uint32_t MCPF;                          /*!< 0x00000054 Multi-Channel Pattern Fault */
  __IOM uint32_t MOSC;                          /*!< 0x00000058 Multi-Channel Output Config */
   __IM uint32_t RESERVED4;
  __IOM uint32_t QDC;                           /*!< 0x00000060 Quadrature Decoder Configuration */
  __IOM uint32_t QOSC;                          /*!< 0x00000064 Quadrature Output Config */
  __IOM uint32_t MCMEC;                         /*!< 0x00000068 Multi-Channel Extra Config */
   __IM uint32_t RESERVED5;
   __IM uint32_t PFLG;                          /*!< 0x00000070 MOTIF interrupt status */
  __IOM uint32_t PFLGE;                         /*!< 0x00000074 MOTIF interrupt enable */
   __OM uint32_t SPFLG;                         /*!< 0x00000078 Interrupt set register */
   __OM uint32_t RPFLG;                         /*!< 0x0000007C Interrupt clear register */
  __IOM uint32_t MCSM1;                         /*!< 0x00000080 Multi-Channel Mode shadow pattern LUT1 */
  __IOM uint32_t MCSM2;                         /*!< 0x00000084 Multi-Channel Mode shadow pattern LUT2 */
  __IOM uint32_t MCSM3;                         /*!< 0x00000088 Multi-Channel Mode shadow pattern LUT3 */
  __IOM uint32_t MCSM4;                         /*!< 0x0000008C Multi-Channel Mode shadow pattern LUT4 */
  __IOM uint32_t MCSM5;                         /*!< 0x00000090 Multi-Channel Mode shadow pattern LUT5 */
  __IOM uint32_t CLUT;                          /*!< 0x00000094 Hall Mode LUT config */
   __IM uint32_t SLUT;                          /*!< 0x00000098 Hall Mode LUT status */
   __IM uint32_t RESERVED6[25];
   __IM uint32_t PDBG;                          /*!< 0x00000100 MOTIF Debug Register */
   __IM uint32_t PLP0S;                         /*!< 0x00000104 MOTIF Low Pass 0 Status */
   __IM uint32_t PLP1S;                         /*!< 0x00000108 MOTIF Low Pass 1 Status */
   __IM uint32_t PLP2S;                         /*!< 0x0000010C MOTIF Low Pass 2 Status */
   __IM uint32_t RESERVED7[60];
} TCPWM_MOTIF_GRP_MOTIF_Type;                   /*!< Size = 512 (0x200) */

/**
  * \brief Trigger Sync bypass for group trigger (TCPWM_MOTIF_GRP)
  */
typedef struct {
        TCPWM_MOTIF_GRP_MOTIF_Type MOTIF[32];   /*!< 0x00000000 MOTIF Module */
} TCPWM_MOTIF_GRP_Type;                         /*!< Size = 16384 (0x4000) */

/**
  * \brief S40 Timer/Counter/PWM (TCPWM)
  */
typedef struct {
        TCPWM_GRP_Type GRP[8];                  /*!< 0x00000000 Group of counters */
        TCPWM_TR_ALL_GF_Type TR_ALL_GF;         /*!< 0x00080000 Glitch filter module for group trigger */
   __IM uint32_t RESERVED[16128];
        TCPWM_TR_ALL_SYNC_BYPASS_Type TR_ALL_SYNC_BYPASS; /*!< 0x00090000 Glitch filter module for group trigger */
   __IM uint32_t RESERVED1[16368];
        TCPWM_MOTIF_GRP_Type MOTIF_GRP[8];      /*!< 0x000A0000 Trigger Sync bypass for group trigger */
} TCPWM_Type;                                   /*!< Size = 786432 (0xC0000) */


/* TCPWM_GRP_CNT.CTRL */
#define TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC0_Pos  0UL
#define TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC0_Msk  0x1UL
#define TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC1_Pos  1UL
#define TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_CC1_Msk  0x2UL
#define TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_PERIOD_Pos 2UL
#define TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_PERIOD_Msk 0x4UL
#define TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_LINE_SEL_Pos 3UL
#define TCPWM_GRP_CNT_CTRL_AUTO_RELOAD_LINE_SEL_Msk 0x8UL
#define TCPWM_GRP_CNT_CTRL_CC0_MATCH_UP_EN_Pos  4UL
#define TCPWM_GRP_CNT_CTRL_CC0_MATCH_UP_EN_Msk  0x10UL
#define TCPWM_GRP_CNT_CTRL_CC0_MATCH_DOWN_EN_Pos 5UL
#define TCPWM_GRP_CNT_CTRL_CC0_MATCH_DOWN_EN_Msk 0x20UL
#define TCPWM_GRP_CNT_CTRL_CC1_MATCH_UP_EN_Pos  6UL
#define TCPWM_GRP_CNT_CTRL_CC1_MATCH_UP_EN_Msk  0x40UL
#define TCPWM_GRP_CNT_CTRL_CC1_MATCH_DOWN_EN_Pos 7UL
#define TCPWM_GRP_CNT_CTRL_CC1_MATCH_DOWN_EN_Msk 0x80UL
#define TCPWM_GRP_CNT_CTRL_PWM_IMM_KILL_Pos     8UL
#define TCPWM_GRP_CNT_CTRL_PWM_IMM_KILL_Msk     0x100UL
#define TCPWM_GRP_CNT_CTRL_PWM_STOP_ON_KILL_Pos 9UL
#define TCPWM_GRP_CNT_CTRL_PWM_STOP_ON_KILL_Msk 0x200UL
#define TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_Pos    10UL
#define TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_Msk    0x400UL
#define TCPWM_GRP_CNT_CTRL_SWAP_ENABLE_Pos      11UL
#define TCPWM_GRP_CNT_CTRL_SWAP_ENABLE_Msk      0x800UL
#define TCPWM_GRP_CNT_CTRL_PWM_DISABLE_MODE_Pos 12UL
#define TCPWM_GRP_CNT_CTRL_PWM_DISABLE_MODE_Msk 0x3000UL
#define TCPWM_GRP_CNT_CTRL_PWM_TC_SYNC_KILL_DT_Pos 14UL
#define TCPWM_GRP_CNT_CTRL_PWM_TC_SYNC_KILL_DT_Msk 0x4000UL
#define TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_DT_Pos 15UL
#define TCPWM_GRP_CNT_CTRL_PWM_SYNC_KILL_DT_Msk 0x8000UL
#define TCPWM_GRP_CNT_CTRL_UP_DOWN_MODE_Pos     16UL
#define TCPWM_GRP_CNT_CTRL_UP_DOWN_MODE_Msk     0x30000UL
#define TCPWM_GRP_CNT_CTRL_ONE_SHOT_Pos         18UL
#define TCPWM_GRP_CNT_CTRL_ONE_SHOT_Msk         0x40000UL
#define TCPWM_GRP_CNT_CTRL_QUAD_ENCODING_MODE_Pos 20UL
#define TCPWM_GRP_CNT_CTRL_QUAD_ENCODING_MODE_Msk 0x300000UL
#define TCPWM_GRP_CNT_CTRL_DITHEREN_Pos         22UL
#define TCPWM_GRP_CNT_CTRL_DITHEREN_Msk         0xC00000UL
#define TCPWM_GRP_CNT_CTRL_MODE_Pos             24UL
#define TCPWM_GRP_CNT_CTRL_MODE_Msk             0x7000000UL
#define TCPWM_GRP_CNT_CTRL_KILL_LINE_POLARITY_Pos 27UL
#define TCPWM_GRP_CNT_CTRL_KILL_LINE_POLARITY_Msk 0x18000000UL
#define TCPWM_GRP_CNT_CTRL_DBG_SUS_EN_Pos       29UL
#define TCPWM_GRP_CNT_CTRL_DBG_SUS_EN_Msk       0x20000000UL
#define TCPWM_GRP_CNT_CTRL_DBG_FREEZE_EN_Pos    30UL
#define TCPWM_GRP_CNT_CTRL_DBG_FREEZE_EN_Msk    0x40000000UL
#define TCPWM_GRP_CNT_CTRL_ENABLED_Pos          31UL
#define TCPWM_GRP_CNT_CTRL_ENABLED_Msk          0x80000000UL
/* TCPWM_GRP_CNT.STATUS */
#define TCPWM_GRP_CNT_STATUS_DOWN_Pos           0UL
#define TCPWM_GRP_CNT_STATUS_DOWN_Msk           0x1UL
#define TCPWM_GRP_CNT_STATUS_CC0_READ_MISS_Pos  1UL
#define TCPWM_GRP_CNT_STATUS_CC0_READ_MISS_Msk  0x2UL
#define TCPWM_GRP_CNT_STATUS_CC1_READ_MISS_Pos  2UL
#define TCPWM_GRP_CNT_STATUS_CC1_READ_MISS_Msk  0x4UL
#define TCPWM_GRP_CNT_STATUS_KILL_STATUS_Pos    3UL
#define TCPWM_GRP_CNT_STATUS_KILL_STATUS_Msk    0x8UL
#define TCPWM_GRP_CNT_STATUS_TR_CAPTURE0_Pos    4UL
#define TCPWM_GRP_CNT_STATUS_TR_CAPTURE0_Msk    0x10UL
#define TCPWM_GRP_CNT_STATUS_TR_COUNT_Pos       5UL
#define TCPWM_GRP_CNT_STATUS_TR_COUNT_Msk       0x20UL
#define TCPWM_GRP_CNT_STATUS_TR_RELOAD_Pos      6UL
#define TCPWM_GRP_CNT_STATUS_TR_RELOAD_Msk      0x40UL
#define TCPWM_GRP_CNT_STATUS_TR_STOP_Pos        7UL
#define TCPWM_GRP_CNT_STATUS_TR_STOP_Msk        0x80UL
#define TCPWM_GRP_CNT_STATUS_TR_START_Pos       8UL
#define TCPWM_GRP_CNT_STATUS_TR_START_Msk       0x100UL
#define TCPWM_GRP_CNT_STATUS_TR_CAPTURE1_Pos    9UL
#define TCPWM_GRP_CNT_STATUS_TR_CAPTURE1_Msk    0x200UL
#define TCPWM_GRP_CNT_STATUS_LINE_OUT_Pos       10UL
#define TCPWM_GRP_CNT_STATUS_LINE_OUT_Msk       0x400UL
#define TCPWM_GRP_CNT_STATUS_LINE_COMPL_OUT_Pos 11UL
#define TCPWM_GRP_CNT_STATUS_LINE_COMPL_OUT_Msk 0x800UL
#define TCPWM_GRP_CNT_STATUS_RUNNING_Pos        15UL
#define TCPWM_GRP_CNT_STATUS_RUNNING_Msk        0x8000UL
#define TCPWM_GRP_CNT_STATUS_DT_CNT_L_Pos       16UL
#define TCPWM_GRP_CNT_STATUS_DT_CNT_L_Msk       0xFF0000UL
#define TCPWM_GRP_CNT_STATUS_DT_CNT_H_Pos       24UL
#define TCPWM_GRP_CNT_STATUS_DT_CNT_H_Msk       0xFF000000UL
/* TCPWM_GRP_CNT.COUNTER */
#define TCPWM_GRP_CNT_COUNTER_COUNTER_Pos       0UL
#define TCPWM_GRP_CNT_COUNTER_COUNTER_Msk       0xFFFFFFFFUL
/* TCPWM_GRP_CNT.CC0 */
#define TCPWM_GRP_CNT_CC0_CC_Pos                0UL
#define TCPWM_GRP_CNT_CC0_CC_Msk                0xFFFFFFFFUL
/* TCPWM_GRP_CNT.CC0_BUFF */
#define TCPWM_GRP_CNT_CC0_BUFF_CC_Pos           0UL
#define TCPWM_GRP_CNT_CC0_BUFF_CC_Msk           0xFFFFFFFFUL
/* TCPWM_GRP_CNT.CC1 */
#define TCPWM_GRP_CNT_CC1_CC_Pos                0UL
#define TCPWM_GRP_CNT_CC1_CC_Msk                0xFFFFFFFFUL
/* TCPWM_GRP_CNT.CC1_BUFF */
#define TCPWM_GRP_CNT_CC1_BUFF_CC_Pos           0UL
#define TCPWM_GRP_CNT_CC1_BUFF_CC_Msk           0xFFFFFFFFUL
/* TCPWM_GRP_CNT.PERIOD */
#define TCPWM_GRP_CNT_PERIOD_PERIOD_Pos         0UL
#define TCPWM_GRP_CNT_PERIOD_PERIOD_Msk         0xFFFFFFFFUL
/* TCPWM_GRP_CNT.PERIOD_BUFF */
#define TCPWM_GRP_CNT_PERIOD_BUFF_PERIOD_Pos    0UL
#define TCPWM_GRP_CNT_PERIOD_BUFF_PERIOD_Msk    0xFFFFFFFFUL
/* TCPWM_GRP_CNT.LINE_SEL */
#define TCPWM_GRP_CNT_LINE_SEL_OUT_SEL_Pos      0UL
#define TCPWM_GRP_CNT_LINE_SEL_OUT_SEL_Msk      0x7UL
#define TCPWM_GRP_CNT_LINE_SEL_COMPL_OUT_SEL_Pos 4UL
#define TCPWM_GRP_CNT_LINE_SEL_COMPL_OUT_SEL_Msk 0x70UL
/* TCPWM_GRP_CNT.LINE_SEL_BUFF */
#define TCPWM_GRP_CNT_LINE_SEL_BUFF_OUT_SEL_Pos 0UL
#define TCPWM_GRP_CNT_LINE_SEL_BUFF_OUT_SEL_Msk 0x7UL
#define TCPWM_GRP_CNT_LINE_SEL_BUFF_COMPL_OUT_SEL_Pos 4UL
#define TCPWM_GRP_CNT_LINE_SEL_BUFF_COMPL_OUT_SEL_Msk 0x70UL
/* TCPWM_GRP_CNT.DT */
#define TCPWM_GRP_CNT_DT_DT_LINE_OUT_L_Pos      0UL
#define TCPWM_GRP_CNT_DT_DT_LINE_OUT_L_Msk      0xFFUL
#define TCPWM_GRP_CNT_DT_DT_LINE_OUT_H_Pos      8UL
#define TCPWM_GRP_CNT_DT_DT_LINE_OUT_H_Msk      0xFF00UL
#define TCPWM_GRP_CNT_DT_DT_LINE_COMPL_OUT_Pos  16UL
#define TCPWM_GRP_CNT_DT_DT_LINE_COMPL_OUT_Msk  0xFFFF0000UL
/* TCPWM_GRP_CNT.DT_BUFF */
#define TCPWM_GRP_CNT_DT_BUFF_DT_LINE_OUT_L_Pos 0UL
#define TCPWM_GRP_CNT_DT_BUFF_DT_LINE_OUT_L_Msk 0xFFUL
#define TCPWM_GRP_CNT_DT_BUFF_DT_LINE_OUT_H_Pos 8UL
#define TCPWM_GRP_CNT_DT_BUFF_DT_LINE_OUT_H_Msk 0xFF00UL
#define TCPWM_GRP_CNT_DT_BUFF_DT_LINE_COMPL_OUT_Pos 16UL
#define TCPWM_GRP_CNT_DT_BUFF_DT_LINE_COMPL_OUT_Msk 0xFFFF0000UL
/* TCPWM_GRP_CNT.PS */
#define TCPWM_GRP_CNT_PS_PS_DIV_Pos             0UL
#define TCPWM_GRP_CNT_PS_PS_DIV_Msk             0x7UL
/* TCPWM_GRP_CNT.TR_CMD */
#define TCPWM_GRP_CNT_TR_CMD_CAPTURE0_Pos       0UL
#define TCPWM_GRP_CNT_TR_CMD_CAPTURE0_Msk       0x1UL
#define TCPWM_GRP_CNT_TR_CMD_RELOAD_Pos         2UL
#define TCPWM_GRP_CNT_TR_CMD_RELOAD_Msk         0x4UL
#define TCPWM_GRP_CNT_TR_CMD_STOP_Pos           3UL
#define TCPWM_GRP_CNT_TR_CMD_STOP_Msk           0x8UL
#define TCPWM_GRP_CNT_TR_CMD_START_Pos          4UL
#define TCPWM_GRP_CNT_TR_CMD_START_Msk          0x10UL
#define TCPWM_GRP_CNT_TR_CMD_CAPTURE1_Pos       5UL
#define TCPWM_GRP_CNT_TR_CMD_CAPTURE1_Msk       0x20UL
/* TCPWM_GRP_CNT.TR_IN_SEL0 */
#define TCPWM_GRP_CNT_TR_IN_SEL0_CAPTURE0_SEL_Pos 0UL
#define TCPWM_GRP_CNT_TR_IN_SEL0_CAPTURE0_SEL_Msk 0xFFUL
#define TCPWM_GRP_CNT_TR_IN_SEL0_COUNT_SEL_Pos  8UL
#define TCPWM_GRP_CNT_TR_IN_SEL0_COUNT_SEL_Msk  0xFF00UL
#define TCPWM_GRP_CNT_TR_IN_SEL0_RELOAD_SEL_Pos 16UL
#define TCPWM_GRP_CNT_TR_IN_SEL0_RELOAD_SEL_Msk 0xFF0000UL
#define TCPWM_GRP_CNT_TR_IN_SEL0_STOP_SEL_Pos   24UL
#define TCPWM_GRP_CNT_TR_IN_SEL0_STOP_SEL_Msk   0xFF000000UL
/* TCPWM_GRP_CNT.TR_IN_SEL1 */
#define TCPWM_GRP_CNT_TR_IN_SEL1_START_SEL_Pos  0UL
#define TCPWM_GRP_CNT_TR_IN_SEL1_START_SEL_Msk  0xFFUL
#define TCPWM_GRP_CNT_TR_IN_SEL1_CAPTURE1_SEL_Pos 8UL
#define TCPWM_GRP_CNT_TR_IN_SEL1_CAPTURE1_SEL_Msk 0xFF00UL
/* TCPWM_GRP_CNT.TR_IN_EDGE_SEL */
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Pos 0UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE0_EDGE_Msk 0x3UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_COUNT_EDGE_Pos 2UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_COUNT_EDGE_Msk 0xCUL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_RELOAD_EDGE_Pos 4UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_RELOAD_EDGE_Msk 0x30UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_STOP_EDGE_Pos 6UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_STOP_EDGE_Msk 0xC0UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_START_EDGE_Pos 8UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_START_EDGE_Msk 0x300UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Pos 10UL
#define TCPWM_GRP_CNT_TR_IN_EDGE_SEL_CAPTURE1_EDGE_Msk 0xC00UL
/* TCPWM_GRP_CNT.TR_PWM_CTRL */
#define TCPWM_GRP_CNT_TR_PWM_CTRL_CC0_MATCH_MODE_Pos 0UL
#define TCPWM_GRP_CNT_TR_PWM_CTRL_CC0_MATCH_MODE_Msk 0x3UL
#define TCPWM_GRP_CNT_TR_PWM_CTRL_OVERFLOW_MODE_Pos 2UL
#define TCPWM_GRP_CNT_TR_PWM_CTRL_OVERFLOW_MODE_Msk 0xCUL
#define TCPWM_GRP_CNT_TR_PWM_CTRL_UNDERFLOW_MODE_Pos 4UL
#define TCPWM_GRP_CNT_TR_PWM_CTRL_UNDERFLOW_MODE_Msk 0x30UL
#define TCPWM_GRP_CNT_TR_PWM_CTRL_CC1_MATCH_MODE_Pos 6UL
#define TCPWM_GRP_CNT_TR_PWM_CTRL_CC1_MATCH_MODE_Msk 0xC0UL
/* TCPWM_GRP_CNT.TR_OUT_SEL */
#define TCPWM_GRP_CNT_TR_OUT_SEL_OUT0_Pos       0UL
#define TCPWM_GRP_CNT_TR_OUT_SEL_OUT0_Msk       0x7UL
#define TCPWM_GRP_CNT_TR_OUT_SEL_OUT1_Pos       4UL
#define TCPWM_GRP_CNT_TR_OUT_SEL_OUT1_Msk       0x70UL
/* TCPWM_GRP_CNT.INTR */
#define TCPWM_GRP_CNT_INTR_TC_Pos               0UL
#define TCPWM_GRP_CNT_INTR_TC_Msk               0x1UL
#define TCPWM_GRP_CNT_INTR_CC0_MATCH_Pos        1UL
#define TCPWM_GRP_CNT_INTR_CC0_MATCH_Msk        0x2UL
#define TCPWM_GRP_CNT_INTR_CC1_MATCH_Pos        2UL
#define TCPWM_GRP_CNT_INTR_CC1_MATCH_Msk        0x4UL
/* TCPWM_GRP_CNT.INTR_SET */
#define TCPWM_GRP_CNT_INTR_SET_TC_Pos           0UL
#define TCPWM_GRP_CNT_INTR_SET_TC_Msk           0x1UL
#define TCPWM_GRP_CNT_INTR_SET_CC0_MATCH_Pos    1UL
#define TCPWM_GRP_CNT_INTR_SET_CC0_MATCH_Msk    0x2UL
#define TCPWM_GRP_CNT_INTR_SET_CC1_MATCH_Pos    2UL
#define TCPWM_GRP_CNT_INTR_SET_CC1_MATCH_Msk    0x4UL
/* TCPWM_GRP_CNT.INTR_MASK */
#define TCPWM_GRP_CNT_INTR_MASK_TC_Pos          0UL
#define TCPWM_GRP_CNT_INTR_MASK_TC_Msk          0x1UL
#define TCPWM_GRP_CNT_INTR_MASK_CC0_MATCH_Pos   1UL
#define TCPWM_GRP_CNT_INTR_MASK_CC0_MATCH_Msk   0x2UL
#define TCPWM_GRP_CNT_INTR_MASK_CC1_MATCH_Pos   2UL
#define TCPWM_GRP_CNT_INTR_MASK_CC1_MATCH_Msk   0x4UL
/* TCPWM_GRP_CNT.INTR_MASKED */
#define TCPWM_GRP_CNT_INTR_MASKED_TC_Pos        0UL
#define TCPWM_GRP_CNT_INTR_MASKED_TC_Msk        0x1UL
#define TCPWM_GRP_CNT_INTR_MASKED_CC0_MATCH_Pos 1UL
#define TCPWM_GRP_CNT_INTR_MASKED_CC0_MATCH_Msk 0x2UL
#define TCPWM_GRP_CNT_INTR_MASKED_CC1_MATCH_Pos 2UL
#define TCPWM_GRP_CNT_INTR_MASKED_CC1_MATCH_Msk 0x4UL
/* TCPWM_GRP_CNT.LFSR */
#define TCPWM_GRP_CNT_LFSR_PLFSR_Pos            0UL
#define TCPWM_GRP_CNT_LFSR_PLFSR_Msk            0xFFUL
#define TCPWM_GRP_CNT_LFSR_DLFSR_Pos            8UL
#define TCPWM_GRP_CNT_LFSR_DLFSR_Msk            0xFF00UL
#define TCPWM_GRP_CNT_LFSR_LIMITER_Pos          16UL
#define TCPWM_GRP_CNT_LFSR_LIMITER_Msk          0x70000UL
/* TCPWM_GRP_CNT.ONE_GF */
#define TCPWM_GRP_CNT_ONE_GF_GF_DEPTH_Pos       0UL
#define TCPWM_GRP_CNT_ONE_GF_GF_DEPTH_Msk       0x7UL
#define TCPWM_GRP_CNT_ONE_GF_GFPS_DIV_Pos       3UL
#define TCPWM_GRP_CNT_ONE_GF_GFPS_DIV_Msk       0x18UL
/* TCPWM_GRP_CNT.TR_ONE_SYNC_BYPASS */
#define TCPWM_GRP_CNT_TR_ONE_SYNC_BYPASS_SYNC_BYPASS_Pos 0UL
#define TCPWM_GRP_CNT_TR_ONE_SYNC_BYPASS_SYNC_BYPASS_Msk 0xFFUL
/* TCPWM_GRP_CNT.HRPWM_CTRL */
#define TCPWM_GRP_CNT_HRPWM_CTRL_HRPWM_EN_Pos   0UL
#define TCPWM_GRP_CNT_HRPWM_CTRL_HRPWM_EN_Msk   0x1UL
#define TCPWM_GRP_CNT_HRPWM_CTRL_DATA_IN_CC0_EN_Pos 3UL
#define TCPWM_GRP_CNT_HRPWM_CTRL_DATA_IN_CC0_EN_Msk 0x8UL
#define TCPWM_GRP_CNT_HRPWM_CTRL_DATA_IN_CC1_EN_Pos 4UL
#define TCPWM_GRP_CNT_HRPWM_CTRL_DATA_IN_CC1_EN_Msk 0x10UL
#define TCPWM_GRP_CNT_HRPWM_CTRL_FREQ_SEL_Pos   5UL
#define TCPWM_GRP_CNT_HRPWM_CTRL_FREQ_SEL_Msk   0x60UL


/* TCPWM_TR_ALL_GF.ALL_GF */
#define TCPWM_TR_ALL_GF_ALL_GF_GF_DEPTH_Pos     0UL
#define TCPWM_TR_ALL_GF_ALL_GF_GF_DEPTH_Msk     0x7UL
#define TCPWM_TR_ALL_GF_ALL_GF_GFPS_DIV_Pos     3UL
#define TCPWM_TR_ALL_GF_ALL_GF_GFPS_DIV_Msk     0x18UL


/* TCPWM_TR_ALL_SYNC_BYPASS.TR_ALL_SYNC_BYPASS */
#define TCPWM_TR_ALL_SYNC_BYPASS_TR_ALL_SYNC_BYPASS_SYNC_BYPASS_Pos 0UL
#define TCPWM_TR_ALL_SYNC_BYPASS_TR_ALL_SYNC_BYPASS_SYNC_BYPASS_Msk 0xFFFFFFFFUL


/* TCPWM_MOTIF_GRP_MOTIF.PCONF */
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_ENABLE_Pos  0UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_ENABLE_Msk  0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_FSEL_Pos    1UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_FSEL_Msk    0x6UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_QDCM_Pos    3UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_QDCM_Msk    0x8UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_HIDG_Pos    4UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_HIDG_Msk    0x10UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_MCUE_Pos    5UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_MCUE_Msk    0x20UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_FTS_Pos     6UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_FTS_Msk     0xC0UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_CHEC_Pos    14UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_CHEC_Msk    0xC000UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_SPES_Pos    17UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_SPES_Msk    0x20000UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_MSES_Pos    21UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_MSES_Msk    0x200000UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_MSYES_Pos   22UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_MSYES_Msk   0x400000UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_EWIE_Pos    26UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_EWIE_Msk    0x4000000UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_EWIL_Pos    27UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_EWIL_Msk    0x8000000UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_LPC_Pos     28UL
#define TCPWM_MOTIF_GRP_MOTIF_PCONF_LPC_Msk     0xF0000000UL
/* TCPWM_MOTIF_GRP_MOTIF.PSUS */
#define TCPWM_MOTIF_GRP_MOTIF_PSUS_SUS_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_PSUS_SUS_Msk      0x7UL
/* TCPWM_MOTIF_GRP_MOTIF.PRUNS */
#define TCPWM_MOTIF_GRP_MOTIF_PRUNS_SRB_Pos     0UL
#define TCPWM_MOTIF_GRP_MOTIF_PRUNS_SRB_Msk     0x1UL
/* TCPWM_MOTIF_GRP_MOTIF.PRUN */
#define TCPWM_MOTIF_GRP_MOTIF_PRUN_RB_Pos       0UL
#define TCPWM_MOTIF_GRP_MOTIF_PRUN_RB_Msk       0x1UL
/* TCPWM_MOTIF_GRP_MOTIF.HIST */
#define TCPWM_MOTIF_GRP_MOTIF_HIST_HIS_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_HIST_HIS_Msk      0x1UL
/* TCPWM_MOTIF_GRP_MOTIF.HMEC */
#define TCPWM_MOTIF_GRP_MOTIF_HMEC_HDBP_Pos     0UL
#define TCPWM_MOTIF_GRP_MOTIF_HMEC_HDBP_Msk     0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_HMEC_HPPE_Pos     1UL
#define TCPWM_MOTIF_GRP_MOTIF_HMEC_HPPE_Msk     0x2UL
/* TCPWM_MOTIF_GRP_MOTIF.HALP */
#define TCPWM_MOTIF_GRP_MOTIF_HALP_HCP_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_HALP_HCP_Msk      0x7UL
#define TCPWM_MOTIF_GRP_MOTIF_HALP_HEP_Pos      3UL
#define TCPWM_MOTIF_GRP_MOTIF_HALP_HEP_Msk      0x38UL
#define TCPWM_MOTIF_GRP_MOTIF_HALP_HPP_Pos      8UL
#define TCPWM_MOTIF_GRP_MOTIF_HALP_HPP_Msk      0x700UL
/* TCPWM_MOTIF_GRP_MOTIF.HALPS */
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HCPS0_Pos   0UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HCPS0_Msk   0x7UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HEPS1_Pos   3UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HEPS1_Msk   0x38UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HPPS2_Pos   8UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HPPS2_Msk   0x700UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT3_Pos   16UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT3_Msk   0x70000UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT4_Pos   19UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT4_Msk   0x380000UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT5_Pos   24UL
#define TCPWM_MOTIF_GRP_MOTIF_HALPS_HLUT5_Msk   0x7000000UL
/* TCPWM_MOTIF_GRP_MOTIF.HOSC */
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_EDN_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_EDN_Msk      0x7UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_CHN_Pos      4UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_CHN_Msk      0x70UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_IDN_Pos      8UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_IDN_Msk      0x700UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_HSTN_Pos     12UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_HSTN_Msk     0x7000UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_SPN_Pos      16UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_SPN_Msk      0x70000UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_CPN_Pos      20UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_CPN_Msk      0x700000UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_PPN_Pos      24UL
#define TCPWM_MOTIF_GRP_MOTIF_HOSC_PPN_Msk      0x7000000UL
/* TCPWM_MOTIF_GRP_MOTIF.MCM */
#define TCPWM_MOTIF_GRP_MOTIF_MCM_MCMP_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCM_MCMP_Msk      0xFFFFFFFFUL
/* TCPWM_MOTIF_GRP_MOTIF.MCSM */
#define TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCSM_MCMPS_Msk    0xFFFFFFFFUL
/* TCPWM_MOTIF_GRP_MOTIF.MCMS */
#define TCPWM_MOTIF_GRP_MOTIF_MCMS_MNPS_Pos     0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMS_MNPS_Msk     0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMS_STHR_Pos     1UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMS_STHR_Msk     0x2UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMS_STMR_Pos     2UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMS_STMR_Msk     0x4UL
/* TCPWM_MOTIF_GRP_MOTIF.MCMC */
#define TCPWM_MOTIF_GRP_MOTIF_MCMC_MNPC_Pos     0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMC_MNPC_Msk     0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMC_MPC_Pos      1UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMC_MPC_Msk      0x2UL
/* TCPWM_MOTIF_GRP_MOTIF.MCMF */
#define TCPWM_MOTIF_GRP_MOTIF_MCMF_MSS_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMF_MSS_Msk      0x1UL
/* TCPWM_MOTIF_GRP_MOTIF.MCPF */
#define TCPWM_MOTIF_GRP_MOTIF_MCPF_MCFV_Pos     0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCPF_MCFV_Msk     0xFFFFFFFFUL
/* TCPWM_MOTIF_GRP_MOTIF.MOSC */
#define TCPWM_MOTIF_GRP_MOTIF_MOSC_PUN_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_MOSC_PUN_Msk      0x7UL
#define TCPWM_MOTIF_GRP_MOTIF_MOSC_SHN_Pos      4UL
#define TCPWM_MOTIF_GRP_MOTIF_MOSC_SHN_Msk      0x70UL
#define TCPWM_MOTIF_GRP_MOTIF_MOSC_MSTN_Pos     8UL
#define TCPWM_MOTIF_GRP_MOTIF_MOSC_MSTN_Msk     0x700UL
/* TCPWM_MOTIF_GRP_MOTIF.QDC */
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PALS_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PALS_Msk      0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PBLS_Pos      1UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PBLS_Msk      0x2UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PHS_Pos       2UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PHS_Msk       0x4UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_INDS_Pos      3UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_INDS_Msk      0x8UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_ICM_Pos       4UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_ICM_Msk       0x30UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_DVAL_Pos      8UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_DVAL_Msk      0x100UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PAEM_Pos      12UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PAEM_Msk      0x3000UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PBEM_Pos      14UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PBEM_Msk      0xC000UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PACS_Pos      16UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PACS_Msk      0x30000UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PBDS_Pos      20UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_PBDS_Msk      0x300000UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_IDS_Pos       24UL
#define TCPWM_MOTIF_GRP_MOTIF_QDC_IDS_Msk       0x3000000UL
/* TCPWM_MOTIF_GRP_MOTIF.QOSC */
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_QCN_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_QCN_Msk      0x7UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_DON_Pos      4UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_DON_Msk      0x70UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_PCN_Pos      8UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_PCN_Msk      0x700UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_CCN_Pos      12UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_CCN_Msk      0x7000UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_IXN_Pos      16UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_IXN_Msk      0x70000UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_QSTN_Pos     20UL
#define TCPWM_MOTIF_GRP_MOTIF_QOSC_QSTN_Msk     0x700000UL
/* TCPWM_MOTIF_GRP_MOTIF.MCMEC */
#define TCPWM_MOTIF_GRP_MOTIF_MCMEC_MSBP_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMEC_MSBP_Msk    0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMEC_MEBP_Pos    1UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMEC_MEBP_Msk    0x2UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMEC_MFCE_Pos    4UL
#define TCPWM_MOTIF_GRP_MOTIF_MCMEC_MFCE_Msk    0x10UL
/* TCPWM_MOTIF_GRP_MOTIF.PFLG */
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_CHES_Pos     0UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_CHES_Msk     0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_WHES_Pos     1UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_WHES_Msk     0x2UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_HIES_Pos     2UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_HIES_Msk     0x4UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_MSTS_Pos     4UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_MSTS_Msk     0x10UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_INDXS_Pos    8UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_INDXS_Msk    0x100UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_ERRS_Pos     9UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_ERRS_Msk     0x200UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_CNTS_Pos     10UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_CNTS_Msk     0x400UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_DIRS_Pos     11UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_DIRS_Msk     0x800UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_PCLKS_Pos    12UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_PCLKS_Msk    0x1000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_CPES_Pos     13UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_CPES_Msk     0x2000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_PPES_Pos     14UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLG_PPES_Msk     0x4000UL
/* TCPWM_MOTIF_GRP_MOTIF.PFLGE */
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_ECHE_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_ECHE_Msk    0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EWHE_Pos    1UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EWHE_Msk    0x2UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EHIE_Pos    2UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EHIE_Msk    0x4UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EMST_Pos    4UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EMST_Msk    0x10UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EINDX_Pos   8UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EINDX_Msk   0x100UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EERR_Pos    9UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EERR_Msk    0x200UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_ECNT_Pos    10UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_ECNT_Msk    0x400UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EDIR_Pos    11UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EDIR_Msk    0x800UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EPCLK_Pos   12UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EPCLK_Msk   0x1000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_ECPE_Pos    13UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_ECPE_Msk    0x2000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EPPE_Pos    14UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_EPPE_Msk    0x4000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_CHESEL_Pos  16UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_CHESEL_Msk  0x10000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_WHESEL_Pos  17UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_WHESEL_Msk  0x20000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_HIESEL_Pos  18UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_HIESEL_Msk  0x40000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_MSTSEL_Pos  20UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_MSTSEL_Msk  0x100000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_INDSEL_Pos  24UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_INDSEL_Msk  0x1000000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_ERRSEL_Pos  25UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_ERRSEL_Msk  0x2000000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_CNTSEL_Pos  26UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_CNTSEL_Msk  0x4000000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_DIRSEL_Pos  27UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_DIRSEL_Msk  0x8000000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_PCLSEL_Pos  28UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_PCLSEL_Msk  0x10000000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_CPSEL_Pos   29UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_CPSEL_Msk   0x20000000UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_PPSEL_Pos   30UL
#define TCPWM_MOTIF_GRP_MOTIF_PFLGE_PPSEL_Msk   0x40000000UL
/* TCPWM_MOTIF_GRP_MOTIF.SPFLG */
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SCHE_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SCHE_Msk    0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SWHE_Pos    1UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SWHE_Msk    0x2UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SHIE_Pos    2UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SHIE_Msk    0x4UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SMST_Pos    4UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SMST_Msk    0x10UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SINDX_Pos   8UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SINDX_Msk   0x100UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SERR_Pos    9UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SERR_Msk    0x200UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SCNT_Pos    10UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SCNT_Msk    0x400UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SDIR_Pos    11UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SDIR_Msk    0x800UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SPCLK_Pos   12UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SPCLK_Msk   0x1000UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SCP_Pos     13UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SCP_Msk     0x2000UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SPP_Pos     14UL
#define TCPWM_MOTIF_GRP_MOTIF_SPFLG_SPP_Msk     0x4000UL
/* TCPWM_MOTIF_GRP_MOTIF.RPFLG */
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RCHE_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RCHE_Msk    0x1UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RWHE_Pos    1UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RWHE_Msk    0x2UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RHIE_Pos    2UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RHIE_Msk    0x4UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RMST_Pos    4UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RMST_Msk    0x10UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RINDX_Pos   8UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RINDX_Msk   0x100UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RERR_Pos    9UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RERR_Msk    0x200UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RCNT_Pos    10UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RCNT_Msk    0x400UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RDIR_Pos    11UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RDIR_Msk    0x800UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RPCLK_Pos   12UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RPCLK_Msk   0x1000UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RCP_Pos     13UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RCP_Msk     0x2000UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RPP_Pos     14UL
#define TCPWM_MOTIF_GRP_MOTIF_RPFLG_RPP_Msk     0x4000UL
/* TCPWM_MOTIF_GRP_MOTIF.MCSM1 */
#define TCPWM_MOTIF_GRP_MOTIF_MCSM1_MLUT1_Pos   0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCSM1_MLUT1_Msk   0xFFFFFFFFUL
/* TCPWM_MOTIF_GRP_MOTIF.MCSM2 */
#define TCPWM_MOTIF_GRP_MOTIF_MCSM2_MLUT2_Pos   0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCSM2_MLUT2_Msk   0xFFFFFFFFUL
/* TCPWM_MOTIF_GRP_MOTIF.MCSM3 */
#define TCPWM_MOTIF_GRP_MOTIF_MCSM3_MLUT3_Pos   0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCSM3_MLUT3_Msk   0xFFFFFFFFUL
/* TCPWM_MOTIF_GRP_MOTIF.MCSM4 */
#define TCPWM_MOTIF_GRP_MOTIF_MCSM4_MLUT4_Pos   0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCSM4_MLUT4_Msk   0xFFFFFFFFUL
/* TCPWM_MOTIF_GRP_MOTIF.MCSM5 */
#define TCPWM_MOTIF_GRP_MOTIF_MCSM5_MLUT5_Pos   0UL
#define TCPWM_MOTIF_GRP_MOTIF_MCSM5_MLUT5_Msk   0xFFFFFFFFUL
/* TCPWM_MOTIF_GRP_MOTIF.CLUT */
#define TCPWM_MOTIF_GRP_MOTIF_CLUT_LUTEN_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_CLUT_LUTEN_Msk    0x1UL
/* TCPWM_MOTIF_GRP_MOTIF.SLUT */
#define TCPWM_MOTIF_GRP_MOTIF_SLUT_PTR_Pos      0UL
#define TCPWM_MOTIF_GRP_MOTIF_SLUT_PTR_Msk      0x7UL
/* TCPWM_MOTIF_GRP_MOTIF.PDBG */
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_QCSV_Pos     0UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_QCSV_Msk     0x7UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_QPSV_Pos     3UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_QPSV_Msk     0x38UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_IVAL_Pos     6UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_IVAL_Msk     0x40UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_HSP_Pos      8UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_HSP_Msk      0x700UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_LPF0V_Pos    12UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_LPF0V_Msk    0x1000UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_LPF1V_Pos    13UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_LPF1V_Msk    0x2000UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_LPF2V_Pos    14UL
#define TCPWM_MOTIF_GRP_MOTIF_PDBG_LPF2V_Msk    0x4000UL
/* TCPWM_MOTIF_GRP_MOTIF.PLP0S */
#define TCPWM_MOTIF_GRP_MOTIF_PLP0S_LPP0_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_PLP0S_LPP0_Msk    0x3FFUL
/* TCPWM_MOTIF_GRP_MOTIF.PLP1S */
#define TCPWM_MOTIF_GRP_MOTIF_PLP1S_LPP1_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_PLP1S_LPP1_Msk    0x3FFUL
/* TCPWM_MOTIF_GRP_MOTIF.PLP2S */
#define TCPWM_MOTIF_GRP_MOTIF_PLP2S_LPP2_Pos    0UL
#define TCPWM_MOTIF_GRP_MOTIF_PLP2S_LPP2_Msk    0x3FFUL


#endif /* _CYIP_TCPWM_H_ */


/* [] END OF FILE */