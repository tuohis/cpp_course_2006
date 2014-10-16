#include <utility>
#include <vector>
#include <string>
namespace wordcounter {

  // The unsigned integer type which is used to represent the number of words.
  typedef unsigned int sizeType;

  // preconditions: file exists and can be accessed
  // returns: a vector of pairs (word, count)
  //          The vector has either n elements, or as many elements
  //          as the input file had distinct words.
  
  std::vector<std::pair<std::string, sizeType> >
  countWords(std::string fileName,
	     sizeType n);
  




}
