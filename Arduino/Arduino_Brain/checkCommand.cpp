#include "Arduino.h"
#include "globals.h"

String checkCommand() {
  if (Serial.available()) {
    String input = Serial.readString();
    if (input == "reset" || input == "r" || input == "R") {
      reset();
      return "true";
    } else if (input == "print" || input == "p") {
      printBoard();
    } else if (input == "minimax" || input == "Minimax" || input == "m" || input == "M") {
      Serial.println("Minimax selected\n");
      Serial.println("M");
      program = 2;
    } else if (input == "alpha-beta" || input == "Alpha-Beta" || input == "Alpha-beta" || input == "alpha-Beta" || input == "A" || input == "a") {
      Serial.println("Alpha-Beta selected\n");
      Serial.println("A");
      program = 3;
    } else if (input == "benimax" || input == "Benimax" || input == "b" || input == "B") {
      Serial.println("Benimax selected\n");
      Serial.println("B");
      program = 1;
    } else if (input == "neural" || input == "nn" || input == "NN" || input == "n" || input == "N") {
      Serial.println("NN selected\n");
      Serial.println("N");
      program = 0;
    } else {
      return input;
    }
  }
  return "false";
}

