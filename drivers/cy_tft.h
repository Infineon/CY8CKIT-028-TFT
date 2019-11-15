/***************************************************************************//**
* \file cy_tft.h
*
* \brief
*    This is display software i8080 interface header file.
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

/**
* \addtogroup group_board_libs_tft TFT Display
* \{
* APIs for controlling the TFT display on the board.
*/

#ifndef CY_TFT_H
#define CY_TFT_H

#include "cy_result.h"
#include "cyhal.h"

/**
 * Initializes GPIOs for the software i8080 interface.
 * @return CY_RSLT_SUCCESS if successfully initialized, else an error about
 * what went wrong
 */
cy_rslt_t cy_tft_io_init(void);

/**
 * Sets value of the display Reset pin.
 * @param[in] value The value to set on the pin
 */
void cy_tft_write_reset_pin(uint8_t value);

/**
 * Writes one byte of data to the software i8080 interface with the LCD_DC pin
 * set to 0. Followed by a low pulse on the NWR line to complete the write.
 * @param[in] command The command to issue to the display
 */
void cy_tft_write_command(uint8_t command);

/**
 * Writes one byte of data to the software i8080 interface with the LCD_DC pin
 * set to 1. Followed by a low pulse on the NWR line to complete the write.
 * @param[in] data The value to issue to the display
 */
void cy_tft_write_data(uint8_t data);

/**
 * Writes multiple command bytes to the software i8080 interface with the LCD_DC
 * pin set to 0.
 * @param[in] data The array of commands to send to the display
 * @param[in] num  The number of commands in the data array to send to the display
 */
void cy_tft_write_command_stream(uint8_t data[], int num);

/**
 * Writes multiple bytes of data to the software i8080 interface with the LCD_DC
 * pin set to 1.
 * @param[in] data The array of data to send to the display
 * @param[in] num  The number of bytes in the data array to send to the display
 */
void cy_tft_write_data_stream(uint8_t data[], int num);

/**
 * Reads one byte of data from the software i8080 interface with the LCD_DC pin
 * set to 1.
 * @return The byte read from the display
 */
uint8_t cy_tft_read_data(void);

/**
 * Reads multiple bytes of data from the software i8080 interface with the LCD_DC
 * pin set to 1.
 * @param[in,out]   data The array of to store the bytes read from the display
 * @param[in]       num  The number of bytes to read from the display
 */
void cy_tft_read_data_stream(uint8_t data[], int num);

/**
 * Free all resources used for the software i8080 interface.
 * @return The byte read from the display
 */
void cy_tft_io_free(void);

#endif

/** \} group_board_libs_tft */

/* [] END OF FILE */
