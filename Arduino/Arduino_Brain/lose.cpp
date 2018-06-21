#include "Arduino.h"
#include "globals.h"

void lose() {
  printBoard();
  Serial.println("YouLose");
  while(!reset(false)){
    checkCommand();
  }
}
