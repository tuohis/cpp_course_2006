#include "bird.hh"
#include "owl.hh"
#include <string>
#include <iostream>
#include <stdexcept>

namespace aviary {

	Owl::Owl(std::string const &name) : Bird(name) {}
	Owl::Owl(Bird const &d) : Bird(d.getName()) {}
	Owl::~Owl() {}
	
	void Owl::speak(std::ostream &os) const
	{
		if (os == NULL)
			throw std::logic_error("Nollastreami");
		
		os << this->getName() << ": WHUU\n";
	}

}
