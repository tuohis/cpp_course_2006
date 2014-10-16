#include "aviary.hh"
#include "bird.hh"
#include <stdexcept>
#include <vector>


namespace aviary {
  
  
	Aviary::~Aviary()
	{
		std::vector<Bird *>::iterator viter;
		for (viter = birds.begin(); viter != birds.end(); viter++) {
			delete *viter;
		}
		
	}
    // When a bird is added to the aviary, it's ownership
    // is transferred. When the aviary is destroyed, all
    // the birds are destroyed too.
    //
    // If bird is NULL, std::logic_error is thrown.
    void Aviary::addBird(Bird *bird)
	{
		if (bird == NULL)
			throw std::logic_error("Lintu on ihan nolla");
		birds.push_back(bird);
	}

    // This function calls the speak() method of all
    // birds in the order they were added to the aviary.
    // The first parameter is passed to the speak() method
    // of a bird.
    void Aviary::speakAll(std::ostream &os) const
	{
		for (std::vector<Bird *>::const_iterator viter = birds.begin(); 
				viter != birds.end(); viter++) {
			(*viter)->speak(os);
		}
	}
    
    // Create a new type alias sizeType

    // Returns how many birds there are in the aviary.
    Aviary::sizeType Aviary::size() const
	{
		return birds.size();
	}
    
    // You must implement at least the indexing operator [].
    // It must work for both const and nonconst aviaries.
    // If the aviary is indexed out of bounds, std::out_of_range is
    // thrown.
    // The return types are const Bird * for the const version and
    // Bird * for the nonconst version.
    
    // Obviously this class must NOT leak any resources.
    // If somebody tries to copy an instance of this class,
    // the compilation must fail.
    const Bird *Aviary::operator[](int i) const
	{
		if (i >= (int)birds.size())
			throw std::out_of_range("");
		
		return birds[i];
	}
	
	Bird *Aviary::operator[](int i)
	{
		if (i >= (int)birds.size())
			throw std::out_of_range("");
		return birds[i];
	}
  
  
}
