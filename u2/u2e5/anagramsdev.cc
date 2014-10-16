#include "anagrams.hh"
#include <string>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

namespace anagrams {
	class Match
	{
	public:
		// Konstruktori
		Match(std::string const &word, std::list<std::string> &l) : word_(word), l_(l) {}
		
		
		void operator()(std::string s) {
			tempword_ = word_;
			isAnagram_ = true;
			
			std::iterator iter = find_first_of(tempword_.begin(), tempword_.end(), 
							s.begin(), s.end());
			if (iter == tempword_.begin()
			
			if (isAnagram_ == true && tempword_ == "")
				l_.push_back(s);
			
			
			return;
		}
			
	private:
		std::string const &word_;
		std::list<std::string> &l_;
		
		std::string tempword_;
		bool isAnagram_;
		char c_;
		
		// for_eachin apufunktio
		void checkIfInWord(char c) {
			// Jos ei ole anagrammi tähän mennessä, niin ei sitten ole tämän
			// jälkeenkään
			if (isAnagram_ = false) {
				return;
			}
			
			// Jos taas tähän mennessä ok, niin kokeillaan edelleen
			else {
				c_ = c;
				
				// poistaa yhden instanssin kirjainta c
				std::string::iterator i = remove_if(tempword_.begin(),
													tempword_.end(),
													&anagrams::Match::isC);
				// Jos voidaan poistaa kirjain, niin 
				if (i != tempword_.end()) {
					tempword_.erase(i);
					// isAnagram_ on edelleen true
					
				
				}
				else {
					isAnagram_ = false;
				
				}
			}
			return;
		}
		
		// remove_ifin predikaattifunktio
		bool isC(char c) {
			return (c == c_);
		}
	};
}		
		

std::list<std::string> anagrams::find(std::istream &ifs, std::string const &word)
{
	std::list<std::string> l;
	
	anagrams::Match f(word, l);
	
	std::istream_iterator<std::string> wordReader(ifs);
	std::istream_iterator<std::string> end;
	for_each(wordReader, end, f);
	
	return l;
}
