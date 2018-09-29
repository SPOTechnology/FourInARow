#include "Arduino.h"
#include "globals.h"

long prevTime;

void humanMove() {
  while (1) {
    if (millis() - prevTime > 200) {
      prevTime = millis();
      if (digitalRead(loadedPin) == HIGH) {
        spot("on", 6);
      }
      if (digitalRead(overridePin) == HIGH) {
        Serial.println("O");
        while (digitalRead(overridePin) == HIGH);
      } else {
        Serial.println("U");
      }
    }
    String input = checkCommand();
    if ((digitalRead(sensor[0]) == HIGH || input == "0") && _0 < 100000) {
      _0 += power(10, ((_0 == 0 ? -1 : int(log10(_0))) + 1));
      break;
    } else if ((digitalRead(sensor[1]) == HIGH || input == "1") && _1 < 100000) {
      _1 += power(10, ((_1 == 0 ? -1 : int(log10(_1))) + 1));
      break;
    } else if ((digitalRead(sensor[2]) == HIGH || input == "2") && _2 < 100000) {
      _2 += power(10, ((_2 == 0 ? -1 : int(log10(_2))) + 1));
      break;
    } else if ((digitalRead(sensor[3]) == HIGH || input == "3") && _3 < 100000) {
      _3 += power(10, ((_3 == 0 ? -1 : int(log10(_3))) + 1));
      break;
    } else if ((digitalRead(sensor[4]) == HIGH || input == "4") && _4 < 100000) {
      _4 += power(10, ((_4 == 0 ? -1 : int(log10(_4))) + 1));
      break;
    } else if ((digitalRead(sensor[5]) == HIGH || input == "5") && _5 < 100000) {
      _5 += power(10, ((_5 == 0 ? -1 : int(log10(_5))) + 1));
      break;
    } else if ((digitalRead(sensor[6]) == HIGH || input == "6") && _6 < 100000) {
      _6 += power(10, ((_6 == 0 ? -1 : int(log10(_6))) + 1));
      break;
    }
  }
  printBoard();
  delay(100);
}
