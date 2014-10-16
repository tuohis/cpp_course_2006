#include "students.hh"
#include <algorithm>
#include <iostream>

// remove_ifin ja sortin vaatimat funktiot
namespace students {
	bool hasFailed(students::Student iVal);
	bool hasSmallerId(students::Student s1, students::Student s2);
	bool hasMorePoints(students::Student s1, students::Student s2);
}

bool students::hasFailed(students::Student iVal)
{
	return (iVal.exercisePoints == 0 || iVal.projectPoints == 0 || iVal.examPoints == 0);
}

bool students::hasSmallerId(students::Student s1, students::Student s2)
{
	return (s1.id < s2.id);
}

bool students::hasMorePoints(students::Student s1, students::Student s2)
{
	unsigned int p1 = s1.exercisePoints + s1.projectPoints + s1.examPoints;
	unsigned int p2 = s2.exercisePoints + s2.projectPoints + s2.examPoints;
	if (p1 == p2)
		return students::hasSmallerId(s1, s2);
	else
		return (p1 > p2);
}


void students::removeFailed(students::StudentArray &l)
{
	students::StudentArray::iterator iter;
	
	iter = remove_if(l.begin(), l.end(), students::hasFailed);
	l.erase(iter, l.end());
}

void students::sortByStudentId(students::StudentArray::iterator begin, 
								students::StudentArray::iterator end)
{
	std::sort(begin, end, students::hasSmallerId);
	
}


void students::sortByStudentPoints(StudentArray::iterator begin,
                           StudentArray::iterator end)
{
	std::sort(begin, end, students::hasMorePoints);
}


void students::print(Student const &s)
{
	unsigned int totalPoints = s.exercisePoints + s.projectPoints + s.examPoints;
	
	std::cout << s.id << " " << s.exercisePoints << " " << s.projectPoints
			  << " " << s.examPoints << " " << totalPoints << std::endl;
	
}


void students::printAll(StudentArray const &l)
{
	std::for_each(l.begin(), l.end(), students::print);
}
