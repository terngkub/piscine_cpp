#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer() :
_name("Default name"),
_title("Default title")
{
	std::cout << _name << ", " << _title << ", is born !\n";
}

Sorcerer::Sorcerer(std::string name, std::string title) :
_name(name),
_title(title)
{
	std::cout << _name << ", " << _title << ", is born !\n";
}

Sorcerer::Sorcerer(Sorcerer const & src) :
_name(src._name),
_title(src._title)
{
	std::cout << _name << ", " << _title << ", is born !\n";
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !\n";
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_title = rhs._title;
	}
	return *this;
}

std::string Sorcerer::getName() const
{
	return _name;
}

std::string Sorcerer::getTitle() const
{
	return _title;
}

void Sorcerer::polymorph(Victim const & victim) const
{
	victim.getPolymorphed();
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !\n";
	return o;
}