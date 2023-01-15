#include "DFPlayer.hpp"
#include "SerialFromProcessing.hpp"

DFPlayer* myDFPlayer;
Message msg;
constexpr uint8_t mp3_num = 4; // SDカードの中に入っている曲の数

void setup() {
    Serial.begin(9600);
    myDFPlayer = new DFPlayer();
    msg.dfplayer_type = DFPlayerType::Play;
    msg.mp3 = 1;
    myDFPlayer->update(msg);
}

void loop() {
  read_update_msg(msg);
  //   delay(9000);
  //   msg.dfplayer_type = DFPlayerType::Next;
  //   myDFPlayer->update(msg);
  // // for (int i = 0; i < 4; ++i){
  // //     msg.dfplayer_type = DFPlayerType::Play;
  // //     msg.data = i+1;
  // //     read_update_msg(msg); // Processingからのデータを読み込む
  // //     myDFPlayer->update(msg);
  // //     Serial.println(msg.data);
  // //     delay(9000);
  // // }
}