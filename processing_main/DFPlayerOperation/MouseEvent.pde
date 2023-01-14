boolean is_playing = true;

void mouseClicked() {
    // クリックされた時の処理
    if (dist(center.x(), screen_size.subtract(bar_height / 2).y(), mouseX, mouseY) <= play_icon_length) {
        // プレイ/停止アイコンをクリックした場合
        if (is_playing) {
            // 停止する
            draw_play_button(new Vector(center.x(), int(screen_size.subtract(bar_height / 2).y())), play_icon_length);
            is_playing = false;
            // Arduinoへのシリアルポートを送信(停止)
            // ArduinoプログラムではPauseとなる
            dfplayer_port.write(8);
        } else {
            // 再生する //<>//
            draw_stop_button(new Vector(center.x(), int(screen_size.subtract(bar_height / 2).y())), play_icon_length);
            is_playing = true;
            // Arduinoへのシリアルポートを送信(再生)
            // ArduinoプログラムではStart
            dfplayer_port.write(9);
        }
    }
}

void mouseMoved() {
    if (dist(center.x(), screen_size.subtract(bar_height / 2).y(), mouseX, mouseY) <= play_icon_length) {
        // 再生/停止ボタンのポインター
        cursor(HAND);
    } else if ((int(screen_size.subtract(bar_height / 2).y())) - 30 * sin(radians(45)) < mouseY && mouseY < int(screen_size.subtract(bar_height / 2).y()) + 30 * sin(radians(45))) {
        if (center.x() + 75 < mouseX && mouseX < center.x() + 115 + 5) {
            // スキップボタンのポインター変化
            cursor(HAND);
        } else if (center.x() - 115 - 5 < mouseX && mouseX < center.x() - 75) {
            // スキップボタンのポインター変化
            cursor(HAND);
        } else {
            cursor(ARROW);
        }
    } else {
        cursor(ARROW);
    }
}
