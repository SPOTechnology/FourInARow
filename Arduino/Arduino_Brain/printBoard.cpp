#include "Arduino.h"
#include "globals.h"

void printBoard() {
  char buff[300];
  sprintf(buff, "board\n%06ld\n%06ld\n%06ld\n%06ld\n%06ld\n%06ld\n%06ld\n", _6, _5, _4, _3, _2, _1, _0);
  Serial.println(buff);
}
