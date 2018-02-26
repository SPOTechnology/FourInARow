#ifndef NEURON_H_INCLUDED
#define NEURON_H_INCLUDED

#include <cmath>

class InputNeuron {
public:
	void setVal(double val) {
		value = val;
	}
	double output(double weight) {
		return value * weight;
	}
	void reset() {
		value = 0;
	}
private:
	long double value = 0.00;
};

class HiddenNeuron {
public:
	void addVal(long double val) {
		value += val;
	}
	double output(double weight) {
		return (1 / (1 + exp(-value))) * weight;
	}
	void reset() {
		value = 0;
	}
private:
	long double value = 0.00;
};

class OutputNeuron {
public:
	void addVal(long double val) {
		value += val;
	}
	double output() {
		return (log(1 + exp(value)) - log(2));
	}
	void reset() {
		value = 0;
		c = 0;
	}
	void assess(int right) {
		c = pow((right - value), 2);
	}
	double cost() {
		return c;
	}
private:
	long double value = 0.00;
	double c = 0;
};

#endif // NEURON_H_INCLUDED
