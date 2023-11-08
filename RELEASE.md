# MTB CAT1 Peripheral Driver Library v3.8.0

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.


## Implementation Details

* CAT1A: Adds Traveo II Body Entry device support.  Devices added:

cyt2b73cas cyt2b74bae cyt2b74bas cyt2b74cae cyt2b74cas cyt2b75bae cyt2b75bas cyt2b75cae cyt2b75cas cyt2b77bae
cyt2b77bas cyt2b77cae cyt2b77cas cyt2b78bae cyt2b78bas cyt2b78cae cyt2b78cas cyt2bl3bae cyt2bl3bas cyt2bl3cae
cyt2bl3cas cyt2bl4bae cyt2bl4bas cyt2bl4cae cyt2bl4cas cyt2bl5bae cyt2bl5bas cyt2bl5cae cyt2bl5cas cyt2bl7bae
cyt2bl7bas cyt2bl7cae cyt2bl7cas cyt2bl8bae cyt2bl8bas cyt2bl8cae cyt2bl8cas 

* Updates drivers to support Traveo II B-E devices.  (See drivers list below.)
* Updates personalities for Traveo II B-E devices.
* Updates IP headers with new-to-CAT1A IP to support Traveo II B-E devices.
* Adds linker scripts and adjusts cat1a system/startup code to work with Traveo II B-E devices.
* CAT1C: Removes some CAT1C SysPm APIs that were not hardware compatible with XMC7xxx devices.
* In order to provide CAT1A support for the TVIIBE PERIv2 hardware, and still provide CAT1A/CAT1B/CAT1B compatibility with cy_sysclk_v2, PERI_DIV_n_NR macros have been renamed to PERI_CLK_GR_DIV_n_NR.  Any application code using the old macros must be updated to use the new macro names.
* Personality fixes: Some personality fixes where IP from other categories overlapped with TVIIBE (mostly CAT1C) were applied to schema v8 personalities.
* Bug fix: Updates Prot driver API availability based on the PERI version. Some devices may have a reduced set of functions available.  If code called APIs not appropriate for the version of PERI, that code will not build without updating to reflect new API availability.  Please note, however, that if code was calling those APIs and the functions are no longer available, there will be no functional difference as the calls were available before but did nothing if the device hardware didn't support the function.

## Build Changes

## Personality Changes
* Updated Personalities (in 8.0 folder):
  * peripheral:
    * evtgen-1.0.cypersonality
    * mcwdt_v2-1.0.cypersonality
    * rtc-3.0.cypersonality
  * platform:
    * bakclk-3.0.cypersonality
    * eco-3.0.cypersonality
    * eco_prescaler-1.0.cypersonality
    * extclk-3.0.cypersonality
    * fastclk-2.0.cypersonality
    * fll-4.0.cypersonality
    * hfclk-3.0.cypersonality
    * ilo-3.0.cypersonality
    * imo-3.0.cypersonality 
    * lfclk-3.0.cypersonality
    * memclk-1.0.cypersonality
    * pathmux-3.0.cypersonality
    * periclk-2.0.cypersonality
    * pll-3.0.cypersonality
    * pll400-1.0.cypersonality
    * power_v3-1.0.cypersonality
    * slowclk-2.0.cypersonality
    * sysclock-3.0.cypersonality
    * tickclk-3.0.cypersonality
    * timerclk-3.0.cypersonality
    * wco-3.0.cypersonality

## Added Drivers
* No new drivers required for TVIIBE.

## Updated Drivers
* Flash
* GPIO
* IPC
* LVD
* MCWDT
* PROT
* RTC
* SysClk
* SysInt
* SysLib
* SysPm
* WDT
* BLE_CLK

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
| [Infineon HAL](https://github.com/Infineon/mtb-hal-cat1)                      | 2.5.4        |
| CMSIS                                                                         | 5.8.0        |
| GCC Compiler                                                                  | 11.3.1       |
| IAR Compiler                                                                  | 9.3          |
| ARM Compiler 6                                                                | 6.16         |
| FreeRTOS                                                                      | 10.4.305     |

## More information

* [Peripheral Driver Library README.md](./README.md)
* [Peripheral Driver Library API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
* [ModusToolbox Software Environment, Quick Start Guide, Documentation, and Videos](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [ModusToolbox Device Configurator Tool Guide](https://www.infineon.com/dgdl/Infineon-ModusToolbox_Device_Configurator_Guide_4-UserManual-v01_00-EN.pdf?fileId=8ac78c8c7d718a49017d99ab297631cb)
* [AN210781 Getting Started with PSoC 6 MCU with Bluetooth Low Energy (BLE) Connectivity](https://www.infineon.com/dgdl/Infineon-AN210781_Getting_Started_with_PSoC_6_MCU_with_Bluetooth_Low_Energy_(BLE)_Connectivity_on_PSoC_Creator-ApplicationNotes-v05_00-EN.pdf?fileId=8ac78c8c7cdc391c017d0d311f536528)
* [PSoC 6](https://www.infineon.com/cms/en/product/microcontroller/32-bit-psoc-arm-cortex-microcontroller/psoc-6-32-bit-arm-cortex-m4-mcu/)
* [CYW20829](https://www.infineon.com/cms/en/product/promopages/airoc20829)
* [TV-II-BH8/BH4](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/)
* [TV-II-BE1/BE4](https://www.infineon.com/cms/en/product/microcontroller/32-bit-traveo-t2g-arm-cortex-microcontroller/)
* [XMC7000](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc7000-industrial-microcontroller-arm-cortex-m7/)
* [Infineon](http://www.infineon.com)


---
© Cypress Semiconductor Corporation (an Infineon company), 2023.
