// Grad.cpp

#include <algorithm>

#include "Int1.h"

istream& read_hw(istream& in, vector<double>& hw);

istream& Int1::read(istream& in) {
	Core::read_common(in);
	in >> toeic;
	read_hw(in, Core::homework);
	return in;
}
double Int1::grade() const {
	return min(Core::grade(), toeic);
}