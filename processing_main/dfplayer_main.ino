#include "DFPlayer.hpp"
#include "Message.hpp"

DFPlayer* myDFPlayer;
Message msg;

void setup() {
    myDFPlayer = new DFPlayer();
    msg.dfplayer_type = DFPlayerType::Play;
    msg.data = 1;
    myDFPlayer->update(msg);
}

void loop() {
    msg.dfplayer_type = DFPlayerType::VolumeDown;
    msg.data = 1;
    // myDFPlayer->update(msg);
    delay(1000);
}