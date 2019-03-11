#include "SuperTrap.hpp"
#include <iostream>

SuperTrap::SuperTrap() : FragTrap(), NinjaTrap()
{
	_name = "Default";
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "SuperTrap default constructor called\n";
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(), NinjaTrap()
{
	_name = name;
	_hitPoints = 100;
	_maxHitPoints = 100;
	_energyPoints = 120;
	_maxEnergyPoints = 120;
	_level = 1;
	_meleeAttackDamage = 60;
	_rangedAttackDamage = 20;
	_armorDamageReduction = 5;
	std::cout << "SuperTrap name constructor called\n";
}

SuperTrap::SuperTrap(SuperTrap const & src) : ClapTrap(src), FragTrap(), NinjaTrap()
{
	std::cout << "SuperTrap copy constructor called\n";
}

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap destructor called\n";
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs)
{
	std::cout << "SuperTrap assignation operator called\n";
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

void SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::meleeAttack(target);
}
