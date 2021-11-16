/**
 * @file co2_chart.ino
 * @brief CO2 chart monitor
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#include <vector>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "src/LedController/LedController.h"
#include "src/TimeUtil/TimeUtil.h"
#include "src/MHZ19B_Controller/MHZ19B_Controller.h"

// Pins
constexpr auto RX_PIN = 1;
constexpr auto TX_PIN = 0;
constexpr auto OLED_SCL_PIN = 5;
constexpr auto OLED_SDA_PIN = 4;

// Display
constexpr auto SCREEN_WIDTH = 128; // OLED display width, in pixels
constexpr auto SCREEN_HEIGHT = 64; // OLED display height, in pixels
constexpr auto OLED_RESET = -1; // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
constexpr uint16_t CHART_DATA_OFFSET = 14;
constexpr uint16_t CHART_DATA_HIGHT = SCREEN_HEIGHT - 14;
constexpr uint16_t CHART_DATA_MIN = 350;
constexpr uint16_t CHART_DATA_MAX = 3000;

led::Red led_r = led::Red();
led::Green led_g = led::Green();
led::Blue led_b = led::Blue();

co2::MHZ19B_Controller co2_controller = co2::MHZ19B_Controller(RX_PIN, TX_PIN);
std::vector<uint16_t> co2_data_vector(SCREEN_WIDTH);

constexpr unsigned long INTERVAL = time_util::Minutes::toMillis(5);

void setup() {
  co2_controller.init();

  led_r.turn_off();
  led_g.turn_off();
  led_b.turn_off();

  Serial.begin(115200);

  Wire.setSDA(OLED_SDA_PIN);
  Wire.setSCL(OLED_SCL_PIN);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    while(1);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.display();

  delay(time_util::Seconds::toMillis(10));
}

void loop() {
  uint16_t co2_data = co2_controller.get_co2();

  Serial.print(co2_data);
  Serial.print("\n");

  char display_data[10];
  sprintf(display_data, "%d ppm", co2_data);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(display_data);

  if (co2_data_vector.size() == SCREEN_WIDTH) {
    co2_data_vector.erase(co2_data_vector.begin());
    co2_data_vector.push_back(co2_data);
    for (uint8_t i = 1; i < SCREEN_WIDTH; i++) {
      plot_data(i - 1, i, co2_data_vector[i-1], co2_data_vector[i]);
    }
  } else {
    co2_data_vector.push_back(co2_data);
    uint8_t data_size = co2_data_vector.size();
    for (uint8_t i = 1; i < data_size; i++) {
      plot_data(i - 1, i, co2_data_vector[i-1], co2_data_vector[i]);
    }
  }
  display.display();

  delay(INTERVAL);
}

/**
 * @brief plot a pair data
 * @param[in] display_x0 1st position of the pair
 * @param[in] display_x1 2nd position of the pair
 * @param[in] data0 1st data of the pair
 * @param[in] data1 1nd data of the pair
 */
void plot_data(uint16_t display_x0, uint16_t display_x1, uint16_t data0, uint16_t data1) {
  uint16_t display_y0 = SCREEN_HEIGHT + (((data0 - CHART_DATA_MIN) * CHART_DATA_OFFSET) / CHART_DATA_MAX) - (((data0 - CHART_DATA_MIN) * CHART_DATA_HIGHT) / CHART_DATA_MAX);
  uint16_t display_y1 = SCREEN_HEIGHT + (((data1 - CHART_DATA_MIN) * CHART_DATA_OFFSET) / CHART_DATA_MAX) - (((data1 - CHART_DATA_MIN) * CHART_DATA_HIGHT) / CHART_DATA_MAX);
  display.drawLine(display_x0, display_y0, display_x1, display_y1, WHITE);
}