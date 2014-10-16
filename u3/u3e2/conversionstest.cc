
#include "conversions.hh"


#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <iterator>
#include <string>



int main() {
  
  // Let's store a floating point number in a string.
  std::string str = "1.234";
  
  // Let's convert it to double...
  double d = conversions::fromString<double>(str);

  // This should also work
  double d2 = conversions::fromString<double>("10.20");
  std::cout << d << " " << d2 << std::endl;
  
  int num = 25;

  // The compiler can deduce the type of num from it's arguments
  // so we don't need to write toString<int>.
  str = conversions::toString(num);
  
  std::cout << str << std::endl;

  // Let's create a vector of ints.
  std::vector<int> v;

  for (int i = 0; i < 10; i++)
    v.push_back(i);
  
  // We want to copy them here as strings
  std::list<std::string> l;

  // We need to use back_inserter, because l is empty!
  try {
  	conversions::convertToString(v.begin(), v.end(), back_inserter(l));
  }
  catch (std::bad_cast) {
	  std::cout << "ERROR! Bad cast on line 45\n";
  }

  // We want to copy those strings as doubles here
  std::vector<double> vd;
  // Let's grow our vector so it can contain those elements
  vd.resize(l.size());
  try {
  	conversions::convertFromString(l.begin(), l.end(), vd.begin());
  }
  catch (std::bad_cast) {
	  std::cout << "ERROR! Bad cast on line 56\n";
  }

  // Let's print out our containers. They should look equal:
  std::cout << "---- v ----" << std::endl;
  std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;

  std::cout << "---- l ----" << std::endl;
  std::copy(l.begin(), l.end(), std::ostream_iterator<std::string>(std::cout, ", "));
  std::cout << std::endl;

  std::cout << "---- vd ----" << std::endl;
  std::copy(vd.begin(), vd.end(), std::ostream_iterator<double>(std::cout, ", "));
  std::cout << std::endl;

  // Kokeillaan str->str-muunnosta
  str = "Kaksi sanaa";
  std::string str2 = conversions::fromString<std::string>(str);
  std::cout << str << str2 << std::endl;
  
  
  // Let's try to convert something to int which can not be converted

  try {
    int invalid = conversions::fromString<int>("can't convert this");
	std::cout << invalid << std::endl;
  } catch (std::bad_cast const &)
    {
      std::cout << "Caught std::bad_cast!" << std::endl;
    }
  
  std::cout << "That's it!" << std::endl;
  
}
