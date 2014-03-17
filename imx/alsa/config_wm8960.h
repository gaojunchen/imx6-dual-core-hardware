/*
 * Copyright (C) 2011 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/* Copyright (C) 2012 Freescale Semiconductor, Inc. */

#ifndef ANDROID_INCLUDE_IMX_CONFIG_WM8960_H
#define ANDROID_INCLUDE_IMX_CONFIG_WM8960_H

#include "audio_hardware.h"


#define MIXER_WM8960_SPEAKER_VOLUME                 "Speaker Playback Volume"
#define MIXER_WM8960_SPEAKER_SWITCH                 "ClassD Speaker Control"
#define MIXER_WM8960_HEADPHONE_VOLUME               "Headphone Playback Volume"
#define MIXER_WM8960_PCM_PLAYBACK_LEFT_SWITCH          "Left Output Mixer PCM Playback Switch"
#define MIXER_WM8960_PCM_PLAYBACK_RIGHT_SWITCH         "Right Output Mixer PCM Playback Switch"


#define MIXER_WM8960_CAPTURE_SWITCH                 "Capture Switch"
#define MIXER_WM8960_CAPTURE_VOLUME                 "Capture Volume"

#define MIXER_WM8960_BOOST_SWITCH_L 				"Left Input Mixer Boost Switch"
#define MIXER_WM8960_BOOST_SWITCH_R 				"Right Input Mixer Boost Switch"

#define MIXER_WM8960_INPGAR_IN3R_SWITCH             "INPGAR IN3R Switch"
#define MIXER_WM8960_MIXINR_IN3R_SWITCH             "MIXINR IN3R Switch"
#define MIXER_WM8960_MIXINR_IN3R_VOLUME             "MIXINR IN3R Volume"

#define MIXER_WM8960_MIXINR_PGA_SWITCH              "MIXINR PGA Switch"
#define MIXER_WM8960_MIXINR_PGA_VOLUME              "MIXINR PGA Volume"

#define MIXER_WM8960_DIGITAL_CAPTURE_VOLUME         "Digital Capture Volume"

#define MIXER_WM8960_DIGITAL_PLAYBACK_VOLUME        "Playback Volume"

#define MIXER_FM_OUTPUT_L 							"Left Output Mixer LINPUT3 Switch"
#define MIXER_FM_OUTPUT_R 							"Right Output Mixer RINPUT3 Switch"

/* These are values that never change */
static struct route_setting defaults_wm8960[] = {
    /* general */
    {
        .ctl_name = MIXER_WM8960_DIGITAL_PLAYBACK_VOLUME,
        .intval = 250,
    },
#if  1
    /* Default set the path to DAC when no speaker and mic */
    {
        .ctl_name = MIXER_WM8960_PCM_PLAYBACK_LEFT_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_PCM_PLAYBACK_RIGHT_SWITCH,
        .intval = 1,
    },
#endif
    {
        .ctl_name = NULL,
    },
};

static struct route_setting bt_output_wm8960[] = {
    {
        .ctl_name = NULL,
    },
};

static struct route_setting speaker_output_wm8960[] = {
    {
        .ctl_name = MIXER_WM8960_SPEAKER_SWITCH,
        .intval = 3,
    },
    {
        .ctl_name = MIXER_WM8960_SPEAKER_VOLUME,
        .intval = 127,
    },
    {
        .ctl_name = NULL,
    },
};

static struct route_setting hs_output_wm8960[] = {
    {
        .ctl_name = MIXER_WM8960_HEADPHONE_VOLUME,
        .intval = 110,
    },
    {
        .ctl_name = NULL,
    },
};

static struct route_setting earpiece_output_wm8960[] = {
    {
        .ctl_name = NULL,
    },
};

static struct route_setting vx_hs_mic_input_wm8960[] = {
    {
        .ctl_name = NULL,
    },
};


