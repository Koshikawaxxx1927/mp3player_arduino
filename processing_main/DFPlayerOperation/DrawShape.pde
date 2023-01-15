void draw_triangle(Vector center, int length, boolean is_flip) {
    fill(0);
    Vector play_triangle1;
    Vector play_triangle2;
    Vector play_triangle3;
    if (is_flip) {
        // 再生アイコンを作るための頂点
        play_triangle1 = new Vector(int(center.x() + length / 2), center.y());
        play_triangle2 = new Vector(int(center.x() + length * cos(radians(-135))), int(center.y() + length * sin(radians(-135))));
        play_triangle3 = new Vector(int(center.x() + length * cos(radians(135))), int(center.y() + length * sin(radians(135))));
    } else {    
        // 再生アイコンを作るための頂点
        play_triangle1 = new Vector(int(center.x() - length / 2), center.y());
        play_triangle2 = new Vector(int(center.x() - length * cos(radians(-135))), int(center.y() - length * sin(radians(-135))));
        play_triangle3 = new Vector(int(center.x() - length * cos(radians(135))), int(center.y() - length * sin(radians(135))));
    }
    // 三角形描写
    triangle(play_triangle1.x(), play_triangle1.y(),
             play_triangle2.x(), play_triangle2.y(),
             play_triangle3.x(), play_triangle3.y());
}

void draw_play_button(Vector center, int length) {
    // 再生ボタンの描写
    strokeWeight(3);
    fill(255);
    circle(center.x(), center.y(), 2 * length);
    fill(0);
    draw_triangle(center.add(new Vector(12, 0)), length, true);
}
  
void draw_stop_button(Vector center, int length) {
    // 停止ボタンの描写
    strokeWeight(3);
    fill(255);
    circle(center.x(), center.y(), 2 * length);
    fill(0);
    int bar_height = 15;
    int bar_width = 2 * length - 40;
    rect(center.x() - 25, center.y() - length + 20, bar_height, bar_width);
    rect(center.x() + 10, center.y() - length + 20, bar_height, bar_width);
}

void draw_next_button(Vector center, int length, boolean is_next) {
    // 次の曲へのスキップボタンの描写
    fill(0);
    if (is_next) {
        int tri_diff = 100;
        int tri_len = 30;
        float bar_adjust = 0.7;
        draw_triangle(new Vector(center.x() + tri_diff, int(screen_size.subtract(bar_height / 2).y())), tri_len, true);
        rect(center.x() + tri_diff + 15,
            int(screen_size.subtract(bar_height / 2).y()) - length * sin(radians(45)) * bar_adjust,
            5, 2.0 * bar_adjust * length * sin(radians(45)));
    } else {
        int tri_diff = 100;
        int tri_len = 30;
        float bar_adjust = 0.7;
        draw_triangle(new Vector(center.x() - tri_diff, int(screen_size.subtract(bar_height / 2).y())), tri_len, false);
        rect(center.x() - tri_diff + 15 - tri_len * (0.5 + cos(radians(45))),
            int(screen_size.subtract(bar_height / 2).y()) - play_icon_length * sin(radians(45)) * bar_adjust,
            5, 2.0 * bar_adjust * play_icon_length * sin(radians(45)));
    }
}

void draw_volume_bar(int volume) {
    // 音声バーの描写
    // 古いボリュームバーを塗りつぶす
    fill(255);
    strokeWeight(0);
    rect(center.x() + 250,
            int(screen_size.subtract(bar_height / 2).y()) - 10,
            200, 25);
    strokeWeight(3);
    // 新しいボリュームバーを描写
    fill(0);
    int volume_bar_height = 5;
    int volume_bar_width = 200;
    int volume_level = 200 / 30;
    rect(center.x() + 250,
         int(screen_size.subtract(bar_height / 2).y()),
         volume_bar_width,
         volume_bar_height);
    rect(center.x() + 250,
         int(screen_size.subtract(bar_height / 2).y()) - 10,
         1,
         25);
    rect(center.x() + 250 + volume_bar_width,
         int(screen_size.subtract(bar_height / 2).y()) - 10,
         1,
         25);
    fill(255);
    circle(10 + center.x() + 250 + volume_level * volume,
           int(screen_size.subtract(bar_height / 2).y()) + volume_bar_height / 2,
           20);
           
    // 音声マーク
    fill(0);
    rect(center.x() + 190,
         int(screen_size.subtract(bar_height / 2).y()),
         10, 10);
    draw_triangle(new Vector(center.x() + 200,
                  int(screen_size.subtract(bar_height / 2).y()) + 5),
                  15,
                  false);
    // 音声マークから出る音の描写
    rect(center.x() + 217,
         int(screen_size.subtract(bar_height / 2).y() - volume_bar_height),
         2, 20);
    rect(center.x() + 225,
         it ),
         2, 26);
}
