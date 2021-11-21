## Chapt. 2 通信

[chapt.1](https://github.com/toms74209200/CO2MO/blob/master/learning/chapt1/hello_world) ではUSBシリアル通信を行いました. ここではGPIOピンと共有している周辺機能を利用して外部装置との通信を行います. 外部装置との通信により外部装置を操作することができます.

### 2-2 センサー入力

ここで使用するCO2センサ(MH-Z19b[[1](#mhz19b_datasheet)]) はデジタルセンサの一種で, 内部にコントローラを持ちます. コントローラがセンサから物理的に意味のある値に変換し, 通信規格にそって通信することでデータを取得することができます. ここではシリアル通信を用いてMH-Z19Bと通信を行います. [chapt.1](https://github.com/toms74209200/CO2MO/blob/master/learning/chapt1/hello_world) でもシリアル通信を使用しましたが, 今回はUSBバス上ではなくGPIOを用いて通信します. UARTによるシリアル通信は HardwareSerial[[2](#arduino_serial)] によって利用することができます. UARTが利用できるピンは予め決まっており, ここでは `GP0`(TX) と `GP1`(RX) を使用しています.

デバイスとの通信を行うには通信規格にのっとって通信するだけでなく, デバイスの動作仕様に従ってデータをやり取りする必要があります. MH-Z19BでもCO2のデータを得るには特定のコマンドを送信し, レスポンスとしてデータを受け取ります. デバイスから受け取ったデータはUARTがレジスタに保存するため, 任意のタイミングでデータを取得することができます.

#### Advanced

- 値の平均値をとるには?

#### Refs.

[1]<a name="mhz19b_datasheet"> [Intelligent Infrared CO2 Module (Model: MH-Z19B) - Winsen](https://www.winsen-sensor.com/d/files/infrared-gas-sensor/mh-z19b-co2-ver1_0.pdf)

[2]<a name="arduino_serial"> [Serial - Arduino Reference](https://www.arduino.cc/reference/en/language/functions/communication/serial/)