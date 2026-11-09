# MTB CAT1 Peripheral Driver Library v3.25.0

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.

## Implementation Details
* CAT1A: Added new TRAVEO&trade; T2G Body Entry QFN-48 MPNs: CYT2B62BAE, CYT2B62BAS, CYT2B62DAE, and CYT2B62DAS (CYT2B6, 576 KB flash), and CYT2B72BAE, CYT2B72BAS, CYT2B72DAE, and CYT2B72DAS (CYT2B7, 1088 KB flash).
* CAT1A: Added the tviibe512k_config.h device configuration header with the correct number of DMAC channels (CPUSS_DMAC_CH_NR = 2) for TRAVEO&trade; T2G Body Entry CYT2B6 devices. The existing CYT2B63, CYT2B64, and CYT2B65 device headers now include tviibe512k_config.h instead of tviibe1m_config.h (CPUSS_DMAC_CH_NR changed from 4 to 2).
* CAT1A: Regenerated the TRAVEO&trade; T2G Body Entry device configuration headers. The unused CPUSS_FLASHC_PRESENT and SRSS_NUM_TOTAL_PLL macros were removed from tviibe1m_config.h and tviibe2m_config.h (CPUSS_FLASHC_PRESENT is still defined as 1 by cy_device.h), PROT_START and PROT_END were added to the protection-region enumerations, and CY_GPIO_PACKAGE_LGA was added to the GPIO package-type enumeration.
* CAT1A: Regenerated the TRAVEO&trade; T2G Body Entry SVD files (tviibe1m.svd, tviibe2m.svd, tviibe4m.svd). The register map is unchanged; register properties are now inherited from device-level defaults, and the write behavior (oneToClear, oneToSet) of interrupt and status registers is described for debuggers.
* CAT1B: Fixed HPPASS register descriptions in psc3.svd and cyip_hppass.h (typo, and CLK_CSG cycle count in the timing example).

## Personality Changes
* Updated Personalities:
  * platform:
    * pin-4.0.cypersonality (Added DRC to avoid different pin versions on the same port)
    * tickclk-3.0.cypersonality (Fixed the generated CPU guard so that SysTick is initialized on the CM4 core of TRAVEO&trade; T2G Body Entry devices)
  * peripheral:
    * pwm_v2-1.0.cypersonality (Fixed typo errors)
    * lin-1.1.cypersonality (Hide LIN enable signals when no valid pin connection exists)
    * eth-1.0.cypersonality (Added RGMII configuration for CYT4DN Ethernet instance 0; added RTL8211FI, DP83848VV, and LAN8720A PHY selection support)

## Updated Drivers

* [ETHIF 1.60](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ethif.html) (Fixed RX buffer exhaustion handling and added RX error notification and queue recovery support.)
* [SCB 3.70](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__scb.html) (Added EZI2C hardware EZ mode APIs and fixed the EZI2C Deep Sleep wake-from-sleep defect.)
* [GPIO 1.150](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__gpio.html) (Fixed the port initialization order in Cy_GPIO_Port_Init().)
* [SMIF 2.150](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__smif.html) (Changed the type of the memSize member of cy_stc_smif_hbmem_device_config_t to uint32_t.)
* [SYSCLK 3.190](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysclk.html) (Fixed the PLL400M frequency calculation for CAT1C devices.)

## Known Issues

