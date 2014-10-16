#include "person.hh"
#include "cperson.h"

#include <string>

typedef struct CPerson {
  char *name;
  int age;
} CPerson;

namespace person {

	Person::Person(const Person &p)
	{
		
		this->person_ = personCreateCopy(p.getCPerson());
	}
	
	Person::Person(const std::string name, int age)
	{
		this->person_ = personConstruct(name.c_str(), age);
	}
	
	std::string Person::getName() const
	{
		std::string s(this->person_->name);
		return s;
	}
	
	int Person::getAge() const
	{
		return this->person_->age;
	}
	
	CPerson const *Person::getCPerson() const
	{
		return this->person_;
	}
	
	
	void Person::setName(std::string const &s)
	{
		personSetName(this->person_, s.c_str());
	}
	
	void Person::setAge(int i)
	{
		personSetAge(this->person_, i);
	}
	
	
	Person::~Person()
	{
		personDestruct(this->person_);
	}
	
	Person& Person::operator=(const Person &p)
	{
		if (&p == this)
			return *this;
		
		personSetAge(this->person_, p.getAge());
		personSetName(this->person_, p.getName().c_str());
		
		
		return *this;
	}

}
