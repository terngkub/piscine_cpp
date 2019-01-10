#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() :
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
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(FragTrap const & src) :
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
	std::cout << "FragTrap copy constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "FragTrap assignation operator called\n";
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

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout
		<< "FR4G-TP " << _name
		<< " attacks " << target
		<< " at range, causing " << _rangedAttackDamage
		<< " points of damage !\n";
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout
		<< "FR4G-TP " << _name
		<< " attacks " << target
		<< " at melee, causing " << _meleeAttackDamage 
		<< " points of damage !\n";
}

void FragTrap::takeDamage(unsigned int amount)
{
	unsigned int damage = amount - _armorDamageReduction;

	if (_hitPoints > damage)
		_hitPoints -= damage;
	else
		_hitPoints = 0;

	std::cout
		<< "FR4G-TP " << _name
		<< " takes after-armor damage of " << damage
		<< ", hit points left " << _hitPoints
		<< ".\n";
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints + amount < _maxHitPoints)
		_hitPoints += amount;
	else
		_hitPoints = _maxHitPoints;

	std::cout
		<< "FR4G-TP " << _name
		<< " is repaired by " << amount
		<< ", hit points left " << _hitPoints
		<< ".\n";
}

std::string FragTrap::getName() const
{
	return _name;
}

unsigned int FragTrap::getHitPoints() const
{
	return _hitPoints;
}

unsigned int FragTrap::getMaxHitPoints() const
{
	return _maxHitPoints;
}

unsigned int FragTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int FragTrap::getMaxEnergyPoints() const
{
	return _maxEnergyPoints;
}

unsigned int FragTrap::getLevel() const
{
	return _level;
}

unsigned int FragTrap::getMeleeAttackDamage() const
{
	return _meleeAttackDamage;
}

unsigned int FragTrap::getRangedAttackDamage() const
{
	return _rangedAttackDamage;
}

unsigned int FragTrap::getArmorDamageReduction() const
{
	return _armorDamageReduction;
}

void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string	attack[5] = {
		"shooting",
		"dancing",
		"sleeping",
		"stealing money",
		"ignoring"
	};

	if (_energyPoints < 25)
		std::cout << "FragTrap tries to use vaulthunter_dot_exe but doesn't have enough energy.\n";
	else
	{
		std::cout
			<< "FR4G-TP " << _name
			<< " attacks " << target
			<< " by " << attack[rand() % 5] 
			<< " !\n";

		_energyPoints -= 25;
	}
}
