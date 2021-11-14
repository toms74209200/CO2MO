/**
 * @file LedController.cpp
 * @brief LED controller
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#include "LedController.h"

led::Red::Red() {
  pinMode(LED_PIN, OUTPUT);
}
void led::Red::turn_on() {
  digitalWrite(LED_PIN, LOW);
}
void led::Red::turn_off() {
  digitalWrite(LED_PIN, HIGH);
}

led::Green::Green() {
  pinMode(LED_PIN, OUTPUT);
}
void led::Green::turn_on() {
  digitalWrite(LED_PIN, LOW);
}
void led::Green::turn_off() {
  digitalWrite(LED_PIN, HIGH);
}

led::Blue::Blue() {
  pinMode(LED_PIN, OUTPUT);
}
void led::Blue::turn_on() {
  digitalWrite(LED_PIN, LOW);
}
void led::Blue::turn_off() {
  digitalWrite(LED_PIN, HIGH);
}