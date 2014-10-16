#ifndef SIEVE_HH
#define SIEVE_HH

#include <list>

namespace sieve {


  // This function performs the sieve of eratosthenes to a list.
  // preconditions:
  // - !list.empty()
  // - list is ordered, the first element is number 2
  // - there are no duplicate entries
  // - it contains all numbers from 2 to list.size() + 1
  // postconditions:
  // - the list contains all prime numbers from 2 to list.size() + 1
  
  void sieve(std::list<int> &list);
  
  // This function erases all multiples of a number from a list
  // preconditions:
  // - !list.empty()
  // - list is ordered, first element is nonnegative
  // - there are no duplicate entries
  // postconditions:
  // - all elements which are multiples of x (except x itself)
  //   are erased from the list.

  void eraseMultiplesOf(std::list<int> &list,
			int x);

}

#endif
