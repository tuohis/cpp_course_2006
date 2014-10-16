
#include <ios>
#include <ostream>
namespace printer {

  // This function prints out a floating point number to output stream
  //
  // The floating point number is printed with a fixed number
  // of digits after the decimal point. The number of digits is
  // given as the third parameter. If the parameter is not given,
  // the default value is 2.
  //
  // Preconditions:
  // - os.good() is true
  // Postconditions:
  // - The second argument (num) is written to the output stream
  // with the proper precision.
  void printWithPrecision(std::ostream &os, double num,
                          std::streamsize precision = 2);
  
  
}
