#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>

#include "globals.h"
#include "weight.h"

long double random(double _min, double _max);

int compare(const void * a, const void * b) { //compare function for q sort
	if ((((Fitness*) b)->fit > ((Fitness*) a)->fit)) {
		return (1);
	}
	if ((((Fitness*) b)->fit < ((Fitness*) a)->fit)) {
		return (-1);
	}
	return (0);
}

void evolve() {
	std::cout << "\n\n\n\n\n\n\n\n\n\n";
	std::cout << "Generation number: " << generation << std::endl;
	for (int population = 0; population < pop; ++population) {
		qsort(fitness[population], gen, sizeof(Fitness), compare);
		for (int genome = 0; genome < gen; ++genome) {
			char buff[100];
			snprintf(buff, 100, "Population %d, Genome %d: %ld", population, genome, fitness[population][genome].fit);
			std::cout << buff << std::endl;
		}

		Weight tempWeight[gen][weights];
		for (int genome = 0; genome < gen; ++genome) {
			for (int w = 0; w < weights; ++w) {
				tempWeight[genome][w].value = weight[population][fitness[population][genome].index][w].val();
			}
		}
		for (int genome = 0; genome < gen / 2; ++genome) {
			for (int w = 0; w < weights; ++w) {
				weight[population][genome][w].setVal(tempWeight[genome][w].value);
				weight[population][(gen / 2) + genome][w].setVal(tempWeight[genome][w].value);
				weight[population][(gen / 2) + genome][w].mutate();
			}
		}
	}

	for (int population = 0; population < pop; ++population) {
		if (random(0, 1) < 0.10) {
			int fromPop = int(random(0, pop) - 0.000001);
			int fromGen = int(random(0, gen / 2) - 0.000001);
			for (int w = 0; w < weights; ++w) {
				weight[population][gen - 1][w].setVal(weight[fromPop][fromGen][w].val());
			}
		}
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n";
}
