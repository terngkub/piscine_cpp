#include <iostream>
#include "Character.hpp"

Character::Character() :
	_name("Default name"),
	_ap(40),
	_weapon(NULL)
{
}

Character::Character(std::string const & name) :
	_name(name),
	_ap(40),
	_weapon(NULL)
{
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character()
{
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_ap = rhs._ap;
		_weapon = rhs._weapon;
	}
	return *this;
}

std::string Character::getName() const
{
	return _name;
}

int Character::getAp() const
{
	return _ap;
}

AWeapon * Character::getWeapon() const
{
	return _weapon;
}

void Character::recoverAP()
{
	int ap = _ap + 10;
	if (ap > 40)
		_ap = 40;
	else
		_ap = ap;
}

void Character::equip(AWeapon * weapon)
{
	_weapon = weapon;
}

void Character::attack(Enemy * enemy)
{
	if (!_weapon)
		return ;
	int apcost = _weapon->getAPCost();
	if (_ap < apcost)
		return ;
	_ap -= apcost;
	std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << "\n";
	_weapon->attack();
	enemy->takeDamage(_weapon->getDamage());
	if (enemy->getHp() <= 0)
		enemy->~Enemy();
}

std::ostream & operator<<(std::ostream & o, Character const & rhs)
{
	if (rhs.getWeapon())
		o << rhs.getName() << " has " << rhs.getAp() << " AP and wields " << rhs.getWeapon()->getName() << "\n";
	else
		o << rhs.getName() << " has " << rhs.getAp() << " AP and is unarmed\n";
	return o;
}