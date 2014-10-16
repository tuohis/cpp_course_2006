#ifndef HH_MYSTR
#define HH_MYSTR

#include <string>

namespace str {

class MyStrTraits : public std::char_traits<char> {
public:
	
	static bool lt(char const &a, char const &b)
	{
		return (tolower(a) < tolower(b));
	}
	
	static bool eq(char const &a, char const &b)
	{
		return (tolower(a) == tolower(b));
	}
	
	static int compare(const char* str1, const char* str2, int num)
	{
		int retval = 0;
		for (int i = 0; i < num; i++) {
			if (str1[i] == '\0' || str2[i] == '\0')
				break;
			
			if ( !eq(str1[i], str2[i]) ) {
				if ( lt(str1[i], str2[i]) )
					retval = -1;
				else
					retval = 1;
				
				break;
			}
		}
		return retval;
	}
};
		

class MyStr : public std::basic_string< char, MyStrTraits, std::allocator<char> > {
public:
	MyStr(char const *str) 
		: std::basic_string< char, MyStrTraits, std::allocator<char> >(str) {}
		
};


}

#endif
