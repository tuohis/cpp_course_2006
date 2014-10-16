#include "rational.hh"

namespace rational {

class MultipleGenerator {

public:
	
	MultipleGenerator(Rational const &r);
	
	Rational operator()();

private:

	int i;
	int n;
	int d;
};

}
