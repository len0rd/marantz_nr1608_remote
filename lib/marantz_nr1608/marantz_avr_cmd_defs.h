// All the definitions for the various Marantz remote control commands
//  this header is generally for internal use. Use marantz_avr.h for external library use
#ifndef __MARANTZ_AVR_CMD_DEFS_H__
#define __MARANTZ_AVR_CMD_DEFS_H__

#include <Arduino.h>
#include "marantz_avr.h"

// the default RC5/RC5x address Marantz uses
#define DEFAULT_MARANTZ_ADDRESS 16

typedef uint8_t marantz_avr_cmd_id_t;

typedef enum marantz_avr_cmd_type {
    MARANTZ_TYPE_INVALID = 0,
    MARANTZ_TYPE_RC5,
    MARANTZ_TYPE_RC5X,

    MARANTZ_TYPE_NUM_TYPES
} marantz_avr_cmd_type_t;

// describes parameters for an avr command
typedef struct marantz_avr_cmd_config {
    marantz_avr_cmd_type_t type;    // what type of command is this (RC5? RC5X?)
    marantz_avr_cmd_id_t address;   // the command's RC5 address
    marantz_avr_cmd_id_t command;   // the command's RC5 command code
    marantz_avr_cmd_id_t extension; // the command's RC5X extension (only used if RC5X command)
    bool ranged_extension;          // RC5x only. The command accepts a range of extension values (eg: direct audio volume)
    marantz_avr_cmd_id_t ranged_extension_min; // min value for the extension field of a ranged RC5x command
    marantz_avr_cmd_id_t ranged_extension_max; // max value for the extension field of a ranged RC5x command
} marantz_avr_cmd_config_t;

/*
 * define ALL the commands
 * These are based off Marantz's IR code list document, which I found here:
 * 
 * https://www.google.com/search?q=marantz+master+ir+hex+codes
 * 
 */

static const marantz_avr_cmd_config_t MARANTZ_AVR_CMDS[] = {
    [MARANTZ_AVR_CMD_PWR_ON]        = {.type    = MARANTZ_TYPE_RC5X,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 12,
                                       .extension = 1},
    [MARANTZ_AVR_CMD_PWR_OFF]       = {.type    = MARANTZ_TYPE_RC5X,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 12,
                                       .extension = 2},
    [MARANTZ_AVR_CMD_PWR_TOGGLE]    = {.type = MARANTZ_TYPE_RC5,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 12},
    [MARANTZ_AVR_CMD_VOLUME_UP]     = {.type = MARANTZ_TYPE_RC5,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 16},
    [MARANTZ_AVR_CMD_VOLUME_DOWN]   = {.type = MARANTZ_TYPE_RC5,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 17},
    [MARANTZ_AVR_CMD_VOLUME_DIRECT] = {.type = MARANTZ_TYPE_RC5X,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 111,
                                       .extension = 0,
                                       .ranged_extension = true,
                                       .ranged_extension_min = 0,
                                       .ranged_extension_max = 63},
    [MARANTZ_AVR_CMD_AUDIO_MUTE_ON] = {.type = MARANTZ_TYPE_RC5X,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 13,
                                       .extension = 0},
    [MARANTZ_AVR_CMD_AUDIO_MUTE_OFF]    = {.type = MARANTZ_TYPE_RC5X,
                                           .address = DEFAULT_MARANTZ_ADDRESS,
                                           .command = 13,
                                           .extension = 1},
    [MARANTZ_AVR_CMD_AUDIO_MUTE_TOGGLE] = {.type = MARANTZ_TYPE_RC5,
                                           .address = 16,
                                           .command = 13},
    [MARANTZ_AVR_CMD_INPUT_NEXT]    = {.type = MARANTZ_TYPE_RC5X,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 0,
                                       .extension = 13},
    [MARANTZ_AVR_CMD_INPUT_PREV]    = {.type = MARANTZ_TYPE_RC5X,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 0,
                                       .extension = 14},
    [MARANTZ_AVR_CMD_INPUT_TUNER]   = {.type = MARANTZ_TYPE_RC5,
                                       .address = 17,
                                       .command = 63},
    [MARANTZ_AVR_CMD_INPUT_CD]      = {.type = MARANTZ_TYPE_RC5,
                                       .address = 20,
                                       .command = 63},
    [MARANTZ_AVR_CMD_INPUT_TV_AUDIO]= {.type = MARANTZ_TYPE_RC5,
                                       .address = 0,
                                       .command = 63},
    [MARANTZ_AVR_CMD_INPUT_DVD]     = {.type = MARANTZ_TYPE_RC5X,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 0,
                                       .extension = 10},
    [MARANTZ_AVR_CMD_INPUT_CBL_SAT] = {.type = MARANTZ_TYPE_RC5,
                                       .address = DEFAULT_MARANTZ_ADDRESS,
                                       .command = 63},
    [MARANTZ_AVR_CMD_INPUT_MEDIA_PLAYER] = {.type = MARANTZ_TYPE_RC5,
                                            .address = 5,
                                            .command = 63}
};

#endif /* #ifndef __MARANTZ_AVR_CMD_DEFS_H__ */
