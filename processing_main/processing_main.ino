#include "DFPlayer.hpp"
#include "Message.hpp"

DFPlayer* myDFPlayer;
Message msg;

void setup() {
    Serial.begin(9600);
    myDFPlayer = new DFPlayer();
    msg.dfplayer_type = DFPlayerType::Play;
    msg.data = 1;
    myDFPlayer->update(msg);
}

void loop() {
    if (Serial.available() > 0) {
        uint8_t data = Serial.read();
        Serial.println(data);
        switch (data) {
            case Play : msg.dfplayer_type = DFPlayerType::Play; break;
            case Volume : msg.dfplayer_type = DFPlayerType::Volume; break;
            case VolumeUp : msg.dfplayer_type = DFPlayerType::VolumeUp; break;
            case VolumeDown : msg.dfplayer_type = DFPlayerType::VolumeDown; break;
            case Sleep : msg.dfplayer_type = DFPlayerType::Sleep; break;
            case Reset : msg.dfplayer_type = DFPlayerType::Reset; break;
            case Next : msg.dfplayer_type = DFPlayerType::Next; break;
            case Previous : msg.dfplayer_type = DFPlayerType::Previous; break;
            case Pause : msg.dfplayer_type = DFPlayerType::Pause; break;
            case Start : msg.dfplayer_type = DFPlayerType::Start; break;
        }
        myDFPlayer->update(msg);
    }
  // msg.dfplayer_type = DFPlayerType::Pause;
  // myDFPlayer->update(msg);
  // delay(3000);
  // msg.dfplayer_type = DFPlayerType::Start;
  // myDFPlayer->update(msg);
  // delay(3000);
}