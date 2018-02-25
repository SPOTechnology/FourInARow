#include "Arduino.h"
#include "globals.h"

void humanMove() {
  while (1) {
    String input = checkCommand();
    if (digitalRead(sensor[0]) == LOW || input == "0") {
      _0 += power(10, ((_0 == 0 ? -1 : int(log10(_0))) + 1));
      break;
    } else if (digitalRead(sensor[1]) == LOW || input == "1") {
      _1 += power(10, ((_1 == 0 ? -1 : int(log10(_1))) + 1));
      break;
    } else if (digitalRead(sensor[2]) == LOW || input == "2") {
      _2 += power(10, ((_2 == 0 ? -1 : int(log10(_2))) + 1));
      break;
    } else if (digitalRead(sensor[3]) == LOW || input == "3") {
      _3 += power(10, ((_3 == 0 ? -1 : int(log10(_3))) + 1));
      break;
    } else if (digitalRead(sensor[4]) == LOW || input == "4") {
      _4 += power(10, ((_4 == 0 ? -1 : int(log10(_4))) + 1));
      break;
    } else if (digitalRead(sensor[5]) == LOW || input == "5") {
      _5 += power(10, ((_5 == 0 ? -1 : int(log10(_5))) + 1));
      break;
    } else if (digitalRead(sensor[6]) == LOW || input == "6") {
      _6 += power(10, ((_6 == 0 ? -1 : int(log10(_6))) + 1));
      break;
    }
  }
  printBoard();
  delay(100);
}
