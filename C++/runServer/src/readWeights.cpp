#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "globals.h"

long double temp[weights];

void readWeights() {
	std::ifstream in0("weights.bin", std::ios::in | std::ios::binary);
	if (in0.is_open()) {
		in0.std::ifstream::read((char *) &temp, sizeof temp);
		in0.std::ifstream::close();

		for (int i = 0; i < weights; ++i) {
			weight[i].setVal(temp[i]);
		}
	} else {
		std::cout << "Failed to read weights" << std::endl;
	}
}
