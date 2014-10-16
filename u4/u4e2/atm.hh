#ifndef ATM_HH
#define ATM_HH

#include <ostream>
#include "account.hh"

namespace bank {
  class Atm
  {

  public:
    // The constructor takes one argument. This argument
    // represents the output stream where the automatic
    // teller machine should print out what it is doing.
    
    Atm(std::ostream &os);




    // These three functions deposit, withdraw and transfer
    // money. They each must have strong exception safety
    // guarantee. All the messages they print to the output stream
    // end with newline.


    // When a deposit is made, a message is printed to the output stream.
    // It has the following format:
    // <account owner> deposit <amount>
    // for example:
    // Esko deposit 100
    
    void deposit(Account &acc, MoneyType m);

    // When a withdraw is made, a message is printed to the output stream.
    // It has the following format:
    // <account owner> withdraw <amount>
    void withdraw(Account &acc, MoneyType m);

    // When a transfer is made, a message is printed to the output stream.
    // It has the following format:
    // <source account holder> transfer <destination account holder> <sum>
    // For example:
    // Esko transfer Juuso 500
    
    void transfer(Account &from, Account &to, MoneyType howMuch);
    
    
  private:

    std::ostream &os;

    // You cannot copy this class.
    
    Atm(const Atm &);
    Atm &operator=(const Atm &);
    


  };


}









#endif
