#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
#include "rational.hh"

namespace rational {

// if denominator is 0, std::logic_error is thrown.
Rational::Rational(int numerator, int denominator)
{
	if (denominator == 0)
		throw std::logic_error("Denominator 0");
	
	this->numerator = numerator;
	this->denominator = denominator;
	this->normalize();
}

// This creates a rational number which is equal to the integer "num"
Rational::Rational(int num)
{
	this->numerator = num;
	this->denominator = 1;
}

// copy constructor
Rational::Rational(const Rational &r)
{
	this->numerator = r.getNumerator();
	this->denominator = r.getDenominator();
	this->normalize();
}

// accessors
int Rational::getNumerator() const
{
	return this->numerator;
}
int Rational::getDenominator() const
{
	return this->denominator;
}

// Comparison operators
bool Rational::operator==(Rational const &r)
{
	int n = r.getNumerator();
	int d = r.getDenominator();
	int gcd1 = Rational::gcd(n, d);
	int gcdThis = Rational::gcd(this->numerator, this->denominator);
	
	return (n / gcd1 == this->numerator / gcdThis && 
		d / gcd1 == this->denominator / gcdThis);
	
}

bool Rational::operator<(Rational const &r)
{
	return ((double)r.getNumerator() / r.getDenominator() > 
			(double)this->numerator / this->denominator);
	
}

bool Rational::operator>=(Rational const &r)
{
	return !(*this < r);
}


bool Rational::operator!=(Rational const &r)
{
	return !(*this == r);
}

bool Rational::operator<=(Rational const &r)
{
	return (*this < r || *this == r);
}rational.hh

bool Rational::operator>(Rational const &r)
{
	return !(*this <= r);
}

// assignment operators =, +=, -=
Rational &Rational::operator=(Rational const &r)
{
	this->numerator = r.getNumerator();
	this->denominator = r.getDenominator();
	this->normalize();
	return *this;
}

Rational &Rational::operator+=(Rational const &r)
{
	// Lavennetaan murtoluvut samannimisiksi
	this->numerator = r.getDenominator() * this->numerator + 
						this->denominator * r.getNumerator();
	this->denominator *= r.getDenominator();
	this->normalize();
	return *this;
}

Rational &Rational::operator+=(int i)
{
	this->numerator += this->denominator * i;
	this->normalize();
	return *this;
}

Rational &Rational::operator-=(Rational const &r)
{
	this->numerator = r.getDenominator() * this->numerator - 
						this->denominator * r.getNumerator();
	this->denominator *= r.getDenominator();
	this->normalize();
	return *this;
}

Rational &Rational::operator-=(int i)
{
	this->numerator -= this->denominator * i;
	return *this;
}

// binary operators +, -
Rational operator+(Rational const &r1, Rational const &r2)
{
	Rational rr(r2.getDenominator() * r1.getNumerator() + 
					r1.getDenominator() * r2.getNumerator() ,
					r1.getDenominator() * r2.getDenominator());
	return rr;
}

Rational operator+(Rational const &r, int i)
{
	Rational rr(r.getNumerator() + r.getDenominator() * i, r.getDenominator());
	
	return rr;
}

Rational operator-(Rational const &r1, Rational const &r2)
{
	Rational rr = r1 + (-r2);
	
	return rr;
}

Rational operator-(Rational const &r, int i)
{
	Rational rr = r + (-i);
	
	return rr;
}

// unary operator -
Rational operator-(Rational const &r)
{
	Rational rr(-1*r.getNumerator(), r.getDenominator());
	
	return rr;
}



/* input and output operators << and >>
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
*/

std::ostream &operator<<(std::ostream &os, Rational const &r)
{
	os << r.getNumerator() << " " << r.getDenominator();
	
	return os;
}

std::istream &operator>>(std::istream &is, Rational &r)
{
	int n, d;
	is >> n;
	if (is.good()) {
		is >> d;
		if (!is.fail())		// Jos ei virhettä, voidaan kirjoittaa r:ään
			r = Rational(n, d);
	}
	return is;
}

/* This function returns the greatest common divisor
// for a and b. It is useful for normalizing a rational number.
//
// For example 6/9, gcd(6, 9) == 3 so we can divide
// both the numerator and denominator by 3 to get 2/3.
*/

int Rational::gcd(int a, int b)
{
  using std::swap;
  a = std::abs(a);
  b = std::abs(b);
  if (a>b) swap(a,b);
  while (a)
	{
	  b %= a;
	  swap(a,b);
	}
  return b;
}



void Rational::normalize()
{
	if (denominator<0) {		// Normalisoidaan etumerkit
		numerator = -numerator;
		denominator = -denominator;
	}
	
	int gcd1 = gcd(numerator, denominator);
	numerator /= gcd1;
	denominator /= gcd1;
}

}
