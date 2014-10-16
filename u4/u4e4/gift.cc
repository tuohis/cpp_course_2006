#include "gift.hh"
#include "mystack.hh"
#include <string.h>


// Konstruktori
Gift::Gift(const char *name)
{
	if (name != NULL) {
	
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
	}
	// Jos nimi ei ole validi pointteri, asetetaan nimeksi tyhjä stringi
	else {
		this->name = new char[1];
		*(this->name) = '\0';
	}
}


Gift::Gift(const Gift& gift)
{
	if (gift.getName() != NULL) {
		this->name = new char[strlen(gift.getName())+1];
		strcpy(this->name, gift.getName());
	}
	else {
		this->name = new char[1];
		*(this->name) = '\0';
	}
}


Gift::~Gift()
{
	delete[] this->name;
}

const char *Gift::getName() const
{
	return name;
}


void Gift::setName(const char *newName)
{
	if (newName == NULL)
		return;
	
	// Tuhotaan vanha nimi ja tehdään uusi
	delete[] this->name;
	this->name = new char[strlen(newName)+1];
	strcpy(this->name, newName);
}


Gift& Gift::operator=(const Gift& otherGift)
{
	delete[] this->name;
	this->name = new char[strlen(otherGift.getName())+1];
	strcpy(this->name, otherGift.getName());
	
	return *this;
}



std::ostream& operator<<(std::ostream& os, const Gift& gift)
{
if (os != NULL)
	os << gift.getName();

return os;
}

std::istream& operator>>(std::istream& is, Gift& gift)
{
char *line = new char[51];
is.getline(line, 50);

gift.setName(line);

return is;
}
