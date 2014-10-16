#include "bird.hh"
#include <string>
#include <iostream>

namespace aviary {

class Duck : public Bird {
public:
	
	explicit Duck(std::string const &name);
	Duck(const Bird &d);
	~Duck();
	
	void speak(std::ostream &os) const;

};

}
