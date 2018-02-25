#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#include "neuron.h"
#include "weight.h"

#define weights ((42*42)+(42*42)+(42*7)) //inputs*hiddens + hiddens*hiddens + hiddens*outputs
#define hiddens 42
#define inputs 42

#define pop 3
#define gen 12

extern Weight weight[pop][gen][weights];
extern Weight *pWeightIH[pop][gen][inputs][hiddens];
extern Weight *pWeightHH[pop][gen][hiddens][hiddens];
extern Weight *pWeightHO[pop][gen][hiddens][7];

extern int brd[7][6];
extern int depthCost;
extern int depthOp;
extern int generation;

extern InputNeuron input[inputs];
extern HiddenNeuron hidden[hiddens];
extern HiddenNeuron hidden2[hiddens];
extern OutputNeuron output[7];

typedef struct {
	long fit;
	int index;
} Fitness;

extern Fitness fitness[pop][gen];

#endif // GLOBALS_H_INCLUDED