* TRAVEO&trade; CYT6BJ8DDE with the second flash controller (FLASHC1): Some SROM flash operations are not available or do not correctly target FLASHC1. In particular, work-flash programming through the native ProgramWorkFlash opcode, blank check, hash calculation, checksum targeting, and erase resume are affected; an unblocked FLASHC1 erase may fail. As a workaround for supported operations, use a PDL adaptation that selects the existing FLASHC1 opcodes by controller/address: ProgramRowStart2 (0x09) for row programming, EraseSectorStart2 (0x1C) for sector erase, and EraseSuspend2 (0x25) for erase suspend. Work-flash programming can be emulated with repeated 32-bit ProgramRowStart2 writes, subject to normal alignment and programming constraints. No workaround is currently available for FLASHC1 hash calculation, blank check, checksum, or erase resume; avoid relying on these APIs for FLASHC1 until the SROM support is fixed.
* Crypto: With Arm Compiler 6, Cy_Crypto_Core_Hkdf() may cause a HardFault (unaligned access) when the data cache is not enabled. The HMAC state in Cy_Crypto_Core_V2_Hkdf_Expand() is not 4-byte aligned on the stack. The workaround: add CY_ALIGN(4) to the stack arrays t_t, hmacState_t and hmacBuffer_t in cy_crypto_core_hkdf_v2.c.
* The System Clock diagram shows incorrect IMO and ILO clock source frequencies for the following device families: XMC5100, XMC5300, TRAVEO&trade; T2G CYT3DL, CYT4DN, CYT2BL, and CYT2CL. Refer to the respective device datasheets for the correct values.
* TRAVEO&trade; T2G CYT4DN: Some Fault numbers defined in cy_en_SysFault_source_t for CAT1C do not match the device fault numbers.
* CAT1A: In device-configurator, certain IP is not completely available for some devices as some combinations of pin connections are not valid.
  * CYT2BL4BAS/CYT2BL4CAE: SCB6 is complete only for UART, cannot support I2C, EZI2C, or SPI.
  * CYT2BL3CAE, CYT2B7CAE: SCB1 is complete only for UART, cannot support I2C, EZI2C, or SPI.
  * On the following devices: CAN FD 0 Channel 3, CAN FD 1 Channel 1, CAN FD 1 Channel 3 is not available (no signal for CAN Rx Pin available).
    * CYT2BL4BAS, CYT2BL3CAE, CYT2BL3CAS, CYT2BL4CAE, CYT2BL3BAE, CYT2BL4BAE, CYT2BL4CAS, CYT2BL3BAS, CYT2B73BAS, CYT2B73CAS, CYT2B73BAE
* TRAVEO&trade; T2G CYT2B7, CYT2B9, and CYT2BL: Does not support emulated eeprom.
* CAT1A: On soft reset, user need to reset back up domain using Cy_SysLib_ResetBackupDomain() to receive Cy_RTC_CenturyInterrupt() callback on Century roll over.
* On building with tools 2.2, user get warning related to the older version of tools used. To avoid this warning, user is advised to migrate to newer tools version or keep working with previous version of this library.  The warning generated is as follows:
  * _#warning "(Library) The referenced 'device support library' contains newer content than is supported. Either downgrade the version of the 'device support library' referenced or upgrade the version of tools being used_
* Design configuration will not be auto migrated from smartio-3.0.cypersonality to smartio-4.0.cypersonality. So, existing projects should use smartio-3.0.cypersonality. New projects can make use of smartio-4.0.cypersonality which includes additional improvements.
* PSOC C3:
  * Overriding Cy_SysLib_ProcessingFault() function in the Non-Secure application does not work.
  * DFU flow: P2_3 is not configurable in the Non-secure application. The workaround: Do not configure/use P2_3 in the design when moved to Non-Secure Trustzone.
  * The Serial Trace feature is not available on the PSOC C3.
  * The application may fault when it was configured to start from RAM.
  * There is a hardware issue related to HRPWM activation on TCPWM block. The workaround for the PSOC C3 device with HRPWM feature available is described in the Cy_TCPWM_PWM_Init() documentation. The device-configurator will generate appropriate code for TCPWM to activate HRPWM on the device on which this feature is available.
  * When the core is clocked from the FLL the device might goes to HardFault. The flash wait states are calculated for the best performance and accurate Core clock. The recommendation is to avoid clocking the core from the FLL clock.
  * Flash refresh feature is not working.


## Defect Fixes

