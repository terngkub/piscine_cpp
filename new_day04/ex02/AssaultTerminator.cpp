#include "AssaultTerminator.hpp"
#include <iostream>

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *\n";
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I'll be back ...\n";
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	std::cout << "* teleports from space *\n";
	*this = src;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

ISpaceMarine * AssaultTerminator::clone() const
{
	ISpaceMarine * marine = new AssaultTerminator(*this);
	return marine;
}

void AssaultTerminator::battleCry() const
{
	std::cout << "This code is unclean. PURIFY IT !\n";
}

void AssaultTerminator::rangedAttack() const
{
	std::cout << "* does nothing *\n";
}

void AssaultTerminator::meleeAttack() const
{
	std::cout << "* attacks with chainfists *\n";
}