#include "Message.hpp"

// ピンの設定をする
void initialize_led();

// それぞれのピンの役割ごとに光らせる
void led_light(const Message& msg);