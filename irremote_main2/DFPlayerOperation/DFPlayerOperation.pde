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

View screen_view; // ウィンドウ上のボタン等を描写

void setup() {
    size(1000, 700); // ウィンドウの大きさ(必ず最初に実行)
    screen_size = new Vector(1000, 700); // ウィンドウの大きさ
    origin = new Vector(0, 0); // ウィンドウ上の原点
    center = screen_size.divide(2); // ウィンドウの中点
    bar_height = 120; // 画像下のバーの高さ
    play_icon_length = 50; // 再生アイコンの長さ
    
    // Arduinoからのメッセージを保存する
    msg = new DFPlayerMessage();
    
    // Arduinoへのシリアルポートの設定
    String arduinoPort = Serial.list()[2];
    dfplayer_port = new Serial(this, arduinoPort, 9600);
    
    msg.type = DFPlayerType.Play;
    screen_view = new View(); // ウィンドウ上のボタン等を描写
}

void draw() {
    // Arduinoからのメッセージを受け取って更新する
    read_update_msg();
}
