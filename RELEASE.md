# MTB CAT1 Peripheral Driver Library v2.4.1

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.

Some restrictions apply to the PSoC 64 devices configuration. Please refer to [PRA (Protected Register Access)](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__pra.html) driver documentation for the details.

## New Features

None

## Build Changes

None

## Personalities Changes

None

## Added Drivers

None

## Updated Drivers

* [Startup 2.95](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__system__config.html)

### Drivers with patch version updates

None

### Obsoleted part numbers

The ModusToolbox Device Configurator can not create the designs targeting the obsolete PSoC 6 part numbers.

Below is a list of PSoC 6 part numbers obsoleted in psoc6pdl release-v1.6.0, with the suggested next best alternative:

| Obsoleted part number | Next best alternative |
| :---                  | :----                 |
| CY8C624AAZI-D44       | CY8C624AAZI-S2D44     |
| CY8C624AFNI-D43       | CY8C624AFNI-S2D43     |
| CY8C624ABZI-D04       | CY8C624ABZI-S2D04     |
| CY8C624ABZI-D14       | CY8C624ABZI-S2D14     |
| CY8C624AAZI-D14       | CY8C624AAZI-S2D14     |
| CY8C6248AZI-D14       | CY8C6248AZI-S2D14     |
| CY8C6248BZI-D44       | CY8C6248BZI-S2D44     |
| CY8C6248AZI-D44       | CY8C6248AZI-S2D44     |
| CY8C6248FNI-D43       | CY8C6248FNI-S2D43     |
| CY8C624ALQI-D42       | N/A                   |

## Known Issues
* CAT1A: On soft reset, user need to reset back up domain using Cy_SysLib_ResetBackupDomain() to receive Cy_RTC_CenturyInterrupt() callback on Century roll over.
* CAT1A: IAR compiler Linker scripts do not support Dual-CPU project with the custom CM0p Application by default. Modify linker scripts to ensure proper layout of CM0p and CM4 images in MCU Flash. Refer to the following AppNote for more information. https://www.infineon.com/dgdl/Infineon-AN215656_PSoC_6_MCU_Dual-CPU_System_Design-ApplicationNotes-v09_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0d3180c4655f&utm_source=cypress&utm_medium=referral&utm_campaign=202110_globe_en_all_integration-application_note.
* On building with tools 2.2, user get warning related to the older version of tools used. To avoid this warning, user is advised to migrate to newer tools version or keep working with previous version of this library.  The warning generated is as follows:
  * _#warning "(Library) The referenced 'device support library' contains newer content than is supported. Either downgrade the version of the 'device support library' referenced or upgrade the version of tools being used_
* RTC: API - Cy_RTC_SyncFromRtc(), The delay used between two critical sections in this API will disable the interrupts until delay expires. For time critical applications, sync from RTC must be implemented on application level by reusing the Cy_RTC_SyncFromRtc() code with the reduced delays.

## Defect Fixes

See the Changelog section of each Driver in the [PDL API Reference](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/modules.html) for all fixes and updates.

## Supported Software and Tools

This version of PDL was validated for compatibility with the following Software and Tools:

| Software and Tools                                                            | Version      |
| :---                                                                          | :----        |
| [Infineon Core Library](https://github.com/Infineon/core-lib)                 | 1.3.0        |
| [Infineon HAL](https://github.com/Infineon/mtb-hal-cat1)                      | 2.0.1        |
| CMSIS-Core(M)                                                                 | 5.4.0        |
| GCC Compiler                                                                  | 10.3.1       |
| IAR Compiler                                                                  | 8.42.2       |
| ARM Compiler 6                                                                | 6.13         |
| FreeRTOS                                                                      | 10.4.302     |

## More information

* [Peripheral Driver Library README.md](./README.md)
* [Peripheral Driver Library API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [ModusToolbox Device Configurator Tool Guide](https://www.infineon.com/dgdl/Infineon-ModusToolbox_Device_Configurator_Guide_4-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d718a49017d99ab297631cb)
* [AN210781 Getting Started with PSoC 6 MCU with Bluetooth Low Energy (BLE) Connectivity](https://www.infineon.com/dgdl/Infineon-AN210781_Getting_Started_with_PSoC_6_MCU_with_Bluetooth_Low_Energy_(BLE)_Connectivity_on_PSoC_Creator-ApplicationNotes-v05_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0d311f536528)
* [PSoC 6 Technical Reference Manuals](https://edit.infineon.com/cms/en/search.html#!term=psoc6%20technical%20reference%20manual&view=downloads)
* [PSoC 6 MCU Datasheets](https://edit.infineon.com/cms/en/search.html?intc=searchkwr-return#!view=downloads&term=psoc6&doc_group=Data%20Sheet)
* [CYW20829](https://www.infineon.com/cms/en/product/promopages/airoc20829)
* [Infineon](http://www.infineon.com)

---
© Cypress Semiconductor Corporation (an Infineon company), 2022.
