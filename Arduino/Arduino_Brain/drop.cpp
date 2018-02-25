#include "Arduino.h"
#include "globals.h"

void vert(String str, int gate) {
  if (str == "open") {
    digitalWrite(vertDoor[gate], HIGH);
    Serial.println("openVert");
    Serial.println(gate);
  } else {
    digitalWrite(vertDoor[gate], LOW);
    Serial.println("closeVert");
    Serial.println(gate);
  }
}

void hor(String str, int gate) {
  if (str == "open") {
    digitalWrite(horDoor[gate], HIGH);
    Serial.println("openHor");
    Serial.println(gate);
  } else {
    digitalWrite(horDoor[gate], LOW);
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
  vert("open", col);
  spot("off", col);
  //while (digitalRead(sensor[col]) == LOW);
  printBoard();
  //delay(1000);
  vert("close", col);
  //delay(500);

  for (int i = col; i < 7; ++i) {
    hor("open", i);
    spot("on", i);
    spot("off", i + 1);
    //delay(1000);
    hor("close", i);
    //delay(500);
  }
}
