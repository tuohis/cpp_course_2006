/** @file christmas.cc
 *  This file contains Christmas program
 */
#include "gift.hh"
#include "mystack.hh"





int main() {
  using std::cout; using std::cin; using std::endl;
  using std::ws; using std::cerr;
  int i,j;
  int sacks;
  int gifts;
  // Even though you cannot use std::string in your implementation,
  // we can use it here :P
  std::string str;
  
  /* read sack and gift counts */

  cout << "How many sacks?" << endl;
  cin >> sacks;
  

  cout << "How many gifts in a sack?" << endl;
  cin >> gifts;
  cin.get();

  /* read stuff */

  MyStack< MyStack<Gift> > sledge;

  for(i=0;i<sacks;i++) {

    Gift tempGift;
    cout << "Please enter gifts for sack " << i+1 << endl;
    
    MyStack<Gift> tempSack;
    
    
    for(j=0;j<gifts;j++) {
      getline(cin, str);

      tempGift.setName(str.c_str());
      if (tempSack.push(&tempGift) == -1) {
	cerr << "failed";
      }
    }

    /* sack read, now push sack to sledge */
    sledge.push(&tempSack);
    
  }
  
  /* pop everything from sledge to see its contents */
  
  
  MyStack<Gift> aSack;
  
  while(sledge.pop(&aSack) == 0) {
    cout << "Sack contents:" << endl;
    Gift aGift;
    while(aSack.pop(&aGift) == 0) {
      cout << aGift << endl;
    }
  }
}



