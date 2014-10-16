#include <ostream>
#include <stdexcept>
#include "account.hh"
#include "atm.hh"

namespace bank {
	// Konstruktori
	Atm::Atm(std::ostream &os) : os(os) { if (os == NULL) throw std::logic_error("huono streami"); }
	
	void Atm::deposit(Account &acc, MoneyType m)
	{
		acc.deposit(m);		// Jos heittää exceptionia, pitäisi lähteä käymään
							// pinoa läpi, eikä suorittaa seuraavaa riviä
		os << acc.getOwner() << " deposit " << m << std::endl;
	}
	
	void Atm::withdraw(Account &acc, MoneyType m)
	{
		acc.withdraw(m);	// Jos heittää exceptionia, pitäisi lähteä käymään
							// pinoa läpi, eikä suorittaa seuraavaa riviä
		os << acc.getOwner() << " withdraw " << m << std::endl;
	}
	
	void Atm::transfer(Account &from, Account &to, MoneyType howMuch)
	{
		int b;
		// Alustetaan väliaikaiset Accountit, joilla on sama owner ja balance
		Account tempFrom(from.getOwner());
		Account tempTo(to.getOwner());
		
		// Jos jompikumpi lukittu, tässä heittää exceptionia
		if ((b = from.getBalance()) >= 0)
			tempFrom.deposit(b);
		else
			tempFrom.withdraw(-b);
		if ((b = to.getBalance()) >= 0)
			tempTo.deposit(b);
		else
			tempTo.withdraw(-b);
		
		// Sitten ruvetaan kikkailemaan balanssien kanssa.
		// from ja to muuttumattomia tässä vaiheessa.
		tempFrom.withdraw(howMuch);
		tempTo.deposit(howMuch);
		
		// Vaihdetaan fromin ja ton parametrit uusiksi
		from.swap(tempFrom);
		to.swap(tempTo);
		
		// Onnistuneesta suorituksesta ilmoitetaan asiaankuuluvasti.
		os << from.getOwner() << " transfer " << to.getOwner() << " " << howMuch;
		os << std::endl;
		
		
		
	}
	
}
