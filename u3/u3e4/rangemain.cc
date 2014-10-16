#include "range.hh"


#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <list>
int main() {

  using range::RangeCheck; using range::eraseInRange;
  using std::cout; using std::endl;

  RangeCheck<int> rg(1, 10); // range [1, 10]

  RangeCheck<int> rg2(2, 11); // [2, 11]
  RangeCheck<int> rg3(3, 7);
  cout << rg(2) << endl; // 2 is inside [1, 10]
  cout << rg(10) << endl;
  cout << rg(11) << endl; // 10 is inside [1, 10], but 11 is not.
  cout << rg(rg2) << endl; // [2, 11] is not inside [1, 10]
  cout << rg(rg3) << endl; // [3, 7] is inside [1, 10]
  std::cout << "---" << endl;

  double arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  std::vector<double> v(arr, arr + 12);
  std::list<double> v2(arr, arr + 12);


  // Let's print out all the numbers
  copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "));
  cout << endl;
  eraseInRange(v, 2.5, 13); // erase all numbers in the range [2.5, 13.0]
  eraseInRange(v2, 0.1, 3.9); // erase all numbers in the range [0.1, 3.9]
  copy(v.begin(), v.end(), std::ostream_iterator<double>(std::cout, " "));
  cout << endl;
  copy(v2.begin(), v2.end(), std::ostream_iterator<double>(std::cout, " "));
  cout << endl;
  
  try {
    RangeCheck<double> rinv(2.3, 1); // throws logic_error
  } catch (std::logic_error)
    {
      cout << "caught logic_error" << endl;
    }
  
  return 0;

}
