/**
 * \addtogroup group_board_libs_microphone Microphone
 * \{
 * The microphone uses the HAL PDM_PCM driver for its initialization. There is
 * no custom driver for this hardware.
 *
 * Microphone Setup
 * ================
 *
 * To enable the microphone on the shield, these steps must be performed:
 *
 * -# Initialize a PLL
 * -# Initialize the audio subsystem clock
 * -# Configure the PDM support system
 *
 * \note For the microphone, there are two parameters passed to the shield
 *       initialization function:
 *       * cyhal_clock_t* - audio_clock in the example code below
 *       * cyhal_pdm_pcm_cfg_t* - configuration settings to use for the PDM
 *
 * \note If either of these are NULL, the microphone will not be enabled.
 *
 * 1. Initialize the PLL
 * ---------------------
 *
 * \note This example code is for a PSoC 6 device.
 *
 * \code
 * cyhal_clock_allocate(&pll_clock, CYHAL_CLOCK_BLOCK_PLL);
 * cyhal_clock_set_frequency(&pll_clock, &lt;AUDIO_SYS_CLOCK_HZ&gt;, NULL);
 * cyhal_clock_set_enabled(&pll_clock, true, true);
 * \endcode
 *
 * The value for &lt;AUDIO_SYS_CLOCK_HZ&gt; is discussed below. A typical value is
 * 16384000.
 *
 * 2. Initialize the audio subsystem clock
 * ---------------------------------------
 *
 * \note This example code is for a PSoC 6 device.
 *
 * \code
 * cyhal_clock_get(&audio_clock, & &lt;AUDIO_CLOCK_RESOURCE&gt;);
 * cyhal_clock_init(&audio_clock);
 * cyhal_clock_set_source(&audio_clock, &pll_clock);
 * cyhal_clock_set_enabled(&audio_clock, true, true);
 * \endcode
 *
 * An appropriate setting for &lt;AUDIO_CLOCK_RESOURCE&gt; is CYHAL_CLOCK_HF[1].
 *
 * 3. Configure the PDM support system
 * -----------------------------------
 *
 * This involves setting the values in the cyhal_pdm_pcm_cfg_t structure. It
 * also involves setting the value of &lt;AUDIO_SYS_CLOCK_HZ&gt;, referred to in
 * example code above.
 *
 * left_gain, right_gain - Typically set to 0. May be set to other values
 * to implement some sort of volume control.
 *
 * decimation_rate - Typically set to 32. May be changed to oversample the
 * PDM for non-voice applications. Or to downsample for low power
 * conditions. For example, implementing some kind of pink-noise wake-up.
 *
 * mode - Typically set to CYHAL_PDM_PCM_MODE_STEREO.
 *
 * sample_rate and &lt;AUDIO_SYS_CLOCK_HZ&gt; - For many applications, setting the
 * sample_rate to 8000 (Hz) and setting &lt;AUDIO_SYS_CLOCK_HZ&gt; to 16384000 will
 * be appropriate.
 *
 * The most common audio sample rates are 8, 16, 32, 44.1, and 48 Ksps.
 *
 * The minimum frequency for the PLL on PSoC 6 is 12.5 MHz. The value of
 * &lt;AUDIO_SYS_CLOCK_HZ&gt; is determined by the sample_rate multiplied by
 * the decimation_rate multiplied by some value (X) that makes the result
 * greater than 12.5 MHz. So, X needs to be at least 64. And that means that
 * the minimum clock frequency from the PLL to achieve the standard sample
 * rates is 16.384 MHz.
 *
 * <b>More information can be found here:</b>
 *
 * www.cypress.com/file/399201/download, chapter 29\n
 * cypresssemiconductorco.github.io/hal-mxs40/html/group__group__hal__pdmpcm.html
 *
 */

/** \} group_board_libs_microphone */
