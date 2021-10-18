/**
 * @file mhz19b_uart.h
 * @brief MH-Z19B CO2 sensor read
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#ifndef MHZ19B_UART_H
#define MHZ19B_UART_H

#include <Arduino.h>

void init_co2();
bool read_mhz19b(unsigned char*);
int get_co2();
int get_temperature();

#endif
