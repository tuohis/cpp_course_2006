#include "person.hh"
#include "cperson.h"
#include <iostream>
#include <string>

int main()
{
	person::Person p1("Mikko", 20);
	person::Person p2(p1);
	person::Person p3(p1);
	
	std::cout << p1.getName() << " " << p1.getAge() << std::endl;
	std::cout << p2.getName() << " " << p2.getAge() << std::endl;
	
	p2.setName("Esa");
	p2.setAge(100);
	
	p3 = p3 = p2;
	
	p3.setAge(39);
	
	std::cout << p2.getName() << " " << p2.getAge() << std::endl;
	std::cout << p3.getName() << " " << p3.getAge() << std::endl;
	
	return 0;
}
