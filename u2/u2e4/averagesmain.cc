#include "averages.hh"
#include <iostream>
#include <stdexcept>

int main()
{
	int i, j;
	double a, h, m;
	std::vector<std::list<int> > v;
	std::list<int> l;
	
	for (i = 0; i < 5; i++) {
		v.push_back(l);
		for (j=i; j<10; j++) {
			v[i].push_back(j);
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
	
	h = averages::highestAverage(v);
	m = averages::lowestAverage(v);
	a = averages::averageOfAverages(v);
	
	std::cout << std::endl << std::endl << h << std::endl;
	std::cout << m << std::endl;
	std::cout << a << std::endl;
	
	return 0;
}
