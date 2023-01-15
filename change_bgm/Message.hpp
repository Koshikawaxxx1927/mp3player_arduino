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
        struct {
            uint8_t mp3;
            uint8_t volume;
        };
    };
} Message;