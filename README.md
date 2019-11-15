# CY8CKIT-028-TFT shield support package

The TFT Display Shield Board (CY8CKIT-028-TFT) has been designed such that a TFT display, audio devices, and sensors can interface with Cypress' PSoC 6 MCUs.

It comes with the features below to enable everyday objects to connect to the Internet of Things (IoT).

* 2.4 inch TFT Display
* Motion Sensor (not yet supported in this library)
* Ambient Light Sensor (not yet supported in this library)
* PDM Microphone (not yet supported in this library)
* Audio Codec (not yet supported in this library)
* 3.5-mm Audio Jack (not yet supported in this library)

This shield has a Newhaven 2.4″ 240×320 TFT display with a Sitronix ST7789 display controller and uses the 8080-Series Parallel Interface.

The E-ink Display Shield Board uses the Arduino Uno pin layout plus an additional 6 pins. It is compatable with the PSoC 6 Pinoeer Kits. Refer to the respective kit guides for more details.

![](docs/html/board.png)

# Quick Start Guide

* [TFT emWin project](#tft-emwin-project)

## TFT emWin project
Follow the steps bellow in order to create a simple emWin project and display some text on it.
1. create an empty PSoC6 project
2. add this package to the project
3. add emWin library to the project
4. enable EMWIN_NOSNTS emWin library option by adding it to the Makefile COMPONENTS list:
```
COMPONENTS+=EMWIN_NOSNTS
```
5. place the following code in the main.c file:
```cpp
#include "cy_pdl.h"
#include "cyhal.h"
#include "cybsp.h"
#include "GUI.h"

int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init();
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    __enable_irq();

    GUI_Init();
    GUI_DispString("Hello world!");

    for(;;)
    {
    }
}
```
6. Build the project and program the kit.

### More information

* [API Reference Guide](https://cypresssemiconductorco.github.io/CY8CKIT-028-TFT/html/index.html)
* [CY8CKIT-028-TFT Documentation](https://www.cypress.com/documentation/development-kitsboards/tft-display-shield-board-cy8ckit-028-tft)
* [SEGGER emWin Middleware Library](https://github.com/cypresssemiconductorco/emwin)
* [Cypress Semiconductor](http://www.cypress.com)
* [Cypress Semiconductor GitHub](https://github.com/cypresssemiconductorco)
* [ModusToolbox](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Cypress Semiconductor Corporation, 2019.
