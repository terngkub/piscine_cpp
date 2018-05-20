/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 13:22:55 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 18:30:31 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() :
	_hp(0),
	_type("Default")
{
}

Enemy::Enemy(int hp, std::string const & type) :
	_hp(hp),
	_type(type)
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		_hp = rhs._hp;
		_type = rhs._type;
	}
	return *this;
}

int			Enemy::getHP() const
{
	return _hp;
}

std::string	Enemy::getType() const
{
	return _type;
}

void		Enemy::setHP(int hp)
{
	_hp = hp;
}

std::ostream & operator<<(std::ostream & o, Enemy const & rhs)
{
	o << "HP: " << rhs.getHP() << std::endl
		<< "Type: " << rhs.getType() << std::endl;
	return o;
}
