#ifndef ACCOUNT_HH
#define ACCOUNT_HH


#include <string>
#include <ostream>
namespace bank {
  typedef int MoneyType;  
  class Account
  {
  public:

    // Constructor. Strong exception safety, may throw.
    Account(std::string owner);



    // Implicit copy constructor, never throws.
    
    // This function never throws an exception.
    void swap(Account &acc);
    
    // This function withdraws a certain sum
    // from the account. It may throw, but it has
    // strong exception safety.
    void withdraw(MoneyType sum);
    
    // This function deposits a certain sum to the
    // account. It may throw, but it has strong exception
    // safety.
    void deposit(MoneyType sum);
    
    
    // This function returns the account balance.
    // Strong exception safety, may throw.
    MoneyType getBalance() const;
    
    // This functions returns the name of the account holder
    // Never throws.
    std::string getOwner() const;
    

    // This functions locks the account. Never throws.
    void lock();

    friend std::ostream &operator<<(std::ostream &os, Account const &acc);
    
  private:


    // Private assigment operator. You cannot assign accounts into accounts.

    Account &operator=(Account const &rhs);
    
    MoneyType balance;
    std::string owner;

    // Normally there should be a way to test is an
    // account locked or not, but for the
    // purposes of this exercise we won't give you one.
    
    bool locked;
    
    
    
  };

}
    
#endif


