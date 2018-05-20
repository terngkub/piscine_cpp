/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 11:08:50 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 11:58:48 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon() :
	_name("Default"),
	_apcost(0),
	_damage(0)
{
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) :
	_name(name),
	_apcost(apcost),
	_damage(damage)
{
}

AWeapon::AWeapon(AWeapon const & src)
{
	*this = src;
}

AWeapon::~AWeapon()
{
}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_apcost = rhs._apcost;
		_damage = rhs._damage;
	}
	return *this;
}

std::string		AWeapon::getName() const
{
	return _name;
}

int				AWeapon::getAPCost() const
{
	return _apcost;
}

int				AWeapon::getDamage() const
{
	return _damage;
}

std::ostream & operator<<(std::ostream & o, AWeapon const & rhs)
{
	o << "Name: " << rhs.getName() << std::endl
		<< "APCost: " << rhs.getAPCost() << std::endl
		<< "Damage: " << rhs.getDamage() << std::endl;
	return o;
}
