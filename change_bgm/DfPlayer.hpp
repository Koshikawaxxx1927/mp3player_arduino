#pragma once
#include "Arduino.h"
#include "Message.hpp"
#include "Device.hpp"

class DFPlayer : public Device {
public:
    // コンストラクタ
    DFPlayer();
    DFPlayer(const DFPlayer&) = delete;
    // コピー代入演算子
    DFPlayer& operator=(const DFPlayer&) = delete;
    // デストラクタ
    virtual ~DFPlayer() = default;

    // メッセージを元に動作する関数
    void update(Message& msg) override;
private:
    // ソフトウェアシリアルライブラリ
    class SoftwareSerial* mySoftwareSerial;
    // DF Player用のライブラリ
    class DFRobotDFPlayerMini* myDFPlayer;
};