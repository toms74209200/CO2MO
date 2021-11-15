/**
 * @file LedController.h
 * @brief LED controller
 * 
 * Copyright (c) 2021 toms74209200
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */

#pragma once

#include <Arduino.h>

namespace led {

class Red {
public:
  Red();
  void turn_on();
  void turn_off();
private:
  const byte LED_PIN = 18;
};

class Green {
public:
  Green();
  void turn_on();
  void turn_off();
private:
  const byte LED_PIN = 19;
};

class Blue {
public:
  Blue();
  void turn_on();
  void turn_off();
private:
  const byte LED_PIN = 20;
};

}
