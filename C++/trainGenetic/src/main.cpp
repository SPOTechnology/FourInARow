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

//functions
long double random(double _min, double _max);
void refPointers(int population, int genome);
void resetBoard();
void writeFile();
void playGame(int opDepth, int population, int genome, int startingMove);
void evolve();
void readFile(char fileName[]);

//globals
int brd[7][6];
int generation = 0;
Fitness fitness[pop][gen];

Weight weight[pop][gen][weights];
Weight *pWeightIH[pop][gen][inputs][hiddens];
Weight *pWeightHH[pop][gen][hiddens][hiddens];
Weight *pWeightHO[pop][gen][hiddens][7];

int main(int argc, char *argv[]) {
	srand(time(NULL));
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 7; ++j) {
			brd[j][i] = 0;
		}
	}
	int startingMoves[7] = { 0, 6, 1, 5, 2, 4, 3 };
	for (int w = 0; w < weights; ++w) {
		for (int population = 0; population < pop; ++population) {
			for (int genome = 0; genome < gen; ++genome) {
				weight[population][genome][w].setVal(random(-1, 1));
			}
		}
	}
	if (argc > 1) {
		readFile(argv[1]);
	}
	for (int population = 0; population < pop; ++population) {
		for (int genome = 0; genome < gen; ++genome) {
			refPointers(population, genome);
		}
	}
	while (1) {
		for (int population = 0; population < pop; ++population) {
			for (int genome = 0; genome < gen; ++genome) {
				fitness[population][genome].fit = 0;
				fitness[population][genome].index = genome;
				for (int start = 0; start < 7; ++start) {
					for (int opDepth = 2; opDepth <= 6; ++opDepth) {
						brd[startingMoves[start]][0] = 1;
						playGame(opDepth, population, genome, startingMoves[start]);
						resetBoard();
					}
				}
			}
		}
		evolve();
		writeFile();
		++generation;
	}
	return 0;
}
