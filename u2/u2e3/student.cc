#include "student.hh"
#include <stdexcept>

void student::setPoints(student::Student &s, int points)
{
	if (points <= student::MAXPOINTS) {
		s.points = points;
		s.grade = (int)(points / 6);
	}
	else
		throw std::logic_error("Pisteidenasetusvirhe");
	
	return;
}

bool student::isValid(student::Student const &s)
{
	return (s.points <= student::MAXPOINTS && s.grade == (int)(s.points / 6));
}
