#pragma once

enum DFPlayerType {
    Play,
    Volume,
    VolumeUp,
    VolumeDown,
    Sleep,
    Reset,
    Next,
    Previous,
    Pause,
    Start,
};

typedef struct {
    union {
        DFPlayerType dfplayer_type;
    };

    union {
        uint8_t data;
    };
} Message;