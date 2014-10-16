#ifndef ANAGRAMS_HH
#define ANAGRAMS_HH

#include <istream>
#include <string>
#include <list>

namespace anagrams {

  // This function finds all anagrams of a certain word from a input stream.
  // The function is case sensitive!
  // For example, "Word" is not an anagram of "word"
  //
  // Preconditions:
  // - word.size() > 0
  // - ifs.good() == true
  //
  // Postconditions:
  // - ifs.eof() == true
  //
  // Returns:
  // a list of strings, where each string is an anagram of
  // the second parameter. The list contains every word in the input stream
  // which was an anagram of the second parameter
  //
  // The words appear in the order they were in the input file.
  //
  // Throws:
  // std::logic_error, on precondition failure
  // std::runtime_error, on postcondition failure, or any other error
  
  std::list<std::string> find(std::istream &ifs, std::string const &word);
  
}



#endif
