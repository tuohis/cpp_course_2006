


#include "account.hh"

#include <string>
#include <ostream>

namespace bank
{


  Account::Account(std::string owner)
    : balance(0), owner(owner), locked(false)
  {}

    

  void Account::swap(Account &acc)
  {
    using std::swap;
    swap(locked, acc.locked);
    swap(balance, acc.balance);
    swap(owner, acc.owner);
  }


  void Account::withdraw(MoneyType sum)
  {
    if (locked)
      throw 1;
    if (sum < 0)
      throw 1;
    balance -= sum;
  }

  void Account::deposit(MoneyType sum)
  {
    if (locked)
      throw 1;
    if (sum < 0)
      throw 1;
    balance += sum;
  }
  
  MoneyType Account::getBalance() const
  {
    if (locked)
      throw 1;
    return balance;
  }

  std::string Account::getOwner() const
  {
    return owner;
  }


  std::ostream &operator<<(std::ostream &os, Account const &acc)
  {
    os << acc.owner << ": ";
    if (acc.locked)
      os << "[LOCKED]";
    else
      os << acc.balance << " cents";
    return os;
  }

  void Account::lock()
  {
    locked = true;
  }


  
}

  
