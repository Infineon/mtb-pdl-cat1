# MTB CAT1 Peripheral Driver Library v3.23.0

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.

## Implementation Details
* Reduced memory footprint for PSOC C3 and CYW20829 devices

## Personality Changes

* Updated Personalities:
  * platform:
    * hfclk-3.0.cypersonality and hfclk-4.0.cypersonality (Made CY_CFG_SYSCLK_CLKHFX_FREQ_MHZ parameter public (where X is the CLKHF number), enabling access in user code)
    * pathmux-3.0.cypersonality (Added support for loop-based clock initialization to reduce code size. Applicable for PSOC C3 and CYW20829 devices.)
    * sysclock-3.0.cypersonality (Optimized clock initialization using loops instead of repetitive function calls, reducing memory consumption. Applicable for PSOC C3 and CYW20829 devices.)
    * power_v2-1.0.cypersonality (Refactored to use low-level functions for Power profile configuration, improving efficiency. Applicable for PSOC C3 and CYW20829 devices.)
    * imo-3.0.cypersonality (Updated IMO accuracy handling for PSOC C3 to deterministically report 2%, hid non-applicable trim controls, and excluded PSOC C3 from USB-trim guidance DRC.)

## Updated Drivers
* [SYSCLK 3.170](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysclk.html)
* [SYSPM 5.220](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syspm.html)
* [SYSLIB 3.110](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syslib.html)
* [ADCMIC 1.10.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__adcmic.html)
* [EFUSE 2.40.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__efuse.html)
* [FLASH 3.150.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__flash.html)
* [IPC 1.160.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ipc.html)
* [MCWDT 1.100.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__mcwdt.html)
* [MS_CTL 1.2.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ms__ctl.html)
* [MXSDIODEV 2.0.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sdiodev.html)
* [SMIF 2.140.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__smif.html)
* [USBFS 2.30.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__usbfs__dev__drv.html)
* [CRYPTO 2.150.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__crypto.html)

## Known Issues

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

* SYSLIB: Fixed CAT1B LCS decoding by masking the source register to 16 bits in `Cy_SysLib_GetDeviceLCS()`.

* Fixed IMO clock accuracy display for PSOC C3 devices by aligning effective IMO accuracy to +/-2% in Device Configurator and removing inconsistent trim-dependent behavior.
* Fixed CAT1B PSC3 FLL max output frequency limit in device headers from 96 MHz to 100 MHz, aligning with TRM and avoiding incorrect `BAD_PARAM` results in SYSCLK FLL configuration for valid frequencies.
* Documentation update: removed Cypress mentions from driver documentation.
* Fixed Cy_SysClk_FllOutputDividerEnable() corrupting CLK_FLL_CONFIG fields.

See the Changelog section of each Driver in the [PDL API Reference](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/modules.html) for all fixes and updates.


## Supported Software and Tools

This version of PDL was validated for compatibility with the following Software and Tools:

| Software and Tools                                                            | Version      |
| :---                                                                          | :----        |
| ModusToolbox&trade;                                                           | 3.7.0        |
| [Infineon Core Library](https://github.com/Infineon/core-lib)                 | 1.7.0        |
| [Device Database](https://github.com/Infineon/device-db)                      | 4.37.0       |
| CMSIS                                                                         | 6.1.0        |
| GCC Compiler                                                                  | 14.2.1       |
| IAR Compiler                                                                  | 9.50.2       |
| ARM Compiler 6                                                                | 6.22.0       |
| FreeRTOS                                                                      | 10.6.202     |

## More information

* [Peripheral Driver Library README.md](./README.md)
* [Peripheral Driver Library API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [ModusToolbox Device Configurator Tool Guide](https://www.infineon.com/dgdl/Infineon-ModusToolbox_Device_Configurator_Guide_4-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d718a49017d99ab297631cb)
* [AN210781 Getting Started with PSOC 6 MCU with Bluetooth Low Energy (BLE) Connectivity](https://www.infineon.com/dgdl/Infineon-AN210781_Getting_Started_with_PSoC_6_MCU_with_Bluetooth_Low_Energy_(BLE)_Connectivity_on_PSoC_Creator-ApplicationNotes-v05_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0d311f536528)
* [PSOC 6](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/)
* [CYW20829](https://www.infineon.com/cms/en/product/promopages/airoc20829)
* [TRAVEO&trade; T2G body MCU family](https://www.infineon.com/products/microcontroller/32-bit-traveo-t2g-arm-cortex/for-body/)
* [TRAVEO&trade; T2G cluster MCU family](https://www.infineon.com/products/microcontroller/32-bit-traveo-t2g-arm-cortex/for-cluster/)
* [XMC7000](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc7000-industrial-microcontroller-arm-cortex-m7/)
* [Infineon](http://www.infineon.com)


---
© Infineon Technologies AG or an affiliate of Infineon Technologies AG, 2020-2026.
