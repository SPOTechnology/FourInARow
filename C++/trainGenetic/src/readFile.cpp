#include <iostream>
#include <fstream>

#include "globals.h"
#include "weight.h"

long double random(double _min, double _max);

void readFile(char fileName[]) {
	long double tempWeight[weights];
	std::ifstream inFile(fileName, std::ios::in | std::ios::binary);
	if (inFile.is_open()) {
		inFile.read((char *) &tempWeight, sizeof tempWeight);
		inFile.close();
	} else {
		std::cout << "Failed to read weights" << std::endl;
		while (1) {
		}
	}
	for (int population = 0; population < pop / 2; ++population) {
		for (int w = 0; w < weights; ++w) {
			weight[population][0][w].setVal(tempWeight[w]);
		}
		for (int genome = 1; genome < gen / 2; ++genome) {
			for (int w = 0; w < weights; ++w) {
				if (random(0, 1) < 0.5) {
					weight[population][genome][w].setVal(tempWeight[w] + random(-0.5, 0.5));
				} else {
					weight[population][genome][w].setVal(tempWeight[w]);
				}
			}
		}
	}
}

