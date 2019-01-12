#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *\n";
}

RadScorpion::RadScorpion(RadScorpion const & src)
{
	*this = src;
	std::cout << "* click click click *\n";
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *\n";
}

RadScorpion & RadScorpion::operator=(RadScorpion const & rhs)
{
	if (this != &rhs)
		Enemy::operator=(rhs);
	return *this;
}

void RadScorpion::takeDamage(int damage)
{
	int hp = getHp() - damage;
	setHp(hp > 0 ? hp : 0);
}
