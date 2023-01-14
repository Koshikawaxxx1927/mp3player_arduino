#include "DFPlayer.hpp"
#include "SerialFromProcessing.hpp"

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
    read_update_msg(msg); // Processingからのデータを読み込む
}