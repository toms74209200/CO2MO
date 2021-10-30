/**
 * @file mhz19b_uart.cpp
 * @brief MH-Z19B CO2 sensor read
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#include "mhz19b_uart.h"

const byte START_BYTE = 0xFF;
const byte REQUEST_SENSOR = 0x01;
const byte READ_CO2 = 0x86;
const byte CHECK_SUM = 0x79;

/**
 * @brief Initializes serial port
 */
void init_co2(byte rx, byte tx) {
  Serial1.setRX(rx);
  Serial1.setTX(tx);
  Serial1.begin(9600);
}

/**
 * @brief Reads MH-Z19B
 * @param[out] pointer of response data
 * @return bool result of successful reading
 */
bool read_mhz19b(byte* response) {
  byte cmd[9] = {START_BYTE,REQUEST_SENSOR,READ_CO2,0x00,0x00,0x00,0x00,0x00,CHECK_SUM};
  Serial1.write(cmd, 9);
  byte buf[10];
  Serial1.readBytes(buf, 9);
  if (buf[0] == 0xFF && buf[1] == 0x86) {
    memcpy(response, buf, sizeof(response));
    return true;
  }
  if (buf[1] == 0xFF && buf[2] == 0x86) {
    byte len = sizeof(response);
    for (byte i = 0; i < len; i++) {
      response[i] = buf[i+1];
    }
    return true;
  }

  return false;

}
/**
 * @brief Gets CO2 data
 * @return int CO2 data
 */
uint16_t get_co2() {
  byte response[9];

  if (!read_mhz19b(response)) {
    return 0;
  }

  byte responseHigh = (byte) response[2];
  byte responseLow = (byte) response[3];
  uint16_t co2_data = (responseHigh << 8) + responseLow;
  return co2_data;
}

/**
 * @brief Get temperature data
 * @return int temperature data
 */
int16_t get_temperature() {
  byte response[9];

  if (!read_mhz19b(response)) {
    return 0;
  }

  int16_t temperature = response[4] - 40;

  return temperature;
}
