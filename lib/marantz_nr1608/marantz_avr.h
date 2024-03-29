#ifndef __MARANTZ_AVR_H__
#define __MARANTZ_AVR_H__

typedef enum marantz_avr_cmd {
    // Power commands:
    MARANTZ_AVR_CMD_PWR_ON = 0,
    MARANTZ_AVR_CMD_PWR_OFF,
    MARANTZ_AVR_CMD_PWR_TOGGLE,
    // Volume commands:
    MARANTZ_AVR_CMD_VOLUME_UP,
    MARANTZ_AVR_CMD_VOLUME_DOWN,
    MARANTZ_AVR_CMD_VOLUME_DIRECT,
    MARANTZ_AVR_CMD_AUDIO_MUTE_ON,
    MARANTZ_AVR_CMD_AUDIO_MUTE_OFF,
    MARANTZ_AVR_CMD_AUDIO_MUTE_TOGGLE,
    // Input commands:
    MARANTZ_AVR_CMD_INPUT_NEXT,
    MARANTZ_AVR_CMD_INPUT_PREV,
    MARANTZ_AVR_CMD_INPUT_TUNER,
    MARANTZ_AVR_CMD_INPUT_CD,
    MARANTZ_AVR_CMD_INPUT_TV_AUDIO,  // not working on 1608
    MARANTZ_AVR_CMD_INPUT_DVD,
    MARANTZ_AVR_CMD_INPUT_CBL_SAT, // not working on 1608
    MARANTZ_AVR_CMD_INPUT_MEDIA_PLAYER,
    

    MARANTZ_AVR_CMD_NUM_CMDS
} marantz_avr_cmd_t;

#endif /* #ifndef __MARANTZ_AVR_H__ */
