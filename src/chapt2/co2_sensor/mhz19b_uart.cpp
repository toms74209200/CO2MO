/**
 * @file mhz19b_uart.cpp
 * @brief MH-Z19B CO2 sensor read
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#include "mhz19b_uart.h"

/**
 * @brief Initializes serial port
 */
void init_co2() {
    Serial1.setRX(1);
    Serial1.setTX(0);
    Serial1.begin(9600);
}

/**
 * @brief Reads MH-Z19B
 * @param[out] pointer of response data
 * @return bool result of successful reading
 */
bool read_mhz19b(unsigned char* response) {
    // MH-Z19 uart communication
    byte cmd[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
    Serial1.write(cmd, 9); //request PPM CO2
    Serial1.readBytes(response, 9);
    if (response[0] != 0xFF){
        return false;
    }
    if (response[1] != 0x86){
        return false;
    }

    return true;

}
/**
 * @brief Gets CO2 data
 * @return int CO2 data
 */
int get_co2() {
    unsigned char response[9];

    if (!read_mhz19b(response)) {
      return 0;
    }

// CO2 calculation
    unsigned int responseHigh = (unsigned int) response[2];
    unsigned int responseLow = (unsigned int) response[3];
    int ppm = (256 * responseHigh) + responseLow;
    return ppm;
}

/**
 * @brief Get temperature data
 * @return int temperature data
 */
int get_temperature() {
    unsigned char response[9];

    if (!read_mhz19b(response)) {
      return 0;
    }

    int temperature = response[4] - 40;

    return temperature;
}
