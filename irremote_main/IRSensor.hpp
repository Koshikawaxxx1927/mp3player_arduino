#pragma once
#include "Pin.hpp"
#include <IRremote.h>        // ライブラリのインクルード

class IRSensor : public Device {
public:
    // コンストラクタ
    IRSensor();
    IRSensor(const IRSensor&) = delete;
    // コピー代入演算子
    IRSensor& operator=(const IRSensor&) = delete;
    // デストラクタ
    virtual ~IRSensor() = default;
    // 赤外線リモコンに応じてメッセージを更新
    void update(Message& msg) override;
private:
    // IR受信オブジェクトの生成(使用ピンを指定)
    IRrecv* irrecv;  
    // 受信情報の格納先(メーカー名/受信したデータ&ビット数など)
    decode_results results;
    // 音楽が再生中の時true
    bool is_playing;
};