#include "tree.hh"
#include <iterator>
#include <algorithm>
#include <iostream>



int main()
{
  using tree::Tree;
  Tree<char> a('a');
  
  a.addLeft('b');
  a.getLeft().addLeft('d');
  a.getLeft().addRight('e');
  a.getLeft().getRight().addLeft('g');
  a.getLeft().getRight().addRight('f');

  a.addRight('c');
  a.getRight().addLeft('h');
  a.getRight().addRight('i');
  a.getRight().getRight().addLeft('j');
  
  
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
