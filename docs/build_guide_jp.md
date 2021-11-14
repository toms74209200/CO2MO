# PR2040 CO2 モニタ ビルド ガイド

## 組み立て

## 環境構築

このプロジェクトでは C/C++ とArduino IDE を用いて開発を行います. 本項ではこれらを用いてデバイスの開発環境の構築を行います.

### C/C++ 開発環境の構築

#### Arduino IDE を使う

**Arduino IDE のインストール**

Arduino IDE をインストール.

[Software | Arduino](https://www.arduino.cc/en/software)

macOS では Homebrew を使ってインストールできます.

```bash
$ brew install --cask arduino
```

**ライブラリの追加**

メニューで「ファイル」>「環境設定」>「追加のボードマネージャのURL」に以下のURLを追加します.

```
https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json
```

**書き込み方法**

「BOOT」スイッチを押しながらUSBに接続します. 「デバイスマネージャ(Windows)」「システム情報(macOS)」で「RP2 Boot」が接続していることを確認してください. 

メニューで「ファイル」>「スケッチ例」>「rp2040」>「Temperature」を選択.

メニューの「ツール」>「シリアルポート」には表示されません. そのまま書き込み, 書き込みに成功するとUSBの接続が切れシリアルポートとして認識されます.

**参考**

- [Arduino IDEでRaspberry Pi Picoの開発環境を構築 | TomoSoft](https://tomosoft.jp/design/?p=43370)

