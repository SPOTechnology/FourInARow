#include <stdlib.h>

long double random(double _min, double _max) {
	long double f = (long double) rand() / RAND_MAX;
	return _min + f * (_max - _min);
}
