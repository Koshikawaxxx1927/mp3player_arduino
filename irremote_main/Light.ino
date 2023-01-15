#include "Light.hpp"

void initialize_led() {
    // 流している曲ごとに光るピン
    pinMode(pin::first_led, OUTPUT);
    pinMode(pin::second_led, OUTPUT);
    pinMode(pin::third_led, OUTPUT);
    pinMode(pin::fourth_led, OUTPUT);
    // 音量の合わせて光るピン
    pinMode(pin::volume_led, OUTPUT);
}

// それぞれのピンの役割ごとに光らせる
void led_light(const Message& msg) {
    // 流していない曲のピンは消す
    digitalWrite(pin::first_led, LOW);
    digitalWrite(pin::second_led, LOW);
    digitalWrite(pin::third_led, LOW);
    digitalWrite(pin::fourth_led, LOW);
    // 流している曲だけ光らせる
    digitalWrite(msg.mp3 + 5, HIGH);
    // 音量の合わせて光らせる
    analogWrite(pin::volume_led, 8 * msg.volume);
}