#include "printer.hh"
#include "statesaver.hh"
#include <iostream>

int main()
{
	printer::printWithPrecision(std::cout, 1.23456, 0);
	std::cout << std::endl;
	printer::printWithPrecision(std::cout, 1.23456, 1);
	std::cout << std::endl;
	printer::printWithPrecision(std::cout, 1.23456);
	std::cout << std::endl;
	printer::printWithPrecision(std::cout, 1.23456, 3);
	std::cout << std::endl;
	printer::printWithPrecision(std::cout, 1.23456, 10);
	std::cout << std::endl;
	
	return 0;
}
