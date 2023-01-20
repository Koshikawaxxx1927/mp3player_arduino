#include "DFPlayer.hpp"
#include "SerialFromProcessing.hpp"
#include "IRSensor.hpp"
#include "DFRobotDFPlayerMini.h"

DFPlayer* myDFPlayer;
IRSensor* ir_remote;
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
    msg.is_changed = true;
    myDFPlayer->update(msg);
    led_light(msg); // LEDを光らせる
    // 赤外線センサ
    ir_remote = new IRSensor();
}

void loop() {
  read_update_msg(msg);
  ir_remote->update(msg);
  myDFPlayer->update(msg);
  led_light(msg); // LEDを光らせる
}