public class View {
    public View() {
        background(255); // 背景を黒にする
        // 背景画像の読み取り
        img = loadImage("../../images/main.png");
        
        // 再生ボタンの描写
        strokeWeight(3);
        fill(255);
        circle(center.x(), center.y(), 2 * play_icon_length); //<>//
        draw_stop_button(new Vector(center.x(), int(screen_size.subtract(bar_height / 2).y())), play_icon_length);

        // 画像の描写
        image(img, origin.x(), origin.y(), screen_size.x(), screen_size.subtract(bar_height).y());

        // 曲のスキップボタン(次の曲)の描写
        draw_next_button(center, play_icon_length, true);
        // 曲のスキップボタン(前の曲)の描写
        draw_next_button(center, play_icon_length, false);
        // ボリュームバーを描写
        read_update_msg();
        // ボリュームの初期値を15としている
        // Arduinoから受信していると初期が遅れてしまうので
        // ハードコーディングをしている
        // これを変える時はArduinoの方も変えなければならない
        draw_volume_bar(15);
    }

    public void update(DFPlayerMessage msg) {
        switch (msg.type) {
            case Play : break;
            case Volume : draw_volume_bar(msg.data); break;
            case VolumeUp : draw_volume_bar(msg.data); break;
            case VolumeDown : draw_volume_bar(msg.data); break;
            case Sleep :  break;
            case Reset :  break;
            case Next :  break;
            case Previous :  break;
            case Pause : {
                is_playing = false;
                // 停止する
                draw_play_button(new Vector(center.x(), int(screen_size.subtract(bar_height / 2).y())), play_icon_length);
                break;
            }
            case Start : {
                is_playing = true;
                // 再生する
                draw_stop_button(new Vector(center.x(), int(screen_size.subtract(bar_height / 2).y())), play_icon_length);
                break;
            }
        }
    }
}