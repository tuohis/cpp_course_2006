#include "anagrams.hh"
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
	iostream ifs;
	ifs << "Tässä täsä tässä. Tääss äsät Tässä. ässät säsät säsätä säsä ä.säst";
	
	list<string> l = anagrams::find(ifs, "tässä");
	
	for (list<string>::iterator iter = l.begin(); iter != l.end(); iter++) {
		cout << *iter << endl;
	}
	
	l = anagrams::find(ifs, "Tässä");
	
	for (list<string>::iterator iter = l.begin(); iter != l.end(); iter++) {
		cout << *iter << endl;
	}
	
	return 0;
}

void print(std::string s)
{
	cout << s << std::endl;
	return;
}
