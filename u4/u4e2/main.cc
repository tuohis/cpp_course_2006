#include "atm.hh"
#include "account.hh"
#include <iostream>
#include <string>

using namespace bank;

int main(void)
{
	Account esko("Esko");
	Account pasi("Pasi");
	
	std::cout << esko << std::endl;
	std::cout << pasi << std::endl;
	
	Atm otto(std::cout);
	
	otto.deposit(esko, 100);
	std::cout << esko << std::endl;
	std::cout << pasi << std::endl;
	
	try {
		otto.withdraw(pasi, 10);
	} catch(...) {
		std::cout << "Ei onnannu withdraw(pasi, 10)\n";
	}
	
	std::cout << esko << std::endl;
	std::cout << pasi << std::endl;
	
	try {
		otto.transfer(esko, pasi, 90);
	} catch(int) {
		std::cout << "Ei onnannu transfer(esko, pasi, 90)\n";
	}
	
	std::cout << esko << std::endl;
	std::cout << pasi << std::endl;
	
	pasi.lock();
	std::cout << "Pasi on nyt lukittu\n";
	
	
	std::cout << esko << std::endl;
	std::cout << pasi << std::endl;
	
	try {
		otto.transfer(pasi, esko, 10);
	} catch(...) {
		std::cout << "Ei onnannu transfer(pasi, esko, 10)\n";
	}
		
	std::cout << esko;
	std::cout << pasi;
	
	return 0;
}
