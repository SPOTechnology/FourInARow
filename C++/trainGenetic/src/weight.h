#ifndef WEIGHT_H_INCLUDED
#define WEIGHT_H_INCLUDED

#include <time.h>

long double random(double _min, double _max);

class Weight {
public:
	void setVal(long double r) {
		value = r;
	}
	long double val() {
		return value;
	}
	void mutate() {
		if (random(0, 1) < 0.5) {
			value += random(-0.5, 0.5);
			if (value > 1) {
				value = 1;
			} else if (value < -1) {
				value = -1;
			}
		}
	}
	long double value = 0;
};

#endif // WEIGHT_H_INCLUDED
