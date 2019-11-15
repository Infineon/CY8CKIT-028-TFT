/***************************************************************************//**
* \file cy_tft.c
*
* \brief
*    This is display software i8080 interface source file
*
********************************************************************************
* \copyright
* Copyright 2018-2019 Cypress Semiconductor Corporation
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

#include "cy_tft.h"
#include "cyhal.h"

#ifndef CY8CKIT_028_TFT_CUSTOM_CONFIG
    #include "cy8ckit_028_tft_config.h"
#endif

/***************************************************************************//**
* \file cy_tft.c
*
* \brief
*    This is display software i8080 interface source file
*
********************************************************************************
* \copyright
* Copyright 2018-2019 Cypress Semiconductor Corporation
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

#include "cy_tft.h"
#include "cyhal.h"

#ifndef CY8CKIT_028_TFT_CUSTOM_CONFIG
    #include "cy8ckit_028_tft_config.h"
#endif



/*******************************************************************************
 * Changes data bus GPIO pins drive mode to digital Hi-Z with enabled input buffer.
 *******************************************************************************/
__STATIC_INLINE void data_io_set_input(void)
{
    /* enable input */
    cyhal_gpio_configure(CY_TFT_DB8, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
    cyhal_gpio_configure(CY_TFT_DB9, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
    cyhal_gpio_configure(CY_TFT_DB10, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
    cyhal_gpio_configure(CY_TFT_DB11, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
    cyhal_gpio_configure(CY_TFT_DB12, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
    cyhal_gpio_configure(CY_TFT_DB13, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
    cyhal_gpio_configure(CY_TFT_DB14, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
    cyhal_gpio_configure(CY_TFT_DB15, CYHAL_GPIO_DIR_INPUT, CYHAL_GPIO_DRIVE_NONE);
}

/*******************************************************************************
 * Changes data bus GPIO pins drive mode to strong drive with disabled input buffer.
 *******************************************************************************/
__STATIC_INLINE void data_io_set_output(void)
{
    /* enable output */
    cyhal_gpio_configure(CY_TFT_DB8, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG);
    cyhal_gpio_configure(CY_TFT_DB9, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG);
    cyhal_gpio_configure(CY_TFT_DB10, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG);
    cyhal_gpio_configure(CY_TFT_DB11, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG);
    cyhal_gpio_configure(CY_TFT_DB12, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG);
    cyhal_gpio_configure(CY_TFT_DB13, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG);
    cyhal_gpio_configure(CY_TFT_DB14, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG);
    cyhal_gpio_configure(CY_TFT_DB15, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG);
}

/*******************************************************************************
 * Writes one byte of data to the software i8080 interface.
 *******************************************************************************/
__STATIC_INLINE void write_data(uint8_t data)
{
    cyhal_gpio_write(CY_TFT_DB8,  data     & 0x01);
    cyhal_gpio_write(CY_TFT_DB9, (data>>1) & 0x01);
    cyhal_gpio_write(CY_TFT_DB10, (data>>2) & 0x01);
    cyhal_gpio_write(CY_TFT_DB11, (data>>3) & 0x01);
    cyhal_gpio_write(CY_TFT_DB12, (data>>4) & 0x01);
    cyhal_gpio_write(CY_TFT_DB13, (data>>5) & 0x01);
    cyhal_gpio_write(CY_TFT_DB14, (data>>6) & 0x01);
    cyhal_gpio_write(CY_TFT_DB15, (data>>7) & 0x01);

    cyhal_gpio_write(CY_TFT_NWR, 0u);
    cyhal_gpio_write(CY_TFT_NWR, 1u);
}

/*******************************************************************************
 * Reads one byte of data from the software i8080 interface.
 *******************************************************************************/
__STATIC_INLINE uint8_t read_data(void)
{
    uint8_t data = 0u;

    cyhal_gpio_write(CY_TFT_NRD, 0u);

    data |= cyhal_gpio_read(CY_TFT_DB8);
    data |= cyhal_gpio_read(CY_TFT_DB9)<<1;
    data |= cyhal_gpio_read(CY_TFT_DB10)<<2;
    data |= cyhal_gpio_read(CY_TFT_DB11)<<3;
    data |= cyhal_gpio_read(CY_TFT_DB12)<<4;
    data |= cyhal_gpio_read(CY_TFT_DB13)<<5;
    data |= cyhal_gpio_read(CY_TFT_DB14)<<6;
    data |= cyhal_gpio_read(CY_TFT_DB15)<<7;

    cyhal_gpio_write(CY_TFT_NRD, 1u);

    return data;
}


cy_rslt_t cy_tft_io_init(void)
{
    cy_rslt_t rslt = cyhal_gpio_init(CY_TFT_DB8, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_DB9, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_DB10, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_DB11, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_DB12, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_DB13, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_DB14, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_DB15, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_NWR, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 1u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_DC, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 0u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_RST, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 1u);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = cyhal_gpio_init(CY_TFT_NRD, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 1u);
    return rslt;
}

void cy_tft_write_reset_pin(uint8_t value)
{
    cyhal_gpio_write(CY_TFT_RST, value);
}

void cy_tft_write_command(uint8_t data)
{
    cyhal_gpio_write(CY_TFT_DC, 0u);
    write_data(data);
}

void cy_tft_write_data(uint8_t data)
{
    cyhal_gpio_write(CY_TFT_DC, 1u);
    write_data(data);
}

void cy_tft_write_command_stream(uint8_t data[], int num)
{
    int i = 0;

    cyhal_gpio_write(CY_TFT_DC, 0u);

    for(i = 0; i < num; i++)
    {
        write_data(data[i]);
    }
}

void cy_tft_write_data_stream(uint8_t data[], int num)
{
    int i = 0;

    cyhal_gpio_write(CY_TFT_DC, 1u);

    for(i = 0; i < num; i++)
    {
        write_data(data[i]);
    }
}

uint8_t cy_tft_read_data(void)
{
    uint8_t data;

    cyhal_gpio_write(CY_TFT_DC, 1u);

    data_io_set_input();
    data = read_data();
    data_io_set_output();

    return data;
}

void cy_tft_read_data_stream(uint8_t data[], int num)
{
    cyhal_gpio_write(CY_TFT_DC, 1u);

    data_io_set_input();

    for(int i = 0; i < num; i++)
    {
        data[i] = read_data();
    }

    data_io_set_output();
}

void cy_tft_io_free(void)
{
    cyhal_gpio_free(CY_TFT_DB8);
    cyhal_gpio_free(CY_TFT_DB9);
    cyhal_gpio_free(CY_TFT_DB10);
    cyhal_gpio_free(CY_TFT_DB11);
    cyhal_gpio_free(CY_TFT_DB12);
    cyhal_gpio_free(CY_TFT_DB13);
    cyhal_gpio_free(CY_TFT_DB14);
    cyhal_gpio_free(CY_TFT_DB15);
    cyhal_gpio_free(CY_TFT_NWR);
    cyhal_gpio_free(CY_TFT_DC);
    cyhal_gpio_free(CY_TFT_RST);
    cyhal_gpio_free(CY_TFT_NRD);
}

/* [] END OF FILE */
