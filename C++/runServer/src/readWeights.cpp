#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

#include "globals.h"

using namespace std;

long double temp[weights];

void readWeights() {
	ifstream in0("weights.bin", ios::in | ios::binary);
	if (in0.is_open()) {
		in0.read((char *) &temp, sizeof temp);
		in0.close();

		for (int i = 0; i < weights; ++i) {
			weight[i].setVal(temp[i]);
		}
	} else {
		cout << "Failed to read weights" << endl;
	}
}
