#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "generator.hh"
#include "rational.hh"
int main()

{
  using rational::Rational;
  using rational::MultipleGenerator;


  
/* should print out
   2 3
   4 3
   2 1
   8 3
*/
  std::generate_n(std::ostream_iterator<Rational>(std::cout, "\n"),
                  4,
                  MultipleGenerator(Rational(2, 3)));
  

}
