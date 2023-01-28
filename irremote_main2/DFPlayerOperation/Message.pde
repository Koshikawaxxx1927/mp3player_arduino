// Arduinoに通知するメッセージ
// それぞれの操作が送られる
public enum DFPlayerType {
    Play,
    Volume,
    VolumeUp,
    VolumeDown,
    Sleep,
    Reset,
    Next,
    Previous,
    Pause,
    Start;
}

public class DFPlayerMessage {
    public DFPlayerMessage() { };
    public DFPlayerType type;
    public int data;
}
