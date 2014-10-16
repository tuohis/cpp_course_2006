#include "tree.hh"
#include <iterator>
#include <algorithm>
#include <iostream>



int main()
{
  using tree::Tree;
  Tree<char> a('a');
  
  a.addRight('b');
  a.getRight().addRight('d');
  a.getRight().getRight().addRight('e');
  a.getRight().getRight().getRight().addRight('g');
  a.getRight().getRight().getRight().getRight().addRight('f');
  a.getRight().getRight().getRight().getRight().getRight().addRight('c');
  a.getRight().getRight().getRight().getRight().getRight().getRight().addRight('h');
  a.getRight().getRight().getRight().getRight().getRight().getRight().getRight().addRight('i');
  a.getRight().getRight().getRight().getRight().getRight().getRight().getRight().getRight().addRight('j');
  
  
  Tree<char>::iterator it = a.begin();



  /* The created tree looks something like this:


                 A
       B                    C
  D       E            H         I
        G   F                  J
 
The order of these elements using with in-order traversal:

D, B, G, E, F, A, H, C, J, I

This is also what this program should print out.

  */
  for (Tree<char>::iterator it = a.begin();
       it != a.end();
       ++it)
    {
      std::cout << *it << std::endl;
    }


  
  
  std::cout << "----" << std::endl;
  
  std::copy(a.begin(), a.end(),
            std::ostream_iterator<char>(std::cout, "\n"));

  a.~Tree();
  
  
}
