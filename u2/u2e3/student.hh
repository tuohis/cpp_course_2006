
#ifndef STUDENT_HH
#define STUDENT_HH
#include <list>
#include <vector>

namespace student {


  // The maximum amount of points a student can receive
  static const int MAXPOINTS = 31;
  
  // Contains the information about a student and his/her grades
  // Invariant for Student s:
  // - points <= MAXPOINTS
  // - grade == (points / 6)
  struct Student {
    int id;
    int points;
    int grade;
  };
  // A sequential container to contain students.
  // You can assume the StudentList is either implemented
  // as a vector, or a list.
  typedef std::list<Student> StudentList;
  
  
  // This function changes the points of a student.
  // It also must update the grade to keep the student data valid
  // Preconditions:
  // - points <= MAXPOINTS
  // Postconditions:
  // s.points == points
  // s.grade == (points / 6)
  // Throws:
  // - std::logic_error on precondition failure
  void setPoints(Student &s, int points);
  

  // This function checks is the invariant of a student true.
  // Returns:
  // true if the invariant of s is true, false otherwise
  bool isValid(Student const &s);
  
  
}

#endif
