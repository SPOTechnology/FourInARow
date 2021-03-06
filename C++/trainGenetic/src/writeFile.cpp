#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>

#include "globals.h"

long prevFit[pop];

time_t prevTime;

long double we[pop][weights];

void writeFile() {
	time_t now = time(0);

	for (int w = 0; w < weights; ++w) {
		for (int population = 0; population < pop; ++population) {
			we[population][w] = weight[population][0][w].val();
		}
	}

	for (int population = 0; population < pop; ++population) {

		char buff[100];

		snprintf(buff, 100, "weights_g%d_pop%d_f%ld_t%ld.bin", generation - 1, population, prevFit[population], prevTime);

		remove(buff);

		snprintf(buff, 100, "weights_g%d_pop%d_f%ld_t%ld.bin", generation, population, fitness[population][0].fit, now);

		std::ofstream out(buff, std::ios::out | std::ios::binary);
		if (!out) {
			std::cout << "Cannot open file";
			return;
		}

		out.write((char *) &we[population], sizeof we[population]);

		out.close();

		prevFit[population] = fitness[population][0].fit;
	}

	prevTime = now;

	while (time(0) - prevTime < 10) {
	}
}
