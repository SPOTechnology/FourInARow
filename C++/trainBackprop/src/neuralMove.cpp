#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <array>
#include <cmath>

#include "neuron.h"
#include "globals.h"

using namespace std;

int possibleMove(int board[6]);
int benimaxMove(int opDepth, int board[7][6]);
//void backprop();

InputNeuron input[inputs];
HiddenNeuron hidden[hiddens];
HiddenNeuron hidden2[hiddens];
OutputNeuron output[7];

int neuralMove() {
	for (int i = 0; i < inputs; ++i) {
		input[i].reset();
	}

	for (int i = 0; i < hiddens; ++i) {
		hidden[i].reset();
		hidden2[i].reset();
	}

	for (int i = 0; i < 7; ++i) {
		output[i].reset();
	}

	int offset = 0;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 7; ++j) {
			int piece = brd[j][i];
			if (piece == 1) {
				input[offset].setVal(1);
			} else if (piece == 2) {
				input[offset].setVal(-1);
			} else {
				input[offset].setVal(0);
			}
			++offset;
		}
	}

	for (int i = 0; i < hiddens; ++i) {
		for (int j = 0; j < inputs; ++j) {
			hidden[i].addVal(input[j].output(pWeightIH[j][i]->val()));
		}
	}

	for (int i = 0; i < hiddens; ++i) {
		for (int j = 0; j < hiddens; ++j) {
			hidden2[i].addVal(hidden[j].output(pWeightHH[j][i]->val()));
		}
	}

	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < hiddens; ++j) {
			output[i].addVal(hidden2[j].output(pWeightHO[j][i]->val()));
		}
	}

	int best = 7;
	long double bestVal = -100;
	for (int i = 0; i < 7; ++i) {
		long double check = output[i].output();
		if (check > bestVal) {
			if (possibleMove(brd[i]) != -1) {
				bestVal = check;
				best = i;
			}
		}
	}
	int board[7][6];
	for (int x = 0; x < 7; ++x) {
		for (int y = 0; y < 6; ++y) {
			if (brd[x][y] == 2) {
				board[x][y] = 1;
			} else if (brd[x][y] == 1) {
				board[x][y] = 2;
			} else {
				board[x][y] = 0;
			}
		}
	}
	int minMove = benimaxMove(5, board);
	for (int out = 0; out < 7; ++out) {
		minMove == out ? output[out].assess(1) : output[out].assess(0);
	}
	//backprop();
	if (best == minMove) {
		++fitness;
	}
	return best;
}
