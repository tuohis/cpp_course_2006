
#include <iostream>

namespace latin {
  // This function transliterates text from is
  // to the original latin alphabet and outputs the result
  // to os.
  // Returns: the second parameter, os
  std::ostream &transliterate(std::istream &is,
                              std::ostream &os);
}
