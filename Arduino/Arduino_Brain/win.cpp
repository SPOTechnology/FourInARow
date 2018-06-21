#include "Arduino.h"
#include "globals.h"

void win() {
  printBoard();
  Serial.println("YouWin");
  while(!reset(false)){
    checkCommand();
  }
}
