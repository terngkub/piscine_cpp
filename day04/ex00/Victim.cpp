#include <iostream>
#include "Victim.hpp"

Victim::Victim() :
_name("Default name")
{
	std::cout << "Some random victim called " << _name << " just popped !\n";
}

Victim::Victim(std::string name) :
_name(name)
{
	std::cout << "Some random victim called " << _name << " just popped !\n";
}

Victim::Victim(Victim const & src) :
_name(src._name)
{
	std::cout << "Some random victim called " << _name << " just popped !\n";
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason !\n";
}

Victim & Victim::operator=(Victim const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
	}
	return *this;
}

std::string Victim::getName() const
{
	return _name;
}

void Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep !\n";
}

std::ostream & operator<<(std::ostream & o, Victim const & rhs)
{
	o << "I'm " << rhs.getName() << " and I like otters !\n";
	return o;
}