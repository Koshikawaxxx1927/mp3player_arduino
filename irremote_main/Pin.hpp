#pragma once

namespace pin {
    // DF Player用のRXピン(受信)
    constexpr uint8_t rx = 3;
    // DF Player用のTXピン(送信)
    constexpr uint8_t tx = 5;

    // LEDライトのピン
    constexpr uint8_t first_led = 6; // 1曲目
    constexpr uint8_t second_led = 7; // 2曲目
    constexpr uint8_t third_led = 8; // 3曲目
    constexpr uint8_t fourth_led = 9; // 4曲目
    // 音量に合わせて光るLEDのピン
    constexpr uint8_t volume_led = 10;

    // 赤外線受信モジュール接続ピン
    constexpr uint8_t ir_remote = 11;
};