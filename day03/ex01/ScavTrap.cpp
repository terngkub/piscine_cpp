#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() :
_name("Default"),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(50),
_maxEnergyPoints(50),
_level(1),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorDamageReduction(3)
{
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(std::string name) :
_name(name),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(50),
_maxEnergyPoints(50),
_level(1),
_meleeAttackDamage(20),
_rangedAttackDamage(15),
_armorDamageReduction(3)
{
	std::cout << "ScavTrap name constructor called\n";
}


ScavTrap::ScavTrap(ScavTrap const & src) :
_name(src._name),
_hitPoints(src._hitPoints),
_maxHitPoints(src._maxHitPoints),
_energyPoints(src._energyPoints),
_maxEnergyPoints(src._maxEnergyPoints),
_level(src._level),
_meleeAttackDamage(src._meleeAttackDamage),
_rangedAttackDamage(src._rangedAttackDamage),
_armorDamageReduction(src._armorDamageReduction)
{
	std::cout << "ScavTrap copy constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "ScavTrap assignation operator called\n";
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

void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout
		<< "SC4V-TP " << _name
		<< " attacks " << target
		<< " at range, causing " << _rangedAttackDamage
		<< " points of damage !\n";
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout
		<< "SC4V-TP " << _name
		<< " attacks " << target
		<< " at melee, causing " << _meleeAttackDamage 
		<< " points of damage !\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = amount - _armorDamageReduction;

	if (_hitPoints > damage)
		_hitPoints -= damage;
	else
		_hitPoints = 0;

	std::cout
		<< "SC4V-TP " << _name
		<< " takes after-armor damage of " << damage
		<< ", hit points left " << _hitPoints
		<< ".\n";
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints + amount < _maxHitPoints)
		_hitPoints += amount;
	else
		_hitPoints = _maxHitPoints;

	std::cout
		<< "SC4V-TP " << _name
		<< " is repaired by " << amount
		<< ", hit points left " << _hitPoints
		<< ".\n";
}

std::string ScavTrap::getName() const
{
	return _name;
}

unsigned int ScavTrap::getHitPoints() const
{
	return _hitPoints;
}

unsigned int ScavTrap::getMaxHitPoints() const
{
	return _maxHitPoints;
}

unsigned int ScavTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int ScavTrap::getMaxEnergyPoints() const
{
	return _maxEnergyPoints;
}

unsigned int ScavTrap::getLevel() const
{
	return _level;
}

unsigned int ScavTrap::getMeleeAttackDamage() const
{
	return _meleeAttackDamage;
}

unsigned int ScavTrap::getRangedAttackDamage() const
{
	return _rangedAttackDamage;
}

unsigned int ScavTrap::getArmorDamageReduction() const
{
	return _armorDamageReduction;
}

void ScavTrap::challengeNewcomer() const
{
	std::string	challenge[5] = {
		"SHOOT !!!",
		"DANCE !!!",
		"SLEEP !!!",
		"OMG !!!",
		"GO AWAY !!!"
	};

	std::cout
		<< "SC4V-TP " << _name
		<< ": " << challenge[rand() % 5] 
		<< " !\n";
}
