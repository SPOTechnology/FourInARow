#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

#define weights ((42*42)+(42*42)+(42*7)) //inputs*hiddens + hiddens*hiddens + hiddens*outputs
#define inputs 42
#define hiddens 42

#include "neuron.h"
#include "weight.h"

extern Weight weight[weights]; //for weights
extern Weight *pWeightIH[inputs][hiddens];
extern Weight *pWeightHH[hiddens][hiddens];
extern Weight *pWeightHO[hiddens][7];
extern int brd[7][6];
extern int depthCost;
extern int depthOp;
extern int fitness;
extern int generation;

extern InputNeuron input[inputs];
extern HiddenNeuron hidden[hiddens];
extern HiddenNeuron hidden2[hiddens];
extern OutputNeuron output[7];

#endif // GLOBALS_H_INCLUDED
