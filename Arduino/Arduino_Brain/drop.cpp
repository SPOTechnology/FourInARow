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
  for (int i = 6; i > col + 1; --i) {
    hor("open", i);
    spot("off", i);
    spot("on", i - 1);
    delay(1300);
    hor("close", i);
  }
  vert("open", col);
  hor("open", col + 1);
  spot("off", col + 1);
  spot("on", col);
  delay(1300);
  hor("close", col + 1);
  vert("close", col);
  spot("off", col);
  delay(1500);
  spot("on", 6);
  printBoard();
}
