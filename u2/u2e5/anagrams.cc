#include "anagrams.hh"
#include <string>
#include <stdexcept>
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

namespace anagrams {
	class match
	{
	public:
		// Konstruktori
		match(std::string const &word, std::list<std::string> &l) : 
			word_(word), l_(l), isAnagram_(true) {}
		
		void operator()(char c) {
			
			// Jos tulee whitespacea vastaan ja sana on tyhjä, on kyseessä anagrammi
			if (isspace(c)) {
				
				if (!isAnagram_) {
					isAnagram_ = true;
				}
				
				else if (compword_.length() == 0) {
					l_.push_back(tempword_);
					
				}
				compword_ = word_;
				tempword_ = "";
				return;
			}
			
			else if (!isAnagram_) return;
			
			else {
				iter_ = find(compword_.begin(), compword_.end(), c);
				
				if (iter_ == compword_.end()) {
					isAnagram_ = false;
				}
				else {
					compword_.erase(iter_);
					tempword_.push_back(c);
				}
			}
			return;
		}
		
	private:
		std::string const &word_;
		std::list<std::string> &l_;
		std::string compword_, tempword_;
		std::string::iterator iter_;
		bool isAnagram_;
	
	};
}		
		

std::list<std::string> anagrams::find(std::istream &ifs, std::string const &word)
{
	if (word.size() == 0)
		throw std::logic_error("Ei sanaa");
	if (!ifs.good())
		throw std::logic_error("Huono streami");
	
	
	std::list<std::string> l;
	
	anagrams::match f(word, l);
	
	std::istreambuf_iterator<char> streamReader(ifs);
	std::istreambuf_iterator<char> end;
	std::for_each(streamReader, end, f);
	
	// if (!ifs.eof())
		// throw std::runtime_error("Streami ei lopussa?");
	
	return l;
}
	
	/*
	Eli: käydään inputin jokainen merkki läpi. Haetusta sanasta poistetaan merkkejä
	sitä mukaa, kun niitä tulee vastaan. Kun tulee whitespacea, haettu sana
	resetataan ja aloitetaan uudestaan.
	*/
