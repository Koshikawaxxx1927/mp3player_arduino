import processing.serial.*;

Serial dfplayer_port; // Arduinoへのシリアルポート
Vector origin; // ウィンドウ上の原点
Vector screen_size; // ウィンドウの大きさ
Vector center; // ウィンドウの中点

// DF Playerから読み取ったメッセージを保存する
DFPlayerMessage msg;

// 再生アイコンを作るための頂点
Vector play_triangle1;
Vector play_triangle2;
Vector play_triangle3;

PImage img; // 背景画像
int bar_height; // 画像下のバーの高さ
int play_icon_length; // 再生アイコンの長さ

void setup() {
    size(1000, 700); // ウィンドウの大きさ(必ず最初に実行)
    screen_size = new Vector(1000, 700); // ウィンドウの大きさ
    origin = new Vector(0, 0); // ウィンドウ上の原点
    center = screen_size.divide(2); // ウィンドウの中点
    bar_height = 120; // 画像下のバーの高さ
    play_icon_length = 50; // 再生アイコンの長さ
    
    // Arduinoからのメッセージを保存する
    msg = new DFPlayerMessage();
    
    background(255); // 背景を黒にする
    // Arduinoへのシリアルポートの設定
    String arduinoPort = Serial.list()[2];
    dfplayer_port = new Serial(this, arduinoPort, 9600);

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
    fill(255);
    strokeWeight(0);
    rect(center.x() + 250,
         int(screen_size.subtract(bar_height / 2).y()) - 10,
         200, 25);
    strokeWeight(3);
    read_update_msg();
    draw_volume_bar(msg.data);
}

void draw() {
    read_update_msg(); //<>//
    //if (msg.type == DFPlayerType.Volume) { //<>//
    //    draw_volume_bar(msg.data); //<>//
    //}
}
