#include "DFPlayer.hpp"
#include "SerialFromProcessing.hpp"

DFPlayer* myDFPlayer;
Message msg;
// SDカードの中に入っている曲の数
// 曲数を変えたら回路も変えなければならない
constexpr uint8_t mp3_num = 4;

void setup() {
    Serial.begin(9600);
    // LEDの初期化
    initialize_led();

    myDFPlayer = new DFPlayer();
    msg.dfplayer_type = DFPlayerType::Play;
    msg.mp3 = 1;
    msg.volume = 20;
    myDFPlayer->update(msg);
    led_light(msg); // LEDを光らせる
}

void loop() {
  read_update_msg(msg);
  led_light(msg); // LEDを光らせる
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