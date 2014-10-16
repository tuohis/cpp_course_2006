#ifndef STUDENTS_HH
#define STUDENTS_HH

#include <vector>
#include <ostream>

namespace students {
  struct Student {
    // The student ID
    int id;
    // How many points the student received from the exercises.
    int exercisePoints;
    // How many points the student received from the project.
    int projectPoints;
    // How many points the student received from the exam
    int examPoints;
  };
  
  // The storage type for students.
  // You can assume identical behaviour to std::vector<Student>.
  typedef std::vector<Student> StudentArray;
  
  // This function erases all students from the array who failed the course.
  // Postconditions:
  // - l does not contain students, which have received 0 from the exercises,
  // project OR exam.
  void removeFailed(StudentArray &l);
  
  // This function sorts a iterator range by the student id in ASCENDING ORDER
  // Preconditions:
  // - [begin, end[ is a valid iterator range. All student ID's are unique in the range.
  // Postconditions:
  // - For all i in the range [begin, end[: ((i + 1) == end || i->id < (i+1)->id)
  void sortByStudentId(StudentArray::iterator begin, StudentArray::iterator end);

  // This function sorts a iterator range by the sum of all points
  // of a student in DESCENDING ORDER. If two students have equal points, then
  // the student with smaller ID comes first.
  // Preconditions:
  // - [begin, end[ is a valid iterator range
  // Postconditions:
  // - For all i in the range [begin, end[:
  //     ((i + 1) == end
  //           ||
  // the sum of all points of *i > the sum of all points of *(i + 1)
  //           ||
  // (the sum of all points of *i == the sum of all points of *(i + 1)) AND
  //                        i->id < (i+1)->id
  
  void sortByStudentPoints(StudentArray::iterator begin,
                           StudentArray::iterator end);
  
  // This function prints the information about a student to std::cout
  // in following format:
  // <student ID> <exercise points> <project points> <exam points> <total points>\n
  // For example, if student 12345 has 1 exercise point, 4 project points and
  // 2 exam points, the following is printed to standard output:

  // 12345 1 4 2 7
  void print(Student const &s);

  // This function prints all students to std::cout in the order they appear in l.
  // The students are separated by newline \n
  void printAll(StudentArray const &l);
  
  
}




#endif
