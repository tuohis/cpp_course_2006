#include "wordcounter.hh"
#include <iostream>

int main()
{
	std::vector<std::pair<std::string, wordcounter::sizeType> > v;
	int i;
	
	v = wordcounter::countWords("wordcounter.cc", 4);
	
	for (i=0; i < v.size(); i++) {
		std::cout << v[i].first << " " << v[i].second << std::endl;
	}
	return 0;
}
