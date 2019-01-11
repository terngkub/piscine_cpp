#include "NinjaTrap.hpp"
#include <iostream>

NinjaTrap::NinjaTrap() : ClapTrap()
{
	_name = "Default";
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	std::cout << "NinjaTrap default constructor called\n";
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	_hitPoints = 60;
	_maxHitPoints = 60;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 5;
	_armorDamageReduction = 0;
	std::cout << "NinjaTrap name constructor called\n";
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src)
{
	std::cout << "NinjaTrap copy constructor called\n";
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap destructor called\n";
}

NinjaTrap & NinjaTrap::operator=(NinjaTrap const & rhs)
{
	std::cout << "NinjaTrap assignation operator called\n";
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_maxHitPoints = rhs._maxHitPoints;
		_energyPoints = rhs._energyPoints;
		_maxEnergyPoints = rhs._maxEnergyPoints;
		_level = rhs._level;
		_meleeAttackDamage = rhs._meleeAttackDamage;
		_rangedAttackDamage = rhs._rangedAttackDamage;
		_armorDamageReduction = rhs._armorDamageReduction;
	}
	return *this;
}

void NinjaTrap::ninjaShoebox(ClapTrap const & trap) const
{
	std::cout << "CrapTrap " << trap.getName() << " was shoeboxing ??? by ninja.\n";
}

void NinjaTrap::ninjaShoebox(FragTrap const & trap) const
{
	std::cout << "FragTrap " << trap.getName() << " was shoeboxing ??? by ninja.\n";
}

void NinjaTrap::ninjaShoebox(ScavTrap const & trap) const
{
	std::cout << "ScavTrap " << trap.getName() << " was shoeboxing ??? by ninja.\n";
}

void NinjaTrap::ninjaShoebox(NinjaTrap const & trap) const
{
	std::cout << "NinjaTrap " << trap.getName() << " was shoeboxing ??? by ninja.\n";
}
