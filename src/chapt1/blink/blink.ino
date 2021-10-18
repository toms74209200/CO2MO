/**
 * @file blink.ino
 * @brief LED blink
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#define LED_R 18
#define LED_G 19
#define LED_B 20

#define INTERVAL 200

void setup() {
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  led_off(LED_R);
  led_off(LED_G);
  led_off(LED_B);
}

void loop() {
  led_on(LED_R);
  delay(INTERVAL);

  led_off(LED_B);
  delay(INTERVAL);

  led_on(LED_G);
  delay(INTERVAL);

  led_off(LED_R);
  delay(INTERVAL);

  led_on(LED_B);
  delay(INTERVAL);

  led_off(LED_G);
  delay(INTERVAL);
}

void led_on(int pin) {
  digitalWrite(pin, LOW);
}

void led_off(int pin) {
  digitalWrite(pin, HIGH);
}
