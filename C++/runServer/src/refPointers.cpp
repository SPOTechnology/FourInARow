#include "globals.h"
#include "weight.h"

void refPointers() {
	int offset = 0;
	for (int i = 0; i < hiddens; ++i) {
		for (int j = 0; j < inputs; ++j) {
			pWeightIH[j][i] = &weight[offset];
			++offset;
		}
	}
	for (int i = 0; i < hiddens; ++i) {
		for (int j = 0; j < hiddens; ++j) {
			pWeightHH[j][i] = &weight[offset];
			++offset;
		}
	}

	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < hiddens; ++j) {
			pWeightHO[j][i] = &weight[offset];
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
