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
	long double bestVal = -100000;
	for (int i = 0; i < 7; ++i) {
		long double check = output[i].output();
		if (check > bestVal) {
			if (possibleMove(brd[i]) != -1) {
				bestVal = check;
				best = i;
			}
		}
	}
	return best;
}
