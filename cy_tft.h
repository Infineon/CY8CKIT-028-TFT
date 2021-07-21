/***********************************************************************************************//**
 * \file cy_tft.h
 *
 * \brief
 *    DEPRICATED TFT functions. These items have been replaced by items in
 *    mtb_st7789v.h. This file will be removed in a future release.
 *
 ***************************************************************************************************
 * \copyright
 * Copyright 2018-2021 Cypress Semiconductor Corporation
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
 **************************************************************************************************/

#pragma once

/** \cond INTERNAL */

/**
 * \addtogroup group_board_libs_tft TFT Display
 * \{
 * Deprecated APIs for controlling the TFT display on the board. Control of the display should be
 * done using the display-tft-st7789v library. Details are available at
 * https://github.com/cypresssemiconductorco/display-tft-st7789v.
 */

#include <stddef.h>
#include "cy_result.h"
#include "mtb_st7789v.h"
#include "cy8ckit_028_tft_pins.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
 * Initializes GPIOs for the software i8080 interface.
 * @return CY_RSLT_SUCCESS if successfully initialized, else an error about
 * what went wrong
 */
static inline cy_rslt_t cy_tft_io_init(void)
{
    static const mtb_st7789v_pins_t PINS =
    {
        .db08 = CY8CKIT_028_TFT_PIN_DISPLAY_DB8,
        .db09 = CY8CKIT_028_TFT_PIN_DISPLAY_DB9,
        .db10 = CY8CKIT_028_TFT_PIN_DISPLAY_DB10,
        .db11 = CY8CKIT_028_TFT_PIN_DISPLAY_DB11,
        .db12 = CY8CKIT_028_TFT_PIN_DISPLAY_DB12,
        .db13 = CY8CKIT_028_TFT_PIN_DISPLAY_DB13,
        .db14 = CY8CKIT_028_TFT_PIN_DISPLAY_DB14,
        .db15 = CY8CKIT_028_TFT_PIN_DISPLAY_DB15,
        .nrd  = CY8CKIT_028_TFT_PIN_DISPLAY_NRD,
        .nwr  = CY8CKIT_028_TFT_PIN_DISPLAY_NWR,
        .dc   = CY8CKIT_028_TFT_PIN_DISPLAY_DC,
        .rst  = CY8CKIT_028_TFT_PIN_DISPLAY_RST,
    };
    return mtb_st7789v_init8(&PINS);
}


/**
 * Sets value of the display Reset pin.
 * @param[in] value The value to set on the pin
 */
static inline void cy_tft_write_reset_pin(uint8_t value)
{
    mtb_st7789v_write_reset_pin((bool)value);
}


/**
 * Writes one byte of data to the software i8080 interface with the LCD_DC pin
 * set to 0. Followed by a low pulse on the NWR line to complete the write.
 * @param[in] command The command to issue to the display
 */
static inline void cy_tft_write_command(uint8_t command)
{
    mtb_st7789v_write_command(command);
}


/**
 * Writes one byte of data to the software i8080 interface with the LCD_DC pin
 * set to 1. Followed by a low pulse on the NWR line to complete the write.
 * @param[in] data The value to issue to the display
 */
static inline void cy_tft_write_data(uint8_t data)
{
    mtb_st7789v_write_data(data);
}


/**
 * Writes multiple command bytes to the software i8080 interface with the LCD_DC
 * pin set to 0.
 * @param[in] data The array of commands to send to the display
 * @param[in] num  The number of commands in the data array to send to the display
 */
static inline void cy_tft_write_command_stream(uint8_t data[], int num)
{
    mtb_st7789v_write_command_stream(data, num);
}


/**
 * Writes multiple bytes of data to the software i8080 interface with the LCD_DC
 * pin set to 1.
 * @param[in] data The array of data to send to the display
 * @param[in] num  The number of bytes in the data array to send to the display
 */
static inline void cy_tft_write_data_stream(uint8_t data[], int num)
{
    mtb_st7789v_write_data_stream(data, num);
}


/**
 * Reads one byte of data from the software i8080 interface with the LCD_DC pin
 * set to 1.
 * @return The byte read from the display
 */
static inline uint8_t cy_tft_read_data(void)
{
    return mtb_st7789v_read_data();
}


/**
 * Reads multiple bytes of data from the software i8080 interface with the LCD_DC
 * pin set to 1.
 * @param[in,out]   data The array of to store the bytes read from the display
 * @param[in]       num  The number of bytes to read from the display
 */
static inline void cy_tft_read_data_stream(uint8_t data[], int num)
{
    mtb_st7789v_read_data_stream(data, num);
}


/**
 * Free all resources used for the software i8080 interface.
 * @return The byte read from the display
 */
static inline void cy_tft_io_free(void)
{
    mtb_st7789v_free();
}


#if defined(__cplusplus)
}
#endif

/** \} group_board_libs_tft */
/** \endcond */
