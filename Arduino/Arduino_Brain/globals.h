#include <Ethernet.h>

#ifndef GLOBALS_H
#define GLOBALS_H

extern const int loadedPin;
extern const int resetPin;
extern const int sensor[7];
extern const int horDoor[7];
extern const int vertDoor[7];
extern int program;
extern String address;

extern long _0;
extern long _1;
extern long _2;
extern long _3;
extern long _4;
extern long _5;
extern long _6;

extern EthernetClient client;

char makeRequest(bool search);
void win();
void lose();
void humanMove();
long power(long base, long exponent);
void printBoard();
void drop(int col);
void AIMove();
bool reset(bool order);
String checkCommand();
void tie();
void getMove(String server, bool search);
void spot (String str, int col);

#endif
