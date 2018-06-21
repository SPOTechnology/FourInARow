#include "Arduino.h"
#include "globals.h"

void tie() {
  printBoard();
  Serial.println("YouTie");
  while(!reset(false)){
    checkCommand();
  }
}
