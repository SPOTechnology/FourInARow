#include "Arduino.h"
#include "globals.h"

void AIMove() {
  char moveChar = makeRequest(true);
  while (moveChar == 'e') {
    moveChar = makeRequest(true);
  }
  if (moveChar == 'h') {
    win();
    return;
  } else if (moveChar == 't') {
    tie();
    return;
  } else if (moveChar == '0') {
    _0 +=  2 * power(10, ((_0 == 0 ? -1 : int(log10(_0))) + 1));
  } else if (moveChar == '1') {
    _1 +=  2 * power(10, ((_1 == 0 ? -1 : int(log10(_1))) + 1));
  } else if (moveChar == '2') {
    _2 +=  2 * power(10, ((_2 == 0 ? -1 : int(log10(_2))) + 1));
  } else if (moveChar == '3') {
    _3 +=  2 * power(10, ((_3 == 0 ? -1 : int(log10(_3))) + 1));
  } else if (moveChar == '4') {
    _4 +=  2 * power(10, ((_4 == 0 ? -1 : int(log10(_4))) + 1));
  } else if (moveChar == '5') {
    _5 +=  2 * power(10, ((_5 == 0 ? -1 : int(log10(_5))) + 1));
  } else if (moveChar == '6') {
    _6 +=  2 * power(10, ((_6 == 0 ? -1 : int(log10(_6))) + 1));
  }
  Serial.print("AI moves to: ");
  Serial.println(moveChar);
  while (digitalRead(loadedPin) == HIGH);
  drop(moveChar - 48);
  char checkLose = makeRequest(false);
  while (checkLose == 'e') {
    checkLose = makeRequest(false);
  }
  if (checkLose == 'c') {
    lose();
    return;
  } else if (checkLose == 't') {
    tie();
    return;
  } else {
    printBoard();
  }
}

