/**
 * @file hello_world.ino
 * @brief Hello World
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

void setup() {
  Serial.begin(115200);
  delay(5000);
}

void loop() {
  Serial.printf("Hello, World!\n");
  delay(1000);
}