#include "globals.h"

long _0 = 0L;
long _1 = 0L;
long _2 = 0L;
long _3 = 0L;
long _4 = 0L;
long _5 = 0L;
long _6 = 0L;

int program = 1;

const int sensor[7] = {22, 23, 24, 25, 26, 27, 28};
const int horDoor[7] = {29, 30, 31, 32, 33, 34, 35};
const int vertDoor[7] = {36, 37, 38, 39, 40, 41, 42};
const int resetPin = 52;
const int overridePin = 8;
const int loadedPin = 7;

void setup() {
  for (int i = 0; i < 7; ++i) {
    pinMode(sensor[i], INPUT);
    pinMode(resetPin, INPUT);
    pinMode(loadedPin, INPUT);
    pinMode(overridePin, INPUT);
    pinMode(horDoor[i], OUTPUT);
    pinMode(vertDoor[i], OUTPUT);
    digitalWrite(horDoor[i], HIGH);
    digitalWrite(vertDoor[i], HIGH);
  }
  // Open serial communications and wait for port to open
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  printProgram();
  if (checkCommand() == "true") {
    return;
  }
  Serial.println("P");
  humanMove();
  if (checkCommand() == "true") {
    return;
  }
  Serial.println("T");
  AIMove();
}

void printProgram() {
  switch (program) {
    case 0:
      Serial.println("N");
      break;
    case 1:
      Serial.println("M");
      break;
    case 2:
      Serial.println("B");
      break;
    case 3:
      Serial.println("A");
      break;
  }
}

