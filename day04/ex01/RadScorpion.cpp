/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 18:35:15 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/20 18:40:40 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src)
{
	*this = src;
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}


RadScorpion & RadScorpion::operator=(RadScorpion const & rhs)
{
	if (this != &rhs)
		Enemy::operator=(rhs);
	return *this;
}


void	RadScorpion::takeDamage(int damage)
{
	int hp = getHP() - damage;
	setHP(hp > 0 ? hp : 0);
}
