#ifndef WEIGHT_H_INCLUDED
#define WEIGHT_H_INCLUDED

class Weight {
public:
	void setVal(long double r) {
		value = r;
	}
	double val() {
		return value;
	}
	void suggest(long double s) {
		++suggestions;
		delta += (s - delta) / (suggestions + 1);
	}
	void change() {
		value += delta;
		suggestions = 0;
		delta = 0;
	}
private:
	long double value = 0;
	long double delta = 0;
	long suggestions = 0;
};

#endif // WEIGHT_H_INCLUDED
