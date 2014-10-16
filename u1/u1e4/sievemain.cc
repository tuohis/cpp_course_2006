#include "sieve.hh"
#include <iostream>
#include <string>
#include <list>

int main()
{
	
	unsigned int i;
	std::list<int>::iterator iter;
	std::list<int> list;
	
	for (i=2; i<21; i++) {
		list.push_back(i);
	}
	
	for (iter=list.begin(); iter != list.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	
	sieve::eraseMultiplesOf(list, 2);
	
	for (iter=list.begin(); iter != list.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
	
	sieve::sieve(list);
	
	for (iter=list.begin(); iter != list.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	return 0;
}
