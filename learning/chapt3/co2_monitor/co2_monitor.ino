/**
 * @file co2_monitor.ino
 * @brief CO2 monitor
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>

#include "mhz19b_uart.h"

#define INTERVAL 1000

#define RX_PIN 1
#define TX_PIN 0

#define OLED_SCL_PIN 5
#define OLED_SDA_PIN 4
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {

// Debug USB serial
  Serial.begin(115200);

// CO2 sensor serial port
  init_co2(RX_PIN, TX_PIN);

  Wire.setSDA(OLED_SDA_PIN);
  Wire.setSCL(OLED_SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while(1);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.display();
}

void loop() {
  uint16_t co2_data = get_co2();

  Serial.print(co2_data);
  Serial.print("\n");

  char display_data[10];
  sprintf(display_data, "%d ppm", co2_data);

  display.clearDisplay();
  display.setCursor(10, SCREEN_HEIGHT/2 - 10);
  display.println(display_data);
  display.display();

  // Interval
  delay(INTERVAL);
}
