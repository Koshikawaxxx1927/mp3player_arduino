#include <IRremote.h>        // ライブラリのインクルード
const int ReceiverPin = 11;  // 赤外線受信モジュール接続ピンをD2に
 
IRrecv irrecv(ReceiverPin);  // IR受信オブジェクトの生成(使用ピンを指定)
decode_results results;      // 受信情報の格納先(メーカー名/受信したデータ&ビット数など)
 
void setup() {
 
  Serial.begin(9600);       // シリアルポートを初期化
  irrecv.enableIRIn();        // 赤外線(IR)受信モジュールを有効に
 
  delay(500);
  Serial.println("リモコンのキーを押して下さい！");
 
}
 
 
void loop() {
  
  if (irrecv.decode(&results)){            // 赤外線受信モジュールからデータを受信したかの確認
 
    if( results.value == 0xFF30CF){       // "2"が押された時
      Serial.println("1キーON");
    }
    else if( results.value == 0xFF18E7 ){  // "8"が押された時
      Serial.println("2キーON");
    }
    else if (results.value == 0xFF7A85) {
      Serial.println("3キーON");
    }
    else if( results.value == 0xFF10EF ){  // "4"が押された時
      Serial.println("4キーON");
    }
    else if( results.value == 0xFF02FD ){  // "6"が押された時
      Serial.println("Play ON");  
    }
    else if( results.value == 0xFFC23D ){  // "5"が押された時
      Serial.println("Next ON");
    } else if( results.value == 0xFF22DD ){  // "5"が押された時
      Serial.println("Previous ON");
    } else if( results.value == 0xFF629D ){  // "5"が押された時
      Serial.println("Volume UP");
    } else if( results.value == 0xFFA857 ){  // "5"が押された時
      Serial.println("Volume DOWN");
    }
    else Serial.println("未割り当てのキー");   // 未割り当てのキーが押された時
 
    Serial.print("IRコード: "); 
    Serial.print(results.value, HEX);       // 16進数で受信値を出力
    Serial.print(",  ビット: ");
    Serial.println(results.bits);           // ビット数(受信値長)を出力
    Serial.println("");
   
    irrecv.resume();                        // 次の値を受け取る
    
  }
 
  delay(500);
 
}