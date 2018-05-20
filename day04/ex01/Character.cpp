/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:46:14 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 19:10:14 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() :
	_ap(40),
	_name("Default"),
	_weapon(NULL)
{
}

Character::Character(std::string const & name) :
	_ap(40),
	_name(name),
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
		_ap = rhs._ap;
		_name = rhs._name;
		_weapon = rhs._weapon;
	}
	return *this;
}

void		Character::recoverAP()
{
	int ap = _ap + 10;
	if (ap > 40)
		_ap = 40;
	else
		_ap = ap;
}

void		Character::equip(AWeapon *weapon)
{
	_weapon = weapon;
}

void		Character::attack(Enemy *enemy)
{
	if (_weapon && _ap >= _weapon->getAPCost())
	{
		std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
		_ap -= _weapon->getAPCost();
		_weapon->attack();
		enemy->takeDamage(_weapon->getDamage());
		if (enemy->getHP() <= 0)
			enemy->~Enemy();
	}
}

std::string	Character::getName() const
{
	return _name;
}

int			Character::getAP() const
{
	return _ap;
}

AWeapon		*Character::getWeapon() const
{
	return _weapon;
}

std::ostream & operator<<(std::ostream & o, Character const & rhs)
{
	if (rhs.getWeapon())
		std::cout << rhs.getName() << " has " << rhs.getAP() << " AP and weilds a " << rhs.getWeapon()->getName() << std::endl;
	else
		std::cout << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
}
