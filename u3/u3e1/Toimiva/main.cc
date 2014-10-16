#include "person.hh"
#include "cperson.h"
#include <iostream>
#include <string>

int main()
{
	using namespace person;
	 const Person p("Esko", 25);
	
	 // Prints "Esko 25"
	 std::cout << p.getName() << " " << p.getAge() << std::endl;
	
	 Person p2(p);
	p2 = p;
	 p2.setName("Jussi");
	p2.setAge(200);
	 // Prints "Jussi 25"
	 std::cout << p2.getName() << " " << p2.getAge() << std::endl;
	
	 Person p3("foo", 10);
	 p3 = p2;
	 // Prints "Jussi 25"
	 std::cout << p3.getName() << " " << p3.getAge() << std::endl;
	
	 p3 = p3; // Nothing happens
	
	 // Prints "Jussi 25"
	 std::cout << personGetName(p3.getCPerson()) << " " <<
	 personGetAge(p3.getCPerson()) << std::endl;
	 // p, p2 and p3 go out of scope and all memory related to them is freed
	
	/*person::Person p1("Mikko", 20);
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
	
	*/return 0;
}