static struct route_setting mm_main_mic_input_wm8960[] = {
    {
        .ctl_name = MIXER_WM8960_CAPTURE_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_BOOST_SWITCH_L,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_BOOST_SWITCH_R,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_CAPTURE_VOLUME,
        .intval = 55,
    },
    {
        .ctl_name = MIXER_WM8960_DIGITAL_CAPTURE_VOLUME,
        .intval = 0,
    },/*
    {
        .ctl_name = MIXER_WM8960_INPGAR_IN3R_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_MIXINR_PGA_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_MIXINR_PGA_VOLUME,
        .intval = 7,
    },*/
    {
        .ctl_name = MIXER_WM8960_MIXINR_IN3R_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_MIXINR_IN3R_VOLUME,
        .intval = 0,
    },
    {
        .ctl_name = NULL,
    },
};


static struct route_setting vx_main_mic_input_wm8960[] = {
    {
        .ctl_name = NULL,
    },
};

/*hs_mic exchanged with main mic for sabresd, because the the main is no implemented*/
static struct route_setting mm_hs_mic_input_wm8960[] = {
    {
        .ctl_name = MIXER_WM8960_CAPTURE_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_BOOST_SWITCH_R,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_CAPTURE_VOLUME,
        .intval = 55,
    },
    {
        .ctl_name = MIXER_WM8960_DIGITAL_CAPTURE_VOLUME,
        .intval = 0,
    },/*
    {
        .ctl_name = MIXER_WM8960_INPGAR_IN3R_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_MIXINR_PGA_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_MIXINR_PGA_VOLUME,
        .intval = 7,
    },*/
    {
        .ctl_name = MIXER_WM8960_MIXINR_IN3R_SWITCH,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_WM8960_MIXINR_IN3R_VOLUME,
        .intval = 0,
    },
    {
        .ctl_name = NULL,
    },
};

static struct route_setting vx_bt_mic_input_wm8960[] = {
    {
        .ctl_name = NULL,
    },
};


static struct route_setting mm_bt_mic_input_wm8960[] = {
    {
        .ctl_name = NULL,
    },
};

static struct route_setting fm_output_path_wm8960[] = {
    {
        .ctl_name = MIXER_FM_OUTPUT_L,
        .intval = 1,
    },
    {
        .ctl_name = MIXER_FM_OUTPUT_R,
        .intval = 1,
    },
    {
        .ctl_name = NULL,
    },
};
/* ALSA cards for IMX, these must be defined according different board / kernel config*/
static struct audio_card  wm8960_card = {
    .name = "wm8960-audio",
    .driver_name = "wm8960-audio",
    .supported_devices = (AUDIO_DEVICE_OUT_EARPIECE |
            AUDIO_DEVICE_OUT_SPEAKER |
            AUDIO_DEVICE_OUT_WIRED_HEADSET |
            AUDIO_DEVICE_OUT_WIRED_HEADPHONE |
            AUDIO_DEVICE_OUT_ANLG_DOCK_HEADSET |
            AUDIO_DEVICE_OUT_DGTL_DOCK_HEADSET |
            AUDIO_DEVICE_OUT_ALL_SCO |
            AUDIO_DEVICE_OUT_DEFAULT |
            /* IN */
            AUDIO_DEVICE_IN_COMMUNICATION |
            AUDIO_DEVICE_IN_AMBIENT |
            AUDIO_DEVICE_IN_BUILTIN_MIC |
            AUDIO_DEVICE_IN_WIRED_HEADSET |
            AUDIO_DEVICE_IN_BACK_MIC |
            AUDIO_DEVICE_IN_ALL_SCO |
            AUDIO_DEVICE_IN_DEFAULT),
    .defaults            = defaults_wm8960,
    .bt_output           = bt_output_wm8960,
    .speaker_output      = speaker_output_wm8960,
    .hs_output           = hs_output_wm8960,
    .earpiece_output     = earpiece_output_wm8960,
    .vx_hs_mic_input     = vx_hs_mic_input_wm8960,
    .mm_main_mic_input   = mm_main_mic_input_wm8960,
    .vx_main_mic_input   = vx_main_mic_input_wm8960,
    .mm_hs_mic_input     = mm_hs_mic_input_wm8960,
    .vx_bt_mic_input     = vx_bt_mic_input_wm8960,
    .mm_bt_mic_input     = mm_bt_mic_input_wm8960,
	.fm_output 			 = fm_output_path_wm8960,
    .card                = 0,
    .out_rate            = 0,
    .in_rate             = 0,
};

#endif  /* ANDROID_INCLUDE_IMX_CONFIG_WM8960_H */
