#ifndef FEEDBACKS_HH
#define FEEDBACKS_HH

#include "student.hh"

namespace student {

  // This function takes a list of students and a list of feedbacks,
  // and returns a new list where the feedback points have been added
  // to the points of the students.
  //
  // Because the feedback was given anonymously, there is no information
  // about the student in the feedbackList.
  //
  // To combine the points, you can assume that the elements with the same
  // index in the container belong together. For example, the points
  // for the fifth student in the student list are in the fifth position
  // of the feedback list.
  //
  // Preconditions:
  // - All students are valid (their invariant is true)
  // - list.size() == feedbackList.size()
  // Returns:
  // - A list of students with updated points and grades.
  // All students are valid in the list.
  // Throws:
  // - std::logic_error on precondition failure
  // - std::runtime_error if the return value is not valid.
  StudentList addFeedbackPoints(StudentList const &list,
                                std::vector<int> const &feedbackList);
  
  
  
}





#endif
