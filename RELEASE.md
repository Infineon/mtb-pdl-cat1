# MTB CAT1 Peripheral Driver Library v3.11.0

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.


## Implementation Details
* CAT1C: Support for TVIIC2D6M devices: cyt4dnjbas, cyt4dnjbbs, cyt4dnjbcs, cyt4dnjbds, cyt4dnjbes, cyt4dnjbfs, cyt4dnjbgs, cyt4dnjbhs, cyt4dnjbjs, cyt4dnjbks, cyt4dnjbls, cyt4dnjbms, cyt4dnjbns, cyt4dnjbps, cyt4dnjbqs, cyt4dnjbrs

## Build Changes

## Personality Changes
* New Personalities (in 8.0 folder):
    * eth-1.0.cypersonality
* Updated Personalities (in 8.0 folder):
  * peripheral:
    * smif_v2-1.0.cypersonality
    * emusb-1.0.cypersonality
    * dma-3.0.cypersonality
  * platform:
    * axidmac-1.0.cypersonality
    * bakclk-3.0.cypersonality
    * dma-3.0.cypersonality
    * lfclk-3.0.cypersonality
    * lpeco_prescaler-1.0.cypersonality
    * lepco-1.0.cypersonality
    * power_v3-1.0.cypersonality
    * sysclock-3.0.cypersonality
    * wco-3.0.cypersonality

## Added Drivers
* [AXIDMAC 1.0](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__axidmac.html)

## Updated Drivers
* [CRYPTO 2.110](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__crypto.html)
* [FLASH 3.110](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__flash.html)
* [IPC 1.130](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ipc.html)
* [PROT 1.100](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__prot.html)
* [SAR2 1.1](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sar2.html)
* [SMIF 2.80](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__smif.html)
* [SYSCLK 3.110](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysclk.html)
* [SYSPM 5.130](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syspm.html)

### Drivers with patch version updates


### Obsoleted part numbers


## Known Issues
* CAT1A: In device-configurator, certain IP is not completely available for some devices as some combinations of pin connections are not valid.
  * CYT2BL4BAS/CYT2BL4CAE: SCB6 is complete only for UART, cannot support I2C, EZI2C, or SPI.
  * CYT2BL3CAE, CYT2B7CAE: SCB1 is complete only for UART, cannot support I2C, EZI2C, or SPI.
  * On the following devices: CAN FD 0 Channel 3, CAN FD 1 Channel 1, CAN FD 1 Channel 3 is not available (no signal for CAN Rx Pin available).
    * CYT2BL4BAS, CYT2BL3CAE, CYT2BL3CAS, CYT2BL4CAE, CYT2BL3BAE, CYT2BL4BAE, CYT2BL4CAS, CYT2BL3BAS, CYT2B73BAS, CYT2B73CAS, CYT2B73BAE
* Traveo II B-E: Does not support emulated eeprom.
* CAT1A: On soft reset, user need to reset back up domain using Cy_SysLib_ResetBackupDomain() to receive Cy_RTC_CenturyInterrupt() callback on Century roll over.
* On building with tools 2.2, user get warning related to the older version of tools used. To avoid this warning, user is advised to migrate to newer tools version or keep working with previous version of this library.  The warning generated is as follows:
  * _#warning "(Library) The referenced 'device support library' contains newer content than is supported. Either downgrade the version of the 'device support library' referenced or upgrade the version of tools being used_
* Design configuration will not be auto migrated from smartio-3.0.cypersonality to smartio-4.0.cypersonality. So, existing projects should use smartio-3.0.cypersonality. New projects can make use of smartio-4.0.cypersonality which includes additional improvements.
* CAT1C: This release does not support D-CACHE on CAT1C platform


## Defect Fixes

See the Changelog section of each Driver in the [PDL API Reference](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/modules.html) for all fixes and updates.

## Supported Software and Tools

This version of PDL was validated for compatibility with the following Software and Tools:

| Software and Tools                                                            | Version      |
| :---                                                                          | :----        |
| [Infineon Core Library](https://github.com/Infineon/core-lib)                 | 1.4.1        |
| [Infineon HAL](https://github.com/Infineon/mtb-hal-cat1)                      | 2.6.0        |
| CMSIS                                                                         | 5.8.0        |
| GCC Compiler                                                                  | 11.3.1       |
| IAR Compiler                                                                  | 9.40.2       |
| ARM Compiler 6                                                                | 6.16         |
| FreeRTOS                                                                      | 10.4.305     |
| [Device Database](https://github.com/Infineon/device-db)                      | 4.16.0       |

## More information

* [Peripheral Driver Library README.md](./README.md)
* [Peripheral Driver Library API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [ModusToolbox Device Configurator Tool Guide](https://www.infineon.com/dgdl/Infineon-ModusToolbox_Device_Configurator_Guide_4-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d718a49017d99ab297631cb)
* [AN210781 Getting Started with PSoC 6 MCU with Bluetooth Low Energy (BLE) Connectivity](https://www.infineon.com/dgdl/Infineon-AN210781_Getting_Started_with_PSoC_6_MCU_with_Bluetooth_Low_Energy_(BLE)_Connectivity_on_PSoC_Creator-ApplicationNotes-v05_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0d311f536528)
* [PSoC 6](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/)
* [CYW20829](https://www.infineon.com/cms/en/product/promopages/airoc20829)
* [TV-II-BH8/BH4](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/)
* [TV-II-BE4/BE2/BE1/BE512K](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/)
* [TV-II-C-2D-6M](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/32-bit-traveo-t2g-arm-cortex-for-cluster/)
* [XMC7000](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc7000-industrial-microcontroller-arm-cortex-m7/)
* [Infineon](http://www.infineon.com)


---
© Cypress Semiconductor Corporation (an Infineon company), 2024.
