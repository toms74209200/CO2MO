## Chapt. 1 Hello World

まずはマイコンの基本的な周辺機能を用いてファームウェアによるデバイスの操作方法を学びます.

### 1-2 シリアル通信を使った「Hello World」

このデバイスのマイコン(RP2040)はGPIO以外にも多数の周辺機能を持ちます. 周辺機能により通信規格がサポートされているため, ファームウェア上ではほとんど通信規格を意識することなく実装することができます.

![rp2040_overview](https://github.com/toms74209200/CO2MO/blob/master/docs/fig/rp2040_overview.jpg)

[RP2040 Datasheet](https://datasheets.raspberrypi.com/rp2040/rp2040-datasheet.pdf)

ここではUSBバスプロトコル上でシリアル通信(UART)を行います. 周辺機能とライブラリによりUSBバスプロトコルを意識することなく, PCとのシリアル通信を行うことができます. ソースコードを書き込んだあと, メニューの「ツール」>「シリアルモニタ」を開くと, デバイスから文字が送られてきていることが確認できます.

このときうまくいかない場合は以下の点を確認しましょう.

- 「ツール」>「シリアルポート」は該当のデバイスになっているか.
- 「シリアルモニタ」のボーレートは適切な数値になっているか.

#### Advanced

- PCから送信したデータを扱うには?