* CYT2B CM0+ IAR linker: Fixed .cy_sharedmem placement to use application SRAM instead of SROM-reserved SRAM, consistent with GCC_ARM and ARM. This addresses a HardFault during runtime initialization when the Flash/SROM driver is linked. The fix is delivered in the linker script templates of mtb-template-cat1 v1.13.0 and in the BSPs generated from it.
* TRAVEO&trade; T2G Body Entry CM0+ startup (system_psoc6_cm0plus.c): Fixed PrepareSystemCallInfrastructure() being removed from the image by GCC 14. The SROM vector table was read through a constant pointer to address 0, so the IRQ0/IRQ1 SROM system call handlers were not installed and Flash/SROM API calls from the CM0+ and CM4 cores were not serviced. The fix is delivered in the startup templates of mtb-template-cat1 v1.13.0 and in the BSPs generated from it.
* ETHIF: Fixed invalid RX buffer access when no free receive buffers are available. Added an RX error callback and Cy_ETHIF_RxErrorResetAndRecover() for RX queue recovery after buffer exhaustion or overrun, with automatic recovery when no RX error callback is registered.
* SCB EZI2C: Fixed a Deep Sleep wake-from-sleep defect where an EZI2C slave configured with enableWakeFromSleep only enabled EC_AM_MODE, so the data phase was serviced by CPU-clocked EZ logic; a CPU EZ_DATA read then conflicted with the external access and returned 0xFF (INTR_RX.BLOCKED). The EZI2C block now stays internally clocked in Active/Sleep, and the Deep Sleep callback (Cy_SCB_EZI2C_DeepSleepCallback) enables EC_OP_MODE, EZ_MODE, and BLOCK before the Deep Sleep transition and clears them after wake, so the whole EZ transfer is serviced on the external clock during Deep Sleep. Applies to all CAT1 devices.
* GPIO: Fixed the port initialization order in Cy_GPIO_Port_Init(). HSIOM routing was applied after GPIO_PRT_CFG, so a pin with an output driver was briefly driven low as a GPIO before being routed to its peripheral, which produced a glitch on the line. The HSIOM registers are now written first, as in Cy_GPIO_Pin_Init().
* SMIF: Fixed the "enumerated type mixed with another type" warning reported by the IAR compiler for the generated HyperBus memory configuration code. The memSize member of cy_stc_smif_hbmem_device_config_t is now uint32_t; use values from cy_en_device_size_t to initialize it.
* SYSCLK: Fixed Cy_SysClk_Pll400MGetFrequency() on CAT1C devices, which always applied the fractional divider even when the fractional mode (FRAC_EN) was disabled.
* SYSCLK / CAT1A device support: Fixed MISRA C-2012 violations (Rules 8.4, 10.4 and 20.9) reported for TRAVEO&trade; T2G Body Entry devices without PLL400M (for example CYT2B72DAE).
* Fixed the tickclk-3.0 personality CPU guard so that SysTick is initialized on the CM4 core of TRAVEO&trade; T2G Body Entry devices.

See the Changelog section of each Driver in the [PDL API Reference](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/modules.html) for all fixes and updates.

## Supported Software and Tools

This version of PDL was validated for compatibility with the following Software and Tools:

| Software and Tools                                                            | Version      |
| :---                                                                          | :----        |
| ModusToolbox&trade;                                                           | 3.8.0        |
| [Infineon Core Library](https://github.com/Infineon/core-lib)                 | 1.8.0        |
| [Device Database](https://github.com/Infineon/device-db)                      | 4.41.0       |
| CMSIS                                                                         | 6.1.0        |
| GCC Compiler                                                                  | 14.2.1       |
| IAR Compiler                                                                  | 9.50.2       |
| ARM Compiler 6                                                                | 6.22.0       |
| FreeRTOS                                                                      | 10.6.202     |

## More information

* [Peripheral Driver Library README.md](./README.md)
* [Peripheral Driver Library API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [ModusToolbox Device Configurator Tool Guide](https://www.infineon.com/row/public/documents/30/44/infineon-infineon-device-configurator-user-guide-usermanual-en.pdf)
* [AN210781 Getting Started with PSOC 6 MCU with Bluetooth Low Energy (BLE) Connectivity](https://www.infineon.com/dgdl/Infineon-AN210781_Getting_Started_with_PSoC_6_MCU_with_Bluetooth_Low_Energy_(BLE)_Connectivity_on_PSoC_Creator-ApplicationNotes-v05_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0d311f536528)
* [PSOC 6](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/)
* [CYW20829](https://www.infineon.com/cms/en/product/promopages/airoc20829)
* [TRAVEO&trade; T2G body MCU family](https://www.infineon.com/products/microcontroller/32-bit-traveo-t2g-arm-cortex/for-body/)
* [TRAVEO&trade; T2G cluster MCU family](https://www.infineon.com/products/microcontroller/32-bit-traveo-t2g-arm-cortex/for-cluster/)
* [XMC7000](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc7000-industrial-microcontroller-arm-cortex-m7/)
* [Infineon](http://www.infineon.com)


---
© Infineon Technologies AG or an affiliate of Infineon Technologies AG, 2020-2026.
