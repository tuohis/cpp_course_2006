#ifndef RATIONAL_HH
#define RATIONAL_HH

#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdlib>

namespace rational {

  class Rational {
  public:

    // if denominator is 0, std::logic_error is thrown.
    Rational(int numerator,
             int denominator);
    
    // This creates a rational number which is equal to the integer "num"
    Rational(int num);

    // copy constructor
    Rational(const Rational &r);
    
    // accessors
    int getNumerator() const;
    int getDenominator() const;

    // You must implement these operators:
    //
    // ==, <, =, +=, -=
	bool operator==(Rational const &r);
	bool operator<(Rational const &r);
  	bool operator>=(Rational const &r);
	bool operator!=(Rational const &r);
	bool operator<=(Rational const &r);
	bool operator>(Rational const &r);
	
	Rational &operator=(Rational const &r);
	Rational &operator+=(Rational const &r);
	Rational &operator+=(int i);
	Rational &operator-=(Rational const &r);
	Rational &operator-=(int i);
	
    

    
  private:

	int numerator;
  	int denominator;
  
    // This function returns the greatest common divisor
    // for a and b. It is useful for normalizing a rational number.
    //
    // For example 6/9, gcd(6, 9) == 3 so we can divide
    // both the numerator and denominator by 3 to get 2/3.
    
  	void normalize();
  
    int gcd(int a, int b);
    
  };


// binary operators +, -
Rational operator+(Rational const &r1, Rational const &r2);
Rational operator+(Rational const &r, int i);
Rational operator-(Rational const &r1, Rational const &r2);
Rational operator-(Rational const &r, int i);

// unary operator -
Rational operator-(Rational const &r);

// input and output operators << and >>
// so the class can be streamed to and streamed from.
// The rational number is formatted like this:
// <numerator> <denominator>
// For example if numerator is 4 and denominator is 5, the output is
// 4 5
// 
// The output stream operators "normalize" the rational number.
// For example, 2/4 is written to output as "1 2",
// 1/-2 is written to output as "-1 2" and -2/-4 is written as
// "1 2".
//
// You can implement these operators either as member functions,
// or nonmember functions in the namespace scope.


std::ostream &operator<<(std::ostream &os, Rational const &r);
std::istream &operator>>(std::istream &is, Rational &r);

}


#endif
