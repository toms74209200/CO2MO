## Chapt. 2 通信

[chapt.1](https://github.com/toms74209200/CO2MO/blob/master/learning/chapt1/hello_world) ではUSBシリアル通信を行いました. ここではGPIOピンと共有している周辺機能を利用して外部装置との通信を行います. 外部装置との通信により外部装置を操作することができます.

### 2-1 OLED ディスプレイ上での「Hello World」

広く利用されているデバイスではその通信処理がライブラリとして提供されている場合があります. ここで使用するOLEDディスプレイもSSD1306という広く利用されているものを使用します. ここではI2Cという通信規格[[1](#arduino_wire)] を使用してOLEDディスプレイ（のドライバであるSSD1306）との通信を行います. 本来I2Cの通信規格とデバイスの動作仕様に基づいて操作する必要がありますが, 公開されているライブラリを利用することで動作仕様を意識せずに実装することができます.

#### ライブラリのインポート

下記では使用する `Adafruit_SSD1306` と `Adafruit_GFX` ライブラリのインストールを行います[[2](#adafruit_ssd1306)]. 環境構築の際にインストールしている場合は不要です.

メニューで「スケッチ」>「ライブラリをインクルード」>「ライブラリを管理…」を選択し「ライブラリマネージャ」を開きます. 「ライブラリマネージャ」で `Adafruit_SSD1306` と `Adafruit_GFX` を検索しインストールします.

#### ライブラリの利用

`Adafruit_SSD1306` クラスを使用することでOLED ディスプレイを操作することができます. 実際にはマイコンであるRP2040のI2C機能を使用するため, I2C機能を利用できるピンを選択する必要があります. ここでは `GP0`(TX) と `GP1`(RX) を使用しています.

ディスプレイの描画はすべてビットマップのため, 文字列の描画もビットマップによって行われています. しかしディスプレイドライバやライブラリを使用することで, それを意識することなくシリアル通信と同じような操作をするだけで文字列を表示することができます.

#### Advanced

- フォントを変更するには?

#### Refs.

[1]<a name="arduino_wire"/> [Arduino - Wire](https://www.arduino.cc/en/reference/wire)

[2]<a name="adafruit_ssd1306"/> [SSD1306 datasheet](https://cdn-shop.adafruit.com/datasheets/SSD1306.pdf)
[Arduino Library & Examples | Monochrome OLED Breakouts | Adafruit Learning System](https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples)

[3]<a name="yamorijp_font"> [arduino-examples/main.cpp at master · yamorijp/arduino-examples](https://github.com/yamorijp/arduino-examples/blob/master/ssd1306/src/main.cpp)

