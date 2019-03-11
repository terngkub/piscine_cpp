#include <iostream>
#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !\n";
}

SuperMutant::SuperMutant(SuperMutant const & src)
{
	*this = src;
	std::cout << "Gaaah. Me want smash heads !\n";
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ...\n";
}

SuperMutant & SuperMutant::operator=(SuperMutant const & rhs)
{
	if (this != &rhs)
		Enemy::operator=(rhs);
	return *this;
}

void SuperMutant::takeDamage(int damage)
{
	int hp = getHp() - damage + 3;
	setHp(hp > 0 ? hp : 0);
}
