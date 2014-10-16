#include "statesaver.hh"
#include <iostream>

namespace statesaver {

StateSaver::StateSaver(std::ostream &os) : os_(os)
{
	this->flags = os.flags();
	this->precision = os.precision();
	this->width = os.width();
}

StateSaver::~StateSaver()
{
	this->os_.flags(this->flags);
	this->os_.precision(this->precision);
	this->os_.width(this->width);
}

}
