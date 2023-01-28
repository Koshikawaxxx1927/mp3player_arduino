#include "IRSensor.hpp"

IRSensor::IRSensor() {
    // 赤外線センサにピン番号を指定
    irrecv = new IRrecv(pin::ir_remote);
    // 赤外線(IR)受信モジュールを有効に
    irrecv->enableIRIn();
    is_playing = true;
}

void IRSensor::update(Message& msg) {
    if (irrecv->decode(&results)) {
        // 赤外線受信モジュールからデータを受信したかの確認
        switch (results.value) {
            case 0xFF30CF : {
                // 1曲目を流す
                msg.is_changed = true;
                msg.dfplayer_type = DFPlayerType::Play;
                msg.mp3 = 1;
                break;
            }
            case 0xFF18E7 : {
                // 2曲目を流す
                msg.is_changed = true;
                msg.dfplayer_type = DFPlayerType::Play;
                msg.mp3 = 2;
                break;
            }
            case 0xFF7A85 : {
                // 3曲目を流す
                msg.is_changed = true;
                msg.dfplayer_type = DFPlayerType::Play;
                msg.mp3 = 3;
                break;
            }
            case 0xFF10EF : {
                // 4曲目を流す
                msg.is_changed = true;
                msg.dfplayer_type = DFPlayerType::Play;
                msg.mp3 = 4;
                break;
            }
            case 0xFF02FD : {
                // 再生/停止を行う
                msg.is_changed = true;
                if (is_playing) {
                    is_playing = false;
                    msg.dfplayer_type = DFPlayerType::Pause;
                } else {
                    is_playing = true;
                    msg.dfplayer_type = DFPlayerType::Start;
                }
                Serial.write(msg.dfplayer_type);
                break;
            }
            case 0xFFC23D : {
                // 次の曲を流す
                msg.is_changed = true;
                msg.dfplayer_type = DFPlayerType::Next;
                break;
            }
            case 0xFF22DD : {
                // 前の曲を流す
                msg.is_changed = true;
                msg.dfplayer_type = DFPlayerType::Previous;
                break;
            }
            case 0xFF629D : {
                // ボリュームを上げる
                msg.dfplayer_type = DFPlayerType::VolumeUp;
                msg.is_changed = true;
                msg.volume ++;
                if (msg.volume > 30) msg.volume = 30;
                Serial.write(msg.dfplayer_type);
                Serial.write(msg.volume);
                break;
            }
            case 0xFFA857 : {
                // ボリュームを下げる
                msg.dfplayer_type = DFPlayerType::VolumeDown;
                msg.is_changed = true;
                msg.volume --;
                if (msg.volume < 0) msg.volume = 0;
                Serial.write(msg.dfplayer_type);
                Serial.write(msg.volume);
                break;
            }
        }
        irrecv->resume(); // 次の値を受け取る
    }
}