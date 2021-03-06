#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <time.h>

#include "globals.h"

int prevFit;

time_t prevTime;

long double we[weights];

void writeFile() {
	time_t now = time(0);

	for (int w = 0; w < weights; ++w) {
		we[w] = weight[w].val();
	}

	char buff[100];

	snprintf(buff, 100, "weights_g%d_f%d_t%ld.bin", generation - 1, prevFit,
			prevTime);

	remove(buff);

	snprintf(buff, 100, "weights_g%d_f%d_t%ld.bin", generation, fitness, now);

	std::ofstream out(buff, std::ios::out | std::ios::binary);
	if (!out) {
		std::cout << "Cannot open file";
		return;
	}

	out.write((char *) &we, sizeof we);

	out.close();

	prevFit = fitness;

	prevTime = now;
}
