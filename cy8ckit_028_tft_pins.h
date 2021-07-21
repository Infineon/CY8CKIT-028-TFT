/***********************************************************************************************//**
 * \file cy8ckit_028_tft_pins.h
 *
 * \brief
 *    Main header file of the shield support library.
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

#include "cybsp.h"

/**
 * \addtogroup group_board_libs_pins
 * \{
 * Pin mapping of the GPIOs used by shield peripherals
 */

#if defined(__cplusplus)
extern "C"
{
#endif

// Display connections
/** Pin for the Display Data8 signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DB8      (CYBSP_J2_2)
/** Pin for the Display Data9 signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DB9      (CYBSP_J2_4)
/** Pin for the Display Data10 signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DB10     (CYBSP_J2_6)
/** Pin for the Display Data11 signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DB11     (CYBSP_J2_10)
/** Pin for the Display Data12 signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DB12     (CYBSP_J2_12)
/** Pin for the Display Data13 signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DB13     (CYBSP_D7)
/** Pin for the Display Data14 signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DB14     (CYBSP_D8)
/** Pin for the Display Data15 signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DB15     (CYBSP_D9)
/** Pin for the Display Read signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_NRD      (CYBSP_D10)
/** Pin for the Display Write signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_NWR      (CYBSP_D11)
/** Pin for the Display D/C signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_DC       (CYBSP_D12)
/** Pin for the Display Reset signal */
#define CY8CKIT_028_TFT_PIN_DISPLAY_RST      (CYBSP_D13)

// Internal measurement unit (IMU) : accelerometer + gyro
/** Pin for the Accelerometer/Gyroscope I2C SCL signal */
#define CY8CKIT_028_TFT_PIN_IMU_I2C_SCL      (CYBSP_I2C_SCL)
/** Pin for the Accelerometer/Gyroscope I2C SDA signal */
#define CY8CKIT_028_TFT_PIN_IMU_I2C_SDA      (CYBSP_I2C_SDA)
/** Pin for the Accelerometer/Gyroscope Interrupt1 signal */
#define CY8CKIT_028_TFT_PIN_IMU_INT_1        (CYBSP_A2)
/** Pin for the Accelerometer/Gyroscope Interrupt2 signal */
#define CY8CKIT_028_TFT_PIN_IMU_INT_2        (CYBSP_A3)

// Ambient light sensor
/** Pin for the Ambient light sensor */
#define CY8CKIT_028_TFT_PIN_ALS_OUT          (CYBSP_A0)

// PDM Microphone
/** Pin for the PDM Clock */
#define CY8CKIT_028_TFT_PIN_PDM_CLK          (CYBSP_A4)
/** Pin for the PDM Data */
#define CY8CKIT_028_TFT_PIN_PDM_DATA         (CYBSP_A5)

// Audio Codec
/** Pin for the Audio Codec's I2C SCL signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2C_SCL    (CYBSP_I2C_SCL)
/** Pin for the Audio Codec's I2C SDA signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2C_SDA    (CYBSP_I2C_SDA)
/** Pin for the Audio Codec's I2S MasterClock signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2S_MCLK   (CYBSP_D0)
/** Pin for the Audio Codec's I2S TX SerialClock signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2S_TX_SCK (CYBSP_D1)
/** Pin for the Audio Codec's TX WordSelect signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2S_TX_WS  (CYBSP_D2)
/** Pin for the Audio Codec's I2S TX SerialDataOut signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2S_TX_SDO (CYBSP_D3)
/** Pin for the Audio Codec's I2S RX SerialClock signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2S_RX_SCK (CYBSP_D4)
/** Pin for the Audio Codec's I2S RX WordSelect signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2S_RX_WS  (CYBSP_D5)
/** Pin for the Audio Codec's I2S RX SerialDataIn signal */
#define CY8CKIT_028_TFT_PIN_CODEC_I2S_RX_SDI (CYBSP_D6)

#if defined(__cplusplus)
}
#endif

/** \} group_board_libs_pins */
