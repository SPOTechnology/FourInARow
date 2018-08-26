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
		std::cout << "Invalid Program" << std::endl;
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
	std::cout << "AI moves to: " << m << std::endl;
	printBoard(m - 48);

	if (!automatic) {
		switch (program) {
		case 0:
			std::cout << std::endl << "<br/>";
			std::cout << "Neural Network" << std::endl << "<br/>";
			for (int x = 0; x < 7; ++x) {
				std::cout << " " << x << ": " << output[x].output() << std::endl
						<< "<br/>";
			}
			break;
		case 1:
			std::cout << std::endl << "<br/>";
			std::cout << "Minimax" << std::endl << "<br/>";
			for (int x = 0; x < 7; ++x) {
				std::cout << " " << x << ": " << value[x] << std::endl
						<< "<br/>";
			}
			std::cout << std::endl << "<br/>" << "Depth: " << depth << std::endl
					<< "<br/>" << std::endl;
			break;
		case 2:
			qsort(moves, 7, sizeof(Moves), compareM);
			std::cout << std::endl << "<br/>";
			std::cout << "Benimax" << std::endl << "<br/>";
			for (int x = 0; x < 7; ++x) {
				std::cout << " " << moves[x].move << ": " << moves[x].val
						<< std::endl << "<br/>";
			}
			std::cout << std::endl << "<br/>" << "Depth: " << depth << std::endl
					<< "<br/>" << std::endl;
			break;
		case 3:
			qsort(moves, 7, sizeof(Moves), compareM);
			std::cout << std::endl << "<br/>";
			std::cout << "Alpha-Beta" << std::endl << "<br/>";
			for (int x = 0; x < 7; ++x) {
				std::cout << " " << moves[x].move << ": " << moves[x].val
						<< std::endl << "<br/>";
			}
			std::cout << std::endl << "<br/>" << "Depth: " << depth << std::endl
					<< "<br/>" << std::endl;
			break;
		}
	} else {
		std::cout << std::endl << "<br/>" << std::endl << "<br/>" << "automatic"
				<< std::endl << "<br/>";
	}
	double runTime = double(clock() - startTime) / CLOCKS_PER_SEC;
	std::cout << std::endl << "<br/>" << "Total runtime: " << runTime
			<< " seconds" << std::endl << "<br/>" << std::endl;
	return 0;
}

