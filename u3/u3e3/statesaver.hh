#ifndef STATESAVER_HH
#define STATESAVER_HH

#include <ostream>

namespace statesaver {

  // StateSaver is a RAII class which stores the state of a output stream
  // in the constructor and restores it in the destructor.
  class StateSaver
  {
  public:
    
    StateSaver(std::ostream &os);
    ~StateSaver();

  private:
    // Private operator= and copy constructor
    // We want to prevent people from copying this class.
    StateSaver(StateSaver const &);
    StateSaver &operator=(StateSaver const &);
    
    // You can add your own private members here
  	std::ostream &os_;
	std::ostream::fmtflags flags;		// std::ostream::flags()
  	int precision;	// std::ostream::precision()
  	int width;		// std::ostream::width()
  	

  };
}
    




#endif
