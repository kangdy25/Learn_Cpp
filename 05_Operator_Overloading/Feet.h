#ifndef FEET_H_INCLUDED
#define FEET_H_INCLUDED
#include <iostream>
#include "Meter.h"

class Feet {
	int ft;
	int in;
public:
	Feet() : ft(0), in(0) {}
	Feet(int f, int i) : ft(f), in(i) {}
	Feet(const Meter &m) {
		int cmeter = m.getM() * 100 + m.getCm();
		in = static_cast<int>(cmeter / 2.54 + 0.5);
		ft = in / 12;
		in %= 12;
	}
	operator Meter() const {
		int m = static_cast<int>((ft * 12 + in) * 2.54 + 0.5);
		return Meter(m / 100, m % 100);
	}
	void display() const {
		if (ft)
			cout << ft << "ft ";
		if (in || !ft)
			cout << in << "in ";
		cout << endl;
	}
};
#endif
