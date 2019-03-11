#include "TacticalMarine.hpp"
#include <iostream>

TacticalMarine::TacticalMarine()
{
	std::cout << "Tactical Marine ready for battle\n";
}

TacticalMarine::~TacticalMarine()
{
	std::cout << "Aaargh ...\n";
}

TacticalMarine::TacticalMarine(TacticalMarine const & src)
{
	std::cout << "Tactical Marine ready for battle\n";
	*this = src;
}

TacticalMarine & TacticalMarine::operator=(TacticalMarine const & rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

ISpaceMarine * TacticalMarine::clone() const
{
	ISpaceMarine * marine = new TacticalMarine(*this);
	return marine;
}

void TacticalMarine::battleCry() const
{
	std::cout << "For the holy PLOT !\n";
}

void TacticalMarine::rangedAttack() const
{
	std::cout << "* attacks with bolter *\n";
}

void TacticalMarine::meleeAttack() const
{
	std::cout << "* attacks with chainsword *\n";
}
