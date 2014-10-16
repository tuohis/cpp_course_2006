#include <sstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <iterator>

namespace conversions {

	
template <class T>
T fromString(std::string const &s)
{
	T retval;
	std::stringstream ss;
	ss.str(s);
	
	ss >> retval;
	
	if (ss.fail())
		throw std::bad_cast();
	
	return retval;
	
}

template <>
std::string fromString(std::string const &s)
{
	return s;
}


template <class T>
std::string toString(T const &tos)
{
	std::stringstream ss;
	ss << tos;
	
	if (ss.fail())
		throw std::bad_cast();
	else
		return ss.str();
}


template <class InputIterator, class OutputIterator>
void convertToString(InputIterator begin, InputIterator end, OutputIterator dest)
{
	for(; begin != end; begin++, dest++) {
		*dest = toString<typename std::iterator_traits<InputIterator>::value_type>(*begin);
	
	}
}

template <class InputIterator, class OutputIterator>
void convertFromString(InputIterator begin, InputIterator end, OutputIterator dest)
{

	for(; begin != end; begin++, dest++) {
		
		*dest = fromString<typename std::iterator_traits<OutputIterator>::value_type>(*begin);
	}
}

}
