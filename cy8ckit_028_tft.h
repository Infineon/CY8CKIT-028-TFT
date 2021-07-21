/***********************************************************************************************//**
 * \file cy8ckit_028_tft.h
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

#include "cy8ckit_028_tft_pins.h"
#include "cy_result.h"
#include "cybsp.h"
#include "cyhal_i2c.h"
#include "cyhal_pdmpcm.h"
#include "mtb_ak4954a.h"
#include "mtb_bmi160.h"
#include "mtb_light_sensor.h"
#include "mtb_st7789v.h"

// For backwards compatability
#include "cy_tft.h"


/**
 * \defgroup group_board_libs_shield Shield
 * \defgroup group_board_libs_pins Pins
 * \defgroup group_board_libs_microphone Microphone
 * \defgroup group_board_libs_codec Audio Codec
 * \defgroup group_board_libs_light Light Sensor
 * \defgroup group_board_libs_motion Motion Sensor
 * \defgroup group_board_libs_display TFT Display
 *
 * \addtogroup group_board_libs_codec
 * \{
 * The audio codec is handled by the audio-codec-ak4954a library, details are available at
 * https://github.com/cypresssemiconductorco/audio-codec-ak4954a.
 * \}
 * \addtogroup group_board_libs_light
 * \{
 * The light sensor is handled by the sensor-light library, details are available at
 * https://github.com/cypresssemiconductorco/sensor-light.
 * \}
 * \addtogroup group_board_libs_motion
 * \{
 * The motion sensor is handled by the sensor-motion-bmi160 library, details are available at
 * https://github.com/cypresssemiconductorco/sensor-motion-bmi160.
 * \}
 * \addtogroup group_board_libs_display
 * \{
 * The display is handled by the display-tft-st7789v library, details are available at
 * https://github.com/cypresssemiconductorco/display-tft-st7789v.
 * \}
 */

/**
 * \addtogroup group_board_libs_shield
 * \{
 * Basic set of APIs for interacting with the CY8CKIT-028-TFT shield board.
 * This provides pin definitions and initialization code for the shield.
 * Initialization of the shield configures the internal peripherals to allow
 * them to be used.
 */

#if defined(__cplusplus)
extern "C"
{
#endif


/**
 * Initialize the shield board and all peripherals contained on it.
 * \note This will reserve all CY8CKIT_028_TFT_PIN_DISPLAY pins for the display.
 * @param[in] i2c_inst An optional I2C instance to use for communicating with
 * the motion sensor on the shield. If NULL, a new instance will be allocated
 * using the \ref CY8CKIT_028_TFT_PIN_IMU_I2C_SCL & \ref
 * CY8CKIT_028_TFT_PIN_IMU_I2C_SDA pins.
 * @param[in] adc_inst An optional adc instance to be used with the light
 * sensor. If NULL, a new instance will be allocated.
 * @param[in] pdm_pcm_cfg The configuration for the PDM object used with the microphone.
 * . If NULL, the PDM object will not be initialized.
 * @param[in] audio_clock_inst The audio clock used with the microphone.
 * . If NULL, the PDM object will not be initialized.
 * @return CY_RSLT_SUCCESS if properly initialized, else an error indicating what went wrong.
 */
cy_rslt_t cy8ckit_028_tft_init(cyhal_i2c_t* i2c_inst, cyhal_adc_t* adc_inst,
                               const cyhal_pdm_pcm_cfg_t* pdm_pcm_cfg,
                               cyhal_clock_t* audio_clock_inst);
// For more information about the pdm_pcm_cfg and audio_clock_inst parameters,
// see ../common/microphone_spk0838ht4hb.h

/**
 * Gives the user access to the light sensor object
 * @return A reference to the light sensor object on this shield.
 */
mtb_light_sensor_t* cy8ckit_028_tft_get_light_sensor(void);

/**
 * Gives the user access to the motion sensor object
 * @return A reference to the motion sensor object on this shield.
 */
mtb_bmi160_t* cy8ckit_028_tft_get_motion_sensor(void);

/**
 * Gives the user access to the PDM object use with the microphone.
 * This will be null if the arguments to setup the PDM interface were not provided.
 * @return A reference to the PDM microphone object on this shield.
 */
cyhal_pdm_pcm_t* cy8ckit_028_tft_get_pdm(void);

/**
 * Frees up any resources allocated as part of \ref cy8ckit_028_tft_init().
 */
void cy8ckit_028_tft_free(void);

#if defined(__cplusplus)
}
#endif

/** \} group_board_libs */
