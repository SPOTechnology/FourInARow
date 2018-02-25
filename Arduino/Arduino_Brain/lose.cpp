#include "Arduino.h"
#include "globals.h"

void lose() {
  Serial.println("YouLose");
  printBoard();
  reset();
}
