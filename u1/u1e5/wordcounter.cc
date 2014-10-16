#include "wordcounter.hh"
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

std::vector<std::pair<std::string, wordcounter::sizeType> >
  wordcounter::countWords(std::string fileName,
	     wordcounter::sizeType n)
{
	std::string s;	// lukubufferi
	std::map<std::string, wordcounter::sizeType> m;
	std::vector<std::pair<std::string, wordcounter::sizeType> > v;
	std::map<std::string, wordcounter::sizeType>::iterator p1;
	unsigned int i;
	
	std::ifstream file_op(fileName.c_str());	// avataan file
	
	while (file_op >> s) {
		m[s]++;				// kasvatetaan sanan counttia
	}
	
	file_op.close(); 
	
	// käydään mappi läpi
	std::map<std::string, wordcounter::sizeType>::iterator iter;
	
	for (i=0; i < n; i++) {
		
		for (p1 = iter = m.begin(); iter != m.end(); ++iter) {
			if (iter->second > p1->second) {
				
				p1 = iter;
				
			}
		}
		v.push_back(*p1);
		m.erase(p1);
	}
	return v;
}
