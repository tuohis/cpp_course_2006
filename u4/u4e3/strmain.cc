#include "str.hh"

#include <iostream>
#include <fstream>


#include <vector>
#include <algorithm>
#include <iterator>

namespace {

  // We can transform strings to other
  // kinds of basic_strings of char by
  // converting them first to C strings
  // and then using the basic_string constructor
  // for charT *.
  
  template <typename From, typename To>
  To tr(From const &s)
  {
    return s.c_str();
  }
  
}

int main(int argc, char **argv) {
  using str::MyStr;
  std::string str;

  if (argc != 2)
    {
      std::cout << "Usage: " << argv[0] << ": <file name>" << std::endl;
      return 1;
    }

  std::ifstream ifs(argv[1]); // Open the file for reading
  
  std::vector<MyStr> vec;


  // Read all strings from standard input, transform
  // them to MyStr and then store them into vec.
  transform(std::istream_iterator<std::string>(ifs),
            std::istream_iterator<std::string>(),
            back_inserter(vec),
            tr<std::string, MyStr>); 
  
  // This should use our case insensitive comparing policy
  sort(vec.begin(), vec.end());

  // Convert all MyStr's to std::strings and copy them to
  // standard output, delimited by newline
  transform(vec.begin(), vec.end(),
            std::ostream_iterator<std::string>(std::cout, "\n"),
            tr<MyStr, std::string>);
  
  
}
