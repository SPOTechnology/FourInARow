#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <array>
#include <cmath>
#include <time.h>

#include "neuron.h"
#include "globals.h"
#include "weight.h"

using namespace std;

//functions
char playGame(int program, bool search);
void readWeights();
void refPointers();
void printBoard(int mov);
int compareM(const void * a, const void *b);

//globals
int brd[7][6];

bool automatic = false;
Moves moves[7];
int depth = 0;

Weight weight[weights];
Weight *pWeightIH[inputs][hiddens];
Weight *pWeightHH[hiddens][hiddens];
Weight *pWeightHO[hiddens][7];

int main(int argc, char *argv[]) {
	clock_t startTime = clock();
	int program = argv[8][0] - 48;
	int search = argv[9][0] - 48;

	if (program > 3) {
		cout << "Invalid Program" << endl;
		return 0;
	}

	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 7; ++j) {
			brd[j][i] = int(argv[j + 1][5 - i] - 48);
		}
	}

	refPointers();
	readWeights();
	char m = playGame(program, search == 1 ? true : false);
	cout << "AI moves to: " << m << endl;
	printBoard(m - 48);

	if (!automatic) {
		switch (program) {
			case 0:
				cout << endl << "<br/>";
				cout << "Neural Network" << endl << "<br/>";
				for (int x = 0; x < 7; ++x) {
					cout << " " << x << ": " << output[x].output() << endl << "<br/>";
				}
				break;
			case 1:
				cout << endl << "<br/>";
				cout << "Minimax" << endl << "<br/>";
				for (int x = 0; x < 7; ++x) {
					cout << " " << x << ": " << value[x] << endl << "<br/>";
				}
				break;
			case 2:
				qsort(moves, 7, sizeof(Moves), compareM);
				cout << endl << "<br/>";
				cout << "Benimax" << endl << "<br/>";
				for (int x = 0; x < 7; ++x) {
					cout << " " << moves[x].move << ": " << moves[x].val << endl << "<br/>";
				}
				cout << endl << "<br/>" << "Depth: " << depth << endl << "<br/>" << endl;
				break;
			case 3:
				qsort(moves, 7, sizeof(Moves), compareM);
				cout << endl << "<br/>";
				cout << "Alpha-Beta" << endl << "<br/>";
				for (int x = 0; x < 7; ++x) {
					cout << " " << moves[x].move << ": " << moves[x].val << endl << "<br/>";
				}
				cout << endl << "<br/>" << "Depth: " << depth << endl << "<br/>" << endl;
				break;
		}
	} else {
		cout << endl << "<br/>" << endl << "<br/>" << "automatic" << endl << "<br/>";
	}
	double runTime = double(clock() - startTime) / CLOCKS_PER_SEC;
	cout << endl << "<br/>" << "Total runtime: " << runTime << " seconds" << endl << "<br/>" << endl;
	return 0;
}

