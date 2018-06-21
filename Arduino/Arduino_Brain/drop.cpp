#include "Arduino.h"
#include "globals.h"

void vert(String str, int gate) {
  if (str == "open") {
    digitalWrite(vertDoor[gate], LOW);
    Serial.println("openVert");
    Serial.println(gate);
  } else {
    digitalWrite(vertDoor[gate], HIGH);
    Serial.println("closeVert");
    Serial.println(gate);
  }
}

void hor(String str, int gate) {
  if (str == "open") {
    digitalWrite(horDoor[gate], LOW);
    Serial.println("openHor");
    Serial.println(gate);
  } else {
    digitalWrite(horDoor[gate], HIGH);
    Serial.println("closeHor");
    Serial.println(gate);
  }
}

void spot (String str, int col) {
  if (str == "on") {
    Serial.println("onSpot");
    Serial.println(col);
  } else {
    Serial.println("offSpot");
    Serial.println(col);
  }
}

void drop(int col) {
  for (int i = 6; i > col; --i) {
    hor("open", i);
    spot("off", i);
    spot("on", i - 1);
    delay(1500);
    hor("close", i);
    delay(750);
  }
  vert("open", col);
  while (digitalRead(sensor[col]) == HIGH);
  printBoard();
  spot("off", col);
  delay(750);
  spot("on", 6);
}
