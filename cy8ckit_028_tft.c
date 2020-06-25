/***************************************************************************//**
* \file cy8ckit_028_tft.c
*
* \brief
*    Implementation file of the shield support library.
*
********************************************************************************
* \copyright
* Copyright 2018-2020 Cypress Semiconductor Corporation
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

#include "cy8ckit_028_tft.h"

static cyhal_adc_t adc;
static cyhal_i2c_t i2c;
static mtb_bmi160_t motion_sensor;
static mtb_light_sensor_t light_sensor;
static cyhal_pdm_pcm_t cy8ckit_028_tft_pdm_pcm;

static cyhal_adc_t *adc_ptr;
static cyhal_i2c_t *i2c_ptr;
static bool microphone_initialized = false;

static const mtb_st7789v_pins_t tft_pins =
{
    .db08 = CY8CKIT_028_TFT_PIN_DISPLAY_DB8,
    .db09 = CY8CKIT_028_TFT_PIN_DISPLAY_DB9,
    .db10 = CY8CKIT_028_TFT_PIN_DISPLAY_DB10,
    .db11 = CY8CKIT_028_TFT_PIN_DISPLAY_DB11,
    .db12 = CY8CKIT_028_TFT_PIN_DISPLAY_DB12,
    .db13 = CY8CKIT_028_TFT_PIN_DISPLAY_DB13,
    .db14 = CY8CKIT_028_TFT_PIN_DISPLAY_DB14,
    .db15 = CY8CKIT_028_TFT_PIN_DISPLAY_DB15,
    .nrd = CY8CKIT_028_TFT_PIN_DISPLAY_NRD,
    .nwr = CY8CKIT_028_TFT_PIN_DISPLAY_NWR,
    .dc = CY8CKIT_028_TFT_PIN_DISPLAY_DC,
    .rst = CY8CKIT_028_TFT_PIN_DISPLAY_RST,
};


/*******************************************************************************
 * Initializes the entire shield, included components and related resources
 * (I2C, etc)
*******************************************************************************/
cy_rslt_t cy8ckit_028_tft_init(cyhal_i2c_t *i2c_inst, cyhal_adc_t *adc_inst,
                               cyhal_pdm_pcm_cfg_t *pdm_pcm_cfg,
                               cyhal_clock_t *audio_clock_inst)
{
    cy_rslt_t rslt = CY_RSLT_SUCCESS;

    if (NULL == i2c_inst)
    {
        static const cyhal_i2c_cfg_t I2C_CFG = {
            .is_slave = false,
            .address = 0,
            .frequencyhal_hz = 400000
        };
        cy_rslt_t rslt = cyhal_i2c_init(&i2c, CY8CKIT_028_TFT_PIN_IMU_I2C_SDA,
                CY8CKIT_028_TFT_PIN_IMU_I2C_SCL, NULL);
        if (CY_RSLT_SUCCESS == rslt)
        {
            i2c_ptr = &i2c;
            rslt = cyhal_i2c_configure(&i2c, &I2C_CFG);
        }
    }
    else
    {
        i2c_ptr = i2c_inst;
    }

    if (NULL == adc_inst)
    {
        rslt = cyhal_adc_init(&adc, CY8CKIT_028_TFT_PIN_ALS_OUT, NULL);
        if (CY_RSLT_SUCCESS == rslt)
        {
            adc_ptr = &adc;
        }
    }
    else
    {
        adc_ptr = adc_inst;
    }

    if (CY_RSLT_SUCCESS == rslt)
        rslt = mtb_st7789v_init8(&tft_pins);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = mtb_light_sensor_init(&light_sensor, adc_ptr, CY8CKIT_028_TFT_PIN_ALS_OUT);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = mtb_bmi160_init_i2c(&motion_sensor, i2c_ptr, MTB_BMI160_DEFAULT_ADDRESS);
    if (CY_RSLT_SUCCESS == rslt)
        rslt = mtb_ak4954a_init(i2c_ptr);

    /* Initialize the PDM/PCM block and audio codec */
    if ((CY_RSLT_SUCCESS == rslt) && (NULL != audio_clock_inst) && (NULL != pdm_pcm_cfg))
    {
        microphone_initialized = true;

        rslt = cyhal_pdm_pcm_init(&cy8ckit_028_tft_pdm_pcm, CY8CKIT_028_TFT_PIN_PDM_DATA,
                                  CY8CKIT_028_TFT_PIN_PDM_CLK, audio_clock_inst, pdm_pcm_cfg);
    }

    if (CY_RSLT_SUCCESS != rslt)
        cy8ckit_028_tft_free();

    return rslt;
}


/*******************************************************************************
 * Gives the user access to the light sensor object
*******************************************************************************/
mtb_light_sensor_t* cy8ckit_028_tft_get_light_sensor(void)
{
    return &light_sensor;
}


/*******************************************************************************
 * Gives the user access to the motion sensor object
*******************************************************************************/
mtb_bmi160_t* cy8ckit_028_tft_get_motion_sensor(void)
{
    return &motion_sensor;
}


/*******************************************************************************
 * Gives the user access to the PDM object
*******************************************************************************/
cyhal_pdm_pcm_t * cy8ckit_028_tft_get_pdm(void)
{
    return &cy8ckit_028_tft_pdm_pcm;
}


/*******************************************************************************
 * Frees resources associated with the shield
*******************************************************************************/
void cy8ckit_028_tft_free(void)
{
    mtb_st7789v_free();

    if (i2c_ptr == &i2c)
        cyhal_i2c_free(i2c_ptr);
    i2c_ptr = NULL;

    if (microphone_initialized)
    {
        microphone_initialized = false;
        cyhal_pdm_pcm_free(&cy8ckit_028_tft_pdm_pcm);
    }

    mtb_ak4954a_free();
    mtb_light_sensor_free(&light_sensor);
    mtb_bmi160_free(&motion_sensor);

    /* This must be done last, in case other code prior to this frees
     * an ADC channel */
    if (adc_ptr == &adc)
        cyhal_adc_free(&adc);
}
