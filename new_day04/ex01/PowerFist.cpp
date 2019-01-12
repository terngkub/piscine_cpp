#include <iostream>
#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 20)
{
}

PowerFist::PowerFist(PowerFist const & src)
{
	*this = src;
}

PowerFist::~PowerFist()
{
}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	if (this != &rhs)
		AWeapon::operator=(rhs);
	return *this;
}

void PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *\n";
}