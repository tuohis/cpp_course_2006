#include <algorithm>
#include <iterator>
#include <stdexcept>

namespace range {

template <class T>
class RangeCheck
{
public:
	
	RangeCheck(T const &a, T const &b) : a(a), b(b)
	{
		if (b < a)
			throw std::logic_error("Constructor: b<a");
	}
		
	bool operator() (T const &inRange)
	{
		return (inRange >= a && inRange <= b);
	}
	
	bool operator() (RangeCheck<T> const &range)
	{
		return (range.getA() >= a && range.getB() <= b);
	}
	
	T getA() const
	{
		return a;
	}
	T getB() const
	{
		return b;
	}

private:
	T a;
	T b;
};

template <class C, class T1, class T2>
void eraseInRange(C &container, T1 const &rBegin, T2 const &rEnd)
{
	if (rBegin > rEnd)
		throw std::logic_error("EraseInRange: rBegin > rEnd");
	
	RangeCheck<typename std::iterator_traits<typename C::iterator>::value_type> check(rBegin, rEnd);
	
	container.erase( std::remove_if(container.begin(), container.end(), check), 
					container.end() );
	
}

}
