#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <array>
#include <cmath>
//#include <Windows.h>
#include <time.h>

#include "neuron.h"
#include "globals.h"
#include "weight.h"

using namespace std;

//functions
long double random(double _min, double _max);
void refPointers();
void resetBoard();
void writeFile();
void playGame(int opDepth);

//globals
int brd[7][6];
int fitness = 0;
int generation = 0;
Weight weight[weights];
Weight *pWeightIH[inputs][hiddens];
Weight *pWeightHH[hiddens][hiddens];
Weight *pWeightHO[hiddens][7];

int main() {
	srand(time(NULL));
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 7; ++j) {
			brd[j][i] = 0;
		}
	}
	int startingMoves[24] = { 0, 6, 1, 1, 5, 5, 2, 2, 2, 4, 4, 4, 3, 3, 3, 3, 3,
			3, 3, 3, 3, 3 };
	for (int w = 0; w < weights; ++w) {
		weight[w].setVal(random(-1, 1));
	}
	refPointers();
	while (1) {
		fitness = 0;
		for (int start = 0; start < 24; ++start) {
			for (int opDepth = 2; opDepth <= 6; ++opDepth) {
				brd[startingMoves[start]][0] = 1;
				playGame(opDepth);
				resetBoard();
			}
		}
		writeFile();
		for (int w = 0; w < weights; ++w) {
			weight[w].change();
		}
		++generation;
	}
	return 0;
}
