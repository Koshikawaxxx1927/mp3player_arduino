void read_update_msg() {
    if (dfplayer_port.available() > 0) {
        update_msg();
        //　msg変数が更新された時にウィンドウ上の見た目に反映させる
        screen_view.update(msg);
    }
}

void update_msg() {
    int data = dfplayer_port.read();
    switch (data) {
        case 0 : msg.type = DFPlayerType.Play; break;
        case 1 : {
            msg.type = DFPlayerType.Volume;
            do {} while (dfplayer_port.available() == 0);
            msg.data = dfplayer_port.read();
            break;
        }
        case 2 : msg.type = DFPlayerType.VolumeUp; break;
        case 3 : msg.type = DFPlayerType.VolumeDown; break;
        case 4 : msg.type = DFPlayerType.Sleep; break;
        case 5 : msg.type = DFPlayerType.Reset; break;
        case 6 : msg.type = DFPlayerType.Next; break;
        case 7 : msg.type = DFPlayerType.Previous; break;
        case 8 : msg.type = DFPlayerType.Pause; break;
        case 9 : msg.type = DFPlayerType.Start; break;
    }
}
