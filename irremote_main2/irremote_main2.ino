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
    // 起こると最初から再生する割り込み登録
    attachInterrupt(pin::replay, replay, FALLING);
}

void loop() {
  // Processingからの読み取りとmsgの更新
  read_update_msg(msg);
  // 赤外線センサからの読み取りとmsgの更新
  ir_remote->update(msg);
  // 更新されたmsgをもとにDFPlayer miniを動作させる
  myDFPlayer->update(msg);
  led_light(msg); // LEDを光らせる
}

void replay() {
  // 再生中の音楽を最初から再生するための割り込み関数
  msg.dfplayer_type = DFPlayerType::Play;
  msg.is_changed = true;
}