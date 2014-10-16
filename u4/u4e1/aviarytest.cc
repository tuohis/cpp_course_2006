#include "aviary.hh"
#include "duck.hh"
#include "bird.hh"
#include "owl.hh"

#include <iostream>
#include <string>

using aviary::Aviary;
using aviary::Duck;
using aviary::Owl;

void constTest(Aviary const &a)
{
  a[1]->speak(std::cout);
  
}

int main()
{

  // The output of the program should be this:

  /*
    Esko: QUACK
    Orly: WHUU
    Alfred: QUACK
    Alfred flies!
    Orly: WHUU
  */
  
  Aviary a, b;
  
  a.addBird(new Duck("Esko"));
  a.addBird(new Owl("Orly"));

  a.addBird(new Duck("Alfred"));
  
  
  a.speakAll(std::cout);

  a[2]->fly(std::cout);

  constTest(a);
  


}
