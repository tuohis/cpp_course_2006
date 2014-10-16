#include "bird.hh"
#include <string>
#include <iostream>

namespace aviary {

class Owl : public Bird {
public:
	
	explicit Owl(std::string const &name);
	Owl(Bird const &d);
	~Owl();
	
	void speak(std::ostream &os) const;

};

}
