#include "latin.hh"
#include <ctype.h>
#include <iostream>
#include <iterator>
#include <streambuf>

namespace latin {
	void latinize(char &c);
}



void latin::latinize(char &c)
{
	if ( !(isalnum(c) || isspace(c)) )
		return ;
	
	c = toupper(c);
	
	if (c == 'J')
		c = 'I';
	else if (c == 'K')
		c = 'C';
	else if (c == 'U')
		c = 'V';
	
	return;
}
	

std::ostream &latin::transliterate(std::istream &is,
                              std::ostream &os)
{
	
	std::copy(is, is + is.size(), os);
	std::istreambuf_iterator<char> iter(os);
	
	std::for_each(iter, std::istream_iterator<char>(), latin::latinize);
	
	return os;
}
