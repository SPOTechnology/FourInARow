#include "Arduino.h"
#include "globals.h"

void win() {
  Serial.println("YouWin");
  printBoard();
  reset();
}
