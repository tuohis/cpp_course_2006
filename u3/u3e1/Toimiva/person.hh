#include "cperson.h"

#include <string>

namespace person
{
	class Person
	{
	public:
		Person(const Person &p);
		Person(const std::string name, int age);
		
		std::string getName() const;
		int getAge() const;
		CPerson const *getCPerson() const;
		void setName(std::string const &s);
		void setAge(int i);
		
		~Person();
	
		Person& operator=(const Person &p);
	
	private:
		CPerson *person_;
	};
}
