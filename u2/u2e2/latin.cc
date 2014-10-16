#include "latin.hh"
#include <ctype.h>
#include <iostream>
#include <iterator>
#include <streambuf>

namespace latin {
	
	class latinize
	{
	public:
	   	latinize(std::ostream &os): os_(os) {}
	   	
		void operator()(char c) const { 
			if ( !(isalnum(c) || isspace(c)) )
				return ;
	
			c = toupper(c);
	
			if (c == 'J')
				os_ << 'I';
			else if (c == 'K')
				os_ << 'C';
			else if (c == 'U')
				os_ << 'V';
			else
				os_ << c;
			
			return;
		}
	
	private:
	   std::ostream &os_;
	};
	
}

std::ostream &latin::transliterate(std::istream &is,
                              std::ostream &os)
{
	
	std::istreambuf_iterator<char> iter(is);
	std::istreambuf_iterator<char> end;
	
	latin::latinize f(os);
	
	for_each(iter, end, f);
	
	return os;
	
}
