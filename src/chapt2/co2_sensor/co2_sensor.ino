/**
 * @file co2_sensor.ino
 * @brief CO2 monitor sends serial port
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#include "mhz19b_uart.h"

#define INTERVAL 1000

#define LED_R 18
#define LED_G 19
#define LED_B 20

uint16_t threshold_y = 1500;
uint16_t threshold_r = 2000;

void setup() {
// Debug USB serial
    Serial.begin(115200);

// CO2 sensor serial port
    init_co2();

// LED
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);

    led_off(LED_R);
    led_off(LED_G);
    led_off(LED_B);

    delay(10000);
}

void loop() {

    uint16_t co2_data = get_co2();

    Serial.print(co2_data);
    Serial.print("\n");

    if (co2_data >= threshold_r) {
        led_off(LED_G);
        
        led_on(LED_R);
    } else if (co2_data >= threshold_y) {
        led_on(LED_R);
        led_on(LED_G);
    } else {
        led_off(LED_R);
        
        led_on(LED_G);
    }

    // Interval
    delay(INTERVAL);

}

void led_on(int pin) {
    digitalWrite(pin, LOW);
}

void led_off(int pin) {
    digitalWrite(pin, HIGH);
}
