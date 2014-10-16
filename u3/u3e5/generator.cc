#include "generator.hh"
#include "rational.hh"

namespace rational {

MultipleGenerator::MultipleGenerator(Rational const &r)
{
	this->i = 0;
	this->n = r.getNumerator();
	this->d = r.getDenominator();
}

Rational MultipleGenerator::operator()()
{
	++i;
	return Rational(i*n, d);
}

}
