#include "dfplayer.hpp"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "Pin.hpp"

// コンストラクタ
DFPlayer::DFPlayer() {
    // ソフトウェアシリアルライブラリの初期化
    // tx->送信用 rx->受信用のピンとして設定
    mySoftwareSerial = new SoftwareSerial(pin::rx, pin::tx);

    // DF Player用のライブラリの初期化
    myDFPlayer = new DFRobotDFPlayerMini();
    
    mySoftwareSerial->begin(9600);

    Serial.println();
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

    if (!myDFPlayer->begin(*mySoftwareSerial)) {  // DFPlayerを初期化します。USBピンを使ってなければ、デバイスはSD(TF)カードが選択されます
    // 2秒以内に初期化できなかった場合はエラーメッセージを表示
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
        delay(0); // Code to compatible with ESP8266 watch dog.
    }
    }
    Serial.println(F("DFPlayer Mini online."));
      
    // ボリュームの初期値をセット(0~30);
    myDFPlayer->volume(30);
}

// メッセージを元に動作する関数
void DFPlayer::update(const Message& msg) {
    switch (msg.dfplayer_type) {
        case DFPlayerType::Play : myDFPlayer->play(1); break;
        case DFPlayerType::Volume : myDFPlayer->volume(30); break;
        case DFPlayerType::VolumeUp : myDFPlayer->volumeUp(); break;
        case DFPlayerType::VolumeDown : myDFPlayer->volumeDown(); break;
        case DFPlayerType::Sleep : myDFPlayer->sleep(); break;
        case DFPlayerType::Reset : myDFPlayer->reset(); break;
        case DFPlayerType::Next : myDFPlayer->next(); break;
        case DFPlayerType::Previous : myDFPlayer->previous(); break;
        case DFPlayerType::Pause : myDFPlayer->pause(); break;
        case DFPlayerType::Start : myDFPlayer->start(); break;
    }
}