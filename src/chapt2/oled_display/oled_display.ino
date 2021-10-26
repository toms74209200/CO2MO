/**
 * @file oled_display.ino
 * @brief Hello, World! on OLED display
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  Wire.setSDA(4);
  Wire.setSCL(5);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while(1);
  }

  display.clearDisplay();

  display.setCursor(10, SCREEN_HEIGHT/2);
  display.setTextColor(WHITE);
  display.setFont(&FreeSans9pt7b);
  display.setTextWrap(false);
  display.println("Hello, World!");
  display.display();
}

void loop() {}
