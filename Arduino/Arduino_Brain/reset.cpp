#include "Arduino.h"
#include "globals.h"

bool reset(bool order) {
  if (digitalRead(resetPin) == HIGH) {
    order = true;
  }
  if (order == true) {
    _0 = 0;
    _1 = 0;
    _2 = 0;
    _3 = 0;
    _4 = 0;
    _5 = 0;
    _6 = 0;
    Serial.println("reset");
    return true;
  }
  return false;
}

