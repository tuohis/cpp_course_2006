#include "sieve.hh"
#include <iostream>

void sieve::sieve(std::list<int> &list)
{
	
	int i;
	
	for (i=2; i < list.back(); i++) {
		
		sieve::eraseMultiplesOf(list, i);
	}
}


void sieve::eraseMultiplesOf(std::list<int> &list, int x)
{
	std::list<int>::iterator iter;
	
	
	for (iter = list.begin(); iter != list.end();) {
		if (*iter > x && *iter % x == 0) {
			iter = list.erase(iter);
		}
		else iter++;
	}
	
}
