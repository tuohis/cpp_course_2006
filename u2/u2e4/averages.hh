



#ifndef AVERAGES_HH
#define AVERAGES_HH

#include <list>
#include <vector>
namespace averages {


  // This type is used to represent the sequence of numbers
  typedef std::list<int> list;
  // This type is used to represent the sequence of sequences of numbers
  typedef std::vector<std::list<int> > vector;

  
  // This function returns the average value of the list,
  // which has the highest average in this vector.
  //
  // Preconditions:
  // - v.size() > 0
  // - All lists in the vector have at least one element
  // Returns:
  // - The average value of the list which had the highest average.
  // Throws:
  // - std::logic_error on precondition failure
  double highestAverage(vector const &v);
  // This function returns the average value of the list,
  // which has the lowest average in this vector.
  //
  // Preconditions:
  // - v.size() > 0
  // - All lists in the vector have at least one element
  // Returns:
  // - The average value of the list which had the lowest average.
  // Throws:
  // - std::logic_error on precondition failure
  double lowestAverage(vector const &v);
  // This function returns the average value of the average
  // values of the list elements.
  //
  // Preconditions:
  // - v.size() > 0
  // - All lists in the vector have at least one element
  // Returns:
  // - The average value of all averages of the lists in the vector
  // Throws:
  // - std::logic_error on precondition failure
  double averageOfAverages(vector const &v);
}




#endif
