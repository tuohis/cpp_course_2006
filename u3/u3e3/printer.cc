#include "printer.hh"
#include "statesaver.hh"
#include <iostream>
#include <ios>

namespace printer {

void printWithPrecision(std::ostream &os, double num,
                          std::streamsize precision)
{
	statesaver::StateSaver ss(os);
	
	os.precision(precision);
	// os.width(precision);
	// os.fill('0');
	os.setf(std::ios_base::fixed);
	os.setf(std::ostream::left);
	
	os << num;
}
	
}
