#include "DFPlayer.hpp"
#include "Message.hpp"

DFPlayer* myDFPlayer;
Message msg;

void setup() {
    myDFPlayer = new DFPlayer();
    msg.type = Message::Type::Play;
    msg.data = 1;
    myDFPlayer->update(msg);
}

void loop() {
  
}