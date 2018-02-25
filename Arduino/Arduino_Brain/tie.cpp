#include "Arduino.h"
#include "globals.h"

void tie() {
  Serial.println("Tie");
  printBoard();
  reset();
}
