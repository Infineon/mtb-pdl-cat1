# MTB CAT1 Peripheral Driver Library v3.10.0

Please refer to the [README.md](./README.md) and the
[PDL API Reference Manual](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/index.html)
for a complete description of the Peripheral Driver Library.


## Implementation Details
* CAT1A: Adds Traveo II Body Entry device support.  Devices added:

cyt2b63bae cyt2b63bas cyt2b63cae cyt2b63cas cyt2b64bae cyt2b64bas cyt2b64cae cyt2b64cas
cyt2b65bae cyt2b65bas cyt2b65cae cyt2b65cas cyt2b93bae cyt2b93bas cyt2b93cae cyt2b93cas
cyt2b94bae cyt2b94bas cyt2b94cae cyt2b94cas cyt2b95bae cyt2b95bas cyt2b95cae cyt2b95cas
cyt2b97bae cyt2b97bas cyt2b97cae cyt2b97cas cyt2b98bae cyt2b98bas cyt2b98cae cyt2b98cas

## Build Changes

## Personality Changes
*  Updated Personalities : adcmic-1.0.cypersonality,canfd-3.0.cypersonality,comp-1.0.cypersonality,connectivity_wifi-1.0.cypersonality,counter_v2-1.0.cypersonality,counter-1.0.cypersonality,ctdac-1.0.cypersonality,ezi2c-3.0.cypersonality,
   i2c-4.0.cypersonality, i2s-2.0.cypersonality, keyscan-1.1.cypersonality, lpcomp-2.0.cypersonality, mcwdt-3.0.cypersonality, opamp-1.0.cypersonality, pdm_pcm_v2-3.0.cypersonality,pdm_pcm-1.1.cypersonality,
   pwm_v2-1.0.cypersonality, pwm-1.0.cypersonality, quaddec_v2-1.0.cypersonality, quaddec-1.0.cypersonality,rtc-3.0.cypersonality, sar2-1.0.cypersonality, sar-6.0.cypersonality, sd_host-1.0.cypersonality, shiftreg_v2-1.0.cypersonality,
   smif_intrinsic-1.0.cypersonality, smif_v2-1.0.cypersonality, smif-1.2.cypersonality, spi-3.0.cypersonality, tdm-1.1.cypersonality, uart-3.0.cypersonality, bakclk-3.0.cypersonality, debug-2.0.cypersonality,dma-3.0.cypersonality, 
   eco_prescaler-1.0.cypersonality, eco-3.0.cypersonality, extclk-3.0.cypersonality, hfclk_v2-1.0.cypersonality, hfclk-3.0.cypersonality, iho-1.0.cypersonality, lfclk-3.0.cypersonality, mfclk-3.0.cypersonality, pathmux-3.0.cypersonality,
   pclk_v2-1.0.cypersonality, pclk-3.0.cypersonality, periclk-2.0.cypersonality, pilo-3.0.cypersonality, pin-3.0.cypersonality, power_v2-1.0.cypersonality, power_v3-1.0.cypersonality, pumpclk-3.0.cypersonality, sysclock-3.0.cypersonality.
   tickclk-3.0.cypersonality, timerclk-3.0.cypersonality, wco-3.0.cypersonality.
    

## Added Drivers
* No new drivers added.

## Updated Drivers
* [CRYPTO 2.100](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__crypto.html)
* [CRYPTOLITE 2.50](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__cryptolite.html)
* [DMA 2.80](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__dma.html)
* [EFUSE 2.40](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__efuse.html)
* [EPHY 1.20](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ephy.html)
* [ETHIF 1.20]()
* [FLASH 3.100](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__flash.html)
* [GPIO 1.110](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__gpio.html)
* [IPC 1.120](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__ipc.html)
* [LPCOMP 1.70](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__lpcomp.html)
* [LVD 1.80](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__lvd.html)
* [RTC 2.90](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__rtc.html)
* [SCB 3.20](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__scb.html)
* [SYSFAULT 1.30](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysfault.html)
* [SYSINT 1.120](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysint.html)
* [SMIF 2.70](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__smif.html)
* [SYSLIB 3.60](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syslib.html)
* [SYSTICK 1.80](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__arm__system__timer.html)
* [SYSCLK 3.100](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__sysclk.html)
* [SYSPM 5.120](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__syspm.html)
* [TCPWM 1.70](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__tcpwm.html)
* [TRIGMUX 1.70](https://infineon.github.io/mtb-pdl-cat1/pdl_api_reference_manual/html/group__group__trigmux.html)


### Drivers with patch version updates
* 


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
| [Device Database](https://github.com/Infineon/device-db)                      | 4.14.0       |

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
* [XMC7000](https://www.infineon.com/cms/en/product/microcontroller/32-bit-industrial-microcontroller-based-on-arm-cortex-m/32-bit-xmc7000-industrial-microcontroller-arm-cortex-m7/)
* [Infineon](http://www.infineon.com)


---
© Cypress Semiconductor Corporation (an Infineon company), 2024.
