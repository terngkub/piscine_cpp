#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() :
_name("Default"),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) :
_name(name),
_hitPoints(100),
_maxHitPoints(100),
_energyPoints(100),
_maxEnergyPoints(100),
_level(1),
_meleeAttackDamage(30),
_rangedAttackDamage(20),
_armorDamageReduction(5)
{
	std::cout << "ClapTrap name constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap const & src) :
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
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called\n";
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "ClapTrap assignation operator called\n";
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

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout
		<< "CL4P-TP " << _name
		<< " attacks " << target
		<< " at range, causing " << _rangedAttackDamage
		<< " points of damage !\n";
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout
		<< "CL4P-TP " << _name
		<< " attacks " << target
		<< " at melee, causing " << _meleeAttackDamage 
		<< " points of damage !\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = amount - _armorDamageReduction;

	if (_hitPoints > damage)
		_hitPoints -= damage;
	else
		_hitPoints = 0;

	std::cout
		<< "CL4P-TP " << _name
		<< " takes after-armor damage of " << damage
		<< ", hit points left " << _hitPoints
		<< ".\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints + amount < _maxHitPoints)
		_hitPoints += amount;
	else
		_hitPoints = _maxHitPoints;

	std::cout
		<< "CL4P-TP " << _name
		<< " is repaired by " << amount
		<< ", hit points left " << _hitPoints
		<< ".\n";
}

std::string ClapTrap::getName() const
{
	return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

unsigned int ClapTrap::getMaxHitPoints() const
{
	return _maxHitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int ClapTrap::getMaxEnergyPoints() const
{
	return _maxEnergyPoints;
}

unsigned int ClapTrap::getLevel() const
{
	return _level;
}

unsigned int ClapTrap::getMeleeAttackDamage() const
{
	return _meleeAttackDamage;
}

unsigned int ClapTrap::getRangedAttackDamage() const
{
	return _rangedAttackDamage;
}

unsigned int ClapTrap::getArmorDamageReduction() const
{
	return _armorDamageReduction;
}
