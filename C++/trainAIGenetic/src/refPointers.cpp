#include "globals.h"
#include "weight.h"

using namespace std;


void refPointers(int population, int genome) {
	int offset = 0;
	for (int i = 0; i < hiddens; ++i) {
		for (int j = 0; j < inputs; ++j) {
			pWeightIH[population][genome][j][i] = &weight[population][genome][offset];
			++offset;
		}
	}
	for (int i = 0; i < hiddens; ++i) {
		for (int j = 0; j < hiddens; ++j) {
			pWeightHH[population][genome][j][i] = &weight[population][genome][offset];
			++offset;
		}
	}

	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < hiddens; ++j) {
			pWeightHO[population][genome][j][i] = &weight[population][genome][offset];
			++offset;
		}
	}
}


/*

	int weight[42] = {0};
	weight[3] = 10;
	int *pWeight;
	pWeight = &weight[3];
	*pWeight = 3;
	cout << weight[3] << endl;


	outputs "3"


*/
