#include "duck.hh"
#include "bird.hh"
#include <stdexcept>
#include <string>
#include <iostream>

namespace aviary {

	Duck::Duck(std::string const &name) : Bird(name) {}
	Duck::Duck(const Bird &d) : Bird(d.getName()) {}
	Duck::~Duck() {}
		
	void Duck::speak(std::ostream &os) const
	{
		if (os == NULL)
			throw std::logic_error("Nollastreami");
		
		os << this->getName() << ": QUACK\n";
	}
	
}
