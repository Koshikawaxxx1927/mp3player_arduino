#include "SerialFromProcessing.hpp"

void read_update_msg(Message& msg) {
    if (Serial.available() > 0) {
        uint8_t data = Serial.read();
        __serial::update_msg(msg, data);
        myDFPlayer->update(msg);
    }
}

void __serial::update_msg(Message &msg, uint8_t data) {
    switch (data) {
        case Play : msg.dfplayer_type = DFPlayerType::Play; break;
        case Volume : {
            msg.dfplayer_type = DFPlayerType::Volume;
            do {
            } while (Serial.available() == 0);
            msg.volume = Serial.read();
            break;
        }
        case VolumeUp : msg.dfplayer_type = DFPlayerType::VolumeUp; break;
        case VolumeDown : msg.dfplayer_type = DFPlayerType::VolumeDown; break;
        case Sleep : msg.dfplayer_type = DFPlayerType::Sleep; break;
        case Reset : msg.dfplayer_type = DFPlayerType::Reset; break;
        case Next : msg.dfplayer_type = DFPlayerType::Next; break;
        case Previous : msg.dfplayer_type = DFPlayerType::Previous; break;
        case Pause : msg.dfplayer_type = DFPlayerType::Pause; break;
        case Start : msg.dfplayer_type = DFPlayerType::Start; break;
    }
}