# CY8CKIT-028-TFT shield support library
The TFT Display Shield Board (CY8CKIT-028-TFT) has been designed such that a TFT display, audio devices, and sensors can interface with PSoC MCUs.

See [README.md](README.md) for details on how to use this library.

### What's Included?
This library includes support for each of the hardware components included on the shield:

* 2.4 inch TFT Display (ST7789V)
* Motion Sensor (BMI-160)
* Ambient Light Sensor (TEMT6000X01)
* PDM Microphone example code (SPK0838HT4HB)
* Audio Codec (AK4954A) (not yet supported in this library)

### What Changed?
#### v1.2.0
* Reworked how object initialization/freeing is done.
#### v1.1.0
* Added support for motion sensor
* Added support for light sensor
* Reorganized TFT code into separate sub library
#### v1.0.0
* Initial release supporting the TFT display only

### Supported Software and Tools
This version of the CY8CKIT-028-TFT library was validated for compatibility with the following Software and Tools:

| Software and Tools                        | Version |
| :---                                      | :----:  |
| ModusToolbox Software Environment         | 2.2.1   |
| GCC Compiler                              | 9.3.1   |
| IAR Compiler                              | 8.4     |
| ARM Compiler 6                            | 6.11    |

Minimum required ModusToolbox Software Environment: v2.0

### More information

* [API Reference Guide](https://cypresssemiconductorco.github.io/CY8CKIT-028-TFT/html/index.html)
* [CY8CKIT-028-TFT Documentation](https://www.cypress.com/documentation/development-kitsboards/tft-display-shield-board-cy8ckit-028-tft)
* [SEGGER emWin Middleware Library](https://github.com/cypresssemiconductorco/emwin)
* [Cypress Semiconductor, an Infineon Technologies Company](http://www.cypress.com)
* [Cypress Semiconductor GitHub](https://github.com/cypresssemiconductorco)
* [ModusToolbox](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation, 2019-2021.
